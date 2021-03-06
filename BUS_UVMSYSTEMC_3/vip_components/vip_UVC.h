//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: UVM verification component (UVC)
    - A reusable verification component (UVC) is a (sub-) environment which consists of one or more agents.
    - The verification component or agents may set or get configuration parameters.
    - An independent sequence, which contains the actual transaction data, is processed by the driver via a sequencer.
    - Each verification component is connected to the DUT using a dedicated interface.

    Remark Might use such a method if we want to separate different signal interfaces to the dut with different sequences and sequences's items instead of using a packed
        item style.
 */
#ifndef UVMSYSTEMC_VIP_UVC_H
#define UVMSYSTEMC_VIP_UVC_H

#include "vip_agent.h"

class vip_uvc_Master : public uvm_env /// A UVC is treated as a sub-environment in large-system level environments
{
public:
    vip_agent_Master *agent;

    UVM_COMPONENT_UTILS(vip_uvc_Master);

    vip_uvc_Master(uvm_component_name name)
            : uvm_env(name), agent(0) {}

    void build_phase(uvm_phase &phase) /// Components are instantiated in the build phase
    {
        uvm_env::build_phase(phase); /// Essential call to base class to access properties of the env
        agent = vip_agent_Master::type_id::create("agent", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(agent);
    }

}; // class vip_uvc



class vip_uvc_Slave : public uvm_env /// A UVC is treated as a sub-environment in large-system level environments
{
public:
    vip_agent_Slave *agent;

    UVM_COMPONENT_UTILS(vip_uvc_Slave);

    vip_uvc_Slave(uvm_component_name name)
            : uvm_env(name), agent(0) {}

    void build_phase(uvm_phase &phase) /// Components are instantiated in the build phase
    {
        uvm_env::build_phase(phase); /// Essential call to base class to access properties of the env
        agent = vip_agent_Slave::type_id::create("agent", this); /// Call to the factory which creates and instantiates this component dynamically
        assert(agent);
    }

}; // class vip_uvc
#endif //UVMSYSTEMC_VIP_AGENT_H