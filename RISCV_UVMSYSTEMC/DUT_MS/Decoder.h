#ifndef SYSTEMC_Decoder_H
#define SYSTEMC_Decoder_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

      struct Decoder : public sc_module {

        enum Sections {run};
        Sections section;

        slave_in<unsigned> CtlToDec_port;
        slave_out<DecodedInstr> DecToCtl_port;

        //functions

        DecodedInstr decoded_instr;
        unsigned encoded_instr;
        unsigned funct3;
        unsigned funct7;
        unsigned imm_b;
        unsigned imm_b_1;
        unsigned imm_b_2;
        unsigned imm_b_sext_0;
        unsigned imm_i;
        unsigned imm_i_sext;
        unsigned imm_i_shamt;
        unsigned imm_j;
        unsigned imm_j_1;
        unsigned imm_j_2;
        unsigned imm_j_3;
        unsigned imm_s;
        unsigned imm_u;
        unsigned opcode;
        bool rec;


        void FSM(){
            while(true) {
              if (section==run) {
                if(!coveragePoints["Decoder_1"]){
                  coveragePoints["Decoder_1"] = true;
                  coveragePointsCount++;
                }
                rec = CtlToDec_port->nb_read(encoded_instr);
                if (rec) {
                  if(!coveragePoints["Decoder_2"]){
                    coveragePoints["Decoder_2"] = true;
                    coveragePointsCount++;
                  }
                  decoded_instr.instrType = Unknown;
                  decoded_instr.encType = Error_Type;
                  opcode = ((encoded_instr >> 0) & ((1 << ((6 - 0) + 1)) - 1));
                  funct3 = ((encoded_instr >> 12) & ((1 << ((14 - 12) + 1)) - 1));
                  funct7 = ((encoded_instr >> 25) & ((1 << ((31 - 25) + 1)) - 1));
                  decoded_instr.rs1_addr = ((encoded_instr >> 15) & ((1 << ((19 - 15) + 1)) - 1));
                  decoded_instr.rs2_addr = ((encoded_instr >> 20) & ((1 << ((24 - 20) + 1)) - 1));
                  decoded_instr.rd_addr = ((encoded_instr >> 7) & ((1 << ((11 - 7) + 1)) - 1));
                  if ((opcode == 19)) {
                    if(!coveragePoints["Decoder_3"]){
                      coveragePoints["Decoder_3"] = true;
                      coveragePointsCount++;
                    }
                    imm_i = ((encoded_instr >> 20) & ((1 << ((31 - 20) + 1)) - 1));
                    if ((((imm_i >> 11) & ((1 << ((11 - 11) + 1)) - 1)) == 1)) {
                      if(!coveragePoints["Decoder_4"]){
                        coveragePoints["Decoder_4"] = true;
                        coveragePointsCount++;
                      }
                      imm_i_sext = (((((1 << 20) - 1) << 12) & (((1 << 20) - 1) << 12)) | (((1 << 12) - 1) & imm_i));
                    } else {
                      if(!coveragePoints["Decoder_5"]){
                        coveragePoints["Decoder_5"] = true;
                        coveragePointsCount++;
                      }
                      imm_i_sext = imm_i;
                    }
                    decoded_instr.encType = I;
                    decoded_instr.imm = imm_i_sext;
                    if ((funct3 == 0)) {
                      if(!coveragePoints["Decoder_6"]){
                        coveragePoints["Decoder_6"] = true;
                        coveragePointsCount++;
                      }
                      decoded_instr.instrType = addI;
                    } else {
                      if(!coveragePoints["Decoder_7"]){
                        coveragePoints["Decoder_7"] = true;
                        coveragePointsCount++;
                      }
                      if ((funct3 == 7)) {
                        if(!coveragePoints["Decoder_8"]){
                          coveragePoints["Decoder_8"] = true;
                          coveragePointsCount++;
                        }
                        decoded_instr.instrType = andI;
                      } else {
                        if(!coveragePoints["Decoder_9"]){
                          coveragePoints["Decoder_9"] = true;
                          coveragePointsCount++;
                        }
                        if ((funct3 == 6)) {
                          if(!coveragePoints["Decoder_10"]){
                            coveragePoints["Decoder_10"] = true;
                            coveragePointsCount++;
                          }
                          decoded_instr.instrType = orI;
                        } else {
                          if(!coveragePoints["Decoder_11"]){
                            coveragePoints["Decoder_11"] = true;
                            coveragePointsCount++;
                          }
                          if ((funct3 == 4)) {
                            if(!coveragePoints["Decoder_12"]){
                              coveragePoints["Decoder_12"] = true;
                              coveragePointsCount++;
                            }
                            decoded_instr.instrType = xorI;
                          } else {
                            if(!coveragePoints["Decoder_13"]){
                              coveragePoints["Decoder_13"] = true;
                              coveragePointsCount++;
                            }
                            if ((funct3 == 2)) {
                              if(!coveragePoints["Decoder_14"]){
                                coveragePoints["Decoder_14"] = true;
                                coveragePointsCount++;
                              }
                              decoded_instr.instrType = sltI;
                            } else {
                              if(!coveragePoints["Decoder_15"]){
                                coveragePoints["Decoder_15"] = true;
                                coveragePointsCount++;
                              }
                              if ((funct3 == 3)) {
                                if(!coveragePoints["Decoder_16"]){
                                  coveragePoints["Decoder_16"] = true;
                                  coveragePointsCount++;
                                }
                                decoded_instr.instrType = sltIu;
                              } else {
                                if(!coveragePoints["Decoder_17"]){
                                  coveragePoints["Decoder_17"] = true;
                                  coveragePointsCount++;
                                }
                                if ((funct3 == 1)) {
                                  if(!coveragePoints["Decoder_18"]){
                                    coveragePoints["Decoder_18"] = true;
                                    coveragePointsCount++;
                                  }
                                  decoded_instr.instrType = sllI;
                                  imm_i_shamt = ((encoded_instr >> 20) & ((1 << ((24 - 20) + 1)) - 1));
                                  decoded_instr.imm = imm_i_shamt;
                                } else {
                                  if(!coveragePoints["Decoder_19"]){
                                    coveragePoints["Decoder_19"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((funct3 == 5)) {
                                    if(!coveragePoints["Decoder_20"]){
                                      coveragePoints["Decoder_20"] = true;
                                      coveragePointsCount++;
                                    }
                                    imm_i_shamt = ((encoded_instr >> 20) & ((1 << ((24 - 20) + 1)) - 1));
                                    if ((funct7 == 0)) {
                                      if(!coveragePoints["Decoder_21"]){
                                        coveragePoints["Decoder_21"] = true;
                                        coveragePointsCount++;
                                      }
                                      decoded_instr.instrType = srlI;
                                      decoded_instr.imm = imm_i_shamt;
                                    } else {
                                      if(!coveragePoints["Decoder_22"]){
                                        coveragePoints["Decoder_22"] = true;
                                        coveragePointsCount++;
                                      }
                                      if ((funct7 == 32)) {
                                        if(!coveragePoints["Decoder_23"]){
                                          coveragePoints["Decoder_23"] = true;
                                          coveragePointsCount++;
                                        }
                                        decoded_instr.instrType = sraI;
                                        decoded_instr.imm = imm_i_shamt;
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
                    if(!coveragePoints["Decoder_24"]){
                      coveragePoints["Decoder_24"] = true;
                      coveragePointsCount++;
                    }
                    if ((opcode == 51)) {
                      if(!coveragePoints["Decoder_25"]){
                        coveragePoints["Decoder_25"] = true;
                        coveragePointsCount++;
                      }
                      decoded_instr.encType = R;
                      decoded_instr.imm = 0;
                      if ((funct3 == 0)) {
                        if(!coveragePoints["Decoder_26"]){
                          coveragePoints["Decoder_26"] = true;
                          coveragePointsCount++;
                        }
                        if ((funct7 == 0)) {
                          if(!coveragePoints["Decoder_27"]){
                            coveragePoints["Decoder_27"] = true;
                            coveragePointsCount++;
                          }
                          decoded_instr.instrType = add;
                        }
                        if ((funct7 == 32)) {
                          if(!coveragePoints["Decoder_28"]){
                            coveragePoints["Decoder_28"] = true;
                            coveragePointsCount++;
                          }
                          decoded_instr.instrType = sub;
                        }
                      } else {
                        if(!coveragePoints["Decoder_29"]){
                          coveragePoints["Decoder_29"] = true;
                          coveragePointsCount++;
                        }
                        if ((funct3 == 1)) {
                          if(!coveragePoints["Decoder_30"]){
                            coveragePoints["Decoder_30"] = true;
                            coveragePointsCount++;
                          }
                          decoded_instr.instrType = sll_Instr;
                        } else {
                          if(!coveragePoints["Decoder_31"]){
                            coveragePoints["Decoder_31"] = true;
                            coveragePointsCount++;
                          }
                          if ((funct3 == 2)) {
                            if(!coveragePoints["Decoder_32"]){
                              coveragePoints["Decoder_32"] = true;
                              coveragePointsCount++;
                            }
                            decoded_instr.instrType = slt;
                          } else {
                            if(!coveragePoints["Decoder_33"]){
                              coveragePoints["Decoder_33"] = true;
                              coveragePointsCount++;
                            }
                            if ((funct3 == 3)) {
                              if(!coveragePoints["Decoder_34"]){
                                coveragePoints["Decoder_34"] = true;
                                coveragePointsCount++;
                              }
                              decoded_instr.instrType = sltu;
                            } else {
                              if(!coveragePoints["Decoder_35"]){
                                coveragePoints["Decoder_35"] = true;
                                coveragePointsCount++;
                              }
                              if ((funct3 == 4)) {
                                if(!coveragePoints["Decoder_36"]){
                                  coveragePoints["Decoder_36"] = true;
                                  coveragePointsCount++;
                                }
                                decoded_instr.instrType = Xor_Instr;
                              } else {
                                if(!coveragePoints["Decoder_37"]){
                                  coveragePoints["Decoder_37"] = true;
                                  coveragePointsCount++;
                                }
                                if ((funct3 == 5)) {
                                  if(!coveragePoints["Decoder_38"]){
                                    coveragePoints["Decoder_38"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((funct7 == 0)) {
                                    if(!coveragePoints["Decoder_39"]){
                                      coveragePoints["Decoder_39"] = true;
                                      coveragePointsCount++;
                                    }
                                    decoded_instr.instrType = srl_Instr;
                                  }
                                  if ((funct7 == 32)) {
                                    if(!coveragePoints["Decoder_40"]){
                                      coveragePoints["Decoder_40"] = true;
                                      coveragePointsCount++;
                                    }
                                    decoded_instr.instrType = sra_Instr;
                                  }
                                } else {
                                  if(!coveragePoints["Decoder_41"]){
                                    coveragePoints["Decoder_41"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((funct3 == 6)) {
                                    if(!coveragePoints["Decoder_42"]){
                                      coveragePoints["Decoder_42"] = true;
                                      coveragePointsCount++;
                                    }
                                    decoded_instr.instrType = Or_Instr;
                                  } else {
                                    if(!coveragePoints["Decoder_43"]){
                                      coveragePoints["Decoder_43"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((funct3 == 7)) {
                                      if(!coveragePoints["Decoder_44"]){
                                        coveragePoints["Decoder_44"] = true;
                                        coveragePointsCount++;
                                      }
                                      decoded_instr.instrType = And_Instr;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if(!coveragePoints["Decoder_45"]){
                        coveragePoints["Decoder_45"] = true;
                        coveragePointsCount++;
                      }
                      if ((opcode == 99)) {
                        if(!coveragePoints["Decoder_46"]){
                          coveragePoints["Decoder_46"] = true;
                          coveragePointsCount++;
                        }
                        imm_b_1 = (((((1 << 1) - 1) << 1) & (((encoded_instr >> 31) & ((1 << ((31 - 31) + 1)) - 1)) << 1)) | (((1 << 1) - 1) & ((encoded_instr >> 7) & ((1 << ((7 - 7) + 1)) - 1))));
                        imm_b_2 = (((((1 << 6) - 1) << 4) & (((encoded_instr >> 25) & ((1 << ((30 - 25) + 1)) - 1)) << 4)) | (((1 << 4) - 1) & ((encoded_instr >> 8) & ((1 << ((11 - 8) + 1)) - 1))));
                        imm_b = (((((1 << 2) - 1) << 10) & (imm_b_1 << 10)) | (((1 << 10) - 1) & imm_b_2));
                        if ((((imm_b >> 11) & ((1 << ((11 - 11) + 1)) - 1)) == 1)) {
                          if(!coveragePoints["Decoder_47"]){
                            coveragePoints["Decoder_47"] = true;
                            coveragePointsCount++;
                          }
                          imm_b_sext_0 = (((((1 << 19) - 1) << 12) & (((1 << 19) - 1) << 12)) | (((1 << 12) - 1) & imm_b));
                        } else {
                          if(!coveragePoints["Decoder_48"]){
                            coveragePoints["Decoder_48"] = true;
                            coveragePointsCount++;
                          }
                          imm_b_sext_0 = imm_b;
                        }
                        imm_b = (((((1 << 31) - 1) << 1) & (imm_b_sext_0 << 1)) | (((1 << 1) - 1) & 0));
                        decoded_instr.encType = B;
                        decoded_instr.imm = imm_b;
                        if ((funct3 == 0)) {
                          if(!coveragePoints["Decoder_49"]){
                            coveragePoints["Decoder_49"] = true;
                            coveragePointsCount++;
                          }
                          decoded_instr.instrType = beq;
                        } else {
                          if(!coveragePoints["Decoder_50"]){
                            coveragePoints["Decoder_50"] = true;
                            coveragePointsCount++;
                          }
                          if ((funct3 == 1)) {
                            if(!coveragePoints["Decoder_51"]){
                              coveragePoints["Decoder_51"] = true;
                              coveragePointsCount++;
                            }
                            decoded_instr.instrType = bne;
                          } else {
                            if(!coveragePoints["Decoder_52"]){
                              coveragePoints["Decoder_52"] = true;
                              coveragePointsCount++;
                            }
                            if ((funct3 == 4)) {
                              if(!coveragePoints["Decoder_53"]){
                                coveragePoints["Decoder_53"] = true;
                                coveragePointsCount++;
                              }
                              decoded_instr.instrType = blt;
                            } else {
                              if(!coveragePoints["Decoder_54"]){
                                coveragePoints["Decoder_54"] = true;
                                coveragePointsCount++;
                              }
                              if ((funct3 == 5)) {
                                if(!coveragePoints["Decoder_55"]){
                                  coveragePoints["Decoder_55"] = true;
                                  coveragePointsCount++;
                                }
                                decoded_instr.instrType = bge;
                              } else {
                                if(!coveragePoints["Decoder_56"]){
                                  coveragePoints["Decoder_56"] = true;
                                  coveragePointsCount++;
                                }
                                if ((funct3 == 6)) {
                                  if(!coveragePoints["Decoder_57"]){
                                    coveragePoints["Decoder_57"] = true;
                                    coveragePointsCount++;
                                  }
                                  decoded_instr.instrType = bltu;
                                } else {
                                  if(!coveragePoints["Decoder_58"]){
                                    coveragePoints["Decoder_58"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((funct3 == 7)) {
                                    if(!coveragePoints["Decoder_59"]){
                                      coveragePoints["Decoder_59"] = true;
                                      coveragePointsCount++;
                                    }
                                    decoded_instr.instrType = bgeu;
                                  }
                                }
                              }
                            }
                          }
                        }
                      } else {
                        if(!coveragePoints["Decoder_60"]){
                          coveragePoints["Decoder_60"] = true;
                          coveragePointsCount++;
                        }
                        if ((opcode == 3)) {
                          if(!coveragePoints["Decoder_61"]){
                            coveragePoints["Decoder_61"] = true;
                            coveragePointsCount++;
                          }
                          imm_i = ((encoded_instr >> 20) & ((1 << ((31 - 20) + 1)) - 1));
                          if ((((imm_i >> 11) & ((1 << ((11 - 11) + 1)) - 1)) == 1)) {
                            if(!coveragePoints["Decoder_62"]){
                              coveragePoints["Decoder_62"] = true;
                              coveragePointsCount++;
                            }
                            imm_i_sext = (((((1 << 20) - 1) << 12) & (((1 << 20) - 1) << 12)) | (((1 << 12) - 1) & imm_i));
                          } else {
                            if(!coveragePoints["Decoder_63"]){
                              coveragePoints["Decoder_63"] = true;
                              coveragePointsCount++;
                            }
                            imm_i_sext = imm_i;
                          }
                          decoded_instr.encType = I;
                          decoded_instr.imm = imm_i_sext;
                          if ((funct3 == 0)) {
                            if(!coveragePoints["Decoder_64"]){
                              coveragePoints["Decoder_64"] = true;
                              coveragePointsCount++;
                            }
                            decoded_instr.instrType = lb;
                          } else {
                            if(!coveragePoints["Decoder_65"]){
                              coveragePoints["Decoder_65"] = true;
                              coveragePointsCount++;
                            }
                            if ((funct3 == 1)) {
                              if(!coveragePoints["Decoder_66"]){
                                coveragePoints["Decoder_66"] = true;
                                coveragePointsCount++;
                              }
                              decoded_instr.instrType = lh;
                            } else {
                              if(!coveragePoints["Decoder_67"]){
                                coveragePoints["Decoder_67"] = true;
                                coveragePointsCount++;
                              }
                              if ((funct3 == 2)) {
                                if(!coveragePoints["Decoder_68"]){
                                  coveragePoints["Decoder_68"] = true;
                                  coveragePointsCount++;
                                }
                                decoded_instr.instrType = lw;
                              } else {
                                if(!coveragePoints["Decoder_69"]){
                                  coveragePoints["Decoder_69"] = true;
                                  coveragePointsCount++;
                                }
                                if ((funct3 == 4)) {
                                  if(!coveragePoints["Decoder_70"]){
                                    coveragePoints["Decoder_70"] = true;
                                    coveragePointsCount++;
                                  }
                                  decoded_instr.instrType = lbu;
                                } else {
                                  if(!coveragePoints["Decoder_71"]){
                                    coveragePoints["Decoder_71"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((funct3 == 5)) {
                                    if(!coveragePoints["Decoder_72"]){
                                      coveragePoints["Decoder_72"] = true;
                                      coveragePointsCount++;
                                    }
                                    decoded_instr.instrType = lhu;
                                  }
                                }
                              }
                            }
                          }
                        } else {
                          if(!coveragePoints["Decoder_73"]){
                            coveragePoints["Decoder_73"] = true;
                            coveragePointsCount++;
                          }
                          if ((opcode == 55)) {
                            if(!coveragePoints["Decoder_74"]){
                              coveragePoints["Decoder_74"] = true;
                              coveragePointsCount++;
                            }
                            imm_u = ((encoded_instr >> 12) & ((1 << ((31 - 12) + 1)) - 1));
                            imm_u = (((((1 << 20) - 1) << 12) & (imm_u << 12)) | (((1 << 12) - 1) & 0));
                            decoded_instr.imm = imm_u;
                            decoded_instr.encType = U;
                            decoded_instr.instrType = lui;
                          } else {
                            if(!coveragePoints["Decoder_75"]){
                              coveragePoints["Decoder_75"] = true;
                              coveragePointsCount++;
                            }
                            if ((opcode == 23)) {
                              if(!coveragePoints["Decoder_76"]){
                                coveragePoints["Decoder_76"] = true;
                                coveragePointsCount++;
                              }
                              imm_u = ((encoded_instr >> 12) & ((1 << ((31 - 12) + 1)) - 1));
                              imm_u = (((((1 << 20) - 1) << 12) & (imm_u << 12)) | (((1 << 12) - 1) & 0));
                              decoded_instr.imm = imm_u;
                              decoded_instr.encType = U;
                              decoded_instr.instrType = auipc;
                            } else {
                              if(!coveragePoints["Decoder_77"]){
                                coveragePoints["Decoder_77"] = true;
                                coveragePointsCount++;
                              }
                              if ((opcode == 111)) {
                                if(!coveragePoints["Decoder_78"]){
                                  coveragePoints["Decoder_78"] = true;
                                  coveragePointsCount++;
                                }
                                imm_j_1 = (((((1 << 1) - 1) << 8) & (((encoded_instr >> 31) & ((1 << ((31 - 31) + 1)) - 1)) << 8)) | (((1 << 8) - 1) & ((encoded_instr >> 12) & ((1 << ((19 - 12) + 1)) - 1))));
                                imm_j_2 = (((((1 << 1) - 1) << 10) & (((encoded_instr >> 20) & ((1 << ((20 - 20) + 1)) - 1)) << 10)) | (((1 << 10) - 1) & ((encoded_instr >> 21) & ((1 << ((30 - 21) + 1)) - 1))));
                                imm_j_3 = (((((1 << 11) - 1) << 1) & (imm_j_2 << 1)) | (((1 << 1) - 1) & 0));
                                imm_j = (((((1 << 9) - 1) << 12) & (imm_j_1 << 12)) | (((1 << 12) - 1) & imm_j_3));
                                if ((((encoded_instr >> 31) & ((1 << ((31 - 31) + 1)) - 1)) == 1)) {
                                  if(!coveragePoints["Decoder_79"]){
                                    coveragePoints["Decoder_79"] = true;
                                    coveragePointsCount++;
                                  }
                                  imm_j = (((((1 << 11) - 1) << 21) & (((1 << 11) - 1) << 21)) | (((1 << 21) - 1) & imm_j));
                                }
                                decoded_instr.imm = imm_j;
                                decoded_instr.encType = J;
                                decoded_instr.instrType = jal;
                              } else {
                                if(!coveragePoints["Decoder_80"]){
                                  coveragePoints["Decoder_80"] = true;
                                  coveragePointsCount++;
                                }
                                if ((opcode == 103)) {
                                  if(!coveragePoints["Decoder_81"]){
                                    coveragePoints["Decoder_81"] = true;
                                    coveragePointsCount++;
                                  }
                                  imm_i = ((encoded_instr >> 20) & ((1 << ((31 - 20) + 1)) - 1));
                                  if ((((imm_i >> 11) & ((1 << ((11 - 11) + 1)) - 1)) == 1)) {
                                    if(!coveragePoints["Decoder_82"]){
                                      coveragePoints["Decoder_82"] = true;
                                      coveragePointsCount++;
                                    }
                                    imm_i = (((((1 << 20) - 1) << 12) & (((1 << 20) - 1) << 12)) | (((1 << 12) - 1) & imm_i));
                                  }
                                  decoded_instr.imm = imm_i;
                                  decoded_instr.encType = I;
                                  decoded_instr.instrType = jalr;
                                } else {
                                  if(!coveragePoints["Decoder_83"]){
                                    coveragePoints["Decoder_83"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((opcode == 35)) {
                                    if(!coveragePoints["Decoder_84"]){
                                      coveragePoints["Decoder_84"] = true;
                                      coveragePointsCount++;
                                    }
                                    imm_s = (((((1 << 7) - 1) << 5) & (((encoded_instr >> 25) & ((1 << ((31 - 25) + 1)) - 1)) << 5)) | (((1 << 5) - 1) & ((encoded_instr >> 7) & ((1 << ((11 - 7) + 1)) - 1))));
                                    if ((((imm_s >> 11) & ((1 << ((11 - 11) + 1)) - 1)) == 1)) {
                                      if(!coveragePoints["Decoder_85"]){
                                        coveragePoints["Decoder_85"] = true;
                                        coveragePointsCount++;
                                      }
                                      imm_s = (((((1 << 20) - 1) << 12) & (((1 << 20) - 1) << 12)) | (((1 << 12) - 1) & imm_s));
                                    }
                                    decoded_instr.imm = imm_s;
                                    decoded_instr.encType = S;
                                    if ((funct3 == 0)) {
                                      if(!coveragePoints["Decoder_86"]){
                                        coveragePoints["Decoder_86"] = true;
                                        coveragePointsCount++;
                                      }
                                      decoded_instr.instrType = sb;
                                    } else {
                                      if(!coveragePoints["Decoder_87"]){
                                        coveragePoints["Decoder_87"] = true;
                                        coveragePointsCount++;
                                      }
                                      if ((funct3 == 1)) {
                                        if(!coveragePoints["Decoder_88"]){
                                          coveragePoints["Decoder_88"] = true;
                                          coveragePointsCount++;
                                        }
                                        decoded_instr.instrType = sh;
                                      } else {
                                        if(!coveragePoints["Decoder_89"]){
                                          coveragePoints["Decoder_89"] = true;
                                          coveragePointsCount++;
                                        }
                                        if ((funct3 == 2)) {
                                          if(!coveragePoints["Decoder_90"]){
                                            coveragePoints["Decoder_90"] = true;
                                            coveragePointsCount++;
                                          }
                                          decoded_instr.instrType = sw;
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
                DecToCtl_port->nb_write(decoded_instr);
              }
              wait(SC_ZERO_TIME);
            }//end of while
        }//end of FSM
        int coveragePointsTotal = 90;
        int coveragePointsCount = 0;
        std::map<std::string, bool> coveragePoints;

        SC_HAS_PROCESS(Decoder);

        Decoder(sc_module_name name) :
          section(run),
          encoded_instr(0),
          funct3(0),
          funct7(0),
          imm_b(0),
          imm_b_1(0),
          imm_b_2(0),
          imm_b_sext_0(0),
          imm_i(0),
          imm_i_sext(0),
          imm_i_shamt(0),
          imm_j(0),
          imm_j_1(0),
          imm_j_2(0),
          imm_j_3(0),
          imm_s(0),
          imm_u(0),
          opcode(0),
          rec(false)        {
          SC_THREAD(FSM);
          for(int i = 1; i < coveragePointsTotal; i++)
                    coveragePoints.insert(std::make_pair("Decoder_"+to_string(i),false));
          }
        };//end of module


#endif //SYSTEMC_Decoder_H
