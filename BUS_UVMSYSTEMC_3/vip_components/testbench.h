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

#include "vip_UVC.h"
#include "scoreboard.h"

class testbench : public uvm_env {
public:
    /// All components in the test bench will be dynamically instantiated so they can be overridden by the test if necessary
    vip_uvc_Master *uvc_master;
    vip_uvc_Slave *uvc_slave0;
    vip_uvc_Slave *uvc_slave1;
    vip_uvc_Slave *uvc_slave2;
    vip_uvc_Slave *uvc_slave3;

    vip_uvc_Master *uvc_gm_master;
    vip_uvc_Slave *uvc_gm_slave0;
    vip_uvc_Slave *uvc_gm_slave1;
    vip_uvc_Slave *uvc_gm_slave2;
    vip_uvc_Slave *uvc_gm_slave3;

    scoreboard *scoreboard1;

    UVM_COMPONENT_UTILS(testbench);

    testbench(uvm_component_name name)
            : uvm_env(name),
            uvc_master(0), uvc_slave0(0),uvc_slave1(0),uvc_slave2(0),uvc_slave3(0),
            uvc_gm_master(0), uvc_gm_slave0(0),uvc_gm_slave1(0),uvc_gm_slave2(0),uvc_gm_slave3(0),
              scoreboard1(0) {}

    void build_phase(uvm_phase &phase) {
        uvm_env::build_phase(phase);

        uvc_master = vip_uvc_Master::type_id::create("uvc_master", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_master);
        uvc_slave0 = vip_uvc_Slave::type_id::create("uvc_slave0", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_slave0);
        uvc_slave1 = vip_uvc_Slave::type_id::create("uvc_slave1", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_slave1);
        uvc_slave2 = vip_uvc_Slave::type_id::create("uvc_slave2", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_slave2);
        uvc_slave3 = vip_uvc_Slave::type_id::create("uvc_slave3", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_slave3);

        uvc_gm_master = vip_uvc_Master::type_id::create("uvc_gm_master", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_gm_master);
        uvc_gm_slave0 = vip_uvc_Slave::type_id::create("uvc_gm_slave0", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_gm_slave0);
        uvc_gm_slave1 = vip_uvc_Slave::type_id::create("uvc_gm_slave1", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_gm_slave1);
        uvc_gm_slave2 = vip_uvc_Slave::type_id::create("uvc_gm_slave2", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_gm_slave2);
        uvc_gm_slave3 = vip_uvc_Slave::type_id::create("uvc_gm_slave3", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(uvc_gm_slave3);

        scoreboard1 = scoreboard::type_id::create("scoreboard1", this);
        assert(scoreboard1);

        uvm_config_db<int>::set(this, "uvc_master.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_slave0.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_slave1.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_slave2.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_slave3.agent", "is_active", uvm::UVM_ACTIVE);

        uvm_config_db<int>::set(this, "uvc_gm_master.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_gm_slave0.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_gm_slave1.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_gm_slave2.agent", "is_active", uvm::UVM_ACTIVE);
        uvm_config_db<int>::set(this, "uvc_gm_slave3.agent", "is_active", uvm::UVM_ACTIVE);
    }

    void connect_phase(uvm_phase &phase) {
        uvc_master->agent->driver->item_collected_port_Master_RSP.connect(scoreboard1->listener_Master_RSP_dut);
        uvc_slave0->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave0_REQ_dut);
        uvc_slave1->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave1_REQ_dut);
        uvc_slave2->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave2_REQ_dut);
        uvc_slave3->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave3_REQ_dut);

        uvc_gm_master->agent->driver->item_collected_port_Master_RSP.connect(scoreboard1->listener_Master_RSP_gm);
        uvc_gm_slave0->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave0_REQ_gm);
        uvc_gm_slave1->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave1_REQ_gm);
        uvc_gm_slave2->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave2_REQ_gm);
        uvc_gm_slave3->agent->monitor->item_collected_port_Slave_REQ.connect(scoreboard1->listener_Slave3_REQ_gm);
    }

}; // class testbench

#endif //UVMSYSTEMC_TESTBENCH_H
