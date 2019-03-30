//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#include "subscriber.h"
#include "vip_components/scoreboard.h"

///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////


subscriber_REQ::subscriber_REQ(uvm_component_name name) : uvm_subscriber(name) {}

/// Implementation of the write method for the export in the monitor (in our case it's the driver in the active agent)
void subscriber_REQ::write(const vip_trans_bus_req_t& t)
{
    sc_object *obj = get_parent();
    scoreboard *sb;
    sb = dynamic_cast<scoreboard *>(obj);
    if(this->get_name() == "subscr_Master_req")
        sb->write_listener_Master_REQ(t);
    else if (this->get_name() == "subscr_Slave0_req")
        sb->write_listener_Slave0_REQ(t);
    else if (this->get_name() == "subscr_Slave1_req")
        sb->write_listener_Slave1_REQ(t);
    else if (this->get_name() == "subscr_Slave2_req")
        sb->write_listener_Slave2_REQ(t);
    else if (this->get_name() == "subscr_Slave3_req")
        sb->write_listener_Slave3_REQ(t);
}


///////////////////////////////////////////////////////////
/// *************************************************** ///
///////////////////////////////////////////////////////////


subscriber_RSP::subscriber_RSP(uvm_component_name name) : uvm_subscriber(name) {}

/// Implementation of the write method for the export in the monitor (in our case it's the driver in the active agent)
void subscriber_RSP::write(const vip_trans_bus_resp_t &t)
{
    sc_object* obj = get_parent();
    scoreboard* sb;
    sb = dynamic_cast<scoreboard*>(obj);
    if(this->get_name() == "subscr_Master_rsp")
        sb->write_listener_Master_RSP(t);
    else if (this->get_name() == "subscr_Slave0_rsp")
        sb->write_listener_Slave0_RSP(t);
    else if (this->get_name() == "subscr_Slave1_rsp")
        sb->write_listener_Slave1_RSP(t);
    else if (this->get_name() == "subscr_Slave2_rsp")
        sb->write_listener_Slave2_RSP(t);
    else if (this->get_name() == "subscr_Slave3_rsp")
        sb->write_listener_Slave3_RSP(t);
}
