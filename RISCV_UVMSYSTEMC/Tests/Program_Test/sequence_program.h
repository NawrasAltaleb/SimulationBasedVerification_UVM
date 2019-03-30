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
#ifndef UVMSYSTEMC_SEQUENCE_PROGRAM_H
#define UVMSYSTEMC_SEQUENCE_PROGRAM_H

#include <uvm>
using namespace uvm;
#define CHECK_INTERVAL 50000

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_program : public uvm_sequence<RSP,REQ> {
private:
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
    int num_instr = 0;
    unsigned int next_instr;
    bool ebreak_req = false;

    unsigned int read_memory(REQ *req) {
        unsigned int result = 0;
        if(req->toMemory.mask == MT_W){
            result = *(mem + req->toMemory.addrIn + 0)
                     + ((*(mem + req->toMemory.addrIn + 1)) << 8)
                     + (*(mem + req->toMemory.addrIn + 2) << 16)
                     + (*(mem + req->toMemory.addrIn + 3) << 24);
        } else if (req->toMemory.mask == MT_H) {
            result = *(mem + req->toMemory.addrIn + 0)
                     + (*(mem + req->toMemory.addrIn + 1) << 8);
            // sign extend
            if ((result & 0x00008000)) {
                result = 0xFFFF0000 | (result & 0x0000FFFF);
            }
        } else if (req->toMemory.mask == MT_B) {
            result = *(mem + req->toMemory.addrIn + 0);
            // sign extend
            if ((result & 0x00000080)) {
                result = 0xFFFFFF00 | (result & 0x000000FF);
            }
        } else if (req->toMemory.mask == MT_HU) {
            result = *(mem + req->toMemory.addrIn + 0)
                     + (*(mem + req->toMemory.addrIn + 1) << 8);
        } else if (req->toMemory.mask == MT_BU) {
            result = *(mem + req->toMemory.addrIn + 0);
        }
        return result;
    }

    void write_memory(REQ *req) {
        if (req->toMemory.mask == MT_W) {
            *(mem + req->toMemory.addrIn + 0) = req->toMemory.dataIn & 0xFF;
            *(mem + req->toMemory.addrIn + 1) = (req->toMemory.dataIn >> 8) & 0xFF;
            *(mem + req->toMemory.addrIn + 2) = (req->toMemory.dataIn >> 16) & 0xFF;
            *(mem + req->toMemory.addrIn + 3) = (req->toMemory.dataIn >> 24) & 0xFF;
        } else if (req->toMemory.mask == MT_H) {
            *(mem + req->toMemory.addrIn + 0) = req->toMemory.dataIn & 0xFF;
            *(mem + req->toMemory.addrIn + 1) = (req->toMemory.dataIn >> 8) & 0xFF;
        } else if (req->toMemory.mask == MT_B) {
            *(mem + req->toMemory.addrIn + 0) = req->toMemory.dataIn & 0xFF;
        }
//        mem[req->toMemory.addrIn / 4] = req->toMemory.dataIn;
    }

    void check_internals() {
        std::cout<<"Checking Internals registers: start\n";
        RSP *rsp;
        REQ *req;
        for(int i = 0; i < 32; i++) {
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = sw_instr[i];
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);
            if (req->toMemory.req == ME_AccessType::ME_WR) {
                /// we can store it to a temp mem
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            }
        }
        std::cout<<"Checking Internals registers: done\n";

        /// Send one last instruction to reset the pc back 32 instructions
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = 0xF81FF06F; // j -32*4
        this->start_item(rsp);
        this->finish_item(rsp);
        this->get_response(req);
    }
public:
    uint8_t *mem;
    uint32_t size;

public:
    sequence_program(const std::string &name)
            : uvm_sequence<RSP,REQ>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_program<RSP,REQ>);

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
        next_instr = read_memory(req);
        if(next_instr == 0x00100073)
            ebreak_req = true;

        while(!ebreak_req){
            num_instr++;
            if(num_instr == CHECK_INTERVAL){
                num_instr = 0;
                this->check_internals();
            }
            rsp = new RSP();
            req = new REQ();
            rsp->fromMemory.loadedData = next_instr;
            this->start_item(rsp);
            this->finish_item(rsp);
            this->get_response(req);

            if (req->toMemory.req == ME_AccessType::ME_WR) {
                write_memory(req);
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;/// doesn't have any effect
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            }

            /// more transactions for load instruction
            if ((next_instr & 0x7F) == 0x03){
                next_instr = read_memory(req);
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = next_instr;
                this->start_item(rsp);
                this->finish_item(rsp);
                this->get_response(req); /// this should be an instruction
            }

            next_instr = read_memory(req);
            if(next_instr == 0x00100073) /// a better conditioning should include if(req->toMemory.addrIn) belong to Instr_mem
                ebreak_req = true;
        }

        this->check_internals();
        /// send ebreak instruction
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = next_instr;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// don't wait for a response
    }

}; // class sequence

#endif //UVMSYSTEMC_SEQUENCE_PROGRAM_H
