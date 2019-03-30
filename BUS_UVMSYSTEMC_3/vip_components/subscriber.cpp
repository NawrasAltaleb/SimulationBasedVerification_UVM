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
    if (this->get_name() == "subscr_Slave0_req_dut")
        sb->write_listener_Slave0_REQ_dut(t);
    else if (this->get_name() == "subscr_Slave1_req_dut")
        sb->write_listener_Slave1_REQ_dut(t);
    else if (this->get_name() == "subscr_Slave2_req_dut")
        sb->write_listener_Slave2_REQ_dut(t);
    else if (this->get_name() == "subscr_Slave3_req_dut")
        sb->write_listener_Slave3_REQ_dut(t);
    else if (this->get_name() == "subscr_Slave0_req_gm")
        sb->write_listener_Slave0_REQ_gm(t);
    else if (this->get_name() == "subscr_Slave1_req_gm")
        sb->write_listener_Slave1_REQ_gm(t);
    else if (this->get_name() == "subscr_Slave2_req_gm")
        sb->write_listener_Slave2_REQ_gm(t);
    else if (this->get_name() == "subscr_Slave3_req_gm")
        sb->write_listener_Slave3_REQ_gm(t);

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
    if(this->get_name() == "subscr_Master_rsp_dut")
        sb->write_listener_Master_RSP_dut(t);
    else if (this->get_name() == "subscr_Master_rsp_gm")
        sb->write_listener_Master_RSP_gm(t);
}
