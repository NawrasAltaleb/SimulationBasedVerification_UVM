//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 13.10.18.
//

#ifndef GOLDEN_RISCV_C_H_
#define GOLDEN_RISCV_C_H_

// Adjusts code to be appropriate for the SCAM tool
// Working ESL-Description -> #define NOSCAM
// Properties can be generated -> //#define NOSCAM
#define NOSCAM

#include "systemc.h"
#include "Interfaces.h"
#include "GOLDEN_CPU_Interfaces.h"
#ifndef NOSCAM
#include "Memory_Interfaces.h"
#else
#include "../../RISCV_commons/Memory_Interfaces.h"
#endif

#define OPCODE_U1   0x37 //0110111
#define OPCODE_U2   0x17 //0010111
#define OPCODE_J    0x6F //1101111
#define OPCODE_I_J  0x67 //1100111
#define OPCODE_B    0x63 //1100011
#define OPCODE_I_L  0x03 //0000011
#define OPCODE_S    0x23 //0100011
#define OPCODE_I_I  0x13 //0010011
#define OPCODE_R    0x33 //0110011
#define OPCODE_I_M  0x0F //0001111
#define OPCODE_I_S  0x73 //1110011

#define OPCODE_FIELD(x) ((x) & 0x7F)
#define FUNCT3_FIELD(x) (((x) >> 12) & 0x07)
#define FUNCT7_FIELD(x) (((x) >> 25) & 0x7F)
#define RS1_FIELD(x)    (((x) >> 15) & 0x1F)
#define RS2_FIELD(x)    (((x) >> 20) & 0x1F)
#define RD_FIELD(x)     (((x) >> 7) & 0x1F)
#define SIGN_FIELD(x)   (((x) >> 31) & 0x1)

#define IMM_U_FIELD(x)      ((x) & static_cast<unsigned int>(0xFFFFF000))
#define POS_IMM_I_FIELD(x)  ((x) >> 20)
#define POS_IMM_S_FIELD(x)  ((((x) >> 20) & 0xFE0) | (((x) >> 7) & 0x1F))
#define POS_IMM_B_FIELD(x)  ((((x) << 4) & 0x800) | (((x) >> 20) & 0x7E0) | (((x) >> 7) & 0x1E))
#define POS_IMM_J_FIELD(x)  (((x) & 0xFF000) | (((x) >> 9) & 0x800) | (((x) >> 20) & 0x7FE))
#define NEG_IMM_I_FIELD(x)  (static_cast<unsigned int>(0xFFFFF000) | POS_IMM_I_FIELD(x))
#define NEG_IMM_S_FIELD(x)  (static_cast<unsigned int>(0xFFFFF000) | POS_IMM_S_FIELD(x))
#define NEG_IMM_B_FIELD(x)  (static_cast<unsigned int>(0xFFFFF000) | POS_IMM_B_FIELD(x))
#define NEG_IMM_J_FIELD(x)  (static_cast<unsigned int>(0xFFF00000) | POS_IMM_J_FIELD(x))

//#define writeReg( dst, data )  ((dst) == 1 ? (reg_file_01 = dstData) : ( ( ( (x) * (x) ) / ( ( x ) + ( y ) ) ) * ( y ) ))
//writeRegfile(getRdAddr(encodedInstr), aluResult);

class GoldenCore : public sc_module {
public:
    //Constructor
    SC_HAS_PROCESS(GoldenCore);

    GoldenCore(sc_module_name name) :
            fromMemoryPort("fromMemoryPort"),
            toMemoryPort("toMemoryPort"),
            section(fetch),
            nextsection(fetch),
            pcReg(0),
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
            reg_file_31(0) {
        SC_THREAD(run);
    }

    // ports for communication with memory/decoder
    blocking_out<CUtoME_IF> toMemoryPort;
    blocking_in<MEtoCU_IF> fromMemoryPort;

    // data for communication with memory
    CUtoME_IF toMemoryData;
    MEtoCU_IF fromMemoryData;

    /// Visibale variables
    // register file data
    unsigned int reg_file_01 = 0;
    unsigned int reg_file_02 = 0;
    unsigned int reg_file_03 = 0;
    unsigned int reg_file_04 = 0;
    unsigned int reg_file_05 = 0;
    unsigned int reg_file_06 = 0;
    unsigned int reg_file_07 = 0;
    unsigned int reg_file_08 = 0;
    unsigned int reg_file_09 = 0;
    unsigned int reg_file_10 = 0;
    unsigned int reg_file_11 = 0;
    unsigned int reg_file_12 = 0;
    unsigned int reg_file_13 = 0;
    unsigned int reg_file_14 = 0;
    unsigned int reg_file_15 = 0;
    unsigned int reg_file_16 = 0;
    unsigned int reg_file_17 = 0;
    unsigned int reg_file_18 = 0;
    unsigned int reg_file_19 = 0;
    unsigned int reg_file_20 = 0;
    unsigned int reg_file_21 = 0;
    unsigned int reg_file_22 = 0;
    unsigned int reg_file_23 = 0;
    unsigned int reg_file_24 = 0;
    unsigned int reg_file_25 = 0;
    unsigned int reg_file_26 = 0;
    unsigned int reg_file_27 = 0;
    unsigned int reg_file_28 = 0;
    unsigned int reg_file_29 = 0;
    unsigned int reg_file_30 = 0;
    unsigned int reg_file_31 = 0;

    unsigned int pcReg;

    // ISA sections
    enum Sections {
        fetch,              // fetch next instruction from memory
        execute             // decode the fetched instruction and do all the manipulations till writing back to the register file
    };
    Sections section, nextsection;

    // Other control signals:
    unsigned int encodedInstr;

    unsigned int aluOp1;
    unsigned int aluOp2;
    unsigned int aluResult;

//    bool writeReg;
//    unsigned int writeReg_data;
    bool takeBranch;

    void run() {
        while (true) {

            // fetch next instruction
            if (section == Sections::fetch) {
//                writeReg = false;
//                writeReg_data = 0;
                // Set up memory access
                toMemoryData.req = ME_RD;
                toMemoryData.mask = MT_W; // always for instructions
                toMemoryData.addrIn = pcReg;
                toMemoryData.dataIn = 0;    // not relevant

//                std::cout << "**** ISA **** request instruction addr: 0x" << hex << toMemoryData.addrIn << "\n";
                toMemoryPort->write(toMemoryData); //Send request to memory

                fromMemoryPort->read(fromMemoryData); //Read encoded instruction from memory
//                std::cout << "\t\t\t\t\t\t\t\t\t\t**** ISA **** receive instruction: " << hex << fromMemoryData.loadedData << "\n";

                encodedInstr = fromMemoryData.loadedData;

#ifndef NOSCAM
                /// Termination happens through a proper EBREAK or ECALL(SYS_exit)
                if (fromMemoryData.loadedData == 0x100073) {
                    std::cout << "**** ISA **** is terminating\n";
                    break;
                }
#endif
                nextsection = Sections::execute;
            }

            if (section == Sections::execute) {
/*
                if (getRs1Addr(encodedInstr) == 0) {
                    aluOp1 = 0;
                } else if (getRs1Addr(encodedInstr) == 1) {
                    aluOp1 = reg_file_01;
                } else if (getRs1Addr(encodedInstr) == 2) {
                    aluOp1 = reg_file_02;
                } else if (getRs1Addr(encodedInstr) == 3) {
                    aluOp1 = reg_file_03;
                } else if (getRs1Addr(encodedInstr) == 4) {
                    aluOp1 = reg_file_04;
                } else if (getRs1Addr(encodedInstr) == 5) {
                    aluOp1 = reg_file_05;
                } else if (getRs1Addr(encodedInstr) == 6) {
                    aluOp1 = reg_file_06;
                } else if (getRs1Addr(encodedInstr) == 7) {
                    aluOp1 = reg_file_07;
                } else if (getRs1Addr(encodedInstr) == 8) {
                    aluOp1 = reg_file_08;
                } else if (getRs1Addr(encodedInstr) == 9) {
                    aluOp1 = reg_file_09;
                } else if (getRs1Addr(encodedInstr) == 10) {
                    aluOp1 = reg_file_10;
                } else if (getRs1Addr(encodedInstr) == 11) {
                    aluOp1 = reg_file_11;
                } else if (getRs1Addr(encodedInstr) == 12) {
                    aluOp1 = reg_file_12;
                } else if (getRs1Addr(encodedInstr) == 13) {
                    aluOp1 = reg_file_13;
                } else if (getRs1Addr(encodedInstr) == 14) {
                    aluOp1 = reg_file_14;
                } else if (getRs1Addr(encodedInstr) == 15) {
                    aluOp1 = reg_file_15;
                } else if (getRs1Addr(encodedInstr) == 16) {
                    aluOp1 = reg_file_16;
                } else if (getRs1Addr(encodedInstr) == 17) {
                    aluOp1 = reg_file_17;
                } else if (getRs1Addr(encodedInstr) == 18) {
                    aluOp1 = reg_file_18;
                } else if (getRs1Addr(encodedInstr) == 19) {
                    aluOp1 = reg_file_19;
                } else if (getRs1Addr(encodedInstr) == 20) {
                    aluOp1 = reg_file_20;
                } else if (getRs1Addr(encodedInstr) == 21) {
                    aluOp1 = reg_file_21;
                } else if (getRs1Addr(encodedInstr) == 22) {
                    aluOp1 = reg_file_22;
                } else if (getRs1Addr(encodedInstr) == 23) {
                    aluOp1 = reg_file_23;
                } else if (getRs1Addr(encodedInstr) == 24) {
                    aluOp1 = reg_file_24;
                } else if (getRs1Addr(encodedInstr) == 25) {
                    aluOp1 = reg_file_25;
                } else if (getRs1Addr(encodedInstr) == 26) {
                    aluOp1 = reg_file_26;
                } else if (getRs1Addr(encodedInstr) == 27) {
                    aluOp1 = reg_file_27;
                } else if (getRs1Addr(encodedInstr) == 28) {
                    aluOp1 = reg_file_28;
                } else if (getRs1Addr(encodedInstr) == 29) {
                    aluOp1 = reg_file_29;
                } else if (getRs1Addr(encodedInstr) == 30) {
                    aluOp1 = reg_file_30;
                } else {
                    aluOp1 = reg_file_31;
                }

                if (getRs2Addr(encodedInstr) == 0) {
                    aluOp2 = 0;
                } else if (getRs2Addr(encodedInstr) == 1) {
                    aluOp2 = reg_file_01;
                } else if (getRs2Addr(encodedInstr) == 2) {
                    aluOp2 = reg_file_02;
                } else if (getRs2Addr(encodedInstr) == 3) {
                    aluOp2 = reg_file_03;
                } else if (getRs2Addr(encodedInstr) == 4) {
                    aluOp2 = reg_file_04;
                } else if (getRs2Addr(encodedInstr) == 5) {
                    aluOp2 = reg_file_05;
                } else if (getRs2Addr(encodedInstr) == 6) {
                    aluOp2 = reg_file_06;
                } else if (getRs2Addr(encodedInstr) == 7) {
                    aluOp2 = reg_file_07;
                } else if (getRs2Addr(encodedInstr) == 8) {
                    aluOp2 = reg_file_08;
                } else if (getRs2Addr(encodedInstr) == 9) {
                    aluOp2 = reg_file_09;
                } else if (getRs2Addr(encodedInstr) == 10) {
                    aluOp2 = reg_file_10;
                } else if (getRs2Addr(encodedInstr) == 11) {
                    aluOp2 = reg_file_11;
                } else if (getRs2Addr(encodedInstr) == 12) {
                    aluOp2 = reg_file_12;
                } else if (getRs2Addr(encodedInstr) == 13) {
                    aluOp2 = reg_file_13;
                } else if (getRs2Addr(encodedInstr) == 14) {
                    aluOp2 = reg_file_14;
                } else if (getRs2Addr(encodedInstr) == 15) {
                    aluOp2 = reg_file_15;
                } else if (getRs2Addr(encodedInstr) == 16) {
                    aluOp2 = reg_file_16;
                } else if (getRs2Addr(encodedInstr) == 17) {
                    aluOp2 = reg_file_17;
                } else if (getRs2Addr(encodedInstr) == 18) {
                    aluOp2 = reg_file_18;
                } else if (getRs2Addr(encodedInstr) == 19) {
                    aluOp2 = reg_file_19;
                } else if (getRs2Addr(encodedInstr) == 20) {
                    aluOp2 = reg_file_20;
                } else if (getRs2Addr(encodedInstr) == 21) {
                    aluOp2 = reg_file_21;
                } else if (getRs2Addr(encodedInstr) == 22) {
                    aluOp2 = reg_file_22;
                } else if (getRs2Addr(encodedInstr) == 23) {
                    aluOp2 = reg_file_23;
                } else if (getRs2Addr(encodedInstr) == 24) {
                    aluOp2 = reg_file_24;
                } else if (getRs2Addr(encodedInstr) == 25) {
                    aluOp2 = reg_file_25;
                } else if (getRs2Addr(encodedInstr) == 26) {
                    aluOp2 = reg_file_26;
                } else if (getRs2Addr(encodedInstr) == 27) {
                    aluOp2 = reg_file_27;
                } else if (getRs2Addr(encodedInstr) == 28) {
                    aluOp2 = reg_file_28;
                } else if (getRs2Addr(encodedInstr) == 29) {
                    aluOp2 = reg_file_29;
                } else if (getRs2Addr(encodedInstr) == 30) {
                    aluOp2 = reg_file_30;
                } else {
                    aluOp2 = reg_file_31;
                }
*/
                // Decode instruction
                if (getEncType(encodedInstr) == G_ENC_R) {
                    /////////////////////////////////////////////////////////////////////////////
                    //|  ID (RF_READ)   |        EX       |    ---------    |  WB (RF_WRITE)  |//
                    /////////////////////////////////////////////////////////////////////////////

                    //Set-up operands for alu by reading from regfile
                    aluOp1 = readRegfile(getRs1Addr(encodedInstr));
                    aluOp2 = readRegfile(getRs2Addr(encodedInstr));

                    aluResult = getALUresult(getALUfunc(getInstrType(encodedInstr)), aluOp1, aluOp2); //Compute result

                    //write back
//                    writeRegfile(getRdAddr(encodedInstr), aluResult);
//                    writeReg = true;
//                    writeReg_data = aluResult;
                    if (getRdAddr(encodedInstr) == 1) {
                        reg_file_01 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 2) {
                        reg_file_02 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 3) {
                        reg_file_03 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 4) {
                        reg_file_04 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 5) {
                        reg_file_05 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 6) {
                        reg_file_06 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 7) {
                        reg_file_07 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 8) {
                        reg_file_08 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 9) {
                        reg_file_09 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 10) {
                        reg_file_10 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 11) {
                        reg_file_11 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 12) {
                        reg_file_12 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 13) {
                        reg_file_13 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 14) {
                        reg_file_14 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 15) {
                        reg_file_15 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 16) {
                        reg_file_16 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 17) {
                        reg_file_17 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 18) {
                        reg_file_18 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 19) {
                        reg_file_19 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 20) {
                        reg_file_20 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 21) {
                        reg_file_21 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 22) {
                        reg_file_22 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 23) {
                        reg_file_23 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 24) {
                        reg_file_24 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 25) {
                        reg_file_25 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 26) {
                        reg_file_26 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 27) {
                        reg_file_27 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 28) {
                        reg_file_28 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 29) {
                        reg_file_29 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 30) {
                        reg_file_30 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 31) {
                        reg_file_31 = aluResult;
                    }

                    //Set-up PC
                    pcReg = pcReg + 4;
                } else if (getEncType(encodedInstr) == G_ENC_B) {
                    /////////////////////////////////////////////////////////////////////////////
                    //|  ID (RF_READ)   |        EX       |    ---------    |    ---------    |//
                    /////////////////////////////////////////////////////////////////////////////
                    //Set-up operands for alu by reading from regfile
                    aluOp1 = readRegfile(getRs1Addr(encodedInstr));
                    aluOp2 = readRegfile(getRs2Addr(encodedInstr));

                    aluResult = getALUresult(getALUfunc(getInstrType(encodedInstr)), aluOp1, aluOp2); //Compute result

                    //Set-up PC
                    takeBranch = getBranchStatus(encodedInstr, aluResult);
                    if(takeBranch)
                        pcReg = pcReg + getImmediate(encodedInstr);
                    else
                        pcReg = pcReg + 4;
                } else if (getEncType(encodedInstr) == G_ENC_S) {
                    /////////////////////////////////////////////////////////////////////////////
                    //|  ID (RF_READ)   |        EX       |       MEM       |    ---------    |//
                    /////////////////////////////////////////////////////////////////////////////
                    //Set-up operands for alu by reading from regfile
                    aluOp1 = readRegfile(getRs1Addr(encodedInstr));
                    aluOp2 = getImmediate(encodedInstr);

                    aluResult = getALUresult(G_ALU_ADD, aluOp1, aluOp2); //Compute result

                    //prepare memory access
                    toMemoryData.req = ME_WR;
                    toMemoryData.mask = getMemoryMask(getInstrType(encodedInstr)); // set memory access mask
                    toMemoryData.addrIn = aluResult; // Set address (getALUresult result) for stores
                    toMemoryData.dataIn = readRegfile(getRs2Addr(encodedInstr)); // Set data for stores, rs2 = source for store

//                    std::cout << "**** ISA **** request STORE addr: 0x" << hex << toMemoryData.addrIn << ", data: "<< toMemoryData.dataIn << "\n";
                    toMemoryPort->write(toMemoryData); // Store

                    //Set-up PC
                    pcReg = pcReg + 4;
                } else if (getEncType(encodedInstr) == G_ENC_U) {
                    /////////////////////////////////////////////////////////////////////////////
                    //|        ID       |        EX       |    ---------    |  WB (RF_WRITE)  |//
                    /////////////////////////////////////////////////////////////////////////////
                    aluOp1 = pcReg;
                    aluOp2 = getImmediate(encodedInstr);
                    aluResult = getALUresult_U(encodedInstr, aluOp1, aluOp2);

                    //write back
//                    writeReg = true;
//                    writeReg_data = aluResult;
//                    writeRegfile(getRdAddr(encodedInstr), aluResult);
                    if (getRdAddr(encodedInstr) == 1) {
                        reg_file_01 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 2) {
                        reg_file_02 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 3) {
                        reg_file_03 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 4) {
                        reg_file_04 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 5) {
                        reg_file_05 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 6) {
                        reg_file_06 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 7) {
                        reg_file_07 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 8) {
                        reg_file_08 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 9) {
                        reg_file_09 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 10) {
                        reg_file_10 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 11) {
                        reg_file_11 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 12) {
                        reg_file_12 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 13) {
                        reg_file_13 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 14) {
                        reg_file_14 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 15) {
                        reg_file_15 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 16) {
                        reg_file_16 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 17) {
                        reg_file_17 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 18) {
                        reg_file_18 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 19) {
                        reg_file_19 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 20) {
                        reg_file_20 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 21) {
                        reg_file_21 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 22) {
                        reg_file_22 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 23) {
                        reg_file_23 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 24) {
                        reg_file_24 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 25) {
                        reg_file_25 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 26) {
                        reg_file_26 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 27) {
                        reg_file_27 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 28) {
                        reg_file_28 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 29) {
                        reg_file_29 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 30) {
                        reg_file_30 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 31) {
                        reg_file_31 = aluResult;
                    }

                    //Set-up PC
                    pcReg = pcReg + 4;
                } else if (getEncType(encodedInstr) == G_ENC_J) {
                    /////////////////////////////////////////////////////////////////////////////
                    //|        ID       |    ---------    |    ---------    |  WB (RF_WRITE)  |//
                    /////////////////////////////////////////////////////////////////////////////
//                    aluOp1 = 0;
//                    aluOp2 = 0;
                    //write back
//                    writeReg = true;
//                    writeReg_data = pcReg + 4;
//                    writeRegfile(getRdAddr(encodedInstr), pcReg + 4);
                    if (getRdAddr(encodedInstr) == 1) {
                        reg_file_01 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 2) {
                        reg_file_02 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 3) {
                        reg_file_03 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 4) {
                        reg_file_04 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 5) {
                        reg_file_05 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 6) {
                        reg_file_06 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 7) {
                        reg_file_07 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 8) {
                        reg_file_08 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 9) {
                        reg_file_09 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 10) {
                        reg_file_10 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 11) {
                        reg_file_11 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 12) {
                        reg_file_12 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 13) {
                        reg_file_13 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 14) {
                        reg_file_14 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 15) {
                        reg_file_15 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 16) {
                        reg_file_16 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 17) {
                        reg_file_17 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 18) {
                        reg_file_18 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 19) {
                        reg_file_19 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 20) {
                        reg_file_20 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 21) {
                        reg_file_21 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 22) {
                        reg_file_22 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 23) {
                        reg_file_23 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 24) {
                        reg_file_24 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 25) {
                        reg_file_25 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 26) {
                        reg_file_26 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 27) {
                        reg_file_27 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 28) {
                        reg_file_28 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 29) {
                        reg_file_29 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 30) {
                        reg_file_30 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 31) {
                        reg_file_31 = pcReg + 4;
                    }

                    //Set-up PC
                    pcReg = pcReg + getImmediate(encodedInstr);
                } else if (getEncType(encodedInstr) == G_ENC_I_I) {
                    /////////////////////////////////////////////////////////////////////////////
                    //|  ID (RF_READ)   |        EX       |    ---------    |  WB (RF_WRITE)  |//
                    /////////////////////////////////////////////////////////////////////////////
                    //Set-up operands for alu by reading from regfile
                    aluOp1 = readRegfile(getRs1Addr(encodedInstr));
                    aluOp2 = getImmediate(encodedInstr);

                    aluResult = getALUresult(getALUfunc(getInstrType(encodedInstr)), aluOp1, aluOp2); //Compute result

                    //write back
//                    writeReg = true;
//                    writeReg_data = aluResult;
//                    writeRegfile(getRdAddr(encodedInstr), aluResult);
                    if (getRdAddr(encodedInstr) == 1) {
                        reg_file_01 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 2) {
                        reg_file_02 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 3) {
                        reg_file_03 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 4) {
                        reg_file_04 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 5) {
                        reg_file_05 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 6) {
                        reg_file_06 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 7) {
                        reg_file_07 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 8) {
                        reg_file_08 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 9) {
                        reg_file_09 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 10) {
                        reg_file_10 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 11) {
                        reg_file_11 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 12) {
                        reg_file_12 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 13) {
                        reg_file_13 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 14) {
                        reg_file_14 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 15) {
                        reg_file_15 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 16) {
                        reg_file_16 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 17) {
                        reg_file_17 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 18) {
                        reg_file_18 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 19) {
                        reg_file_19 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 20) {
                        reg_file_20 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 21) {
                        reg_file_21 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 22) {
                        reg_file_22 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 23) {
                        reg_file_23 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 24) {
                        reg_file_24 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 25) {
                        reg_file_25 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 26) {
                        reg_file_26 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 27) {
                        reg_file_27 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 28) {
                        reg_file_28 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 29) {
                        reg_file_29 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 30) {
                        reg_file_30 = aluResult;
                    } else if (getRdAddr(encodedInstr) == 31) {
                        reg_file_31 = aluResult;
                    }

                    //Set-up PC
                    pcReg = pcReg + 4;
                } else if (getEncType(encodedInstr) == G_ENC_I_L) { // loads
                    /////////////////////////////////////////////////////////////////////////////
                    //|  ID (RF_READ)   |        EX       |       MEM       |  ID (RF_WRITE)  |//
                    /////////////////////////////////////////////////////////////////////////////
                    //Set-up operands for alu by reading from regfile
                    aluOp1 = readRegfile(getRs1Addr(encodedInstr));
                    aluOp2 = getImmediate(encodedInstr);

                    aluResult = getALUresult(G_ALU_ADD, aluOp1, aluOp2);

                    //prepare memory access
                    toMemoryData.req = ME_RD;
                    toMemoryData.mask = getMemoryMask(getInstrType(encodedInstr)); // set memory access mask
                    toMemoryData.addrIn = aluResult; // Set address (getALUresult result) for loads
                    toMemoryData.dataIn = 0; // (not relevant for loads)

                    // Request load
//                    std::cout << "**** ISA **** request LOAD addr: 0x" << hex << toMemoryData.addrIn << "\n";
                    toMemoryPort->write(toMemoryData);

                    // Load done
                    fromMemoryPort->read(fromMemoryData);
//                    std::cout << "\t\t\t\t\t\t\t\t\t\t**** ISA **** receive LOAD data: 0x" << hex << fromMemoryData.loadedData << "\n";

                    //write back
//                    writeReg = true;
//                    writeReg_data = fromMemoryData.loadedData;
//                    writeRegfile(getRdAddr(encodedInstr), fromMemoryData.loadedData);
                    if (getRdAddr(encodedInstr) == 1) {
                        reg_file_01 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 2) {
                        reg_file_02 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 3) {
                        reg_file_03 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 4) {
                        reg_file_04 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 5) {
                        reg_file_05 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 6) {
                        reg_file_06 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 7) {
                        reg_file_07 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 8) {
                        reg_file_08 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 9) {
                        reg_file_09 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 10) {
                        reg_file_10 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 11) {
                        reg_file_11 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 12) {
                        reg_file_12 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 13) {
                        reg_file_13 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 14) {
                        reg_file_14 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 15) {
                        reg_file_15 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 16) {
                        reg_file_16 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 17) {
                        reg_file_17 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 18) {
                        reg_file_18 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 19) {
                        reg_file_19 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 20) {
                        reg_file_20 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 21) {
                        reg_file_21 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 22) {
                        reg_file_22 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 23) {
                        reg_file_23 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 24) {
                        reg_file_24 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 25) {
                        reg_file_25 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 26) {
                        reg_file_26 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 27) {
                        reg_file_27 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 28) {
                        reg_file_28 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 29) {
                        reg_file_29 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 30) {
                        reg_file_30 = fromMemoryData.loadedData;
                    } else if (getRdAddr(encodedInstr) == 31) {
                        reg_file_31 = fromMemoryData.loadedData;
                    }

                    //Set-up PC
                    pcReg = pcReg + 4;
                } else if (getEncType(encodedInstr) == G_ENC_I_J) {
                    /////////////////////////////////////////////////////////////////////////////
                    //|  ID (RF_READ)   |    ---------    |    ---------    |  WB (RF_WRITE)  |//
                    /////////////////////////////////////////////////////////////////////////////
                    aluOp1 = readRegfile(getRs1Addr(encodedInstr));
                    aluOp2 = getImmediate(encodedInstr);

                    //write back
//                    writeReg = true;
//                    writeReg_data = pcReg + 4;
//                    writeRegfile(getRdAddr(encodedInstr), pcReg + 4);
                    if (getRdAddr(encodedInstr) == 1) {
                        reg_file_01 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 2) {
                        reg_file_02 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 3) {
                        reg_file_03 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 4) {
                        reg_file_04 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 5) {
                        reg_file_05 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 6) {
                        reg_file_06 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 7) {
                        reg_file_07 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 8) {
                        reg_file_08 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 9) {
                        reg_file_09 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 10) {
                        reg_file_10 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 11) {
                        reg_file_11 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 12) {
                        reg_file_12 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 13) {
                        reg_file_13 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 14) {
                        reg_file_14 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 15) {
                        reg_file_15 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 16) {
                        reg_file_16 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 17) {
                        reg_file_17 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 18) {
                        reg_file_18 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 19) {
                        reg_file_19 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 20) {
                        reg_file_20 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 21) {
                        reg_file_21 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 22) {
                        reg_file_22 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 23) {
                        reg_file_23 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 24) {
                        reg_file_24 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 25) {
                        reg_file_25 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 26) {
                        reg_file_26 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 27) {
                        reg_file_27 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 28) {
                        reg_file_28 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 29) {
                        reg_file_29 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 30) {
                        reg_file_30 = pcReg + 4;
                    } else if (getRdAddr(encodedInstr) == 31) {
                        reg_file_31 = pcReg + 4;
                    }

                    //Set-up PC
                    pcReg = aluOp1 + aluOp2;
                } else {
#ifndef NOSCAM
                    // Terminate if Unknown instr
                    if (getInstrType(encodedInstr) == G_INSTR_UNKNOWN) {
                        break;
                    }
#endif
                }

/*
                if(writeReg){
                    if (getRdAddr(encodedInstr) == 1) {
                        reg_file_01 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 2) {
                        reg_file_02 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 3) {
                        reg_file_03 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 4) {
                        reg_file_04 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 5) {
                        reg_file_05 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 6) {
                        reg_file_06 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 7) {
                        reg_file_07 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 8) {
                        reg_file_08 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 9) {
                        reg_file_09 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 10) {
                        reg_file_10 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 11) {
                        reg_file_11 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 12) {
                        reg_file_12 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 13) {
                        reg_file_13 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 14) {
                        reg_file_14 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 15) {
                        reg_file_15 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 16) {
                        reg_file_16 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 17) {
                        reg_file_17 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 18) {
                        reg_file_18 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 19) {
                        reg_file_19 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 20) {
                        reg_file_20 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 21) {
                        reg_file_21 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 22) {
                        reg_file_22 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 23) {
                        reg_file_23 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 24) {
                        reg_file_24 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 25) {
                        reg_file_25 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 26) {
                        reg_file_26 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 27) {
                        reg_file_27 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 28) {
                        reg_file_28 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 29) {
                        reg_file_29 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 30) {
                        reg_file_30 = writeReg_data;
                    } else if (getRdAddr(encodedInstr) == 31) {
                        reg_file_31 = writeReg_data;
                    }
                }*/
                nextsection = Sections::fetch; // Fetch next instruction
            }

            section = nextsection; // Set next section
        }
    }


    G_EncType getEncType(unsigned int encodedInstr) const {
        if (OPCODE_FIELD(encodedInstr) == OPCODE_R) {
            return G_ENC_R;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_I_I) {
            return G_ENC_I_I;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_I_L) {
            return G_ENC_I_L;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_I_J) {
            return G_ENC_I_J;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_S) {
            return G_ENC_S;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_B) {
            return G_ENC_B;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_U1 || OPCODE_FIELD(encodedInstr) == OPCODE_U2) {
            return G_ENC_U;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_J) {
            return G_ENC_J;
        } else {
            return G_ENC_ERR;
        }
    }


    G_InstrType getInstrType(unsigned int encodedInstr) const {
        if (OPCODE_FIELD(encodedInstr) == OPCODE_R) {
            if (FUNCT3_FIELD(encodedInstr) == 0x00) {
                if (FUNCT7_FIELD(encodedInstr) == 0x00) {
                    return G_INSTR_ADD;
                } else if (FUNCT7_FIELD(encodedInstr) == 0x20) {
                    return G_INSTR_SUB;
                } else {
                    return G_INSTR_UNKNOWN;
                }
            } else if (FUNCT3_FIELD(encodedInstr) == 0x01) {
                return G_INSTR_SLL;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x02) {
                return G_INSTR_SLT;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x03) {
                return G_INSTR_SLTU;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x04) {
                return G_INSTR_XOR;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x05) {
                if (FUNCT7_FIELD(encodedInstr) == 0x00) {
                    return G_INSTR_SRL;
                } else if (FUNCT7_FIELD(encodedInstr) == 0x20) {
                    return G_INSTR_SRA;
                } else {
                    return G_INSTR_UNKNOWN;
                }
            } else if (FUNCT3_FIELD(encodedInstr) == 0x06) {
                return G_INSTR_OR;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x07) {
                return G_INSTR_AND;
            } else {
                return G_INSTR_UNKNOWN;
            }
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_I_I) {
            if (FUNCT3_FIELD(encodedInstr) == 0x00) {
                return G_INSTR_ADDI;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x01) {
                return G_INSTR_SLLI;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x02) {
                return G_INSTR_SLTI;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x03) {
                return G_INSTR_SLTUI;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x04) {
                return G_INSTR_XORI;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x05) {
                if (FUNCT7_FIELD(encodedInstr) == 0x00) {
                    return G_INSTR_SRLI;
                } else if (FUNCT7_FIELD(encodedInstr) == 0x20) {
                    return G_INSTR_SRAI;
                } else {
                    return G_INSTR_UNKNOWN;
                }
            } else if (FUNCT3_FIELD(encodedInstr) == 0x06) {
                return G_INSTR_ORI;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x07) {
                return G_INSTR_ANDI;
            } else {
                return G_INSTR_UNKNOWN;
            }
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_I_L) {
            if (FUNCT3_FIELD(encodedInstr) == 0x00) {
                return G_INSTR_LB;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x01) {
                return G_INSTR_LH;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x02) {
                return G_INSTR_LW;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x04) {
                return G_INSTR_LBU;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x05) {
                return G_INSTR_LHU;
            } else {
                return G_INSTR_UNKNOWN;
            }
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_I_J) {
            return G_INSTR_JALR;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_S) {
            if (FUNCT3_FIELD(encodedInstr) == 0x00) {
                return G_INSTR_SB;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x01) {
                return G_INSTR_SH;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x02) {
                return G_INSTR_SW;
            } else {
                return G_INSTR_UNKNOWN;
            }
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_B) {
            if (FUNCT3_FIELD(encodedInstr) == 0x00) {
                return G_INSTR_BEQ;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x01) {
                return G_INSTR_BNE;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x04) {
                return G_INSTR_BLT;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x05) {
                return G_INSTR_BGE;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x06) {
                return G_INSTR_BLTU;
            } else if (FUNCT3_FIELD(encodedInstr) == 0x07) {
                return G_INSTR_BGEU;
            } else {
                return G_INSTR_UNKNOWN;
            }
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_U1) {
            return G_INSTR_LUI;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_U2) {
            return G_INSTR_AUIPC;
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_J) {
            return G_INSTR_JAL;
        } else {
            return G_INSTR_UNKNOWN;
        }
    }


    unsigned int getRs1Addr(unsigned int encodedInstr) const {
        if (OPCODE_FIELD(encodedInstr) == OPCODE_R ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_I ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_L ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_J ||
            OPCODE_FIELD(encodedInstr) == OPCODE_S ||
            OPCODE_FIELD(encodedInstr) == OPCODE_B) {
            return RS1_FIELD(encodedInstr);
        } else {
            return 0;
        }
    }


    unsigned int getRs2Addr(unsigned int encodedInstr) const {
        if (OPCODE_FIELD(encodedInstr) == OPCODE_R ||
            OPCODE_FIELD(encodedInstr) == OPCODE_S ||
            OPCODE_FIELD(encodedInstr) == OPCODE_B) {
            return RS2_FIELD(encodedInstr);
        } else {
            return 0;
        }
    }


    unsigned int getRdAddr(unsigned int encodedInstr) const {
        if (OPCODE_FIELD(encodedInstr) == OPCODE_R ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_I ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_L ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_J ||
            OPCODE_FIELD(encodedInstr) == OPCODE_U1 ||
            OPCODE_FIELD(encodedInstr) == OPCODE_U2 ||
            OPCODE_FIELD(encodedInstr) == OPCODE_J) {
            return RD_FIELD(encodedInstr);
        } else {
            return 0;
        }
    }


    unsigned int getImmediate(unsigned int encodedInstr) const {
        if (OPCODE_FIELD(encodedInstr) == OPCODE_I_I ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_L ||
            OPCODE_FIELD(encodedInstr) == OPCODE_I_J) {
            if (SIGN_FIELD(encodedInstr) == 0)
                return POS_IMM_I_FIELD(encodedInstr);
            else
                return NEG_IMM_I_FIELD(encodedInstr);
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_S) {
            if (SIGN_FIELD(encodedInstr) == 0)
                return POS_IMM_S_FIELD(encodedInstr);
            else
                return NEG_IMM_S_FIELD(encodedInstr);
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_B) {
            if (SIGN_FIELD(encodedInstr) == 0)
                return POS_IMM_B_FIELD(encodedInstr);
            else
                return NEG_IMM_B_FIELD(encodedInstr);
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_U1 ||
                   OPCODE_FIELD(encodedInstr) == OPCODE_U2) {
            return IMM_U_FIELD(encodedInstr);
        } else if (OPCODE_FIELD(encodedInstr) == OPCODE_J) {
            if (SIGN_FIELD(encodedInstr) == 0)
                return POS_IMM_J_FIELD(encodedInstr);
            else
                return NEG_IMM_J_FIELD(encodedInstr);
        } else {
            return 0;
        }
    }


    G_ALUfuncType getALUfunc(G_InstrType instr) const {
        if (instr == G_INSTR_ADD || instr == G_INSTR_ADDI ||
            instr == G_INSTR_LB || instr == G_INSTR_LH || instr == G_INSTR_LW || instr == G_INSTR_LBU || instr == G_INSTR_LHU ||
            instr == G_INSTR_SB || instr == G_INSTR_SH || instr == G_INSTR_SW ||
            instr == G_INSTR_AUIPC) {
            return G_ALU_ADD;
        } else if (instr == G_INSTR_SUB ||
                   instr == G_INSTR_BEQ || instr == G_INSTR_BNE) {
            return G_ALU_SUB;
        } else if (instr == G_INSTR_SLL || instr == G_INSTR_SLLI) {
            return G_ALU_SLL;
        } else if (instr == G_INSTR_SLT || instr == G_INSTR_SLTI ||
                   instr == G_INSTR_BLT || instr == G_INSTR_BGE) {
            return G_ALU_SLT;
        } else if (instr == G_INSTR_SLTU || instr == G_INSTR_SLTUI ||
                   instr == G_INSTR_BLTU || instr == G_INSTR_BGEU) {
            return G_ALU_SLTU;
        } else if (instr == G_INSTR_XOR || instr == G_INSTR_XORI) {
            return G_ALU_XOR;
        } else if (instr == G_INSTR_SRL || instr == G_INSTR_SRLI) {
            return G_ALU_SRL;
        } else if (instr == G_INSTR_SRA || instr == G_INSTR_SRAI) {
            return G_ALU_SRA;
        } else if (instr == G_INSTR_OR || instr == G_INSTR_ORI) {
            return G_ALU_OR;
        } else if (instr == G_INSTR_AND || instr == G_INSTR_ANDI) {
            return G_ALU_AND;
        } else if (instr == G_INSTR_JALR || instr == G_INSTR_JAL) {
            return G_ALU_X;
        } else if (instr == G_INSTR_LUI) {
            return G_ALU_COPY1;
        } else return G_ALU_X;
    }


    ME_MaskType getMemoryMask(G_InstrType instr) const {
        if (instr == G_INSTR_LW || instr == G_INSTR_SW) {
            return MT_W;
        } else if (instr == G_INSTR_LH || instr == G_INSTR_SH) {
            return MT_H;
        } else if (instr == G_INSTR_LB || instr == G_INSTR_SB) {
            return MT_B;
        } else if (instr == G_INSTR_LHU) {
            return MT_HU;
        } else if (instr == G_INSTR_LBU) {
            return MT_BU;
        } else return MT_X;
    }


    unsigned int readRegfile(unsigned int src) const {
        if (src == 0) {
            return 0;
        } else if (src == 1) {
            return reg_file_01;
        } else if (src == 2) {
            return reg_file_02;
        } else if (src == 3) {
            return reg_file_03;
        } else if (src == 4) {
            return reg_file_04;
        } else if (src == 5) {
            return reg_file_05;
        } else if (src == 6) {
            return reg_file_06;
        } else if (src == 7) {
            return reg_file_07;
        } else if (src == 8) {
            return reg_file_08;
        } else if (src == 9) {
            return reg_file_09;
        } else if (src == 10) {
            return reg_file_10;
        } else if (src == 11) {
            return reg_file_11;
        } else if (src == 12) {
            return reg_file_12;
        } else if (src == 13) {
            return reg_file_13;
        } else if (src == 14) {
            return reg_file_14;
        } else if (src == 15) {
            return reg_file_15;
        } else if (src == 16) {
            return reg_file_16;
        } else if (src == 17) {
            return reg_file_17;
        } else if (src == 18) {
            return reg_file_18;
        } else if (src == 19) {
            return reg_file_19;
        } else if (src == 20) {
            return reg_file_20;
        } else if (src == 21) {
            return reg_file_21;
        } else if (src == 22) {
            return reg_file_22;
        } else if (src == 23) {
            return reg_file_23;
        } else if (src == 24) {
            return reg_file_24;
        } else if (src == 25) {
            return reg_file_25;
        } else if (src == 26) {
            return reg_file_26;
        } else if (src == 27) {
            return reg_file_27;
        } else if (src == 28) {
            return reg_file_28;
        } else if (src == 29) {
            return reg_file_29;
        } else if (src == 30) {
            return reg_file_30;
        } else {
            return reg_file_31;
        }
    }


    void writeRegfile(unsigned int dst, unsigned int dstData) {
        if (dst == 1) {
            reg_file_01 = dstData;
        } else if (dst == 2) {
            reg_file_02 = dstData;
        } else if (dst == 3) {
            reg_file_03 = dstData;
        } else if (dst == 4) {
            reg_file_04 = dstData;
        } else if (dst == 5) {
            reg_file_05 = dstData;
        } else if (dst == 6) {
            reg_file_06 = dstData;
        } else if (dst == 7) {
            reg_file_07 = dstData;
        } else if (dst == 8) {
            reg_file_08 = dstData;
        } else if (dst == 9) {
            reg_file_09 = dstData;
        } else if (dst == 10) {
            reg_file_10 = dstData;
        } else if (dst == 11) {
            reg_file_11 = dstData;
        } else if (dst == 12) {
            reg_file_12 = dstData;
        } else if (dst == 13) {
            reg_file_13 = dstData;
        } else if (dst == 14) {
            reg_file_14 = dstData;
        } else if (dst == 15) {
            reg_file_15 = dstData;
        } else if (dst == 16) {
            reg_file_16 = dstData;
        } else if (dst == 17) {
            reg_file_17 = dstData;
        } else if (dst == 18) {
            reg_file_18 = dstData;
        } else if (dst == 19) {
            reg_file_19 = dstData;
        } else if (dst == 20) {
            reg_file_20 = dstData;
        } else if (dst == 21) {
            reg_file_21 = dstData;
        } else if (dst == 22) {
            reg_file_22 = dstData;
        } else if (dst == 23) {
            reg_file_23 = dstData;
        } else if (dst == 24) {
            reg_file_24 = dstData;
        } else if (dst == 25) {
            reg_file_25 = dstData;
        } else if (dst == 26) {
            reg_file_26 = dstData;
        } else if (dst == 27) {
            reg_file_27 = dstData;
        } else if (dst == 28) {
            reg_file_28 = dstData;
        } else if (dst == 29) {
            reg_file_29 = dstData;
        } else if (dst == 30) {
            reg_file_30 = dstData;
        } else if (dst == 31) {
            reg_file_31 = dstData;
        }
        return;
    }


    unsigned int getALUresult(G_ALUfuncType aluFunction, unsigned int operand1, unsigned int operand2) const {
        if (aluFunction == G_ALU_ADD) {
            return operand1 + operand2;
        } else if (aluFunction == G_ALU_SUB) {
            return operand1 - operand2;
        } else if (aluFunction == G_ALU_AND) {
            return operand1 & operand2;
        } else if (aluFunction == G_ALU_OR) {
            return operand1 | operand2;
        } else if (aluFunction == G_ALU_XOR) {
            return operand1 ^ operand2;
        } else if (aluFunction == G_ALU_SLT) {
            if (static_cast<int>(operand1) < static_cast<int>(operand2)) {
                return 1;
            } else {
                return 0;
            }
        } else if (aluFunction == G_ALU_SLTU) {
            if (operand1 < operand2) {
                return 1;
            } else {
                return 0;
            }
        } else if (aluFunction == G_ALU_SLL) {
            return operand1 << (operand2 & 0x1F);
        } else if (aluFunction == G_ALU_SRA) {
            return static_cast<unsigned int>(static_cast<int>(operand1) >> static_cast<int>(operand2 & 0x1F));
        } else if (aluFunction == G_ALU_SRL) {
            return operand1 >> (operand2 & 0x1F);
        } else if (aluFunction == G_ALU_COPY1) {
            return operand2;
        } else {
            return 0;
        }
    }

/*
    unsigned int getBranchresult(unsigned int encodedInstr, unsigned int aluResult, unsigned int pcReg) const {
        if (getInstrType(encodedInstr) == G_INSTR_BEQ && aluResult == 0) {
            return pcReg + getImmediate(encodedInstr);
        } else if (getInstrType(encodedInstr) == G_INSTR_BNE && aluResult != 0) {
            return pcReg + getImmediate(encodedInstr);
        } else if (getInstrType(encodedInstr) == G_INSTR_BLT && aluResult == 1) {
            return pcReg + getImmediate(encodedInstr);
        } else if (getInstrType(encodedInstr) == G_INSTR_BGE && aluResult == 0) {
            return pcReg + getImmediate(encodedInstr);
        } else if (getInstrType(encodedInstr) == G_INSTR_BLTU && aluResult == 1) {
            return pcReg + getImmediate(encodedInstr);
        } else if (getInstrType(encodedInstr) == G_INSTR_BGEU && aluResult == 0) {
            return pcReg + getImmediate(encodedInstr);
        } else {
            return pcReg + 4;
        }
    }
*/

    unsigned int getALUresult_U(unsigned int encodedInstr, unsigned int pcReg, unsigned int imm) const {
        if (getInstrType(encodedInstr) == G_INSTR_LUI) {
            return getALUresult(G_ALU_COPY1, pcReg, imm); //Compute result
        } else { //G_INSTR_AUIPC
            return getALUresult(G_ALU_ADD, pcReg, imm); //Compute result
        }
    }

    bool getBranchStatus(unsigned int encodedInstr, unsigned int aluResult) const {
        if (getInstrType(encodedInstr) == G_INSTR_BEQ && aluResult == 0) {
            return true;
        } else if (getInstrType(encodedInstr) == G_INSTR_BNE && aluResult != 0) {
            return true;
        } else if (getInstrType(encodedInstr) == G_INSTR_BLT && aluResult == 1) {
            return true;
        } else if (getInstrType(encodedInstr) == G_INSTR_BGE && aluResult == 0) {
            return true;
        } else if (getInstrType(encodedInstr) == G_INSTR_BLTU && aluResult == 1) {
            return true;
        } else if (getInstrType(encodedInstr) == G_INSTR_BGEU && aluResult == 0) {
            return true;
        } else {
            return false;
        }
    }
};
#endif //GOLDEN_RISCV_ISA_H_