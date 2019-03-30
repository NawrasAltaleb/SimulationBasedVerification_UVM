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
    uvm_analysis_export<vip_trans_bus_req_t> listener_Master_REQ; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_Master_RSP; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave0_REQ; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave1_REQ; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave2_REQ; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave3_REQ; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_Slave0_RSP; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_Slave1_RSP; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_Slave2_RSP; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_resp_t> listener_Slave3_RSP; /// Exports used to connect to the subscribers

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
    Blocking<bus_req_t> master_req;
    Blocking<bus_resp_t> slave0_rsp;
    Blocking<bus_resp_t> slave1_rsp;
    Blocking<bus_resp_t> slave2_rsp;
    Blocking<bus_resp_t> slave3_rsp;
    //Out-por
    Blocking<bus_resp_t> master_rsp;
    Blocking<bus_req_t> slave0_req;
    Blocking<bus_req_t> slave1_req;
    Blocking<bus_req_t> slave2_req;
    Blocking<bus_req_t> slave3_req;
    // Variables for communicating with goldenReference
    vip_trans_bus_resp_t trans_Master_RSP;
    vip_trans_bus_req_t trans_Slave0_REQ;
    vip_trans_bus_req_t trans_Slave1_REQ;
    vip_trans_bus_req_t trans_Slave2_REQ;
    vip_trans_bus_req_t trans_Slave3_REQ;
    vector<vip_trans_bus_req_t> vec_Master_REQ;
    vector<vip_trans_bus_resp_t> vec_Master_RSP_dut;
    vector<vip_trans_bus_resp_t> vec_Master_RSP_gm;
    vector<vip_trans_bus_req_t> vec_Slave0_REQ_dut;
    vector<vip_trans_bus_req_t> vec_Slave0_REQ_gm;
    vector<vip_trans_bus_req_t> vec_Slave1_REQ_dut;
    vector<vip_trans_bus_req_t> vec_Slave1_REQ_gm;
    vector<vip_trans_bus_req_t> vec_Slave2_REQ_dut;
    vector<vip_trans_bus_req_t> vec_Slave2_REQ_gm;
    vector<vip_trans_bus_req_t> vec_Slave3_REQ_dut;
    vector<vip_trans_bus_req_t> vec_Slave3_REQ_gm;
    vector<vip_trans_bus_resp_t> vec_Slave0_RSP;
    vector<vip_trans_bus_resp_t> vec_Slave1_RSP;
    vector<vip_trans_bus_resp_t> vec_Slave2_RSP;
    vector<vip_trans_bus_resp_t> vec_Slave3_RSP;


    scoreboard(uvm_component_name name) : uvm_scoreboard(name),
        master_req("master_req"), slave0_rsp("slave0_rsp"), slave1_rsp("slave1_rsp"), slave2_rsp("slave2_rsp"), slave3_rsp("slave3_rsp"),
        master_rsp("master_rsp"), slave0_req("slave0_req"), slave1_req("slave1_req"), slave2_req("slave2_req"), slave3_req("slave3_req"),
        goldenReference("goldenModel") {
        //Port binding:
        goldenReference.master_in(master_req);
        goldenReference.slave_out0(slave0_req);
        goldenReference.slave_out1(slave1_req);
        goldenReference.slave_out2(slave2_req);
        goldenReference.slave_out3(slave3_req);
        goldenReference.slave_in0(slave0_rsp);
        goldenReference.slave_in1(slave1_rsp);
        goldenReference.slave_in2(slave2_rsp);
        goldenReference.slave_in3(slave3_rsp);
        goldenReference.master_out(master_rsp);
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
        listener_Master_REQ(subscr_Master_req->analysis_export);
        listener_Master_RSP(subscr_Master_rsp->analysis_export);
        listener_Slave0_REQ(subscr_Slave0_req->analysis_export);
        listener_Slave1_REQ(subscr_Slave1_req->analysis_export);
        listener_Slave2_REQ(subscr_Slave2_req->analysis_export);
        listener_Slave3_REQ(subscr_Slave3_req->analysis_export);
        listener_Slave0_RSP(subscr_Slave0_rsp->analysis_export);
        listener_Slave1_RSP(subscr_Slave1_rsp->analysis_export);
        listener_Slave2_RSP(subscr_Slave2_rsp->analysis_export);
        listener_Slave3_RSP(subscr_Slave3_rsp->analysis_export);
    }


    /// Via the subscribers the expected and the processed transactions become available which are used for the actual checking
    void write_listener_Master_REQ(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "-------- fromMaster -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Master_REQ.push_back(t);
    }

    void write_listener_Master_RSP(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-------- toMaster -------- data: " << t.bus_resp.data
                  << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        vec_Master_RSP_dut.push_back(t);
    }

    void write_listener_Slave0_REQ(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave0 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave0_REQ_dut.push_back(t);
    }

    void write_listener_Slave1_REQ(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave1 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave1_REQ_dut.push_back(t);
    }

    void write_listener_Slave2_REQ(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave2 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave2_REQ_dut.push_back(t);
    }

    void write_listener_Slave3_REQ(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave3 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave3_REQ_dut.push_back(t);
    }

    void write_listener_Slave0_RSP(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave0 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        vec_Slave0_RSP.push_back(t);
    }

    void write_listener_Slave1_RSP(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave1 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        vec_Slave1_RSP.push_back(t);
    }

    void write_listener_Slave2_RSP(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave2 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        vec_Slave2_RSP.push_back(t);
    }

    void write_listener_Slave3_RSP(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- fromSlave3 -------- data: " << t.bus_resp.data << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        vec_Slave3_RSP.push_back(t);
    }


    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&scoreboard::run_Master_REQ, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Master_RSP, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave0_REQ, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave1_REQ, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave2_REQ, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave3_REQ, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave0_RSP, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave1_RSP, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave2_RSP, this)),
                            sc_spawn(sc_bind(&scoreboard::run_Slave3_RSP, this)),
                            sc_spawn(sc_bind(&scoreboard::compareAll, this))
        SC_JOIN
    }


    void run_Master_REQ() {
        while (true) {
            if (!vec_Master_REQ.empty()){
                master_req.write(vec_Master_REQ.begin()->bus_req);
                vec_Master_REQ.erase(vec_Master_REQ.begin());
            }
            wait(SC_ZERO_TIME);
        }
    }

    void run_Master_RSP() {
        while (true) {
            master_rsp.read(trans_Master_RSP.bus_resp);
            vec_Master_RSP_gm.push_back(trans_Master_RSP);
            wait(SC_ZERO_TIME);
#ifdef DEBUG
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-------- GM toMaster -------- data: " << trans_Master_RSP.bus_resp.data
                      << " ack: " << trans_Master_RSP.bus_resp.ack << "  -- vector size: " << vec_Master_RSP_gm.size() << std::endl;
#endif
        }
    }

    void run_Slave0_RSP() {
        while (true) {
            if (!vec_Slave0_RSP.empty()){
                slave0_rsp.write(vec_Slave0_RSP.begin()->bus_resp);
                vec_Slave0_RSP.erase(vec_Slave0_RSP.begin());
            }
            wait(SC_ZERO_TIME);
        }
    }

    void run_Slave1_RSP() {
        while (true) {
            if (!vec_Slave1_RSP.empty()){
                slave1_rsp.write(vec_Slave1_RSP.begin()->bus_resp);
                vec_Slave1_RSP.erase(vec_Slave1_RSP.begin());
            }
            wait(SC_ZERO_TIME);
        }
    }

    void run_Slave2_RSP() {
        while (true) {
            if (!vec_Slave2_RSP.empty()){
                slave2_rsp.write(vec_Slave2_RSP.begin()->bus_resp);
                vec_Slave2_RSP.erase(vec_Slave2_RSP.begin());
            }
            wait(SC_ZERO_TIME);
        }
    }

    void run_Slave3_RSP() {
        while (true) {
            if (vec_Slave3_RSP.size() > 0){
                slave3_rsp.write(vec_Slave3_RSP.begin()->bus_resp);
                vec_Slave3_RSP.erase(vec_Slave3_RSP.begin());
            }
            wait(SC_ZERO_TIME);
        }
    }

    void run_Slave0_REQ() {
        while (true) {
            slave0_req.read(trans_Slave0_REQ.bus_req);
            vec_Slave0_REQ_gm.push_back(trans_Slave0_REQ);
            wait(SC_ZERO_TIME);
#ifdef DEBUG
            std::cout << "\t\t\t\t\t\t\t\t\t-------- GM toSlave0 -------- addr: " << trans_Slave0_REQ.bus_req.addr << " data: "
                      << trans_Slave0_REQ.bus_req.data << " trans: " << trans_Slave0_REQ.bus_req.trans_type << "  -- vector size: " << vec_Slave0_REQ_gm.size() << std::endl;
#endif
        }
    }

    void run_Slave1_REQ() {
        while (true) {
            slave1_req.read(trans_Slave1_REQ.bus_req);
            vec_Slave1_REQ_gm.push_back(trans_Slave1_REQ);
            wait(SC_ZERO_TIME);
#ifdef DEBUG
            std::cout << "\t\t\t\t\t\t\t\t\t-------- GM toSlave1 -------- addr: " << trans_Slave1_REQ.bus_req.addr << " data: "
                      << trans_Slave1_REQ.bus_req.data << " trans: " << trans_Slave1_REQ.bus_req.trans_type << "  -- vector size: " << vec_Slave1_REQ_gm.size() << std::endl;
#endif
        }
    }

    void run_Slave2_REQ() {
        while (true) {
            slave2_req.read(trans_Slave2_REQ.bus_req);
            vec_Slave2_REQ_gm.push_back(trans_Slave2_REQ);
            wait(SC_ZERO_TIME);
#ifdef DEBUG
            std::cout << "\t\t\t\t\t\t\t\t\t-------- GM toSlave2 -------- addr: " << trans_Slave2_REQ.bus_req.addr << " data: "
                      << trans_Slave2_REQ.bus_req.data << " trans: " << trans_Slave2_REQ.bus_req.trans_type << "  -- vector size: " << vec_Slave2_REQ_gm.size() << std::endl;
#endif
        }
    }

    void run_Slave3_REQ() {
        while (true) {
            slave3_req.read(trans_Slave3_REQ.bus_req);
            vec_Slave3_REQ_gm.push_back(trans_Slave3_REQ);
            wait(SC_ZERO_TIME);
#ifdef DEBUG
            std::cout << "\t\t\t\t\t\t\t\t\t-------- GM toSlave3 -------- addr: " << trans_Slave3_REQ.bus_req.addr << " data: "
                      << trans_Slave3_REQ.bus_req.data << " trans: " << trans_Slave3_REQ.bus_req.trans_type << "  -- vector size: " << vec_Slave3_REQ_gm.size() << std::endl;
#endif
        }
    }

    void compareAll() {
        while (true) {
            if (!vec_Master_RSP_dut.empty() && !vec_Master_RSP_gm.empty()) {
                vip_trans_bus_resp_t t_dut = *(vec_Master_RSP_dut.begin());
                vip_trans_bus_resp_t t_gm = *(vec_Master_RSP_gm.begin());

            if (!t_dut.do_compare(t_gm)) {
                std::stringstream message;
                message << "DUT: data(" << t_dut.bus_resp.data << ") ack(" << t_dut.bus_resp.ack << ") --- ";
                message << "GM: data(" << t_gm.bus_resp.data << ") ack(" << t_gm.bus_resp.ack << ")";
                uvm_report_error("Master_RSP", message.str(), UVM_MEDIUM);
            }

                vec_Master_RSP_dut.erase(vec_Master_RSP_dut.begin());
                vec_Master_RSP_gm.erase(vec_Master_RSP_gm.begin());
            }

            //////////////////////////////////////////////////////////////////

            if (!vec_Slave0_REQ_dut.empty() && !vec_Slave0_REQ_gm.empty()) {
                vip_trans_bus_req_t t_dut = *(vec_Slave0_REQ_dut.begin());
                vip_trans_bus_req_t t_gm = *(vec_Slave0_REQ_gm.begin());

                if (!t_dut.do_compare(t_gm)) {
                    std::stringstream message;
                    message << "DUT: addr(" << t_dut.bus_req.addr << ") data(" << t_dut.bus_req.data << ") trans(" << t_dut.bus_req.trans_type << ") --- ";
                    message << "GM: addr(" << t_gm.bus_req.addr << ") data(" << t_gm.bus_req.data << ") trans(" << t_gm.bus_req.trans_type << ")";
                    uvm_report_error("Slave0_REQ", message.str(), UVM_MEDIUM);
                }

                vec_Slave0_REQ_dut.erase(vec_Slave0_REQ_dut.begin());
                vec_Slave0_REQ_gm.erase(vec_Slave0_REQ_gm.begin());
            }

            //////////////////////////////////////////////////////////////////

            if (!vec_Slave1_REQ_dut.empty() && !vec_Slave1_REQ_gm.empty()) {
                vip_trans_bus_req_t t_dut = *(vec_Slave1_REQ_dut.begin());
                vip_trans_bus_req_t t_gm = *(vec_Slave1_REQ_gm.begin());

                if (!t_dut.do_compare(t_gm)) {
                    std::stringstream message;
                    message << "DUT: addr(" << t_dut.bus_req.addr << ") data(" << t_dut.bus_req.data << ") trans(" << t_dut.bus_req.trans_type << ") --- ";
                    message << "GM: addr(" << t_gm.bus_req.addr << ") data(" << t_gm.bus_req.data << ") trans(" << t_gm.bus_req.trans_type << ")";
                    uvm_report_error("Slave1_REQ", message.str(), UVM_MEDIUM);
                }

                vec_Slave1_REQ_dut.erase(vec_Slave1_REQ_dut.begin());
                vec_Slave1_REQ_gm.erase(vec_Slave1_REQ_gm.begin());
            }

            //////////////////////////////////////////////////////////////////

            if (!vec_Slave2_REQ_dut.empty() && !vec_Slave2_REQ_gm.empty()) {
                vip_trans_bus_req_t t_dut = *(vec_Slave2_REQ_dut.begin());
                vip_trans_bus_req_t t_gm = *(vec_Slave2_REQ_gm.begin());

                if (!t_dut.do_compare(t_gm)) {
                    std::stringstream message;
                    message << "DUT: addr(" << t_dut.bus_req.addr << ") data(" << t_dut.bus_req.data << ") trans(" << t_dut.bus_req.trans_type << ") --- ";
                    message << "GM: addr(" << t_gm.bus_req.addr << ") data(" << t_gm.bus_req.data << ") trans(" << t_gm.bus_req.trans_type << ")";
                    uvm_report_error("Slave2_REQ", message.str(), UVM_MEDIUM);
                }

                vec_Slave2_REQ_dut.erase(vec_Slave2_REQ_dut.begin());
                vec_Slave2_REQ_gm.erase(vec_Slave2_REQ_gm.begin());
            }

            //////////////////////////////////////////////////////////////////

            if (!vec_Slave3_REQ_dut.empty() && !vec_Slave3_REQ_gm.empty()) {
                vip_trans_bus_req_t t_dut = *(vec_Slave3_REQ_dut.begin());
                vip_trans_bus_req_t t_gm = *(vec_Slave3_REQ_gm.begin());

                if (!t_dut.do_compare(t_gm)) {
                    std::stringstream message;
                    message << "DUT: addr(" << t_dut.bus_req.addr << ") data(" << t_dut.bus_req.data << ") trans(" << t_dut.bus_req.trans_type << ") --- ";
                    message << "GM: addr(" << t_gm.bus_req.addr << ") data(" << t_gm.bus_req.data << ") trans(" << t_gm.bus_req.trans_type << ")";
                    uvm_report_error("Slave3_REQ", message.str(), UVM_MEDIUM);
                }

                vec_Slave3_REQ_dut.erase(vec_Slave3_REQ_dut.begin());
                vec_Slave3_REQ_gm.erase(vec_Slave3_REQ_gm.begin());
            }

            wait(SC_ZERO_TIME);
        }
    }

};

#endif //UVMSYSTEMC_SCOREBOARD_H
