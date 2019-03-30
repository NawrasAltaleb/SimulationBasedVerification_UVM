#ifndef SYSTEMC_ALU_H
#define SYSTEMC_ALU_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

  struct ALU : public sc_module {

    enum Sections {run};
    Sections section;

    slave_out<ALUtoCtl_IF> ALUtoCtl_port;
    slave_in<CtlToALU_IF> CtlToALU_port;

    //functions

    ALUtoCtl_IF ALUtoCtl_data;
    CtlToALU_IF CtlToALU_data;
    unsigned alu_op1;
    unsigned alu_op2;
    bool rec;


    void FSM(){
        while(true) {
          if (section==run) {
            if(!coveragePoints["ALU_1"]){
              coveragePoints["ALU_1"] = true;
              coveragePointsCount++;
            }
            rec = CtlToALU_port->nb_read(CtlToALU_data);
            if (rec) {
              if(!coveragePoints["ALU_2"]){
                coveragePoints["ALU_2"] = true;
                coveragePointsCount++;
              }
              ALUtoCtl_data.ALU_result = 0;
              if ((CtlToALU_data.op1_sel == OP_REG)) {
                if(!coveragePoints["ALU_3"]){
                  coveragePoints["ALU_3"] = true;
                  coveragePointsCount++;
                }
                alu_op1 = CtlToALU_data.reg1_contents;
              } else {
                if(!coveragePoints["ALU_4"]){
                  coveragePoints["ALU_4"] = true;
                  coveragePointsCount++;
                }
                if ((CtlToALU_data.op1_sel == OP_IMM)) {
                  if(!coveragePoints["ALU_5"]){
                    coveragePoints["ALU_5"] = true;
                    coveragePointsCount++;
                  }
                  alu_op1 = CtlToALU_data.imm;
                } else {
                  if(!coveragePoints["ALU_6"]){
                    coveragePoints["ALU_6"] = true;
                    coveragePointsCount++;
                  }
                  if ((CtlToALU_data.op1_sel == OP_PC)) {
                    if(!coveragePoints["ALU_7"]){
                      coveragePoints["ALU_7"] = true;
                      coveragePointsCount++;
                    }
                    alu_op1 = CtlToALU_data.pc_reg;
                  } else {
                    if(!coveragePoints["ALU_8"]){
                      coveragePoints["ALU_8"] = true;
                      coveragePointsCount++;
                    }
                    alu_op1 = 0;
                  }
                }
              }
              if ((CtlToALU_data.op2_sel == OP_REG)) {
                if(!coveragePoints["ALU_9"]){
                  coveragePoints["ALU_9"] = true;
                  coveragePointsCount++;
                }
                alu_op2 = CtlToALU_data.reg2_contents;
              } else {
                if(!coveragePoints["ALU_10"]){
                  coveragePoints["ALU_10"] = true;
                  coveragePointsCount++;
                }
                if ((CtlToALU_data.op2_sel == OP_IMM)) {
                  if(!coveragePoints["ALU_11"]){
                    coveragePoints["ALU_11"] = true;
                    coveragePointsCount++;
                  }
                  alu_op2 = CtlToALU_data.imm;
                } else {
                  if(!coveragePoints["ALU_12"]){
                    coveragePoints["ALU_12"] = true;
                    coveragePointsCount++;
                  }
                  if ((CtlToALU_data.op2_sel == OP_PC)) {
                    if(!coveragePoints["ALU_13"]){
                      coveragePoints["ALU_13"] = true;
                      coveragePointsCount++;
                    }
                    alu_op2 = CtlToALU_data.pc_reg;
                  } else {
                    if(!coveragePoints["ALU_14"]){
                      coveragePoints["ALU_14"] = true;
                      coveragePointsCount++;
                    }
                    alu_op2 = 0;
                  }
                }
              }
              if ((CtlToALU_data.alu_fun != ALU_X)) {
                if(!coveragePoints["ALU_15"]){
                  coveragePoints["ALU_15"] = true;
                  coveragePointsCount++;
                }
                if ((CtlToALU_data.alu_fun == ALU_ADD)) {
                  if(!coveragePoints["ALU_16"]){
                    coveragePoints["ALU_16"] = true;
                    coveragePointsCount++;
                  }
                  ALUtoCtl_data.ALU_result = (alu_op1 + alu_op2);
                } else {
                  if(!coveragePoints["ALU_17"]){
                    coveragePoints["ALU_17"] = true;
                    coveragePointsCount++;
                  }
                  if ((CtlToALU_data.alu_fun == ALU_SUB)) {
                    if(!coveragePoints["ALU_18"]){
                      coveragePoints["ALU_18"] = true;
                      coveragePointsCount++;
                    }
                    ALUtoCtl_data.ALU_result = (alu_op1 + -(alu_op2));
                  } else {
                    if(!coveragePoints["ALU_19"]){
                      coveragePoints["ALU_19"] = true;
                      coveragePointsCount++;
                    }
                    if ((CtlToALU_data.alu_fun == ALU_AND)) {
                      if(!coveragePoints["ALU_20"]){
                        coveragePoints["ALU_20"] = true;
                        coveragePointsCount++;
                      }
                      ALUtoCtl_data.ALU_result = (alu_op1 & alu_op2);
                    } else {
                      if(!coveragePoints["ALU_21"]){
                        coveragePoints["ALU_21"] = true;
                        coveragePointsCount++;
                      }
                      if ((CtlToALU_data.alu_fun == ALU_OR)) {
                        if(!coveragePoints["ALU_22"]){
                          coveragePoints["ALU_22"] = true;
                          coveragePointsCount++;
                        }
                        ALUtoCtl_data.ALU_result = (alu_op1 | alu_op2);
                      } else {
                        if(!coveragePoints["ALU_23"]){
                          coveragePoints["ALU_23"] = true;
                          coveragePointsCount++;
                        }
                        if ((CtlToALU_data.alu_fun == ALU_XOR)) {
                          if(!coveragePoints["ALU_24"]){
                            coveragePoints["ALU_24"] = true;
                            coveragePointsCount++;
                          }
                          ALUtoCtl_data.ALU_result = (alu_op1 ^ alu_op2);
                        } else {
                          if(!coveragePoints["ALU_25"]){
                            coveragePoints["ALU_25"] = true;
                            coveragePointsCount++;
                          }
                          if ((CtlToALU_data.alu_fun == ALU_SLT)) {
                            if(!coveragePoints["ALU_26"]){
                              coveragePoints["ALU_26"] = true;
                              coveragePointsCount++;
                            }
                            if ((static_cast<int>(alu_op1) < static_cast<int>(alu_op2))) {
                              if(!coveragePoints["ALU_27"]){
                                coveragePoints["ALU_27"] = true;
                                coveragePointsCount++;
                              }
                              ALUtoCtl_data.ALU_result = 1;
                            } else {
                              if(!coveragePoints["ALU_28"]){
                                coveragePoints["ALU_28"] = true;
                                coveragePointsCount++;
                              }
                              ALUtoCtl_data.ALU_result = 0;
                            }
                          } else {
                            if(!coveragePoints["ALU_29"]){
                              coveragePoints["ALU_29"] = true;
                              coveragePointsCount++;
                            }
                            if ((CtlToALU_data.alu_fun == ALU_SLTU)) {
                              if(!coveragePoints["ALU_30"]){
                                coveragePoints["ALU_30"] = true;
                                coveragePointsCount++;
                              }
                              if ((alu_op1 < alu_op2)) {
                                if(!coveragePoints["ALU_31"]){
                                  coveragePoints["ALU_31"] = true;
                                  coveragePointsCount++;
                                }
                                ALUtoCtl_data.ALU_result = 1;
                              } else {
                                if(!coveragePoints["ALU_32"]){
                                  coveragePoints["ALU_32"] = true;
                                  coveragePointsCount++;
                                }
                                ALUtoCtl_data.ALU_result = 0;
                              }
                            } else {
                              if(!coveragePoints["ALU_33"]){
                                coveragePoints["ALU_33"] = true;
                                coveragePointsCount++;
                              }
                              if ((CtlToALU_data.alu_fun == ALU_SLL)) {
                                if(!coveragePoints["ALU_34"]){
                                  coveragePoints["ALU_34"] = true;
                                  coveragePointsCount++;
                                }
                                ALUtoCtl_data.ALU_result = (alu_op1 << (alu_op2 & 31));
                              } else {
                                if(!coveragePoints["ALU_35"]){
                                  coveragePoints["ALU_35"] = true;
                                  coveragePointsCount++;
                                }
                                if ((CtlToALU_data.alu_fun == ALU_SRA)) {
                                  if(!coveragePoints["ALU_36"]){
                                    coveragePoints["ALU_36"] = true;
                                    coveragePointsCount++;
                                  }
                                  ALUtoCtl_data.ALU_result = static_cast<unsigned>((static_cast<int>(alu_op1) >> static_cast<int>((alu_op2 & 31))));
                                } else {
                                  if(!coveragePoints["ALU_37"]){
                                    coveragePoints["ALU_37"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((CtlToALU_data.alu_fun == ALU_SRL)) {
                                    if(!coveragePoints["ALU_38"]){
                                      coveragePoints["ALU_38"] = true;
                                      coveragePointsCount++;
                                    }
                                    ALUtoCtl_data.ALU_result = (alu_op1 >> (alu_op2 & 31));
                                  } else {
                                    if(!coveragePoints["ALU_39"]){
                                      coveragePoints["ALU_39"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((CtlToALU_data.alu_fun == ALU_COPY1)) {
                                      if(!coveragePoints["ALU_40"]){
                                        coveragePoints["ALU_40"] = true;
                                        coveragePointsCount++;
                                      }
                                      ALUtoCtl_data.ALU_result = alu_op1;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            ALUtoCtl_port->nb_write(ALUtoCtl_data);
          }
          wait(SC_ZERO_TIME);
        }//end of while
    }//end of FSM
    int coveragePointsTotal = 40;
    int coveragePointsCount = 0;
    std::map<std::string, bool> coveragePoints;

    SC_HAS_PROCESS(ALU);

    ALU(sc_module_name name) :
      section(run),
      alu_op1(0),
      alu_op2(0),
      rec(false)    {
      SC_THREAD(FSM);
      for(int i = 1; i < coveragePointsTotal; i++)
            coveragePoints.insert(std::make_pair("ALU_"+to_string(i),false));
      }
    };//end of module


#endif //SYSTEMC_ALU_H
