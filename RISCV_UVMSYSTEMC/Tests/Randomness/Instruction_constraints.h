//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#ifndef UVMSYSTEMC_INSTRUCTION_CONSTRAINTS_H
#define UVMSYSTEMC_INSTRUCTION_CONSTRAINTS_H

#include "scv.h"
#include "../../Golden_Reference/GOLDEN_CPU_Interfaces.h"

enum instr_constraint_type {R_format, I_I_format, I_L_format, I_J_format, I_M_format, I_S_format, S_format, B_format, U_format, J_format,
                            Mini_format};


class R_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(R_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_ADD, G_InstrType::G_INSTR_SUB, G_InstrType::G_INSTR_SLL, G_InstrType::G_INSTR_SLT,
                                              G_InstrType::G_INSTR_SLTU, G_InstrType::G_INSTR_XOR, G_InstrType::G_INSTR_SRL, G_InstrType::G_INSTR_SRA,
                                              G_InstrType::G_INSTR_OR, G_InstrType::G_INSTR_AND});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_R);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() = 0);//doesn't have an effect
    }
};

class I_I_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(I_I_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_ADDI, G_InstrType::G_INSTR_SLLI, G_InstrType::G_INSTR_SLTI, G_InstrType::G_INSTR_SLTUI,
                                              G_InstrType::G_INSTR_XORI, G_InstrType::G_INSTR_SRLI, G_InstrType::G_INSTR_SRAI, G_InstrType::G_INSTR_ORI,
                                              G_InstrType::G_INSTR_ANDI});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_I_I);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0xFFF);
    }
};

class I_L_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(I_L_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_LB, G_InstrType::G_INSTR_LH, G_InstrType::G_INSTR_LBU, G_InstrType::G_INSTR_LHU, G_InstrType::G_INSTR_LW});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_I_L);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0xFFF);
    }
};

class I_J_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(I_J_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_JALR});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_I_J);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0xFFF);
    }
};

class I_M_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(I_M_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_FENCE, G_InstrType::G_INSTR_FENCEI});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_I_M);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0x0FF);
    }
};

class I_S_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(I_S_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_CSRRW, G_InstrType::G_INSTR_CSRRS, G_InstrType::G_INSTR_CSRRC,
                                              G_InstrType::G_INSTR_CSRRWI, G_InstrType::G_INSTR_CSRRSI, G_InstrType::G_INSTR_CSRRCI,
                                              G_InstrType::G_INSTR_PRIV});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_I_S);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        std::list<unsigned int> allowed_CSRs({0x300, 0x301, 0x302, 0x303, 0x304, 0x305, 0x306,
                                             0x340, 0x341, 0x342, 0x343, 0x344,
                                             0xF11, 0xF12, 0xF13, 0xF14});
        decodedInstr->G_imm.keep_only(allowed_CSRs);
    }
};

class S_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(S_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_SB, G_InstrType::G_INSTR_SH, G_InstrType::G_INSTR_SW});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_S);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0xFFF);
    }
};

class B_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(B_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_BEQ, G_InstrType::G_INSTR_BNE, G_InstrType::G_INSTR_BLT,
                                              G_InstrType::G_INSTR_BGE, G_InstrType::G_INSTR_BLTU, G_InstrType::G_INSTR_BGEU});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_B);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0x1FFF);
    }
};

class U_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(U_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_LUI, G_InstrType::G_INSTR_AUIPC});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_U);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0xFFFFFFFF);
    }
};

class J_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(J_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_JAL});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_J);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() = 0);//doesn't have an effect
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() <= 0xFFFFF);
    }
};

class Mini_Type : virtual public scv_constraint_base {
public:
    scv_smart_ptr<G_DecodedInstr> decodedInstr;
SCV_CONSTRAINT_CTOR(Mini_Type) {
        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_ADD, G_InstrType::G_INSTR_SUB, G_InstrType::G_INSTR_SLL, G_InstrType::G_INSTR_SLT,
                                              G_InstrType::G_INSTR_SLTU, G_InstrType::G_INSTR_XOR, G_InstrType::G_INSTR_SRL, G_InstrType::G_INSTR_SRA,
                                              G_InstrType::G_INSTR_OR, G_InstrType::G_INSTR_AND,
                                              G_InstrType::G_INSTR_ADDI, G_InstrType::G_INSTR_SLLI, G_InstrType::G_INSTR_SLTI, G_InstrType::G_INSTR_SLTUI,
                                              G_InstrType::G_INSTR_XORI, G_InstrType::G_INSTR_SRLI, G_InstrType::G_INSTR_SRAI, G_InstrType::G_INSTR_ORI,
                                              G_InstrType::G_INSTR_ANDI,
                                              G_InstrType::G_INSTR_LB, G_InstrType::G_INSTR_LH, G_InstrType::G_INSTR_LBU, G_InstrType::G_INSTR_LHU,
                                              G_InstrType::G_INSTR_LW,
                                              G_InstrType::G_INSTR_JALR,
                                              G_InstrType::G_INSTR_SB, G_InstrType::G_INSTR_SH, G_InstrType::G_INSTR_SW,
                                              G_InstrType::G_INSTR_BEQ, G_InstrType::G_INSTR_BNE, G_InstrType::G_INSTR_BLT,
                                              G_InstrType::G_INSTR_BGE, G_InstrType::G_INSTR_BLTU, G_InstrType::G_INSTR_BGEU,
                                              G_InstrType::G_INSTR_LUI, G_InstrType::G_INSTR_AUIPC,
                                              G_InstrType::G_INSTR_JAL});
        decodedInstr->G_instrType.keep_only(allowed_instr);
        std::list<G_EncType> allowed_enc({G_EncType::G_ENC_R, G_EncType::G_ENC_I_I, G_EncType::G_ENC_I_L, G_EncType::G_ENC_I_J, G_EncType::G_ENC_S, G_EncType::G_ENC_B,
                                          G_EncType::G_ENC_U, G_EncType::G_ENC_J});
        decodedInstr->G_encType.keep_only(allowed_enc);
        SCV_CONSTRAINT(decodedInstr->G_rs1_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rs2_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_rd_addr() < 32);
        SCV_CONSTRAINT(decodedInstr->G_imm() = 0xFFFFFFFF);
    }
};



inline void constrain_instr(scv_smart_ptr<G_DecodedInstr>& sp, instr_constraint_type t){
    switch(t){
        case R_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_ADD, G_InstrType::G_INSTR_SUB, G_InstrType::G_INSTR_SLL, G_InstrType::G_INSTR_SLT,
                                                  G_InstrType::G_INSTR_SLTU, G_InstrType::G_INSTR_XOR, G_InstrType::G_INSTR_SRL, G_InstrType::G_INSTR_SRA,
                                                  G_InstrType::G_INSTR_OR, G_InstrType::G_INSTR_AND});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_R);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 31);
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0);//doesn't have an effect
            break;
        }
        case I_I_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_ADDI, G_InstrType::G_INSTR_SLLI, G_InstrType::G_INSTR_SLTI, G_InstrType::G_INSTR_SLTUI,
                                                  G_InstrType::G_INSTR_XORI, G_InstrType::G_INSTR_SRLI, G_InstrType::G_INSTR_SRAI, G_InstrType::G_INSTR_ORI,
                                                  G_InstrType::G_INSTR_ANDI});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_I_I);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 0);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0xFFF);
            break;
        }
        case I_L_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_LB, G_InstrType::G_INSTR_LH, G_InstrType::G_INSTR_LBU, G_InstrType::G_INSTR_LHU, G_InstrType::G_INSTR_LW});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_I_L);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 0);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0xFFF);
            break;
        }
        case I_J_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_JALR});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_I_J);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 0);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0xFFF);
            break;
        }
        case I_M_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_FENCE, G_InstrType::G_INSTR_FENCEI});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_I_M);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 0);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0x0FF);
            break;
        }
        case I_S_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_CSRRW, G_InstrType::G_INSTR_CSRRS, G_InstrType::G_INSTR_CSRRC,
                                                  G_InstrType::G_INSTR_CSRRWI, G_InstrType::G_INSTR_CSRRSI, G_InstrType::G_INSTR_CSRRCI,
                                                  G_InstrType::G_INSTR_PRIV});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_I_S);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 0);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            std::list<unsigned int> allowed_CSRs({0x300, 0x301, 0x302, 0x303, 0x304, 0x305, 0x306,
                                                  0x340, 0x341, 0x342, 0x343, 0x344,
                                                  0xF11, 0xF12, 0xF13, 0xF14});
            sp->G_imm.keep_only(allowed_CSRs);
            break;
        }
        case S_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_SB, G_InstrType::G_INSTR_SH, G_InstrType::G_INSTR_SW});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_S);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 31);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 0);
            sp->G_imm.keep_only(0, 0xFFF);
            break;
        }
        case B_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_BEQ, G_InstrType::G_INSTR_BNE, G_InstrType::G_INSTR_BLT,
                                                  G_InstrType::G_INSTR_BGE, G_InstrType::G_INSTR_BLTU, G_InstrType::G_INSTR_BGEU});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_B);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 31);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 0);
            sp->G_imm.keep_only(0, 0x1FFF);
            break;
        }
        case U_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_LUI, G_InstrType::G_INSTR_AUIPC});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_U);
            sp->G_rs1_addr.keep_only(0, 0);
            sp->G_rs2_addr.keep_only(0, 0);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0xFFFFFFFF);
            break;
        }
        case J_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_JAL});
            sp->G_instrType.keep_only(allowed_instr);
            sp->G_encType.keep_only(G_EncType::G_ENC_J);
            sp->G_rs1_addr.keep_only(0, 0);
            sp->G_rs2_addr.keep_only(0, 0);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0xFFFFF);
            break;
        }
        case Mini_format:{
            std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_ADD, G_InstrType::G_INSTR_SUB, G_InstrType::G_INSTR_SLL, G_InstrType::G_INSTR_SLT,
                                                  G_InstrType::G_INSTR_SLTU, G_InstrType::G_INSTR_XOR, G_InstrType::G_INSTR_SRL, G_InstrType::G_INSTR_SRA,
                                                  G_InstrType::G_INSTR_OR, G_InstrType::G_INSTR_AND,
                                                  G_InstrType::G_INSTR_ADDI, G_InstrType::G_INSTR_SLLI, G_InstrType::G_INSTR_SLTI, G_InstrType::G_INSTR_SLTUI,
                                                  G_InstrType::G_INSTR_XORI, G_InstrType::G_INSTR_SRLI, G_InstrType::G_INSTR_SRAI, G_InstrType::G_INSTR_ORI,
                                                  G_InstrType::G_INSTR_ANDI,
                                                  G_InstrType::G_INSTR_LB, G_InstrType::G_INSTR_LH, G_InstrType::G_INSTR_LBU, G_InstrType::G_INSTR_LHU,
//                                                  G_InstrType::G_INSTR_LW,
                                                  G_InstrType::G_INSTR_JALR,
                                                  G_InstrType::G_INSTR_SB, G_InstrType::G_INSTR_SH, G_InstrType::G_INSTR_SW,
                                                  G_InstrType::G_INSTR_BEQ, G_InstrType::G_INSTR_BNE, G_InstrType::G_INSTR_BLT,
                                                  G_InstrType::G_INSTR_BGE, G_InstrType::G_INSTR_BLTU, G_InstrType::G_INSTR_BGEU//,
//                                                  G_InstrType::G_INSTR_LUI, G_InstrType::G_INSTR_AUIPC//,
//                                                  G_InstrType::G_INSTR_JAL
            });
            sp->G_instrType.keep_only(allowed_instr);
            std::list<G_EncType> allowed_enc({G_EncType::G_ENC_R, G_EncType::G_ENC_I_I,
                                              G_EncType::G_ENC_I_L,
                                              G_EncType::G_ENC_I_J,
                                              G_EncType::G_ENC_S,
                                              G_EncType::G_ENC_B//,
//                                              G_EncType::G_ENC_U//,
//                                              G_EncType::G_ENC_J
            });
            sp->G_encType.keep_only(allowed_enc);
            sp->G_rs1_addr.keep_only(0, 31);
            sp->G_rs2_addr.keep_only(0, 31);//doesn't have an effect
            sp->G_rd_addr.keep_only(0, 31);
            sp->G_imm.keep_only(0, 0xFFFFFFFF);
            break;
        }
        default:
            break;
    }
}


inline void constrain_instrEXT(scv_smart_ptr<G_DecodedInstrEXT>& sp, instr_constraint_type t) {
    switch (t) {
        case Mini_format: {
            scv_bag< G_EncType > field_dist;
            field_dist.add(G_ENC_R, 40);//20
            field_dist.add(G_ENC_I_I, 40);//20
            field_dist.add(G_ENC_I_L, 10);
            field_dist.add(G_ENC_I_J, 1);//1
            field_dist.add(G_ENC_S, 50);
            field_dist.add(G_ENC_B, 10);
            field_dist.add(G_ENC_U, 15);
            field_dist.add(G_ENC_J, 1);

            std::list<G_EncType> allowed_enc({G_ENC_R, G_ENC_I_I, G_ENC_I_L, G_ENC_I_J, G_ENC_S, G_ENC_B, G_ENC_U, G_ENC_J});
//            std::list<G_EncType> allowed_enc({G_ENC_R, G_ENC_I_I, G_ENC_I_L, G_ENC_I_J, G_ENC_S, G_ENC_U});

            std::list<G_InstrType> R_instr({G_InstrType::G_INSTR_ADD, G_InstrType::G_INSTR_SUB, G_InstrType::G_INSTR_SLL, G_InstrType::G_INSTR_SLT,
                                            G_InstrType::G_INSTR_SLTU, G_InstrType::G_INSTR_XOR, G_InstrType::G_INSTR_SRL, G_InstrType::G_INSTR_SRA,
                                            G_InstrType::G_INSTR_OR, G_InstrType::G_INSTR_AND});

            std::list<G_InstrType> I_I_instr({G_InstrType::G_INSTR_ADDI, G_InstrType::G_INSTR_SLLI, G_InstrType::G_INSTR_SLTI, G_InstrType::G_INSTR_SLTUI,
                                            G_InstrType::G_INSTR_XORI, G_InstrType::G_INSTR_SRLI, G_InstrType::G_INSTR_SRAI, G_InstrType::G_INSTR_ORI,
                                            G_InstrType::G_INSTR_ANDI});

            std::list<G_InstrType> I_L_instr({G_InstrType::G_INSTR_LB, G_InstrType::G_INSTR_LH, G_InstrType::G_INSTR_LBU, G_InstrType::G_INSTR_LHU,
//                                                  G_InstrType::G_INSTR_LW,
                                             });

            std::list<G_InstrType> I_J_instr({G_InstrType::G_INSTR_JALR});

            std::list<G_InstrType> S_instr({G_InstrType::G_INSTR_SB, G_InstrType::G_INSTR_SH, G_InstrType::G_INSTR_SW});

            std::list<G_InstrType> B_instr({G_InstrType::G_INSTR_BEQ, G_InstrType::G_INSTR_BNE, G_InstrType::G_INSTR_BLT,
                                            G_InstrType::G_INSTR_BGE, G_InstrType::G_INSTR_BLTU, G_InstrType::G_INSTR_BGEU});

            std::list<G_InstrType> U_instr({G_InstrType::G_INSTR_LUI, G_InstrType::G_INSTR_AUIPC});

            std::list<G_InstrType> J_instr({G_InstrType::G_INSTR_JAL});


            sp->encType.set_mode(field_dist);
//            sp->encType.keep_only(allowed_enc);
            sp->r_instr.keep_only(R_instr);
            sp->i_i_instr.keep_only(I_I_instr);
            sp->i_l_instr.keep_only(I_L_instr);
            sp->i_j_instr.keep_only(I_J_instr);
            sp->s_instr.keep_only(S_instr);
            sp->b_instr.keep_only(B_instr);
            sp->u_instr.keep_only(U_instr);
            sp->j_instr.keep_only(J_instr);
            sp->rs1_addr.keep_only(0, 31);
            sp->rs2_addr.keep_only(0, 31);//doesn't have an effect
            sp->rd_addr.keep_only(0, 31);
            sp->imm.keep_only(0, 0xFFFFFFFF);
            break;
        }
        default:
            break;
    }
}
#endif //UVMSYSTEMC_INSTRUCTION_CONSTRAINTS_H
