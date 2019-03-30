//
// Created by ludwig on 30.01.17.
//
#include <Interfaces.h>
#include "systemc.h"

#include "../../../SingleMasterMultiSlave/ESL/Compound.h"

#ifndef PROJECT_BUS_H
#define PROJECT_BUS_H

struct Bus : public sc_module {

    //In-port
    blocking_in<bus_req_t> master_in;
    blocking_in<bus_resp_t> slave_in0;
    blocking_in<bus_resp_t> slave_in1;
    blocking_in<bus_resp_t> slave_in2;
    blocking_in<bus_resp_t> slave_in3;


    //Out-por
    blocking_out<bus_resp_t> master_out;
    blocking_out<bus_req_t> slave_out0;
    blocking_out<bus_req_t> slave_out1;
    blocking_out<bus_req_t> slave_out2;
    blocking_out<bus_req_t> slave_out3;


    //Variables
    bus_req_t req;
    bus_resp_t resp;
    bool free_to_issue = true;

    enum Sections {
        FETCH, ISSUE, REPLY
    };
    Sections section;
    Sections nextsection;

    //Constructor
    SC_HAS_PROCESS(Bus);

    Bus(sc_module_name name) :
            master_in("master_in"),
            master_out("master_out"),
            slave_out0("slave_out0"),
            slave_out1("slave_out1"),
            slave_out2("slave_out2"),
            slave_out3("slave_out3"),
            slave_in0("slave_in0"),
            slave_in1("slave_in1"),
            slave_in2("slave_in2"),
            slave_in3("slave_in3"),
            section(FETCH),
            nextsection(FETCH) {
        SC_THREAD(fsm);
    }

    void fsm() {

        while (true) {
            section = nextsection;
            if (section == FETCH) {
                this->master_in->read(req);
//                std::cout << this->name() << " - FETCH to addr: " << req.addr << std::endl;
                if (free_to_issue) {
                    free_to_issue = false;
                    nextsection = ISSUE;
                } else {
                    resp.ack = RTY;
                    resp.data = 0;
                    free_to_issue = true;
                    nextsection = REPLY;
                }
            }
            if (section == ISSUE) {
//                std::cout << this->name() << " - ISSUE to addr: " << req.addr << std::endl;

                if (SINGLE_READ == req.trans_type) {
                    req.data = 0;
                }

                if (req.addr >= 0 && req.addr < 8) {
                    slave_out0->write(req);
                    slave_in0->read(resp);
                } else if (req.addr >= 8 && req.addr < 16) {
                    req.addr = req.addr - 8;
                    slave_out1->write(req);
                    slave_in1->read(resp);
                } else if (req.addr >= 16 && req.addr < 24) {
                    req.addr = req.addr - 16;
                    slave_out2->write(req);
                    slave_in2->read(resp);
                } else if (req.addr >= 24 && req.addr < 32) {
                    req.addr = req.addr - 24;
                    slave_out3->write(req);
                    slave_in3->read(resp);
                } else {
                    resp.ack = OK;
                    resp.data = 0;
                }
                if (SINGLE_WRITE == req.trans_type) {
                    resp.data = 0;
                }
                nextsection = REPLY;
            }
            if (section == REPLY) {
//                std::cout << this->name() << " - REPLY to addr " << req.addr << " with ack = " << resp.ack << std::endl;
                master_out->write(resp);
                nextsection = FETCH;
            }
            wait(SC_ZERO_TIME);
        }
    }
};


#endif //PROJECT_BUS_H
