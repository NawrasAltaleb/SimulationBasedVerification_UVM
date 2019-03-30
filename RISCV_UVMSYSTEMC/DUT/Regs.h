#ifndef SYSTEMC_Regs_H
#define SYSTEMC_Regs_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

    struct Regs : public sc_module {

      enum Sections {run};
      Sections section;

      slave_out<RegfileType> fromRegsPort;
      slave_in<RegfileWriteType> toRegsPort;

      //functions

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
      RegfileType regfile;
      RegfileWriteType regfileWrite;


      void FSM(){
          while(true) {
            if (section==run) {
              if(!coveragePoints["Regs_1"]){
                coveragePoints["Regs_1"] = true;
                coveragePointsCount++;
              }
              regfile.reg_file_01 = reg_file_01;
              regfile.reg_file_02 = reg_file_02;
              regfile.reg_file_03 = reg_file_03;
              regfile.reg_file_04 = reg_file_04;
              regfile.reg_file_05 = reg_file_05;
              regfile.reg_file_06 = reg_file_06;
              regfile.reg_file_07 = reg_file_07;
              regfile.reg_file_08 = reg_file_08;
              regfile.reg_file_09 = reg_file_09;
              regfile.reg_file_10 = reg_file_10;
              regfile.reg_file_11 = reg_file_11;
              regfile.reg_file_12 = reg_file_12;
              regfile.reg_file_13 = reg_file_13;
              regfile.reg_file_14 = reg_file_14;
              regfile.reg_file_15 = reg_file_15;
              regfile.reg_file_16 = reg_file_16;
              regfile.reg_file_17 = reg_file_17;
              regfile.reg_file_18 = reg_file_18;
              regfile.reg_file_19 = reg_file_19;
              regfile.reg_file_20 = reg_file_20;
              regfile.reg_file_21 = reg_file_21;
              regfile.reg_file_22 = reg_file_22;
              regfile.reg_file_23 = reg_file_23;
              regfile.reg_file_24 = reg_file_24;
              regfile.reg_file_25 = reg_file_25;
              regfile.reg_file_26 = reg_file_26;
              regfile.reg_file_27 = reg_file_27;
              regfile.reg_file_28 = reg_file_28;
              regfile.reg_file_29 = reg_file_29;
              regfile.reg_file_30 = reg_file_30;
              regfile.reg_file_31 = reg_file_31;
              fromRegsPort->nb_write(regfile);
              rec = toRegsPort->nb_read(regfileWrite);
              if (rec) {
                if(!coveragePoints["Regs_2"]){
                  coveragePoints["Regs_2"] = true;
                  coveragePointsCount++;
                }
                if ((regfileWrite.dst != 0)) {
                  if(!coveragePoints["Regs_3"]){
                    coveragePoints["Regs_3"] = true;
                    coveragePointsCount++;
                  }
                  if ((regfileWrite.dst == 1)) {
                    if(!coveragePoints["Regs_4"]){
                      coveragePoints["Regs_4"] = true;
                      coveragePointsCount++;
                    }
                    reg_file_01 = regfileWrite.dstData;
                  } else {
                    if(!coveragePoints["Regs_5"]){
                      coveragePoints["Regs_5"] = true;
                      coveragePointsCount++;
                    }
                    if ((regfileWrite.dst == 2)) {
                      if(!coveragePoints["Regs_6"]){
                        coveragePoints["Regs_6"] = true;
                        coveragePointsCount++;
                      }
                      reg_file_02 = regfileWrite.dstData;
                    } else {
                      if(!coveragePoints["Regs_7"]){
                        coveragePoints["Regs_7"] = true;
                        coveragePointsCount++;
                      }
                      if ((regfileWrite.dst == 3)) {
                        if(!coveragePoints["Regs_8"]){
                          coveragePoints["Regs_8"] = true;
                          coveragePointsCount++;
                        }
                        reg_file_03 = regfileWrite.dstData;
                      } else {
                        if(!coveragePoints["Regs_9"]){
                          coveragePoints["Regs_9"] = true;
                          coveragePointsCount++;
                        }
                        if ((regfileWrite.dst == 4)) {
                          if(!coveragePoints["Regs_10"]){
                            coveragePoints["Regs_10"] = true;
                            coveragePointsCount++;
                          }
                          reg_file_04 = regfileWrite.dstData;
                        } else {
                          if(!coveragePoints["Regs_11"]){
                            coveragePoints["Regs_11"] = true;
                            coveragePointsCount++;
                          }
                          if ((regfileWrite.dst == 5)) {
                            if(!coveragePoints["Regs_12"]){
                              coveragePoints["Regs_12"] = true;
                              coveragePointsCount++;
                            }
                            reg_file_05 = regfileWrite.dstData;
                          } else {
                            if(!coveragePoints["Regs_13"]){
                              coveragePoints["Regs_13"] = true;
                              coveragePointsCount++;
                            }
                            if ((regfileWrite.dst == 6)) {
                              if(!coveragePoints["Regs_14"]){
                                coveragePoints["Regs_14"] = true;
                                coveragePointsCount++;
                              }
                              reg_file_06 = regfileWrite.dstData;
                            } else {
                              if(!coveragePoints["Regs_15"]){
                                coveragePoints["Regs_15"] = true;
                                coveragePointsCount++;
                              }
                              if ((regfileWrite.dst == 7)) {
                                if(!coveragePoints["Regs_16"]){
                                  coveragePoints["Regs_16"] = true;
                                  coveragePointsCount++;
                                }
                                reg_file_07 = regfileWrite.dstData;
                              } else {
                                if(!coveragePoints["Regs_17"]){
                                  coveragePoints["Regs_17"] = true;
                                  coveragePointsCount++;
                                }
                                if ((regfileWrite.dst == 8)) {
                                  if(!coveragePoints["Regs_18"]){
                                    coveragePoints["Regs_18"] = true;
                                    coveragePointsCount++;
                                  }
                                  reg_file_08 = regfileWrite.dstData;
                                } else {
                                  if(!coveragePoints["Regs_19"]){
                                    coveragePoints["Regs_19"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((regfileWrite.dst == 9)) {
                                    if(!coveragePoints["Regs_20"]){
                                      coveragePoints["Regs_20"] = true;
                                      coveragePointsCount++;
                                    }
                                    reg_file_09 = regfileWrite.dstData;
                                  } else {
                                    if(!coveragePoints["Regs_21"]){
                                      coveragePoints["Regs_21"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((regfileWrite.dst == 10)) {
                                      if(!coveragePoints["Regs_22"]){
                                        coveragePoints["Regs_22"] = true;
                                        coveragePointsCount++;
                                      }
                                      reg_file_10 = regfileWrite.dstData;
                                    } else {
                                      if(!coveragePoints["Regs_23"]){
                                        coveragePoints["Regs_23"] = true;
                                        coveragePointsCount++;
                                      }
                                      if ((regfileWrite.dst == 11)) {
                                        if(!coveragePoints["Regs_24"]){
                                          coveragePoints["Regs_24"] = true;
                                          coveragePointsCount++;
                                        }
                                        reg_file_11 = regfileWrite.dstData;
                                      } else {
                                        if(!coveragePoints["Regs_25"]){
                                          coveragePoints["Regs_25"] = true;
                                          coveragePointsCount++;
                                        }
                                        if ((regfileWrite.dst == 12)) {
                                          if(!coveragePoints["Regs_26"]){
                                            coveragePoints["Regs_26"] = true;
                                            coveragePointsCount++;
                                          }
                                          reg_file_12 = regfileWrite.dstData;
                                        } else {
                                          if(!coveragePoints["Regs_27"]){
                                            coveragePoints["Regs_27"] = true;
                                            coveragePointsCount++;
                                          }
                                          if ((regfileWrite.dst == 13)) {
                                            if(!coveragePoints["Regs_28"]){
                                              coveragePoints["Regs_28"] = true;
                                              coveragePointsCount++;
                                            }
                                            reg_file_13 = regfileWrite.dstData;
                                          } else {
                                            if(!coveragePoints["Regs_29"]){
                                              coveragePoints["Regs_29"] = true;
                                              coveragePointsCount++;
                                            }
                                            if ((regfileWrite.dst == 14)) {
                                              if(!coveragePoints["Regs_30"]){
                                                coveragePoints["Regs_30"] = true;
                                                coveragePointsCount++;
                                              }
                                              reg_file_14 = regfileWrite.dstData;
                                            } else {
                                              if(!coveragePoints["Regs_31"]){
                                                coveragePoints["Regs_31"] = true;
                                                coveragePointsCount++;
                                              }
                                              if ((regfileWrite.dst == 15)) {
                                                if(!coveragePoints["Regs_32"]){
                                                  coveragePoints["Regs_32"] = true;
                                                  coveragePointsCount++;
                                                }
                                                reg_file_15 = regfileWrite.dstData;
                                              } else {
                                                if(!coveragePoints["Regs_33"]){
                                                  coveragePoints["Regs_33"] = true;
                                                  coveragePointsCount++;
                                                }
                                                if ((regfileWrite.dst == 16)) {
                                                  if(!coveragePoints["Regs_34"]){
                                                    coveragePoints["Regs_34"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  reg_file_16 = regfileWrite.dstData;
                                                } else {
                                                  if(!coveragePoints["Regs_35"]){
                                                    coveragePoints["Regs_35"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  if ((regfileWrite.dst == 17)) {
                                                    if(!coveragePoints["Regs_36"]){
                                                      coveragePoints["Regs_36"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    reg_file_17 = regfileWrite.dstData;
                                                  } else {
                                                    if(!coveragePoints["Regs_37"]){
                                                      coveragePoints["Regs_37"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    if ((regfileWrite.dst == 18)) {
                                                      if(!coveragePoints["Regs_38"]){
                                                        coveragePoints["Regs_38"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      reg_file_18 = regfileWrite.dstData;
                                                    } else {
                                                      if(!coveragePoints["Regs_39"]){
                                                        coveragePoints["Regs_39"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      if ((regfileWrite.dst == 19)) {
                                                        if(!coveragePoints["Regs_40"]){
                                                          coveragePoints["Regs_40"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        reg_file_19 = regfileWrite.dstData;
                                                      } else {
                                                        if(!coveragePoints["Regs_41"]){
                                                          coveragePoints["Regs_41"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        if ((regfileWrite.dst == 20)) {
                                                          if(!coveragePoints["Regs_42"]){
                                                            coveragePoints["Regs_42"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          reg_file_20 = regfileWrite.dstData;
                                                        } else {
                                                          if(!coveragePoints["Regs_43"]){
                                                            coveragePoints["Regs_43"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          if ((regfileWrite.dst == 21)) {
                                                            if(!coveragePoints["Regs_44"]){
                                                              coveragePoints["Regs_44"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            reg_file_21 = regfileWrite.dstData;
                                                          } else {
                                                            if(!coveragePoints["Regs_45"]){
                                                              coveragePoints["Regs_45"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            if ((regfileWrite.dst == 22)) {
                                                              if(!coveragePoints["Regs_46"]){
                                                                coveragePoints["Regs_46"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              reg_file_22 = regfileWrite.dstData;
                                                            } else {
                                                              if(!coveragePoints["Regs_47"]){
                                                                coveragePoints["Regs_47"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              if ((regfileWrite.dst == 23)) {
                                                                if(!coveragePoints["Regs_48"]){
                                                                  coveragePoints["Regs_48"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                reg_file_23 = regfileWrite.dstData;
                                                              } else {
                                                                if(!coveragePoints["Regs_49"]){
                                                                  coveragePoints["Regs_49"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                if ((regfileWrite.dst == 24)) {
                                                                  if(!coveragePoints["Regs_50"]){
                                                                    coveragePoints["Regs_50"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  reg_file_24 = regfileWrite.dstData;
                                                                } else {
                                                                  if(!coveragePoints["Regs_51"]){
                                                                    coveragePoints["Regs_51"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  if ((regfileWrite.dst == 25)) {
                                                                    if(!coveragePoints["Regs_52"]){
                                                                      coveragePoints["Regs_52"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    reg_file_25 = regfileWrite.dstData;
                                                                  } else {
                                                                    if(!coveragePoints["Regs_53"]){
                                                                      coveragePoints["Regs_53"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    if ((regfileWrite.dst == 26)) {
                                                                      if(!coveragePoints["Regs_54"]){
                                                                        coveragePoints["Regs_54"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      reg_file_26 = regfileWrite.dstData;
                                                                    } else {
                                                                      if(!coveragePoints["Regs_55"]){
                                                                        coveragePoints["Regs_55"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      if ((regfileWrite.dst == 27)) {
                                                                        if(!coveragePoints["Regs_56"]){
                                                                          coveragePoints["Regs_56"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        reg_file_27 = regfileWrite.dstData;
                                                                      } else {
                                                                        if(!coveragePoints["Regs_57"]){
                                                                          coveragePoints["Regs_57"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        if ((regfileWrite.dst == 28)) {
                                                                          if(!coveragePoints["Regs_58"]){
                                                                            coveragePoints["Regs_58"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          reg_file_28 = regfileWrite.dstData;
                                                                        } else {
                                                                          if(!coveragePoints["Regs_59"]){
                                                                            coveragePoints["Regs_59"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          if ((regfileWrite.dst == 29)) {
                                                                            if(!coveragePoints["Regs_60"]){
                                                                              coveragePoints["Regs_60"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            reg_file_29 = regfileWrite.dstData;
                                                                          } else {
                                                                            if(!coveragePoints["Regs_61"]){
                                                                              coveragePoints["Regs_61"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            if ((regfileWrite.dst == 30)) {
                                                                              if(!coveragePoints["Regs_62"]){
                                                                                coveragePoints["Regs_62"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              reg_file_30 = regfileWrite.dstData;
                                                                            } else {
                                                                              if(!coveragePoints["Regs_63"]){
                                                                                coveragePoints["Regs_63"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              reg_file_31 = regfileWrite.dstData;
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
            wait(SC_ZERO_TIME);
          }//end of while
      }//end of FSM
      int coveragePointsTotal = 63;
      int coveragePointsCount = 0;
      std::map<std::string, bool> coveragePoints;

      SC_HAS_PROCESS(Regs);

      Regs(sc_module_name name) :
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
        reg_file_31(0)      {
        SC_THREAD(FSM);
        for(int i = 1; i < coveragePointsTotal; i++)
                coveragePoints.insert(std::make_pair("Regs_"+to_string(i),false));
        }
      };//end of module


#endif //SYSTEMC_Regs_H
