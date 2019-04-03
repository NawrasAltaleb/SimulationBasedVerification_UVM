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

using namespace uvm;
// my version
#include <scv.h>
#include "Tests/Randomness/Data_ext.h"

template <typename REQ = uvm_sequence_item, typename RSP = REQ>
class sequence_REQ : public uvm_sequence<REQ,RSP> {
public:
    sequence_REQ(const std::string &name)
            : uvm_sequence<REQ,RSP>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_REQ<REQ,RSP>);

    void pre_body()
    {
        // raise objection if started as a root sequence
//        if(this->starting_phase != NULL)
//            this->starting_phase->raise_objection(this);
    }

    void body() {
        REQ *req;
        RSP *rsp;
        scv_smart_ptr<bus_req_t> seqReq("seqReq");
        seqReq->addr.keep_only(0,40);

        for (int i = 0; i < 105; i++) {
            req = new REQ();
            rsp = new RSP();
            seqReq->next();
            req->bus_req.addr = (*seqReq).addr;
            req->bus_req.data = (*seqReq).data;
            req->bus_req.trans_type = (*seqReq).trans_type;
//            std::cout << "sequence ....."<< req->bus_req.addr <<"...... " << req->bus_req.data << " type " << req->bus_req.trans_type << "\n";
            this->start_item(req);
            this->finish_item(req);
            this->get_response(rsp);
        }
    }

    void post_body()
    {
        // drop objection if started as a root sequence
//        if(this->starting_phase != NULL)
//            this->starting_phase->drop_objection(this);
    }

}; // class sequence

template <typename REQ = uvm_sequence_item, typename RSP = REQ>
class sequence_RSP : public uvm_sequence<REQ,RSP> {
public:
    sequence_RSP(const std::string &name)
            : uvm_sequence<REQ,RSP>(name) {}

    UVM_OBJECT_PARAM_UTILS(sequence_RSP<REQ,RSP>);

    void pre_body()
    {
        // raise objection if started as a root sequence
//        if(this->starting_phase != NULL)
//            this->starting_phase->raise_objection(this);
    }

    void body() {
        REQ *req;
        RSP *rsp;
        scv_smart_ptr<bus_resp_t> seqRsp("seqRsp");
//        scv_bag< ack_t > field_dist;
//        field_dist.add(OK, 100);
//        field_dist.add(RTY, 10);
//        field_dist.add(ERR, 10);
//        seqRsp->ack.set_mode(field_dist);
        seqRsp->ack.keep_only(OK);

        for (int i = 0; i < 100; i++) {
            req = new REQ();
            rsp = new RSP();
            seqRsp->next();
            req->bus_resp.data = (*seqRsp).data;
            req->bus_resp.ack = (*seqRsp).ack;
//            std::cout << "sequence ........... " << req->bus_resp.data << " ack " << req->bus_resp.ack << "\n";
            this->start_item(req);
            this->finish_item(req);
            this->get_response(rsp);
        }
    }

    void post_body()
    {
        // drop objection if started as a root sequence
//        if(this->starting_phase != NULL)
//            this->starting_phase->drop_objection(this);
    }

}; // class sequence
#endif //UVMSYSTEMC_SEQUENCE_INIT_H
