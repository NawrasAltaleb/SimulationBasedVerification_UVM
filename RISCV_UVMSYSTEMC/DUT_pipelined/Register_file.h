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
                if(!coveragePoints["Register_file_458"]){
                    coveragePoints["Register_file_458"] = true;
                    coveragePointsCount++;
                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
                    if(!coveragePoints["Register_file_459"]){
                        coveragePoints["Register_file_459"] = true;
                        coveragePointsCount++;
                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                    }
                    if (((DPtoRF_data.wrReq == RF_WR) and (DPtoRF_data.dst != 0))) {
                        if(!coveragePoints["Register_file_460"]){
                            coveragePoints["Register_file_460"] = true;
                            coveragePointsCount++;
                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                        }
                        if ((DPtoRF_data.dst == 1)) {
                            if(!coveragePoints["Register_file_461"]){
                                coveragePoints["Register_file_461"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            reg_file_01 = DPtoRF_data.dstData;
                        } else {
                            if(!coveragePoints["Register_file_462"]){
                                coveragePoints["Register_file_462"] = true;
                                coveragePointsCount++;
                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                            }
                            if ((DPtoRF_data.dst == 2)) {
                                if(!coveragePoints["Register_file_463"]){
                                    coveragePoints["Register_file_463"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                }
                                reg_file_02 = DPtoRF_data.dstData;
                            } else {
                                if(!coveragePoints["Register_file_464"]){
                                    coveragePoints["Register_file_464"] = true;
                                    coveragePointsCount++;
                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                }
                                if ((DPtoRF_data.dst == 3)) {
                                    if(!coveragePoints["Register_file_465"]){
                                        coveragePoints["Register_file_465"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    reg_file_03 = DPtoRF_data.dstData;
                                } else {
                                    if(!coveragePoints["Register_file_466"]){
                                        coveragePoints["Register_file_466"] = true;
                                        coveragePointsCount++;
                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                    }
                                    if ((DPtoRF_data.dst == 4)) {
                                        if(!coveragePoints["Register_file_467"]){
                                            coveragePoints["Register_file_467"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        reg_file_04 = DPtoRF_data.dstData;
                                    } else {
                                        if(!coveragePoints["Register_file_468"]){
                                            coveragePoints["Register_file_468"] = true;
                                            coveragePointsCount++;
                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                        }
                                        if ((DPtoRF_data.dst == 5)) {
                                            if(!coveragePoints["Register_file_469"]){
                                                coveragePoints["Register_file_469"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                            }
                                            reg_file_05 = DPtoRF_data.dstData;
                                        } else {
                                            if(!coveragePoints["Register_file_470"]){
                                                coveragePoints["Register_file_470"] = true;
                                                coveragePointsCount++;
                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                            }
                                            if ((DPtoRF_data.dst == 6)) {
                                                if(!coveragePoints["Register_file_471"]){
                                                    coveragePoints["Register_file_471"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                }
                                                reg_file_06 = DPtoRF_data.dstData;
                                            } else {
                                                if(!coveragePoints["Register_file_472"]){
                                                    coveragePoints["Register_file_472"] = true;
                                                    coveragePointsCount++;
                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                }
                                                if ((DPtoRF_data.dst == 7)) {
                                                    if(!coveragePoints["Register_file_473"]){
                                                        coveragePoints["Register_file_473"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                    }
                                                    reg_file_07 = DPtoRF_data.dstData;
                                                } else {
                                                    if(!coveragePoints["Register_file_474"]){
                                                        coveragePoints["Register_file_474"] = true;
                                                        coveragePointsCount++;
                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                    }
                                                    if ((DPtoRF_data.dst == 8)) {
                                                        if(!coveragePoints["Register_file_475"]){
                                                            coveragePoints["Register_file_475"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                        }
                                                        reg_file_08 = DPtoRF_data.dstData;
                                                    } else {
                                                        if(!coveragePoints["Register_file_476"]){
                                                            coveragePoints["Register_file_476"] = true;
                                                            coveragePointsCount++;
                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                        }
                                                        if ((DPtoRF_data.dst == 9)) {
                                                            if(!coveragePoints["Register_file_477"]){
                                                                coveragePoints["Register_file_477"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                            }
                                                            reg_file_09 = DPtoRF_data.dstData;
                                                        } else {
                                                            if(!coveragePoints["Register_file_478"]){
                                                                coveragePoints["Register_file_478"] = true;
                                                                coveragePointsCount++;
                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                            }
                                                            if ((DPtoRF_data.dst == 10)) {
                                                                if(!coveragePoints["Register_file_479"]){
                                                                    coveragePoints["Register_file_479"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                }
                                                                reg_file_10 = DPtoRF_data.dstData;
                                                            } else {
                                                                if(!coveragePoints["Register_file_480"]){
                                                                    coveragePoints["Register_file_480"] = true;
                                                                    coveragePointsCount++;
                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                }
                                                                if ((DPtoRF_data.dst == 11)) {
                                                                    if(!coveragePoints["Register_file_481"]){
                                                                        coveragePoints["Register_file_481"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                    }
                                                                    reg_file_11 = DPtoRF_data.dstData;
                                                                } else {
                                                                    if(!coveragePoints["Register_file_482"]){
                                                                        coveragePoints["Register_file_482"] = true;
                                                                        coveragePointsCount++;
                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                    }
                                                                    if ((DPtoRF_data.dst == 12)) {
                                                                        if(!coveragePoints["Register_file_483"]){
                                                                            coveragePoints["Register_file_483"] = true;
                                                                            coveragePointsCount++;
                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                        }
                                                                        reg_file_12 = DPtoRF_data.dstData;
                                                                    } else {
                                                                        if(!coveragePoints["Register_file_484"]){
                                                                            coveragePoints["Register_file_484"] = true;
                                                                            coveragePointsCount++;
                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                        }
                                                                        if ((DPtoRF_data.dst == 13)) {
                                                                            if(!coveragePoints["Register_file_485"]){
                                                                                coveragePoints["Register_file_485"] = true;
                                                                                coveragePointsCount++;
                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                            }
                                                                            reg_file_13 = DPtoRF_data.dstData;
                                                                        } else {
                                                                            if(!coveragePoints["Register_file_486"]){
                                                                                coveragePoints["Register_file_486"] = true;
                                                                                coveragePointsCount++;
                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                            }
                                                                            if ((DPtoRF_data.dst == 14)) {
                                                                                if(!coveragePoints["Register_file_487"]){
                                                                                    coveragePoints["Register_file_487"] = true;
                                                                                    coveragePointsCount++;
                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                }
                                                                                reg_file_14 = DPtoRF_data.dstData;
                                                                            } else {
                                                                                if(!coveragePoints["Register_file_488"]){
                                                                                    coveragePoints["Register_file_488"] = true;
                                                                                    coveragePointsCount++;
                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                }
                                                                                if ((DPtoRF_data.dst == 15)) {
                                                                                    if(!coveragePoints["Register_file_489"]){
                                                                                        coveragePoints["Register_file_489"] = true;
                                                                                        coveragePointsCount++;
                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                    }
                                                                                    reg_file_15 = DPtoRF_data.dstData;
                                                                                } else {
                                                                                    if(!coveragePoints["Register_file_490"]){
                                                                                        coveragePoints["Register_file_490"] = true;
                                                                                        coveragePointsCount++;
                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                    }
                                                                                    if ((DPtoRF_data.dst == 16)) {
                                                                                        if(!coveragePoints["Register_file_491"]){
                                                                                            coveragePoints["Register_file_491"] = true;
                                                                                            coveragePointsCount++;
                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                        }
                                                                                        reg_file_16 = DPtoRF_data.dstData;
                                                                                    } else {
                                                                                        if(!coveragePoints["Register_file_492"]){
                                                                                            coveragePoints["Register_file_492"] = true;
                                                                                            coveragePointsCount++;
                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                        }
                                                                                        if ((DPtoRF_data.dst == 17)) {
                                                                                            if(!coveragePoints["Register_file_493"]){
                                                                                                coveragePoints["Register_file_493"] = true;
                                                                                                coveragePointsCount++;
                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                            }
                                                                                            reg_file_17 = DPtoRF_data.dstData;
                                                                                        } else {
                                                                                            if(!coveragePoints["Register_file_494"]){
                                                                                                coveragePoints["Register_file_494"] = true;
                                                                                                coveragePointsCount++;
                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                            }
                                                                                            if ((DPtoRF_data.dst == 18)) {
                                                                                                if(!coveragePoints["Register_file_495"]){
                                                                                                    coveragePoints["Register_file_495"] = true;
                                                                                                    coveragePointsCount++;
                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                }
                                                                                                reg_file_18 = DPtoRF_data.dstData;
                                                                                            } else {
                                                                                                if(!coveragePoints["Register_file_496"]){
                                                                                                    coveragePoints["Register_file_496"] = true;
                                                                                                    coveragePointsCount++;
                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                }
                                                                                                if ((DPtoRF_data.dst == 19)) {
                                                                                                    if(!coveragePoints["Register_file_497"]){
                                                                                                        coveragePoints["Register_file_497"] = true;
                                                                                                        coveragePointsCount++;
                                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                    }
                                                                                                    reg_file_19 = DPtoRF_data.dstData;
                                                                                                } else {
                                                                                                    if(!coveragePoints["Register_file_498"]){
                                                                                                        coveragePoints["Register_file_498"] = true;
                                                                                                        coveragePointsCount++;
                                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                    }
                                                                                                    if ((DPtoRF_data.dst == 20)) {
                                                                                                        if(!coveragePoints["Register_file_499"]){
                                                                                                            coveragePoints["Register_file_499"] = true;
                                                                                                            coveragePointsCount++;
                                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                        }
                                                                                                        reg_file_20 = DPtoRF_data.dstData;
                                                                                                    } else {
                                                                                                        if(!coveragePoints["Register_file_500"]){
                                                                                                            coveragePoints["Register_file_500"] = true;
                                                                                                            coveragePointsCount++;
                                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                        }
                                                                                                        if ((DPtoRF_data.dst == 21)) {
                                                                                                            if(!coveragePoints["Register_file_501"]){
                                                                                                                coveragePoints["Register_file_501"] = true;
                                                                                                                coveragePointsCount++;
                                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                            }
                                                                                                            reg_file_21 = DPtoRF_data.dstData;
                                                                                                        } else {
                                                                                                            if(!coveragePoints["Register_file_502"]){
                                                                                                                coveragePoints["Register_file_502"] = true;
                                                                                                                coveragePointsCount++;
                                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                            }
                                                                                                            if ((DPtoRF_data.dst == 22)) {
                                                                                                                if(!coveragePoints["Register_file_503"]){
                                                                                                                    coveragePoints["Register_file_503"] = true;
                                                                                                                    coveragePointsCount++;
                                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                }
                                                                                                                reg_file_22 = DPtoRF_data.dstData;
                                                                                                            } else {
                                                                                                                if(!coveragePoints["Register_file_504"]){
                                                                                                                    coveragePoints["Register_file_504"] = true;
                                                                                                                    coveragePointsCount++;
                                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                }
                                                                                                                if ((DPtoRF_data.dst == 23)) {
                                                                                                                    if(!coveragePoints["Register_file_505"]){
                                                                                                                        coveragePoints["Register_file_505"] = true;
                                                                                                                        coveragePointsCount++;
                                                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                    }
                                                                                                                    reg_file_23 = DPtoRF_data.dstData;
                                                                                                                } else {
                                                                                                                    if(!coveragePoints["Register_file_506"]){
                                                                                                                        coveragePoints["Register_file_506"] = true;
                                                                                                                        coveragePointsCount++;
                                                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                    }
                                                                                                                    if ((DPtoRF_data.dst == 24)) {
                                                                                                                        if(!coveragePoints["Register_file_507"]){
                                                                                                                            coveragePoints["Register_file_507"] = true;
                                                                                                                            coveragePointsCount++;
                                                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                        }
                                                                                                                        reg_file_24 = DPtoRF_data.dstData;
                                                                                                                    } else {
                                                                                                                        if(!coveragePoints["Register_file_508"]){
                                                                                                                            coveragePoints["Register_file_508"] = true;
                                                                                                                            coveragePointsCount++;
                                                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                        }
                                                                                                                        if ((DPtoRF_data.dst == 25)) {
                                                                                                                            if(!coveragePoints["Register_file_509"]){
                                                                                                                                coveragePoints["Register_file_509"] = true;
                                                                                                                                coveragePointsCount++;
                                                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                            }
                                                                                                                            reg_file_25 = DPtoRF_data.dstData;
                                                                                                                        } else {
                                                                                                                            if(!coveragePoints["Register_file_510"]){
                                                                                                                                coveragePoints["Register_file_510"] = true;
                                                                                                                                coveragePointsCount++;
                                                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                            }
                                                                                                                            if ((DPtoRF_data.dst == 26)) {
                                                                                                                                if(!coveragePoints["Register_file_511"]){
                                                                                                                                    coveragePoints["Register_file_511"] = true;
                                                                                                                                    coveragePointsCount++;
                                                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                }
                                                                                                                                reg_file_26 = DPtoRF_data.dstData;
                                                                                                                            } else {
                                                                                                                                if(!coveragePoints["Register_file_512"]){
                                                                                                                                    coveragePoints["Register_file_512"] = true;
                                                                                                                                    coveragePointsCount++;
                                                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                }
                                                                                                                                if ((DPtoRF_data.dst == 27)) {
                                                                                                                                    if(!coveragePoints["Register_file_513"]){
                                                                                                                                        coveragePoints["Register_file_513"] = true;
                                                                                                                                        coveragePointsCount++;
                                                                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                    }
                                                                                                                                    reg_file_27 = DPtoRF_data.dstData;
                                                                                                                                } else {
                                                                                                                                    if(!coveragePoints["Register_file_514"]){
                                                                                                                                        coveragePoints["Register_file_514"] = true;
                                                                                                                                        coveragePointsCount++;
                                                                                                                                        std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                    }
                                                                                                                                    if ((DPtoRF_data.dst == 28)) {
                                                                                                                                        if(!coveragePoints["Register_file_515"]){
                                                                                                                                            coveragePoints["Register_file_515"] = true;
                                                                                                                                            coveragePointsCount++;
                                                                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                        }
                                                                                                                                        reg_file_28 = DPtoRF_data.dstData;
                                                                                                                                    } else {
                                                                                                                                        if(!coveragePoints["Register_file_516"]){
                                                                                                                                            coveragePoints["Register_file_516"] = true;
                                                                                                                                            coveragePointsCount++;
                                                                                                                                            std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                        }
                                                                                                                                        if ((DPtoRF_data.dst == 29)) {
                                                                                                                                            if(!coveragePoints["Register_file_517"]){
                                                                                                                                                coveragePoints["Register_file_517"] = true;
                                                                                                                                                coveragePointsCount++;
                                                                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                            }
                                                                                                                                            reg_file_29 = DPtoRF_data.dstData;
                                                                                                                                        } else {
                                                                                                                                            if(!coveragePoints["Register_file_518"]){
                                                                                                                                                coveragePoints["Register_file_518"] = true;
                                                                                                                                                coveragePointsCount++;
                                                                                                                                                std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                            }
                                                                                                                                            if ((DPtoRF_data.dst == 30)) {
                                                                                                                                                if(!coveragePoints["Register_file_519"]){
                                                                                                                                                    coveragePoints["Register_file_519"] = true;
                                                                                                                                                    coveragePointsCount++;
                                                                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
                                                                                                                                                }
                                                                                                                                                reg_file_30 = DPtoRF_data.dstData;
                                                                                                                                            } else {
                                                                                                                                                if(!coveragePoints["Register_file_520"]){
                                                                                                                                                    coveragePoints["Register_file_520"] = true;
                                                                                                                                                    coveragePointsCount++;
                                                                                                                                                    std::cout<<"Coverage Percentage: Register_file" << ( coveragePointsCount * 100 /coveragePointsTotal ) << "%\n";
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
            wait(SC_ZERO_TIME);
        }//end of while
    }//end of FSM
    int coveragePointsTotal = 520;
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
            reg_file_31(0)      {
        SC_THREAD(FSM);
        for(int i = 1; i < coveragePointsTotal; i++)
            coveragePoints.insert(std::make_pair("Register_file_"+to_string(i),false));
    }
};//end of module


#endif //SYSTEMC_Register_file_H
