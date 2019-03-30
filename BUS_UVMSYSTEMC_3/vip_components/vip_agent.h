//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: UVM agent
 * - Component responsible to drive and monitor the DUT.
 * - Typically contains three components: Sequencer, Driver and Monitor
 * - Could contain analysis functionality for basic coverage and checking. Remark: How to use this!!??
 * - Possible configurations:
 *      - Active agent: sequencer and driver are enabled. Remark: I'm using this for connecting to the "fromMemory" port.
 *                                                                The Driver sends items to DUT and subscriber at the same time, and the monitor is disabled.
 *      - Passive agent: only monitors signals (sequencer and driver are disabled). Remark: used for "toMemory" port.
 *      - Master or slave configuration
 */

#ifndef UVMSYSTEMC_VIP_AGENT_H
#define UVMSYSTEMC_VIP_AGENT_H

#include "vip_sequencer.h"
#include "vip_driver.h"
#include "vip_monitor.h"
#include "vip_trans.h"
using namespace uvm;

class vip_agent_Master : public uvm_agent {
public:
    vip_sequencer_Master<vip_trans_bus_req_t,vip_trans_bus_resp_t> *sequencer;
    vip_driver_Master<vip_trans_bus_req_t,vip_trans_bus_resp_t> *driver;
//    vip_monitor_Master *monitor;
    // TODO: Could contain analysis functionality for basic coverage and checking

    UVM_COMPONENT_UTILS(vip_agent_Master);

    vip_agent_Master(uvm_component_name name)
            : uvm_agent(name), sequencer(0),
              driver(0)//, monitor(0)
              {}

    void build_phase(uvm_phase &phase) {
        uvm_agent::build_phase(phase);

        if (get_is_active() == uvm::UVM_ACTIVE) {

            sequencer = vip_sequencer_Master<vip_trans_bus_req_t,vip_trans_bus_resp_t>::type_id::create("sequencer", this);
            assert(sequencer);

            driver = vip_driver_Master<vip_trans_bus_req_t,vip_trans_bus_resp_t>::type_id::create("driver", this);
            assert(driver);

        } else {

//            monitor = vip_monitor_Master::type_id::create("monitor", this);
//            assert(monitor);
        }
    }

    void connect_phase(uvm_phase &phase) {
        /// Only the connection between sequencer and driver is made here. Connection of driver and monitor to the DUT is done via
        /// the configuration mechanism in the driver and monitor, respectively
        if (get_is_active() == uvm::UVM_ACTIVE) {
            driver->seq_item_port.connect(sequencer->seq_item_export);
        }
    }

}; // class vip_agent



class vip_agent_Slave : public uvm_agent {
public:
    vip_sequencer<vip_trans_bus_resp_t> *sequencer;
    vip_driver_RSP<vip_trans_bus_resp_t> *driver;
    vip_monitor_Slave *monitor;
    // TODO: Could contain analysis functionality for basic coverage and checking

    UVM_COMPONENT_UTILS(vip_agent_Slave);

    vip_agent_Slave(uvm_component_name name)
            : uvm_agent(name), sequencer(0),
              driver(0), monitor(0) {}

    void build_phase(uvm_phase &phase) {
        uvm_agent::build_phase(phase);

        if (get_is_active() == uvm::UVM_ACTIVE) {

            sequencer = vip_sequencer<vip_trans_bus_resp_t>::type_id::create("sequencer", this);
            assert(sequencer);

            driver = vip_driver_RSP<vip_trans_bus_resp_t>::type_id::create("driver", this);
            assert(driver);

            monitor = vip_monitor_Slave::type_id::create("monitor", this);
            assert(monitor);
        } else {

            monitor = vip_monitor_Slave::type_id::create("monitor", this);
            assert(monitor);
        }
    }

    void connect_phase(uvm_phase &phase) {
        /// Only the connection between sequencer and driver is made here. Connection of driver and monitor to the DUT is done via
        /// the configuration mechanism in the driver and monitor, respectively
        if (get_is_active() == uvm::UVM_ACTIVE) {
            driver->seq_item_port.connect(sequencer->seq_item_export);
        }
    }

}; // class vip_agent

#endif //UVMSYSTEMC_VIP_AGENT_H
