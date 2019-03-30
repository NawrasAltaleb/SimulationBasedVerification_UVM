//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: scoreboard
 *  - The scoreboard performs end-to-end checking by comparing expected and processed transactions
 *      Remark: in our implementation we will be comparing the expected value (coming from ISA as golden model) with the processed value (coming form DUT)
 *  - These transactions are retrieved by dedicated subscribers or listeners, which implement the "write" method of the analysis ports of each monitor, to which
 *      these subscribers are connected.
 *      Remark: one subscriber connected to Active-Agent's-Driver's analysis port representing the "fromMemory" connection, and one subscriber connected to the
 *              Passive-Agent's-Monitor's analysis port representing the "toMemory" connection.
 *  - A scoreboard may contain a predictor, which acts as reference or golden model. Alternatively, the scoreboard may contain an algorithm to calculate the expected
 *      transaction. Remark: our scoreboard will have ISA as a golden model.
 */
#ifndef UVMSYSTEMC_SCOREBOARD_H
#define UVMSYSTEMC_SCOREBOARD_H

#include "subscriber.h"
#include "Interfaces.h"
#include "Golden_Reference/Bus.h"
using namespace uvm;

//#define DEBUG

class scoreboard : public uvm_scoreboard {
public:
    uvm_analysis_export<vip_trans_bus_req_t> listener_fromMaster; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_toMaster; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_toSlave0; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_toSlave1; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_toSlave2; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_toSlave3; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_fromSlave0; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_fromSlave1; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_fromSlave2; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_fromSlave3; /// Exports used to connect to the subscribers

    subscriber_REQ *subscr_Master_req;
    subscriber_RSP *subscr_Master_rsp;
    subscriber_REQ *subscr_Slave0_req;
    subscriber_REQ *subscr_Slave1_req;
    subscriber_REQ *subscr_Slave2_req;
    subscriber_REQ *subscr_Slave3_req;
    subscriber_RSP *subscr_Slave0_rsp;
    subscriber_RSP *subscr_Slave1_rsp;
    subscriber_RSP *subscr_Slave2_rsp;
    subscriber_RSP *subscr_Slave3_rsp;


    /// instance of ISA need to be added to the scoreboard
    GoldenBus goldenReference;
    // Channel instantiation
    Blocking<bus_req_t> master_in;
    Blocking<bus_resp_t> slave_in0;
    Blocking<bus_resp_t> slave_in1;
    Blocking<bus_resp_t> slave_in2;
    Blocking<bus_resp_t> slave_in3;
    //Out-por
    Blocking<bus_resp_t> master_out;
    Blocking<bus_req_t> slave_out0;
    Blocking<bus_req_t> slave_out1;
    Blocking<bus_req_t> slave_out2;
    Blocking<bus_req_t> slave_out3;
    // Variables for communicating with goldenReference
    vip_trans_bus_resp_t toMaster_trans;
    vip_trans_bus_req_t toSlave0_trans;
    vip_trans_bus_req_t toSlave1_trans;
    vip_trans_bus_req_t toSlave2_trans;
    vip_trans_bus_req_t toSlave3_trans;

    scoreboard(uvm_component_name name) : uvm_scoreboard(name),
                                          master_in("master_in"), slave_in0("slave_in0"), slave_in1("slave_in1"), slave_in2("slave_in2"), slave_in3("slave_in3"),
                                          master_out("master_out"), slave_out0("slave_out0"), slave_out1("slave_out1"), slave_out2("slave_out2"), slave_out3("slave_out3"),
                                            goldenReference("goldenModel"){
        //Port binding:
        goldenReference.master_in(master_in);
        goldenReference.slave_out0(slave_out0);
        goldenReference.slave_out1(slave_out1);
        goldenReference.slave_out2(slave_out2);
        goldenReference.slave_out3(slave_out3);
        goldenReference.slave_in0(slave_in0);
        goldenReference.slave_in1(slave_in1);
        goldenReference.slave_in2(slave_in2);
        goldenReference.slave_in3(slave_in3);
        goldenReference.master_out(master_out);
    }

    UVM_COMPONENT_UTILS(scoreboard)

    void build_phase(uvm_phase &phase) {
        uvm_scoreboard::build_phase(phase);

        uvm_config_db<uvm_object *>::set(this, "subscr_Master_req", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Master_req = subscriber_REQ::type_id::create("subscr_Master_req", this);
        assert(subscr_Master_req);

        uvm_config_db<uvm_object *>::set(this, "subscr_Master_rsp", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Master_rsp = subscriber_RSP::type_id::create("subscr_Master_rsp", this);
        assert(subscr_Master_rsp);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave0_req", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave0_req = subscriber_REQ::type_id::create("subscr_Slave0_req", this);
        assert(subscr_Slave0_req);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave1_req", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave1_req = subscriber_REQ::type_id::create("subscr_Slave1_req", this);
        assert(subscr_Slave1_req);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave2_req", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave2_req = subscriber_REQ::type_id::create("subscr_Slave2_req", this);
        assert(subscr_Slave2_req);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave3_req", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave3_req = subscriber_REQ::type_id::create("subscr_Slave3_req", this);
        assert(subscr_Slave3_req);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave0_rsp", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave0_rsp = subscriber_RSP::type_id::create("subscr_Slave0_rsp", this);
        assert(subscr_Slave0_rsp);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave1_rsp", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave1_rsp = subscriber_RSP::type_id::create("subscr_Slave1_rsp", this);
        assert(subscr_Slave1_rsp);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave2_rsp", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave2_rsp = subscriber_RSP::type_id::create("subscr_Slave2_rsp", this);
        assert(subscr_Slave2_rsp);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave3_rsp", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave3_rsp = subscriber_RSP::type_id::create("subscr_Slave3_rsp", this);
        assert(subscr_Slave3_rsp);
    }

    void connect_phase(uvm_phase &phase) {
        listener_fromMaster(subscr_Master_req->analysis_export);
        listener_toMaster(subscr_Master_rsp->analysis_export);
        listener_toSlave0(subscr_Slave0_req->analysis_export);
        listener_toSlave1(subscr_Slave1_req->analysis_export);
        listener_toSlave2(subscr_Slave2_req->analysis_export);
        listener_toSlave3(subscr_Slave3_req->analysis_export);
        listener_fromSlave0(subscr_Slave0_rsp->analysis_export);
        listener_fromSlave1(subscr_Slave1_rsp->analysis_export);
        listener_fromSlave2(subscr_Slave2_rsp->analysis_export);
        listener_fromSlave3(subscr_Slave3_rsp->analysis_export);
    }


    /// Via the subscribers the expected and the processed transactions become available which are used for the actual checking
    void write_listener_fromMaster(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "-------- fromMaster -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        master_in.write(t.bus_req);
    }

    void write_listener_toMaster(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-------- toMaster -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        master_out.read(toMaster_trans.bus_resp);

        if (!t.do_compare(toMaster_trans)) {
            std::stringstream message;
            message << "DUT: data(" << t.bus_resp.data << ") ack(" << t.bus_resp.ack << ") --- ";
            message << "GM: data(" << toMaster_trans.bus_resp.data << ") ack(" << toMaster_trans.bus_resp.ack << ")";
            uvm_report_error("toMaster", message.str(), UVM_MEDIUM);
        }
    }

    void write_listener_toSlave0(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave0 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        slave_out0.read(toSlave0_trans.bus_req);

        if (!t.do_compare(toSlave0_trans)) {
            std::stringstream message;
            message << "DUT: addr(" << t.bus_req.addr << ") data(" << t.bus_req.data << ") trans(" << t.bus_req.trans_type << ") --- ";
            message << "GM: addr(" << toSlave0_trans.bus_req.addr << ") data(" << toSlave0_trans.bus_req.data << ") trans(" << toSlave0_trans.bus_req.trans_type << ")";
            uvm_report_error("toSlave0", message.str(), UVM_MEDIUM);
        }
    }

    void write_listener_toSlave1(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave1 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        slave_out1.read(toSlave1_trans.bus_req);

        if (!t.do_compare(toSlave1_trans)) {
            std::stringstream message;
            message << "DUT: addr(" << t.bus_req.addr << ") data(" << t.bus_req.data << ") trans(" << t.bus_req.trans_type << ") --- ";
            message << "GM: addr(" << toSlave1_trans.bus_req.addr << ") data(" << toSlave1_trans.bus_req.data << ") trans(" << toSlave1_trans.bus_req.trans_type << ")";
            uvm_report_error("toSlave1", message.str(), UVM_MEDIUM);
        }
    }

    void write_listener_toSlave2(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave2 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        slave_out2.read(toSlave2_trans.bus_req);

        if (!t.do_compare(toSlave2_trans)) {
            std::stringstream message;
            message << "DUT: addr(" << t.bus_req.addr << ") data(" << t.bus_req.data << ") trans(" << t.bus_req.trans_type << ") --- ";
            message << "GM: addr(" << toSlave2_trans.bus_req.addr << ") data(" << toSlave2_trans.bus_req.data << ") trans(" << toSlave2_trans.bus_req.trans_type << ")";
            uvm_report_error("toSlave2", message.str(), UVM_MEDIUM);
        }
    }

    void write_listener_toSlave3(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave3 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        slave_out3.read(toSlave3_trans.bus_req);
        if (!t.do_compare(toSlave3_trans)) {
            std::stringstream message;
            message << "DUT: addr(" << t.bus_req.addr << ") data(" << t.bus_req.data << ") trans(" << t.bus_req.trans_type << ") --- ";
            message << "GM: addr(" << toSlave3_trans.bus_req.addr << ") data(" << toSlave3_trans.bus_req.data << ") trans(" << toSlave3_trans.bus_req.trans_type << ")";
            uvm_report_error("toSlave3", message.str(), UVM_MEDIUM);
        }
    }

    void write_listener_fromSlave0(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave0 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        slave_in0.write(t.bus_resp);
    }

    void write_listener_fromSlave1(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave1 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        slave_in1.write(t.bus_resp);
    }

    void write_listener_fromSlave2(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave2 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        slave_in2.write(t.bus_resp);
    }

    void write_listener_fromSlave3(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave3 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        slave_in3.write(t.bus_resp);
    }

};

#endif //UVMSYSTEMC_SCOREBOARD_H
