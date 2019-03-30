#ifndef SYSTEMC_Control_unit_H
#define SYSTEMC_Control_unit_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

  struct Control_unit : public sc_module {

    enum Sections {decodeInstr, memAccess, setDataPathSignals, setDmemAccess, setPipelineSignals, setStallSignals, updatePC};
    Sections section;

    master_out<CUtoDP_IF> CUtoDP_port;
    blocking_out<CUtoME_IF> CUtoME_port;
    master_in<DPtoCU_IF> DPtoCU_port;
    blocking_in<MEtoCU_IF> MEtoCU_port;

    //functions
    ALUfuncType getALUfunc(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 51)) {
        if(!coveragePoints["Control_unit_1"]){
          coveragePoints["Control_unit_1"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((((encodedInstr >> 12) & 7) == 0)) {
          if(!coveragePoints["Control_unit_2"]){
            coveragePoints["Control_unit_2"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 25) & 127) == 0)) {
            if(!coveragePoints["Control_unit_3"]){
              coveragePoints["Control_unit_3"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(ALU_ADD);
          } else {
            if(!coveragePoints["Control_unit_4"]){
              coveragePoints["Control_unit_4"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 25) & 127) == 32)) {
              if(!coveragePoints["Control_unit_5"]){
                coveragePoints["Control_unit_5"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(ALU_SUB);
            } else {
              if(!coveragePoints["Control_unit_6"]){
                coveragePoints["Control_unit_6"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(ALU_X);
            }
          }
        } else {
          if(!coveragePoints["Control_unit_7"]){
            coveragePoints["Control_unit_7"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 12) & 7) == 1)) {
            if(!coveragePoints["Control_unit_8"]){
              coveragePoints["Control_unit_8"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(ALU_SLL);
          } else {
            if(!coveragePoints["Control_unit_9"]){
              coveragePoints["Control_unit_9"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 12) & 7) == 2)) {
              if(!coveragePoints["Control_unit_10"]){
                coveragePoints["Control_unit_10"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(ALU_SLT);
            } else {
              if(!coveragePoints["Control_unit_11"]){
                coveragePoints["Control_unit_11"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((encodedInstr >> 12) & 7) == 3)) {
                if(!coveragePoints["Control_unit_12"]){
                  coveragePoints["Control_unit_12"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(ALU_SLTU);
              } else {
                if(!coveragePoints["Control_unit_13"]){
                  coveragePoints["Control_unit_13"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((((encodedInstr >> 12) & 7) == 4)) {
                  if(!coveragePoints["Control_unit_14"]){
                    coveragePoints["Control_unit_14"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(ALU_XOR);
                } else {
                  if(!coveragePoints["Control_unit_15"]){
                    coveragePoints["Control_unit_15"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr >> 12) & 7) == 5)) {
                    if(!coveragePoints["Control_unit_16"]){
                      coveragePoints["Control_unit_16"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 25) & 127) == 0)) {
                      if(!coveragePoints["Control_unit_17"]){
                        coveragePoints["Control_unit_17"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(ALU_SRL);
                    } else {
                      if(!coveragePoints["Control_unit_18"]){
                        coveragePoints["Control_unit_18"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 25) & 127) == 32)) {
                        if(!coveragePoints["Control_unit_19"]){
                          coveragePoints["Control_unit_19"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(ALU_SRA);
                      } else {
                        if(!coveragePoints["Control_unit_20"]){
                          coveragePoints["Control_unit_20"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(ALU_X);
                      }
                    }
                  } else {
                    if(!coveragePoints["Control_unit_21"]){
                      coveragePoints["Control_unit_21"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 12) & 7) == 6)) {
                      if(!coveragePoints["Control_unit_22"]){
                        coveragePoints["Control_unit_22"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(ALU_OR);
                    } else {
                      if(!coveragePoints["Control_unit_23"]){
                        coveragePoints["Control_unit_23"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 12) & 7) == 7)) {
                        if(!coveragePoints["Control_unit_24"]){
                          coveragePoints["Control_unit_24"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(ALU_AND);
                      } else {
                        if(!coveragePoints["Control_unit_25"]){
                          coveragePoints["Control_unit_25"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
      } else {
        if(!coveragePoints["Control_unit_26"]){
          coveragePoints["Control_unit_26"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 19)) {
          if(!coveragePoints["Control_unit_27"]){
            coveragePoints["Control_unit_27"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 12) & 7) == 0)) {
            if(!coveragePoints["Control_unit_28"]){
              coveragePoints["Control_unit_28"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(ALU_ADD);
          } else {
            if(!coveragePoints["Control_unit_29"]){
              coveragePoints["Control_unit_29"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 12) & 7) == 1)) {
              if(!coveragePoints["Control_unit_30"]){
                coveragePoints["Control_unit_30"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(ALU_SLL);
            } else {
              if(!coveragePoints["Control_unit_31"]){
                coveragePoints["Control_unit_31"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((encodedInstr >> 12) & 7) == 2)) {
                if(!coveragePoints["Control_unit_32"]){
                  coveragePoints["Control_unit_32"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(ALU_SLT);
              } else {
                if(!coveragePoints["Control_unit_33"]){
                  coveragePoints["Control_unit_33"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((((encodedInstr >> 12) & 7) == 3)) {
                  if(!coveragePoints["Control_unit_34"]){
                    coveragePoints["Control_unit_34"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(ALU_SLTU);
                } else {
                  if(!coveragePoints["Control_unit_35"]){
                    coveragePoints["Control_unit_35"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr >> 12) & 7) == 4)) {
                    if(!coveragePoints["Control_unit_36"]){
                      coveragePoints["Control_unit_36"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(ALU_XOR);
                  } else {
                    if(!coveragePoints["Control_unit_37"]){
                      coveragePoints["Control_unit_37"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 12) & 7) == 5)) {
                      if(!coveragePoints["Control_unit_38"]){
                        coveragePoints["Control_unit_38"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 25) & 127) == 0)) {
                        if(!coveragePoints["Control_unit_39"]){
                          coveragePoints["Control_unit_39"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(ALU_SRL);
                      } else {
                        if(!coveragePoints["Control_unit_40"]){
                          coveragePoints["Control_unit_40"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((((encodedInstr >> 25) & 127) == 32)) {
                          if(!coveragePoints["Control_unit_41"]){
                            coveragePoints["Control_unit_41"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          return(ALU_SRA);
                        } else {
                          if(!coveragePoints["Control_unit_42"]){
                            coveragePoints["Control_unit_42"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          return(ALU_X);
                        }
                      }
                    } else {
                      if(!coveragePoints["Control_unit_43"]){
                        coveragePoints["Control_unit_43"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 12) & 7) == 6)) {
                        if(!coveragePoints["Control_unit_44"]){
                          coveragePoints["Control_unit_44"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(ALU_OR);
                      } else {
                        if(!coveragePoints["Control_unit_45"]){
                          coveragePoints["Control_unit_45"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((((encodedInstr >> 12) & 7) == 7)) {
                          if(!coveragePoints["Control_unit_46"]){
                            coveragePoints["Control_unit_46"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          return(ALU_AND);
                        } else {
                          if(!coveragePoints["Control_unit_47"]){
                            coveragePoints["Control_unit_47"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
        } else {
          if(!coveragePoints["Control_unit_48"]){
            coveragePoints["Control_unit_48"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if (((encodedInstr & 127) == 3)) {
            if(!coveragePoints["Control_unit_49"]){
              coveragePoints["Control_unit_49"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(ALU_ADD);
          } else {
            if(!coveragePoints["Control_unit_50"]){
              coveragePoints["Control_unit_50"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((encodedInstr & 127) == 35)) {
              if(!coveragePoints["Control_unit_51"]){
                coveragePoints["Control_unit_51"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(ALU_ADD);
            } else {
              if(!coveragePoints["Control_unit_52"]){
                coveragePoints["Control_unit_52"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if (((encodedInstr & 127) == 55)) {
                if(!coveragePoints["Control_unit_53"]){
                  coveragePoints["Control_unit_53"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(ALU_COPY1);
              } else {
                if(!coveragePoints["Control_unit_54"]){
                  coveragePoints["Control_unit_54"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (((encodedInstr & 127) == 23)) {
                  if(!coveragePoints["Control_unit_55"]){
                    coveragePoints["Control_unit_55"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(ALU_ADD);
                } else {
                  if(!coveragePoints["Control_unit_56"]){
                    coveragePoints["Control_unit_56"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(ALU_X);
                }
              }
            }
          }
        }
      }
    }

    AL_OperandSelType getALUop1Sel(unsigned encodedInstr) {
      if ((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 35))) {
        if(!coveragePoints["Control_unit_57"]){
          coveragePoints["Control_unit_57"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(OP_REG);
      } else {
        if(!coveragePoints["Control_unit_58"]){
          coveragePoints["Control_unit_58"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 55)) {
          if(!coveragePoints["Control_unit_59"]){
            coveragePoints["Control_unit_59"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(OP_IMM);
        } else {
          if(!coveragePoints["Control_unit_60"]){
            coveragePoints["Control_unit_60"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if (((encodedInstr & 127) == 23)) {
            if(!coveragePoints["Control_unit_61"]){
              coveragePoints["Control_unit_61"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(OP_PC);
          } else {
            if(!coveragePoints["Control_unit_62"]){
              coveragePoints["Control_unit_62"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(OP_X);
          }
        }
      }
    }

    AL_OperandSelType getALUop2Sel(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 51)) {
        if(!coveragePoints["Control_unit_63"]){
          coveragePoints["Control_unit_63"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(OP_REG);
      } else {
        if(!coveragePoints["Control_unit_64"]){
          coveragePoints["Control_unit_64"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((((((encodedInstr & 127) == 19) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 35)) or ((encodedInstr & 127) == 23))) {
          if(!coveragePoints["Control_unit_65"]){
            coveragePoints["Control_unit_65"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(OP_IMM);
        } else {
          if(!coveragePoints["Control_unit_66"]){
            coveragePoints["Control_unit_66"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(OP_X);
        }
      }
    }

    bool getBranchEvaluation(InstrType instrType, unsigned reg1Content, unsigned reg2Content) {
      if (((instrType == INSTR_BEQ) and ((reg1Content - reg2Content) == 0))) {
        if(!coveragePoints["Control_unit_67"]){
          coveragePoints["Control_unit_67"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(true);
      } else {
        if(!coveragePoints["Control_unit_68"]){
          coveragePoints["Control_unit_68"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((instrType == INSTR_BNE) and ((reg1Content - reg2Content) != 0))) {
          if(!coveragePoints["Control_unit_69"]){
            coveragePoints["Control_unit_69"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(true);
        } else {
          if(!coveragePoints["Control_unit_70"]){
            coveragePoints["Control_unit_70"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if (((instrType == INSTR_BLT) and (static_cast<int>(reg1Content) < static_cast<int>(reg2Content)))) {
            if(!coveragePoints["Control_unit_71"]){
              coveragePoints["Control_unit_71"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(true);
          } else {
            if(!coveragePoints["Control_unit_72"]){
              coveragePoints["Control_unit_72"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((instrType == INSTR_BGE) and (static_cast<int>(reg1Content) >= static_cast<int>(reg2Content)))) {
              if(!coveragePoints["Control_unit_73"]){
                coveragePoints["Control_unit_73"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(true);
            } else {
              if(!coveragePoints["Control_unit_74"]){
                coveragePoints["Control_unit_74"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if (((instrType == INSTR_BLTU) and (reg1Content < reg2Content))) {
                if(!coveragePoints["Control_unit_75"]){
                  coveragePoints["Control_unit_75"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(true);
              } else {
                if(!coveragePoints["Control_unit_76"]){
                  coveragePoints["Control_unit_76"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (((instrType == INSTR_BGEU) and (reg1Content >= reg2Content))) {
                  if(!coveragePoints["Control_unit_77"]){
                    coveragePoints["Control_unit_77"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(true);
                } else {
                  if(!coveragePoints["Control_unit_78"]){
                    coveragePoints["Control_unit_78"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(false);
                }
              }
            }
          }
        }
      }
    }

    ME_MaskType getDmemMask(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 3)) {
        if(!coveragePoints["Control_unit_79"]){
          coveragePoints["Control_unit_79"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((((encodedInstr >> 12) & 7) == 0)) {
          if(!coveragePoints["Control_unit_80"]){
            coveragePoints["Control_unit_80"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(MT_B);
        } else {
          if(!coveragePoints["Control_unit_81"]){
            coveragePoints["Control_unit_81"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 12) & 7) == 1)) {
            if(!coveragePoints["Control_unit_82"]){
              coveragePoints["Control_unit_82"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(MT_H);
          } else {
            if(!coveragePoints["Control_unit_83"]){
              coveragePoints["Control_unit_83"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 12) & 7) == 2)) {
              if(!coveragePoints["Control_unit_84"]){
                coveragePoints["Control_unit_84"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(MT_W);
            } else {
              if(!coveragePoints["Control_unit_85"]){
                coveragePoints["Control_unit_85"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((encodedInstr >> 12) & 7) == 4)) {
                if(!coveragePoints["Control_unit_86"]){
                  coveragePoints["Control_unit_86"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(MT_BU);
              } else {
                if(!coveragePoints["Control_unit_87"]){
                  coveragePoints["Control_unit_87"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((((encodedInstr >> 12) & 7) == 5)) {
                  if(!coveragePoints["Control_unit_88"]){
                    coveragePoints["Control_unit_88"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(MT_HU);
                } else {
                  if(!coveragePoints["Control_unit_89"]){
                    coveragePoints["Control_unit_89"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(MT_X);
                }
              }
            }
          }
        }
      } else {
        if(!coveragePoints["Control_unit_90"]){
          coveragePoints["Control_unit_90"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 35)) {
          if(!coveragePoints["Control_unit_91"]){
            coveragePoints["Control_unit_91"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 12) & 7) == 0)) {
            if(!coveragePoints["Control_unit_92"]){
              coveragePoints["Control_unit_92"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(MT_B);
          } else {
            if(!coveragePoints["Control_unit_93"]){
              coveragePoints["Control_unit_93"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 12) & 7) == 1)) {
              if(!coveragePoints["Control_unit_94"]){
                coveragePoints["Control_unit_94"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(MT_H);
            } else {
              if(!coveragePoints["Control_unit_95"]){
                coveragePoints["Control_unit_95"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((encodedInstr >> 12) & 7) == 2)) {
                if(!coveragePoints["Control_unit_96"]){
                  coveragePoints["Control_unit_96"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(MT_W);
              } else {
                if(!coveragePoints["Control_unit_97"]){
                  coveragePoints["Control_unit_97"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(MT_X);
              }
            }
          }
        } else {
          if(!coveragePoints["Control_unit_98"]){
            coveragePoints["Control_unit_98"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(MT_X);
        }
      }
    }

    ME_AccessType getDmemReq(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 3)) {
        if(!coveragePoints["Control_unit_99"]){
          coveragePoints["Control_unit_99"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(ME_RD);
      } else {
        if(!coveragePoints["Control_unit_100"]){
          coveragePoints["Control_unit_100"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 35)) {
          if(!coveragePoints["Control_unit_101"]){
            coveragePoints["Control_unit_101"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(ME_WR);
        } else {
          if(!coveragePoints["Control_unit_102"]){
            coveragePoints["Control_unit_102"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(ME_X);
        }
      }
    }

    EncType getEncType(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 51)) {
        if(!coveragePoints["Control_unit_103"]){
          coveragePoints["Control_unit_103"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(ENC_R);
      } else {
        if(!coveragePoints["Control_unit_104"]){
          coveragePoints["Control_unit_104"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 19)) {
          if(!coveragePoints["Control_unit_105"]){
            coveragePoints["Control_unit_105"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(ENC_I_I);
        } else {
          if(!coveragePoints["Control_unit_106"]){
            coveragePoints["Control_unit_106"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if (((encodedInstr & 127) == 3)) {
            if(!coveragePoints["Control_unit_107"]){
              coveragePoints["Control_unit_107"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(ENC_I_L);
          } else {
            if(!coveragePoints["Control_unit_108"]){
              coveragePoints["Control_unit_108"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((encodedInstr & 127) == 103)) {
              if(!coveragePoints["Control_unit_109"]){
                coveragePoints["Control_unit_109"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(ENC_I_J);
            } else {
              if(!coveragePoints["Control_unit_110"]){
                coveragePoints["Control_unit_110"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if (((encodedInstr & 127) == 35)) {
                if(!coveragePoints["Control_unit_111"]){
                  coveragePoints["Control_unit_111"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(ENC_S);
              } else {
                if(!coveragePoints["Control_unit_112"]){
                  coveragePoints["Control_unit_112"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (((encodedInstr & 127) == 99)) {
                  if(!coveragePoints["Control_unit_113"]){
                    coveragePoints["Control_unit_113"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(ENC_B);
                } else {
                  if(!coveragePoints["Control_unit_114"]){
                    coveragePoints["Control_unit_114"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr & 127) == 55) or ((encodedInstr & 127) == 23))) {
                    if(!coveragePoints["Control_unit_115"]){
                      coveragePoints["Control_unit_115"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(ENC_U);
                  } else {
                    if(!coveragePoints["Control_unit_116"]){
                      coveragePoints["Control_unit_116"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if (((encodedInstr & 127) == 111)) {
                      if(!coveragePoints["Control_unit_117"]){
                        coveragePoints["Control_unit_117"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(ENC_J);
                    } else {
                      if(!coveragePoints["Control_unit_118"]){
                        coveragePoints["Control_unit_118"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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

    unsigned getImmS2(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 103)) {
        if(!coveragePoints["Control_unit_119"]){
          coveragePoints["Control_unit_119"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((((encodedInstr >> 31) & 1) == 1)) {
          if(!coveragePoints["Control_unit_120"]){
            coveragePoints["Control_unit_120"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return((static_cast<unsigned>(-4096) | (encodedInstr >> 20)));
        } else {
          if(!coveragePoints["Control_unit_121"]){
            coveragePoints["Control_unit_121"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return((encodedInstr >> 20));
        }
      } else {
        if(!coveragePoints["Control_unit_122"]){
          coveragePoints["Control_unit_122"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 99)) {
          if(!coveragePoints["Control_unit_123"]){
            coveragePoints["Control_unit_123"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 31) & 1) == 1)) {
            if(!coveragePoints["Control_unit_124"]){
              coveragePoints["Control_unit_124"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return((static_cast<unsigned>(-4096) | ((((encodedInstr << 4) & 2048) | ((encodedInstr >> 20) & 2016)) | ((encodedInstr >> 7) & 30))));
          } else {
            if(!coveragePoints["Control_unit_125"]){
              coveragePoints["Control_unit_125"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(((((encodedInstr << 4) & 2048) | ((encodedInstr >> 20) & 2016)) | ((encodedInstr >> 7) & 30)));
          }
        } else {
          if(!coveragePoints["Control_unit_126"]){
            coveragePoints["Control_unit_126"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if (((encodedInstr & 127) == 111)) {
            if(!coveragePoints["Control_unit_127"]){
              coveragePoints["Control_unit_127"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 31) & 1) == 1)) {
              if(!coveragePoints["Control_unit_128"]){
                coveragePoints["Control_unit_128"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return((static_cast<unsigned>(-1048576) | (((encodedInstr & 1044480) | ((encodedInstr >> 9) & 2048)) | ((encodedInstr >> 20) & 2046))));
            } else {
              if(!coveragePoints["Control_unit_129"]){
                coveragePoints["Control_unit_129"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return((((encodedInstr & 1044480) | ((encodedInstr >> 9) & 2048)) | ((encodedInstr >> 20) & 2046)));
            }
          } else {
            if(!coveragePoints["Control_unit_130"]){
              coveragePoints["Control_unit_130"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(0);
          }
        }
      }
    }

    unsigned getImmS5(unsigned encodedInstr) {
      if ((((encodedInstr & 127) == 19) or ((encodedInstr & 127) == 3))) {
        if(!coveragePoints["Control_unit_131"]){
          coveragePoints["Control_unit_131"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((((encodedInstr >> 31) & 1) == 1)) {
          if(!coveragePoints["Control_unit_132"]){
            coveragePoints["Control_unit_132"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return((static_cast<unsigned>(-4096) | (encodedInstr >> 20)));
        } else {
          if(!coveragePoints["Control_unit_133"]){
            coveragePoints["Control_unit_133"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return((encodedInstr >> 20));
        }
      } else {
        if(!coveragePoints["Control_unit_134"]){
          coveragePoints["Control_unit_134"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 35)) {
          if(!coveragePoints["Control_unit_135"]){
            coveragePoints["Control_unit_135"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 31) & 1) == 1)) {
            if(!coveragePoints["Control_unit_136"]){
              coveragePoints["Control_unit_136"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return((static_cast<unsigned>(-4096) | (((encodedInstr >> 20) & 4064) | ((encodedInstr >> 7) & 31))));
          } else {
            if(!coveragePoints["Control_unit_137"]){
              coveragePoints["Control_unit_137"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return((((encodedInstr >> 20) & 4064) | ((encodedInstr >> 7) & 31)));
          }
        } else {
          if(!coveragePoints["Control_unit_138"]){
            coveragePoints["Control_unit_138"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr & 127) == 55) or ((encodedInstr & 127) == 23))) {
            if(!coveragePoints["Control_unit_139"]){
              coveragePoints["Control_unit_139"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return((encodedInstr & static_cast<unsigned>(-4096)));
          } else {
            if(!coveragePoints["Control_unit_140"]){
              coveragePoints["Control_unit_140"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(0);
          }
        }
      }
    }

    InstrType getInstrType(unsigned encodedInstr) {
      if (((encodedInstr & 127) == 51)) {
        if(!coveragePoints["Control_unit_141"]){
          coveragePoints["Control_unit_141"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((((encodedInstr >> 12) & 7) == 0)) {
          if(!coveragePoints["Control_unit_142"]){
            coveragePoints["Control_unit_142"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 25) & 127) == 0)) {
            if(!coveragePoints["Control_unit_143"]){
              coveragePoints["Control_unit_143"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(INSTR_ADD);
          } else {
            if(!coveragePoints["Control_unit_144"]){
              coveragePoints["Control_unit_144"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 25) & 127) == 32)) {
              if(!coveragePoints["Control_unit_145"]){
                coveragePoints["Control_unit_145"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(INSTR_SUB);
            } else {
              if(!coveragePoints["Control_unit_146"]){
                coveragePoints["Control_unit_146"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(INSTR_UNKNOWN);
            }
          }
        } else {
          if(!coveragePoints["Control_unit_147"]){
            coveragePoints["Control_unit_147"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 12) & 7) == 1)) {
            if(!coveragePoints["Control_unit_148"]){
              coveragePoints["Control_unit_148"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(INSTR_SLL);
          } else {
            if(!coveragePoints["Control_unit_149"]){
              coveragePoints["Control_unit_149"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 12) & 7) == 2)) {
              if(!coveragePoints["Control_unit_150"]){
                coveragePoints["Control_unit_150"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(INSTR_SLT);
            } else {
              if(!coveragePoints["Control_unit_151"]){
                coveragePoints["Control_unit_151"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((encodedInstr >> 12) & 7) == 3)) {
                if(!coveragePoints["Control_unit_152"]){
                  coveragePoints["Control_unit_152"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(INSTR_SLTU);
              } else {
                if(!coveragePoints["Control_unit_153"]){
                  coveragePoints["Control_unit_153"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((((encodedInstr >> 12) & 7) == 4)) {
                  if(!coveragePoints["Control_unit_154"]){
                    coveragePoints["Control_unit_154"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(INSTR_XOR);
                } else {
                  if(!coveragePoints["Control_unit_155"]){
                    coveragePoints["Control_unit_155"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr >> 12) & 7) == 5)) {
                    if(!coveragePoints["Control_unit_156"]){
                      coveragePoints["Control_unit_156"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 25) & 127) == 0)) {
                      if(!coveragePoints["Control_unit_157"]){
                        coveragePoints["Control_unit_157"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_SRL);
                    } else {
                      if(!coveragePoints["Control_unit_158"]){
                        coveragePoints["Control_unit_158"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 25) & 127) == 32)) {
                        if(!coveragePoints["Control_unit_159"]){
                          coveragePoints["Control_unit_159"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(INSTR_SRA);
                      } else {
                        if(!coveragePoints["Control_unit_160"]){
                          coveragePoints["Control_unit_160"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(INSTR_UNKNOWN);
                      }
                    }
                  } else {
                    if(!coveragePoints["Control_unit_161"]){
                      coveragePoints["Control_unit_161"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 12) & 7) == 6)) {
                      if(!coveragePoints["Control_unit_162"]){
                        coveragePoints["Control_unit_162"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_OR);
                    } else {
                      if(!coveragePoints["Control_unit_163"]){
                        coveragePoints["Control_unit_163"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 12) & 7) == 7)) {
                        if(!coveragePoints["Control_unit_164"]){
                          coveragePoints["Control_unit_164"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(INSTR_AND);
                      } else {
                        if(!coveragePoints["Control_unit_165"]){
                          coveragePoints["Control_unit_165"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
        if(!coveragePoints["Control_unit_166"]){
          coveragePoints["Control_unit_166"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 19)) {
          if(!coveragePoints["Control_unit_167"]){
            coveragePoints["Control_unit_167"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr >> 12) & 7) == 0)) {
            if(!coveragePoints["Control_unit_168"]){
              coveragePoints["Control_unit_168"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(INSTR_ADDI);
          } else {
            if(!coveragePoints["Control_unit_169"]){
              coveragePoints["Control_unit_169"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 12) & 7) == 1)) {
              if(!coveragePoints["Control_unit_170"]){
                coveragePoints["Control_unit_170"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(INSTR_SLLI);
            } else {
              if(!coveragePoints["Control_unit_171"]){
                coveragePoints["Control_unit_171"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((encodedInstr >> 12) & 7) == 2)) {
                if(!coveragePoints["Control_unit_172"]){
                  coveragePoints["Control_unit_172"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(INSTR_SLTI);
              } else {
                if(!coveragePoints["Control_unit_173"]){
                  coveragePoints["Control_unit_173"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((((encodedInstr >> 12) & 7) == 3)) {
                  if(!coveragePoints["Control_unit_174"]){
                    coveragePoints["Control_unit_174"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(INSTR_SLTUI);
                } else {
                  if(!coveragePoints["Control_unit_175"]){
                    coveragePoints["Control_unit_175"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr >> 12) & 7) == 4)) {
                    if(!coveragePoints["Control_unit_176"]){
                      coveragePoints["Control_unit_176"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(INSTR_XORI);
                  } else {
                    if(!coveragePoints["Control_unit_177"]){
                      coveragePoints["Control_unit_177"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 12) & 7) == 5)) {
                      if(!coveragePoints["Control_unit_178"]){
                        coveragePoints["Control_unit_178"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 25) & 127) == 0)) {
                        if(!coveragePoints["Control_unit_179"]){
                          coveragePoints["Control_unit_179"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(INSTR_SRLI);
                      } else {
                        if(!coveragePoints["Control_unit_180"]){
                          coveragePoints["Control_unit_180"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((((encodedInstr >> 25) & 127) == 32)) {
                          if(!coveragePoints["Control_unit_181"]){
                            coveragePoints["Control_unit_181"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          return(INSTR_SRAI);
                        } else {
                          if(!coveragePoints["Control_unit_182"]){
                            coveragePoints["Control_unit_182"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          return(INSTR_UNKNOWN);
                        }
                      }
                    } else {
                      if(!coveragePoints["Control_unit_183"]){
                        coveragePoints["Control_unit_183"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 12) & 7) == 6)) {
                        if(!coveragePoints["Control_unit_184"]){
                          coveragePoints["Control_unit_184"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(INSTR_ORI);
                      } else {
                        if(!coveragePoints["Control_unit_185"]){
                          coveragePoints["Control_unit_185"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((((encodedInstr >> 12) & 7) == 7)) {
                          if(!coveragePoints["Control_unit_186"]){
                            coveragePoints["Control_unit_186"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          return(INSTR_ANDI);
                        } else {
                          if(!coveragePoints["Control_unit_187"]){
                            coveragePoints["Control_unit_187"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
          if(!coveragePoints["Control_unit_188"]){
            coveragePoints["Control_unit_188"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if (((encodedInstr & 127) == 3)) {
            if(!coveragePoints["Control_unit_189"]){
              coveragePoints["Control_unit_189"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((encodedInstr >> 12) & 7) == 0)) {
              if(!coveragePoints["Control_unit_190"]){
                coveragePoints["Control_unit_190"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(INSTR_LB);
            } else {
              if(!coveragePoints["Control_unit_191"]){
                coveragePoints["Control_unit_191"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((encodedInstr >> 12) & 7) == 1)) {
                if(!coveragePoints["Control_unit_192"]){
                  coveragePoints["Control_unit_192"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(INSTR_LH);
              } else {
                if(!coveragePoints["Control_unit_193"]){
                  coveragePoints["Control_unit_193"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((((encodedInstr >> 12) & 7) == 2)) {
                  if(!coveragePoints["Control_unit_194"]){
                    coveragePoints["Control_unit_194"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(INSTR_LW);
                } else {
                  if(!coveragePoints["Control_unit_195"]){
                    coveragePoints["Control_unit_195"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr >> 12) & 7) == 4)) {
                    if(!coveragePoints["Control_unit_196"]){
                      coveragePoints["Control_unit_196"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(INSTR_LBU);
                  } else {
                    if(!coveragePoints["Control_unit_197"]){
                      coveragePoints["Control_unit_197"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 12) & 7) == 5)) {
                      if(!coveragePoints["Control_unit_198"]){
                        coveragePoints["Control_unit_198"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_LHU);
                    } else {
                      if(!coveragePoints["Control_unit_199"]){
                        coveragePoints["Control_unit_199"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_UNKNOWN);
                    }
                  }
                }
              }
            }
          } else {
            if(!coveragePoints["Control_unit_200"]){
              coveragePoints["Control_unit_200"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((encodedInstr & 127) == 103)) {
              if(!coveragePoints["Control_unit_201"]){
                coveragePoints["Control_unit_201"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(INSTR_JALR);
            } else {
              if(!coveragePoints["Control_unit_202"]){
                coveragePoints["Control_unit_202"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if (((encodedInstr & 127) == 35)) {
                if(!coveragePoints["Control_unit_203"]){
                  coveragePoints["Control_unit_203"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((((encodedInstr >> 12) & 7) == 0)) {
                  if(!coveragePoints["Control_unit_204"]){
                    coveragePoints["Control_unit_204"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  return(INSTR_SB);
                } else {
                  if(!coveragePoints["Control_unit_205"]){
                    coveragePoints["Control_unit_205"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr >> 12) & 7) == 1)) {
                    if(!coveragePoints["Control_unit_206"]){
                      coveragePoints["Control_unit_206"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(INSTR_SH);
                  } else {
                    if(!coveragePoints["Control_unit_207"]){
                      coveragePoints["Control_unit_207"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 12) & 7) == 2)) {
                      if(!coveragePoints["Control_unit_208"]){
                        coveragePoints["Control_unit_208"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_SW);
                    } else {
                      if(!coveragePoints["Control_unit_209"]){
                        coveragePoints["Control_unit_209"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_UNKNOWN);
                    }
                  }
                }
              } else {
                if(!coveragePoints["Control_unit_210"]){
                  coveragePoints["Control_unit_210"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (((encodedInstr & 127) == 99)) {
                  if(!coveragePoints["Control_unit_211"]){
                    coveragePoints["Control_unit_211"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if ((((encodedInstr >> 12) & 7) == 0)) {
                    if(!coveragePoints["Control_unit_212"]){
                      coveragePoints["Control_unit_212"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(INSTR_BEQ);
                  } else {
                    if(!coveragePoints["Control_unit_213"]){
                      coveragePoints["Control_unit_213"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((((encodedInstr >> 12) & 7) == 1)) {
                      if(!coveragePoints["Control_unit_214"]){
                        coveragePoints["Control_unit_214"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_BNE);
                    } else {
                      if(!coveragePoints["Control_unit_215"]){
                        coveragePoints["Control_unit_215"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if ((((encodedInstr >> 12) & 7) == 4)) {
                        if(!coveragePoints["Control_unit_216"]){
                          coveragePoints["Control_unit_216"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(INSTR_BLT);
                      } else {
                        if(!coveragePoints["Control_unit_217"]){
                          coveragePoints["Control_unit_217"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((((encodedInstr >> 12) & 7) == 5)) {
                          if(!coveragePoints["Control_unit_218"]){
                            coveragePoints["Control_unit_218"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          return(INSTR_BGE);
                        } else {
                          if(!coveragePoints["Control_unit_219"]){
                            coveragePoints["Control_unit_219"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                          }
                          if ((((encodedInstr >> 12) & 7) == 6)) {
                            if(!coveragePoints["Control_unit_220"]){
                              coveragePoints["Control_unit_220"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            return(INSTR_BLTU);
                          } else {
                            if(!coveragePoints["Control_unit_221"]){
                              coveragePoints["Control_unit_221"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            if ((((encodedInstr >> 12) & 7) == 7)) {
                              if(!coveragePoints["Control_unit_222"]){
                                coveragePoints["Control_unit_222"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                              }
                              return(INSTR_BGEU);
                            } else {
                              if(!coveragePoints["Control_unit_223"]){
                                coveragePoints["Control_unit_223"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                              }
                              return(INSTR_UNKNOWN);
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                  if(!coveragePoints["Control_unit_224"]){
                    coveragePoints["Control_unit_224"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  if (((encodedInstr & 127) == 55)) {
                    if(!coveragePoints["Control_unit_225"]){
                      coveragePoints["Control_unit_225"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(INSTR_LUI);
                  } else {
                    if(!coveragePoints["Control_unit_226"]){
                      coveragePoints["Control_unit_226"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if (((encodedInstr & 127) == 23)) {
                      if(!coveragePoints["Control_unit_227"]){
                        coveragePoints["Control_unit_227"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      return(INSTR_AUIPC);
                    } else {
                      if(!coveragePoints["Control_unit_228"]){
                        coveragePoints["Control_unit_228"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                      }
                      if (((encodedInstr & 127) == 111)) {
                        if(!coveragePoints["Control_unit_229"]){
                          coveragePoints["Control_unit_229"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(INSTR_JAL);
                      } else {
                        if(!coveragePoints["Control_unit_230"]){
                          coveragePoints["Control_unit_230"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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

    unsigned getPC(bool branchTaken, unsigned imm, unsigned pcReg, PC_SelType pcSel, unsigned reg1Content) {
      if ((pcSel == PC_BR)) {
        if(!coveragePoints["Control_unit_231"]){
          coveragePoints["Control_unit_231"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (branchTaken) {
          if(!coveragePoints["Control_unit_232"]){
            coveragePoints["Control_unit_232"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(((pcReg - 8) + imm));
        } else {
          if(!coveragePoints["Control_unit_233"]){
            coveragePoints["Control_unit_233"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return((pcReg + 4));
        }
      } else {
        if(!coveragePoints["Control_unit_234"]){
          coveragePoints["Control_unit_234"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((pcSel == PC_J)) {
          if(!coveragePoints["Control_unit_235"]){
            coveragePoints["Control_unit_235"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(((pcReg - 4) + imm));
        } else {
          if(!coveragePoints["Control_unit_236"]){
            coveragePoints["Control_unit_236"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((pcSel == PC_JR)) {
            if(!coveragePoints["Control_unit_237"]){
              coveragePoints["Control_unit_237"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return((reg1Content + imm));
          } else {
            if(!coveragePoints["Control_unit_238"]){
              coveragePoints["Control_unit_238"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return((pcReg + 4));
          }
        }
      }
    }

    PC_SelType getPCsel(unsigned encodedInstr) {
      if ((((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 35)) or ((encodedInstr & 127) == 55)) or ((encodedInstr & 127) == 23))) {
        if(!coveragePoints["Control_unit_239"]){
          coveragePoints["Control_unit_239"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(PC_4);
      } else {
        if(!coveragePoints["Control_unit_240"]){
          coveragePoints["Control_unit_240"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 103)) {
          if(!coveragePoints["Control_unit_241"]){
            coveragePoints["Control_unit_241"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(PC_JR);
        } else {
          if(!coveragePoints["Control_unit_242"]){
            coveragePoints["Control_unit_242"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if (((encodedInstr & 127) == 99)) {
            if(!coveragePoints["Control_unit_243"]){
              coveragePoints["Control_unit_243"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(PC_BR);
          } else {
            if(!coveragePoints["Control_unit_244"]){
              coveragePoints["Control_unit_244"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((encodedInstr & 127) == 111)) {
              if(!coveragePoints["Control_unit_245"]){
                coveragePoints["Control_unit_245"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(PC_J);
            } else {
              if(!coveragePoints["Control_unit_246"]){
                coveragePoints["Control_unit_246"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              return(PC_4);
            }
          }
        }
      }
    }

    RF_RD_AccessType getRegFileReqS2(unsigned encodedInstr) {
      if ((((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 103)) or ((encodedInstr & 127) == 35)) or ((encodedInstr & 127) == 99))) {
        if(!coveragePoints["Control_unit_247"]){
          coveragePoints["Control_unit_247"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(RF_RD);
      } else {
        if(!coveragePoints["Control_unit_248"]){
          coveragePoints["Control_unit_248"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(RF_RD_X);
      }
    }

    RF_WR_AccessType getRegFileReqS5(unsigned encodedInstr) {
      if (((((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 103)) or ((encodedInstr & 127) == 55)) or ((encodedInstr & 127) == 23)) or ((encodedInstr & 127) == 111))) {
        if(!coveragePoints["Control_unit_249"]){
          coveragePoints["Control_unit_249"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(RF_WR);
      } else {
        if(!coveragePoints["Control_unit_250"]){
          coveragePoints["Control_unit_250"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(RF_WR_X);
      }
    }

    RF_WriteDataSelType getRegFileWriteDataSel(unsigned encodedInstr) {
      if ((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 55)) or ((encodedInstr & 127) == 23))) {
        if(!coveragePoints["Control_unit_251"]){
          coveragePoints["Control_unit_251"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(WB_ALU);
      } else {
        if(!coveragePoints["Control_unit_252"]){
          coveragePoints["Control_unit_252"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((encodedInstr & 127) == 3)) {
          if(!coveragePoints["Control_unit_253"]){
            coveragePoints["Control_unit_253"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(WB_MEM);
        } else {
          if(!coveragePoints["Control_unit_254"]){
            coveragePoints["Control_unit_254"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          if ((((encodedInstr & 127) == 103) or ((encodedInstr & 127) == 111))) {
            if(!coveragePoints["Control_unit_255"]){
              coveragePoints["Control_unit_255"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(WB_PC4);
          } else {
            if(!coveragePoints["Control_unit_256"]){
              coveragePoints["Control_unit_256"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(WB_X);
          }
        }
      }
    }

    unsigned getRegRdAddr(unsigned encodedInstr) {
      if (((((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 103)) or ((encodedInstr & 127) == 55)) or ((encodedInstr & 127) == 23)) or ((encodedInstr & 127) == 111))) {
        if(!coveragePoints["Control_unit_257"]){
          coveragePoints["Control_unit_257"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(((encodedInstr >> 7) & 31));
      } else {
        if(!coveragePoints["Control_unit_258"]){
          coveragePoints["Control_unit_258"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(0);
      }
    }

    unsigned getRegRs1Addr(unsigned encodedInstr) {
      if ((((((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 19)) or ((encodedInstr & 127) == 3)) or ((encodedInstr & 127) == 103)) or ((encodedInstr & 127) == 35)) or ((encodedInstr & 127) == 99))) {
        if(!coveragePoints["Control_unit_259"]){
          coveragePoints["Control_unit_259"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(((encodedInstr >> 15) & 31));
      } else {
        if(!coveragePoints["Control_unit_260"]){
          coveragePoints["Control_unit_260"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(0);
      }
    }

    unsigned getRegRs2Addr(unsigned encodedInstr) {
      if (((((encodedInstr & 127) == 51) or ((encodedInstr & 127) == 35)) or ((encodedInstr & 127) == 99))) {
        if(!coveragePoints["Control_unit_261"]){
          coveragePoints["Control_unit_261"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(((encodedInstr >> 20) & 31));
      } else {
        if(!coveragePoints["Control_unit_262"]){
          coveragePoints["Control_unit_262"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(0);
      }
    }

    bool getStallOnce(EncType currEncType, EncType prevEncType, unsigned regRdAddr, unsigned regRs1Addr, unsigned regRs2Addr) {
      if (((((currEncType == ENC_B) and (((prevEncType == ENC_R) or (prevEncType == ENC_I_I)) or (prevEncType == ENC_U))) or ((currEncType == ENC_R) and (prevEncType == ENC_I_L))) and ((regRs1Addr == regRdAddr) or (regRs2Addr == regRdAddr)))) {
        if(!coveragePoints["Control_unit_263"]){
          coveragePoints["Control_unit_263"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(true);
      } else {
        if(!coveragePoints["Control_unit_264"]){
          coveragePoints["Control_unit_264"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if (((((((currEncType == ENC_I_I) or (currEncType == ENC_I_L)) or (currEncType == ENC_S)) and (prevEncType == ENC_I_L)) or ((currEncType == ENC_I_J) and (((prevEncType == ENC_R) or (prevEncType == ENC_I_I)) or (prevEncType == ENC_U)))) and (regRs1Addr == regRdAddr))) {
          if(!coveragePoints["Control_unit_265"]){
            coveragePoints["Control_unit_265"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(true);
        } else {
          if(!coveragePoints["Control_unit_266"]){
            coveragePoints["Control_unit_266"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(false);
        }
      }
    }

    bool getStallTwice(EncType currEncType, EncType prevEncType, unsigned regRdAddr, unsigned regRs1Addr, unsigned regRs2Addr) {
      if ((((currEncType == ENC_B) and (prevEncType == ENC_I_L)) and ((regRs1Addr == regRdAddr) or (regRs2Addr == regRdAddr)))) {
        if(!coveragePoints["Control_unit_267"]){
          coveragePoints["Control_unit_267"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        return(true);
      } else {
        if(!coveragePoints["Control_unit_268"]){
          coveragePoints["Control_unit_268"] = true;
          coveragePointsCount++;
          std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
        }
        if ((((currEncType == ENC_I_J) and (prevEncType == ENC_I_L)) and (regRs1Addr == regRdAddr))) {
          if(!coveragePoints["Control_unit_269"]){
            coveragePoints["Control_unit_269"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(true);
        } else {
          if(!coveragePoints["Control_unit_270"]){
            coveragePoints["Control_unit_270"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
          }
          return(false);
        }
      }
    }


    CUtoDP_S3 CUtoDP_3_s2;
    CUtoDP_S3 CUtoDP_3_s3;
    CUtoDP_S4 CUtoDP_4_s2;
    CUtoDP_S4 CUtoDP_4_s3;
    CUtoDP_S4 CUtoDP_4_s4;
    CUtoDP_S5 CUtoDP_5_s2;
    CUtoDP_S5 CUtoDP_5_s3;
    CUtoDP_S5 CUtoDP_5_s4;
    CUtoDP_S5 CUtoDP_5_s5;
    CUtoDP_IF CUtoDP_data;
    CUtoME_IF CUtoME_data;
    DEtoCU_IF DEtoCU_data;
    DPtoCU_IF DPtoCU_data;
    MEtoCU_IF MEtoCU_data;
    bool currBranchTaken;
    unsigned currPCimm;
    PC_SelType currPCsel;
    unsigned currReg1Content;
    bool dmemAccess;
    EncType encType_prev2;
    EncType encType_prev3;
    unsigned encodedInstr;
    bool flush;
    bool flushDmemAccess;
    bool flushDmemAccessTemp;
    unsigned loadedInstr;
    unsigned pc;
    bool prevDmemAccess;
    InstrType prevInstrType;
    bool prevJalrInstr;
    unsigned prevPCimm;
    PC_SelType prevPCsel;
    unsigned prevReg1Content;
    unsigned regRdAddr_prev2;
    unsigned regRdAddr_prev3;
    bool stall;
    bool stallOnce;
    bool stallTwice;


    void FSM(){
        while(true) {
          if (section==decodeInstr) {
            if(!coveragePoints["Control_unit_271"]){
              coveragePoints["Control_unit_271"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (not(stall)) {
              if(!coveragePoints["Control_unit_272"]){
                coveragePoints["Control_unit_272"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              encodedInstr = loadedInstr;
              loadedInstr = MEtoCU_data.loadedData;
            }
            DEtoCU_data.pcSel_s2 = getPCsel(encodedInstr);
            DEtoCU_data.imm_s2 = getImmS2(encodedInstr);
            DEtoCU_data.encType_s2 = getEncType(encodedInstr);
            DEtoCU_data.instrType_s2 = getInstrType(encodedInstr);
            DEtoCU_data.regFileReq_s2 = getRegFileReqS2(encodedInstr);
            DEtoCU_data.regRs1Addr_s2 = getRegRs1Addr(encodedInstr);
            DEtoCU_data.regRs2Addr_s2 = getRegRs2Addr(encodedInstr);
            DEtoCU_data.regRdAddr_s2 = getRegRdAddr(encodedInstr);
            DEtoCU_data.aluFunc_s3 = getALUfunc(encodedInstr);
            DEtoCU_data.aluOp1Sel_s3 = getALUop1Sel(encodedInstr);
            DEtoCU_data.aluOp2Sel_s3 = getALUop2Sel(encodedInstr);
            DEtoCU_data.imm_s3 = getImmS5(encodedInstr);
            DEtoCU_data.dmemReq_s4 = getDmemReq(encodedInstr);
            DEtoCU_data.dmemMask_s4 = getDmemMask(encodedInstr);
            DEtoCU_data.regFileReq_s5 = getRegFileReqS5(encodedInstr);
            DEtoCU_data.regFileWriteDataSel_s5 = getRegFileWriteDataSel(encodedInstr);
            section = setStallSignals;
          }
          else if (section==memAccess) {
            if(!coveragePoints["Control_unit_273"]){
              coveragePoints["Control_unit_273"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (dmemAccess) {
              if(!coveragePoints["Control_unit_274"]){
                coveragePoints["Control_unit_274"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoME_data.req = DPtoCU_data.req;
              CUtoME_data.mask = DPtoCU_data.mask;
              CUtoME_data.addrIn = DPtoCU_data.addrIn;
              CUtoME_data.dataIn = DPtoCU_data.dataIn;
            } else {
              if(!coveragePoints["Control_unit_275"]){
                coveragePoints["Control_unit_275"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoME_data.req = ME_RD;
              CUtoME_data.mask = MT_W;
              CUtoME_data.addrIn = pc;
              CUtoME_data.dataIn = 0;
            }
            CUtoME_port->write(CUtoME_data);
            MEtoCU_port->read(MEtoCU_data);
            if (dmemAccess) {
              if(!coveragePoints["Control_unit_276"]){
                coveragePoints["Control_unit_276"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_data.loadedData = MEtoCU_data.loadedData;
            } else {
              if(!coveragePoints["Control_unit_277"]){
                coveragePoints["Control_unit_277"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_data.loadedData = 0;
            }
            section = decodeInstr;
          }
          else if (section==setDataPathSignals) {
            if(!coveragePoints["Control_unit_278"]){
              coveragePoints["Control_unit_278"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (dmemAccess) {
              if(!coveragePoints["Control_unit_279"]){
                coveragePoints["Control_unit_279"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_data.prevDmemAccess = true;
              prevDmemAccess = true;
            } else {
              if(!coveragePoints["Control_unit_280"]){
                coveragePoints["Control_unit_280"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_data.prevDmemAccess = false;
              prevDmemAccess = false;
            }
            encType_prev3 = encType_prev2;
            regRdAddr_prev3 = regRdAddr_prev2;
            encType_prev2 = CUtoDP_data.encType_s2;
            regRdAddr_prev2 = CUtoDP_data.regRdAddr_s2;
            if (flushDmemAccess) {
              if(!coveragePoints["Control_unit_281"]){
                coveragePoints["Control_unit_281"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              flushDmemAccessTemp = true;
            } else {
              if(!coveragePoints["Control_unit_282"]){
                coveragePoints["Control_unit_282"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              flushDmemAccessTemp = false;
            }
            if ((((CUtoDP_data.encType_s2 == ENC_J) and CUtoDP_data.stallDmemAccess) or (flush and (CUtoDP_data.stallDmemAccess or dmemAccess)))) {
              if(!coveragePoints["Control_unit_283"]){
                coveragePoints["Control_unit_283"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              flushDmemAccess = true;
            } else {
              if(!coveragePoints["Control_unit_284"]){
                coveragePoints["Control_unit_284"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              flushDmemAccess = false;
            }
            if ((((((((currBranchTaken or flushDmemAccessTemp) or flush) or CUtoDP_data.stallDmemAccess) or stallOnce) or stallTwice) or (CUtoDP_data.encType_s2 == ENC_J)) or (CUtoDP_data.encType_s2 == ENC_I_J))) {
              if(!coveragePoints["Control_unit_285"]){
                coveragePoints["Control_unit_285"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              currPCsel = PC_4;
              currPCimm = 0;
              CUtoDP_data.encType_s2 = ENC_I_I;
              prevInstrType = INSTR_ADDI;
              CUtoDP_data.regFileReq_s2 = RF_RD_X;
              CUtoDP_data.regRs1Addr_s2 = 0;
              CUtoDP_data.regRs2Addr_s2 = 0;
              CUtoDP_data.regRdAddr_s2 = 0;
              CUtoDP_3_s2.aluFunc_s3 = ALU_X;
              CUtoDP_3_s2.aluOp1Sel_s3 = OP_X;
              CUtoDP_3_s2.aluOp2Sel_s3 = OP_X;
              CUtoDP_3_s2.imm_s3 = 0;
              CUtoDP_4_s2.dmemReq_s4 = ME_X;
              CUtoDP_4_s2.dmemMask_s4 = MT_X;
              CUtoDP_5_s2.regFileReq_s5 = RF_WR_X;
              CUtoDP_5_s2.regFileWriteDataSel_s5 = WB_X;
            } else {
              if(!coveragePoints["Control_unit_286"]){
                coveragePoints["Control_unit_286"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              currPCsel = DEtoCU_data.pcSel_s2;
              currPCimm = DEtoCU_data.imm_s2;
              CUtoDP_data.encType_s2 = DEtoCU_data.encType_s2;
              prevInstrType = DEtoCU_data.instrType_s2;
              CUtoDP_data.regFileReq_s2 = DEtoCU_data.regFileReq_s2;
              CUtoDP_data.regRs1Addr_s2 = DEtoCU_data.regRs1Addr_s2;
              CUtoDP_data.regRs2Addr_s2 = DEtoCU_data.regRs2Addr_s2;
              CUtoDP_data.regRdAddr_s2 = DEtoCU_data.regRdAddr_s2;
              CUtoDP_3_s2.aluFunc_s3 = DEtoCU_data.aluFunc_s3;
              CUtoDP_3_s2.aluOp1Sel_s3 = DEtoCU_data.aluOp1Sel_s3;
              CUtoDP_3_s2.aluOp2Sel_s3 = DEtoCU_data.aluOp2Sel_s3;
              CUtoDP_3_s2.imm_s3 = DEtoCU_data.imm_s3;
              CUtoDP_4_s2.dmemReq_s4 = DEtoCU_data.dmemReq_s4;
              CUtoDP_4_s2.dmemMask_s4 = DEtoCU_data.dmemMask_s4;
              CUtoDP_5_s2.regFileReq_s5 = DEtoCU_data.regFileReq_s5;
              CUtoDP_5_s2.regFileWriteDataSel_s5 = DEtoCU_data.regFileWriteDataSel_s5;
            }
            CUtoDP_data.aluFunc_s3 = CUtoDP_3_s3.aluFunc_s3;
            CUtoDP_data.aluOp1Sel_s3 = CUtoDP_3_s3.aluOp1Sel_s3;
            CUtoDP_data.aluOp2Sel_s3 = CUtoDP_3_s3.aluOp2Sel_s3;
            CUtoDP_data.imm_s3 = CUtoDP_3_s3.imm_s3;
            CUtoDP_data.dmemReq_s4 = CUtoDP_4_s4.dmemReq_s4;
            CUtoDP_data.dmemMask_s4 = CUtoDP_4_s4.dmemMask_s4;
            CUtoDP_data.regFileReq_s5 = CUtoDP_5_s5.regFileReq_s5;
            CUtoDP_data.regFileWriteDataSel_s5 = CUtoDP_5_s5.regFileWriteDataSel_s5;
            CUtoDP_port->write(CUtoDP_data);
            section = updatePC;
          }
          else if (section==setDmemAccess) {
            if(!coveragePoints["Control_unit_287"]){
              coveragePoints["Control_unit_287"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (CUtoDP_data.stallDmemAccess) {
              if(!coveragePoints["Control_unit_288"]){
                coveragePoints["Control_unit_288"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              dmemAccess = true;
            } else {
              if(!coveragePoints["Control_unit_289"]){
                coveragePoints["Control_unit_289"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              dmemAccess = false;
            }
            if ((((CUtoDP_data.dmemReq_s4 == ME_RD) or (CUtoDP_data.dmemReq_s4 == ME_WR)) and not(dmemAccess))) {
              if(!coveragePoints["Control_unit_290"]){
                coveragePoints["Control_unit_290"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_data.stallDmemAccess = true;
            } else {
              if(!coveragePoints["Control_unit_291"]){
                coveragePoints["Control_unit_291"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_data.stallDmemAccess = false;
            }
            if ((dmemAccess and stallTwice)) {
              if(!coveragePoints["Control_unit_292"]){
                coveragePoints["Control_unit_292"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              stallTwice = true;
              stallOnce = false;
            } else {
              if(!coveragePoints["Control_unit_293"]){
                coveragePoints["Control_unit_293"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((dmemAccess and stallOnce)) {
                if(!coveragePoints["Control_unit_294"]){
                  coveragePoints["Control_unit_294"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                stallOnce = true;
                stallTwice = false;
              } else {
                if(!coveragePoints["Control_unit_295"]){
                  coveragePoints["Control_unit_295"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (stallTwice) {
                  if(!coveragePoints["Control_unit_296"]){
                    coveragePoints["Control_unit_296"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  stallOnce = true;
                  stallTwice = false;
                } else {
                  if(!coveragePoints["Control_unit_297"]){
                    coveragePoints["Control_unit_297"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  stallOnce = false;
                  stallTwice = false;
                }
              }
            }
            section = memAccess;
          }
          else if (section==setPipelineSignals) {
            if(!coveragePoints["Control_unit_298"]){
              coveragePoints["Control_unit_298"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (not(CUtoDP_data.stallDmemAccess)) {
              if(!coveragePoints["Control_unit_299"]){
                coveragePoints["Control_unit_299"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_5_s5.regFileReq_s5 = CUtoDP_5_s4.regFileReq_s5;
              CUtoDP_5_s5.regFileWriteDataSel_s5 = CUtoDP_5_s4.regFileWriteDataSel_s5;
              CUtoDP_4_s4.dmemReq_s4 = CUtoDP_4_s3.dmemReq_s4;
              CUtoDP_4_s4.dmemMask_s4 = CUtoDP_4_s3.dmemMask_s4;
              CUtoDP_5_s4.regFileReq_s5 = CUtoDP_5_s3.regFileReq_s5;
              CUtoDP_5_s4.regFileWriteDataSel_s5 = CUtoDP_5_s3.regFileWriteDataSel_s5;
              CUtoDP_3_s3.aluFunc_s3 = CUtoDP_3_s2.aluFunc_s3;
              CUtoDP_3_s3.aluOp1Sel_s3 = CUtoDP_3_s2.aluOp1Sel_s3;
              CUtoDP_3_s3.aluOp2Sel_s3 = CUtoDP_3_s2.aluOp2Sel_s3;
              CUtoDP_3_s3.imm_s3 = CUtoDP_3_s2.imm_s3;
              CUtoDP_4_s3.dmemReq_s4 = CUtoDP_4_s2.dmemReq_s4;
              CUtoDP_4_s3.dmemMask_s4 = CUtoDP_4_s2.dmemMask_s4;
              CUtoDP_5_s3.regFileReq_s5 = CUtoDP_5_s2.regFileReq_s5;
              CUtoDP_5_s3.regFileWriteDataSel_s5 = CUtoDP_5_s2.regFileWriteDataSel_s5;
            }
            section = setDmemAccess;
          }
          else if (section==setStallSignals) {
            if(!coveragePoints["Control_unit_300"]){
              coveragePoints["Control_unit_300"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            DPtoCU_port->read(DPtoCU_data);
            if ((flush and dmemAccess)) {
              if(!coveragePoints["Control_unit_301"]){
                coveragePoints["Control_unit_301"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              currReg1Content = prevReg1Content;
              currBranchTaken = true;
            } else {
              if(!coveragePoints["Control_unit_302"]){
                coveragePoints["Control_unit_302"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              currReg1Content = DPtoCU_data.reg1Content;
              currBranchTaken = getBranchEvaluation(prevInstrType,DPtoCU_data.reg1Content,DPtoCU_data.reg2Content);
            }
            if ((not(stall) and (CUtoDP_data.regRdAddr_s2 != 0))) {
              if(!coveragePoints["Control_unit_303"]){
                coveragePoints["Control_unit_303"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              stallOnce = getStallOnce(DEtoCU_data.encType_s2,CUtoDP_data.encType_s2,CUtoDP_data.regRdAddr_s2,DEtoCU_data.regRs1Addr_s2,DEtoCU_data.regRs2Addr_s2);
              stallTwice = getStallTwice(DEtoCU_data.encType_s2,CUtoDP_data.encType_s2,CUtoDP_data.regRdAddr_s2,DEtoCU_data.regRs1Addr_s2,DEtoCU_data.regRs2Addr_s2);
            }
            if (((((not(stallOnce) and not(stallTwice)) and (CUtoDP_data.encType_s2 != ENC_J)) and (CUtoDP_data.encType_s2 != ENC_I_J)) and not(currBranchTaken))) {
              if(!coveragePoints["Control_unit_304"]){
                coveragePoints["Control_unit_304"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              if ((((((DEtoCU_data.encType_s2 == ENC_I_J) and (encType_prev2 == ENC_I_L)) and (DEtoCU_data.regRs1Addr_s2 == regRdAddr_prev2)) and (regRdAddr_prev2 != 0)) or ((((DEtoCU_data.encType_s2 == ENC_B) and (encType_prev2 == ENC_I_L)) and ((DEtoCU_data.regRs1Addr_s2 == regRdAddr_prev2) or (DEtoCU_data.regRs2Addr_s2 == regRdAddr_prev2))) and (regRdAddr_prev2 != 0)))) {
                if(!coveragePoints["Control_unit_305"]){
                  coveragePoints["Control_unit_305"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                stallOnce = true;
              } else {
                if(!coveragePoints["Control_unit_306"]){
                  coveragePoints["Control_unit_306"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((prevDmemAccess and (((((DEtoCU_data.encType_s2 == ENC_I_J) and (encType_prev3 == ENC_I_L)) and (DEtoCU_data.regRs1Addr_s2 == regRdAddr_prev3)) and (regRdAddr_prev3 != 0)) or ((((DEtoCU_data.encType_s2 == ENC_B) and (encType_prev3 == ENC_I_L)) and ((DEtoCU_data.regRs1Addr_s2 == regRdAddr_prev3) or (DEtoCU_data.regRs2Addr_s2 == regRdAddr_prev3))) and (regRdAddr_prev3 != 0))))) {
                  if(!coveragePoints["Control_unit_307"]){
                    coveragePoints["Control_unit_307"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  stallOnce = true;
                } else {
                  if(!coveragePoints["Control_unit_308"]){
                    coveragePoints["Control_unit_308"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                  }
                  stallOnce = false;
                }
              }
            }
            section = setDataPathSignals;
          }
          else if (section==updatePC) {
            if(!coveragePoints["Control_unit_309"]){
              coveragePoints["Control_unit_309"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((CUtoDP_data.stallDmemAccess or stallOnce) or stallTwice)) {
              if(!coveragePoints["Control_unit_310"]){
                coveragePoints["Control_unit_310"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              stall = true;
            } else {
              if(!coveragePoints["Control_unit_311"]){
                coveragePoints["Control_unit_311"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              stall = false;
            }
            if ((prevJalrInstr or currBranchTaken)) {
              if(!coveragePoints["Control_unit_312"]){
                coveragePoints["Control_unit_312"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              flush = true;
              prevReg1Content = DPtoCU_data.reg1Content;
              currPCsel = prevPCsel;
              currPCimm = prevPCimm;
            } else {
              if(!coveragePoints["Control_unit_313"]){
                coveragePoints["Control_unit_313"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              flush = false;
              prevReg1Content = 0;
            }
            if (((CUtoDP_data.encType_s2 == ENC_I_J) or (CUtoDP_data.encType_s2 == ENC_B))) {
              if(!coveragePoints["Control_unit_314"]){
                coveragePoints["Control_unit_314"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              prevPCsel = DEtoCU_data.pcSel_s2;
              prevPCimm = DEtoCU_data.imm_s2;
              currPCsel = PC_4;
              currPCimm = 0;
              if ((CUtoDP_data.encType_s2 == ENC_I_J)) {
                if(!coveragePoints["Control_unit_315"]){
                  coveragePoints["Control_unit_315"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                prevJalrInstr = true;
              } else {
                if(!coveragePoints["Control_unit_316"]){
                  coveragePoints["Control_unit_316"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                prevJalrInstr = false;
              }
            } else {
              if(!coveragePoints["Control_unit_317"]){
                coveragePoints["Control_unit_317"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              prevJalrInstr = false;
            }
            if (not(stall)) {
              if(!coveragePoints["Control_unit_318"]){
                coveragePoints["Control_unit_318"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Control_unit " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
              }
              CUtoDP_data.pc_s2 = pc;
              pc = getPC(currBranchTaken,currPCimm,CUtoDP_data.pc_s2,currPCsel,currReg1Content);
            }
            section = setPipelineSignals;
          }
          
        }//end of while
    }//end of FSM
    int coveragePointsTotal = 318;
    int coveragePointsCount = 0;
    std::map<std::string, bool> coveragePoints;

    SC_HAS_PROCESS(Control_unit);

    Control_unit(sc_module_name name) :
      section(memAccess),
      currBranchTaken(false),
      currPCimm(0),
      currPCsel(PC_4),
      currReg1Content(0),
      dmemAccess(false),
      encType_prev2(ENC_B),
      encType_prev3(ENC_B),
      encodedInstr(0),
      flush(false),
      flushDmemAccess(false),
      flushDmemAccessTemp(false),
      loadedInstr(19),
      pc(0),
      prevDmemAccess(false),
      prevInstrType(INSTR_ADD),
      prevJalrInstr(false),
      prevPCimm(0),
      prevPCsel(PC_4),
      prevReg1Content(0),
      regRdAddr_prev2(0),
      regRdAddr_prev3(0),
      stall(false),
      stallOnce(false),
      stallTwice(false)    {
            SC_THREAD(FSM);
      for(int i = 1; i < coveragePointsTotal; i++)
            coveragePoints.insert(std::make_pair("Control_unit_"+to_string(i),false));
      }
    };//end of module


#endif //SYSTEMC_Control_unit_H
