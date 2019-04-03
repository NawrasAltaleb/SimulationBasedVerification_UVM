//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#ifndef UVMSYSTEMC_VIP_TRANS_H
#define UVMSYSTEMC_VIP_TRANS_H

#include <uvm>
#include "Compound.h"

class vip_trans_bus_req_t : public uvm::uvm_sequence_item {    /// Inherits from uvm_transaction
public:
    bus_req_t bus_req;

    UVM_OBJECT_UTILS(vip_trans_bus_req_t);

    vip_trans_bus_req_t(const std::string &name = "vip_trans_bus_req_t") {
        bus_req.addr = 0;
        bus_req.trans_type = SINGLE_READ;
        bus_req.data = 0;
    }

    /// A sequence item should implement all elementary member functions to print, pack, unpack, copy and compare the data items
    /// (there are no field macros in UVM-SystemC )
    virtual void do_print(uvm::uvm_printer &printer) const {
        printer.print_field_int("addr", bus_req.addr);
        printer.print_field_int("data", bus_req.data);
        printer.print_field_int("trans_type", bus_req.trans_type);
    }
//    virtual void do_pack( uvm_packer& packer ) const { ... }
//    virtual void do_unpack( uvm_packer& packer ) { ... }
//    virtual void do_copy( const uvm_object* rhs ) { ... }
    virtual bool do_compare( const uvm_object& rhs ) const {
        const vip_trans_bus_req_t* rhs_ = dynamic_cast<const vip_trans_bus_req_t*>(&rhs);
        if(rhs_ == NULL)
            UVM_FATAL("do_compare", "cast failed, check type compatibility");

        return ((bus_req.addr == rhs_->bus_req.addr) &&
                (bus_req.data == rhs_->bus_req.data) &&
                (bus_req.trans_type == rhs_->bus_req.trans_type));
    }
}; // class vip_trans


class vip_trans_bus_resp_t : public uvm::uvm_sequence_item {    /// Inherits from uvm_transaction
public:
    bus_resp_t bus_resp;

    UVM_OBJECT_UTILS(vip_trans_bus_resp_t);

    vip_trans_bus_resp_t(const std::string &name = "vip_trans_bus_resp_t") {
        bus_resp.data = 0;
        bus_resp.ack = OK;
    }

    virtual void do_print(uvm::uvm_printer &printer) const {
        printer.print_field_int("data", bus_resp.data);
        printer.print_field_int("ack", bus_resp.ack);
    }
//    virtual void do_pack( uvm_packer& packer ) const { ... }
//    virtual void do_unpack( uvm_packer& packer ) { ... }
//    virtual void do_copy( const uvm_object* rhs ) { ... }
    virtual bool do_compare( const uvm_object& rhs ) const {
        const vip_trans_bus_resp_t* rhs_ = dynamic_cast<const vip_trans_bus_resp_t*>(&rhs);
        if(rhs_ == NULL)
            UVM_FATAL("do_compare", "cast failed, check type compatibility");

        return ((bus_resp.data == rhs_->bus_resp.data) &&
                (bus_resp.ack == rhs_->bus_resp.ack));
    }
}; // class vip_trans
#endif //UVMSYSTEMC_VIP_TRANS_H
