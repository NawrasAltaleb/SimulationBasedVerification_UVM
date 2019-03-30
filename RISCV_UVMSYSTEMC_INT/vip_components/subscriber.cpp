//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#include "subscriber.h"
#include "scoreboard.h"


///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////

subscriber_toMemory::subscriber_toMemory(uvm_component_name name): uvm_subscriber(name) {}

/// Implementation of the write method for the export in the monitor (in our case it's the driver in the active agent)
void subscriber_toMemory::write(const vip_trans_toMemory& t) {

    sc_object* obj = get_parent();
    scoreboard* sb;
    sb = dynamic_cast<scoreboard*>(obj);
    /// Transactions (toMemory) are passed to the parenting scoreboard
    if (this->get_name() == "subscr_toMemory_dut")
        sb->write_listener_toMemory_dut(t);
    else if (this->get_name() == "subscr_toMemory_gm")
        sb->write_listener_toMemory_gm(t);
}

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////

subscriber_fromMemory::subscriber_fromMemory(uvm_component_name name) : uvm_subscriber(name) {}

/// Implementation of the write method for the export in the monitor (in our case it's the driver in the active agent)
void subscriber_fromMemory::write(const vip_trans_fromMemory& t)
{
    sc_object* obj = get_parent();
    scoreboard* sb;
    sb = dynamic_cast<scoreboard*>(obj);
    /// Transactions (fromMemory) are passed to the parenting scoreboard
    if (this->get_name() == "subscr_fromMemory_dut")
        sb->write_listener_fromMemory_dut(t);
    else if (this->get_name() == "subscr_fromMemory_gm")
        sb->write_listener_fromMemory_gm(t);
}

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////