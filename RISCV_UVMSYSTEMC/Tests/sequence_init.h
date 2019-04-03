//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: UVM sequence
 * - Sequences are part of the test scenario and define streams of transactions.
 *      Remark: That's why we should separate different scenarios (Reg_Reg, Reg_Imm ..) into different tests having specific sequences (with specific constrains)
 * - The properties (or attributes) of a transaction are captured in a sequence item.
 * - Sequences are NOT part of the testbench hierarchy, but are mapped onto one or more sequenceRs.
 * - Sequences can be layered, hierarchical or virtual, and may contain multiple sequences or sequence items.
 *      Remark: does this mean that the same sequence will have a sub_sequence for instructions and a sub_sequence for loaded data!?
 * - Sequences and transactions can be configured via the factory.
 * -
 */
#ifndef UVMSYSTEMC_SEQUENCE_INIT_H
#define UVMSYSTEMC_SEQUENCE_INIT_H

#include <uvm>
using namespace uvm;
// my version
#include <scv.h>
#include "Tests/Randomness/Data_ext.h"
#include "Tests/Randomness/Encoder.h"
#include "Tests/Randomness/Instruction_constraints.h"

#define MINI_NUM_TRANS 30300
#define CHECK_INTERVAL 10000


unsigned int li_instr_2[32] = {
        0x16400013,     //li    x0,100
        0x06500093,     //li    x1,101
        0x08000113,     //li    x2,102
        0x00100193,     //li    x3,103
        0x52600213,     //li    x4,104
        0x65600293,     //li    x5,105
        0x36A00313,     //li    x6,106
        0x06B00393,     //li    x7,107
        0x06C00413,     //li    x8,108
        0x16D00493,     //li    x9,109
        0x00100513,     //li    x10,110
        0x66F00593,     //li    x11,111
        0x87000613,     //li    x12,112
        0x17100693,     //li    x13,113
        0x37200713,     //li    x14,114
        0x27300793,     //li    x15,115
        0x47400813,     //li    x16,116
        0x97500893,     //li    x17,117
        0x00100913,     //li    x18,118
        0x57700993,     //li    x19,119
        0x67800A13,     //li    x20,120
        0xB7900A93,     //li    x21,121
        0x67A00B13,     //li    x22,122
        0x77B00B93,     //li    x23,123
        0xE7C00C13,     //li    x24,124
        0x77D00C93,     //li    x25,125
        0x27E00D13,     //li    x26,126
        0x07F00D93,     //li    x27,127
        0x00100E13,     //li    x28,128
        0x68100E93,     //li    x29,129
        0xC8200F13,     //li    x30,130
        0xF8300F93      //li    x31,131
};

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_mini : public uvm_sequence<RSP,REQ> {
private:
    int num_instr = 0;
    unsigned int next_instr;
    unsigned int program[MINI_NUM_TRANS];
    scv_smart_ptr<unsigned int> loadedData;
    bool ebreak_req = false;

    unsigned int contact_memory(REQ *req) {
        unsigned int result = 0;
        if (req->toMemory.req == ME_AccessType::ME_RD) {
            if (req->toMemory.mask == MT_W) {
                num_instr++;
                result = program[(req->toMemory.addrIn / 4) % MINI_NUM_TRANS];
//                if(this->get_name() == "seq_gm")
//                    cout<<hex<<"reading Insr from 0x"<<req->toMemory.addrIn<<" instruction 0x"<<result<<"\n";

//                if(this->get_name() == "seq_dut")
//                    cout<<"\t\t\t\t\t\t\t\t\t\t\t";
//                    cout<<hex<<"reading Inst from 0x"<<req->toMemory.addrIn<<" instruction 0x"<<result<<"\n";
            } else if (req->toMemory.mask == MT_X) {
                cout << this->get_name() << " Wrong memory access!!!!\n";
            } else {
                loadedData->next();
                result = *loadedData;
//                result = num_loaded;
//                num_loaded++;
//                if(this->get_name() == "seq_dut")
//                    cout<<"\t\t\t\t\t\t\t\t\t\t\t";
//                cout<<hex<<"reading data with mask: "<<req->toMemory.mask<<dec<<" data 0x"<<result<<"\n";
            }
        } else if (req->toMemory.req == ME_AccessType::ME_WR) {
            result = 0;
        } else if (req->toMemory.req == ME_AccessType::ME_X) {
            cout << this->get_name() << " Wrong memory access!!!!\n";
        }

        return result;
    }

    void check_internals(RSP *rsp, REQ *req) {
        std::cout<<this->get_name()<< " - Checking Internals registers\n";
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            /// In the case of a previous load or store contact memory
            while ((req->toMemory.req == ME_AccessType::ME_WR) ||
                    (req->toMemory.req == ME_AccessType::ME_RD &&  req->toMemory.mask != MT_W)) {
                rsp = new RSP();
                if(req->toMemory.req == ME_AccessType::ME_WR)
                    rsp->fromMemory.loadedData = 0x0;
                else {
                    loadedData->next();
                    rsp->fromMemory.loadedData = *loadedData;
                }
                req = new REQ();
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
            }
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        // first time should not be a ME_WR because we already sent a series of nop operations
        for (i = 0; i < 32; i++) {
            /// In the case of a previous load or store contact memory
            while (req->toMemory.req == ME_AccessType::ME_WR ) {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0x0;
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
            }
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            /// In the case of a previous load or store contact memory
            while (req->toMemory.req == ME_AccessType::ME_WR) {// || (req->toMemory.req == ME_AccessType::ME_RD && req->toMemory.addrIn >= instr_mem_end)) {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
            }
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
//        std::cout<<"Checking Internals registers: done\n";
    }
public:
    int seedNUM;

    sequence_mini(const std::string &name)
            : uvm_sequence<RSP,REQ>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_mini<RSP,REQ>);

    void pre_body() {
        scv_smart_ptr<G_DecodedInstrEXT> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instrEXT(decodedInstr, Mini_format);
        loadedData->set_random(gseed);

        int i;
        /// Load registers with immediate values
        for(i = 0; i<32; i++)
            program[i] = li_instr_2[i];

        /// Create random program
        G_DecodedInstr d_Instr;
        while (i<MINI_NUM_TRANS-5) {
            decodedInstr->next();

            d_Instr.G_encType = (*decodedInstr).encType;
            d_Instr.G_rs1_addr = (*decodedInstr).rs1_addr;
            d_Instr.G_rs2_addr = (*decodedInstr).rs2_addr;
            d_Instr.G_rd_addr = (*decodedInstr).rd_addr;
            d_Instr.G_imm = (*decodedInstr).imm;

            if ((*decodedInstr).encType == G_ENC_R) {
                d_Instr.G_instrType = (*decodedInstr).r_instr;
                program[i] = encode_instruction(d_Instr);

            } else if ((*decodedInstr).encType == G_ENC_I_I) {
                d_Instr.G_instrType = (*decodedInstr).i_i_instr;
                program[i] = encode_instruction(d_Instr);

            } else if ((*decodedInstr).encType == G_ENC_I_L) {
                d_Instr.G_instrType = (*decodedInstr).i_l_instr;
                program[i] = encode_instruction(d_Instr);

            } else if ((*decodedInstr).encType == G_ENC_I_J) {
                d_Instr.G_instrType = (*decodedInstr).i_j_instr;
                program[i] = encode_instruction(d_Instr);

            } else if ((*decodedInstr).encType == G_ENC_S) {
                d_Instr.G_instrType = (*decodedInstr).s_instr;
                program[i] = encode_instruction(d_Instr);

            } else if ((*decodedInstr).encType == G_ENC_B) {
                d_Instr.G_instrType = (*decodedInstr).b_instr;
                program[i] = encode_instruction(d_Instr);

            } else if ((*decodedInstr).encType == G_ENC_U) {
                d_Instr.G_instrType = (*decodedInstr).u_instr;
                program[i] = encode_instruction(d_Instr);

            } else if ((*decodedInstr).encType == G_ENC_J) {
                d_Instr.G_instrType = (*decodedInstr).j_instr;
                program[i] = encode_instruction(d_Instr);
            }

            if((*decodedInstr).encType == G_ENC_I_J || (*decodedInstr).encType == G_ENC_B || (*decodedInstr).encType == G_ENC_J){
                program[++i] = 0x13;
                program[++i] = 0x13;
            }

            i++;
        }
        while(i<MINI_NUM_TRANS - 1){
            program[i] = 0x13;
            i++;
        }
        program[i] = 0x00100073; // EBREAK
    }

    void body() {
        RSP *rsp;
        REQ *req;

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);
        next_instr = contact_memory(req);
        if(next_instr == 0x00100073)
            ebreak_req = true;

        while(!ebreak_req){
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = next_instr;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
            next_instr = contact_memory(req);

            /// to make sure we are not intercepting any crucial execution, wait until a nop arrives (note: it should also test that the next_instr read is not a data)
            if ((num_instr > CHECK_INTERVAL) && next_instr == 0x13){
//                this->check_internals(rsp, req);
                num_instr = 0;
            }
            if(next_instr == 0x00100073) /// a better conditioning should include if(req->toMemory.addrIn) belong to Instr_mem
                ebreak_req = true;
        }

        this->check_internals(rsp, req);
        /// final instruction (eBreak)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = next_instr;
        this->start_item(rsp);
        this->finish_item(rsp);
    }

}; // class sequence

#endif //UVMSYSTEMC_SEQUENCE_INIT_H
