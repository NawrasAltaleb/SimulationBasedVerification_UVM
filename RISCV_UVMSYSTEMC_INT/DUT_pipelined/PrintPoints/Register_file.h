#ifndef SYSTEMC_Register_file_H
#define SYSTEMC_Register_file_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

struct Register_file : public sc_module {

    enum Sections {run};
    Sections section;

    slave_in<DPtoRF_IF> DPtoRF_port;
    slave_out<RFtoDP_IF> RFtoDP_port;

    //functions

    DPtoRF_IF DPtoRF_data;
    RFtoDP_IF RFtoDP_data;
    bool rec;
    unsigned reg_file_01;
    unsigned reg_file_02;
    unsigned reg_file_03;
    unsigned reg_file_04;
    unsigned reg_file_05;
    unsigned reg_file_06;
    unsigned reg_file_07;
    unsigned reg_file_08;
    unsigned reg_file_09;
    unsigned reg_file_10;
    unsigned reg_file_11;
    unsigned reg_file_12;
    unsigned reg_file_13;
    unsigned reg_file_14;
    unsigned reg_file_15;
    unsigned reg_file_16;
    unsigned reg_file_17;
    unsigned reg_file_18;
    unsigned reg_file_19;
    unsigned reg_file_20;
    unsigned reg_file_21;
    unsigned reg_file_22;
    unsigned reg_file_23;
    unsigned reg_file_24;
    unsigned reg_file_25;
    unsigned reg_file_26;
    unsigned reg_file_27;
    unsigned reg_file_28;
    unsigned reg_file_29;
    unsigned reg_file_30;
    unsigned reg_file_31;


    void FSM(){
      while(true) {
        if (section==run) {
          if(!coveragePoints["Register_file_1"]){
            coveragePoints["Register_file_1"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Register_file_1\n";
          }
          RFtoDP_data.reg_file_01 = reg_file_01;
          RFtoDP_data.reg_file_02 = reg_file_02;
          RFtoDP_data.reg_file_03 = reg_file_03;
          RFtoDP_data.reg_file_04 = reg_file_04;
          RFtoDP_data.reg_file_05 = reg_file_05;
          RFtoDP_data.reg_file_06 = reg_file_06;
          RFtoDP_data.reg_file_07 = reg_file_07;
          RFtoDP_data.reg_file_08 = reg_file_08;
          RFtoDP_data.reg_file_09 = reg_file_09;
          RFtoDP_data.reg_file_10 = reg_file_10;
          RFtoDP_data.reg_file_11 = reg_file_11;
          RFtoDP_data.reg_file_12 = reg_file_12;
          RFtoDP_data.reg_file_13 = reg_file_13;
          RFtoDP_data.reg_file_14 = reg_file_14;
          RFtoDP_data.reg_file_15 = reg_file_15;
          RFtoDP_data.reg_file_16 = reg_file_16;
          RFtoDP_data.reg_file_17 = reg_file_17;
          RFtoDP_data.reg_file_18 = reg_file_18;
          RFtoDP_data.reg_file_19 = reg_file_19;
          RFtoDP_data.reg_file_20 = reg_file_20;
          RFtoDP_data.reg_file_21 = reg_file_21;
          RFtoDP_data.reg_file_22 = reg_file_22;
          RFtoDP_data.reg_file_23 = reg_file_23;
          RFtoDP_data.reg_file_24 = reg_file_24;
          RFtoDP_data.reg_file_25 = reg_file_25;
          RFtoDP_data.reg_file_26 = reg_file_26;
          RFtoDP_data.reg_file_27 = reg_file_27;
          RFtoDP_data.reg_file_28 = reg_file_28;
          RFtoDP_data.reg_file_29 = reg_file_29;
          RFtoDP_data.reg_file_30 = reg_file_30;
          RFtoDP_data.reg_file_31 = reg_file_31;
          RFtoDP_port->nb_write(RFtoDP_data);
          rec = DPtoRF_port->nb_read(DPtoRF_data);
          if (rec) {
            if(!coveragePoints["Register_file_2"]){
              coveragePoints["Register_file_2"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Register_file_2\n";
            }
            if (((DPtoRF_data.wrReq == RF_WR) and (DPtoRF_data.dst != 0))) {
              if(!coveragePoints["Register_file_3"]){
                coveragePoints["Register_file_3"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Register_file_3\n";
              }
              if ((DPtoRF_data.dst == 1)) {
                if(!coveragePoints["Register_file_4"]){
                  coveragePoints["Register_file_4"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Register_file_4\n";
                }
                reg_file_01 = DPtoRF_data.dstData;
              } else {
                if(!coveragePoints["Register_file_5"]){
                  coveragePoints["Register_file_5"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Register_file_5\n";
                }
                if ((DPtoRF_data.dst == 2)) {
                  if(!coveragePoints["Register_file_6"]){
                    coveragePoints["Register_file_6"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Register_file_6\n";
                  }
                  reg_file_02 = DPtoRF_data.dstData;
                } else {
                  if(!coveragePoints["Register_file_7"]){
                    coveragePoints["Register_file_7"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Register_file_7\n";
                  }
                  if ((DPtoRF_data.dst == 3)) {
                    if(!coveragePoints["Register_file_8"]){
                      coveragePoints["Register_file_8"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Register_file_8\n";
                    }
                    reg_file_03 = DPtoRF_data.dstData;
                  } else {
                    if(!coveragePoints["Register_file_9"]){
                      coveragePoints["Register_file_9"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Register_file_9\n";
                    }
                    if ((DPtoRF_data.dst == 4)) {
                      if(!coveragePoints["Register_file_10"]){
                        coveragePoints["Register_file_10"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Register_file_10\n";
                      }
                      reg_file_04 = DPtoRF_data.dstData;
                    } else {
                      if(!coveragePoints["Register_file_11"]){
                        coveragePoints["Register_file_11"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Register_file_11\n";
                      }
                      if ((DPtoRF_data.dst == 5)) {
                        if(!coveragePoints["Register_file_12"]){
                          coveragePoints["Register_file_12"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Register_file_12\n";
                        }
                        reg_file_05 = DPtoRF_data.dstData;
                      } else {
                        if(!coveragePoints["Register_file_13"]){
                          coveragePoints["Register_file_13"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Register_file_13\n";
                        }
                        if ((DPtoRF_data.dst == 6)) {
                          if(!coveragePoints["Register_file_14"]){
                            coveragePoints["Register_file_14"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Register_file_14\n";
                          }
                          reg_file_06 = DPtoRF_data.dstData;
                        } else {
                          if(!coveragePoints["Register_file_15"]){
                            coveragePoints["Register_file_15"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Register_file_15\n";
                          }
                          if ((DPtoRF_data.dst == 7)) {
                            if(!coveragePoints["Register_file_16"]){
                              coveragePoints["Register_file_16"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Register_file_16\n";
                            }
                            reg_file_07 = DPtoRF_data.dstData;
                          } else {
                            if(!coveragePoints["Register_file_17"]){
                              coveragePoints["Register_file_17"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Register_file_17\n";
                            }
                            if ((DPtoRF_data.dst == 8)) {
                              if(!coveragePoints["Register_file_18"]){
                                coveragePoints["Register_file_18"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Register_file_18\n";
                              }
                              reg_file_08 = DPtoRF_data.dstData;
                            } else {
                              if(!coveragePoints["Register_file_19"]){
                                coveragePoints["Register_file_19"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Register_file_19\n";
                              }
                              if ((DPtoRF_data.dst == 9)) {
                                if(!coveragePoints["Register_file_20"]){
                                  coveragePoints["Register_file_20"] = true;
                                  coveragePointsCount++;
                                  std::cout<<"Coverage Percentage: Register_file_20\n";
                                }
                                reg_file_09 = DPtoRF_data.dstData;
                              } else {
                                if(!coveragePoints["Register_file_21"]){
                                  coveragePoints["Register_file_21"] = true;
                                  coveragePointsCount++;
                                  std::cout<<"Coverage Percentage: Register_file_21\n";
                                }
                                if ((DPtoRF_data.dst == 10)) {
                                  if(!coveragePoints["Register_file_22"]){
                                    coveragePoints["Register_file_22"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Register_file_22\n";
                                  }
                                  reg_file_10 = DPtoRF_data.dstData;
                                } else {
                                  if(!coveragePoints["Register_file_23"]){
                                    coveragePoints["Register_file_23"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Register_file_23\n";
                                  }
                                  if ((DPtoRF_data.dst == 11)) {
                                    if(!coveragePoints["Register_file_24"]){
                                      coveragePoints["Register_file_24"] = true;
                                      coveragePointsCount++;
                                      std::cout<<"Coverage Percentage: Register_file_24\n";
                                    }
                                    reg_file_11 = DPtoRF_data.dstData;
                                  } else {
                                    if(!coveragePoints["Register_file_25"]){
                                      coveragePoints["Register_file_25"] = true;
                                      coveragePointsCount++;
                                      std::cout<<"Coverage Percentage: Register_file_25\n";
                                    }
                                    if ((DPtoRF_data.dst == 12)) {
                                      if(!coveragePoints["Register_file_26"]){
                                        coveragePoints["Register_file_26"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Register_file_26\n";
                                      }
                                      reg_file_12 = DPtoRF_data.dstData;
                                    } else {
                                      if(!coveragePoints["Register_file_27"]){
                                        coveragePoints["Register_file_27"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Register_file_27\n";
                                      }
                                      if ((DPtoRF_data.dst == 13)) {
                                        if(!coveragePoints["Register_file_28"]){
                                          coveragePoints["Register_file_28"] = true;
                                          coveragePointsCount++;
                                          std::cout<<"Coverage Percentage: Register_file_28\n";
                                        }
                                        reg_file_13 = DPtoRF_data.dstData;
                                      } else {
                                        if(!coveragePoints["Register_file_29"]){
                                          coveragePoints["Register_file_29"] = true;
                                          coveragePointsCount++;
                                          std::cout<<"Coverage Percentage: Register_file_29\n";
                                        }
                                        if ((DPtoRF_data.dst == 14)) {
                                          if(!coveragePoints["Register_file_30"]){
                                            coveragePoints["Register_file_30"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Register_file_30\n";
                                          }
                                          reg_file_14 = DPtoRF_data.dstData;
                                        } else {
                                          if(!coveragePoints["Register_file_31"]){
                                            coveragePoints["Register_file_31"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Register_file_31\n";
                                          }
                                          if ((DPtoRF_data.dst == 15)) {
                                            if(!coveragePoints["Register_file_32"]){
                                              coveragePoints["Register_file_32"] = true;
                                              coveragePointsCount++;
                                              std::cout<<"Coverage Percentage: Register_file_32\n";
                                            }
                                            reg_file_15 = DPtoRF_data.dstData;
                                          } else {
                                            if(!coveragePoints["Register_file_33"]){
                                              coveragePoints["Register_file_33"] = true;
                                              coveragePointsCount++;
                                              std::cout<<"Coverage Percentage: Register_file_33\n";
                                            }
                                            if ((DPtoRF_data.dst == 16)) {
                                              if(!coveragePoints["Register_file_34"]){
                                                coveragePoints["Register_file_34"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Register_file_34\n";
                                              }
                                              reg_file_16 = DPtoRF_data.dstData;
                                            } else {
                                              if(!coveragePoints["Register_file_35"]){
                                                coveragePoints["Register_file_35"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Register_file_35\n";
                                              }
                                              if ((DPtoRF_data.dst == 17)) {
                                                if(!coveragePoints["Register_file_36"]){
                                                  coveragePoints["Register_file_36"] = true;
                                                  coveragePointsCount++;
                                                  std::cout<<"Coverage Percentage: Register_file_36\n";
                                                }
                                                reg_file_17 = DPtoRF_data.dstData;
                                              } else {
                                                if(!coveragePoints["Register_file_37"]){
                                                  coveragePoints["Register_file_37"] = true;
                                                  coveragePointsCount++;
                                                  std::cout<<"Coverage Percentage: Register_file_37\n";
                                                }
                                                if ((DPtoRF_data.dst == 18)) {
                                                  if(!coveragePoints["Register_file_38"]){
                                                    coveragePoints["Register_file_38"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Register_file_38\n";
                                                  }
                                                  reg_file_18 = DPtoRF_data.dstData;
                                                } else {
                                                  if(!coveragePoints["Register_file_39"]){
                                                    coveragePoints["Register_file_39"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Register_file_39\n";
                                                  }
                                                  if ((DPtoRF_data.dst == 19)) {
                                                    if(!coveragePoints["Register_file_40"]){
                                                      coveragePoints["Register_file_40"] = true;
                                                      coveragePointsCount++;
                                                      std::cout<<"Coverage Percentage: Register_file_40\n";
                                                    }
                                                    reg_file_19 = DPtoRF_data.dstData;
                                                  } else {
                                                    if(!coveragePoints["Register_file_41"]){
                                                      coveragePoints["Register_file_41"] = true;
                                                      coveragePointsCount++;
                                                      std::cout<<"Coverage Percentage: Register_file_41\n";
                                                    }
                                                    if ((DPtoRF_data.dst == 20)) {
                                                      if(!coveragePoints["Register_file_42"]){
                                                        coveragePoints["Register_file_42"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Register_file_42\n";
                                                      }
                                                      reg_file_20 = DPtoRF_data.dstData;
                                                    } else {
                                                      if(!coveragePoints["Register_file_43"]){
                                                        coveragePoints["Register_file_43"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Register_file_43\n";
                                                      }
                                                      if ((DPtoRF_data.dst == 21)) {
                                                        if(!coveragePoints["Register_file_44"]){
                                                          coveragePoints["Register_file_44"] = true;
                                                          coveragePointsCount++;
                                                          std::cout<<"Coverage Percentage: Register_file_44\n";
                                                        }
                                                        reg_file_21 = DPtoRF_data.dstData;
                                                      } else {
                                                        if(!coveragePoints["Register_file_45"]){
                                                          coveragePoints["Register_file_45"] = true;
                                                          coveragePointsCount++;
                                                          std::cout<<"Coverage Percentage: Register_file_45\n";
                                                        }
                                                        if ((DPtoRF_data.dst == 22)) {
                                                          if(!coveragePoints["Register_file_46"]){
                                                            coveragePoints["Register_file_46"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Register_file_46\n";
                                                          }
                                                          reg_file_22 = DPtoRF_data.dstData;
                                                        } else {
                                                          if(!coveragePoints["Register_file_47"]){
                                                            coveragePoints["Register_file_47"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Register_file_47\n";
                                                          }
                                                          if ((DPtoRF_data.dst == 23)) {
                                                            if(!coveragePoints["Register_file_48"]){
                                                              coveragePoints["Register_file_48"] = true;
                                                              coveragePointsCount++;
                                                              std::cout<<"Coverage Percentage: Register_file_48\n";
                                                            }
                                                            reg_file_23 = DPtoRF_data.dstData;
                                                          } else {
                                                            if(!coveragePoints["Register_file_49"]){
                                                              coveragePoints["Register_file_49"] = true;
                                                              coveragePointsCount++;
                                                              std::cout<<"Coverage Percentage: Register_file_49\n";
                                                            }
                                                            if ((DPtoRF_data.dst == 24)) {
                                                              if(!coveragePoints["Register_file_50"]){
                                                                coveragePoints["Register_file_50"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Register_file_50\n";
                                                              }
                                                              reg_file_24 = DPtoRF_data.dstData;
                                                            } else {
                                                              if(!coveragePoints["Register_file_51"]){
                                                                coveragePoints["Register_file_51"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Register_file_51\n";
                                                              }
                                                              if ((DPtoRF_data.dst == 25)) {
                                                                if(!coveragePoints["Register_file_52"]){
                                                                  coveragePoints["Register_file_52"] = true;
                                                                  coveragePointsCount++;
                                                                  std::cout<<"Coverage Percentage: Register_file_52\n";
                                                                }
                                                                reg_file_25 = DPtoRF_data.dstData;
                                                              } else {
                                                                if(!coveragePoints["Register_file_53"]){
                                                                  coveragePoints["Register_file_53"] = true;
                                                                  coveragePointsCount++;
                                                                  std::cout<<"Coverage Percentage: Register_file_53\n";
                                                                }
                                                                if ((DPtoRF_data.dst == 26)) {
                                                                  if(!coveragePoints["Register_file_54"]){
                                                                    coveragePoints["Register_file_54"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Register_file_54\n";
                                                                  }
                                                                  reg_file_26 = DPtoRF_data.dstData;
                                                                } else {
                                                                  if(!coveragePoints["Register_file_55"]){
                                                                    coveragePoints["Register_file_55"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Register_file_55\n";
                                                                  }
                                                                  if ((DPtoRF_data.dst == 27)) {
                                                                    if(!coveragePoints["Register_file_56"]){
                                                                      coveragePoints["Register_file_56"] = true;
                                                                      coveragePointsCount++;
                                                                      std::cout<<"Coverage Percentage: Register_file_56\n";
                                                                    }
                                                                    reg_file_27 = DPtoRF_data.dstData;
                                                                  } else {
                                                                    if(!coveragePoints["Register_file_57"]){
                                                                      coveragePoints["Register_file_57"] = true;
                                                                      coveragePointsCount++;
                                                                      std::cout<<"Coverage Percentage: Register_file_57\n";
                                                                    }
                                                                    if ((DPtoRF_data.dst == 28)) {
                                                                      if(!coveragePoints["Register_file_58"]){
                                                                        coveragePoints["Register_file_58"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Register_file_58\n";
                                                                      }
                                                                      reg_file_28 = DPtoRF_data.dstData;
                                                                    } else {
                                                                      if(!coveragePoints["Register_file_59"]){
                                                                        coveragePoints["Register_file_59"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Register_file_59\n";
                                                                      }
                                                                      if ((DPtoRF_data.dst == 29)) {
                                                                        if(!coveragePoints["Register_file_60"]){
                                                                          coveragePoints["Register_file_60"] = true;
                                                                          coveragePointsCount++;
                                                                          std::cout<<"Coverage Percentage: Register_file_60\n";
                                                                        }
                                                                        reg_file_29 = DPtoRF_data.dstData;
                                                                      } else {
                                                                        if(!coveragePoints["Register_file_61"]){
                                                                          coveragePoints["Register_file_61"] = true;
                                                                          coveragePointsCount++;
                                                                          std::cout<<"Coverage Percentage: Register_file_61\n";
                                                                        }
                                                                        if ((DPtoRF_data.dst == 30)) {
                                                                          if(!coveragePoints["Register_file_62"]){
                                                                            coveragePoints["Register_file_62"] = true;
                                                                            coveragePointsCount++;
                                                                            std::cout<<"Coverage Percentage: Register_file_62\n";
                                                                          }
                                                                          reg_file_30 = DPtoRF_data.dstData;
                                                                        } else {
                                                                          if(!coveragePoints["Register_file_63"]){
                                                                            coveragePoints["Register_file_63"] = true;
                                                                            coveragePointsCount++;
                                                                            std::cout<<"Coverage Percentage: Register_file_63\n";
                                                                          }
                                                                          reg_file_31 = DPtoRF_data.dstData;
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
                    }
                  }
                }
              }
            }
          }
        }

      }//end of while
    }//end of FSM
    int coveragePointsTotal = 63;
    int coveragePointsCount = 0;
    std::map<std::string, bool> coveragePoints;

    SC_HAS_PROCESS(Register_file);

    Register_file(sc_module_name name) :
            section(run),
            rec(false),
            reg_file_01(0),
            reg_file_02(0),
            reg_file_03(0),
            reg_file_04(0),
            reg_file_05(0),
            reg_file_06(0),
            reg_file_07(0),
            reg_file_08(0),
            reg_file_09(0),
            reg_file_10(0),
            reg_file_11(0),
            reg_file_12(0),
            reg_file_13(0),
            reg_file_14(0),
            reg_file_15(0),
            reg_file_16(0),
            reg_file_17(0),
            reg_file_18(0),
            reg_file_19(0),
            reg_file_20(0),
            reg_file_21(0),
            reg_file_22(0),
            reg_file_23(0),
            reg_file_24(0),
            reg_file_25(0),
            reg_file_26(0),
            reg_file_27(0),
            reg_file_28(0),
            reg_file_29(0),
            reg_file_30(0),
            reg_file_31(0)        {
      SC_THREAD(FSM);
      for(int i = 1; i < coveragePointsTotal; i++)
        coveragePoints.insert(std::make_pair("Register_file_"+to_string(i),false));
    }
};//end of module


#endif //SYSTEMC_Register_file_H
