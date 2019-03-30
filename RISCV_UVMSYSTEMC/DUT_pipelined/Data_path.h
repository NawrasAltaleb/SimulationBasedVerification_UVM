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
            if(!coveragePoints["Data_path_319"]){
                coveragePoints["Data_path_319"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(loadedData);
        } else {
            if(!coveragePoints["Data_path_320"]){
                coveragePoints["Data_path_320"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((srcAddr_s3 == dstAddr_s4) and (srcAddr_s3 != 0))) {
                if(!coveragePoints["Data_path_321"]){
                    coveragePoints["Data_path_321"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(aluResult_s4);
            } else {
                if(!coveragePoints["Data_path_322"]){
                    coveragePoints["Data_path_322"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(regContent_s3);
            }
        }
    }

    unsigned dmemDataInFwdUnit(unsigned aluResult_s5, unsigned dstAddr_s5, EncType encType_s5, bool fwdPrevLoadedData, unsigned loadedData, unsigned prevLoadedData, unsigned reg2Content_s4, unsigned src2Addr_s4) {
        if ((((src2Addr_s4 == dstAddr_s5) and (encType_s5 == ENC_I_L)) and (src2Addr_s4 != 0))) {
            if(!coveragePoints["Data_path_323"]){
                coveragePoints["Data_path_323"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(loadedData);
        } else {
            if(!coveragePoints["Data_path_324"]){
                coveragePoints["Data_path_324"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if (((src2Addr_s4 == dstAddr_s5) and (src2Addr_s4 != 0))) {
                if(!coveragePoints["Data_path_325"]){
                    coveragePoints["Data_path_325"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(aluResult_s5);
            } else {
                if(!coveragePoints["Data_path_326"]){
                    coveragePoints["Data_path_326"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (fwdPrevLoadedData) {
                    if(!coveragePoints["Data_path_327"]){
                        coveragePoints["Data_path_327"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(prevLoadedData);
                } else {
                    if(!coveragePoints["Data_path_328"]){
                        coveragePoints["Data_path_328"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(reg2Content_s4);
                }
            }
        }
    }

    unsigned getALUoperand(unsigned aluOpFwdUnitValue, AL_OperandSelType aluOpSel_s3, unsigned imm_s3, unsigned pc_s3) {
        if ((aluOpSel_s3 == OP_REG)) {
            if(!coveragePoints["Data_path_329"]){
                coveragePoints["Data_path_329"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(aluOpFwdUnitValue);
        } else {
            if(!coveragePoints["Data_path_330"]){
                coveragePoints["Data_path_330"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((aluOpSel_s3 == OP_IMM)) {
                if(!coveragePoints["Data_path_331"]){
                    coveragePoints["Data_path_331"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(imm_s3);
            } else {
                if(!coveragePoints["Data_path_332"]){
                    coveragePoints["Data_path_332"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((aluOpSel_s3 == OP_PC)) {
                    if(!coveragePoints["Data_path_333"]){
                        coveragePoints["Data_path_333"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(pc_s3);
                } else {
                    if(!coveragePoints["Data_path_334"]){
                        coveragePoints["Data_path_334"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(0);
                }
            }
        }
    }

    unsigned getALUresult(DPtoAL_IF DPtoAL_data) {
        if ((DPtoAL_data.aluFunc == ALU_ADD)) {
            if(!coveragePoints["Data_path_335"]){
                coveragePoints["Data_path_335"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return((DPtoAL_data.aluOp1 + DPtoAL_data.aluOp2));
        } else {
            if(!coveragePoints["Data_path_336"]){
                coveragePoints["Data_path_336"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((DPtoAL_data.aluFunc == ALU_SUB)) {
                if(!coveragePoints["Data_path_337"]){
                    coveragePoints["Data_path_337"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return((DPtoAL_data.aluOp1 + -(DPtoAL_data.aluOp2)));
            } else {
                if(!coveragePoints["Data_path_338"]){
                    coveragePoints["Data_path_338"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((DPtoAL_data.aluFunc == ALU_AND)) {
                    if(!coveragePoints["Data_path_339"]){
                        coveragePoints["Data_path_339"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return((DPtoAL_data.aluOp1 & DPtoAL_data.aluOp2));
                } else {
                    if(!coveragePoints["Data_path_340"]){
                        coveragePoints["Data_path_340"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((DPtoAL_data.aluFunc == ALU_OR)) {
                        if(!coveragePoints["Data_path_341"]){
                            coveragePoints["Data_path_341"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return((DPtoAL_data.aluOp1 | DPtoAL_data.aluOp2));
                    } else {
                        if(!coveragePoints["Data_path_342"]){
                            coveragePoints["Data_path_342"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((DPtoAL_data.aluFunc == ALU_XOR)) {
                            if(!coveragePoints["Data_path_343"]){
                                coveragePoints["Data_path_343"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            return((DPtoAL_data.aluOp1 ^ DPtoAL_data.aluOp2));
                        } else {
                            if(!coveragePoints["Data_path_344"]){
                                coveragePoints["Data_path_344"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            if ((DPtoAL_data.aluFunc == ALU_SLT)) {
                                if(!coveragePoints["Data_path_345"]){
                                    coveragePoints["Data_path_345"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                }
                                if ((static_cast<int>(DPtoAL_data.aluOp1) < static_cast<int>(DPtoAL_data.aluOp2))) {
                                    if(!coveragePoints["Data_path_346"]){
                                        coveragePoints["Data_path_346"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    return(1);
                                } else {
                                    if(!coveragePoints["Data_path_347"]){
                                        coveragePoints["Data_path_347"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    return(0);
                                }
                            } else {
                                if(!coveragePoints["Data_path_348"]){
                                    coveragePoints["Data_path_348"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                }
                                if ((DPtoAL_data.aluFunc == ALU_SLTU)) {
                                    if(!coveragePoints["Data_path_349"]){
                                        coveragePoints["Data_path_349"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    if ((DPtoAL_data.aluOp1 < DPtoAL_data.aluOp2)) {
                                        if(!coveragePoints["Data_path_350"]){
                                            coveragePoints["Data_path_350"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        return(1);
                                    } else {
                                        if(!coveragePoints["Data_path_351"]){
                                            coveragePoints["Data_path_351"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        return(0);
                                    }
                                } else {
                                    if(!coveragePoints["Data_path_352"]){
                                        coveragePoints["Data_path_352"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    if ((DPtoAL_data.aluFunc == ALU_SLL)) {
                                        if(!coveragePoints["Data_path_353"]){
                                            coveragePoints["Data_path_353"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        return((DPtoAL_data.aluOp1 << (DPtoAL_data.aluOp2 & 31)));
                                    } else {
                                        if(!coveragePoints["Data_path_354"]){
                                            coveragePoints["Data_path_354"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        if ((DPtoAL_data.aluFunc == ALU_SRA)) {
                                            if(!coveragePoints["Data_path_355"]){
                                                coveragePoints["Data_path_355"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                            }
                                            return(static_cast<unsigned>((static_cast<int>(DPtoAL_data.aluOp1) >> static_cast<int>((DPtoAL_data.aluOp2 & 31)))));
                                        } else {
                                            if(!coveragePoints["Data_path_356"]){
                                                coveragePoints["Data_path_356"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                            }
                                            if ((DPtoAL_data.aluFunc == ALU_SRL)) {
                                                if(!coveragePoints["Data_path_357"]){
                                                    coveragePoints["Data_path_357"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                }
                                                return((DPtoAL_data.aluOp1 >> (DPtoAL_data.aluOp2 & 31)));
                                            } else {
                                                if(!coveragePoints["Data_path_358"]){
                                                    coveragePoints["Data_path_358"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                }
                                                if ((DPtoAL_data.aluFunc == ALU_COPY1)) {
                                                    if(!coveragePoints["Data_path_359"]){
                                                        coveragePoints["Data_path_359"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                    }
                                                    return(DPtoAL_data.aluOp1);
                                                } else {
                                                    if(!coveragePoints["Data_path_360"]){
                                                        coveragePoints["Data_path_360"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
            if(!coveragePoints["Data_path_361"]){
                coveragePoints["Data_path_361"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((srcAddr == 0)) {
                if(!coveragePoints["Data_path_362"]){
                    coveragePoints["Data_path_362"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(0);
            } else {
                if(!coveragePoints["Data_path_363"]){
                    coveragePoints["Data_path_363"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((srcAddr == 1)) {
                    if(!coveragePoints["Data_path_364"]){
                        coveragePoints["Data_path_364"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(RFtoDP_data.reg_file_01);
                } else {
                    if(!coveragePoints["Data_path_365"]){
                        coveragePoints["Data_path_365"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((srcAddr == 2)) {
                        if(!coveragePoints["Data_path_366"]){
                            coveragePoints["Data_path_366"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return(RFtoDP_data.reg_file_02);
                    } else {
                        if(!coveragePoints["Data_path_367"]){
                            coveragePoints["Data_path_367"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((srcAddr == 3)) {
                            if(!coveragePoints["Data_path_368"]){
                                coveragePoints["Data_path_368"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            return(RFtoDP_data.reg_file_03);
                        } else {
                            if(!coveragePoints["Data_path_369"]){
                                coveragePoints["Data_path_369"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            if ((srcAddr == 4)) {
                                if(!coveragePoints["Data_path_370"]){
                                    coveragePoints["Data_path_370"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                }
                                return(RFtoDP_data.reg_file_04);
                            } else {
                                if(!coveragePoints["Data_path_371"]){
                                    coveragePoints["Data_path_371"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                }
                                if ((srcAddr == 5)) {
                                    if(!coveragePoints["Data_path_372"]){
                                        coveragePoints["Data_path_372"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    return(RFtoDP_data.reg_file_05);
                                } else {
                                    if(!coveragePoints["Data_path_373"]){
                                        coveragePoints["Data_path_373"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    if ((srcAddr == 6)) {
                                        if(!coveragePoints["Data_path_374"]){
                                            coveragePoints["Data_path_374"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        return(RFtoDP_data.reg_file_06);
                                    } else {
                                        if(!coveragePoints["Data_path_375"]){
                                            coveragePoints["Data_path_375"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        if ((srcAddr == 7)) {
                                            if(!coveragePoints["Data_path_376"]){
                                                coveragePoints["Data_path_376"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                            }
                                            return(RFtoDP_data.reg_file_07);
                                        } else {
                                            if(!coveragePoints["Data_path_377"]){
                                                coveragePoints["Data_path_377"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                            }
                                            if ((srcAddr == 8)) {
                                                if(!coveragePoints["Data_path_378"]){
                                                    coveragePoints["Data_path_378"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                }
                                                return(RFtoDP_data.reg_file_08);
                                            } else {
                                                if(!coveragePoints["Data_path_379"]){
                                                    coveragePoints["Data_path_379"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                }
                                                if ((srcAddr == 9)) {
                                                    if(!coveragePoints["Data_path_380"]){
                                                        coveragePoints["Data_path_380"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                    }
                                                    return(RFtoDP_data.reg_file_09);
                                                } else {
                                                    if(!coveragePoints["Data_path_381"]){
                                                        coveragePoints["Data_path_381"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                    }
                                                    if ((srcAddr == 10)) {
                                                        if(!coveragePoints["Data_path_382"]){
                                                            coveragePoints["Data_path_382"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                        }
                                                        return(RFtoDP_data.reg_file_10);
                                                    } else {
                                                        if(!coveragePoints["Data_path_383"]){
                                                            coveragePoints["Data_path_383"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                        }
                                                        if ((srcAddr == 11)) {
                                                            if(!coveragePoints["Data_path_384"]){
                                                                coveragePoints["Data_path_384"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                            }
                                                            return(RFtoDP_data.reg_file_11);
                                                        } else {
                                                            if(!coveragePoints["Data_path_385"]){
                                                                coveragePoints["Data_path_385"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                            }
                                                            if ((srcAddr == 12)) {
                                                                if(!coveragePoints["Data_path_386"]){
                                                                    coveragePoints["Data_path_386"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                }
                                                                return(RFtoDP_data.reg_file_12);
                                                            } else {
                                                                if(!coveragePoints["Data_path_387"]){
                                                                    coveragePoints["Data_path_387"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                }
                                                                if ((srcAddr == 13)) {
                                                                    if(!coveragePoints["Data_path_388"]){
                                                                        coveragePoints["Data_path_388"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                    }
                                                                    return(RFtoDP_data.reg_file_13);
                                                                } else {
                                                                    if(!coveragePoints["Data_path_389"]){
                                                                        coveragePoints["Data_path_389"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                    }
                                                                    if ((srcAddr == 14)) {
                                                                        if(!coveragePoints["Data_path_390"]){
                                                                            coveragePoints["Data_path_390"] = true;
                                                                            coveragePointsCount++;
                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                        }
                                                                        return(RFtoDP_data.reg_file_14);
                                                                    } else {
                                                                        if(!coveragePoints["Data_path_391"]){
                                                                            coveragePoints["Data_path_391"] = true;
                                                                            coveragePointsCount++;
                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                        }
                                                                        if ((srcAddr == 15)) {
                                                                            if(!coveragePoints["Data_path_392"]){
                                                                                coveragePoints["Data_path_392"] = true;
                                                                                coveragePointsCount++;
                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                            }
                                                                            return(RFtoDP_data.reg_file_15);
                                                                        } else {
                                                                            if(!coveragePoints["Data_path_393"]){
                                                                                coveragePoints["Data_path_393"] = true;
                                                                                coveragePointsCount++;
                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                            }
                                                                            if ((srcAddr == 16)) {
                                                                                if(!coveragePoints["Data_path_394"]){
                                                                                    coveragePoints["Data_path_394"] = true;
                                                                                    coveragePointsCount++;
                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                }
                                                                                return(RFtoDP_data.reg_file_16);
                                                                            } else {
                                                                                if(!coveragePoints["Data_path_395"]){
                                                                                    coveragePoints["Data_path_395"] = true;
                                                                                    coveragePointsCount++;
                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                }
                                                                                if ((srcAddr == 17)) {
                                                                                    if(!coveragePoints["Data_path_396"]){
                                                                                        coveragePoints["Data_path_396"] = true;
                                                                                        coveragePointsCount++;
                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                    }
                                                                                    return(RFtoDP_data.reg_file_17);
                                                                                } else {
                                                                                    if(!coveragePoints["Data_path_397"]){
                                                                                        coveragePoints["Data_path_397"] = true;
                                                                                        coveragePointsCount++;
                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                    }
                                                                                    if ((srcAddr == 18)) {
                                                                                        if(!coveragePoints["Data_path_398"]){
                                                                                            coveragePoints["Data_path_398"] = true;
                                                                                            coveragePointsCount++;
                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                        }
                                                                                        return(RFtoDP_data.reg_file_18);
                                                                                    } else {
                                                                                        if(!coveragePoints["Data_path_399"]){
                                                                                            coveragePoints["Data_path_399"] = true;
                                                                                            coveragePointsCount++;
                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                        }
                                                                                        if ((srcAddr == 19)) {
                                                                                            if(!coveragePoints["Data_path_400"]){
                                                                                                coveragePoints["Data_path_400"] = true;
                                                                                                coveragePointsCount++;
                                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                            }
                                                                                            return(RFtoDP_data.reg_file_19);
                                                                                        } else {
                                                                                            if(!coveragePoints["Data_path_401"]){
                                                                                                coveragePoints["Data_path_401"] = true;
                                                                                                coveragePointsCount++;
                                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                            }
                                                                                            if ((srcAddr == 20)) {
                                                                                                if(!coveragePoints["Data_path_402"]){
                                                                                                    coveragePoints["Data_path_402"] = true;
                                                                                                    coveragePointsCount++;
                                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                }
                                                                                                return(RFtoDP_data.reg_file_20);
                                                                                            } else {
                                                                                                if(!coveragePoints["Data_path_403"]){
                                                                                                    coveragePoints["Data_path_403"] = true;
                                                                                                    coveragePointsCount++;
                                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                }
                                                                                                if ((srcAddr == 21)) {
                                                                                                    if(!coveragePoints["Data_path_404"]){
                                                                                                        coveragePoints["Data_path_404"] = true;
                                                                                                        coveragePointsCount++;
                                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                    }
                                                                                                    return(RFtoDP_data.reg_file_21);
                                                                                                } else {
                                                                                                    if(!coveragePoints["Data_path_405"]){
                                                                                                        coveragePoints["Data_path_405"] = true;
                                                                                                        coveragePointsCount++;
                                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                    }
                                                                                                    if ((srcAddr == 22)) {
                                                                                                        if(!coveragePoints["Data_path_406"]){
                                                                                                            coveragePoints["Data_path_406"] = true;
                                                                                                            coveragePointsCount++;
                                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                        }
                                                                                                        return(RFtoDP_data.reg_file_22);
                                                                                                    } else {
                                                                                                        if(!coveragePoints["Data_path_407"]){
                                                                                                            coveragePoints["Data_path_407"] = true;
                                                                                                            coveragePointsCount++;
                                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                        }
                                                                                                        if ((srcAddr == 23)) {
                                                                                                            if(!coveragePoints["Data_path_408"]){
                                                                                                                coveragePoints["Data_path_408"] = true;
                                                                                                                coveragePointsCount++;
                                                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                            }
                                                                                                            return(RFtoDP_data.reg_file_23);
                                                                                                        } else {
                                                                                                            if(!coveragePoints["Data_path_409"]){
                                                                                                                coveragePoints["Data_path_409"] = true;
                                                                                                                coveragePointsCount++;
                                                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                            }
                                                                                                            if ((srcAddr == 24)) {
                                                                                                                if(!coveragePoints["Data_path_410"]){
                                                                                                                    coveragePoints["Data_path_410"] = true;
                                                                                                                    coveragePointsCount++;
                                                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                }
                                                                                                                return(RFtoDP_data.reg_file_24);
                                                                                                            } else {
                                                                                                                if(!coveragePoints["Data_path_411"]){
                                                                                                                    coveragePoints["Data_path_411"] = true;
                                                                                                                    coveragePointsCount++;
                                                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                }
                                                                                                                if ((srcAddr == 25)) {
                                                                                                                    if(!coveragePoints["Data_path_412"]){
                                                                                                                        coveragePoints["Data_path_412"] = true;
                                                                                                                        coveragePointsCount++;
                                                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                    }
                                                                                                                    return(RFtoDP_data.reg_file_25);
                                                                                                                } else {
                                                                                                                    if(!coveragePoints["Data_path_413"]){
                                                                                                                        coveragePoints["Data_path_413"] = true;
                                                                                                                        coveragePointsCount++;
                                                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                    }
                                                                                                                    if ((srcAddr == 26)) {
                                                                                                                        if(!coveragePoints["Data_path_414"]){
                                                                                                                            coveragePoints["Data_path_414"] = true;
                                                                                                                            coveragePointsCount++;
                                                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                        }
                                                                                                                        return(RFtoDP_data.reg_file_26);
                                                                                                                    } else {
                                                                                                                        if(!coveragePoints["Data_path_415"]){
                                                                                                                            coveragePoints["Data_path_415"] = true;
                                                                                                                            coveragePointsCount++;
                                                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                        }
                                                                                                                        if ((srcAddr == 27)) {
                                                                                                                            if(!coveragePoints["Data_path_416"]){
                                                                                                                                coveragePoints["Data_path_416"] = true;
                                                                                                                                coveragePointsCount++;
                                                                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                            }
                                                                                                                            return(RFtoDP_data.reg_file_27);
                                                                                                                        } else {
                                                                                                                            if(!coveragePoints["Data_path_417"]){
                                                                                                                                coveragePoints["Data_path_417"] = true;
                                                                                                                                coveragePointsCount++;
                                                                                                                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                            }
                                                                                                                            if ((srcAddr == 28)) {
                                                                                                                                if(!coveragePoints["Data_path_418"]){
                                                                                                                                    coveragePoints["Data_path_418"] = true;
                                                                                                                                    coveragePointsCount++;
                                                                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                }
                                                                                                                                return(RFtoDP_data.reg_file_28);
                                                                                                                            } else {
                                                                                                                                if(!coveragePoints["Data_path_419"]){
                                                                                                                                    coveragePoints["Data_path_419"] = true;
                                                                                                                                    coveragePointsCount++;
                                                                                                                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                }
                                                                                                                                if ((srcAddr == 29)) {
                                                                                                                                    if(!coveragePoints["Data_path_420"]){
                                                                                                                                        coveragePoints["Data_path_420"] = true;
                                                                                                                                        coveragePointsCount++;
                                                                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                    }
                                                                                                                                    return(RFtoDP_data.reg_file_29);
                                                                                                                                } else {
                                                                                                                                    if(!coveragePoints["Data_path_421"]){
                                                                                                                                        coveragePoints["Data_path_421"] = true;
                                                                                                                                        coveragePointsCount++;
                                                                                                                                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                    }
                                                                                                                                    if ((srcAddr == 30)) {
                                                                                                                                        if(!coveragePoints["Data_path_422"]){
                                                                                                                                            coveragePoints["Data_path_422"] = true;
                                                                                                                                            coveragePointsCount++;
                                                                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                        }
                                                                                                                                        return(RFtoDP_data.reg_file_30);
                                                                                                                                    } else {
                                                                                                                                        if(!coveragePoints["Data_path_423"]){
                                                                                                                                            coveragePoints["Data_path_423"] = true;
                                                                                                                                            coveragePointsCount++;
                                                                                                                                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
            if(!coveragePoints["Data_path_424"]){
                coveragePoints["Data_path_424"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(0);
        }
    }

    unsigned getWBdata(unsigned aluResult_s5, unsigned loadedData, unsigned pc_s5, RF_WriteDataSelType wbSel_s5) {
        if ((wbSel_s5 == WB_ALU)) {
            if(!coveragePoints["Data_path_425"]){
                coveragePoints["Data_path_425"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(aluResult_s5);
        } else {
            if(!coveragePoints["Data_path_426"]){
                coveragePoints["Data_path_426"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((wbSel_s5 == WB_MEM)) {
                if(!coveragePoints["Data_path_427"]){
                    coveragePoints["Data_path_427"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(loadedData);
            } else {
                if(!coveragePoints["Data_path_428"]){
                    coveragePoints["Data_path_428"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((wbSel_s5 == WB_PC4)) {
                    if(!coveragePoints["Data_path_429"]){
                        coveragePoints["Data_path_429"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return((pc_s5 + 4));
                } else {
                    if(!coveragePoints["Data_path_430"]){
                        coveragePoints["Data_path_430"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return(0);
                }
            }
        }
    }

    unsigned regContentFwdUnit(unsigned aluResult_s4, unsigned aluResult_s5, unsigned dstAddr_s4, unsigned dstAddr_s5, EncType encType_s4, EncType encType_s5, unsigned loadedData, unsigned pc_s4, unsigned pc_s5, unsigned regContent, unsigned srcAddr) {
        if ((srcAddr == 0)) {
            if(!coveragePoints["Data_path_431"]){
                coveragePoints["Data_path_431"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            return(0);
        } else {
            if(!coveragePoints["Data_path_432"]){
                coveragePoints["Data_path_432"] = true;
                coveragePointsCount++;
                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
            }
            if ((((srcAddr == dstAddr_s5) and (encType_s5 == ENC_I_L)) and (srcAddr != dstAddr_s4))) {
                if(!coveragePoints["Data_path_433"]){
                    coveragePoints["Data_path_433"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                return(loadedData);
            } else {
                if(!coveragePoints["Data_path_434"]){
                    coveragePoints["Data_path_434"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (((srcAddr == dstAddr_s5) and ((encType_s5 == ENC_I_J) or (encType_s5 == ENC_J)))) {
                    if(!coveragePoints["Data_path_435"]){
                        coveragePoints["Data_path_435"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    return((pc_s5 + 4));
                } else {
                    if(!coveragePoints["Data_path_436"]){
                        coveragePoints["Data_path_436"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if (((srcAddr == dstAddr_s4) and (encType_s4 == ENC_J))) {
                        if(!coveragePoints["Data_path_437"]){
                            coveragePoints["Data_path_437"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        return((pc_s4 + 4));
                    } else {
                        if(!coveragePoints["Data_path_438"]){
                            coveragePoints["Data_path_438"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((srcAddr == dstAddr_s4)) {
                            if(!coveragePoints["Data_path_439"]){
                                coveragePoints["Data_path_439"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            return(aluResult_s4);
                        } else {
                            if(!coveragePoints["Data_path_440"]){
                                coveragePoints["Data_path_440"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            if ((srcAddr == dstAddr_s5)) {
                                if(!coveragePoints["Data_path_441"]){
                                    coveragePoints["Data_path_441"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                }
                                return(aluResult_s5);
                            } else {
                                if(!coveragePoints["Data_path_442"]){
                                    coveragePoints["Data_path_442"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
                if(!coveragePoints["Data_path_443"]){
                    coveragePoints["Data_path_443"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                DPtoAL_data.aluFunc = CUtoDP_data.aluFunc_s3;
                DPtoAL_data.aluOp1 = getALUoperand(aluOpFwdUnit(DP_S4_data.aluResult_s4,DP_S4_data.regRdAddr_s4,DP_S5_data.regRdAddr_s5,DP_S5_data.encType_s5,CUtoDP_data.loadedData,DP_S3_data.reg1Content_s3,DP_S3_data.regRs1Addr_s3),CUtoDP_data.aluOp1Sel_s3,CUtoDP_data.imm_s3,DP_S3_data.pc_s3);
                DPtoAL_data.aluOp2 = getALUoperand(aluOpFwdUnit(DP_S4_data.aluResult_s4,DP_S4_data.regRdAddr_s4,DP_S5_data.regRdAddr_s5,DP_S5_data.encType_s5,CUtoDP_data.loadedData,DP_S3_data.reg2Content_s3,DP_S3_data.regRs2Addr_s3),CUtoDP_data.aluOp2Sel_s3,CUtoDP_data.imm_s3,DP_S3_data.pc_s3);
                section = memoryStage;
            }
            else if (section==memoryStage) {
                if(!coveragePoints["Data_path_444"]){
                    coveragePoints["Data_path_444"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if ((CUtoDP_data.dmemReq_s4 == ME_RD)) {
                    if(!coveragePoints["Data_path_445"]){
                        coveragePoints["Data_path_445"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    DPtoCU_data.req = CUtoDP_data.dmemReq_s4;
                    DPtoCU_data.mask = CUtoDP_data.dmemMask_s4;
                    DPtoCU_data.addrIn = DP_S4_data.aluResult_s4;
                    DPtoCU_data.dataIn = 0;
                } else {
                    if(!coveragePoints["Data_path_446"]){
                        coveragePoints["Data_path_446"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((CUtoDP_data.dmemReq_s4 == ME_WR)) {
                        if(!coveragePoints["Data_path_447"]){
                            coveragePoints["Data_path_447"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        DPtoCU_data.req = CUtoDP_data.dmemReq_s4;
                        DPtoCU_data.mask = CUtoDP_data.dmemMask_s4;
                        DPtoCU_data.addrIn = DP_S4_data.aluResult_s4;
                        DPtoCU_data.dataIn = dmemDataInFwdUnit(DP_S5_data.aluResult_s5,DP_S5_data.regRdAddr_s5,DP_S5_data.encType_s5,DP_S4_data.fwdPrevLoadedData,CUtoDP_data.loadedData,DP_S4_data.prevLoadedData,DP_S4_data.reg2Content_s4,DP_S4_data.regRs2Addr_s4);
                    } else {
                        if(!coveragePoints["Data_path_448"]){
                            coveragePoints["Data_path_448"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        DPtoCU_data.req = ME_X;
                        DPtoCU_data.mask = MT_X;
                        DPtoCU_data.addrIn = 0;
                        DPtoCU_data.dataIn = 0;
                    }
                }
                if (((((CUtoDP_data.prevDmemAccess and (DP_S3_data.encType_s3 == ENC_S)) and (DP_S5_data.encType_s5 == ENC_I_L)) and (DP_S3_data.regRs2Addr_s3 == DP_S5_data.regRdAddr_s5)) and (DP_S5_data.regRdAddr_s5 != 0))) {
                    if(!coveragePoints["Data_path_449"]){
                        coveragePoints["Data_path_449"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    DP_S4_data.fwdPrevLoadedData = true;
                    DP_S4_data.prevLoadedData = CUtoDP_data.loadedData;
                } else {
                    if(!coveragePoints["Data_path_450"]){
                        coveragePoints["Data_path_450"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if ((DP_S4_data.fwdPrevLoadedData and CUtoDP_data.stallDmemAccess)) {
                        if(!coveragePoints["Data_path_451"]){
                            coveragePoints["Data_path_451"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        DP_S4_data.fwdPrevLoadedData = true;
                    } else {
                        if(!coveragePoints["Data_path_452"]){
                            coveragePoints["Data_path_452"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        DP_S4_data.fwdPrevLoadedData = false;
                    }
                }
                section = writeBackStage;
            }
            else if (section==readRegFileStage) {
                if(!coveragePoints["Data_path_453"]){
                    coveragePoints["Data_path_453"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                DPtoCU_port->nb_write(DPtoCU_data);
                rec = CUtoDP_port->nb_read(CUtoDP_data);
                if (rec) {
                    if(!coveragePoints["Data_path_454"]){
                        coveragePoints["Data_path_454"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
                if(!coveragePoints["Data_path_455"]){
                    coveragePoints["Data_path_455"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                if (not(CUtoDP_data.stallDmemAccess)) {
                    if(!coveragePoints["Data_path_456"]){
                        coveragePoints["Data_path_456"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
                if(!coveragePoints["Data_path_457"]){
                    coveragePoints["Data_path_457"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Data_path" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                }
                DPtoRF_data.wrReq = CUtoDP_data.regFileReq_s5;
                DPtoRF_data.dst = DP_S5_data.regRdAddr_s5;
                DPtoRF_data.dstData = getWBdata(DP_S5_data.aluResult_s5,CUtoDP_data.loadedData,DP_S5_data.pc_s5,CUtoDP_data.regFileWriteDataSel_s5);
                DPtoRF_port->write(DPtoRF_data);
                section = setPipelineSignals;
            }
            wait(SC_ZERO_TIME);
        }//end of while
    }//end of FSM
    int coveragePointsTotal = 457;
    int coveragePointsCount = 0;
    std::map<std::string, bool> coveragePoints;

    SC_HAS_PROCESS(Data_path);

    Data_path(sc_module_name name) :
            section(readRegFileStage),
            rec(false),
            reg1Content(0),
            reg2Content(0)    {
        SC_THREAD(FSM);
        for(int i = 1; i < coveragePointsTotal; i++)
            coveragePoints.insert(std::make_pair("Data_path_"+to_string(i),false));
    }
};//end of module


#endif //SYSTEMC_Data_path_H
