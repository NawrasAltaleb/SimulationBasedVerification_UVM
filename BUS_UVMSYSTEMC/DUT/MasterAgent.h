#ifndef SYSTEMC_MasterAgent_H
#define SYSTEMC_MasterAgent_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

      struct MasterAgent : public sc_module {

        enum Sections {DONE, IDLE, READ, WAITING, WRITE};
        Sections section;

        shared_out<master_signals> agent_to_bus;
        blocking_out<bus_resp_t> agent_to_master;
        shared_in<slave_signals> bus_to_agent;
        master_in<bool> clk;
        blocking_in<bus_req_t> master_to_agent;

        //functions

        bus_req_t agent_to_bus_req;
        bus_resp_t agent_to_bus_resp;
        bool clk_pulse;
        slave_signals wb_in;
        master_signals wb_out;


        void FSM(){
            while(true) {
              if (section==DONE) {
                if(!coveragePoints["MasterAgent_1"]){
                  coveragePoints["MasterAgent_1"] = true;
                  coveragePointsCount++;
                }
                clk->read(clk_pulse);
                bus_to_agent->get(wb_in);
                if ((wb_in.ack == false)) {
                  if(!coveragePoints["MasterAgent_2"]){
                    coveragePoints["MasterAgent_2"] = true;
                    coveragePointsCount++;
                  }
                  agent_to_master->write(agent_to_bus_resp);
                  section = IDLE;
                }
              }
              else if (section==IDLE) {
                if(!coveragePoints["MasterAgent_3"]){
                  coveragePoints["MasterAgent_3"] = true;
                  coveragePointsCount++;
                }
                master_to_agent->read(agent_to_bus_req);
                if ((agent_to_bus_req.trans_type == SINGLE_READ)) {
                  if(!coveragePoints["MasterAgent_4"]){
                    coveragePoints["MasterAgent_4"] = true;
                    coveragePointsCount++;
                  }
                  section = READ;
                } else {
                  if(!coveragePoints["MasterAgent_5"]){
                    coveragePoints["MasterAgent_5"] = true;
                    coveragePointsCount++;
                  }
                  section = WRITE;
                }
              }
              else if (section==READ) {
                if(!coveragePoints["MasterAgent_6"]){
                  coveragePoints["MasterAgent_6"] = true;
                  coveragePointsCount++;
                }
                wb_out.addr = agent_to_bus_req.addr;
                wb_out.data = 0;
                wb_out.we = false;
                wb_out.cyc = true;
                wb_out.stb = true;
                agent_to_bus->set(wb_out);
                section = WAITING;
              }
              else if (section==WAITING) {
                if(!coveragePoints["MasterAgent_7"]){
                  coveragePoints["MasterAgent_7"] = true;
                  coveragePointsCount++;
                }
                clk->read(clk_pulse);
                bus_to_agent->get(wb_in);
                if ((wb_in.ack == true)) {
                  if(!coveragePoints["MasterAgent_8"]){
                    coveragePoints["MasterAgent_8"] = true;
                    coveragePointsCount++;
                  }
                  agent_to_bus_resp.ack = OK;
                  agent_to_bus_resp.data = wb_in.data;
                  if ((wb_in.err == true)) {
                    if(!coveragePoints["MasterAgent_9"]){
                      coveragePoints["MasterAgent_9"] = true;
                      coveragePointsCount++;
                    }
                    agent_to_bus_resp.ack = ERR;
                  }
                  wb_out.addr = 0;
                  wb_out.data = 0;
                  wb_out.we = false;
                  wb_out.cyc = false;
                  wb_out.stb = false;
                  agent_to_bus->set(wb_out);
                  section = DONE;
                }
              }
              else if (section==WRITE) {
                if(!coveragePoints["MasterAgent_10"]){
                  coveragePoints["MasterAgent_10"] = true;
                  coveragePointsCount++;
                }
                wb_out.addr = agent_to_bus_req.addr;
                wb_out.data = agent_to_bus_req.data;
                wb_out.we = true;
                wb_out.cyc = true;
                wb_out.stb = true;
                agent_to_bus->set(wb_out);
                section = WAITING;
              }
              wait(SC_ZERO_TIME);
            }//end of while
        }//end of FSM
        int coveragePointsTotal = 10;
        int coveragePointsCount = 0;
        std::map<std::string, bool> coveragePoints;

        SC_HAS_PROCESS(MasterAgent);

        MasterAgent(sc_module_name name) :
          section(IDLE),
          clk_pulse(false)        {
          SC_THREAD(FSM);
          for(int i = 1; i < coveragePointsTotal; i++)
                    coveragePoints.insert(std::make_pair("MasterAgent_"+to_string(i),false));
          }
        };//end of module


#endif //SYSTEMC_MasterAgent_H
