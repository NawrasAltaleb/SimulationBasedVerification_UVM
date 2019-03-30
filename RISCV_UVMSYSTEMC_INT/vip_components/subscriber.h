//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#ifndef UVMSYSTEMC_SUBSCRIBERS_H
#define UVMSYSTEMC_SUBSCRIBERS_H

#include <uvm>
#include "vip_trans.h"
using namespace uvm;

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////

class subscriber_toMemory: public uvm_subscriber<vip_trans_toMemory> {
public:
    subscriber_toMemory(uvm_component_name name);

    UVM_COMPONENT_UTILS(subscriber_toMemory)

    virtual void write(const vip_trans_toMemory& t);
};

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////

class subscriber_fromMemory: public uvm_subscriber<vip_trans_fromMemory> {
public:
    subscriber_fromMemory(uvm_component_name name);

    UVM_COMPONENT_UTILS(subscriber_fromMemory)

    virtual void write(const vip_trans_fromMemory &t);
};

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////

#endif //UVMSYSTEMC_SUBSCRIBERS_H
