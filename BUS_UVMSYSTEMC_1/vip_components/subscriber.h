//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#ifndef UVMSYSTEMC_SUBSCRIBERS_H
#define UVMSYSTEMC_SUBSCRIBERS_H

#include <uvm>
#include "vip_trans.h"

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////

class subscriber_REQ: public uvm::uvm_subscriber<vip_trans_bus_req_t> {
public:
    subscriber_REQ(uvm::uvm_component_name name);

    UVM_COMPONENT_UTILS(subscriber_REQ)

    virtual void write(const vip_trans_bus_req_t &t);
};

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////

class subscriber_RSP: public uvm::uvm_subscriber<vip_trans_bus_resp_t> {
public:
    subscriber_RSP(uvm::uvm_component_name name);

    UVM_COMPONENT_UTILS(subscriber_RSP)

    virtual void write(const vip_trans_bus_resp_t &t);
};


#endif //UVMSYSTEMC_SUBSCRIBERS_H
