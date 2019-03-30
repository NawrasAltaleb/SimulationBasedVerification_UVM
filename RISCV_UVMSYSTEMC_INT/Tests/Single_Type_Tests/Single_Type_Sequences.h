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
#define NUM_TRANS 100

unsigned int li_instr[32] = {
        0x06400013,     //li	x0,100
        0x06500093,     //li	x1,101
        0x06600113,     //li	x2,102
        0x06700193,     //li	x3,103
        0x06800213,     //li	x4,104
        0x06900293,     //li	x5,105
        0x06A00313,     //li	x6,106
        0x06B00393,     //li	x7,107
        0x06C00413,     //li	x8,108
        0x06D00493,     //li	x9,109
        0x06E00513,     //li	x10,110
        0x06F00593,     //li	x11,111
        0x07000613,     //li	x12,112
        0x07100693,     //li	x13,113
        0x07200713,     //li	x14,114
        0x07300793,     //li	x15,115
        0x07400813,     //li	x16,116
        0x07500893,     //li	x17,117
        0x07600913,     //li	x18,118
        0x07700993,     //li	x19,119
        0x07800A13,     //li	x20,120
        0x07900A93,     //li	x21,121
        0x07A00B13,     //li	x22,122
        0x07B00B93,     //li	x23,123
        0x07C00C13,     //li	x24,124
        0x07D00C93,     //li	x25,125
        0x07E00D13,     //li	x26,126
        0x07F00D93,     //li	x27,127
        0x08000E13,     //li	x28,128
        0x08100E93,     //li	x29,129
        0x08200F13,     //li	x30,130
        0x08300F93      //li	x31,131
};

unsigned int li_instr_2[32] = {
        0x16400013,     //li	x0,100
        0x06500093,     //li	x1,101
        0x08000113,     //li	x2,102
        0x00100193,     //li	x3,103
        0x52600213,     //li	x4,104
        0x65600293,     //li	x5,105
        0x36A00313,     //li	x6,106
        0x06B00393,     //li	x7,107
        0x06C00413,     //li	x8,108
        0x16D00493,     //li	x9,109
        0x00100513,     //li	x10,110
        0x66F00593,     //li	x11,111
        0x87000613,     //li	x12,112
        0x17100693,     //li	x13,113
        0x37200713,     //li	x14,114
        0x27300793,     //li	x15,115
        0x47400813,     //li	x16,116
        0x97500893,     //li	x17,117
        0x00100913,     //li	x18,118
        0x57700993,     //li	x19,119
        0x67800A13,     //li	x20,120
        0xB7900A93,     //li	x21,121
        0x67A00B13,     //li	x22,122
        0x77B00B93,     //li	x23,123
        0xE7C00C13,     //li	x24,124
        0x77D00C93,     //li	x25,125
        0x27E00D13,     //li	x26,126
        0x07F00D93,     //li	x27,127
        0x00100E13,     //li	x28,128
        0x68100E93,     //li	x29,129
        0xC8200F13,     //li	x30,130
        0xF8300F93      //li	x31,131
};

unsigned int sw_instr[32] = {
        0x00002023,     //sw x0, 0(x0)
        0x001020A3,     //sw x1, 1(x0)
        0x00202123,     //sw x2, 2(x0)
        0x003021A3,     //sw x3, 3(x0)
        0x00402223,     //sw x4, 4(x0)
        0x005022A3,     //sw x5, 5(x0)
        0x00602323,     //sw x6, 6(x0)
        0x007023A3,     //sw x7, 7(x0)
        0x00802423,     //sw x8, 8(x0)
        0x009024A3,     //sw x9, 9(x0)
        0x00A02523,     //sw x10, 10(x0)
        0x00B025A3,     //sw x11, 11(x0)
        0x00C02623,     //sw x12, 12(x0)
        0x00D026A3,     //sw x13, 13(x0)
        0x00E02723,     //sw x14, 14(x0)
        0x00F027A3,     //sw x15, 15(x0)
        0x01002823,     //sw x16, 16(x0)
        0x011028A3,     //sw x17, 17(x0)
        0x01202923,     //sw x18, 18(x0)
        0x013029A3,     //sw x19, 19(x0)
        0x01402A23,     //sw x20, 20(x0)
        0x01502AA3,     //sw x21, 21(x0)
        0x01602B23,     //sw x22, 22(x0)
        0x01702BA3,     //sw x23, 23(x0)
        0x01802C23,     //sw x24, 24(x0)
        0x01902CA3,     //sw x25, 25(x0)
        0x01A02D23,     //sw x26, 26(x0)
        0x01B02DA3,     //sw x27, 27(x0)
        0x01C02E23,     //sw x28, 28(x0)
        0x01D02EA3,     //sw x29, 29(x0)
        0x01E02F23,     //sw x30, 30(x0)
        0x01F02FA3      //sw x31, 31(x0)
};


template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_R : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;

    explicit sequence_R(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_R<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen", seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, R_format);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = i;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
//            std::cout<<"sequence " << this->get_name() << " ........... " <<hex<<rsp->fromMemory.loadedData<<"\n";
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_R

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_I_I : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;
    explicit sequence_I_I(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_I_I<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, I_I_format);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = i;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
//        constrain_instr(decodedInstr, I_I_format);
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_I_I

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_I_L : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;
    explicit sequence_I_L(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_I_L<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        scv_smart_ptr<unsigned int> loadedData("loadedData");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, I_L_format);
        loadedData->set_random(gseed);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = i;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
        for (int i = 0; i < NUM_TRANS; i++) {
            // send instruction
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);

            // send data //FIXME: can't always work because it's not always in this order from a pipelined point of view
            rsp = new RSP();
            req = new REQ();
            loadedData->next();
            rsp->fromMemory.loadedData = (*loadedData);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_I_L

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_I_J : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;
    explicit sequence_I_J(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_I_J<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, I_J_format);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = i;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
            /// First, send a couple of nop instructions to make sure no jumping instruction will flush any other instruction
            for (int i = 0; i < 4; i++) {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0x13;
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
            }
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_I_J

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_S : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;
    explicit sequence_S(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_S<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, S_format);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = i;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
        int i = 0;
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
            } else {
                rsp = new RSP();
                req = new REQ();
                decodedInstr->next();
                rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_S

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_B : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;
    explicit sequence_B(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_B<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, B_format);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            unsigned int val = ( (i & 0xFFF00000) >> 20) % 10;
            rsp->fromMemory.loadedData = (i & 0x000FFFFF) & (val << 20) ; /// In order to get some equal values
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
            /// First, send a couple of nop instructions to make sure no branching instruction will flush any other instruction
            for (int i = 0; i < 2; i++) {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0x13;
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
            }
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_B

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_U : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;
    explicit sequence_U(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_U<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, U_format);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = i;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_U

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_J : public uvm_sequence<RSP,REQ> {
public:
    int seedNUM;
    explicit sequence_J(const std::string &name) : uvm_sequence<RSP, REQ>(name) {}
    UVM_OBJECT_PARAM_UTILS(sequence_J<RSP, REQ>);

    void body() {
        RSP *rsp;
        REQ *req;
        scv_smart_ptr<G_DecodedInstr> decodedInstr("decodedInstr");
        /// decide on a constant random chain
        scv_shared_ptr<scv_random> gseed(new scv_random("gen",seedNUM));
        decodedInstr->set_random(gseed);
        constrain_instr(decodedInstr, J_format);

        /// send first dummy instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0;
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);

        /// Load registers with immediate values
        for (unsigned int &i : li_instr) {
            rsp = new RSP();
            req = new REQ();

            rsp->fromMemory.loadedData = i;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }

        /// main random cycle
        for (int i = 0; i < NUM_TRANS; i++) {
            rsp = new RSP();
            req = new REQ();
            decodedInstr->next();
            rsp->fromMemory.loadedData = encode_instruction(*decodedInstr);
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
            /// First, send a couple of nop instructions to make sure no branching instruction will flush any other instruction
            for (int i = 0; i < 2; i++) {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0x13;
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
            }
        }

        check_internals_exit();
    }

    void check_internals_exit() {
        RSP *rsp;
        REQ *req;
        int i = 0;
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = 0x13;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
        }
        while (i < 32) {
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            } else {
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = sw_instr[i];
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req);
                i++;
            }
        }
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
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
        rsp->fromMemory.loadedData = 0x100073;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// DUT would have brook by now and no response will be given
    }

}; // class sequence_J

#endif //UVMSYSTEMC_SINGLE_TYPE_SEQUENCES_H
