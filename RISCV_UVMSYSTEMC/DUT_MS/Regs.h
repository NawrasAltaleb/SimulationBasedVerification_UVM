#ifndef SYSTEMC_Regs_H
#define SYSTEMC_Regs_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

        struct Regs : public sc_module {

          enum Sections {run};
          Sections section;

          slave_in<CtlToRegs_IF> CtlToRegs_port;
          slave_out<RegsToCtl_IF> RegsToCtl_port;

          //functions

          CtlToRegs_IF CtlToRegs_data;
          RegsToCtl_IF RegsToCtl_data;
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
                  if(!coveragePoints["Regs_1"]){
                    coveragePoints["Regs_1"] = true;
                    coveragePointsCount++;
                  }
                  rec = CtlToRegs_port->nb_read(CtlToRegs_data);
                  if (rec) {
                    if(!coveragePoints["Regs_2"]){
                      coveragePoints["Regs_2"] = true;
                      coveragePointsCount++;
                    }
                    if ((CtlToRegs_data.req == REG_RD)) {
                      if(!coveragePoints["Regs_3"]){
                        coveragePoints["Regs_3"] = true;
                        coveragePointsCount++;
                      }
                      if ((CtlToRegs_data.src1 == 0)) {
                        if(!coveragePoints["Regs_4"]){
                          coveragePoints["Regs_4"] = true;
                          coveragePointsCount++;
                        }
                        RegsToCtl_data.contents1 = 0;
                      } else {
                        if(!coveragePoints["Regs_5"]){
                          coveragePoints["Regs_5"] = true;
                          coveragePointsCount++;
                        }
                        if ((CtlToRegs_data.src1 == 1)) {
                          if(!coveragePoints["Regs_6"]){
                            coveragePoints["Regs_6"] = true;
                            coveragePointsCount++;
                          }
                          RegsToCtl_data.contents1 = reg_file_01;
                        } else {
                          if(!coveragePoints["Regs_7"]){
                            coveragePoints["Regs_7"] = true;
                            coveragePointsCount++;
                          }
                          if ((CtlToRegs_data.src1 == 2)) {
                            if(!coveragePoints["Regs_8"]){
                              coveragePoints["Regs_8"] = true;
                              coveragePointsCount++;
                            }
                            RegsToCtl_data.contents1 = reg_file_02;
                          } else {
                            if(!coveragePoints["Regs_9"]){
                              coveragePoints["Regs_9"] = true;
                              coveragePointsCount++;
                            }
                            if ((CtlToRegs_data.src1 == 3)) {
                              if(!coveragePoints["Regs_10"]){
                                coveragePoints["Regs_10"] = true;
                                coveragePointsCount++;
                              }
                              RegsToCtl_data.contents1 = reg_file_03;
                            } else {
                              if(!coveragePoints["Regs_11"]){
                                coveragePoints["Regs_11"] = true;
                                coveragePointsCount++;
                              }
                              if ((CtlToRegs_data.src1 == 4)) {
                                if(!coveragePoints["Regs_12"]){
                                  coveragePoints["Regs_12"] = true;
                                  coveragePointsCount++;
                                }
                                RegsToCtl_data.contents1 = reg_file_04;
                              } else {
                                if(!coveragePoints["Regs_13"]){
                                  coveragePoints["Regs_13"] = true;
                                  coveragePointsCount++;
                                }
                                if ((CtlToRegs_data.src1 == 5)) {
                                  if(!coveragePoints["Regs_14"]){
                                    coveragePoints["Regs_14"] = true;
                                    coveragePointsCount++;
                                  }
                                  RegsToCtl_data.contents1 = reg_file_05;
                                } else {
                                  if(!coveragePoints["Regs_15"]){
                                    coveragePoints["Regs_15"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((CtlToRegs_data.src1 == 6)) {
                                    if(!coveragePoints["Regs_16"]){
                                      coveragePoints["Regs_16"] = true;
                                      coveragePointsCount++;
                                    }
                                    RegsToCtl_data.contents1 = reg_file_06;
                                  } else {
                                    if(!coveragePoints["Regs_17"]){
                                      coveragePoints["Regs_17"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((CtlToRegs_data.src1 == 7)) {
                                      if(!coveragePoints["Regs_18"]){
                                        coveragePoints["Regs_18"] = true;
                                        coveragePointsCount++;
                                      }
                                      RegsToCtl_data.contents1 = reg_file_07;
                                    } else {
                                      if(!coveragePoints["Regs_19"]){
                                        coveragePoints["Regs_19"] = true;
                                        coveragePointsCount++;
                                      }
                                      if ((CtlToRegs_data.src1 == 8)) {
                                        if(!coveragePoints["Regs_20"]){
                                          coveragePoints["Regs_20"] = true;
                                          coveragePointsCount++;
                                        }
                                        RegsToCtl_data.contents1 = reg_file_08;
                                      } else {
                                        if(!coveragePoints["Regs_21"]){
                                          coveragePoints["Regs_21"] = true;
                                          coveragePointsCount++;
                                        }
                                        if ((CtlToRegs_data.src1 == 9)) {
                                          if(!coveragePoints["Regs_22"]){
                                            coveragePoints["Regs_22"] = true;
                                            coveragePointsCount++;
                                          }
                                          RegsToCtl_data.contents1 = reg_file_09;
                                        } else {
                                          if(!coveragePoints["Regs_23"]){
                                            coveragePoints["Regs_23"] = true;
                                            coveragePointsCount++;
                                          }
                                          if ((CtlToRegs_data.src1 == 10)) {
                                            if(!coveragePoints["Regs_24"]){
                                              coveragePoints["Regs_24"] = true;
                                              coveragePointsCount++;
                                            }
                                            RegsToCtl_data.contents1 = reg_file_10;
                                          } else {
                                            if(!coveragePoints["Regs_25"]){
                                              coveragePoints["Regs_25"] = true;
                                              coveragePointsCount++;
                                            }
                                            if ((CtlToRegs_data.src1 == 11)) {
                                              if(!coveragePoints["Regs_26"]){
                                                coveragePoints["Regs_26"] = true;
                                                coveragePointsCount++;
                                              }
                                              RegsToCtl_data.contents1 = reg_file_11;
                                            } else {
                                              if(!coveragePoints["Regs_27"]){
                                                coveragePoints["Regs_27"] = true;
                                                coveragePointsCount++;
                                              }
                                              if ((CtlToRegs_data.src1 == 12)) {
                                                if(!coveragePoints["Regs_28"]){
                                                  coveragePoints["Regs_28"] = true;
                                                  coveragePointsCount++;
                                                }
                                                RegsToCtl_data.contents1 = reg_file_12;
                                              } else {
                                                if(!coveragePoints["Regs_29"]){
                                                  coveragePoints["Regs_29"] = true;
                                                  coveragePointsCount++;
                                                }
                                                if ((CtlToRegs_data.src1 == 13)) {
                                                  if(!coveragePoints["Regs_30"]){
                                                    coveragePoints["Regs_30"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  RegsToCtl_data.contents1 = reg_file_13;
                                                } else {
                                                  if(!coveragePoints["Regs_31"]){
                                                    coveragePoints["Regs_31"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  if ((CtlToRegs_data.src1 == 14)) {
                                                    if(!coveragePoints["Regs_32"]){
                                                      coveragePoints["Regs_32"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    RegsToCtl_data.contents1 = reg_file_14;
                                                  } else {
                                                    if(!coveragePoints["Regs_33"]){
                                                      coveragePoints["Regs_33"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    if ((CtlToRegs_data.src1 == 15)) {
                                                      if(!coveragePoints["Regs_34"]){
                                                        coveragePoints["Regs_34"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      RegsToCtl_data.contents1 = reg_file_15;
                                                    } else {
                                                      if(!coveragePoints["Regs_35"]){
                                                        coveragePoints["Regs_35"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      if ((CtlToRegs_data.src1 == 16)) {
                                                        if(!coveragePoints["Regs_36"]){
                                                          coveragePoints["Regs_36"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        RegsToCtl_data.contents1 = reg_file_16;
                                                      } else {
                                                        if(!coveragePoints["Regs_37"]){
                                                          coveragePoints["Regs_37"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        if ((CtlToRegs_data.src1 == 17)) {
                                                          if(!coveragePoints["Regs_38"]){
                                                            coveragePoints["Regs_38"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          RegsToCtl_data.contents1 = reg_file_17;
                                                        } else {
                                                          if(!coveragePoints["Regs_39"]){
                                                            coveragePoints["Regs_39"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          if ((CtlToRegs_data.src1 == 18)) {
                                                            if(!coveragePoints["Regs_40"]){
                                                              coveragePoints["Regs_40"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            RegsToCtl_data.contents1 = reg_file_18;
                                                          } else {
                                                            if(!coveragePoints["Regs_41"]){
                                                              coveragePoints["Regs_41"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            if ((CtlToRegs_data.src1 == 19)) {
                                                              if(!coveragePoints["Regs_42"]){
                                                                coveragePoints["Regs_42"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              RegsToCtl_data.contents1 = reg_file_19;
                                                            } else {
                                                              if(!coveragePoints["Regs_43"]){
                                                                coveragePoints["Regs_43"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              if ((CtlToRegs_data.src1 == 20)) {
                                                                if(!coveragePoints["Regs_44"]){
                                                                  coveragePoints["Regs_44"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                RegsToCtl_data.contents1 = reg_file_20;
                                                              } else {
                                                                if(!coveragePoints["Regs_45"]){
                                                                  coveragePoints["Regs_45"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                if ((CtlToRegs_data.src1 == 21)) {
                                                                  if(!coveragePoints["Regs_46"]){
                                                                    coveragePoints["Regs_46"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  RegsToCtl_data.contents1 = reg_file_21;
                                                                } else {
                                                                  if(!coveragePoints["Regs_47"]){
                                                                    coveragePoints["Regs_47"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  if ((CtlToRegs_data.src1 == 22)) {
                                                                    if(!coveragePoints["Regs_48"]){
                                                                      coveragePoints["Regs_48"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    RegsToCtl_data.contents1 = reg_file_22;
                                                                  } else {
                                                                    if(!coveragePoints["Regs_49"]){
                                                                      coveragePoints["Regs_49"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    if ((CtlToRegs_data.src1 == 23)) {
                                                                      if(!coveragePoints["Regs_50"]){
                                                                        coveragePoints["Regs_50"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      RegsToCtl_data.contents1 = reg_file_23;
                                                                    } else {
                                                                      if(!coveragePoints["Regs_51"]){
                                                                        coveragePoints["Regs_51"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      if ((CtlToRegs_data.src1 == 24)) {
                                                                        if(!coveragePoints["Regs_52"]){
                                                                          coveragePoints["Regs_52"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        RegsToCtl_data.contents1 = reg_file_24;
                                                                      } else {
                                                                        if(!coveragePoints["Regs_53"]){
                                                                          coveragePoints["Regs_53"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        if ((CtlToRegs_data.src1 == 25)) {
                                                                          if(!coveragePoints["Regs_54"]){
                                                                            coveragePoints["Regs_54"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          RegsToCtl_data.contents1 = reg_file_25;
                                                                        } else {
                                                                          if(!coveragePoints["Regs_55"]){
                                                                            coveragePoints["Regs_55"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          if ((CtlToRegs_data.src1 == 26)) {
                                                                            if(!coveragePoints["Regs_56"]){
                                                                              coveragePoints["Regs_56"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            RegsToCtl_data.contents1 = reg_file_26;
                                                                          } else {
                                                                            if(!coveragePoints["Regs_57"]){
                                                                              coveragePoints["Regs_57"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            if ((CtlToRegs_data.src1 == 27)) {
                                                                              if(!coveragePoints["Regs_58"]){
                                                                                coveragePoints["Regs_58"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              RegsToCtl_data.contents1 = reg_file_27;
                                                                            } else {
                                                                              if(!coveragePoints["Regs_59"]){
                                                                                coveragePoints["Regs_59"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              if ((CtlToRegs_data.src1 == 28)) {
                                                                                if(!coveragePoints["Regs_60"]){
                                                                                  coveragePoints["Regs_60"] = true;
                                                                                  coveragePointsCount++;
                                                                                }
                                                                                RegsToCtl_data.contents1 = reg_file_28;
                                                                              } else {
                                                                                if(!coveragePoints["Regs_61"]){
                                                                                  coveragePoints["Regs_61"] = true;
                                                                                  coveragePointsCount++;
                                                                                }
                                                                                if ((CtlToRegs_data.src1 == 29)) {
                                                                                  if(!coveragePoints["Regs_62"]){
                                                                                    coveragePoints["Regs_62"] = true;
                                                                                    coveragePointsCount++;
                                                                                  }
                                                                                  RegsToCtl_data.contents1 = reg_file_29;
                                                                                } else {
                                                                                  if(!coveragePoints["Regs_63"]){
                                                                                    coveragePoints["Regs_63"] = true;
                                                                                    coveragePointsCount++;
                                                                                  }
                                                                                  if ((CtlToRegs_data.src1 == 30)) {
                                                                                    if(!coveragePoints["Regs_64"]){
                                                                                      coveragePoints["Regs_64"] = true;
                                                                                      coveragePointsCount++;
                                                                                    }
                                                                                    RegsToCtl_data.contents1 = reg_file_30;
                                                                                  } else {
                                                                                    if(!coveragePoints["Regs_65"]){
                                                                                      coveragePoints["Regs_65"] = true;
                                                                                      coveragePointsCount++;
                                                                                    }
                                                                                    if ((CtlToRegs_data.src1 == 31)) {
                                                                                      if(!coveragePoints["Regs_66"]){
                                                                                        coveragePoints["Regs_66"] = true;
                                                                                        coveragePointsCount++;
                                                                                      }
                                                                                      RegsToCtl_data.contents1 = reg_file_31;
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
                      if ((CtlToRegs_data.src2 == 0)) {
                        if(!coveragePoints["Regs_67"]){
                          coveragePoints["Regs_67"] = true;
                          coveragePointsCount++;
                        }
                        RegsToCtl_data.contents2 = 0;
                      } else {
                        if(!coveragePoints["Regs_68"]){
                          coveragePoints["Regs_68"] = true;
                          coveragePointsCount++;
                        }
                        if ((CtlToRegs_data.src2 == 1)) {
                          if(!coveragePoints["Regs_69"]){
                            coveragePoints["Regs_69"] = true;
                            coveragePointsCount++;
                          }
                          RegsToCtl_data.contents2 = reg_file_01;
                        } else {
                          if(!coveragePoints["Regs_70"]){
                            coveragePoints["Regs_70"] = true;
                            coveragePointsCount++;
                          }
                          if ((CtlToRegs_data.src2 == 2)) {
                            if(!coveragePoints["Regs_71"]){
                              coveragePoints["Regs_71"] = true;
                              coveragePointsCount++;
                            }
                            RegsToCtl_data.contents2 = reg_file_02;
                          } else {
                            if(!coveragePoints["Regs_72"]){
                              coveragePoints["Regs_72"] = true;
                              coveragePointsCount++;
                            }
                            if ((CtlToRegs_data.src2 == 3)) {
                              if(!coveragePoints["Regs_73"]){
                                coveragePoints["Regs_73"] = true;
                                coveragePointsCount++;
                              }
                              RegsToCtl_data.contents2 = reg_file_03;
                            } else {
                              if(!coveragePoints["Regs_74"]){
                                coveragePoints["Regs_74"] = true;
                                coveragePointsCount++;
                              }
                              if ((CtlToRegs_data.src2 == 4)) {
                                if(!coveragePoints["Regs_75"]){
                                  coveragePoints["Regs_75"] = true;
                                  coveragePointsCount++;
                                }
                                RegsToCtl_data.contents2 = reg_file_04;
                              } else {
                                if(!coveragePoints["Regs_76"]){
                                  coveragePoints["Regs_76"] = true;
                                  coveragePointsCount++;
                                }
                                if ((CtlToRegs_data.src2 == 5)) {
                                  if(!coveragePoints["Regs_77"]){
                                    coveragePoints["Regs_77"] = true;
                                    coveragePointsCount++;
                                  }
                                  RegsToCtl_data.contents2 = reg_file_05;
                                } else {
                                  if(!coveragePoints["Regs_78"]){
                                    coveragePoints["Regs_78"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((CtlToRegs_data.src2 == 6)) {
                                    if(!coveragePoints["Regs_79"]){
                                      coveragePoints["Regs_79"] = true;
                                      coveragePointsCount++;
                                    }
                                    RegsToCtl_data.contents2 = reg_file_06;
                                  } else {
                                    if(!coveragePoints["Regs_80"]){
                                      coveragePoints["Regs_80"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((CtlToRegs_data.src2 == 7)) {
                                      if(!coveragePoints["Regs_81"]){
                                        coveragePoints["Regs_81"] = true;
                                        coveragePointsCount++;
                                      }
                                      RegsToCtl_data.contents2 = reg_file_07;
                                    } else {
                                      if(!coveragePoints["Regs_82"]){
                                        coveragePoints["Regs_82"] = true;
                                        coveragePointsCount++;
                                      }
                                      if ((CtlToRegs_data.src2 == 8)) {
                                        if(!coveragePoints["Regs_83"]){
                                          coveragePoints["Regs_83"] = true;
                                          coveragePointsCount++;
                                        }
                                        RegsToCtl_data.contents2 = reg_file_08;
                                      } else {
                                        if(!coveragePoints["Regs_84"]){
                                          coveragePoints["Regs_84"] = true;
                                          coveragePointsCount++;
                                        }
                                        if ((CtlToRegs_data.src2 == 9)) {
                                          if(!coveragePoints["Regs_85"]){
                                            coveragePoints["Regs_85"] = true;
                                            coveragePointsCount++;
                                          }
                                          RegsToCtl_data.contents2 = reg_file_09;
                                        } else {
                                          if(!coveragePoints["Regs_86"]){
                                            coveragePoints["Regs_86"] = true;
                                            coveragePointsCount++;
                                          }
                                          if ((CtlToRegs_data.src2 == 10)) {
                                            if(!coveragePoints["Regs_87"]){
                                              coveragePoints["Regs_87"] = true;
                                              coveragePointsCount++;
                                            }
                                            RegsToCtl_data.contents2 = reg_file_10;
                                          } else {
                                            if(!coveragePoints["Regs_88"]){
                                              coveragePoints["Regs_88"] = true;
                                              coveragePointsCount++;
                                            }
                                            if ((CtlToRegs_data.src2 == 11)) {
                                              if(!coveragePoints["Regs_89"]){
                                                coveragePoints["Regs_89"] = true;
                                                coveragePointsCount++;
                                              }
                                              RegsToCtl_data.contents2 = reg_file_11;
                                            } else {
                                              if(!coveragePoints["Regs_90"]){
                                                coveragePoints["Regs_90"] = true;
                                                coveragePointsCount++;
                                              }
                                              if ((CtlToRegs_data.src2 == 12)) {
                                                if(!coveragePoints["Regs_91"]){
                                                  coveragePoints["Regs_91"] = true;
                                                  coveragePointsCount++;
                                                }
                                                RegsToCtl_data.contents2 = reg_file_12;
                                              } else {
                                                if(!coveragePoints["Regs_92"]){
                                                  coveragePoints["Regs_92"] = true;
                                                  coveragePointsCount++;
                                                }
                                                if ((CtlToRegs_data.src2 == 13)) {
                                                  if(!coveragePoints["Regs_93"]){
                                                    coveragePoints["Regs_93"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  RegsToCtl_data.contents2 = reg_file_13;
                                                } else {
                                                  if(!coveragePoints["Regs_94"]){
                                                    coveragePoints["Regs_94"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  if ((CtlToRegs_data.src2 == 14)) {
                                                    if(!coveragePoints["Regs_95"]){
                                                      coveragePoints["Regs_95"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    RegsToCtl_data.contents2 = reg_file_14;
                                                  } else {
                                                    if(!coveragePoints["Regs_96"]){
                                                      coveragePoints["Regs_96"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    if ((CtlToRegs_data.src2 == 15)) {
                                                      if(!coveragePoints["Regs_97"]){
                                                        coveragePoints["Regs_97"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      RegsToCtl_data.contents2 = reg_file_15;
                                                    } else {
                                                      if(!coveragePoints["Regs_98"]){
                                                        coveragePoints["Regs_98"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      if ((CtlToRegs_data.src2 == 16)) {
                                                        if(!coveragePoints["Regs_99"]){
                                                          coveragePoints["Regs_99"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        RegsToCtl_data.contents2 = reg_file_16;
                                                      } else {
                                                        if(!coveragePoints["Regs_100"]){
                                                          coveragePoints["Regs_100"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        if ((CtlToRegs_data.src2 == 17)) {
                                                          if(!coveragePoints["Regs_101"]){
                                                            coveragePoints["Regs_101"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          RegsToCtl_data.contents2 = reg_file_17;
                                                        } else {
                                                          if(!coveragePoints["Regs_102"]){
                                                            coveragePoints["Regs_102"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          if ((CtlToRegs_data.src2 == 18)) {
                                                            if(!coveragePoints["Regs_103"]){
                                                              coveragePoints["Regs_103"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            RegsToCtl_data.contents2 = reg_file_18;
                                                          } else {
                                                            if(!coveragePoints["Regs_104"]){
                                                              coveragePoints["Regs_104"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            if ((CtlToRegs_data.src2 == 19)) {
                                                              if(!coveragePoints["Regs_105"]){
                                                                coveragePoints["Regs_105"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              RegsToCtl_data.contents2 = reg_file_19;
                                                            } else {
                                                              if(!coveragePoints["Regs_106"]){
                                                                coveragePoints["Regs_106"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              if ((CtlToRegs_data.src2 == 20)) {
                                                                if(!coveragePoints["Regs_107"]){
                                                                  coveragePoints["Regs_107"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                RegsToCtl_data.contents2 = reg_file_20;
                                                              } else {
                                                                if(!coveragePoints["Regs_108"]){
                                                                  coveragePoints["Regs_108"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                if ((CtlToRegs_data.src2 == 21)) {
                                                                  if(!coveragePoints["Regs_109"]){
                                                                    coveragePoints["Regs_109"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  RegsToCtl_data.contents2 = reg_file_21;
                                                                } else {
                                                                  if(!coveragePoints["Regs_110"]){
                                                                    coveragePoints["Regs_110"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  if ((CtlToRegs_data.src2 == 22)) {
                                                                    if(!coveragePoints["Regs_111"]){
                                                                      coveragePoints["Regs_111"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    RegsToCtl_data.contents2 = reg_file_22;
                                                                  } else {
                                                                    if(!coveragePoints["Regs_112"]){
                                                                      coveragePoints["Regs_112"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    if ((CtlToRegs_data.src2 == 23)) {
                                                                      if(!coveragePoints["Regs_113"]){
                                                                        coveragePoints["Regs_113"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      RegsToCtl_data.contents2 = reg_file_23;
                                                                    } else {
                                                                      if(!coveragePoints["Regs_114"]){
                                                                        coveragePoints["Regs_114"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      if ((CtlToRegs_data.src2 == 24)) {
                                                                        if(!coveragePoints["Regs_115"]){
                                                                          coveragePoints["Regs_115"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        RegsToCtl_data.contents2 = reg_file_24;
                                                                      } else {
                                                                        if(!coveragePoints["Regs_116"]){
                                                                          coveragePoints["Regs_116"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        if ((CtlToRegs_data.src2 == 25)) {
                                                                          if(!coveragePoints["Regs_117"]){
                                                                            coveragePoints["Regs_117"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          RegsToCtl_data.contents2 = reg_file_25;
                                                                        } else {
                                                                          if(!coveragePoints["Regs_118"]){
                                                                            coveragePoints["Regs_118"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          if ((CtlToRegs_data.src2 == 26)) {
                                                                            if(!coveragePoints["Regs_119"]){
                                                                              coveragePoints["Regs_119"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            RegsToCtl_data.contents2 = reg_file_26;
                                                                          } else {
                                                                            if(!coveragePoints["Regs_120"]){
                                                                              coveragePoints["Regs_120"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            if ((CtlToRegs_data.src2 == 27)) {
                                                                              if(!coveragePoints["Regs_121"]){
                                                                                coveragePoints["Regs_121"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              RegsToCtl_data.contents2 = reg_file_27;
                                                                            } else {
                                                                              if(!coveragePoints["Regs_122"]){
                                                                                coveragePoints["Regs_122"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              if ((CtlToRegs_data.src2 == 28)) {
                                                                                if(!coveragePoints["Regs_123"]){
                                                                                  coveragePoints["Regs_123"] = true;
                                                                                  coveragePointsCount++;
                                                                                }
                                                                                RegsToCtl_data.contents2 = reg_file_28;
                                                                              } else {
                                                                                if(!coveragePoints["Regs_124"]){
                                                                                  coveragePoints["Regs_124"] = true;
                                                                                  coveragePointsCount++;
                                                                                }
                                                                                if ((CtlToRegs_data.src2 == 29)) {
                                                                                  if(!coveragePoints["Regs_125"]){
                                                                                    coveragePoints["Regs_125"] = true;
                                                                                    coveragePointsCount++;
                                                                                  }
                                                                                  RegsToCtl_data.contents2 = reg_file_29;
                                                                                } else {
                                                                                  if(!coveragePoints["Regs_126"]){
                                                                                    coveragePoints["Regs_126"] = true;
                                                                                    coveragePointsCount++;
                                                                                  }
                                                                                  if ((CtlToRegs_data.src2 == 30)) {
                                                                                    if(!coveragePoints["Regs_127"]){
                                                                                      coveragePoints["Regs_127"] = true;
                                                                                      coveragePointsCount++;
                                                                                    }
                                                                                    RegsToCtl_data.contents2 = reg_file_30;
                                                                                  } else {
                                                                                    if(!coveragePoints["Regs_128"]){
                                                                                      coveragePoints["Regs_128"] = true;
                                                                                      coveragePointsCount++;
                                                                                    }
                                                                                    if ((CtlToRegs_data.src2 == 31)) {
                                                                                      if(!coveragePoints["Regs_129"]){
                                                                                        coveragePoints["Regs_129"] = true;
                                                                                        coveragePointsCount++;
                                                                                      }
                                                                                      RegsToCtl_data.contents2 = reg_file_31;
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
                    } else {
                      if(!coveragePoints["Regs_130"]){
                        coveragePoints["Regs_130"] = true;
                        coveragePointsCount++;
                      }
                      if ((CtlToRegs_data.req == REG_WR)) {
                        if(!coveragePoints["Regs_131"]){
                          coveragePoints["Regs_131"] = true;
                          coveragePointsCount++;
                        }
                        if ((CtlToRegs_data.dst == 1)) {
                          if(!coveragePoints["Regs_132"]){
                            coveragePoints["Regs_132"] = true;
                            coveragePointsCount++;
                          }
                          reg_file_01 = CtlToRegs_data.dst_data;
                        } else {
                          if(!coveragePoints["Regs_133"]){
                            coveragePoints["Regs_133"] = true;
                            coveragePointsCount++;
                          }
                          if ((CtlToRegs_data.dst == 2)) {
                            if(!coveragePoints["Regs_134"]){
                              coveragePoints["Regs_134"] = true;
                              coveragePointsCount++;
                            }
                            reg_file_02 = CtlToRegs_data.dst_data;
                          } else {
                            if(!coveragePoints["Regs_135"]){
                              coveragePoints["Regs_135"] = true;
                              coveragePointsCount++;
                            }
                            if ((CtlToRegs_data.dst == 3)) {
                              if(!coveragePoints["Regs_136"]){
                                coveragePoints["Regs_136"] = true;
                                coveragePointsCount++;
                              }
                              reg_file_03 = CtlToRegs_data.dst_data;
                            } else {
                              if(!coveragePoints["Regs_137"]){
                                coveragePoints["Regs_137"] = true;
                                coveragePointsCount++;
                              }
                              if ((CtlToRegs_data.dst == 4)) {
                                if(!coveragePoints["Regs_138"]){
                                  coveragePoints["Regs_138"] = true;
                                  coveragePointsCount++;
                                }
                                reg_file_04 = CtlToRegs_data.dst_data;
                              } else {
                                if(!coveragePoints["Regs_139"]){
                                  coveragePoints["Regs_139"] = true;
                                  coveragePointsCount++;
                                }
                                if ((CtlToRegs_data.dst == 5)) {
                                  if(!coveragePoints["Regs_140"]){
                                    coveragePoints["Regs_140"] = true;
                                    coveragePointsCount++;
                                  }
                                  reg_file_05 = CtlToRegs_data.dst_data;
                                } else {
                                  if(!coveragePoints["Regs_141"]){
                                    coveragePoints["Regs_141"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((CtlToRegs_data.dst == 6)) {
                                    if(!coveragePoints["Regs_142"]){
                                      coveragePoints["Regs_142"] = true;
                                      coveragePointsCount++;
                                    }
                                    reg_file_06 = CtlToRegs_data.dst_data;
                                  } else {
                                    if(!coveragePoints["Regs_143"]){
                                      coveragePoints["Regs_143"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((CtlToRegs_data.dst == 7)) {
                                      if(!coveragePoints["Regs_144"]){
                                        coveragePoints["Regs_144"] = true;
                                        coveragePointsCount++;
                                      }
                                      reg_file_07 = CtlToRegs_data.dst_data;
                                    } else {
                                      if(!coveragePoints["Regs_145"]){
                                        coveragePoints["Regs_145"] = true;
                                        coveragePointsCount++;
                                      }
                                      if ((CtlToRegs_data.dst == 8)) {
                                        if(!coveragePoints["Regs_146"]){
                                          coveragePoints["Regs_146"] = true;
                                          coveragePointsCount++;
                                        }
                                        reg_file_08 = CtlToRegs_data.dst_data;
                                      } else {
                                        if(!coveragePoints["Regs_147"]){
                                          coveragePoints["Regs_147"] = true;
                                          coveragePointsCount++;
                                        }
                                        if ((CtlToRegs_data.dst == 9)) {
                                          if(!coveragePoints["Regs_148"]){
                                            coveragePoints["Regs_148"] = true;
                                            coveragePointsCount++;
                                          }
                                          reg_file_09 = CtlToRegs_data.dst_data;
                                        } else {
                                          if(!coveragePoints["Regs_149"]){
                                            coveragePoints["Regs_149"] = true;
                                            coveragePointsCount++;
                                          }
                                          if ((CtlToRegs_data.dst == 10)) {
                                            if(!coveragePoints["Regs_150"]){
                                              coveragePoints["Regs_150"] = true;
                                              coveragePointsCount++;
                                            }
                                            reg_file_10 = CtlToRegs_data.dst_data;
                                          } else {
                                            if(!coveragePoints["Regs_151"]){
                                              coveragePoints["Regs_151"] = true;
                                              coveragePointsCount++;
                                            }
                                            if ((CtlToRegs_data.dst == 11)) {
                                              if(!coveragePoints["Regs_152"]){
                                                coveragePoints["Regs_152"] = true;
                                                coveragePointsCount++;
                                              }
                                              reg_file_11 = CtlToRegs_data.dst_data;
                                            } else {
                                              if(!coveragePoints["Regs_153"]){
                                                coveragePoints["Regs_153"] = true;
                                                coveragePointsCount++;
                                              }
                                              if ((CtlToRegs_data.dst == 12)) {
                                                if(!coveragePoints["Regs_154"]){
                                                  coveragePoints["Regs_154"] = true;
                                                  coveragePointsCount++;
                                                }
                                                reg_file_12 = CtlToRegs_data.dst_data;
                                              } else {
                                                if(!coveragePoints["Regs_155"]){
                                                  coveragePoints["Regs_155"] = true;
                                                  coveragePointsCount++;
                                                }
                                                if ((CtlToRegs_data.dst == 13)) {
                                                  if(!coveragePoints["Regs_156"]){
                                                    coveragePoints["Regs_156"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  reg_file_13 = CtlToRegs_data.dst_data;
                                                } else {
                                                  if(!coveragePoints["Regs_157"]){
                                                    coveragePoints["Regs_157"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  if ((CtlToRegs_data.dst == 14)) {
                                                    if(!coveragePoints["Regs_158"]){
                                                      coveragePoints["Regs_158"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    reg_file_14 = CtlToRegs_data.dst_data;
                                                  } else {
                                                    if(!coveragePoints["Regs_159"]){
                                                      coveragePoints["Regs_159"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    if ((CtlToRegs_data.dst == 15)) {
                                                      if(!coveragePoints["Regs_160"]){
                                                        coveragePoints["Regs_160"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      reg_file_15 = CtlToRegs_data.dst_data;
                                                    } else {
                                                      if(!coveragePoints["Regs_161"]){
                                                        coveragePoints["Regs_161"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      if ((CtlToRegs_data.dst == 16)) {
                                                        if(!coveragePoints["Regs_162"]){
                                                          coveragePoints["Regs_162"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        reg_file_16 = CtlToRegs_data.dst_data;
                                                      } else {
                                                        if(!coveragePoints["Regs_163"]){
                                                          coveragePoints["Regs_163"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        if ((CtlToRegs_data.dst == 17)) {
                                                          if(!coveragePoints["Regs_164"]){
                                                            coveragePoints["Regs_164"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          reg_file_17 = CtlToRegs_data.dst_data;
                                                        } else {
                                                          if(!coveragePoints["Regs_165"]){
                                                            coveragePoints["Regs_165"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          if ((CtlToRegs_data.dst == 18)) {
                                                            if(!coveragePoints["Regs_166"]){
                                                              coveragePoints["Regs_166"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            reg_file_18 = CtlToRegs_data.dst_data;
                                                          } else {
                                                            if(!coveragePoints["Regs_167"]){
                                                              coveragePoints["Regs_167"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            if ((CtlToRegs_data.dst == 19)) {
                                                              if(!coveragePoints["Regs_168"]){
                                                                coveragePoints["Regs_168"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              reg_file_19 = CtlToRegs_data.dst_data;
                                                            } else {
                                                              if(!coveragePoints["Regs_169"]){
                                                                coveragePoints["Regs_169"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              if ((CtlToRegs_data.dst == 20)) {
                                                                if(!coveragePoints["Regs_170"]){
                                                                  coveragePoints["Regs_170"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                reg_file_20 = CtlToRegs_data.dst_data;
                                                              } else {
                                                                if(!coveragePoints["Regs_171"]){
                                                                  coveragePoints["Regs_171"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                if ((CtlToRegs_data.dst == 21)) {
                                                                  if(!coveragePoints["Regs_172"]){
                                                                    coveragePoints["Regs_172"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  reg_file_21 = CtlToRegs_data.dst_data;
                                                                } else {
                                                                  if(!coveragePoints["Regs_173"]){
                                                                    coveragePoints["Regs_173"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  if ((CtlToRegs_data.dst == 22)) {
                                                                    if(!coveragePoints["Regs_174"]){
                                                                      coveragePoints["Regs_174"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    reg_file_22 = CtlToRegs_data.dst_data;
                                                                  } else {
                                                                    if(!coveragePoints["Regs_175"]){
                                                                      coveragePoints["Regs_175"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    if ((CtlToRegs_data.dst == 23)) {
                                                                      if(!coveragePoints["Regs_176"]){
                                                                        coveragePoints["Regs_176"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      reg_file_23 = CtlToRegs_data.dst_data;
                                                                    } else {
                                                                      if(!coveragePoints["Regs_177"]){
                                                                        coveragePoints["Regs_177"] = true;
                                                                        coveragePointsCount++;
                                                                      }
                                                                      if ((CtlToRegs_data.dst == 24)) {
                                                                        if(!coveragePoints["Regs_178"]){
                                                                          coveragePoints["Regs_178"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        reg_file_24 = CtlToRegs_data.dst_data;
                                                                      } else {
                                                                        if(!coveragePoints["Regs_179"]){
                                                                          coveragePoints["Regs_179"] = true;
                                                                          coveragePointsCount++;
                                                                        }
                                                                        if ((CtlToRegs_data.dst == 25)) {
                                                                          if(!coveragePoints["Regs_180"]){
                                                                            coveragePoints["Regs_180"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          reg_file_25 = CtlToRegs_data.dst_data;
                                                                        } else {
                                                                          if(!coveragePoints["Regs_181"]){
                                                                            coveragePoints["Regs_181"] = true;
                                                                            coveragePointsCount++;
                                                                          }
                                                                          if ((CtlToRegs_data.dst == 26)) {
                                                                            if(!coveragePoints["Regs_182"]){
                                                                              coveragePoints["Regs_182"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            reg_file_26 = CtlToRegs_data.dst_data;
                                                                          } else {
                                                                            if(!coveragePoints["Regs_183"]){
                                                                              coveragePoints["Regs_183"] = true;
                                                                              coveragePointsCount++;
                                                                            }
                                                                            if ((CtlToRegs_data.dst == 27)) {
                                                                              if(!coveragePoints["Regs_184"]){
                                                                                coveragePoints["Regs_184"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              reg_file_27 = CtlToRegs_data.dst_data;
                                                                            } else {
                                                                              if(!coveragePoints["Regs_185"]){
                                                                                coveragePoints["Regs_185"] = true;
                                                                                coveragePointsCount++;
                                                                              }
                                                                              if ((CtlToRegs_data.dst == 28)) {
                                                                                if(!coveragePoints["Regs_186"]){
                                                                                  coveragePoints["Regs_186"] = true;
                                                                                  coveragePointsCount++;
                                                                                }
                                                                                reg_file_28 = CtlToRegs_data.dst_data;
                                                                              } else {
                                                                                if(!coveragePoints["Regs_187"]){
                                                                                  coveragePoints["Regs_187"] = true;
                                                                                  coveragePointsCount++;
                                                                                }
                                                                                if ((CtlToRegs_data.dst == 29)) {
                                                                                  if(!coveragePoints["Regs_188"]){
                                                                                    coveragePoints["Regs_188"] = true;
                                                                                    coveragePointsCount++;
                                                                                  }
                                                                                  reg_file_29 = CtlToRegs_data.dst_data;
                                                                                } else {
                                                                                  if(!coveragePoints["Regs_189"]){
                                                                                    coveragePoints["Regs_189"] = true;
                                                                                    coveragePointsCount++;
                                                                                  }
                                                                                  if ((CtlToRegs_data.dst == 30)) {
                                                                                    if(!coveragePoints["Regs_190"]){
                                                                                      coveragePoints["Regs_190"] = true;
                                                                                      coveragePointsCount++;
                                                                                    }
                                                                                    reg_file_30 = CtlToRegs_data.dst_data;
                                                                                  } else {
                                                                                    if(!coveragePoints["Regs_191"]){
                                                                                      coveragePoints["Regs_191"] = true;
                                                                                      coveragePointsCount++;
                                                                                    }
                                                                                    if ((CtlToRegs_data.dst == 31)) {
                                                                                      if(!coveragePoints["Regs_192"]){
                                                                                        coveragePoints["Regs_192"] = true;
                                                                                        coveragePointsCount++;
                                                                                      }
                                                                                      reg_file_31 = CtlToRegs_data.dst_data;
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
                  }
                  RegsToCtl_port->nb_write(RegsToCtl_data);
                }
                wait(SC_ZERO_TIME);
              }//end of while
          }//end of FSM
          int coveragePointsTotal = 192;
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
            reg_file_31(0)          {
            SC_THREAD(FSM);
            for(int i = 1; i < coveragePointsTotal; i++)
                        coveragePoints.insert(std::make_pair("Regs_"+to_string(i),false));
            }
          };//end of module


#endif //SYSTEMC_Regs_H
