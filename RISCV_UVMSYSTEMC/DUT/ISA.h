#ifndef SYSTEMC_ISA_H
#define SYSTEMC_ISA_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

  struct ISA : public sc_module {

    enum Sections {execute, fetch};
    Sections section;

    blocking_in<MEtoCU_IF> fromMemoryPort;
    master_in<RegfileType> fromRegsPort;
    blocking_out<CUtoME_IF> toMemoryPort;
    master_out<RegfileWriteType> toRegsPort;

    //functions
    unsigned branchPCcalculation(unsigned aluResult, unsigned encodedInstr, unsigned pcReg) {
      if (((getInstrType(encodedInstr) == INSTR_BEQ) and (aluResult == 0))) {
        if(!coveragePoints["ISA_1"]){
          coveragePoints["ISA_1"] = true;
          coveragePointsCount++;
        }
        return((pcReg + getImmediate(encodedInstr)));
      } else {
        if(!coveragePoints["ISA_2"]){
          coveragePoints["ISA_2"] = true;
          coveragePointsCount++;
        }
        if (((getInstrType(encodedInstr) == INSTR_BNE) and (aluResult != 0))) {
          if(!coveragePoints["ISA_3"]){
            coveragePoints["ISA_3"] = true;
            coveragePointsCount++;
          }
          return((pcReg + getImmediate(encodedInstr)));
        } else {
          if(!coveragePoints["ISA_4"]){
            coveragePoints["ISA_4"] = true;
            coveragePointsCount++;
          }
          if (((getInstrType(encodedInstr) == INSTR_BLT) and (aluResult == 1))) {
            if(!coveragePoints["ISA_5"]){
              coveragePoints["ISA_5"] = true;
              coveragePointsCount++;
            }
            return((pcReg + getImmediate(encodedInstr)));
          } else {
            if(!coveragePoints["ISA_6"]){
              coveragePoints["ISA_6"] = true;
              coveragePointsCount++;
            }
            if (((getInstrType(encodedInstr) == INSTR_BGE) and (aluResult == 0))) {
              if(!coveragePoints["ISA_7"]){
                coveragePoints["ISA_7"] = true;
                coveragePointsCount++;
              }
              return((pcReg + getImmediate(encodedInstr)));
            } else {
              if(!coveragePoints["ISA_8"]){
                coveragePoints["ISA_8"] = true;
                coveragePointsCount++;
              }
              if (((getInstrType(encodedInstr) == INSTR_BLTU) and (aluResult == 1))) {
                if(!coveragePoints["ISA_9"]){
                  coveragePoints["ISA_9"] = true;
                  coveragePointsCount++;
                }
                return((pcReg + getImmediate(encodedInstr)));
              } else {
                if(!coveragePoints["ISA_10"]){
                  coveragePoints["ISA_10"] = true;
                  coveragePointsCount++;
                }
                if (((getInstrType(encodedInstr) == INSTR_BGEU) and (aluResult == 0))) {
                  if(!coveragePoints["ISA_11"]){
                    coveragePoints["ISA_11"] = true;
                    coveragePointsCount++;
                  }
                  return((pcReg + getImmediate(encodedInstr)));
                } else {
                  if(!coveragePoints["ISA_12"]){
                    coveragePoints["ISA_12"] = true;
                    coveragePointsCount++;
                  }
                  return((pcReg + 4));
                }
              }
            }
          }
        }
      }
    }

    ALUfuncType getALUfunc(InstrType instr) {
      if ((((((((((((instr == INSTR_ADD) or (instr == INSTR_ADDI)) or (instr == INSTR_LB)) or (instr == INSTR_LH)) or (instr == INSTR_LW)) or (instr == INSTR_LBU)) or (instr == INSTR_LHU)) or (instr == INSTR_SB)) or (instr == INSTR_SH)) or (instr == INSTR_SW)) or (instr == INSTR_AUIPC))) {
        if(!coveragePoints["ISA_13"]){
          coveragePoints["ISA_13"] = true;
          coveragePointsCount++;
        }
        return(ALU_ADD);
      } else {
        if(!coveragePoints["ISA_14"]){
          coveragePoints["ISA_14"] = true;
          coveragePointsCount++;
        }
        if ((((instr == INSTR_SUB) or (instr == INSTR_BEQ)) or (instr == INSTR_BNE))) {
          if(!coveragePoints["ISA_15"]){
            coveragePoints["ISA_15"] = true;
            coveragePointsCount++;
          }
          return(ALU_SUB);
        } else {
          if(!coveragePoints["ISA_16"]){
            coveragePoints["ISA_16"] = true;
            coveragePointsCount++;
          }
          if (((instr == INSTR_SLL) or (instr == INSTR_SLLI))) {
            if(!coveragePoints["ISA_17"]){
              coveragePoints["ISA_17"] = true;
              coveragePointsCount++;
            }
            return(ALU_SLL);
          } else {
            if(!coveragePoints["ISA_18"]){
              coveragePoints["ISA_18"] = true;
              coveragePointsCount++;
            }
            if (((((instr == INSTR_SLT) or (instr == INSTR_SLTI)) or (instr == INSTR_BLT)) or (instr == INSTR_BGE))) {
              if(!coveragePoints["ISA_19"]){
                coveragePoints["ISA_19"] = true;
                coveragePointsCount++;
              }
              return(ALU_SLT);
            } else {
              if(!coveragePoints["ISA_20"]){
                coveragePoints["ISA_20"] = true;
                coveragePointsCount++;
              }
              if (((((instr == INSTR_SLTU) or (instr == INSTR_SLTUI)) or (instr == INSTR_BLTU)) or (instr == INSTR_BGEU))) {
                if(!coveragePoints["ISA_21"]){
                  coveragePoints["ISA_21"] = true;
                  coveragePointsCount++;
                }
                return(ALU_SLTU);
              } else {
                if(!coveragePoints["ISA_22"]){
                  coveragePoints["ISA_22"] = true;
                  coveragePointsCount++;
                }
                if (((instr == INSTR_XOR) or (instr == INSTR_XORI))) {
                  if(!coveragePoints["ISA_23"]){
                    coveragePoints["ISA_23"] = true;
                    coveragePointsCount++;
                  }
                  return(ALU_XOR);
                } else {
                  if(!coveragePoints["ISA_24"]){
                    coveragePoints["ISA_24"] = true;
                    coveragePointsCount++;
                  }
                  if (((instr == INSTR_SRL) or (instr == INSTR_SRLI))) {
                    if(!coveragePoints["ISA_25"]){
                      coveragePoints["ISA_25"] = true;
                      coveragePointsCount++;
                    }
                    return(ALU_SRL);
                  } else {
                    if(!coveragePoints["ISA_26"]){
                      coveragePoints["ISA_26"] = true;
                      coveragePointsCount++;
                    }
                    if (((instr == INSTR_SRA) or (instr == INSTR_SRAI))) {
                      if(!coveragePoints["ISA_27"]){
                        coveragePoints["ISA_27"] = true;
                        coveragePointsCount++;
                      }
                      return(ALU_SRA);
                    } else {
                      if(!coveragePoints["ISA_28"]){
                        coveragePoints["ISA_28"] = true;
                        coveragePointsCount++;
                      }
                      if (((instr == INSTR_OR) or (instr == INSTR_ORI))) {
                        if(!coveragePoints["ISA_29"]){
                          coveragePoints["ISA_29"] = true;
                          coveragePointsCount++;
                        }
                        return(ALU_OR);
                      } else {
                        if(!coveragePoints["ISA_30"]){
                          coveragePoints["ISA_30"] = true;
                          coveragePointsCount++;
                        }
                        if (((instr == INSTR_AND) or (instr == INSTR_ANDI))) {
                          if(!coveragePoints["ISA_31"]){
                            coveragePoints["ISA_31"] = true;
                            coveragePointsCount++;
                          }
                          return(ALU_AND);
                        } else {
                          if(!coveragePoints["ISA_32"]){
                            coveragePoints["ISA_32"] = true;
                            coveragePointsCount++;
                          }
                          if (((instr == INSTR_JALR) or (instr == INSTR_JAL))) {
                            if(!coveragePoints["ISA_33"]){
                              coveragePoints["ISA_33"] = true;
                              coveragePointsCount++;
                            }
                            return(ALU_X);
                          } else {
                            if(!coveragePoints["ISA_34"]){
                              coveragePoints["ISA_34"] = true;
                              coveragePointsCount++;
                            }
                            if ((instr == INSTR_LUI)) {
                              if(!coveragePoints["ISA_35"]){
                                coveragePoints["ISA_35"] = true;
                                coveragePointsCount++;
                              }
                              return(ALU_COPY1);
                            } else {
                              if(!coveragePoints["ISA_36"]){
                                coveragePoints["ISA_36"] = true;
                                coveragePointsCount++;
                              }
                              return(ALU_X);
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

    unsigned getALUresult(ALUfuncType aluFunction, unsigned operand1, unsigned operand2) {
      if ((aluFunction == ALU_ADD)) {
        if(!coveragePoints["ISA_37"]){
          coveragePoints["ISA_37"] = true;
          coveragePointsCount++;
        }
        return((operand1 + operand2));
      } else {
        if(!coveragePoints["ISA_38"]){
          coveragePoints["ISA_38"] = true;
          coveragePointsCount++;
        }
        if ((aluFunction == ALU_SUB)) {
          if(!coveragePoints["ISA_39"]){
            coveragePoints["ISA_39"] = true;
            coveragePointsCount++;
          }
          return((operand1 + -(operand2)));
        } else {
          if(!coveragePoints["ISA_40"]){
            coveragePoints["ISA_40"] = true;
            coveragePointsCount++;
          }
          if ((aluFunction == ALU_AND)) {
            if(!coveragePoints["ISA_41"]){
              coveragePoints["ISA_41"] = true;
              coveragePointsCount++;
            }
            return((operand1 & operand2));
          } else {
            if(!coveragePoints["ISA_42"]){
              coveragePoints["ISA_42"] = true;
              coveragePointsCount++;
            }
            if ((aluFunction == ALU_OR)) {
              if(!coveragePoints["ISA_43"]){
                coveragePoints["ISA_43"] = true;
                coveragePointsCount++;
              }
              return((operand1 | operand2));
            } else {
              if(!coveragePoints["ISA_44"]){
                coveragePoints["ISA_44"] = true;
                coveragePointsCount++;
              }
              if ((aluFunction == ALU_XOR)) {
                if(!coveragePoints["ISA_45"]){
                  coveragePoints["ISA_45"] = true;
                  coveragePointsCount++;
                }
                return((operand1 ^ operand2));
              } else {
                if(!coveragePoints["ISA_46"]){
                  coveragePoints["ISA_46"] = true;
                  coveragePointsCount++;
                }
                if ((aluFunction == ALU_SLT)) {
                  if(!coveragePoints["ISA_47"]){
                    coveragePoints["ISA_47"] = true;
                    coveragePointsCount++;
                  }
                  if ((static_cast<int>(operand1) < static_cast<int>(operand2))) {
                    if(!coveragePoints["ISA_48"]){
                      coveragePoints["ISA_48"] = true;
                      coveragePointsCount++;
                    }
                    return(1);
                  } else {
                    if(!coveragePoints["ISA_49"]){
                      coveragePoints["ISA_49"] = true;
                      coveragePointsCount++;
                    }
                    return(0);
                  }
                } else {
                  if(!coveragePoints["ISA_50"]){
                    coveragePoints["ISA_50"] = true;
                    coveragePointsCount++;
                  }
                  if ((aluFunction == ALU_SLTU)) {
                    if(!coveragePoints["ISA_51"]){
                      coveragePoints["ISA_51"] = true;
                      coveragePointsCount++;
                    }
                    if ((operand1 < operand2)) {
                      if(!coveragePoints["ISA_52"]){
                        coveragePoints["ISA_52"] = true;
                        coveragePointsCount++;
                      }
                      return(1);
                    } else {
                      if(!coveragePoints["ISA_53"]){
                        coveragePoints["ISA_53"] = true;
                        coveragePointsCount++;
                      }
                      return(0);
                    }
                  } else {
                    if(!coveragePoints["ISA_54"]){
                      coveragePoints["ISA_54"] = true;
                      coveragePointsCount++;
                    }
                    if ((aluFunction == ALU_SLL)) {
                      if(!coveragePoints["ISA_55"]){
                        coveragePoints["ISA_55"] = true;
                        coveragePointsCount++;
                      }
                      return((operand1 << (operand2 & 31)));
                    } else {
                      if(!coveragePoints["ISA_56"]){
                        coveragePoints["ISA_56"] = true;
                        coveragePointsCount++;
                      }
                      if ((aluFunction == ALU_SRA)) {
                        if(!coveragePoints["ISA_57"]){
                          coveragePoints["ISA_57"] = true;
                          coveragePointsCount++;
                        }
                        return(static_cast<unsigned>((static_cast<int>(operand1) >> static_cast<int>((operand2 & 31)))));
                      } else {
                        if(!coveragePoints["ISA_58"]){
                          coveragePoints["ISA_58"] = true;
                          coveragePointsCount++;
                        }
                        if ((aluFunction == ALU_SRL)) {
                          if(!coveragePoints["ISA_59"]){
                            coveragePoints["ISA_59"] = true;
                            coveragePointsCount++;
                          }
                          return((operand1 >> (operand2 & 31)));
                        } else {
                          if(!coveragePoints["ISA_60"]){
                            coveragePoints["ISA_60"] = true;
                            coveragePointsCount++;
                          }
                          if ((aluFunction == ALU_COPY1)) {
                            if(!coveragePoints["ISA_61"]){
                              coveragePoints["ISA_61"] = true;
                              coveragePointsCount++;
                            }
                            return(operand1);
                          } else {
                            if(!coveragePoints["ISA_62"]){
                              coveragePoints["ISA_62"] = true;
                              coveragePointsCount++;
                            }
                            return(0);
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

    EncType getEncType(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 51)) {
        if(!coveragePoints["ISA_63"]){
          coveragePoints["ISA_63"] = true;
          coveragePointsCount++;
        }
        return(ENC_R);
      } else {
        if(!coveragePoints["ISA_64"]){
          coveragePoints["ISA_64"] = true;
          coveragePointsCount++;
        }
        if (((encodedInstr & 127) == 19)) {
          if(!coveragePoints["ISA_65"]){
            coveragePoints["ISA_65"] = true;
            coveragePointsCount++;
          }
          return(ENC_I_I);
        } else {
          if(!coveragePoints["ISA_66"]){
            coveragePoints["ISA_66"] = true;
            coveragePointsCount++;
          }
          if (((encodedInstr & 127) == 3)) {
            if(!coveragePoints["ISA_67"]){
              coveragePoints["ISA_67"] = true;
              coveragePointsCount++;
            }
            return(ENC_I_L);
          } else {
            if(!coveragePoints["ISA_68"]){
              coveragePoints["ISA_68"] = true;
              coveragePointsCount++;
            }
            if (((encodedInstr & 127) == 103)) {
              if(!coveragePoints["ISA_69"]){
                coveragePoints["ISA_69"] = true;
                coveragePointsCount++;
              }
              return(ENC_I_J);
            } else {
              if(!coveragePoints["ISA_70"]){
                coveragePoints["ISA_70"] = true;
                coveragePointsCount++;
              }
              if (((encodedInstr & 127) == 35)) {
                if(!coveragePoints["ISA_71"]){
                  coveragePoints["ISA_71"] = true;
                  coveragePointsCount++;
                }
                return(ENC_S);
              } else {
                if(!coveragePoints["ISA_72"]){
                  coveragePoints["ISA_72"] = true;
                  coveragePointsCount++;
                }
                if (((encodedInstr & 127) == 99)) {
                  if(!coveragePoints["ISA_73"]){
                    coveragePoints["ISA_73"] = true;
                    coveragePointsCount++;
                  }
                  return(ENC_B);
                } else {
                  if(!coveragePoints["ISA_74"]){
                    coveragePoints["ISA_74"] = true;
                    coveragePointsCount++;
                  }
                  if ((((encodedInstr & 127) == 55) or ((encodedInstr & 127) == 23))) {
                    if(!coveragePoints["ISA_75"]){
                      coveragePoints["ISA_75"] = true;
                      coveragePointsCount++;
                    }
                    return(ENC_U);
                  } else {
                    if(!coveragePoints["ISA_76"]){
                      coveragePoints["ISA_76"] = true;
                      coveragePointsCount++;
                    }
                    if (((encodedInstr & 127) == 111)) {
                      if(!coveragePoints["ISA_77"]){
                        coveragePoints["ISA_77"] = true;
                        coveragePointsCount++;
                      }
                      return(ENC_J);
                    } else {
                      if(!coveragePoints["ISA_78"]){
                        coveragePoints["ISA_78"] = true;
                        coveragePointsCount++;
                      }
                      return(ENC_ERR);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    unsigned getEncUALUresult(unsigned encodedInstr, unsigned pcReg) {
      if ((getInstrType(encodedInstr) == INSTR_LUI)) {
        if(!coveragePoints["ISA_79"]){
          coveragePoints["ISA_79"] = true;
          coveragePointsCount++;
        }
        return(getALUresult(ALU_COPY1,getImmediate(encodedInstr),0));
      } else {
        if(!coveragePoints["ISA_80"]){
          coveragePoints["ISA_80"] = true;
          coveragePointsCount++;
        }
        return(getALUresult(ALU_ADD,pcReg,getImmediate(encodedInstr)));
      }
    }

    unsigned getImmediate(unsigned encodedInstr) {
      if (((((encodedInstr & 127) == 19) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 103))) {
        if(!coveragePoints["ISA_81"]){
          coveragePoints["ISA_81"] = true;
          coveragePointsCount++;
        }
        if ((((encodedInstr >> 31) & 1) == 0)) {
          if(!coveragePoints["ISA_82"]){
            coveragePoints["ISA_82"] = true;
            coveragePointsCount++;
          }
          return((encodedInstr >> 20));
        } else {
          if(!coveragePoints["ISA_83"]){
            coveragePoints["ISA_83"] = true;
            coveragePointsCount++;
          }
          return((static_cast<unsigned>(-4096) | (encodedInstr >> 20)));
        }
      } else {
        if(!coveragePoints["ISA_84"]){
          coveragePoints["ISA_84"] = true;
          coveragePointsCount++;
        }
        if (((encodedInstr & 127) == 35)) {
          if(!coveragePoints["ISA_85"]){
            coveragePoints["ISA_85"] = true;
            coveragePointsCount++;
          }
          if ((((encodedInstr >> 31) & 1) == 0)) {
            if(!coveragePoints["ISA_86"]){
              coveragePoints["ISA_86"] = true;
              coveragePointsCount++;
            }
            return((((encodedInstr >> 20) & 4064) | ((encodedInstr >> 7) & 31)));
          } else {
            if(!coveragePoints["ISA_87"]){
              coveragePoints["ISA_87"] = true;
              coveragePointsCount++;
            }
            return((static_cast<unsigned>(-4096) | (((encodedInstr >> 20) & 4064) | ((encodedInstr >> 7) & 31))));
          }
        } else {
          if(!coveragePoints["ISA_88"]){
            coveragePoints["ISA_88"] = true;
            coveragePointsCount++;
          }
          if (((encodedInstr & 127) == 99)) {
            if(!coveragePoints["ISA_89"]){
              coveragePoints["ISA_89"] = true;
              coveragePointsCount++;
            }
            if ((((encodedInstr >> 31) & 1) == 0)) {
              if(!coveragePoints["ISA_90"]){
                coveragePoints["ISA_90"] = true;
                coveragePointsCount++;
              }
              return(((((encodedInstr << 4) & 2048) | ((encodedInstr >> 20) & 2016)) | ((encodedInstr >> 7) & 30)));
            } else {
              if(!coveragePoints["ISA_91"]){
                coveragePoints["ISA_91"] = true;
                coveragePointsCount++;
              }
              return((static_cast<unsigned>(-4096) | ((((encodedInstr << 4) & 2048) | ((encodedInstr >> 20) & 2016)) | ((encodedInstr >> 7) & 30))));
            }
          } else {
            if(!coveragePoints["ISA_92"]){
              coveragePoints["ISA_92"] = true;
              coveragePointsCount++;
            }
            if ((((encodedInstr & 127) == 55) or ((encodedInstr & 127) == 23))) {
              if(!coveragePoints["ISA_93"]){
                coveragePoints["ISA_93"] = true;
                coveragePointsCount++;
              }
              return((encodedInstr & static_cast<unsigned>(-4096)));
            } else {
              if(!coveragePoints["ISA_94"]){
                coveragePoints["ISA_94"] = true;
                coveragePointsCount++;
              }
              if (((encodedInstr & 127) == 111)) {
                if(!coveragePoints["ISA_95"]){
                  coveragePoints["ISA_95"] = true;
                  coveragePointsCount++;
                }
                if ((((encodedInstr >> 31) & 1) == 0)) {
                  if(!coveragePoints["ISA_96"]){
                    coveragePoints["ISA_96"] = true;
                    coveragePointsCount++;
                  }
                  return((((encodedInstr & 1044480) | ((encodedInstr >> 9) & 2048)) | ((encodedInstr >> 20) & 2046)));
                } else {
                  if(!coveragePoints["ISA_97"]){
                    coveragePoints["ISA_97"] = true;
                    coveragePointsCount++;
                  }
                  return((static_cast<unsigned>(-1048576) | (((encodedInstr & 1044480) | ((encodedInstr >> 9) & 2048)) | ((encodedInstr >> 20) & 2046))));
                }
              } else {
                if(!coveragePoints["ISA_98"]){
                  coveragePoints["ISA_98"] = true;
                  coveragePointsCount++;
                }
                return(0);
              }
            }
          }
        }
      }
    }

    InstrType getInstrType(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 51)) {
        if(!coveragePoints["ISA_99"]){
          coveragePoints["ISA_99"] = true;
          coveragePointsCount++;
        }
        if ((((encodedInstr >> 12) & 7) == 0)) {
          if(!coveragePoints["ISA_100"]){
            coveragePoints["ISA_100"] = true;
            coveragePointsCount++;
          }
          if ((((encodedInstr >> 25) & 127) == 0)) {
            if(!coveragePoints["ISA_101"]){
              coveragePoints["ISA_101"] = true;
              coveragePointsCount++;
            }
            return(INSTR_ADD);
          } else {
            if(!coveragePoints["ISA_102"]){
              coveragePoints["ISA_102"] = true;
              coveragePointsCount++;
            }
            if ((((encodedInstr >> 25) & 127) == 32)) {
              if(!coveragePoints["ISA_103"]){
                coveragePoints["ISA_103"] = true;
                coveragePointsCount++;
              }
              return(INSTR_SUB);
            } else {
              if(!coveragePoints["ISA_104"]){
                coveragePoints["ISA_104"] = true;
                coveragePointsCount++;
              }
              return(INSTR_UNKNOWN);
            }
          }
        } else {
          if(!coveragePoints["ISA_105"]){
            coveragePoints["ISA_105"] = true;
            coveragePointsCount++;
          }
          if ((((encodedInstr >> 12) & 7) == 1)) {
            if(!coveragePoints["ISA_106"]){
              coveragePoints["ISA_106"] = true;
              coveragePointsCount++;
            }
            return(INSTR_SLL);
          } else {
            if(!coveragePoints["ISA_107"]){
              coveragePoints["ISA_107"] = true;
              coveragePointsCount++;
            }
            if ((((encodedInstr >> 12) & 7) == 2)) {
              if(!coveragePoints["ISA_108"]){
                coveragePoints["ISA_108"] = true;
                coveragePointsCount++;
              }
              return(INSTR_SLT);
            } else {
              if(!coveragePoints["ISA_109"]){
                coveragePoints["ISA_109"] = true;
                coveragePointsCount++;
              }
              if ((((encodedInstr >> 12) & 7) == 3)) {
                if(!coveragePoints["ISA_110"]){
                  coveragePoints["ISA_110"] = true;
                  coveragePointsCount++;
                }
                return(INSTR_SLTU);
              } else {
                if(!coveragePoints["ISA_111"]){
                  coveragePoints["ISA_111"] = true;
                  coveragePointsCount++;
                }
                if ((((encodedInstr >> 12) & 7) == 4)) {
                  if(!coveragePoints["ISA_112"]){
                    coveragePoints["ISA_112"] = true;
                    coveragePointsCount++;
                  }
                  return(INSTR_XOR);
                } else {
                  if(!coveragePoints["ISA_113"]){
                    coveragePoints["ISA_113"] = true;
                    coveragePointsCount++;
                  }
                  if ((((encodedInstr >> 12) & 7) == 5)) {
                    if(!coveragePoints["ISA_114"]){
                      coveragePoints["ISA_114"] = true;
                      coveragePointsCount++;
                    }
                    if ((((encodedInstr >> 25) & 127) == 0)) {
                      if(!coveragePoints["ISA_115"]){
                        coveragePoints["ISA_115"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_SRL);
                    } else {
                      if(!coveragePoints["ISA_116"]){
                        coveragePoints["ISA_116"] = true;
                        coveragePointsCount++;
                      }
                      if ((((encodedInstr >> 25) & 127) == 32)) {
                        if(!coveragePoints["ISA_117"]){
                          coveragePoints["ISA_117"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_SRA);
                      } else {
                        if(!coveragePoints["ISA_118"]){
                          coveragePoints["ISA_118"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_UNKNOWN);
                      }
                    }
                  } else {
                    if(!coveragePoints["ISA_119"]){
                      coveragePoints["ISA_119"] = true;
                      coveragePointsCount++;
                    }
                    if ((((encodedInstr >> 12) & 7) == 6)) {
                      if(!coveragePoints["ISA_120"]){
                        coveragePoints["ISA_120"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_OR);
                    } else {
                      if(!coveragePoints["ISA_121"]){
                        coveragePoints["ISA_121"] = true;
                        coveragePointsCount++;
                      }
                      if ((((encodedInstr >> 12) & 7) == 7)) {
                        if(!coveragePoints["ISA_122"]){
                          coveragePoints["ISA_122"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_AND);
                      } else {
                        if(!coveragePoints["ISA_123"]){
                          coveragePoints["ISA_123"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_UNKNOWN);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else {
        if(!coveragePoints["ISA_124"]){
          coveragePoints["ISA_124"] = true;
          coveragePointsCount++;
        }
        if (((encodedInstr & 127) == 19)) {
          if(!coveragePoints["ISA_125"]){
            coveragePoints["ISA_125"] = true;
            coveragePointsCount++;
          }
          if ((((encodedInstr >> 12) & 7) == 0)) {
            if(!coveragePoints["ISA_126"]){
              coveragePoints["ISA_126"] = true;
              coveragePointsCount++;
            }
            return(INSTR_ADDI);
          } else {
            if(!coveragePoints["ISA_127"]){
              coveragePoints["ISA_127"] = true;
              coveragePointsCount++;
            }
            if ((((encodedInstr >> 12) & 7) == 1)) {
              if(!coveragePoints["ISA_128"]){
                coveragePoints["ISA_128"] = true;
                coveragePointsCount++;
              }
              return(INSTR_SLLI);
            } else {
              if(!coveragePoints["ISA_129"]){
                coveragePoints["ISA_129"] = true;
                coveragePointsCount++;
              }
              if ((((encodedInstr >> 12) & 7) == 2)) {
                if(!coveragePoints["ISA_130"]){
                  coveragePoints["ISA_130"] = true;
                  coveragePointsCount++;
                }
                return(INSTR_SLTI);
              } else {
                if(!coveragePoints["ISA_131"]){
                  coveragePoints["ISA_131"] = true;
                  coveragePointsCount++;
                }
                if ((((encodedInstr >> 12) & 7) == 3)) {
                  if(!coveragePoints["ISA_132"]){
                    coveragePoints["ISA_132"] = true;
                    coveragePointsCount++;
                  }
                  return(INSTR_SLTUI);
                } else {
                  if(!coveragePoints["ISA_133"]){
                    coveragePoints["ISA_133"] = true;
                    coveragePointsCount++;
                  }
                  if ((((encodedInstr >> 12) & 7) == 4)) {
                    if(!coveragePoints["ISA_134"]){
                      coveragePoints["ISA_134"] = true;
                      coveragePointsCount++;
                    }
                    return(INSTR_XORI);
                  } else {
                    if(!coveragePoints["ISA_135"]){
                      coveragePoints["ISA_135"] = true;
                      coveragePointsCount++;
                    }
                    if ((((encodedInstr >> 12) & 7) == 5)) {
                      if(!coveragePoints["ISA_136"]){
                        coveragePoints["ISA_136"] = true;
                        coveragePointsCount++;
                      }
                      if ((((encodedInstr >> 25) & 127) == 0)) {
                        if(!coveragePoints["ISA_137"]){
                          coveragePoints["ISA_137"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_SRLI);
                      } else {
                        if(!coveragePoints["ISA_138"]){
                          coveragePoints["ISA_138"] = true;
                          coveragePointsCount++;
                        }
                        if ((((encodedInstr >> 25) & 127) == 32)) {
                          if(!coveragePoints["ISA_139"]){
                            coveragePoints["ISA_139"] = true;
                            coveragePointsCount++;
                          }
                          return(INSTR_SRAI);
                        } else {
                          if(!coveragePoints["ISA_140"]){
                            coveragePoints["ISA_140"] = true;
                            coveragePointsCount++;
                          }
                          return(INSTR_UNKNOWN);
                        }
                      }
                    } else {
                      if(!coveragePoints["ISA_141"]){
                        coveragePoints["ISA_141"] = true;
                        coveragePointsCount++;
                      }
                      if ((((encodedInstr >> 12) & 7) == 6)) {
                        if(!coveragePoints["ISA_142"]){
                          coveragePoints["ISA_142"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_ORI);
                      } else {
                        if(!coveragePoints["ISA_143"]){
                          coveragePoints["ISA_143"] = true;
                          coveragePointsCount++;
                        }
                        if ((((encodedInstr >> 12) & 7) == 7)) {
                          if(!coveragePoints["ISA_144"]){
                            coveragePoints["ISA_144"] = true;
                            coveragePointsCount++;
                          }
                          return(INSTR_ANDI);
                        } else {
                          if(!coveragePoints["ISA_145"]){
                            coveragePoints["ISA_145"] = true;
                            coveragePointsCount++;
                          }
                          return(INSTR_UNKNOWN);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        } else {
          if(!coveragePoints["ISA_146"]){
            coveragePoints["ISA_146"] = true;
            coveragePointsCount++;
          }
          if (((encodedInstr & 127) == 3)) {
            if(!coveragePoints["ISA_147"]){
              coveragePoints["ISA_147"] = true;
              coveragePointsCount++;
            }
            if ((((encodedInstr >> 12) & 7) == 0)) {
              if(!coveragePoints["ISA_148"]){
                coveragePoints["ISA_148"] = true;
                coveragePointsCount++;
              }
              return(INSTR_LB);
            } else {
              if(!coveragePoints["ISA_149"]){
                coveragePoints["ISA_149"] = true;
                coveragePointsCount++;
              }
              if ((((encodedInstr >> 12) & 7) == 1)) {
                if(!coveragePoints["ISA_150"]){
                  coveragePoints["ISA_150"] = true;
                  coveragePointsCount++;
                }
                return(INSTR_LH);
              } else {
                if(!coveragePoints["ISA_151"]){
                  coveragePoints["ISA_151"] = true;
                  coveragePointsCount++;
                }
                if ((((encodedInstr >> 12) & 7) == 2)) {
                  if(!coveragePoints["ISA_152"]){
                    coveragePoints["ISA_152"] = true;
                    coveragePointsCount++;
                  }
                  return(INSTR_LW);
                } else {
                  if(!coveragePoints["ISA_153"]){
                    coveragePoints["ISA_153"] = true;
                    coveragePointsCount++;
                  }
                  if ((((encodedInstr >> 12) & 7) == 4)) {
                    if(!coveragePoints["ISA_154"]){
                      coveragePoints["ISA_154"] = true;
                      coveragePointsCount++;
                    }
                    return(INSTR_LBU);
                  } else {
                    if(!coveragePoints["ISA_155"]){
                      coveragePoints["ISA_155"] = true;
                      coveragePointsCount++;
                    }
                    if ((((encodedInstr >> 12) & 7) == 5)) {
                      if(!coveragePoints["ISA_156"]){
                        coveragePoints["ISA_156"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_LHU);
                    } else {
                      if(!coveragePoints["ISA_157"]){
                        coveragePoints["ISA_157"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_UNKNOWN);
                    }
                  }
                }
              }
            }
          } else {
            if(!coveragePoints["ISA_158"]){
              coveragePoints["ISA_158"] = true;
              coveragePointsCount++;
            }
            if (((encodedInstr & 127) == 103)) {
              if(!coveragePoints["ISA_159"]){
                coveragePoints["ISA_159"] = true;
                coveragePointsCount++;
              }
              return(INSTR_JALR);
            } else {
              if(!coveragePoints["ISA_160"]){
                coveragePoints["ISA_160"] = true;
                coveragePointsCount++;
              }
              if (((encodedInstr & 127) == 35)) {
                if(!coveragePoints["ISA_161"]){
                  coveragePoints["ISA_161"] = true;
                  coveragePointsCount++;
                }
                if ((((encodedInstr >> 12) & 7) == 0)) {
                  if(!coveragePoints["ISA_162"]){
                    coveragePoints["ISA_162"] = true;
                    coveragePointsCount++;
                  }
                  return(INSTR_SB);
                } else {
                  if(!coveragePoints["ISA_163"]){
                    coveragePoints["ISA_163"] = true;
                    coveragePointsCount++;
                  }
                  if ((((encodedInstr >> 12) & 7) == 1)) {
                    if(!coveragePoints["ISA_164"]){
                      coveragePoints["ISA_164"] = true;
                      coveragePointsCount++;
                    }
                    return(INSTR_SH);
                  } else {
                    if(!coveragePoints["ISA_165"]){
                      coveragePoints["ISA_165"] = true;
                      coveragePointsCount++;
                    }
                    if ((((encodedInstr >> 12) & 7) == 2)) {
                      if(!coveragePoints["ISA_166"]){
                        coveragePoints["ISA_166"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_SW);
                    } else {
                      if(!coveragePoints["ISA_167"]){
                        coveragePoints["ISA_167"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_UNKNOWN);
                    }
                  }
                }
              } else {
                if(!coveragePoints["ISA_168"]){
                  coveragePoints["ISA_168"] = true;
                  coveragePointsCount++;
                }
                if (((encodedInstr & 127) == 99)) {
                  if(!coveragePoints["ISA_169"]){
                    coveragePoints["ISA_169"] = true;
                    coveragePointsCount++;
                  }
                  if ((((encodedInstr >> 12) & 7) == 0)) {
                    if(!coveragePoints["ISA_170"]){
                      coveragePoints["ISA_170"] = true;
                      coveragePointsCount++;
                    }
                    return(INSTR_BEQ);
                  } else {
                    if(!coveragePoints["ISA_171"]){
                      coveragePoints["ISA_171"] = true;
                      coveragePointsCount++;
                    }
                    if ((((encodedInstr >> 12) & 7) == 1)) {
                      if(!coveragePoints["ISA_172"]){
                        coveragePoints["ISA_172"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_BNE);
                    } else {
                      if(!coveragePoints["ISA_173"]){
                        coveragePoints["ISA_173"] = true;
                        coveragePointsCount++;
                      }
                      if ((((encodedInstr >> 12) & 7) == 4)) {
                        if(!coveragePoints["ISA_174"]){
                          coveragePoints["ISA_174"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_BLT);
                      } else {
                        if(!coveragePoints["ISA_175"]){
                          coveragePoints["ISA_175"] = true;
                          coveragePointsCount++;
                        }
                        if ((((encodedInstr >> 12) & 7) == 5)) {
                          if(!coveragePoints["ISA_176"]){
                            coveragePoints["ISA_176"] = true;
                            coveragePointsCount++;
                          }
                          return(INSTR_BGE);
                        } else {
                          if(!coveragePoints["ISA_177"]){
                            coveragePoints["ISA_177"] = true;
                            coveragePointsCount++;
                          }
                          if ((((encodedInstr >> 12) & 7) == 6)) {
                            if(!coveragePoints["ISA_178"]){
                              coveragePoints["ISA_178"] = true;
                              coveragePointsCount++;
                            }
                            return(INSTR_BLTU);
                          } else {
                            if(!coveragePoints["ISA_179"]){
                              coveragePoints["ISA_179"] = true;
                              coveragePointsCount++;
                            }
                            if ((((encodedInstr >> 12) & 7) == 7)) {
                              if(!coveragePoints["ISA_180"]){
                                coveragePoints["ISA_180"] = true;
                                coveragePointsCount++;
                              }
                              return(INSTR_BGEU);
                            } else {
                              if(!coveragePoints["ISA_181"]){
                                coveragePoints["ISA_181"] = true;
                                coveragePointsCount++;
                              }
                              return(INSTR_UNKNOWN);
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                  if(!coveragePoints["ISA_182"]){
                    coveragePoints["ISA_182"] = true;
                    coveragePointsCount++;
                  }
                  if (((encodedInstr & 127) == 55)) {
                    if(!coveragePoints["ISA_183"]){
                      coveragePoints["ISA_183"] = true;
                      coveragePointsCount++;
                    }
                    return(INSTR_LUI);
                  } else {
                    if(!coveragePoints["ISA_184"]){
                      coveragePoints["ISA_184"] = true;
                      coveragePointsCount++;
                    }
                    if (((encodedInstr & 127) == 23)) {
                      if(!coveragePoints["ISA_185"]){
                        coveragePoints["ISA_185"] = true;
                        coveragePointsCount++;
                      }
                      return(INSTR_AUIPC);
                    } else {
                      if(!coveragePoints["ISA_186"]){
                        coveragePoints["ISA_186"] = true;
                        coveragePointsCount++;
                      }
                      if (((encodedInstr & 127) == 111)) {
                        if(!coveragePoints["ISA_187"]){
                          coveragePoints["ISA_187"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_JAL);
                      } else {
                        if(!coveragePoints["ISA_188"]){
                          coveragePoints["ISA_188"] = true;
                          coveragePointsCount++;
                        }
                        return(INSTR_UNKNOWN);
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

    ME_MaskType getMemoryMask(InstrType instr) {
      if (((instr == INSTR_LB) or (instr == INSTR_SB))) {
        if(!coveragePoints["ISA_189"]){
          coveragePoints["ISA_189"] = true;
          coveragePointsCount++;
        }
        return(MT_B);
      } else {
        if(!coveragePoints["ISA_190"]){
          coveragePoints["ISA_190"] = true;
          coveragePointsCount++;
        }
        if (((instr == INSTR_LH) or (instr == INSTR_SH))) {
          if(!coveragePoints["ISA_191"]){
            coveragePoints["ISA_191"] = true;
            coveragePointsCount++;
          }
          return(MT_H);
        } else {
          if(!coveragePoints["ISA_192"]){
            coveragePoints["ISA_192"] = true;
            coveragePointsCount++;
          }
          if (((instr == INSTR_LW) or (instr == INSTR_SW))) {
            if(!coveragePoints["ISA_193"]){
              coveragePoints["ISA_193"] = true;
              coveragePointsCount++;
            }
            return(MT_W);
          } else {
            if(!coveragePoints["ISA_194"]){
              coveragePoints["ISA_194"] = true;
              coveragePointsCount++;
            }
            if ((instr == INSTR_LBU)) {
              if(!coveragePoints["ISA_195"]){
                coveragePoints["ISA_195"] = true;
                coveragePointsCount++;
              }
              return(MT_BU);
            } else {
              if(!coveragePoints["ISA_196"]){
                coveragePoints["ISA_196"] = true;
                coveragePointsCount++;
              }
              if ((instr == INSTR_LHU)) {
                if(!coveragePoints["ISA_197"]){
                  coveragePoints["ISA_197"] = true;
                  coveragePointsCount++;
                }
                return(MT_HU);
              } else {
                if(!coveragePoints["ISA_198"]){
                  coveragePoints["ISA_198"] = true;
                  coveragePointsCount++;
                }
                return(MT_X);
              }
            }
          }
        }
      }
    }

    unsigned getRdAddr(unsigned encodedInstr) {
      if (((((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 103)) or ((encodedInstr & 127) == 55)) or ((encodedInstr & 127) == 23)) or ((encodedInstr & 127) == 111))) {
        if(!coveragePoints["ISA_199"]){
          coveragePoints["ISA_199"] = true;
          coveragePointsCount++;
        }
        return(((encodedInstr >> 7) & 31));
      } else {
        if(!coveragePoints["ISA_200"]){
          coveragePoints["ISA_200"] = true;
          coveragePointsCount++;
        }
        return(0);
      }
    }

    unsigned getRs1Addr(unsigned encodedInstr) {
      if ((((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 103)) or ((encodedInstr & 127) == 35)) or ((encodedInstr & 127) == 99))) {
        if(!coveragePoints["ISA_201"]){
          coveragePoints["ISA_201"] = true;
          coveragePointsCount++;
        }
        return(((encodedInstr >> 15) & 31));
      } else {
        if(!coveragePoints["ISA_202"]){
          coveragePoints["ISA_202"] = true;
          coveragePointsCount++;
        }
        return(0);
      }
    }

    unsigned getRs2Addr(unsigned encodedInstr) {
      if (((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 35)) or ((encodedInstr & 127) == 99))) {
        if(!coveragePoints["ISA_203"]){
          coveragePoints["ISA_203"] = true;
          coveragePointsCount++;
        }
        return(((encodedInstr >> 20) & 31));
      } else {
        if(!coveragePoints["ISA_204"]){
          coveragePoints["ISA_204"] = true;
          coveragePointsCount++;
        }
        return(0);
      }
    }

    unsigned readRegfile(RegfileType regfile, unsigned src) {
      if ((src == 0)) {
        if(!coveragePoints["ISA_205"]){
          coveragePoints["ISA_205"] = true;
          coveragePointsCount++;
        }
        return(0);
      } else {
        if(!coveragePoints["ISA_206"]){
          coveragePoints["ISA_206"] = true;
          coveragePointsCount++;
        }
        if ((src == 1)) {
          if(!coveragePoints["ISA_207"]){
            coveragePoints["ISA_207"] = true;
            coveragePointsCount++;
          }
          return(regfile.reg_file_01);
        } else {
          if(!coveragePoints["ISA_208"]){
            coveragePoints["ISA_208"] = true;
            coveragePointsCount++;
          }
          if ((src == 2)) {
            if(!coveragePoints["ISA_209"]){
              coveragePoints["ISA_209"] = true;
              coveragePointsCount++;
            }
            return(regfile.reg_file_02);
          } else {
            if(!coveragePoints["ISA_210"]){
              coveragePoints["ISA_210"] = true;
              coveragePointsCount++;
            }
            if ((src == 3)) {
              if(!coveragePoints["ISA_211"]){
                coveragePoints["ISA_211"] = true;
                coveragePointsCount++;
              }
              return(regfile.reg_file_03);
            } else {
              if(!coveragePoints["ISA_212"]){
                coveragePoints["ISA_212"] = true;
                coveragePointsCount++;
              }
              if ((src == 4)) {
                if(!coveragePoints["ISA_213"]){
                  coveragePoints["ISA_213"] = true;
                  coveragePointsCount++;
                }
                return(regfile.reg_file_04);
              } else {
                if(!coveragePoints["ISA_214"]){
                  coveragePoints["ISA_214"] = true;
                  coveragePointsCount++;
                }
                if ((src == 5)) {
                  if(!coveragePoints["ISA_215"]){
                    coveragePoints["ISA_215"] = true;
                    coveragePointsCount++;
                  }
                  return(regfile.reg_file_05);
                } else {
                  if(!coveragePoints["ISA_216"]){
                    coveragePoints["ISA_216"] = true;
                    coveragePointsCount++;
                  }
                  if ((src == 6)) {
                    if(!coveragePoints["ISA_217"]){
                      coveragePoints["ISA_217"] = true;
                      coveragePointsCount++;
                    }
                    return(regfile.reg_file_06);
                  } else {
                    if(!coveragePoints["ISA_218"]){
                      coveragePoints["ISA_218"] = true;
                      coveragePointsCount++;
                    }
                    if ((src == 7)) {
                      if(!coveragePoints["ISA_219"]){
                        coveragePoints["ISA_219"] = true;
                        coveragePointsCount++;
                      }
                      return(regfile.reg_file_07);
                    } else {
                      if(!coveragePoints["ISA_220"]){
                        coveragePoints["ISA_220"] = true;
                        coveragePointsCount++;
                      }
                      if ((src == 8)) {
                        if(!coveragePoints["ISA_221"]){
                          coveragePoints["ISA_221"] = true;
                          coveragePointsCount++;
                        }
                        return(regfile.reg_file_08);
                      } else {
                        if(!coveragePoints["ISA_222"]){
                          coveragePoints["ISA_222"] = true;
                          coveragePointsCount++;
                        }
                        if ((src == 9)) {
                          if(!coveragePoints["ISA_223"]){
                            coveragePoints["ISA_223"] = true;
                            coveragePointsCount++;
                          }
                          return(regfile.reg_file_09);
                        } else {
                          if(!coveragePoints["ISA_224"]){
                            coveragePoints["ISA_224"] = true;
                            coveragePointsCount++;
                          }
                          if ((src == 10)) {
                            if(!coveragePoints["ISA_225"]){
                              coveragePoints["ISA_225"] = true;
                              coveragePointsCount++;
                            }
                            return(regfile.reg_file_10);
                          } else {
                            if(!coveragePoints["ISA_226"]){
                              coveragePoints["ISA_226"] = true;
                              coveragePointsCount++;
                            }
                            if ((src == 11)) {
                              if(!coveragePoints["ISA_227"]){
                                coveragePoints["ISA_227"] = true;
                                coveragePointsCount++;
                              }
                              return(regfile.reg_file_11);
                            } else {
                              if(!coveragePoints["ISA_228"]){
                                coveragePoints["ISA_228"] = true;
                                coveragePointsCount++;
                              }
                              if ((src == 12)) {
                                if(!coveragePoints["ISA_229"]){
                                  coveragePoints["ISA_229"] = true;
                                  coveragePointsCount++;
                                }
                                return(regfile.reg_file_12);
                              } else {
                                if(!coveragePoints["ISA_230"]){
                                  coveragePoints["ISA_230"] = true;
                                  coveragePointsCount++;
                                }
                                if ((src == 13)) {
                                  if(!coveragePoints["ISA_231"]){
                                    coveragePoints["ISA_231"] = true;
                                    coveragePointsCount++;
                                  }
                                  return(regfile.reg_file_13);
                                } else {
                                  if(!coveragePoints["ISA_232"]){
                                    coveragePoints["ISA_232"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((src == 14)) {
                                    if(!coveragePoints["ISA_233"]){
                                      coveragePoints["ISA_233"] = true;
                                      coveragePointsCount++;
                                    }
                                    return(regfile.reg_file_14);
                                  } else {
                                    if(!coveragePoints["ISA_234"]){
                                      coveragePoints["ISA_234"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((src == 15)) {
                                      if(!coveragePoints["ISA_235"]){
                                        coveragePoints["ISA_235"] = true;
                                        coveragePointsCount++;
                                      }
                                      return(regfile.reg_file_15);
                                    } else {
                                      if(!coveragePoints["ISA_236"]){
                                        coveragePoints["ISA_236"] = true;
                                        coveragePointsCount++;
                                      }
                                      if ((src == 16)) {
                                        if(!coveragePoints["ISA_237"]){
                                          coveragePoints["ISA_237"] = true;
                                          coveragePointsCount++;
                                        }
                                        return(regfile.reg_file_16);
                                      } else {
                                        if(!coveragePoints["ISA_238"]){
                                          coveragePoints["ISA_238"] = true;
                                          coveragePointsCount++;
                                        }
                                        if ((src == 17)) {
                                          if(!coveragePoints["ISA_239"]){
                                            coveragePoints["ISA_239"] = true;
                                            coveragePointsCount++;
                                          }
                                          return(regfile.reg_file_17);
                                        } else {
                                          if(!coveragePoints["ISA_240"]){
                                            coveragePoints["ISA_240"] = true;
                                            coveragePointsCount++;
                                          }
                                          if ((src == 18)) {
                                            if(!coveragePoints["ISA_241"]){
                                              coveragePoints["ISA_241"] = true;
                                              coveragePointsCount++;
                                            }
                                            return(regfile.reg_file_18);
                                          } else {
                                            if(!coveragePoints["ISA_242"]){
                                              coveragePoints["ISA_242"] = true;
                                              coveragePointsCount++;
                                            }
                                            if ((src == 19)) {
                                              if(!coveragePoints["ISA_243"]){
                                                coveragePoints["ISA_243"] = true;
                                                coveragePointsCount++;
                                              }
                                              return(regfile.reg_file_19);
                                            } else {
                                              if(!coveragePoints["ISA_244"]){
                                                coveragePoints["ISA_244"] = true;
                                                coveragePointsCount++;
                                              }
                                              if ((src == 20)) {
                                                if(!coveragePoints["ISA_245"]){
                                                  coveragePoints["ISA_245"] = true;
                                                  coveragePointsCount++;
                                                }
                                                return(regfile.reg_file_20);
                                              } else {
                                                if(!coveragePoints["ISA_246"]){
                                                  coveragePoints["ISA_246"] = true;
                                                  coveragePointsCount++;
                                                }
                                                if ((src == 21)) {
                                                  if(!coveragePoints["ISA_247"]){
                                                    coveragePoints["ISA_247"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  return(regfile.reg_file_21);
                                                } else {
                                                  if(!coveragePoints["ISA_248"]){
                                                    coveragePoints["ISA_248"] = true;
                                                    coveragePointsCount++;
                                                  }
                                                  if ((src == 22)) {
                                                    if(!coveragePoints["ISA_249"]){
                                                      coveragePoints["ISA_249"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    return(regfile.reg_file_22);
                                                  } else {
                                                    if(!coveragePoints["ISA_250"]){
                                                      coveragePoints["ISA_250"] = true;
                                                      coveragePointsCount++;
                                                    }
                                                    if ((src == 23)) {
                                                      if(!coveragePoints["ISA_251"]){
                                                        coveragePoints["ISA_251"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      return(regfile.reg_file_23);
                                                    } else {
                                                      if(!coveragePoints["ISA_252"]){
                                                        coveragePoints["ISA_252"] = true;
                                                        coveragePointsCount++;
                                                      }
                                                      if ((src == 24)) {
                                                        if(!coveragePoints["ISA_253"]){
                                                          coveragePoints["ISA_253"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        return(regfile.reg_file_24);
                                                      } else {
                                                        if(!coveragePoints["ISA_254"]){
                                                          coveragePoints["ISA_254"] = true;
                                                          coveragePointsCount++;
                                                        }
                                                        if ((src == 25)) {
                                                          if(!coveragePoints["ISA_255"]){
                                                            coveragePoints["ISA_255"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          return(regfile.reg_file_25);
                                                        } else {
                                                          if(!coveragePoints["ISA_256"]){
                                                            coveragePoints["ISA_256"] = true;
                                                            coveragePointsCount++;
                                                          }
                                                          if ((src == 26)) {
                                                            if(!coveragePoints["ISA_257"]){
                                                              coveragePoints["ISA_257"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            return(regfile.reg_file_26);
                                                          } else {
                                                            if(!coveragePoints["ISA_258"]){
                                                              coveragePoints["ISA_258"] = true;
                                                              coveragePointsCount++;
                                                            }
                                                            if ((src == 27)) {
                                                              if(!coveragePoints["ISA_259"]){
                                                                coveragePoints["ISA_259"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              return(regfile.reg_file_27);
                                                            } else {
                                                              if(!coveragePoints["ISA_260"]){
                                                                coveragePoints["ISA_260"] = true;
                                                                coveragePointsCount++;
                                                              }
                                                              if ((src == 28)) {
                                                                if(!coveragePoints["ISA_261"]){
                                                                  coveragePoints["ISA_261"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                return(regfile.reg_file_28);
                                                              } else {
                                                                if(!coveragePoints["ISA_262"]){
                                                                  coveragePoints["ISA_262"] = true;
                                                                  coveragePointsCount++;
                                                                }
                                                                if ((src == 29)) {
                                                                  if(!coveragePoints["ISA_263"]){
                                                                    coveragePoints["ISA_263"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  return(regfile.reg_file_29);
                                                                } else {
                                                                  if(!coveragePoints["ISA_264"]){
                                                                    coveragePoints["ISA_264"] = true;
                                                                    coveragePointsCount++;
                                                                  }
                                                                  if ((src == 30)) {
                                                                    if(!coveragePoints["ISA_265"]){
                                                                      coveragePoints["ISA_265"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    return(regfile.reg_file_30);
                                                                  } else {
                                                                    if(!coveragePoints["ISA_266"]){
                                                                      coveragePoints["ISA_266"] = true;
                                                                      coveragePointsCount++;
                                                                    }
                                                                    return(regfile.reg_file_31);
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


    unsigned aluOp1;
    unsigned aluOp2;
    unsigned aluResult;
    unsigned encodedInstr;
    MEtoCU_IF fromMemoryData;
    CUtoME_IF memoryAccess;
    unsigned pcReg;
    RegfileType regfile;
    RegfileWriteType regfileWrite;


    void FSM(){
        while(true) {
          if (section==execute) {
            if(!coveragePoints["ISA_267"]){
              coveragePoints["ISA_267"] = true;
              coveragePointsCount++;
            }
            if ((getEncType(encodedInstr) == ENC_R)) {
              if(!coveragePoints["ISA_268"]){
                coveragePoints["ISA_268"] = true;
                coveragePointsCount++;
              }
              fromRegsPort->read(regfile);
              getRs1Addr(encodedInstr);
              aluOp1 = readRegfile(regfile,getRs1Addr(encodedInstr));
              getRs2Addr(encodedInstr);
              aluOp2 = readRegfile(regfile,getRs2Addr(encodedInstr));
              aluResult = getALUresult(getALUfunc(getInstrType(encodedInstr)),aluOp1,aluOp2);
              regfileWrite.dst = getRdAddr(encodedInstr);
              regfileWrite.dstData = aluResult;
              toRegsPort->write(regfileWrite);
              pcReg = (pcReg + 4);
            } else {
              if(!coveragePoints["ISA_269"]){
                coveragePoints["ISA_269"] = true;
                coveragePointsCount++;
              }
              if ((getEncType(encodedInstr) == ENC_B)) {
                if(!coveragePoints["ISA_270"]){
                  coveragePoints["ISA_270"] = true;
                  coveragePointsCount++;
                }
                fromRegsPort->read(regfile);
                getRs1Addr(encodedInstr);
                aluOp1 = readRegfile(regfile,getRs1Addr(encodedInstr));
                getRs2Addr(encodedInstr);
                aluOp2 = readRegfile(regfile,getRs2Addr(encodedInstr));
                aluResult = getALUresult(getALUfunc(getInstrType(encodedInstr)),aluOp1,aluOp2);
                pcReg = branchPCcalculation(aluResult,encodedInstr,pcReg);
              } else {
                if(!coveragePoints["ISA_271"]){
                  coveragePoints["ISA_271"] = true;
                  coveragePointsCount++;
                }
                if ((getEncType(encodedInstr) == ENC_S)) {
                  if(!coveragePoints["ISA_272"]){
                    coveragePoints["ISA_272"] = true;
                    coveragePointsCount++;
                  }
                  fromRegsPort->read(regfile);
                  getRs1Addr(encodedInstr);
                  aluOp1 = readRegfile(regfile,getRs1Addr(encodedInstr));
                  aluOp2 = getImmediate(encodedInstr);
                  aluResult = getALUresult(ALU_ADD,aluOp1,aluOp2);
                  memoryAccess.req = ME_WR;
                  memoryAccess.mask = getMemoryMask(getInstrType(encodedInstr));
                  memoryAccess.addrIn = aluResult;
                  getRs2Addr(encodedInstr);
                  memoryAccess.dataIn = readRegfile(regfile,getRs2Addr(encodedInstr));
                  toMemoryPort->write(memoryAccess);
                  fromMemoryPort->read(fromMemoryData);
                  pcReg = (pcReg + 4);
                } else {
                  if(!coveragePoints["ISA_273"]){
                    coveragePoints["ISA_273"] = true;
                    coveragePointsCount++;
                  }
                  if ((getEncType(encodedInstr) == ENC_U)) {
                    if(!coveragePoints["ISA_274"]){
                      coveragePoints["ISA_274"] = true;
                      coveragePointsCount++;
                    }
                    regfileWrite.dst = getRdAddr(encodedInstr);
                    regfileWrite.dstData = getEncUALUresult(encodedInstr,pcReg);
                    toRegsPort->write(regfileWrite);
                    pcReg = (pcReg + 4);
                  } else {
                    if(!coveragePoints["ISA_275"]){
                      coveragePoints["ISA_275"] = true;
                      coveragePointsCount++;
                    }
                    if ((getEncType(encodedInstr) == ENC_J)) {
                      if(!coveragePoints["ISA_276"]){
                        coveragePoints["ISA_276"] = true;
                        coveragePointsCount++;
                      }
                      regfileWrite.dst = getRdAddr(encodedInstr);
                      regfileWrite.dstData = (pcReg + 4);
                      toRegsPort->write(regfileWrite);
                      pcReg = (pcReg + getImmediate(encodedInstr));
                    } else {
                      if(!coveragePoints["ISA_277"]){
                        coveragePoints["ISA_277"] = true;
                        coveragePointsCount++;
                      }
                      if ((getEncType(encodedInstr) == ENC_I_I)) {
                        if(!coveragePoints["ISA_278"]){
                          coveragePoints["ISA_278"] = true;
                          coveragePointsCount++;
                        }
                        fromRegsPort->read(regfile);
                        getRs1Addr(encodedInstr);
                        aluOp1 = readRegfile(regfile,getRs1Addr(encodedInstr));
                        aluOp2 = getImmediate(encodedInstr);
                        aluResult = getALUresult(getALUfunc(getInstrType(encodedInstr)),aluOp1,aluOp2);
                        regfileWrite.dst = getRdAddr(encodedInstr);
                        regfileWrite.dstData = aluResult;
                        toRegsPort->write(regfileWrite);
                        pcReg = (pcReg + 4);
                      } else {
                        if(!coveragePoints["ISA_279"]){
                          coveragePoints["ISA_279"] = true;
                          coveragePointsCount++;
                        }
                        if ((getEncType(encodedInstr) == ENC_I_L)) {
                          if(!coveragePoints["ISA_280"]){
                            coveragePoints["ISA_280"] = true;
                            coveragePointsCount++;
                          }
                          fromRegsPort->read(regfile);
                          getRs1Addr(encodedInstr);
                          aluOp1 = readRegfile(regfile,getRs1Addr(encodedInstr));
                          aluOp2 = getImmediate(encodedInstr);
                          aluResult = getALUresult(ALU_ADD,aluOp1,aluOp2);
                          memoryAccess.req = ME_RD;
                          memoryAccess.mask = getMemoryMask(getInstrType(encodedInstr));
                          memoryAccess.addrIn = aluResult;
                          memoryAccess.dataIn = 0;
                          regfileWrite.dst = getRdAddr(encodedInstr);
                          toMemoryPort->write(memoryAccess);
                          fromMemoryPort->read(fromMemoryData);
                          regfileWrite.dstData = fromMemoryData.loadedData;
                          toRegsPort->write(regfileWrite);
                          pcReg = (pcReg + 4);
                        } else {
                          if(!coveragePoints["ISA_281"]){
                            coveragePoints["ISA_281"] = true;
                            coveragePointsCount++;
                          }
                          if ((getEncType(encodedInstr) == ENC_I_J)) {
                            if(!coveragePoints["ISA_282"]){
                              coveragePoints["ISA_282"] = true;
                              coveragePointsCount++;
                            }
                            fromRegsPort->read(regfile);
                            regfileWrite.dst = getRdAddr(encodedInstr);
                            regfileWrite.dstData = (pcReg + 4);
                            toRegsPort->write(regfileWrite);
                            getRs1Addr(encodedInstr);
                            readRegfile(regfile,getRs1Addr(encodedInstr));
                            pcReg = (readRegfile(regfile,getRs1Addr(encodedInstr)) + getImmediate(encodedInstr));
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            section = fetch;
          }
          else if (section==fetch) {
            if(!coveragePoints["ISA_283"]){
              coveragePoints["ISA_283"] = true;
              coveragePointsCount++;
            }
            memoryAccess.req = ME_RD;
            memoryAccess.mask = MT_W;
            memoryAccess.addrIn = pcReg;
            memoryAccess.dataIn = 0;
            toMemoryPort->write(memoryAccess);
            fromMemoryPort->read(fromMemoryData);
            encodedInstr = fromMemoryData.loadedData;
            section = execute;
          }
          wait(SC_ZERO_TIME);
        }//end of while
    }//end of FSM
    int coveragePointsTotal = 283;
    int coveragePointsCount = 0;
    std::map<std::string, bool> coveragePoints;

    SC_HAS_PROCESS(ISA);

    ISA(sc_module_name name) :
      section(fetch),
      aluOp1(0),
      aluOp2(0),
      aluResult(0),
      encodedInstr(0),
      pcReg(0)    {
      SC_THREAD(FSM);
      for(int i = 1; i < coveragePointsTotal; i++)
            coveragePoints.insert(std::make_pair("ISA_"+to_string(i),false));
      }
    };//end of module


#endif //SYSTEMC_ISA_H
