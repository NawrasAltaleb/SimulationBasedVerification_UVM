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
#define CHECK_INTERVAL 5000

template <typename RSP = uvm_sequence_item, typename REQ = uvm_sequence_item>
class sequence_program : public uvm_sequence<RSP,REQ> {
private:
    int num_instr = 0;
    unsigned int next_instr;
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
                } else
                    throw std::logic_error(std::string("@ME: Unauthorized read. Terminating!"));
            }
        } else if (req->toMemory.req == ME_AccessType::ME_WR) {
            if (req->toMemory.mask != MT_X) {
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
                } else if (req->toMemory.mask == MT_BU || req->toMemory.mask == MT_HU) {
                    throw std::logic_error(std::string("@ME: Unauthorized write, illegal mask. Terminating!"));
                } else {
                    throw std::logic_error(std::string("@ME: Unauthorized write. Terminating!"));
                }
            }
        } else {
            throw std::logic_error(std::string("@ME: Undefined memory req"));
        }
        return result;
    }


    void check_internals(RSP *rsp, REQ *req) {
        std::cout<<"Checking Internals registers: start\n";
        unsigned int temp_instr;
//        RSP *rsp;
//        REQ *req;
        int i = 0;
        std::cout<<"sequence: data: "<<dec<<req->toMemory.dataIn << " at address: "<<std::hex<<req->toMemory.addrIn<< "   with req="<< req->toMemory.req << "   and mask="<<req->toMemory.mask<<"\n";
        /// send a bunch of nop instructions to make sure all inprocess instructions are finished
        for (i = 0; i < 16; i++) {
            /// In the case of a previous load or store contact memory
            while (req->toMemory.req == ME_AccessType::ME_WR ) {//|| (req->toMemory.req == ME_AccessType::ME_RD && req->toMemory.addrIn >= instr_mem_end)) {
                temp_instr = contact_memory(req);
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = temp_instr;
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
        while(i<32) {
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
            /// In the case of a previous load or store contact memory
            while (req->toMemory.req == ME_AccessType::ME_WR) {// || (req->toMemory.req == ME_AccessType::ME_RD && req->toMemory.addrIn >= instr_mem_end)) {
//                temp_instr = contact_memory(req);
                rsp = new RSP();
                req = new REQ();
                rsp->fromMemory.loadedData = 0;//temp_instr;
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

        // Send one last instruction to reset the pc back 32 instructions followed by a nope
//        rsp = new RSP();
//        req = new REQ();
//        rsp->fromMemory.loadedData = 0xFC1FF06F; // j -16*4
////        rsp->fromMemory.loadedData = 0xF81FF06F; // j -32*4
////        rsp->fromMemory.loadedData = 0xFB7FF06F; // j -(32+5)*4
////        rsp->fromMemory.loadedData = 0xF01FF06F; // j -(32+32)*4
////        rsp->fromMemory.loadedData = 0xF01FF06F; // j -(32+32+1)*4
//        this->start_item(rsp);
//        this->finish_item(rsp);
//        this->get_response(req);
//
//        rsp = new RSP();
//        req = new REQ();
//        rsp->fromMemory.loadedData = 0x13;
//        this->start_item(rsp);
//        this->finish_item(rsp);
//        this->get_response(req);

        std::cout<<"Checking Internals registers: done\n";
    }
public:
    uint8_t *mem;
    uint32_t size;
    uint32_t instr_mem_end;

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

            /// pass to checking internals if the previous request was an instruction read request
            if((num_instr >= CHECK_INTERVAL) &&
               (req->toMemory.req == ME_AccessType::ME_RD && req->toMemory.addrIn < instr_mem_end)) {
                num_instr = 0;
//                this->check_internals(rsp, req);
            }

            if(next_instr == 0x00100073) /// a better conditioning should include if(req->toMemory.addrIn) belong to Instr_mem
                ebreak_req = true;
        }

//        this->check_internals(rsp, req);
        /// final instruction (eBreak)
        rsp = new RSP();
        req = new REQ();
        rsp->fromMemory.loadedData = next_instr;
        this->start_item(rsp);
        this->finish_item(rsp);
//        this->get_response(req); /// don't wait for a response
    }

}; // class sequence

#endif //UVMSYSTEMC_SEQUENCE_PROGRAM_H
