#ifndef DATA_TYPES_H
#define DATA_TYPES_H

enum ALU_function {ALU_ADD, ALU_AND, ALU_COPY1, ALU_OR, ALU_SLL, ALU_SLT, ALU_SLTU, ALU_SRA, ALU_SRL, ALU_SUB, ALU_X, ALU_XOR};
enum ALUopType {OP_IMM, OP_PC, OP_REG, OP_X};
enum AccessType_Reg {REG_RD, REG_WR};
enum EncType {B, Error_Type, I, J, R, S, U};
enum InstrTypeOld {And_Instr, Or_Instr, Unknown, Xor_Instr, add, addI, andI, auipc, beq, bge, bgeu, blt, bltu, bne, jal, jalr, lb, lbu, lh, lhu, lui, lw, orI, sb, sh, sllI, sll_Instr, slt, sltI, sltIu, sltu, sraI, sra_Instr, srlI, srl_Instr, sub, sw, xorI};
//enum ME_AccessType {ME_RD, ME_WR, ME_X};
//enum ME_MaskType {MT_B, MT_BU, MT_H, MT_HU, MT_W, MT_X};
enum PCselType {PC_4, PC_BR, PC_EXC, PC_J, PC_JR};
enum WBselType {WB_ALU, WB_MEM, WB_PC4, WB_X};
struct ALUtoCtl_IF { unsigned ALU_result; };
//struct CUtoME_IF { unsigned addrIn; unsigned dataIn; ME_MaskType mask; ME_AccessType req; };
struct CtlToALU_IF { ALU_function alu_fun; unsigned imm; ALUopType op1_sel; ALUopType op2_sel; unsigned pc_reg; unsigned reg1_contents; unsigned reg2_contents; };
struct CtlToRegs_IF { unsigned dst; unsigned dst_data; AccessType_Reg req; unsigned src1; unsigned src2; };
struct DecodedInstr { EncType encType; unsigned imm; InstrTypeOld instrType; unsigned rd_addr; unsigned rs1_addr; unsigned rs2_addr; };
//struct MEtoCU_IF { unsigned loadedData; };
struct RegsToCtl_IF { unsigned contents1; unsigned contents2; };


#endif //DATA_TYPES_H
