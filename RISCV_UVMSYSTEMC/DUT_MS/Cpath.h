#ifndef SYSTEMC_Cpath_H
#define SYSTEMC_Cpath_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

    struct Cpath : public sc_module {

      enum Sections {calculateNextPC, decode, executeALU, fetch, memoryOperation, readRegisterFile, setControl, writeBack};
      Sections section;

      master_in<ALUtoCtl_IF> ALUtoCtl_port;
      master_out<CtlToALU_IF> CtlToALU_port;
      master_out<unsigned> CtlToDec_port;
      blocking_out<CUtoME_IF> CtlToMem_port;
      master_out<CtlToRegs_IF> CtlToRegs_port;
      master_in<DecodedInstr> DecToCtl_port;
      blocking_in<MEtoCU_IF> MemToCtl_port;
      master_in<RegsToCtl_IF> RegsToCtl_port;

      //functions

      ALUtoCtl_IF ALUtoCtl_data;
      CtlToALU_IF CtlToALU_data;
      CtlToRegs_IF CtlToRegs_data;
      RegsToCtl_IF RegsToCtl_data;
      bool br_en;
      DecodedInstr decodedInstr;
      MEtoCU_IF encodedInstr;
      MEtoCU_IF fromMemoryData;
      bool mem_en;
      CUtoME_IF memoryAccess;
      unsigned pc_next;
      unsigned pc_reg;
      PCselType pc_sel;
      bool reg_rd_en;
      bool var;
      unsigned wb_data;
      bool wb_en;
      WBselType wb_sel;


      void FSM(){
          while(true) {
            if (section==calculateNextPC) {
              if(!coveragePoints["Cpath_1"]){
                coveragePoints["Cpath_1"] = true;
                coveragePointsCount++;
              }
              pc_sel = PC_4;
              if (br_en) {
                if(!coveragePoints["Cpath_2"]){
                  coveragePoints["Cpath_2"] = true;
                  coveragePointsCount++;
                }
                if (((decodedInstr.instrType == beq) and (ALUtoCtl_data.ALU_result == 0))) {
                  if(!coveragePoints["Cpath_3"]){
                    coveragePoints["Cpath_3"] = true;
                    coveragePointsCount++;
                  }
                  pc_sel = PC_BR;
                } else {
                  if(!coveragePoints["Cpath_4"]){
                    coveragePoints["Cpath_4"] = true;
                    coveragePointsCount++;
                  }
                  if (((decodedInstr.instrType == bne) and (ALUtoCtl_data.ALU_result != 0))) {
                    if(!coveragePoints["Cpath_5"]){
                      coveragePoints["Cpath_5"] = true;
                      coveragePointsCount++;
                    }
                    pc_sel = PC_BR;
                  } else {
                    if(!coveragePoints["Cpath_6"]){
                      coveragePoints["Cpath_6"] = true;
                      coveragePointsCount++;
                    }
                    if (((decodedInstr.instrType == blt) and (ALUtoCtl_data.ALU_result == 1))) {
                      if(!coveragePoints["Cpath_7"]){
                        coveragePoints["Cpath_7"] = true;
                        coveragePointsCount++;
                      }
                      pc_sel = PC_BR;
                    } else {
                      if(!coveragePoints["Cpath_8"]){
                        coveragePoints["Cpath_8"] = true;
                        coveragePointsCount++;
                      }
                      if (((decodedInstr.instrType == bge) and (ALUtoCtl_data.ALU_result == 0))) {
                        if(!coveragePoints["Cpath_9"]){
                          coveragePoints["Cpath_9"] = true;
                          coveragePointsCount++;
                        }
                        pc_sel = PC_BR;
                      } else {
                        if(!coveragePoints["Cpath_10"]){
                          coveragePoints["Cpath_10"] = true;
                          coveragePointsCount++;
                        }
                        if (((decodedInstr.instrType == bltu) and (ALUtoCtl_data.ALU_result == 1))) {
                          if(!coveragePoints["Cpath_11"]){
                            coveragePoints["Cpath_11"] = true;
                            coveragePointsCount++;
                          }
                          pc_sel = PC_BR;
                        } else {
                          if(!coveragePoints["Cpath_12"]){
                            coveragePoints["Cpath_12"] = true;
                            coveragePointsCount++;
                          }
                          if (((decodedInstr.instrType == bgeu) and (ALUtoCtl_data.ALU_result == 0))) {
                            if(!coveragePoints["Cpath_13"]){
                              coveragePoints["Cpath_13"] = true;
                              coveragePointsCount++;
                            }
                            pc_sel = PC_BR;
                          }
                        }
                      }
                    }
                  }
                }
              }
              if ((decodedInstr.instrType == jal)) {
                if(!coveragePoints["Cpath_14"]){
                  coveragePoints["Cpath_14"] = true;
                  coveragePointsCount++;
                }
                pc_sel = PC_J;
              } else {
                if(!coveragePoints["Cpath_15"]){
                  coveragePoints["Cpath_15"] = true;
                  coveragePointsCount++;
                }
                if ((decodedInstr.instrType == jalr)) {
                  if(!coveragePoints["Cpath_16"]){
                    coveragePoints["Cpath_16"] = true;
                    coveragePointsCount++;
                  }
                  pc_sel = PC_JR;
                }
              }
              if ((pc_sel == PC_4)) {
                if(!coveragePoints["Cpath_17"]){
                  coveragePoints["Cpath_17"] = true;
                  coveragePointsCount++;
                }
                pc_next = (pc_reg + 4);
              } else {
                if(!coveragePoints["Cpath_18"]){
                  coveragePoints["Cpath_18"] = true;
                  coveragePointsCount++;
                }
                if ((pc_sel == PC_BR)) {
                  if(!coveragePoints["Cpath_19"]){
                    coveragePoints["Cpath_19"] = true;
                    coveragePointsCount++;
                  }
                  pc_next = (pc_reg + decodedInstr.imm);
                } else {
                  if(!coveragePoints["Cpath_20"]){
                    coveragePoints["Cpath_20"] = true;
                    coveragePointsCount++;
                  }
                  if ((pc_sel == PC_J)) {
                    if(!coveragePoints["Cpath_21"]){
                      coveragePoints["Cpath_21"] = true;
                      coveragePointsCount++;
                    }
                    pc_next = (pc_reg + decodedInstr.imm);
                  } else {
                    if(!coveragePoints["Cpath_22"]){
                      coveragePoints["Cpath_22"] = true;
                      coveragePointsCount++;
                    }
                    if ((pc_sel == PC_JR)) {
                      if(!coveragePoints["Cpath_23"]){
                        coveragePoints["Cpath_23"] = true;
                        coveragePointsCount++;
                      }
                      pc_next = (RegsToCtl_data.contents1 + decodedInstr.imm);
                    } else {
                      if(!coveragePoints["Cpath_24"]){
                        coveragePoints["Cpath_24"] = true;
                        coveragePointsCount++;
                      }
                      if ((pc_sel == PC_EXC)) {
                        if(!coveragePoints["Cpath_25"]){
                          coveragePoints["Cpath_25"] = true;
                          coveragePointsCount++;
                        }
                      }
                    }
                  }
                }
              }
              section = memoryOperation;
            }
            else if (section==decode) {
              if(!coveragePoints["Cpath_26"]){
                coveragePoints["Cpath_26"] = true;
                coveragePointsCount++;
              }
              CtlToDec_port->write(encodedInstr.loadedData);
              DecToCtl_port->read(decodedInstr);
              section = setControl;
            }
            else if (section==executeALU) {
              if(!coveragePoints["Cpath_27"]){
                coveragePoints["Cpath_27"] = true;
                coveragePointsCount++;
              }
              CtlToALU_data.reg1_contents = RegsToCtl_data.contents1;
              CtlToALU_data.reg2_contents = RegsToCtl_data.contents2;
              CtlToALU_data.imm = decodedInstr.imm;
              CtlToALU_data.pc_reg = pc_reg;
              CtlToALU_port->write(CtlToALU_data);
              ALUtoCtl_port->read(ALUtoCtl_data);
              section = calculateNextPC;
            }
            else if (section==fetch) {
              if(!coveragePoints["Cpath_28"]){
                coveragePoints["Cpath_28"] = true;
                coveragePointsCount++;
              }
              memoryAccess.addrIn = pc_reg;
              memoryAccess.dataIn = 0;
              memoryAccess.mask = MT_W;
              memoryAccess.req = ME_RD;
              CtlToMem_port->write(memoryAccess);
              MemToCtl_port->read(encodedInstr);
              section = decode;
            }
            else if (section==memoryOperation) {
              if(!coveragePoints["Cpath_29"]){
                coveragePoints["Cpath_29"] = true;
                coveragePointsCount++;
              }
              if (mem_en) {
                if(!coveragePoints["Cpath_30"]){
                  coveragePoints["Cpath_30"] = true;
                  coveragePointsCount++;
                }
                memoryAccess.addrIn = ALUtoCtl_data.ALU_result;
                if ((memoryAccess.req == ME_WR)) {
                  if(!coveragePoints["Cpath_31"]){
                    coveragePoints["Cpath_31"] = true;
                    coveragePointsCount++;
                  }
                  memoryAccess.dataIn = RegsToCtl_data.contents2;
                } else {
                  if(!coveragePoints["Cpath_32"]){
                    coveragePoints["Cpath_32"] = true;
                    coveragePointsCount++;
                  }
                  if ((memoryAccess.req == ME_RD)) {
                    if(!coveragePoints["Cpath_33"]){
                      coveragePoints["Cpath_33"] = true;
                      coveragePointsCount++;
                    }
                    memoryAccess.dataIn = 0;
                  }
                }
                CtlToMem_port->write(memoryAccess);
                MemToCtl_port->read(fromMemoryData);
              }
              section = writeBack;
            }
            else if (section==readRegisterFile) {
              if(!coveragePoints["Cpath_34"]){
                coveragePoints["Cpath_34"] = true;
                coveragePointsCount++;
              }
              if (reg_rd_en) {
                if(!coveragePoints["Cpath_35"]){
                  coveragePoints["Cpath_35"] = true;
                  coveragePointsCount++;
                }
                CtlToRegs_data.src1 = decodedInstr.rs1_addr;
                CtlToRegs_data.src2 = decodedInstr.rs2_addr;
                CtlToRegs_data.req = REG_RD;
                CtlToRegs_port->write(CtlToRegs_data);
                RegsToCtl_port->read(RegsToCtl_data);
              }
              section = executeALU;
            }
            else if (section==setControl) {
              if(!coveragePoints["Cpath_36"]){
                coveragePoints["Cpath_36"] = true;
                coveragePointsCount++;
              }
              if ((decodedInstr.encType == I)) {
                if(!coveragePoints["Cpath_37"]){
                  coveragePoints["Cpath_37"] = true;
                  coveragePointsCount++;
                }
                if ((((((((((decodedInstr.instrType == addI) or (decodedInstr.instrType == sltI)) or (decodedInstr.instrType == sltIu)) or (decodedInstr.instrType == xorI)) or (decodedInstr.instrType == orI)) or (decodedInstr.instrType == andI)) or (decodedInstr.instrType == sllI)) or (decodedInstr.instrType == srlI)) or (decodedInstr.instrType == sraI))) {
                  if(!coveragePoints["Cpath_38"]){
                    coveragePoints["Cpath_38"] = true;
                    coveragePointsCount++;
                  }
                  CtlToALU_data.op1_sel = OP_REG;
                  CtlToALU_data.op2_sel = OP_IMM;
                  wb_sel = WB_ALU;
                  wb_en = true;
                  reg_rd_en = true;
                  mem_en = false;
                  br_en = false;
                  if ((decodedInstr.instrType == addI)) {
                    if(!coveragePoints["Cpath_39"]){
                      coveragePoints["Cpath_39"] = true;
                      coveragePointsCount++;
                    }
                    CtlToALU_data.alu_fun = ALU_ADD;
                  } else {
                    if(!coveragePoints["Cpath_40"]){
                      coveragePoints["Cpath_40"] = true;
                      coveragePointsCount++;
                    }
                    if ((decodedInstr.instrType == sltI)) {
                      if(!coveragePoints["Cpath_41"]){
                        coveragePoints["Cpath_41"] = true;
                        coveragePointsCount++;
                      }
                      CtlToALU_data.alu_fun = ALU_SLT;
                    } else {
                      if(!coveragePoints["Cpath_42"]){
                        coveragePoints["Cpath_42"] = true;
                        coveragePointsCount++;
                      }
                      if ((decodedInstr.instrType == sltIu)) {
                        if(!coveragePoints["Cpath_43"]){
                          coveragePoints["Cpath_43"] = true;
                          coveragePointsCount++;
                        }
                        CtlToALU_data.alu_fun = ALU_SLTU;
                      } else {
                        if(!coveragePoints["Cpath_44"]){
                          coveragePoints["Cpath_44"] = true;
                          coveragePointsCount++;
                        }
                        if ((decodedInstr.instrType == xorI)) {
                          if(!coveragePoints["Cpath_45"]){
                            coveragePoints["Cpath_45"] = true;
                            coveragePointsCount++;
                          }
                          CtlToALU_data.alu_fun = ALU_XOR;
                        } else {
                          if(!coveragePoints["Cpath_46"]){
                            coveragePoints["Cpath_46"] = true;
                            coveragePointsCount++;
                          }
                          if ((decodedInstr.instrType == orI)) {
                            if(!coveragePoints["Cpath_47"]){
                              coveragePoints["Cpath_47"] = true;
                              coveragePointsCount++;
                            }
                            CtlToALU_data.alu_fun = ALU_OR;
                          } else {
                            if(!coveragePoints["Cpath_48"]){
                              coveragePoints["Cpath_48"] = true;
                              coveragePointsCount++;
                            }
                            if ((decodedInstr.instrType == andI)) {
                              if(!coveragePoints["Cpath_49"]){
                                coveragePoints["Cpath_49"] = true;
                                coveragePointsCount++;
                              }
                              CtlToALU_data.alu_fun = ALU_AND;
                            } else {
                              if(!coveragePoints["Cpath_50"]){
                                coveragePoints["Cpath_50"] = true;
                                coveragePointsCount++;
                              }
                              if ((decodedInstr.instrType == sllI)) {
                                if(!coveragePoints["Cpath_51"]){
                                  coveragePoints["Cpath_51"] = true;
                                  coveragePointsCount++;
                                }
                                CtlToALU_data.alu_fun = ALU_SLL;
                              } else {
                                if(!coveragePoints["Cpath_52"]){
                                  coveragePoints["Cpath_52"] = true;
                                  coveragePointsCount++;
                                }
                                if ((decodedInstr.instrType == srlI)) {
                                  if(!coveragePoints["Cpath_53"]){
                                    coveragePoints["Cpath_53"] = true;
                                    coveragePointsCount++;
                                  }
                                  CtlToALU_data.alu_fun = ALU_SRL;
                                } else {
                                  if(!coveragePoints["Cpath_54"]){
                                    coveragePoints["Cpath_54"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((decodedInstr.instrType == sraI)) {
                                    if(!coveragePoints["Cpath_55"]){
                                      coveragePoints["Cpath_55"] = true;
                                      coveragePointsCount++;
                                    }
                                    CtlToALU_data.alu_fun = ALU_SRA;
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
                  if(!coveragePoints["Cpath_56"]){
                    coveragePoints["Cpath_56"] = true;
                    coveragePointsCount++;
                  }
                  if ((((((decodedInstr.instrType == lb) or (decodedInstr.instrType == lh)) or (decodedInstr.instrType == lw)) or (decodedInstr.instrType == lbu)) or (decodedInstr.instrType == lhu))) {
                    if(!coveragePoints["Cpath_57"]){
                      coveragePoints["Cpath_57"] = true;
                      coveragePointsCount++;
                    }
                    CtlToALU_data.op1_sel = OP_REG;
                    CtlToALU_data.op2_sel = OP_IMM;
                    CtlToALU_data.alu_fun = ALU_ADD;
                    wb_sel = WB_MEM;
                    wb_en = true;
                    reg_rd_en = true;
                    mem_en = true;
                    br_en = false;
                    memoryAccess.req = ME_RD;
                    if ((decodedInstr.instrType == lb)) {
                      if(!coveragePoints["Cpath_58"]){
                        coveragePoints["Cpath_58"] = true;
                        coveragePointsCount++;
                      }
                      memoryAccess.mask = MT_B;
                    } else {
                      if(!coveragePoints["Cpath_59"]){
                        coveragePoints["Cpath_59"] = true;
                        coveragePointsCount++;
                      }
                      if ((decodedInstr.instrType == lh)) {
                        if(!coveragePoints["Cpath_60"]){
                          coveragePoints["Cpath_60"] = true;
                          coveragePointsCount++;
                        }
                        memoryAccess.mask = MT_H;
                      } else {
                        if(!coveragePoints["Cpath_61"]){
                          coveragePoints["Cpath_61"] = true;
                          coveragePointsCount++;
                        }
                        if ((decodedInstr.instrType == lw)) {
                          if(!coveragePoints["Cpath_62"]){
                            coveragePoints["Cpath_62"] = true;
                            coveragePointsCount++;
                          }
                          memoryAccess.mask = MT_W;
                        } else {
                          if(!coveragePoints["Cpath_63"]){
                            coveragePoints["Cpath_63"] = true;
                            coveragePointsCount++;
                          }
                          if ((decodedInstr.instrType == lbu)) {
                            if(!coveragePoints["Cpath_64"]){
                              coveragePoints["Cpath_64"] = true;
                              coveragePointsCount++;
                            }
                            memoryAccess.mask = MT_BU;
                          } else {
                            if(!coveragePoints["Cpath_65"]){
                              coveragePoints["Cpath_65"] = true;
                              coveragePointsCount++;
                            }
                            if ((decodedInstr.instrType == lhu)) {
                              if(!coveragePoints["Cpath_66"]){
                                coveragePoints["Cpath_66"] = true;
                                coveragePointsCount++;
                              }
                              memoryAccess.mask = MT_HU;
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if(!coveragePoints["Cpath_67"]){
                      coveragePoints["Cpath_67"] = true;
                      coveragePointsCount++;
                    }
                    if ((decodedInstr.instrType == jalr)) {
                      if(!coveragePoints["Cpath_68"]){
                        coveragePoints["Cpath_68"] = true;
                        coveragePointsCount++;
                      }
                      CtlToALU_data.op1_sel = OP_X;
                      CtlToALU_data.op2_sel = OP_X;
                      CtlToALU_data.alu_fun = ALU_X;
                      wb_sel = WB_PC4;
                      wb_en = true;
                      reg_rd_en = true;
                      mem_en = false;
                      br_en = false;
                    }
                  }
                }
              } else {
                if(!coveragePoints["Cpath_69"]){
                  coveragePoints["Cpath_69"] = true;
                  coveragePointsCount++;
                }
                if ((decodedInstr.encType == R)) {
                  if(!coveragePoints["Cpath_70"]){
                    coveragePoints["Cpath_70"] = true;
                    coveragePointsCount++;
                  }
                  CtlToALU_data.op1_sel = OP_REG;
                  CtlToALU_data.op2_sel = OP_REG;
                  wb_sel = WB_ALU;
                  wb_en = true;
                  reg_rd_en = true;
                  mem_en = false;
                  br_en = false;
                  if ((decodedInstr.instrType == add)) {
                    if(!coveragePoints["Cpath_71"]){
                      coveragePoints["Cpath_71"] = true;
                      coveragePointsCount++;
                    }
                    CtlToALU_data.alu_fun = ALU_ADD;
                  } else {
                    if(!coveragePoints["Cpath_72"]){
                      coveragePoints["Cpath_72"] = true;
                      coveragePointsCount++;
                    }
                    if ((decodedInstr.instrType == sub)) {
                      if(!coveragePoints["Cpath_73"]){
                        coveragePoints["Cpath_73"] = true;
                        coveragePointsCount++;
                      }
                      CtlToALU_data.alu_fun = ALU_SUB;
                    } else {
                      if(!coveragePoints["Cpath_74"]){
                        coveragePoints["Cpath_74"] = true;
                        coveragePointsCount++;
                      }
                      if ((decodedInstr.instrType == sll_Instr)) {
                        if(!coveragePoints["Cpath_75"]){
                          coveragePoints["Cpath_75"] = true;
                          coveragePointsCount++;
                        }
                        CtlToALU_data.alu_fun = ALU_SLL;
                      } else {
                        if(!coveragePoints["Cpath_76"]){
                          coveragePoints["Cpath_76"] = true;
                          coveragePointsCount++;
                        }
                        if ((decodedInstr.instrType == slt)) {
                          if(!coveragePoints["Cpath_77"]){
                            coveragePoints["Cpath_77"] = true;
                            coveragePointsCount++;
                          }
                          CtlToALU_data.alu_fun = ALU_SLT;
                        } else {
                          if(!coveragePoints["Cpath_78"]){
                            coveragePoints["Cpath_78"] = true;
                            coveragePointsCount++;
                          }
                          if ((decodedInstr.instrType == sltu)) {
                            if(!coveragePoints["Cpath_79"]){
                              coveragePoints["Cpath_79"] = true;
                              coveragePointsCount++;
                            }
                            CtlToALU_data.alu_fun = ALU_SLTU;
                          } else {
                            if(!coveragePoints["Cpath_80"]){
                              coveragePoints["Cpath_80"] = true;
                              coveragePointsCount++;
                            }
                            if ((decodedInstr.instrType == Xor_Instr)) {
                              if(!coveragePoints["Cpath_81"]){
                                coveragePoints["Cpath_81"] = true;
                                coveragePointsCount++;
                              }
                              CtlToALU_data.alu_fun = ALU_XOR;
                            } else {
                              if(!coveragePoints["Cpath_82"]){
                                coveragePoints["Cpath_82"] = true;
                                coveragePointsCount++;
                              }
                              if ((decodedInstr.instrType == srl_Instr)) {
                                if(!coveragePoints["Cpath_83"]){
                                  coveragePoints["Cpath_83"] = true;
                                  coveragePointsCount++;
                                }
                                CtlToALU_data.alu_fun = ALU_SRL;
                              } else {
                                if(!coveragePoints["Cpath_84"]){
                                  coveragePoints["Cpath_84"] = true;
                                  coveragePointsCount++;
                                }
                                if ((decodedInstr.instrType == sra_Instr)) {
                                  if(!coveragePoints["Cpath_85"]){
                                    coveragePoints["Cpath_85"] = true;
                                    coveragePointsCount++;
                                  }
                                  CtlToALU_data.alu_fun = ALU_SRA;
                                } else {
                                  if(!coveragePoints["Cpath_86"]){
                                    coveragePoints["Cpath_86"] = true;
                                    coveragePointsCount++;
                                  }
                                  if ((decodedInstr.instrType == Or_Instr)) {
                                    if(!coveragePoints["Cpath_87"]){
                                      coveragePoints["Cpath_87"] = true;
                                      coveragePointsCount++;
                                    }
                                    CtlToALU_data.alu_fun = ALU_OR;
                                  } else {
                                    if(!coveragePoints["Cpath_88"]){
                                      coveragePoints["Cpath_88"] = true;
                                      coveragePointsCount++;
                                    }
                                    if ((decodedInstr.instrType == And_Instr)) {
                                      if(!coveragePoints["Cpath_89"]){
                                        coveragePoints["Cpath_89"] = true;
                                        coveragePointsCount++;
                                      }
                                      CtlToALU_data.alu_fun = ALU_AND;
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
                  if(!coveragePoints["Cpath_90"]){
                    coveragePoints["Cpath_90"] = true;
                    coveragePointsCount++;
                  }
                  if ((decodedInstr.encType == B)) {
                    if(!coveragePoints["Cpath_91"]){
                      coveragePoints["Cpath_91"] = true;
                      coveragePointsCount++;
                    }
                    CtlToALU_data.op1_sel = OP_REG;
                    CtlToALU_data.op2_sel = OP_REG;
                    wb_sel = WB_X;
                    reg_rd_en = true;
                    wb_en = false;
                    mem_en = false;
                    br_en = true;
                    if ((decodedInstr.instrType == beq)) {
                      if(!coveragePoints["Cpath_92"]){
                        coveragePoints["Cpath_92"] = true;
                        coveragePointsCount++;
                      }
                      CtlToALU_data.alu_fun = ALU_SUB;
                    } else {
                      if(!coveragePoints["Cpath_93"]){
                        coveragePoints["Cpath_93"] = true;
                        coveragePointsCount++;
                      }
                      if ((decodedInstr.instrType == bne)) {
                        if(!coveragePoints["Cpath_94"]){
                          coveragePoints["Cpath_94"] = true;
                          coveragePointsCount++;
                        }
                        CtlToALU_data.alu_fun = ALU_SUB;
                      } else {
                        if(!coveragePoints["Cpath_95"]){
                          coveragePoints["Cpath_95"] = true;
                          coveragePointsCount++;
                        }
                        if ((decodedInstr.instrType == blt)) {
                          if(!coveragePoints["Cpath_96"]){
                            coveragePoints["Cpath_96"] = true;
                            coveragePointsCount++;
                          }
                          CtlToALU_data.alu_fun = ALU_SLT;
                        } else {
                          if(!coveragePoints["Cpath_97"]){
                            coveragePoints["Cpath_97"] = true;
                            coveragePointsCount++;
                          }
                          if ((decodedInstr.instrType == bge)) {
                            if(!coveragePoints["Cpath_98"]){
                              coveragePoints["Cpath_98"] = true;
                              coveragePointsCount++;
                            }
                            CtlToALU_data.alu_fun = ALU_SLT;
                          } else {
                            if(!coveragePoints["Cpath_99"]){
                              coveragePoints["Cpath_99"] = true;
                              coveragePointsCount++;
                            }
                            if ((decodedInstr.instrType == bltu)) {
                              if(!coveragePoints["Cpath_100"]){
                                coveragePoints["Cpath_100"] = true;
                                coveragePointsCount++;
                              }
                              CtlToALU_data.alu_fun = ALU_SLTU;
                            } else {
                              if(!coveragePoints["Cpath_101"]){
                                coveragePoints["Cpath_101"] = true;
                                coveragePointsCount++;
                              }
                              if ((decodedInstr.instrType == bgeu)) {
                                if(!coveragePoints["Cpath_102"]){
                                  coveragePoints["Cpath_102"] = true;
                                  coveragePointsCount++;
                                }
                                CtlToALU_data.alu_fun = ALU_SLTU;
                              }
                            }
                          }
                        }
                      }
                    }
                  } else {
                    if(!coveragePoints["Cpath_103"]){
                      coveragePoints["Cpath_103"] = true;
                      coveragePointsCount++;
                    }
                    if ((decodedInstr.encType == J)) {
                      if(!coveragePoints["Cpath_104"]){
                        coveragePoints["Cpath_104"] = true;
                        coveragePointsCount++;
                      }
                      if ((decodedInstr.instrType == jal)) {
                        if(!coveragePoints["Cpath_105"]){
                          coveragePoints["Cpath_105"] = true;
                          coveragePointsCount++;
                        }
                        CtlToALU_data.op1_sel = OP_X;
                        CtlToALU_data.op2_sel = OP_X;
                        CtlToALU_data.alu_fun = ALU_X;
                        wb_sel = WB_PC4;
                        reg_rd_en = false;
                        wb_en = true;
                        mem_en = false;
                        br_en = false;
                      }
                    } else {
                      if(!coveragePoints["Cpath_106"]){
                        coveragePoints["Cpath_106"] = true;
                        coveragePointsCount++;
                      }
                      if ((decodedInstr.encType == S)) {
                        if(!coveragePoints["Cpath_107"]){
                          coveragePoints["Cpath_107"] = true;
                          coveragePointsCount++;
                        }
                        CtlToALU_data.op1_sel = OP_REG;
                        CtlToALU_data.op2_sel = OP_IMM;
                        CtlToALU_data.alu_fun = ALU_ADD;
                        wb_sel = WB_X;
                        wb_en = false;
                        reg_rd_en = true;
                        mem_en = true;
                        br_en = false;
                        memoryAccess.req = ME_WR;
                        if ((decodedInstr.instrType == sb)) {
                          if(!coveragePoints["Cpath_108"]){
                            coveragePoints["Cpath_108"] = true;
                            coveragePointsCount++;
                          }
                          memoryAccess.mask = MT_B;
                        } else {
                          if(!coveragePoints["Cpath_109"]){
                            coveragePoints["Cpath_109"] = true;
                            coveragePointsCount++;
                          }
                          if ((decodedInstr.instrType == sh)) {
                            if(!coveragePoints["Cpath_110"]){
                              coveragePoints["Cpath_110"] = true;
                              coveragePointsCount++;
                            }
                            memoryAccess.mask = MT_H;
                          } else {
                            if(!coveragePoints["Cpath_111"]){
                              coveragePoints["Cpath_111"] = true;
                              coveragePointsCount++;
                            }
                            if ((decodedInstr.instrType == sw)) {
                              if(!coveragePoints["Cpath_112"]){
                                coveragePoints["Cpath_112"] = true;
                                coveragePointsCount++;
                              }
                              memoryAccess.mask = MT_W;
                            }
                          }
                        }
                      } else {
                        if(!coveragePoints["Cpath_113"]){
                          coveragePoints["Cpath_113"] = true;
                          coveragePointsCount++;
                        }
                        if ((decodedInstr.encType == U)) {
                          if(!coveragePoints["Cpath_114"]){
                            coveragePoints["Cpath_114"] = true;
                            coveragePointsCount++;
                          }
                          wb_sel = WB_ALU;
                          wb_en = true;
                          reg_rd_en = false;
                          mem_en = false;
                          br_en = false;
                          if ((decodedInstr.instrType == lui)) {
                            if(!coveragePoints["Cpath_115"]){
                              coveragePoints["Cpath_115"] = true;
                              coveragePointsCount++;
                            }
                            CtlToALU_data.op1_sel = OP_IMM;
                            CtlToALU_data.op2_sel = OP_X;
                            CtlToALU_data.alu_fun = ALU_COPY1;
                          } else {
                            if(!coveragePoints["Cpath_116"]){
                              coveragePoints["Cpath_116"] = true;
                              coveragePointsCount++;
                            }
                            if ((decodedInstr.instrType == auipc)) {
                              if(!coveragePoints["Cpath_117"]){
                                coveragePoints["Cpath_117"] = true;
                                coveragePointsCount++;
                              }
                              CtlToALU_data.op1_sel = OP_PC;
                              CtlToALU_data.op2_sel = OP_IMM;
                              CtlToALU_data.alu_fun = ALU_ADD;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              section = readRegisterFile;
            }
            else if (section==writeBack) {
              if(!coveragePoints["Cpath_118"]){
                coveragePoints["Cpath_118"] = true;
                coveragePointsCount++;
              }
              if ((wb_sel == WB_ALU)) {
                if(!coveragePoints["Cpath_119"]){
                  coveragePoints["Cpath_119"] = true;
                  coveragePointsCount++;
                }
                wb_data = ALUtoCtl_data.ALU_result;
              } else {
                if(!coveragePoints["Cpath_120"]){
                  coveragePoints["Cpath_120"] = true;
                  coveragePointsCount++;
                }
                if ((wb_sel == WB_MEM)) {
                  if(!coveragePoints["Cpath_121"]){
                    coveragePoints["Cpath_121"] = true;
                    coveragePointsCount++;
                  }
                  wb_data = fromMemoryData.loadedData;
                } else {
                  if(!coveragePoints["Cpath_122"]){
                    coveragePoints["Cpath_122"] = true;
                    coveragePointsCount++;
                  }
                  if ((wb_sel == WB_PC4)) {
                    if(!coveragePoints["Cpath_123"]){
                      coveragePoints["Cpath_123"] = true;
                      coveragePointsCount++;
                    }
                    wb_data = (pc_reg + 4);
                  }
                }
              }
              if ((((wb_en == true) and (wb_sel != WB_X)) and (decodedInstr.rd_addr != 0))) {
                if(!coveragePoints["Cpath_124"]){
                  coveragePoints["Cpath_124"] = true;
                  coveragePointsCount++;
                }
                CtlToRegs_data.dst = decodedInstr.rd_addr;
                CtlToRegs_data.dst_data = wb_data;
                CtlToRegs_data.req = REG_WR;
                CtlToRegs_port->write(CtlToRegs_data);
              }
              pc_reg = pc_next;
              section = fetch;
            }
            wait(SC_ZERO_TIME);
          }//end of while
      }//end of FSM
      int coveragePointsTotal = 124;
      int coveragePointsCount = 0;
      std::map<std::string, bool> coveragePoints;

      SC_HAS_PROCESS(Cpath);

      Cpath(sc_module_name name) :
        section(fetch),
        br_en(false),
        mem_en(false),
        pc_next(0),
        pc_reg(0),
        pc_sel(PC_4),
        reg_rd_en(false),
        var(false),
        wb_data(0),
        wb_en(false),
        wb_sel(WB_ALU)      {
        SC_THREAD(FSM);
        for(int i = 1; i < coveragePointsTotal; i++)
                coveragePoints.insert(std::make_pair("Cpath_"+to_string(i),false));
        }
      };//end of module


#endif //SYSTEMC_Cpath_H
