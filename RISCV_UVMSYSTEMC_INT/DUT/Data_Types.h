#ifndef DATA_TYPES_H
#define DATA_TYPES_H

enum ALUfuncType {ALU_ADD, ALU_AND, ALU_COPY1, ALU_OR, ALU_SLL, ALU_SLT, ALU_SLTU, ALU_SRA, ALU_SRL, ALU_SUB, ALU_X, ALU_XOR};
enum EncType {ENC_B, ENC_ERR, ENC_I_I, ENC_I_J, ENC_I_L, ENC_J, ENC_R, ENC_S, ENC_U};
enum InstrType {INSTR_ADD, INSTR_ADDI, INSTR_AND, INSTR_ANDI, INSTR_AUIPC, INSTR_BEQ, INSTR_BGE, INSTR_BGEU, INSTR_BLT, INSTR_BLTU, INSTR_BNE, INSTR_JAL, INSTR_JALR, INSTR_LB, INSTR_LBU, INSTR_LH, INSTR_LHU, INSTR_LUI, INSTR_LW, INSTR_OR, INSTR_ORI, INSTR_SB, INSTR_SH, INSTR_SLL, INSTR_SLLI, INSTR_SLT, INSTR_SLTI, INSTR_SLTU, INSTR_SLTUI, INSTR_SRA, INSTR_SRAI, INSTR_SRL, INSTR_SRLI, INSTR_SUB, INSTR_SW, INSTR_UNKNOWN, INSTR_XOR, INSTR_XORI};
//enum ME_AccessType {ME_RD, ME_WR, ME_X};
//enum ME_MaskType {MT_B, MT_BU, MT_H, MT_HU, MT_W, MT_X};
//struct CUtoME_IF { unsigned addrIn; unsigned dataIn; ME_MaskType mask; ME_AccessType req; };
//struct MEtoCU_IF { unsigned loadedData; };
struct RegfileType { unsigned reg_file_01; unsigned reg_file_02; unsigned reg_file_03; unsigned reg_file_04; unsigned reg_file_05; unsigned reg_file_06; unsigned reg_file_07; unsigned reg_file_08; unsigned reg_file_09; unsigned reg_file_10; unsigned reg_file_11; unsigned reg_file_12; unsigned reg_file_13; unsigned reg_file_14; unsigned reg_file_15; unsigned reg_file_16; unsigned reg_file_17; unsigned reg_file_18; unsigned reg_file_19; unsigned reg_file_20; unsigned reg_file_21; unsigned reg_file_22; unsigned reg_file_23; unsigned reg_file_24; unsigned reg_file_25; unsigned reg_file_26; unsigned reg_file_27; unsigned reg_file_28; unsigned reg_file_29; unsigned reg_file_30; unsigned reg_file_31; };
struct RegfileWriteType { unsigned dst; unsigned dstData; };


#endif //DATA_TYPES_H
