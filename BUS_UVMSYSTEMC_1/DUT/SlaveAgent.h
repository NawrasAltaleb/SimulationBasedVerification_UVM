#ifndef SYSTEMC_SlaveAgent_H
#define SYSTEMC_SlaveAgent_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

        struct SlaveAgent : public sc_module {

          enum Sections {DONE, IDLE, READ, WRITE};
          Sections section;

          shared_out<slave_signals> agent_to_bus;
          blocking_out<bus_req_t> agent_to_slave;
          shared_in<master_signals> bus_to_agent;
          master_in<bool> clk;
          blocking_in<bus_resp_t> slave_to_agent;

          //functions

          bus_req_t agent_to_slave_req;
          bool clk_pulse;
          bus_resp_t slave_to_agent_resp;
          master_signals wb_in;
          slave_signals wb_out;


          void FSM(){
              while(true) {
                if (section==DONE) {
                  if(!coveragePoints["SlaveAgent_1"]){
                    coveragePoints["SlaveAgent_1"] = true;
                    coveragePointsCount++;
                  }
                  clk->read(clk_pulse);
                  bus_to_agent->get(wb_in);
                  if (((wb_in.cyc == false) and (wb_in.stb == false))) {
                    if(!coveragePoints["SlaveAgent_2"]){
                      coveragePoints["SlaveAgent_2"] = true;
                      coveragePointsCount++;
                    }
                    wb_out.ack = false;
                    wb_out.err = false;
                    wb_out.data = 0;
                    section = IDLE;
                  } else {
                    if(!coveragePoints["SlaveAgent_3"]){
                      coveragePoints["SlaveAgent_3"] = true;
                      coveragePointsCount++;
                    }
                    wb_out.ack = true;
                    wb_out.err = (slave_to_agent_resp.ack != OK);
                    wb_out.data = 0;
                    if ((wb_in.we == false)) {
                      if(!coveragePoints["SlaveAgent_4"]){
                        coveragePoints["SlaveAgent_4"] = true;
                        coveragePointsCount++;
                      }
                      wb_out.data = slave_to_agent_resp.data;
                    }
                  }
                  agent_to_bus->set(wb_out);
                }
                else if (section==IDLE) {
                  if(!coveragePoints["SlaveAgent_5"]){
                    coveragePoints["SlaveAgent_5"] = true;
                    coveragePointsCount++;
                  }
                  clk->read(clk_pulse);
                  bus_to_agent->get(wb_in);
                  if ((((wb_in.cyc == true) and (wb_in.stb == true)) and (wb_in.we == false))) {
                    if(!coveragePoints["SlaveAgent_6"]){
                      coveragePoints["SlaveAgent_6"] = true;
                      coveragePointsCount++;
                    }
                    section = READ;
                  } else {
                    if(!coveragePoints["SlaveAgent_7"]){
                      coveragePoints["SlaveAgent_7"] = true;
                      coveragePointsCount++;
                    }
                    if ((((wb_in.cyc == true) and (wb_in.stb == true)) and (wb_in.we == true))) {
                      if(!coveragePoints["SlaveAgent_8"]){
                        coveragePoints["SlaveAgent_8"] = true;
                        coveragePointsCount++;
                      }
                      section = WRITE;
                    }
                  }
                }
                else if (section==READ) {
                  if(!coveragePoints["SlaveAgent_9"]){
                    coveragePoints["SlaveAgent_9"] = true;
                    coveragePointsCount++;
                  }
                  agent_to_slave_req.trans_type = SINGLE_READ;
                  agent_to_slave_req.addr = wb_in.addr;
                  agent_to_slave_req.data = 0;
                  agent_to_slave->write(agent_to_slave_req);
                  slave_to_agent->read(slave_to_agent_resp);
                  section = DONE;
                }
                else if (section==WRITE) {
                  if(!coveragePoints["SlaveAgent_10"]){
                    coveragePoints["SlaveAgent_10"] = true;
                    coveragePointsCount++;
                  }
                  agent_to_slave_req.trans_type = SINGLE_WRITE;
                  agent_to_slave_req.addr = wb_in.addr;
                  agent_to_slave_req.data = wb_in.data;
                  agent_to_slave->write(agent_to_slave_req);
                  slave_to_agent->read(slave_to_agent_resp);
                  slave_to_agent_resp.data = 0;
                  section = DONE;
                }
                wait(SC_ZERO_TIME);
              }//end of while
          }//end of FSM
          int coveragePointsTotal = 10;
          int coveragePointsCount = 0;
          std::map<std::string, bool> coveragePoints;

          SC_HAS_PROCESS(SlaveAgent);

          SlaveAgent(sc_module_name name) :
            section(IDLE),
            clk_pulse(false)          {
            SC_THREAD(FSM);
            for(int i = 1; i < coveragePointsTotal; i++)
                        coveragePoints.insert(std::make_pair("SlaveAgent_"+to_string(i),false));
            }
          };//end of module


#endif //SYSTEMC_SlaveAgent_H
