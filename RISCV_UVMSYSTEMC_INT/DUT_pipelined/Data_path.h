#ifndef SYSTEMC_Data_path_H
#define SYSTEMC_Data_path_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

    struct Data_path : public sc_module {

      enum Sections {executeStage, memoryStage, readRegFileStage, setPipelineSignals, writeBackStage};
      Sections section;

      slave_in<CUtoDP_IF> CUtoDP_port;
      slave_out<DPtoCU_IF> DPtoCU_port;
      master_out<DPtoRF_IF> DPtoRF_port;
      master_in<RFtoDP_IF> RFtoDP_port;

      //functions
      unsigned aluOpFwdUnit(unsigned aluResult_s4, unsigned dstAddr_s4, unsigned dstAddr_s5, EncType encType_s5, unsigned loadedData, unsigned regContent_s3, unsigned srcAddr_s3) {
        if (((((srcAddr_s3 == dstAddr_s5) and (encType_s5 == ENC_I_L)) and (srcAddr_s3 != dstAddr_s4)) and (srcAddr_s3 != 0))) {
          if(!coveragePoints["Data_path_1"]){
            coveragePoints["Data_path_1"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_1\n";
          }
          return(loadedData);
        } else {
          if(!coveragePoints["Data_path_2"]){
            coveragePoints["Data_path_2"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_2\n";
          }
          if (((srcAddr_s3 == dstAddr_s4) and (srcAddr_s3 != 0))) {
            if(!coveragePoints["Data_path_3"]){
              coveragePoints["Data_path_3"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_3\n";
            }
            return(aluResult_s4);
          } else {
            if(!coveragePoints["Data_path_4"]){
              coveragePoints["Data_path_4"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_4\n";
            }
            return(regContent_s3);
          }
        }
      }

      unsigned dmemDataInFwdUnit(unsigned aluResult_s5, unsigned dstAddr_s5, EncType encType_s5, bool fwdPrevLoadedData, unsigned loadedData, unsigned prevLoadedData, unsigned reg2Content_s4, unsigned src2Addr_s4) {
        if ((((src2Addr_s4 == dstAddr_s5) and (encType_s5 == ENC_I_L)) and (src2Addr_s4 != 0))) {
          if(!coveragePoints["Data_path_5"]){
            coveragePoints["Data_path_5"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_5\n";
          }
          return(loadedData);
        } else {
          if(!coveragePoints["Data_path_6"]){
            coveragePoints["Data_path_6"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_6\n";
          }
          if (((src2Addr_s4 == dstAddr_s5) and (src2Addr_s4 != 0))) {
            if(!coveragePoints["Data_path_7"]){
              coveragePoints["Data_path_7"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_7\n";
            }
            return(aluResult_s5);
          } else {
            if(!coveragePoints["Data_path_8"]){
              coveragePoints["Data_path_8"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_8\n";
            }
            if (fwdPrevLoadedData) {
              if(!coveragePoints["Data_path_9"]){
                coveragePoints["Data_path_9"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_9\n";
              }
              return(prevLoadedData);
            } else {
              if(!coveragePoints["Data_path_10"]){
                coveragePoints["Data_path_10"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_10\n";
              }
              return(reg2Content_s4);
            }
          }
        }
      }

      unsigned getALUoperand(unsigned aluOpFwdUnitValue, AL_OperandSelType aluOpSel_s3, unsigned imm_s3, unsigned pc_s3) {
        if ((aluOpSel_s3 == OP_REG)) {
          if(!coveragePoints["Data_path_11"]){
            coveragePoints["Data_path_11"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_11\n";
          }
          return(aluOpFwdUnitValue);
        } else {
          if(!coveragePoints["Data_path_12"]){
            coveragePoints["Data_path_12"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_12\n";
          }
          if ((aluOpSel_s3 == OP_IMM)) {
            if(!coveragePoints["Data_path_13"]){
              coveragePoints["Data_path_13"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_13\n";
            }
            return(imm_s3);
          } else {
            if(!coveragePoints["Data_path_14"]){
              coveragePoints["Data_path_14"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_14\n";
            }
            if ((aluOpSel_s3 == OP_PC)) {
              if(!coveragePoints["Data_path_15"]){
                coveragePoints["Data_path_15"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_15\n";
              }
              return(pc_s3);
            } else {
              if(!coveragePoints["Data_path_16"]){
                coveragePoints["Data_path_16"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_16\n";
              }
              return(0);
            }
          }
        }
      }

      unsigned getALUresult(DPtoAL_IF DPtoAL_data) {
        if ((DPtoAL_data.aluFunc == ALU_ADD)) {
          if(!coveragePoints["Data_path_17"]){
            coveragePoints["Data_path_17"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_17\n";
          }
          return((DPtoAL_data.aluOp1 + DPtoAL_data.aluOp2));
        } else {
          if(!coveragePoints["Data_path_18"]){
            coveragePoints["Data_path_18"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_18\n";
          }
          if ((DPtoAL_data.aluFunc == ALU_SUB)) {
            if(!coveragePoints["Data_path_19"]){
              coveragePoints["Data_path_19"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_19\n";
            }
            return((DPtoAL_data.aluOp1 + -(DPtoAL_data.aluOp2)));
          } else {
            if(!coveragePoints["Data_path_20"]){
              coveragePoints["Data_path_20"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_20\n";
            }
            if ((DPtoAL_data.aluFunc == ALU_AND)) {
              if(!coveragePoints["Data_path_21"]){
                coveragePoints["Data_path_21"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_21\n";
              }
              return((DPtoAL_data.aluOp1 & DPtoAL_data.aluOp2));
            } else {
              if(!coveragePoints["Data_path_22"]){
                coveragePoints["Data_path_22"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_22\n";
              }
              if ((DPtoAL_data.aluFunc == ALU_OR)) {
                if(!coveragePoints["Data_path_23"]){
                  coveragePoints["Data_path_23"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_23\n";
                }
                return((DPtoAL_data.aluOp1 | DPtoAL_data.aluOp2));
              } else {
                if(!coveragePoints["Data_path_24"]){
                  coveragePoints["Data_path_24"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_24\n";
                }
                if ((DPtoAL_data.aluFunc == ALU_XOR)) {
                  if(!coveragePoints["Data_path_25"]){
                    coveragePoints["Data_path_25"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_25\n";
                  }
                  return((DPtoAL_data.aluOp1 ^ DPtoAL_data.aluOp2));
                } else {
                  if(!coveragePoints["Data_path_26"]){
                    coveragePoints["Data_path_26"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_26\n";
                  }
                  if ((DPtoAL_data.aluFunc == ALU_SLT)) {
                    if(!coveragePoints["Data_path_27"]){
                      coveragePoints["Data_path_27"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_27\n";
                    }
                    if ((static_cast<int>(DPtoAL_data.aluOp1) < static_cast<int>(DPtoAL_data.aluOp2))) {
                      if(!coveragePoints["Data_path_28"]){
                        coveragePoints["Data_path_28"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_28\n";
                      }
                      return(1);
                    } else {
                      if(!coveragePoints["Data_path_29"]){
                        coveragePoints["Data_path_29"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_29\n";
                      }
                      return(0);
                    }
                  } else {
                    if(!coveragePoints["Data_path_30"]){
                      coveragePoints["Data_path_30"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_30\n";
                    }
                    if ((DPtoAL_data.aluFunc == ALU_SLTU)) {
                      if(!coveragePoints["Data_path_31"]){
                        coveragePoints["Data_path_31"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_31\n";
                      }
                      if ((DPtoAL_data.aluOp1 < DPtoAL_data.aluOp2)) {
                        if(!coveragePoints["Data_path_32"]){
                          coveragePoints["Data_path_32"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_32\n";
                        }
                        return(1);
                      } else {
                        if(!coveragePoints["Data_path_33"]){
                          coveragePoints["Data_path_33"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_33\n";
                        }
                        return(0);
                      }
                    } else {
                      if(!coveragePoints["Data_path_34"]){
                        coveragePoints["Data_path_34"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_34\n";
                      }
                      if ((DPtoAL_data.aluFunc == ALU_SLL)) {
                        if(!coveragePoints["Data_path_35"]){
                          coveragePoints["Data_path_35"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_35\n";
                        }
                        return((DPtoAL_data.aluOp1 << (DPtoAL_data.aluOp2 & 31)));
                      } else {
                        if(!coveragePoints["Data_path_36"]){
                          coveragePoints["Data_path_36"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_36\n";
                        }
                        if ((DPtoAL_data.aluFunc == ALU_SRA)) {
                          if(!coveragePoints["Data_path_37"]){
                            coveragePoints["Data_path_37"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_37\n";
                          }
                          return(static_cast<unsigned>((static_cast<int>(DPtoAL_data.aluOp1) >> static_cast<int>((DPtoAL_data.aluOp2 & 31)))));
                        } else {
                          if(!coveragePoints["Data_path_38"]){
                            coveragePoints["Data_path_38"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_38\n";
                          }
                          if ((DPtoAL_data.aluFunc == ALU_SRL)) {
                            if(!coveragePoints["Data_path_39"]){
                              coveragePoints["Data_path_39"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_39\n";
                            }
                            return((DPtoAL_data.aluOp1 >> (DPtoAL_data.aluOp2 & 31)));
                          } else {
                            if(!coveragePoints["Data_path_40"]){
                              coveragePoints["Data_path_40"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_40\n";
                            }
                            if ((DPtoAL_data.aluFunc == ALU_COPY1)) {
                              if(!coveragePoints["Data_path_41"]){
                                coveragePoints["Data_path_41"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_41\n";
                              }
                              return(DPtoAL_data.aluOp1);
                            } else {
                              if(!coveragePoints["Data_path_42"]){
                                coveragePoints["Data_path_42"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_42\n";
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

      unsigned getRegContent(RFtoDP_IF RFtoDP_data, RF_RD_AccessType rdReq, unsigned srcAddr) {
        if ((rdReq == RF_RD)) {
          if(!coveragePoints["Data_path_43"]){
            coveragePoints["Data_path_43"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_43\n";
          }
          if ((srcAddr == 0)) {
            if(!coveragePoints["Data_path_44"]){
              coveragePoints["Data_path_44"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_44\n";
            }
            return(0);
          } else {
            if(!coveragePoints["Data_path_45"]){
              coveragePoints["Data_path_45"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_45\n";
            }
            if ((srcAddr == 1)) {
              if(!coveragePoints["Data_path_46"]){
                coveragePoints["Data_path_46"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_46\n";
              }
              return(RFtoDP_data.reg_file_01);
            } else {
              if(!coveragePoints["Data_path_47"]){
                coveragePoints["Data_path_47"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_47\n";
              }
              if ((srcAddr == 2)) {
                if(!coveragePoints["Data_path_48"]){
                  coveragePoints["Data_path_48"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_48\n";
                }
                return(RFtoDP_data.reg_file_02);
              } else {
                if(!coveragePoints["Data_path_49"]){
                  coveragePoints["Data_path_49"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_49\n";
                }
                if ((srcAddr == 3)) {
                  if(!coveragePoints["Data_path_50"]){
                    coveragePoints["Data_path_50"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_50\n";
                  }
                  return(RFtoDP_data.reg_file_03);
                } else {
                  if(!coveragePoints["Data_path_51"]){
                    coveragePoints["Data_path_51"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_51\n";
                  }
                  if ((srcAddr == 4)) {
                    if(!coveragePoints["Data_path_52"]){
                      coveragePoints["Data_path_52"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_52\n";
                    }
                    return(RFtoDP_data.reg_file_04);
                  } else {
                    if(!coveragePoints["Data_path_53"]){
                      coveragePoints["Data_path_53"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_53\n";
                    }
                    if ((srcAddr == 5)) {
                      if(!coveragePoints["Data_path_54"]){
                        coveragePoints["Data_path_54"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_54\n";
                      }
                      return(RFtoDP_data.reg_file_05);
                    } else {
                      if(!coveragePoints["Data_path_55"]){
                        coveragePoints["Data_path_55"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_55\n";
                      }
                      if ((srcAddr == 6)) {
                        if(!coveragePoints["Data_path_56"]){
                          coveragePoints["Data_path_56"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_56\n";
                        }
                        return(RFtoDP_data.reg_file_06);
                      } else {
                        if(!coveragePoints["Data_path_57"]){
                          coveragePoints["Data_path_57"] = true;
                          coveragePointsCount++;
                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_57\n";
                        }
                        if ((srcAddr == 7)) {
                          if(!coveragePoints["Data_path_58"]){
                            coveragePoints["Data_path_58"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_58\n";
                          }
                          return(RFtoDP_data.reg_file_07);
                        } else {
                          if(!coveragePoints["Data_path_59"]){
                            coveragePoints["Data_path_59"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_59\n";
                          }
                          if ((srcAddr == 8)) {
                            if(!coveragePoints["Data_path_60"]){
                              coveragePoints["Data_path_60"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_60\n";
                            }
                            return(RFtoDP_data.reg_file_08);
                          } else {
                            if(!coveragePoints["Data_path_61"]){
                              coveragePoints["Data_path_61"] = true;
                              coveragePointsCount++;
                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_61\n";
                            }
                            if ((srcAddr == 9)) {
                              if(!coveragePoints["Data_path_62"]){
                                coveragePoints["Data_path_62"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_62\n";
                              }
                              return(RFtoDP_data.reg_file_09);
                            } else {
                              if(!coveragePoints["Data_path_63"]){
                                coveragePoints["Data_path_63"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_63\n";
                              }
                              if ((srcAddr == 10)) {
                                if(!coveragePoints["Data_path_64"]){
                                  coveragePoints["Data_path_64"] = true;
                                  coveragePointsCount++;
                                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_64\n";
                                }
                                return(RFtoDP_data.reg_file_10);
                              } else {
                                if(!coveragePoints["Data_path_65"]){
                                  coveragePoints["Data_path_65"] = true;
                                  coveragePointsCount++;
                                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_65\n";
                                }
                                if ((srcAddr == 11)) {
                                  if(!coveragePoints["Data_path_66"]){
                                    coveragePoints["Data_path_66"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_66\n";
                                  }
                                  return(RFtoDP_data.reg_file_11);
                                } else {
                                  if(!coveragePoints["Data_path_67"]){
                                    coveragePoints["Data_path_67"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_67\n";
                                  }
                                  if ((srcAddr == 12)) {
                                    if(!coveragePoints["Data_path_68"]){
                                      coveragePoints["Data_path_68"] = true;
                                      coveragePointsCount++;
                                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_68\n";
                                    }
                                    return(RFtoDP_data.reg_file_12);
                                  } else {
                                    if(!coveragePoints["Data_path_69"]){
                                      coveragePoints["Data_path_69"] = true;
                                      coveragePointsCount++;
                                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_69\n";
                                    }
                                    if ((srcAddr == 13)) {
                                      if(!coveragePoints["Data_path_70"]){
                                        coveragePoints["Data_path_70"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_70\n";
                                      }
                                      return(RFtoDP_data.reg_file_13);
                                    } else {
                                      if(!coveragePoints["Data_path_71"]){
                                        coveragePoints["Data_path_71"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_71\n";
                                      }
                                      if ((srcAddr == 14)) {
                                        if(!coveragePoints["Data_path_72"]){
                                          coveragePoints["Data_path_72"] = true;
                                          coveragePointsCount++;
                                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_72\n";
                                        }
                                        return(RFtoDP_data.reg_file_14);
                                      } else {
                                        if(!coveragePoints["Data_path_73"]){
                                          coveragePoints["Data_path_73"] = true;
                                          coveragePointsCount++;
                                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_73\n";
                                        }
                                        if ((srcAddr == 15)) {
                                          if(!coveragePoints["Data_path_74"]){
                                            coveragePoints["Data_path_74"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_74\n";
                                          }
                                          return(RFtoDP_data.reg_file_15);
                                        } else {
                                          if(!coveragePoints["Data_path_75"]){
                                            coveragePoints["Data_path_75"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_75\n";
                                          }
                                          if ((srcAddr == 16)) {
                                            if(!coveragePoints["Data_path_76"]){
                                              coveragePoints["Data_path_76"] = true;
                                              coveragePointsCount++;
                                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_76\n";
                                            }
                                            return(RFtoDP_data.reg_file_16);
                                          } else {
                                            if(!coveragePoints["Data_path_77"]){
                                              coveragePoints["Data_path_77"] = true;
                                              coveragePointsCount++;
                                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_77\n";
                                            }
                                            if ((srcAddr == 17)) {
                                              if(!coveragePoints["Data_path_78"]){
                                                coveragePoints["Data_path_78"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_78\n";
                                              }
                                              return(RFtoDP_data.reg_file_17);
                                            } else {
                                              if(!coveragePoints["Data_path_79"]){
                                                coveragePoints["Data_path_79"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_79\n";
                                              }
                                              if ((srcAddr == 18)) {
                                                if(!coveragePoints["Data_path_80"]){
                                                  coveragePoints["Data_path_80"] = true;
                                                  coveragePointsCount++;
                                                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_80\n";
                                                }
                                                return(RFtoDP_data.reg_file_18);
                                              } else {
                                                if(!coveragePoints["Data_path_81"]){
                                                  coveragePoints["Data_path_81"] = true;
                                                  coveragePointsCount++;
                                                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_81\n";
                                                }
                                                if ((srcAddr == 19)) {
                                                  if(!coveragePoints["Data_path_82"]){
                                                    coveragePoints["Data_path_82"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_82\n";
                                                  }
                                                  return(RFtoDP_data.reg_file_19);
                                                } else {
                                                  if(!coveragePoints["Data_path_83"]){
                                                    coveragePoints["Data_path_83"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_83\n";
                                                  }
                                                  if ((srcAddr == 20)) {
                                                    if(!coveragePoints["Data_path_84"]){
                                                      coveragePoints["Data_path_84"] = true;
                                                      coveragePointsCount++;
                                                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_84\n";
                                                    }
                                                    return(RFtoDP_data.reg_file_20);
                                                  } else {
                                                    if(!coveragePoints["Data_path_85"]){
                                                      coveragePoints["Data_path_85"] = true;
                                                      coveragePointsCount++;
                                                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_85\n";
                                                    }
                                                    if ((srcAddr == 21)) {
                                                      if(!coveragePoints["Data_path_86"]){
                                                        coveragePoints["Data_path_86"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_86\n";
                                                      }
                                                      return(RFtoDP_data.reg_file_21);
                                                    } else {
                                                      if(!coveragePoints["Data_path_87"]){
                                                        coveragePoints["Data_path_87"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_87\n";
                                                      }
                                                      if ((srcAddr == 22)) {
                                                        if(!coveragePoints["Data_path_88"]){
                                                          coveragePoints["Data_path_88"] = true;
                                                          coveragePointsCount++;
                                                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_88\n";
                                                        }
                                                        return(RFtoDP_data.reg_file_22);
                                                      } else {
                                                        if(!coveragePoints["Data_path_89"]){
                                                          coveragePoints["Data_path_89"] = true;
                                                          coveragePointsCount++;
                                                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_89\n";
                                                        }
                                                        if ((srcAddr == 23)) {
                                                          if(!coveragePoints["Data_path_90"]){
                                                            coveragePoints["Data_path_90"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_90\n";
                                                          }
                                                          return(RFtoDP_data.reg_file_23);
                                                        } else {
                                                          if(!coveragePoints["Data_path_91"]){
                                                            coveragePoints["Data_path_91"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_91\n";
                                                          }
                                                          if ((srcAddr == 24)) {
                                                            if(!coveragePoints["Data_path_92"]){
                                                              coveragePoints["Data_path_92"] = true;
                                                              coveragePointsCount++;
                                                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_92\n";
                                                            }
                                                            return(RFtoDP_data.reg_file_24);
                                                          } else {
                                                            if(!coveragePoints["Data_path_93"]){
                                                              coveragePoints["Data_path_93"] = true;
                                                              coveragePointsCount++;
                                                              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_93\n";
                                                            }
                                                            if ((srcAddr == 25)) {
                                                              if(!coveragePoints["Data_path_94"]){
                                                                coveragePoints["Data_path_94"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_94\n";
                                                              }
                                                              return(RFtoDP_data.reg_file_25);
                                                            } else {
                                                              if(!coveragePoints["Data_path_95"]){
                                                                coveragePoints["Data_path_95"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_95\n";
                                                              }
                                                              if ((srcAddr == 26)) {
                                                                if(!coveragePoints["Data_path_96"]){
                                                                  coveragePoints["Data_path_96"] = true;
                                                                  coveragePointsCount++;
                                                                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_96\n";
                                                                }
                                                                return(RFtoDP_data.reg_file_26);
                                                              } else {
                                                                if(!coveragePoints["Data_path_97"]){
                                                                  coveragePoints["Data_path_97"] = true;
                                                                  coveragePointsCount++;
                                                                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_97\n";
                                                                }
                                                                if ((srcAddr == 27)) {
                                                                  if(!coveragePoints["Data_path_98"]){
                                                                    coveragePoints["Data_path_98"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_98\n";
                                                                  }
                                                                  return(RFtoDP_data.reg_file_27);
                                                                } else {
                                                                  if(!coveragePoints["Data_path_99"]){
                                                                    coveragePoints["Data_path_99"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_99\n";
                                                                  }
                                                                  if ((srcAddr == 28)) {
                                                                    if(!coveragePoints["Data_path_100"]){
                                                                      coveragePoints["Data_path_100"] = true;
                                                                      coveragePointsCount++;
                                                                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_100\n";
                                                                    }
                                                                    return(RFtoDP_data.reg_file_28);
                                                                  } else {
                                                                    if(!coveragePoints["Data_path_101"]){
                                                                      coveragePoints["Data_path_101"] = true;
                                                                      coveragePointsCount++;
                                                                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_101\n";
                                                                    }
                                                                    if ((srcAddr == 29)) {
                                                                      if(!coveragePoints["Data_path_102"]){
                                                                        coveragePoints["Data_path_102"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_102\n";
                                                                      }
                                                                      return(RFtoDP_data.reg_file_29);
                                                                    } else {
                                                                      if(!coveragePoints["Data_path_103"]){
                                                                        coveragePoints["Data_path_103"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_103\n";
                                                                      }
                                                                      if ((srcAddr == 30)) {
                                                                        if(!coveragePoints["Data_path_104"]){
                                                                          coveragePoints["Data_path_104"] = true;
                                                                          coveragePointsCount++;
                                                                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_104\n";
                                                                        }
                                                                        return(RFtoDP_data.reg_file_30);
                                                                      } else {
                                                                        if(!coveragePoints["Data_path_105"]){
                                                                          coveragePoints["Data_path_105"] = true;
                                                                          coveragePointsCount++;
                                                                          std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_105\n";
                                                                        }
                                                                        return(RFtoDP_data.reg_file_31);
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
          if(!coveragePoints["Data_path_106"]){
            coveragePoints["Data_path_106"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_106\n";
          }
          return(0);
        }
      }

      unsigned getWBdata(unsigned aluResult_s5, unsigned loadedData, unsigned pc_s5, RF_WriteDataSelType wbSel_s5) {
        if ((wbSel_s5 == WB_ALU)) {
          if(!coveragePoints["Data_path_107"]){
            coveragePoints["Data_path_107"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_107\n";
          }
          return(aluResult_s5);
        } else {
          if(!coveragePoints["Data_path_108"]){
            coveragePoints["Data_path_108"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_108\n";
          }
          if ((wbSel_s5 == WB_MEM)) {
            if(!coveragePoints["Data_path_109"]){
              coveragePoints["Data_path_109"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_109\n";
            }
            return(loadedData);
          } else {
            if(!coveragePoints["Data_path_110"]){
              coveragePoints["Data_path_110"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_110\n";
            }
            if ((wbSel_s5 == WB_PC4)) {
              if(!coveragePoints["Data_path_111"]){
                coveragePoints["Data_path_111"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_111\n";
              }
              return((pc_s5 + 4));
            } else {
              if(!coveragePoints["Data_path_112"]){
                coveragePoints["Data_path_112"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_112\n";
              }
              return(0);
            }
          }
        }
      }

      unsigned regContentFwdUnit(unsigned aluResult_s4, unsigned aluResult_s5, unsigned dstAddr_s4, unsigned dstAddr_s5, EncType encType_s4, EncType encType_s5, unsigned loadedData, unsigned pc_s4, unsigned pc_s5, unsigned regContent, unsigned srcAddr) {
        if ((srcAddr == 0)) {
          if(!coveragePoints["Data_path_113"]){
            coveragePoints["Data_path_113"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_113\n";
          }
          return(0);
        } else {
          if(!coveragePoints["Data_path_114"]){
            coveragePoints["Data_path_114"] = true;
            coveragePointsCount++;
            std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_114\n";
          }
          if ((((srcAddr == dstAddr_s5) and (encType_s5 == ENC_I_L)) and (srcAddr != dstAddr_s4))) {
            if(!coveragePoints["Data_path_115"]){
              coveragePoints["Data_path_115"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_115\n";
            }
            return(loadedData);
          } else {
            if(!coveragePoints["Data_path_116"]){
              coveragePoints["Data_path_116"] = true;
              coveragePointsCount++;
              std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_116\n";
            }
            if (((srcAddr == dstAddr_s5) and ((encType_s5 == ENC_I_J) or (encType_s5 == ENC_J)))) {
              if(!coveragePoints["Data_path_117"]){
                coveragePoints["Data_path_117"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_117\n";
              }
              return((pc_s5 + 4));
            } else {
              if(!coveragePoints["Data_path_118"]){
                coveragePoints["Data_path_118"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_118\n";
              }
              if (((srcAddr == dstAddr_s4) and (encType_s4 == ENC_J))) {
                if(!coveragePoints["Data_path_119"]){
                  coveragePoints["Data_path_119"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_119\n";
                }
                return((pc_s4 + 4));
              } else {
                if(!coveragePoints["Data_path_120"]){
                  coveragePoints["Data_path_120"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_120\n";
                }
                if ((srcAddr == dstAddr_s4)) {
                  if(!coveragePoints["Data_path_121"]){
                    coveragePoints["Data_path_121"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_121\n";
                  }
                  return(aluResult_s4);
                } else {
                  if(!coveragePoints["Data_path_122"]){
                    coveragePoints["Data_path_122"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_122\n";
                  }
                  if ((srcAddr == dstAddr_s5)) {
                    if(!coveragePoints["Data_path_123"]){
                      coveragePoints["Data_path_123"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_123\n";
                    }
                    return(aluResult_s5);
                  } else {
                    if(!coveragePoints["Data_path_124"]){
                      coveragePoints["Data_path_124"] = true;
                      coveragePointsCount++;
                      std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_124\n";
                    }
                    return(regContent);
                  }
                }
              }
            }
          }
        }
      }


      CUtoDP_IF CUtoDP_data;
      DP_S3 DP_S3_data;
      DP_S4 DP_S4_data;
      DP_S5 DP_S5_data;
      DPtoAL_IF DPtoAL_data;
      DPtoCU_IF DPtoCU_data;
      DPtoRF_IF DPtoRF_data;
      RFtoDP_IF RFtoDP_data;
      bool rec;
      unsigned reg1Content;
      unsigned reg2Content;


      void FSM(){
          while(true) {
            if (section==executeStage) {
              if(!coveragePoints["Data_path_125"]){
                coveragePoints["Data_path_125"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_125\n";
              }
              DPtoAL_data.aluFunc = CUtoDP_data.aluFunc_s3;
              DPtoAL_data.aluOp1 = getALUoperand(aluOpFwdUnit(DP_S4_data.aluResult_s4,DP_S4_data.regRdAddr_s4,DP_S5_data.regRdAddr_s5,DP_S5_data.encType_s5,CUtoDP_data.loadedData,DP_S3_data.reg1Content_s3,DP_S3_data.regRs1Addr_s3),CUtoDP_data.aluOp1Sel_s3,CUtoDP_data.imm_s3,DP_S3_data.pc_s3);
              DPtoAL_data.aluOp2 = getALUoperand(aluOpFwdUnit(DP_S4_data.aluResult_s4,DP_S4_data.regRdAddr_s4,DP_S5_data.regRdAddr_s5,DP_S5_data.encType_s5,CUtoDP_data.loadedData,DP_S3_data.reg2Content_s3,DP_S3_data.regRs2Addr_s3),CUtoDP_data.aluOp2Sel_s3,CUtoDP_data.imm_s3,DP_S3_data.pc_s3);
              section = memoryStage;
            }
            else if (section==memoryStage) {
              if(!coveragePoints["Data_path_126"]){
                coveragePoints["Data_path_126"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_126\n";
              }
              if ((CUtoDP_data.dmemReq_s4 == ME_RD)) {
                if(!coveragePoints["Data_path_127"]){
                  coveragePoints["Data_path_127"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_127\n";
                }
                DPtoCU_data.req = CUtoDP_data.dmemReq_s4;
                DPtoCU_data.mask = CUtoDP_data.dmemMask_s4;
                DPtoCU_data.addrIn = DP_S4_data.aluResult_s4;
                DPtoCU_data.dataIn = 0;
              } else {
                if(!coveragePoints["Data_path_128"]){
                  coveragePoints["Data_path_128"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_128\n";
                }
                if ((CUtoDP_data.dmemReq_s4 == ME_WR)) {
                  if(!coveragePoints["Data_path_129"]){
                    coveragePoints["Data_path_129"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_129\n";
                  }
                  DPtoCU_data.req = CUtoDP_data.dmemReq_s4;
                  DPtoCU_data.mask = CUtoDP_data.dmemMask_s4;
                  DPtoCU_data.addrIn = DP_S4_data.aluResult_s4;
                  DPtoCU_data.dataIn = dmemDataInFwdUnit(DP_S5_data.aluResult_s5,DP_S5_data.regRdAddr_s5,DP_S5_data.encType_s5,DP_S4_data.fwdPrevLoadedData,CUtoDP_data.loadedData,DP_S4_data.prevLoadedData,DP_S4_data.reg2Content_s4,DP_S4_data.regRs2Addr_s4);
                } else {
                  if(!coveragePoints["Data_path_130"]){
                    coveragePoints["Data_path_130"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_130\n";
                  }
                  DPtoCU_data.req = ME_X;
                  DPtoCU_data.mask = MT_X;
                  DPtoCU_data.addrIn = 0;
                  DPtoCU_data.dataIn = 0;
                }
              }
              if (((((CUtoDP_data.prevDmemAccess and (DP_S3_data.encType_s3 == ENC_S)) and (DP_S5_data.encType_s5 == ENC_I_L)) and (DP_S3_data.regRs2Addr_s3 == DP_S5_data.regRdAddr_s5)) and (DP_S5_data.regRdAddr_s5 != 0))) {
                if(!coveragePoints["Data_path_131"]){
                  coveragePoints["Data_path_131"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_131\n";
                }
                DP_S4_data.fwdPrevLoadedData = true;
                DP_S4_data.prevLoadedData = CUtoDP_data.loadedData;
              } else {
                if(!coveragePoints["Data_path_132"]){
                  coveragePoints["Data_path_132"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_132\n";
                }
                if ((DP_S4_data.fwdPrevLoadedData and CUtoDP_data.stallDmemAccess)) {
                  if(!coveragePoints["Data_path_133"]){
                    coveragePoints["Data_path_133"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_133\n";
                  }
                  DP_S4_data.fwdPrevLoadedData = true;
                } else {
                  if(!coveragePoints["Data_path_134"]){
                    coveragePoints["Data_path_134"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_134\n";
                  }
                  DP_S4_data.fwdPrevLoadedData = false;
                }
              }
              section = writeBackStage;
            }
            else if (section==readRegFileStage) {
              if(!coveragePoints["Data_path_135"]){
                coveragePoints["Data_path_135"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_135\n";
              }
              DPtoCU_port->nb_write(DPtoCU_data);
              rec = CUtoDP_port->nb_read(CUtoDP_data);
              if (rec) {
                if(!coveragePoints["Data_path_136"]){
                  coveragePoints["Data_path_136"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_136\n";
                }
                RFtoDP_port->read(RFtoDP_data);
                reg1Content = regContentFwdUnit(DP_S4_data.aluResult_s4,DP_S5_data.aluResult_s5,DP_S4_data.regRdAddr_s4,DP_S5_data.regRdAddr_s5,DP_S4_data.encType_s4,DP_S5_data.encType_s5,CUtoDP_data.loadedData,DP_S4_data.pc_s4,DP_S5_data.pc_s5,getRegContent(RFtoDP_data,CUtoDP_data.regFileReq_s2,CUtoDP_data.regRs1Addr_s2),CUtoDP_data.regRs1Addr_s2);
                reg2Content = regContentFwdUnit(DP_S4_data.aluResult_s4,DP_S5_data.aluResult_s5,DP_S4_data.regRdAddr_s4,DP_S5_data.regRdAddr_s5,DP_S4_data.encType_s4,DP_S5_data.encType_s5,CUtoDP_data.loadedData,DP_S4_data.pc_s4,DP_S5_data.pc_s5,getRegContent(RFtoDP_data,CUtoDP_data.regFileReq_s2,CUtoDP_data.regRs2Addr_s2),CUtoDP_data.regRs2Addr_s2);
                DPtoCU_data.reg1Content = reg1Content;
                DPtoCU_data.reg2Content = reg2Content;
                section = executeStage;
              }
            }
            else if (section==setPipelineSignals) {
              if(!coveragePoints["Data_path_137"]){
                coveragePoints["Data_path_137"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_137\n";
              }
              if (not(CUtoDP_data.stallDmemAccess)) {
                if(!coveragePoints["Data_path_138"]){
                  coveragePoints["Data_path_138"] = true;
                  coveragePointsCount++;
                  std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_138\n";
                }
                DP_S5_data.pc_s5 = DP_S4_data.pc_s4;
                DP_S5_data.encType_s5 = DP_S4_data.encType_s4;
                DP_S5_data.regRdAddr_s5 = DP_S4_data.regRdAddr_s4;
                DP_S5_data.aluResult_s5 = DP_S4_data.aluResult_s4;
                DP_S4_data.pc_s4 = DP_S3_data.pc_s3;
                DP_S4_data.encType_s4 = DP_S3_data.encType_s3;
                DP_S4_data.regRs2Addr_s4 = DP_S3_data.regRs2Addr_s3;
                DP_S4_data.regRdAddr_s4 = DP_S3_data.regRdAddr_s3;
                DP_S4_data.reg2Content_s4 = DP_S3_data.reg2Content_s3;
                DP_S4_data.aluResult_s4 = getALUresult(DPtoAL_data);
                DP_S3_data.pc_s3 = CUtoDP_data.pc_s2;
                DP_S3_data.encType_s3 = CUtoDP_data.encType_s2;
                DP_S3_data.regRs1Addr_s3 = CUtoDP_data.regRs1Addr_s2;
                DP_S3_data.regRs2Addr_s3 = CUtoDP_data.regRs2Addr_s2;
                DP_S3_data.regRdAddr_s3 = CUtoDP_data.regRdAddr_s2;
                DP_S3_data.reg1Content_s3 = reg1Content;
                DP_S3_data.reg2Content_s3 = reg2Content;
              }
              section = readRegFileStage;
            }
            else if (section==writeBackStage) {
              if(!coveragePoints["Data_path_139"]){
                coveragePoints["Data_path_139"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path " << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%    ------    Data_path_139\n";
              }
              DPtoRF_data.wrReq = CUtoDP_data.regFileReq_s5;
              DPtoRF_data.dst = DP_S5_data.regRdAddr_s5;
              DPtoRF_data.dstData = getWBdata(DP_S5_data.aluResult_s5,CUtoDP_data.loadedData,DP_S5_data.pc_s5,CUtoDP_data.regFileWriteDataSel_s5);
              DPtoRF_port->write(DPtoRF_data);
              section = setPipelineSignals;
            }
            
          }//end of while
      }//end of FSM
      int coveragePointsTotal = 139;
      int coveragePointsCount = 0;
      std::map<std::string, bool> coveragePoints;

      SC_HAS_PROCESS(Data_path);

      Data_path(sc_module_name name) :
        section(readRegFileStage),
        rec(false),
        reg1Content(0),
        reg2Content(0)      {
                SC_THREAD(FSM);
        for(int i = 1; i < coveragePointsTotal; i++)
                coveragePoints.insert(std::make_pair("Data_path_"+to_string(i),false));
        }
      };//end of module


#endif //SYSTEMC_Data_path_H
