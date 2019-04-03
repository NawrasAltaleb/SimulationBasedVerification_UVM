//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: UVM monitor
 * - The monitor is a passive element that ‘only’ captures the DUT signals.
 *      Remark: monitor is passive but if the "fromMemory" command is a write command resulting from a store instruction then the subscriber needs to handle it.
 * - It extracts signal information from the interface and translates this information to abstract transactions.
 * - It will distribute this transaction to all connected elements for e.g. coverage collection and checking. //FIXME: does this mean I can connect it to different subscribers (one for read instruction request and one for load-store data) ?
 * - Connection between the monitor and the DUT is established by using a dedicated channel, which is made available via the configuration mechanism.
 *
 */

#ifndef UVMSYSTEMC_VIP_MONITOR_H
#define UVMSYSTEMC_VIP_MONITOR_H

#include "vip_trans.h"
#include "vip_if.h"
using namespace uvm;

class vip_monitor_Master : public uvm_monitor {
public:
    uvm_analysis_port<vip_trans_bus_resp_t> item_collected_port_Master_RSP; /// Analysis port used to pass collected data to attached components
    vip_if_BUS_RSP *vif_BusToMaster; /// Placeholder needed to store the handle to the interface object

    vip_monitor_Master(uvm_component_name name) : uvm_monitor(name) {}

    UVM_COMPONENT_UTILS(vip_monitor_Master)

    void build_phase(uvm_phase &phase) {
        uvm_monitor::build_phase(phase);

        /// Get interface object using the configuration mechanism
        if (!uvm_config_db<vip_if_BUS_RSP *>::get(this, "*", "vif_BusToMaster", vif_BusToMaster))
            UVM_FATAL(this->get_name(), "Virtual interface not defined! Simulation aborted!");
    }

    void run_phase(uvm_phase &phase) {
        vip_trans_bus_resp_t t;
        while (true) // monitor forever
        {
            vif_BusToMaster->BUS_RSP.read(t.bus_resp);
            item_collected_port_Master_RSP.write(t);
        }
    }

}; // class vip_monitor


class vip_monitor_Slave : public uvm_monitor {
public:
    uvm_analysis_port<vip_trans_bus_req_t> item_collected_port_Slave_REQ; /// Analysis port used to pass collected data to attached components
    vip_if_BUS_REQ *vif_BusToSlave; /// Placeholder needed to store the handle to the interface object

    vip_monitor_Slave(uvm_component_name name) : uvm_monitor(name) {}

    UVM_COMPONENT_UTILS(vip_monitor_Slave)

    void build_phase(uvm_phase &phase) {
        uvm_monitor::build_phase(phase);

        /// Get interface object using the configuration mechanism
        if (!uvm_config_db<vip_if_BUS_REQ *>::get(this, "*", "vif_BusToSlave", vif_BusToSlave))
            UVM_FATAL(this->get_name(), "Virtual interface not defined! Simulation aborted!");
    }

    void run_phase(uvm_phase &phase) {
        vip_trans_bus_req_t t;
        while (true) // monitor forever
        {
            vif_BusToSlave->BUS_REQ.read(t.bus_req);
            item_collected_port_Slave_REQ.write(t);
        }
    }

}; // class vip_monitor
#endif //UVMSYSTEMC_VIP_MONITOR_H
