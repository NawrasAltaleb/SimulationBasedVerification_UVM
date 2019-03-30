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
#include "systemc.h"
using namespace uvm;

//#define DEBUG

class scoreboard : public uvm_scoreboard {
public:
    uvm_analysis_export<vip_trans_bus_resp_t> listener_Master_RSP_dut; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave0_REQ_dut; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave1_REQ_dut; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave2_REQ_dut; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave3_REQ_dut; /// Exports used to connect to the subscribers

    uvm_analysis_export<vip_trans_bus_resp_t> listener_Master_RSP_gm; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave0_REQ_gm; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave1_REQ_gm; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave2_REQ_gm; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_bus_req_t> listener_Slave3_REQ_gm; /// Exports used to connect to the subscribers

    subscriber_RSP *subscr_Master_rsp_dut;
    subscriber_REQ *subscr_Slave0_req_dut;
    subscriber_REQ *subscr_Slave1_req_dut;
    subscriber_REQ *subscr_Slave2_req_dut;
    subscriber_REQ *subscr_Slave3_req_dut;

    subscriber_RSP *subscr_Master_rsp_gm;
    subscriber_REQ *subscr_Slave0_req_gm;
    subscriber_REQ *subscr_Slave1_req_gm;
    subscriber_REQ *subscr_Slave2_req_gm;
    subscriber_REQ *subscr_Slave3_req_gm;

    // Variables for communicating with goldenReference
    std::vector<vip_trans_bus_resp_t> vec_Master_RSP_dut;
    std::vector<vip_trans_bus_req_t> vec_Slave0_REQ_dut;
    std::vector<vip_trans_bus_req_t> vec_Slave1_REQ_dut;
    std::vector<vip_trans_bus_req_t> vec_Slave2_REQ_dut;
    std::vector<vip_trans_bus_req_t> vec_Slave3_REQ_dut;

    std::vector<vip_trans_bus_resp_t> vec_Master_RSP_gm;
    std::vector<vip_trans_bus_req_t> vec_Slave0_REQ_gm;
    std::vector<vip_trans_bus_req_t> vec_Slave1_REQ_gm;
    std::vector<vip_trans_bus_req_t> vec_Slave2_REQ_gm;
    std::vector<vip_trans_bus_req_t> vec_Slave3_REQ_gm;

    scoreboard(uvm_component_name name) : uvm_scoreboard(name){}

    UVM_COMPONENT_UTILS(scoreboard)

    void build_phase(uvm_phase &phase) {
        uvm_scoreboard::build_phase(phase);

        uvm_config_db<uvm_object *>::set(this, "subscr_Master_rsp_dut", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Master_rsp_dut = subscriber_RSP::type_id::create("subscr_Master_rsp_dut", this);
        assert(subscr_Master_rsp_dut);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave0_req_dut", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave0_req_dut = subscriber_REQ::type_id::create("subscr_Slave0_req_dut", this);
        assert(subscr_Slave0_req_dut);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave1_req_dut", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave1_req_dut = subscriber_REQ::type_id::create("subscr_Slave1_req_dut", this);
        assert(subscr_Slave1_req_dut);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave2_req_dut", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave2_req_dut = subscriber_REQ::type_id::create("subscr_Slave2_req_dut", this);
        assert(subscr_Slave2_req_dut);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave3_req_dut", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave3_req_dut = subscriber_REQ::type_id::create("subscr_Slave3_req_dut", this);
        assert(subscr_Slave3_req_dut);

        uvm_config_db<uvm_object *>::set(this, "subscr_Master_rsp_gm", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Master_rsp_gm = subscriber_RSP::type_id::create("subscr_Master_rsp_gm", this);
        assert(subscr_Master_rsp_gm);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave0_req_gm", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave0_req_gm = subscriber_REQ::type_id::create("subscr_Slave0_req_gm", this);
        assert(subscr_Slave0_req_gm);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave1_req_gm", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave1_req_gm = subscriber_REQ::type_id::create("subscr_Slave1_req_gm", this);
        assert(subscr_Slave1_req_gm);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave2_req_gm", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave2_req_gm = subscriber_REQ::type_id::create("subscr_Slave2_req_gm", this);
        assert(subscr_Slave2_req_gm);

        uvm_config_db<uvm_object *>::set(this, "subscr_Slave3_req_gm", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_Slave3_req_gm = subscriber_REQ::type_id::create("subscr_Slave3_req_gm", this);
        assert(subscr_Slave3_req_gm);
    }

    void connect_phase(uvm_phase &phase) {
        listener_Master_RSP_dut(subscr_Master_rsp_dut->analysis_export);
        listener_Slave0_REQ_dut(subscr_Slave0_req_dut->analysis_export);
        listener_Slave1_REQ_dut(subscr_Slave1_req_dut->analysis_export);
        listener_Slave2_REQ_dut(subscr_Slave2_req_dut->analysis_export);
        listener_Slave3_REQ_dut(subscr_Slave3_req_dut->analysis_export);

        listener_Master_RSP_gm(subscr_Master_rsp_gm->analysis_export);
        listener_Slave0_REQ_gm(subscr_Slave0_req_gm->analysis_export);
        listener_Slave1_REQ_gm(subscr_Slave1_req_gm->analysis_export);
        listener_Slave2_REQ_gm(subscr_Slave2_req_gm->analysis_export);
        listener_Slave3_REQ_gm(subscr_Slave3_req_gm->analysis_export);
    }


    /// Via the subscribers the expected and the processed transactions become available which are used for the actual checking
    void write_listener_Master_RSP_dut(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-------- toMaster -------- data: " << t.bus_resp.data
                  << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        if(t.bus_resp.ack == OK) // FIXME: Here is a real concern
            vec_Master_RSP_dut.push_back(t);
    }

    void write_listener_Slave0_REQ_dut(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave0 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave0_REQ_dut.push_back(t);
    }

    void write_listener_Slave1_REQ_dut(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave1 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave1_REQ_dut.push_back(t);
    }

    void write_listener_Slave2_REQ_dut(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave2 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave2_REQ_dut.push_back(t);
    }

    void write_listener_Slave3_REQ_dut(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave3 -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave3_REQ_dut.push_back(t);
    }


    void write_listener_Master_RSP_gm(const vip_trans_bus_resp_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-------- toMaster (GM) -------- data: " << t.bus_resp.data
                  << " ack: "
                  << t.bus_resp.ack << std::endl;
#endif
        vec_Master_RSP_gm.push_back(t);
    }

    void write_listener_Slave0_REQ_gm(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave0  (GM)-------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave0_REQ_gm.push_back(t);
    }

    void write_listener_Slave1_REQ_gm(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave1 (GM) -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave1_REQ_gm.push_back(t);
    }

    void write_listener_Slave2_REQ_gm(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave2 (GM) -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave2_REQ_gm.push_back(t);
    }

    void write_listener_Slave3_REQ_gm(const vip_trans_bus_req_t &t) {
#ifdef DEBUG
        std::cout << "\t\t\t\t\t\t\t\t\t-------- toSlave3 (GM) -------- addr: " << t.bus_req.addr << " data: "
                  << t.bus_req.data << " trans: " << t.bus_req.trans_type << std::endl;
#endif
        vec_Slave3_REQ_gm.push_back(t);
    }

    void run_phase(uvm::uvm_phase &phase) {
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
