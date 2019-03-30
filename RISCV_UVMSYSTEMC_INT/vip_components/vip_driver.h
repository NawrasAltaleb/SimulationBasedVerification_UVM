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


#include <uvm>
#include "vip_if.h"

template <class RSP, class REQ>
class vip_driver : public uvm::uvm_driver<RSP, REQ> {
public:
    uvm::uvm_analysis_port<RSP> item_collected_port_fromMemory;
    uvm::uvm_analysis_port<REQ> item_collected_port_toMemory;
    vip_if_fromMemory *vif_fromMemory; /// Placeholder needed to store the handle to the interface object
    vip_if_toMemory *vif_toMemory; /// Placeholder needed to store the handle to the interface object

    vip_driver(uvm::uvm_component_name name) : uvm::uvm_driver<RSP, REQ>(name) {}

    UVM_COMPONENT_PARAM_UTILS(vip_driver<RSP, REQ>); /// Registration of the template class

    void build_phase(uvm::uvm_phase &phase) {
        uvm::uvm_driver<RSP, REQ>::build_phase(phase);

        /// Get interface object using the configuration mechanism
        if (!uvm::uvm_config_db<vip_if_fromMemory *>::get(this, "*", "vif_fromMemory", vif_fromMemory))
            UVM_FATAL(this->get_name(), "Virtual interface not defined! Simulation aborted!");
        if (!uvm::uvm_config_db<vip_if_toMemory *>::get(this, "*", "vif_toMemory", vif_toMemory))
            UVM_FATAL(this->get_name(), "Virtual interface not defined! Simulation aborted!");
    }

    void run_phase(uvm::uvm_phase &phase) {
        RSP rsp;
        REQ req;

        /// First request from DUT
        this->seq_item_port->get_next_item(rsp);
        req.set_id_info(rsp);
        this->seq_item_port->item_done();
        vif_toMemory->toMemory_Port.read(req.toMemory);
        item_collected_port_toMemory.write(req);
        this->seq_item_port->put_response(req);

        while (true) // forever loop
        {
            /// write sequence response (instruction)
            this->seq_item_port->get_next_item(rsp);
            drive_fromMemory(rsp);
            item_collected_port_fromMemory.write(rsp);
            req.set_id_info(rsp);

            if (rsp.fromMemory.loadedData != 0x00100073) {
                /// read dut request
                vif_toMemory->toMemory_Port.read(req.toMemory);
                item_collected_port_toMemory.write(req);
                this->seq_item_port->item_done();
                this->seq_item_port->put_response(req);
            } else {
                this->seq_item_port->item_done();
                this->seq_item_port->put_response(req);
            }
//
//            /// store instruction process
//            if (req.toMemory.req == ME_AccessType::ME_WR) {
//                /// write to sequence the store value
//                this->seq_item_port->item_done();
//                this->seq_item_port->put_response(req);
//
//                /// in order to get next instruction we need to initiate a new sequence item just to give back the dut request
//                this->seq_item_port->get_next_item(rsp);
//                //no writing to dut
//                drive_fromMemory(rsp); // TODO: This should be commented in case of a STORE instruction without reading
//                item_collected_port_fromMemory.write(rsp); // TODO: This should be commented in case of a STORE instruction without reading
//                req.set_id_info(rsp);
//                /// read dut request (Instruction)
//                vif_toMemory->toMemory_Port.read(req.toMemory);
//                item_collected_port_toMemory.write(req);
//            }
//
//            this->seq_item_port->item_done();
//            this->seq_item_port->put_response(req);
        }
    }

    void drive_fromMemory(const RSP &rsp) {
//        if(this->get_full_name() == "my_test.tb.g_uvc.agent.driver")
//            std::cout << hex<<rsp.fromMemory.loadedData <<"\n";
        vif_fromMemory->fromMemory_Port.write(rsp.fromMemory); /// Driver output signals are written to the interface directly
    }

}; // class vip_driver

#endif //UVMSYSTEMC_VIP_DRIVER_H
