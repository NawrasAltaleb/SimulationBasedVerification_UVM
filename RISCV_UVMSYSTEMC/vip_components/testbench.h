//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: UVM testbench
 *  - A testbench is defined as the complete environment which instantiates and configures the UVCs, scoreboard, and virtual sequencer if available.
 *      Remark: should the interrupt sources be created here and have their signals connected somehow to the DUT or should these interrupt signals be as part of the
 *      sequences to be sent to the DUT? I guess, it's better to be as part of the sequences
 *  - The UVCs are sub-environments in a testbench
 *      Remark: we only need more than one UVC if we are planning to have more than one interface with the DUT, i.e. when we have interrupt signals as well
 *  - The testbench only makes the connections between the scoreboard and virtual sequencer to each UVC; the connection between UVCs and the DUT is arranged within
 *      the UVCs.
 */
#ifndef UVMSYSTEMC_TESTBENCH_H
#define UVMSYSTEMC_TESTBENCH_H

#include <uvm>

#include "vip_UVC.h"
#include "scoreboard.h"
using namespace uvm;

class testbench : public uvm_env {
public:
    /// All components in the test bench will be dynamically instantiated so they can be overridden by the test if necessary
    vip_uvc *uvc_gm;
    vip_uvc *uvc;
    scoreboard *scoreboard1;

    UVM_COMPONENT_UTILS(testbench);

    testbench(uvm_component_name name)
            : uvm_env(name),
              uvc_gm(0),
              uvc(0),
              scoreboard1(0) {}

    void build_phase(uvm_phase &phase) {
        uvm_env::build_phase(phase);

        uvc_gm = vip_uvc::type_id::create("uvc_gm", this);
        assert(uvc_gm);
        uvc = vip_uvc::type_id::create("uvc", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc);

        scoreboard1 = scoreboard::type_id::create("scoreboard1", this);
        assert(scoreboard1);

        uvm_config_db<int>::set(this, "uvc_gm.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc.agent", "is_active", uvm::UVM_ACTIVE);
    }

    void connect_phase(uvm_phase &phase) {
        uvc_gm->agent->driver->item_collected_port_fromMemory.connect(scoreboard1->listener_fromMemory_gm);
        uvc_gm->agent->driver->item_collected_port_toMemory.connect(scoreboard1->listener_toMemory_gm);

        uvc->agent->driver->item_collected_port_fromMemory.connect(scoreboard1->listener_fromMemory_dut);
        uvc->agent->driver->item_collected_port_toMemory.connect(scoreboard1->listener_toMemory_dut);
    }

}; // class testbench

#endif //UVMSYSTEMC_TESTBENCH_H
