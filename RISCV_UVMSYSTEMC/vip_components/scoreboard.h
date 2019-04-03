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

#include <uvm>
#include "systemc.h"
#include "subscriber.h"
using namespace std;
using namespace uvm;


class scoreboard : public uvm_scoreboard {
public:
    uvm_analysis_export<vip_trans_fromMemory> listener_fromMemory_gm; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_toMemory> listener_toMemory_gm;
    uvm_analysis_export<vip_trans_fromMemory> listener_fromMemory_dut; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_toMemory> listener_toMemory_dut;

    subscriber_fromMemory *subscr_fromMemory_gm;
    subscriber_toMemory *subscr_toMemory_gm;
    subscriber_fromMemory *subscr_fromMemory_dut;
    subscriber_toMemory *subscr_toMemory_dut;

    vector<vip_trans_toMemory> mem_trans_dut;
    vector<vip_trans_toMemory> mem_trans_gm;

    scoreboard(uvm_component_name name) : uvm_scoreboard(name) {}

    UVM_COMPONENT_UTILS(scoreboard)

    void build_phase(uvm_phase &phase) {
        uvm_scoreboard::build_phase(phase);

        uvm_config_db<uvm_object *>::set(this, "subscr_fromMemory_gm", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_fromMemory_gm = subscriber_fromMemory::type_id::create("subscr_fromMemory_gm", this);
        assert(subscr_fromMemory_gm);

        uvm_config_db<uvm_object *>::set(this, "subscr_toMemory_gm", "sb", this);
        subscr_toMemory_gm = subscriber_toMemory::type_id::create("subscr_toMemory_gm", this);
        assert(subscr_toMemory_gm);

        uvm_config_db<uvm_object *>::set(this, "subscr_fromMemory_dut", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        subscr_fromMemory_dut = subscriber_fromMemory::type_id::create("subscr_fromMemory_dut", this);
        assert(subscr_fromMemory_dut);

        uvm_config_db<uvm_object *>::set(this, "subscr_toMemory_dut", "sb", this);
        subscr_toMemory_dut = subscriber_toMemory::type_id::create("subscr_toMemory_dut", this);
        assert(subscr_toMemory_dut);
    }

    void connect_phase(uvm_phase &phase) {
        listener_fromMemory_gm(subscr_fromMemory_gm->analysis_export);
        listener_toMemory_gm(subscr_toMemory_gm->analysis_export);

        listener_fromMemory_dut(subscr_fromMemory_dut->analysis_export);
        listener_toMemory_dut(subscr_toMemory_dut->analysis_export);
    }

    /// Via the subscribers the expected and the processed transactions become available which are used for the actual checking
    void write_listener_fromMemory_gm(const vip_trans_fromMemory &t) {
//        std::cout << "\t\t\t\t\t\t\t\t\t\t\t-------- GM  fromMemory -------- reply: " << std::hex << t.fromMemory.loadedData << std::endl;
    }

    void write_listener_toMemory_gm(const vip_trans_toMemory &t) {
        if (t.toMemory.req == ME_AccessType::ME_WR) {
//            std::cout << "+++++++++ GM  store +++++++++ addr: 0x" << hex << t.toMemory.addrIn << " Data: " << dec << t.toMemory.dataIn << " MaskType: " << t.toMemory.mask
//                      << std::endl;
            mem_trans_gm.push_back(t);
        }
    }

    /// Via the subscribers the expected and the processed transactions become available which are used for the actual checking
    void write_listener_fromMemory_dut(const vip_trans_fromMemory &t) {
//        std::cout << "\t\t\t\t\t\t\t\t\t\t\t-------- DUT fromMemory -------- reply: " << std::hex << t.fromMemory.loadedData << std::endl;
    }

    void write_listener_toMemory_dut(const vip_trans_toMemory &t) {
        if (t.toMemory.req == ME_AccessType::ME_WR) {
//            std::cout << "+++++++++ DUT store +++++++++ addr: 0x" << hex << t.toMemory.addrIn << " Data: " << dec << t.toMemory.dataIn << " MaskType: " << t.toMemory.mask
//                      << std::endl;
            mem_trans_dut.push_back(t);
        }
    }

    void run_phase(uvm::uvm_phase &phase) {
        while (true) {
            if (!mem_trans_gm.empty() && !mem_trans_dut.empty()) {
                vip_trans_toMemory dut_t = *(mem_trans_dut.begin());
                vip_trans_toMemory gm_t = *(mem_trans_gm.begin());
                if (!dut_t.do_compare(gm_t)) {
                    std::stringstream message;
                    message << "DUT: addr(0x" << hex << dut_t.toMemory.addrIn << ") data(" << dec << dut_t.toMemory.dataIn <<
                            ") req(" << dut_t.toMemory.req << ") mask(" << dut_t.toMemory.mask << ") --- ";
                    message << "GM: addr(0x" << hex << gm_t.toMemory.addrIn << ") data(" << dec << gm_t.toMemory.dataIn <<
                            ") req(" << gm_t.toMemory.req << ") mask(" << gm_t.toMemory.mask << ")";
//                    cout<<message.str()<<"\n";
                    uvm_report_error("toMemory", message.str(), UVM_MEDIUM);
                } //else
//                    uvm_report_info("toMemory", "Equal behavior", UVM_MEDIUM);
                mem_trans_dut.erase(mem_trans_dut.begin());
                mem_trans_gm.erase(mem_trans_gm.begin());
            }
            wait(SC_ZERO_TIME);
        }
    }

    void report_phase(uvm_phase &phase) {
        std::cout << dec << "size: DUT " << mem_trans_dut.size() << " while GM " << mem_trans_gm.size() << "\n";
    }
};

#endif //UVMSYSTEMC_SCOREBOARD_H
