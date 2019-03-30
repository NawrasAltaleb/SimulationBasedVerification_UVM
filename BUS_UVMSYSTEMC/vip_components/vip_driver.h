//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: UVM driver
 * - The driver is responsible to create the physical signals to drive the DUT.
 * - For this, the driver repeatedly requests transactions, encapsulated in a sequence, via the sequencer, and translates these to one or more physical signal(s).
 *      Remark: this depends on the structure of the sequence transaction (item). if we pack signals together or not.
 * - Connection between the driver and the DUT is established by using a dedicated channel, which is made available via the configuration mechanism.
 */

#ifndef UVMSYSTEMC_VIP_DRIVER_H
#define UVMSYSTEMC_VIP_DRIVER_H


//#include <uvm>
#include "vip_trans.h"
#include "vip_if.h"
using namespace uvm;

template <class REQ>
class vip_driver : public uvm::uvm_driver<REQ> {
public:
    uvm_analysis_port<vip_trans_bus_req_t> item_collected_port_Master_REQ;
    vip_if_BUS_REQ *vif_MasterToBus; /// Placeholder needed to store the handle to the interface object

    vip_driver(uvm::uvm_component_name name) : uvm::uvm_driver<REQ>(name) {}

    UVM_COMPONENT_PARAM_UTILS(vip_driver<REQ>); /// Registration of the template class

    void build_phase(uvm::uvm_phase &phase) {
        uvm::uvm_driver<REQ>::build_phase(phase);

        /// Get interface object using the configuration mechanism
        if (!uvm::uvm_config_db<vip_if_BUS_REQ *>::get(this, "*", "vif_MasterToBus", vif_MasterToBus))
            UVM_FATAL(this->get_name(), "Virtual interface not defined! Simulation aborted!");
    }

    void run_phase(uvm::uvm_phase &phase) {
        REQ req;
        REQ rsp;

        while (true) // forever loop
        {
            this->seq_item_port->get_next_item(req);
            item_collected_port_Master_REQ.write(req);
//            std::cout << "driver ....."<< req.bus_req.addr <<"...... " << req.bus_req.data << "\n";
            drive_req(req);
            rsp.set_id_info(req);
            this->seq_item_port->item_done();
            this->seq_item_port->put_response(rsp);
        }
    }

    void drive_req(const REQ &req) {
        vif_MasterToBus->BUS_REQ.write(req.bus_req); /// Driver output signals are written to the interface directly
    }

}; // class vip_driver


template <class RSP>
class vip_driver_RSP : public uvm::uvm_driver<RSP> {
public:
    uvm_analysis_port<vip_trans_bus_resp_t> item_collected_port_Slave_RSP;
    vip_if_BUS_RSP *vif_SlaveToBus; /// Placeholder needed to store the handle to the interface object

    vip_driver_RSP(uvm::uvm_component_name name) : uvm::uvm_driver<RSP>(name) {}

    UVM_COMPONENT_PARAM_UTILS(vip_driver_RSP<RSP>); /// Registration of the template class

    void build_phase(uvm::uvm_phase &phase) {
        uvm::uvm_driver<RSP>::build_phase(phase);

        /// Get interface object using the configuration mechanism
        if (!uvm::uvm_config_db<vip_if_BUS_RSP *>::get(this, "*", "vif_SlaveToBus", vif_SlaveToBus))
            UVM_FATAL(this->get_name(), "Virtual interface not defined! Simulation aborted!");
    }

    void run_phase(uvm::uvm_phase &phase) {
        RSP req;
        RSP rsp;

        while (true) // forever loop
        {
            this->seq_item_port->get_next_item(req);
            item_collected_port_Slave_RSP.write(req);
//            std::cout << "driver ....."<< req.bus_resp.data  <<"...... " << req.bus_req.ack << "\n";
            drive_rsp(req);
            rsp.set_id_info(req);
            this->seq_item_port->item_done();
            this->seq_item_port->put_response(rsp);
        }
    }

    void drive_rsp(const RSP &req) {
        vif_SlaveToBus->BUS_RSP.write(req.bus_resp); /// Driver output signals are written to the interface directly
    }

}; // class vip_driver
#endif //UVMSYSTEMC_VIP_DRIVER_H
