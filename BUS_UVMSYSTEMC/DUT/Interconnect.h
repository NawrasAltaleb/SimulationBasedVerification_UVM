#ifndef SYSTEMC_Interconnect_H
#define SYSTEMC_Interconnect_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

    struct Interconnect : public sc_module {

      enum Sections {DONE, IDLE, START, TRANSMITTING};
      Sections section;

      master_in<bool> clk;
      shared_in<master_signals> master_input;
      shared_out<slave_signals> master_output;
      shared_in<slave_signals> slave_in0;
      shared_in<slave_signals> slave_in1;
      shared_in<slave_signals> slave_in2;
      shared_in<slave_signals> slave_in3;
      shared_out<master_signals> slave_out0;
      shared_out<master_signals> slave_out1;
      shared_out<master_signals> slave_out2;
      shared_out<master_signals> slave_out3;

      //functions

      bool clk_pulse;
      master_signals from_master;
      int slave_number;
      slave_signals to_master;


      void FSM(){
          while(true) {
            if (section==DONE) {
              if(!coveragePoints["Interconnect_1"]){
                coveragePoints["Interconnect_1"] = true;
                coveragePointsCount++;
              }
              master_output->set(to_master);
              clk->read(clk_pulse);
              master_input->get(from_master);
              if (((from_master.cyc == false) and (from_master.stb == false))) {
                if(!coveragePoints["Interconnect_2"]){
                  coveragePoints["Interconnect_2"] = true;
                  coveragePointsCount++;
                }
                to_master.ack = false;
                to_master.err = false;
                to_master.data = 0;
                master_output->set(to_master);
                section = IDLE;
              }
            }
            else if (section==IDLE) {
              if(!coveragePoints["Interconnect_3"]){
                coveragePoints["Interconnect_3"] = true;
                coveragePointsCount++;
              }
              clk->read(clk_pulse);
              master_input->get(from_master);
              if (((from_master.cyc == true) and (from_master.stb == true))) {
                if(!coveragePoints["Interconnect_4"]){
                  coveragePoints["Interconnect_4"] = true;
                  coveragePointsCount++;
                }
                section = START;
              }
            }
            else if (section==START) {
              if(!coveragePoints["Interconnect_5"]){
                coveragePoints["Interconnect_5"] = true;
                coveragePointsCount++;
              }
              section = TRANSMITTING;
              if (((from_master.addr >= 0) and (from_master.addr < 8))) {
                if(!coveragePoints["Interconnect_6"]){
                  coveragePoints["Interconnect_6"] = true;
                  coveragePointsCount++;
                }
                slave_out0->set(from_master);
                slave_number = 0;
              } else {
                if(!coveragePoints["Interconnect_7"]){
                  coveragePoints["Interconnect_7"] = true;
                  coveragePointsCount++;
                }
                if (((from_master.addr >= 8) and (from_master.addr < 16))) {
                  if(!coveragePoints["Interconnect_8"]){
                    coveragePoints["Interconnect_8"] = true;
                    coveragePointsCount++;
                  }
                  from_master.addr = (from_master.addr - 8);
                  slave_out1->set(from_master);
                  slave_number = 1;
                } else {
                  if(!coveragePoints["Interconnect_9"]){
                    coveragePoints["Interconnect_9"] = true;
                    coveragePointsCount++;
                  }
                  if (((from_master.addr >= 16) and (from_master.addr < 24))) {
                    if(!coveragePoints["Interconnect_10"]){
                      coveragePoints["Interconnect_10"] = true;
                      coveragePointsCount++;
                    }
                    from_master.addr = (from_master.addr - 16);
                    slave_out2->set(from_master);
                    slave_number = 2;
                  } else {
                    if(!coveragePoints["Interconnect_11"]){
                      coveragePoints["Interconnect_11"] = true;
                      coveragePointsCount++;
                    }
                    if (((from_master.addr >= 24) and (from_master.addr < 32))) {
                      if(!coveragePoints["Interconnect_12"]){
                        coveragePoints["Interconnect_12"] = true;
                        coveragePointsCount++;
                      }
                      from_master.addr = (from_master.addr - 24);
                      slave_out3->set(from_master);
                      slave_number = 3;
                    } else {
                      if(!coveragePoints["Interconnect_13"]){
                        coveragePoints["Interconnect_13"] = true;
                        coveragePointsCount++;
                      }
                      to_master.ack = true;
                      to_master.data = 0;
                      to_master.err = false;
                      section = DONE;
                    }
                  }
                }
              }
            }
            else if (section==TRANSMITTING) {
              if(!coveragePoints["Interconnect_14"]){
                coveragePoints["Interconnect_14"] = true;
                coveragePointsCount++;
              }
              from_master.data = 0;
              from_master.addr = 0;
              from_master.cyc = false;
              from_master.stb = false;
              from_master.we = false;
              clk->read(clk_pulse);
              if ((slave_number == 0)) {
                if(!coveragePoints["Interconnect_15"]){
                  coveragePoints["Interconnect_15"] = true;
                  coveragePointsCount++;
                }
                slave_in0->get(to_master);
                slave_number = 0;
                if ((to_master.ack == true)) {
                  if(!coveragePoints["Interconnect_16"]){
                    coveragePoints["Interconnect_16"] = true;
                    coveragePointsCount++;
                  }
                  slave_out0->set(from_master);
                  section = DONE;
                }
              } else {
                if(!coveragePoints["Interconnect_17"]){
                  coveragePoints["Interconnect_17"] = true;
                  coveragePointsCount++;
                }
                if ((slave_number == 1)) {
                  if(!coveragePoints["Interconnect_18"]){
                    coveragePoints["Interconnect_18"] = true;
                    coveragePointsCount++;
                  }
                  slave_in1->get(to_master);
                  slave_number = 1;
                  if ((to_master.ack == true)) {
                    if(!coveragePoints["Interconnect_19"]){
                      coveragePoints["Interconnect_19"] = true;
                      coveragePointsCount++;
                    }
                    slave_out1->set(from_master);
                    section = DONE;
                  }
                } else {
                  if(!coveragePoints["Interconnect_20"]){
                    coveragePoints["Interconnect_20"] = true;
                    coveragePointsCount++;
                  }
                  if ((slave_number == 2)) {
                    if(!coveragePoints["Interconnect_21"]){
                      coveragePoints["Interconnect_21"] = true;
                      coveragePointsCount++;
                    }
                    slave_in2->get(to_master);
                    slave_number = 2;
                    if ((to_master.ack == true)) {
                      if(!coveragePoints["Interconnect_22"]){
                        coveragePoints["Interconnect_22"] = true;
                        coveragePointsCount++;
                      }
                      slave_out2->set(from_master);
                      section = DONE;
                    }
                  } else {
                    if(!coveragePoints["Interconnect_23"]){
                      coveragePoints["Interconnect_23"] = true;
                      coveragePointsCount++;
                    }
                    slave_in3->get(to_master);
                    slave_number = 3;
                    if ((to_master.ack == true)) {
                      if(!coveragePoints["Interconnect_24"]){
                        coveragePoints["Interconnect_24"] = true;
                        coveragePointsCount++;
                      }
                      slave_out3->set(from_master);
                      section = DONE;
                    }
                  }
                }
              }
            }
            wait(SC_ZERO_TIME);
          }//end of while
      }//end of FSM
      int coveragePointsTotal = 24;
      int coveragePointsCount = 0;
      std::map<std::string, bool> coveragePoints;

      SC_HAS_PROCESS(Interconnect);

      Interconnect(sc_module_name name) :
        section(IDLE),
        clk_pulse(false),
        slave_number(0)      {
        SC_THREAD(FSM);
        for(int i = 1; i < coveragePointsTotal; i++)
                coveragePoints.insert(std::make_pair("Interconnect_"+to_string(i),false));
        }
      };//end of module


#endif //SYSTEMC_Interconnect_H
