#ifndef DATA_TYPES_H
#define DATA_TYPES_H

enum ALUfuncType {ALU_ADD, ALU_AND, ALU_COPY1, ALU_OR, ALU_SLL, ALU_SLT, ALU_SLTU, ALU_SRA, ALU_SRL, ALU_SUB, ALU_X, ALU_XOR};
enum AL_OperandSelType {OP_IMM, OP_PC, OP_REG, OP_X};
enum EncType {ENC_B, ENC_ERR, ENC_I_I, ENC_I_J, ENC_I_L, ENC_J, ENC_R, ENC_S, ENC_U};
enum InstrType {INSTR_ADD, INSTR_ADDI, INSTR_AND, INSTR_ANDI, INSTR_AUIPC, INSTR_BEQ, INSTR_BGE, INSTR_BGEU, INSTR_BLT, INSTR_BLTU, INSTR_BNE, INSTR_JAL, INSTR_JALR, INSTR_LB, INSTR_LBU, INSTR_LH, INSTR_LHU, INSTR_LUI, INSTR_LW, INSTR_OR, INSTR_ORI, INSTR_SB, INSTR_SH, INSTR_SLL, INSTR_SLLI, INSTR_SLT, INSTR_SLTI, INSTR_SLTU, INSTR_SLTUI, INSTR_SRA, INSTR_SRAI, INSTR_SRL, INSTR_SRLI, INSTR_SUB, INSTR_SW, INSTR_UNKNOWN, INSTR_XOR, INSTR_XORI};
//enum ME_AccessType {ME_RD, ME_WR, ME_X};
//enum ME_MaskType {MT_B, MT_BU, MT_H, MT_HU, MT_W, MT_X};
enum PC_SelType {PC_4, PC_BR, PC_J, PC_JR};
enum RF_RD_AccessType {RF_RD, RF_RD_X};
enum RF_WR_AccessType {RF_WR, RF_WR_X};
enum RF_WriteDataSelType {WB_ALU, WB_MEM, WB_PC4, WB_X};
struct CUtoDP_IF { ALUfuncType aluFunc_s3; AL_OperandSelType aluOp1Sel_s3; AL_OperandSelType aluOp2Sel_s3; ME_MaskType dmemMask_s4; ME_AccessType dmemReq_s4; EncType encType_s2; unsigned imm_s3; unsigned loadedData; unsigned pc_s2; bool prevDmemAccess; RF_RD_AccessType regFileReq_s2; RF_WR_AccessType regFileReq_s5; RF_WriteDataSelType regFileWriteDataSel_s5; unsigned regRdAddr_s2; unsigned regRs1Addr_s2; unsigned regRs2Addr_s2; bool stallDmemAccess; };
struct CUtoDP_S3 { ALUfuncType aluFunc_s3; AL_OperandSelType aluOp1Sel_s3; AL_OperandSelType aluOp2Sel_s3; unsigned imm_s3; };
struct CUtoDP_S4 { ME_MaskType dmemMask_s4; ME_AccessType dmemReq_s4; };
struct CUtoDP_S5 { RF_WR_AccessType regFileReq_s5; RF_WriteDataSelType regFileWriteDataSel_s5; };
//struct CUtoME_IF { unsigned addrIn; unsigned dataIn; ME_MaskType mask; ME_AccessType req; };
struct DEtoCU_IF { ALUfuncType aluFunc_s3; AL_OperandSelType aluOp1Sel_s3; AL_OperandSelType aluOp2Sel_s3; ME_MaskType dmemMask_s4; ME_AccessType dmemReq_s4; EncType encType_s2; unsigned imm_s2; unsigned imm_s3; InstrType instrType_s2; PC_SelType pcSel_s2; RF_RD_AccessType regFileReq_s2; RF_WR_AccessType regFileReq_s5; RF_WriteDataSelType regFileWriteDataSel_s5; unsigned regRdAddr_s2; unsigned regRs1Addr_s2; unsigned regRs2Addr_s2; };
struct DP_S3 { EncType encType_s3; unsigned pc_s3; unsigned reg1Content_s3; unsigned reg2Content_s3; unsigned regRdAddr_s3; unsigned regRs1Addr_s3; unsigned regRs2Addr_s3; };
struct DP_S4 { unsigned aluResult_s4; EncType encType_s4; bool fwdPrevLoadedData; unsigned pc_s4; unsigned prevLoadedData; unsigned reg2Content_s4; unsigned regRdAddr_s4; unsigned regRs2Addr_s4; };
struct DP_S5 { unsigned aluResult_s5; EncType encType_s5; unsigned pc_s5; unsigned regRdAddr_s5; };
struct DPtoAL_IF { ALUfuncType aluFunc; unsigned aluOp1; unsigned aluOp2; };
struct DPtoCU_IF { unsigned addrIn; unsigned dataIn; ME_MaskType mask; unsigned reg1Content; unsigned reg2Content; ME_AccessType req; };
struct DPtoRF_IF { unsigned dst; unsigned dstData; RF_WR_AccessType wrReq; };
//struct MEtoCU_IF { unsigned loadedData; };
struct RFtoDP_IF { unsigned reg_file_01; unsigned reg_file_02; unsigned reg_file_03; unsigned reg_file_04; unsigned reg_file_05; unsigned reg_file_06; unsigned reg_file_07; unsigned reg_file_08; unsigned reg_file_09; unsigned reg_file_10; unsigned reg_file_11; unsigned reg_file_12; unsigned reg_file_13; unsigned reg_file_14; unsigned reg_file_15; unsigned reg_file_16; unsigned reg_file_17; unsigned reg_file_18; unsigned reg_file_19; unsigned reg_file_20; unsigned reg_file_21; unsigned reg_file_22; unsigned reg_file_23; unsigned reg_file_24; unsigned reg_file_25; unsigned reg_file_26; unsigned reg_file_27; unsigned reg_file_28; unsigned reg_file_29; unsigned reg_file_30; unsigned reg_file_31; };


#endif //DATA_TYPES_H
