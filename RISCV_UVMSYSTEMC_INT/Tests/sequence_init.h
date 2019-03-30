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

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_init : public uvm_sequence<RSP,REQ> {
public:
//    int seedNUM;
    sequence_init(const std::string &name)
            : uvm_sequence<RSP,REQ>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_init<RSP,REQ>);

//    void pre_body()
//    {
//        // raise objection if started as a root sequence
//        if(this->starting_phase != NULL)
//            this->starting_phase->raise_objection(this);
//    }

    void body() {
        RSP *rsp;
        REQ *req;
//        std::cout<<"sequence " << this->get_name() << "\n";
        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (int i = 0; i < 32; i++) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = li_instr[i];
//            std::cout<<"sequence ........... " <<req->fromMemory.loadedData<<"\n";
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

//        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
////        constrain_instr(decodedInstr, R_format);
//        /// decide on a constant random chain
//        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
//        decodedInstr->set_random(gseed);
//        std::list<G_InstrType> allowed_instr({G_InstrType::G_INSTR_ADD, G_InstrType::G_INSTR_SUB, G_InstrType::G_INSTR_SLL, G_InstrType::G_INSTR_SLT,
//                                              G_InstrType::G_INSTR_SLTU, G_InstrType::G_INSTR_XOR, G_InstrType::G_INSTR_SRL, G_InstrType::G_INSTR_SRA,
//                                              G_InstrType::G_INSTR_OR, G_InstrType::G_INSTR_AND});
//        decodedInstr->G_instrType.keep_only(allowed_instr);
//        decodedInstr->G_encType.keep_only(G_EncType::G_ENC_R);
//        decodedInstr->G_rs1_addr.keep_only(0, 32);
//        decodedInstr->G_rs2_addr.keep_only(0, 32);
//        decodedInstr->G_rd_addr.keep_only(0, 32);
//        decodedInstr->G_imm.keep_only(0, 0);//doesn't have an effect
//        for (int i = 0; i < 10; i++) {
//            decodedInstr->next();
//            std::cout<<"sequence " << this->get_name() << "...... instr: " <<(*decodedInstr).G_instrType<<" rs1: "<< (*decodedInstr).G_rs1_addr<< " ra2: "
//                                    << (*decodedInstr).G_rs2_addr<< " rd: "<< (*decodedInstr).G_rd_addr<< " ENC: " << (*decodedInstr).G_encType<< " imm: "<< (*decodedInstr).G_imm<< "\n";
//
//        }
        /// store registers values to memory
        for (int i = 0; i < 32; i++) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = sw_instr[i];
//            std::cout<<"sequence ........... " <<rsp->fromMemory.loadedData<<"\n";
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);

            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
//                std::cout<<"sequence: storing.... data: "<<dec<<req->toMemory.dataIn << " at address: "<<std::hex<<req->toMemory.addrIn<<"\n";
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            }
        }

        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (int i = 0; i < 10; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        /// final instruction (eBreak)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x00100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// don't wait for a response
    }

//    void post_body()
//    {
//        // drop objection if started as a root sequence
//        if(this->starting_phase != NULL)
//            this->starting_phase->drop_objection(this);
//    }

}; // class sequence







template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_mini : public uvm_sequence<RSP,REQ> {
private:
//    int num_loaded = 0;
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
                cout << this->get_name() << " FUUUUCCKKKKK!!!!\n";
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
            cout << this->get_name() << " FUUUUCCKKKKK!!!!\n";
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
        program[i] = 0x00100073;

//        if(this->get_name() == "seq_gm"){
//        for (auto &j : program) {
////            decodedInstr->next();
////            j = encode_instruction(*decodedInstr);
////            std::cout<<"sequence " << this->get_name() << hex << "...... instr: " <<(*decodedInstr).G_instrType<<" rs1: "<< (*decodedInstr).G_rs1_addr<< " rs2: "
////                                    << (*decodedInstr).G_rs2_addr<< " rd: "<< (*decodedInstr).G_rd_addr<< " ENC: " << (*decodedInstr).G_encType<< " imm: "<< (*decodedInstr).G_imm<< "\n";
//            cout<<hex<<j<<"\n";
//        }}
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

/*
template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_hex : public uvm_sequence<RSP,REQ> {
private:
    int num_instr = 0;
    int num_loaded = 0;
    unsigned int next_instr;
    unsigned int program[MINI_NUM_TRANS];
    scv_smart_ptr<unsigned int> loadedData;
    unsigned char mem[MEM_DEPTH] = {}; // memory contents //zero initialize
    bool ebreak_req = false;

    unsigned int contact_memory(REQ *req) {
        unsigned int result = 0;
        if (req->toMemory.req == ME_AccessType::ME_RD) {
            if (req->toMemory.mask != MT_X) {
                if (req->toMemory.mask == MT_W) {
                    result = *(mem + req->toMemory.addrIn + 0)
                             + ((*(mem + req->toMemory.addrIn + 1)) << 8)
                             + (*(mem + req->toMemory.addrIn + 2) << 16)
                             + (*(mem + req->toMemory.addrIn + 3) << 24);
                } else {
                    result = num_loaded;
                    num_loaded++;
                }
            }
        } else if (req->toMemory.req == ME_AccessType::ME_WR) {
            result = 0;
        } else {
            throw std::logic_error(std::string("@ME: Undefined memory req"));
        }
//        if (req->toMemory.req == ME_AccessType::ME_RD) {
//            if (req->toMemory.mask == MT_W) {
////                result = someshit[num_instr];
//                result = program[num_instr];
//                num_instr++;
////                result = program[(req->toMemory.addrIn) % MINI_NUM_TRANS];
////                result = program[req->toMemory.addrIn / 4];
////                if(this->get_name() == "seq_gm")
////                    cout<<hex<<"reading Insr from 0x"<<req->toMemory.addrIn<<" instruction 0x"<<result<<"\n";
//
//                if(this->get_name() == "seq_dut")
////                    cout<<"\t\t\t\t\t\t\t\t\t\t\t";
//                    cout<<hex<<"reading Inst from 0x"<<req->toMemory.addrIn<<" instruction 0x"<<result<<"\n";
//            } else if (req->toMemory.mask == MT_X) {
//                cout << this->get_name() << " FUUUUCCKKKKK!!!!\n";
//            } else {
//                loadedData->next();
////                result = *loadedData;
//                result = num_loaded;
//                num_loaded++;
//                if(this->get_name() == "seq_dut")
////                    cout<<"\t\t\t\t\t\t\t\t\t\t\t";
//                    cout<<hex<<"reading data with mask: "<<req->toMemory.mask<<dec<<" data 0x"<<result<<"\n";
////                result = program[(req->toMemory.addrIn) % MINI_NUM_TRANS];
////                if(this->get_name() == "seq_gm")
////                    cout<<hex<<this->get_name()<< "  reading Data from 0x"<<req->toMemory.addrIn<<" data 0x"<<result<<"\n";
//            }
//        } else if (req->toMemory.req == ME_AccessType::ME_WR) {
//            result = 0;
//        } else if (req->toMemory.req == ME_AccessType::ME_X) {
//            cout << this->get_name() << " FUUUUCCKKKKK!!!!\n";
//        }

        return result;
    }

    void check_internals(RSP *rsp, REQ *req) {
        std::cout<<this->get_name()<< " - Checking Internals registers: start\n";
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            /// In the case of a previous load or store contact memory
            while ((req->toMemory.req == ME_AccessType::ME_WR) ||
                   (req->toMemory.req == ME_AccessType::ME_RD && req->toMemory.mask != MT_W)) {
                rsp = new RSP();
                if(req->toMemory.req == ME_AccessType::ME_WR)
                    rsp->fromMemory.loadedData = 0x0;
                else{
                    loadedData->next();
//                    rsp->fromMemory.loadedData = *loadedData;
                    rsp->fromMemory.loadedData = num_loaded;
                    num_loaded++;
                    if(this->get_name() == "seq_dut")
//                        cout<<"\t\t\t\t\t\t\t\t\t\t\t";
                        cout<<hex<<"reading data with mask: "<<req->toMemory.mask<<dec<<" data 0x"<<*loadedData<<"\n";

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

    sequence_hex(const std::string &name)
            : uvm_sequence<RSP,REQ>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_hex<RSP,REQ>);

    void pre_body() {
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        loadedData->set_random(gseed);

        string hex_file_path = "/import/lab/users/altaleb/SCAM/bin/shit/randomLoad.hex";
        ifstream hex_file;
        open_hex_file(hex_file_path, hex_file);

        memset(mem, 0, sizeof(mem)); // clear the array

        string buff;
        int byte = 0;

        while (true) {

            // Little endian: Least significant byte in the smallest address...
            buff.clear();
            hex_file.width(2);
            hex_file >> buff;
            if (buff.empty()) break; // end of file
            unsigned char inst3 = (unsigned char) stoul(buff, nullptr, 16);

            buff.clear();
            hex_file.width(2);
            hex_file >> buff;
            if (buff.empty()) break; // end of file
            unsigned char inst2 = (unsigned char) stoul(buff, nullptr, 16);

            buff.clear();
            hex_file.width(2);
            hex_file >> buff;
            if (buff.empty()) break; // end of file
            unsigned char inst1 = (unsigned char) stoul(buff, nullptr, 16);

            buff.clear();
            hex_file.width(2);
            hex_file >> buff;
            if (buff.empty()) break; // end of file
            unsigned char inst0 = (unsigned char) stoul(buff, nullptr, 16);

            if (byte == MEM_DEPTH) {
                cout << "@IM: The program can't fit into memory!" << endl;
                sc_stop();
                wait(SC_ZERO_TIME);
            }
            mem[byte++] = inst0;

            if (byte == MEM_DEPTH) {
                cout << "@IM: The program can't fit into memory!" << endl;
                sc_stop();
                wait(SC_ZERO_TIME);
            }
            mem[byte++] = inst1;

            if (byte == MEM_DEPTH) {
                cout << "@IM: The program can't fit into memory!" << endl;
                sc_stop();
                wait(SC_ZERO_TIME);
            }
            mem[byte++] = inst2;

            if (byte == MEM_DEPTH) {
                cout << "@IM: The program can't fit into memory!" << endl;
                sc_stop();
                wait(SC_ZERO_TIME);
            }
            mem[byte++] = inst3;
        }
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
            num_instr++;
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = next_instr;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
            next_instr = contact_memory(req);

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
//        this->get_response(req); /// don't wait for a response
    }

}; // class sequence
*/
#endif //UVMSYSTEMC_SEQUENCE_INIT_H
