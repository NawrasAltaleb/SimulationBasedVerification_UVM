//
// Created by tobias on 09.03.17.
//

#ifndef PROJECT_MASTERAGENT_H
#define PROJECT_MASTERAGENT_H

#include "systemc.h"
#include "../../Interfaces/Interfaces.h"
#include "Compound_Bus.h"
#include "../../SingleMasterMultiSlave/ESL/Compound.h"


struct MasterAgent : public sc_module {
    //Sections
    enum Sections {
        STACKING, ISSUE, READ, WRITE, WAITING, DONE
    };
    Sections section;
    Sections nextsection;
    //CLK
    master_in<bool> clk;
    bool clk_pulse;

    //Communication between Master and Agent
    blocking_in<bus_req_t> master_to_agent;
    blocking_out <bus_resp_t> agent_to_master;

    //Communication on BUS
    shared_in<slave_signals> bus_to_agent;
    shared_out<master_signals> agent_to_bus;

    //Variables
    bus_req_t agent_to_bus_req;
    bus_resp_t agent_to_bus_resp;
    bus_req_t req_temp;
    bus_req_t master_req[10];
    int master_req_count = 0;

    master_signals wb_out;
    slave_signals wb_in;

    //Constructor
    SC_HAS_PROCESS(MasterAgent);

    MasterAgent(sc_module_name name) :
            section(STACKING),
            nextsection(STACKING){
        SC_THREAD(fsm);
    }

    void fsm() {
        while (true) {
            section = nextsection;
            if (section == STACKING) {
                if(master_req_count < 10) {
                    this->master_to_agent->read(req_temp);
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
                    agent_to_bus_req = master_req[master_req_count];
                    master_req_count++;
//                    std::cout << this->name() << " - ISSUE " << agent_to_bus_req.addr << std::endl;

                    if (agent_to_bus_req.trans_type == SINGLE_READ) {
                        nextsection = READ;
                    } else
                        nextsection = WRITE;
                }
            }
            if (section == READ) {
//                std::cout << this->name() << " - READ " << agent_to_bus_req.addr << std::endl;
                wb_out.addr = agent_to_bus_req.addr;
                wb_out.data = 0;
                wb_out.we = false;
                wb_out.cyc = true;
                wb_out.stb = true;
                agent_to_bus->set(wb_out);
                nextsection = WAITING;
            }
            if (section == WRITE) {
//                std::cout << this->name() << " - WRITE " << agent_to_bus_req.addr  << std::endl;
                wb_out.addr = agent_to_bus_req.addr;
                wb_out.data = agent_to_bus_req.data;
                wb_out.we = true;
                wb_out.cyc = true;
                wb_out.stb = true;
                agent_to_bus->set(wb_out);
                nextsection = WAITING;
            }
            if (section == WAITING) {
//                std::cout << this->name() << " - WAIT " << std::endl;
                clk->read(clk_pulse);
                bus_to_agent->get(wb_in);
                if (wb_in.ack == true) {
                    agent_to_bus_resp.ack = OK;

//                    if(agent_to_bus_req.trans_type == SINGLE_READ  ) {
                    agent_to_bus_resp.data = wb_in.data;
//                    }
                    if (wb_in.err == true) {
                        agent_to_bus_resp.ack = ERR;
                    }
                    wb_out.addr = 0;
                    wb_out.data = 0;
                    wb_out.we = false;
                    wb_out.cyc = false;
                    wb_out.stb = false;

                    agent_to_bus->set(wb_out);
                    nextsection = DONE;
                }
            }
            if (section == DONE) {
                clk->read(clk_pulse);
                bus_to_agent->get(wb_in);
                if (wb_in.ack == false) {
//                    std::cout << this->name() << " - DONE " << agent_to_bus_resp.data << std::endl;
                    agent_to_master->write(agent_to_bus_resp);
                    nextsection = ISSUE;
                }
            }
            wait(SC_ZERO_TIME);
        }
    }


};

#endif //PROJECT_MASTERAGENT_H