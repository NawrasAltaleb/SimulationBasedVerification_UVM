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
#ifndef UVMSYSTEMC_SINGLE_TYPE_SEQUENCES_H
#define UVMSYSTEMC_SINGLE_TYPE_SEQUENCES_H

#include <uvm>
using namespace uvm;

// my version
#include <scv.h>
#include "Tests/Randomness/Data_ext.h"
#include "Tests/Randomness/Encoder.h"
#include "Tests/Randomness/Instruction_constraints.h"


/// Remark: Don't forget to register every new sequence objects that you create in the factory using this macro: UVM_OBJECT_PARAM_UTILS()
/// Remark: To make sure that your entire sequence will be sent to the DUT make sure to raise an objection at the pre_body phase and drop it at the post_body phase.
#define NUM_TRANS 1000



template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_R : public uvm_sequence<RSP,REQ> {
public:
    sequence_R(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_R<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, R_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        //send final instruction indicating the end of the program code
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_R

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_I_I : public uvm_sequence<RSP,REQ> {
public:
    sequence_I_I(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_I_I<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, I_I_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        //send final instruction indicating the end of the program code (EBREAK instruction)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_I_I

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_I_L : public uvm_sequence<RSP,REQ> {
public:
    sequence_I_L(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_I_L<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        scv_smart_ptr<unsigned int> loadedData("loadedData");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, I_L_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            // send instruction
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);

            // send data
            rsp = new RSP();
            req = new REQ();
            loadedData->next();
            rsp->fromMemory.loadedData = (*loadedData);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        //send final instruction indicating the end of the program code (EBREAK instruction)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_I_L

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_I_J : public uvm_sequence<RSP,REQ> {
public:
    sequence_I_J(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_I_J<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, I_J_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        //send final instruction indicating the end of the program code (EBREAK instruction)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_I_J

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_S : public uvm_sequence<RSP,REQ> {
public:
    sequence_S(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_S<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, S_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
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

        //send final instruction indicating the end of the program code (EBREAK instruction)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_S

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_B : public uvm_sequence<RSP,REQ> {
public:
    sequence_B(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_B<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, B_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        //send final instruction indicating the end of the program code (EBREAK instruction)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_B

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_U : public uvm_sequence<RSP,REQ> {
public:
    sequence_U(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_U<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, U_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        //send final instruction indicating the end of the program code (EBREAK instruction)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_U

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_J : public uvm_sequence<RSP,REQ> {
public:
    sequence_J(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_J<RSP, REQ>);

    void pre_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->raise_objection(this);
    }

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        constrain_instr(decodedInstr, J_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        //send final instruction indicating the end of the program code (EBREAK instruction)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req);
    }

    void post_body() {
        if(this->starting_phase != NULL)
            this->starting_phase->drop_objection(this);
    }
}; // class sequence_J

#endif //UVMSYSTEMC_SINGLE_TYPE_SEQUENCES_H
