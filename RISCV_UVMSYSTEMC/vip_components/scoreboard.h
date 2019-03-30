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
#include "subscriber_fromMemory.h"
#include "subscriber_toMemory.h"
#include "Interfaces.h"
#include "Golden_Reference/GOLDEN_Core.h"
using namespace uvm;

#define CheckingInterval 1000

class scoreboard : public uvm_scoreboard {
public:
    uvm_analysis_export<vip_trans_fromMemory> listener_fromMemory; /// Exports used to connect to the subscribers
    uvm_analysis_export<vip_trans_toMemory> listener_toMemory;
    subscriber_fromMemory *subscr_fromMemory;
    subscriber_toMemory *subscr_toMemory;
    /// instance of ISA need to be added to the scoreboard
    G_Core goldenReference;
    // Channel instantiation
    Blocking<CUtoME_IF> toMemory_channel;
    Blocking<MEtoCU_IF> fromMemory_channel;
    // Variables for communicating with goldenReference
    vip_trans_toMemory toMemory_trans;
    vip_trans_fromMemory fromMemory_trans;
    vector<vip_trans_toMemory> dut_mem_trans;
    vector<vip_trans_toMemory> gm_mem_trans;
    int runningCount;

    scoreboard(uvm_component_name name) : uvm_scoreboard(name),
                                            toMemory_channel("toMemory_channel"),
                                            fromMemory_channel("fromMemory_channel"),
                                            goldenReference("goldenModel"){
        //Port binding:
        goldenReference.COtoME_port(toMemory_channel);
        goldenReference.MEtoCO_port(fromMemory_channel);
        runningCount = 0;
    }

    UVM_COMPONENT_UTILS(scoreboard)

    void build_phase(uvm_phase &phase) {
        uvm_scoreboard::build_phase(phase);

        uvm_config_db<uvm_object*>::set(this, "subscr_fromMemory", "sb", this); /// a trick for subscriber to have a reference to it's containing scoreboard
        uvm_config_db<uvm_object*>::set(this, "subscr_toMemory", "sb", this);
        subscr_fromMemory = subscriber_fromMemory::type_id::create("subscr_fromMemory", this);
        assert(subscr_fromMemory);
        subscr_toMemory = subscriber_toMemory::type_id::create("subscr_toMemory", this);
        assert(subscr_toMemory);
    }

    void connect_phase(uvm_phase &phase) {
        listener_fromMemory(subscr_fromMemory->analysis_export);
        listener_toMemory(subscr_toMemory->analysis_export);
    }

    /// Via the subscribers the expected and the processed transactions become available which are used for the actual checking
    void write_listener_fromMemory(const vip_trans_fromMemory &t) {
//        std::cout << "\t\t\t\t\t\t\t\t\t\t\t-------- fromMemory -------- reply: " << std::hex << t.fromMemory.loadedData << std::endl;

        fromMemory_trans = t;
        fromMemory_channel.write(fromMemory_trans.fromMemory);
    }

    void write_listener_toMemory(const vip_trans_toMemory &t) {
        if (t.toMemory.req == ME_AccessType::ME_WR) {
//            std::cout << "+++++++++ DUT store +++++++++ addr: 0x" << hex << t.toMemory.addrIn << " Data: " << dec << t.toMemory.dataIn << " MaskType: " << t.toMemory.mask
//                      << std::endl;
        }

        toMemory_channel.read(toMemory_trans.toMemory);
        if (toMemory_trans.toMemory.req == ME_AccessType::ME_WR) {
//            std::cout << "+++++++++ ISA store +++++++++ addr: 0x" << hex << toMemory_trans.toMemory.addrIn << " Data: " << dec << toMemory_trans.toMemory.dataIn
//                      << " MaskType: " << toMemory_trans.toMemory.mask << std::endl;
        }

        dut_mem_trans.push_back(t);
        gm_mem_trans.push_back(toMemory_trans);
        runningCount++;
        if(runningCount > CheckingInterval + 20){
            compare_Interval();
            runningCount = runningCount - CheckingInterval;
        }
    }

    void compare_Interval(){
//        uvm_report_info("compare Interval", "Start", UVM_MEDIUM);

        vip_trans_toMemory dut_t;
        vip_trans_toMemory gm_t;
        for (int i = 0; i < CheckingInterval; ++i) {
            dut_t = dut_mem_trans.at(i);
            gm_t = gm_mem_trans.at(i);

            if (!dut_t.do_compare(gm_t)) {
                std::stringstream message;
                message << "DUT: addr(0x" << hex << dut_t.toMemory.addrIn << ") data(" << dec << dut_t.toMemory.dataIn <<
                        ") req(" << dut_t.toMemory.req << ") mask(" << dut_t.toMemory.mask << ") --- ";
                message << "GM: addr(0x" << hex << gm_t.toMemory.addrIn << ") data(" << dec << gm_t.toMemory.dataIn <<
                        ") req(" << gm_t.toMemory.req << ") mask(" << gm_t.toMemory.mask << ")";
                uvm_report_error("toMemory", message.str(), UVM_MEDIUM);

            }
        }

        dut_mem_trans.erase(dut_mem_trans.begin(), dut_mem_trans.begin()+CheckingInterval);
        gm_mem_trans.erase(gm_mem_trans.begin(), gm_mem_trans.begin()+CheckingInterval);

        uvm_report_info("compare Interval", "Done", UVM_MEDIUM);
    }

    void report_phase(uvm_phase &phase) {
//        uvm_report_info("compare Final", "Start", UVM_MEDIUM);

        vip_trans_toMemory dut_t;
        vip_trans_toMemory gm_t;
        for (int i = 0; i < runningCount; ++i) {
            dut_t = dut_mem_trans.at(i);
            gm_t = gm_mem_trans.at(i);

            if (!dut_t.do_compare(gm_t)) {
                std::stringstream message;
                message << "DUT: addr(0x" << hex << dut_t.toMemory.addrIn << ") data(" << dec << dut_t.toMemory.dataIn <<
                        ") req(" << dut_t.toMemory.req << ") mask(" << dut_t.toMemory.mask << ") --- ";
                message << "GM: addr(0x" << hex << gm_t.toMemory.addrIn << ") data(" << dec << gm_t.toMemory.dataIn <<
                        ") req(" << gm_t.toMemory.req << ") mask(" << gm_t.toMemory.mask << ")";
                uvm_report_error("toMemory", message.str(), UVM_MEDIUM);
            }
        }

//        dut_mem_trans.erase(dut_mem_trans.begin(), dut_mem_trans.begin()+runningCount);
//        gm_mem_trans.erase(gm_mem_trans.begin(), gm_mem_trans.begin()+runningCount);
        uvm_report_info("compare Final", "Done", UVM_MEDIUM);
    }
};

#endif //UVMSYSTEMC_SCOREBOARD_H
