//
// Created by ludwig on 30.01.17.
//
#include <Interfaces.h>
#include "systemc.h"

#include "../../SingleMasterMultiSlave/ESL/Compound.h"

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
    bus_req_t req_temp;
    bus_req_t master_req[10];
    int master_req_count = 0;

    enum Sections {
        STACKING, ISSUE
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
            section(STACKING),
            nextsection(STACKING) {
        SC_THREAD(fsm);
    }


    void fsm() {

        while (true) {
            section = nextsection;
            if (section == STACKING) {
                if(master_req_count < 10) {
                    this->master_in->read(req_temp);
                    master_req[master_req_count] = req_temp;
//                    std::cout << this->name() << " - STACKING " << master_req[master_req_count].addr << std::endl;
                    master_req_count++;
                    nextsection = STACKING;
                } else {
                    master_req_count = 0;
                    nextsection = ISSUE;
                }
            }
            if (section == ISSUE) {
                if (master_req_count == 10){
                    master_req_count = 0;
                    nextsection = STACKING;
                } else {
                    req = master_req[master_req_count];
                    master_req_count++;
//                    std::cout << this->name() << " - ISSUE " << req.addr << std::endl;

                    if(SINGLE_READ == req.trans_type){
                        req.data = 0;
                    }

                    if  (req.addr >= 0 && req.addr < 8) {
                        slave_out0->write(req);
                        slave_in0->read(resp);
                    }
                    else if (req.addr >= 8 && req.addr < 16) {
                        req.addr = req.addr - 8;
                        slave_out1->write(req);
                        slave_in1->read(resp);
                    }
                    else if (req.addr >= 16 && req.addr < 24) {
                        req.addr = req.addr - 16;
                        slave_out2->write(req);
                        slave_in2->read(resp);
                    }
                    else if (req.addr >= 24 && req.addr < 32) {
                        req.addr = req.addr - 24;
                        slave_out3->write(req);
                        slave_in3->read(resp);
                    }
                    else {
                        resp.ack = OK;
                        resp.data = 0;
                    }
                    if(SINGLE_WRITE== req.trans_type){
                        resp.data = 0;
                    }
                    master_out->write(resp);
                    nextsection = ISSUE;
                }
            }
            wait(SC_ZERO_TIME);
        }
    }
};


#endif //PROJECT_BUS_H
