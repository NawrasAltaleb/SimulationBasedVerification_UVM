#ifndef SYSTEMC_DUT_H
#define SYSTEMC_DUT_H

#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"
#include "Clk.h"
#include "Interconnect.h"
#include "MasterAgent.h"
#include "SlaveAgent.h"
using namespace std;

class DUT_Core : public sc_module {
public:
  // Constructor
  SC_HAS_PROCESS(DUT_Core);

  Clk clk;
  Interconnect interconnect;
  MasterAgent masterAgent;
  SlaveAgent slaveAgent0;
  SlaveAgent slaveAgent1;
  SlaveAgent slaveAgent2;
  SlaveAgent slaveAgent3;

  Shared<master_signals> InterConnToSlaveAgent0;
  Shared<master_signals> InterConnToSlaveAgent1;
  Shared<master_signals> InterConnToSlaveAgent2;
  Shared<master_signals> InterConnToSlaveAgent3;
  Shared<slave_signals> SlaveAgentTOInterconn0;
  Shared<slave_signals> SlaveAgentTOInterconn1;
  Shared<slave_signals> SlaveAgentTOInterconn2;
  Shared<slave_signals> SlaveAgentTOInterconn3;
  Shared<slave_signals> busToMasterAgent;
  MasterSlave<bool> clk1;
  MasterSlave<bool> clk2;
  MasterSlave<bool> clk3;
  MasterSlave<bool> clk4;
  MasterSlave<bool> clk5;
  MasterSlave<bool> clk6;
  Shared<master_signals> masterAgentToBus;
  blocking_in<bus_req_t> master_in;
  blocking_out<bus_resp_t> master_out;
  blocking_in<bus_resp_t> slave_in0;
  blocking_in<bus_resp_t> slave_in1;
  blocking_in<bus_resp_t> slave_in2;
  blocking_in<bus_resp_t> slave_in3;
  blocking_out<bus_req_t> slave_out0;
  blocking_out<bus_req_t> slave_out1;
  blocking_out<bus_req_t> slave_out2;
  blocking_out<bus_req_t> slave_out3;


  DUT_Core(sc_module_name name) :
    clk("clk_name"),
    interconnect("interconnect_name"),
    masterAgent("masterAgent_name"),
    slaveAgent0("slaveAgent0_name"),
    slaveAgent1("slaveAgent1_name"),
    slaveAgent2("slaveAgent2_name"),
    slaveAgent3("slaveAgent3_name"),
    InterConnToSlaveAgent0("InterConnToSlaveAgent0_name"),
    InterConnToSlaveAgent1("InterConnToSlaveAgent1_name"),
    InterConnToSlaveAgent2("InterConnToSlaveAgent2_name"),
    InterConnToSlaveAgent3("InterConnToSlaveAgent3_name"),
    SlaveAgentTOInterconn0("SlaveAgentTOInterconn0_name"),
    SlaveAgentTOInterconn1("SlaveAgentTOInterconn1_name"),
    SlaveAgentTOInterconn2("SlaveAgentTOInterconn2_name"),
    SlaveAgentTOInterconn3("SlaveAgentTOInterconn3_name"),
    busToMasterAgent("busToMasterAgent_name"),
    clk1("clk1_name"),
    clk2("clk2_name"),
    clk3("clk3_name"),
    clk4("clk4_name"),
    clk5("clk5_name"),
    clk6("clk6_name"),
    masterAgentToBus("masterAgentToBus_name"),
    master_in("master_in_name"),
    master_out("master_out_name"),
    slave_in0("slave_in0_name"),
    slave_in1("slave_in1_name"),
    slave_in2("slave_in2_name"),
    slave_in3("slave_in3_name"),
    slave_out0("slave_out0_name"),
    slave_out1("slave_out1_name"),
    slave_out2("slave_out2_name"),
    slave_out3("slave_out3_name") {
    interconnect.slave_out0(InterConnToSlaveAgent0);
    slaveAgent0.bus_to_agent(InterConnToSlaveAgent0);
    interconnect.slave_out1(InterConnToSlaveAgent1);
    slaveAgent1.bus_to_agent(InterConnToSlaveAgent1);
    interconnect.slave_out2(InterConnToSlaveAgent2);
    slaveAgent2.bus_to_agent(InterConnToSlaveAgent2);
    interconnect.slave_out3(InterConnToSlaveAgent3);
    slaveAgent3.bus_to_agent(InterConnToSlaveAgent3);
    slaveAgent0.agent_to_bus(SlaveAgentTOInterconn0);
    interconnect.slave_in0(SlaveAgentTOInterconn0);
    slaveAgent1.agent_to_bus(SlaveAgentTOInterconn1);
    interconnect.slave_in1(SlaveAgentTOInterconn1);
    slaveAgent2.agent_to_bus(SlaveAgentTOInterconn2);
    interconnect.slave_in2(SlaveAgentTOInterconn2);
    slaveAgent3.agent_to_bus(SlaveAgentTOInterconn3);
    interconnect.slave_in3(SlaveAgentTOInterconn3);
    interconnect.master_output(busToMasterAgent);
    masterAgent.bus_to_agent(busToMasterAgent);
    clk.clk1(clk1);
    masterAgent.clk(clk1);
    clk.clk2(clk2);
    interconnect.clk(clk2);
    clk.clk3(clk3);
    slaveAgent0.clk(clk3);
    clk.clk4(clk4);
    slaveAgent1.clk(clk4);
    clk.clk5(clk5);
    slaveAgent2.clk(clk5);
    clk.clk6(clk6);
    slaveAgent3.clk(clk6);
    masterAgent.agent_to_bus(masterAgentToBus);
    interconnect.master_input(masterAgentToBus);
    masterAgent.master_to_agent(master_in);
    masterAgent.agent_to_master(master_out);
    slaveAgent0.slave_to_agent(slave_in0);
    slaveAgent1.slave_to_agent(slave_in1);
    slaveAgent2.slave_to_agent(slave_in2);
    slaveAgent3.slave_to_agent(slave_in3);
    slaveAgent0.agent_to_slave(slave_out0);
    slaveAgent1.agent_to_slave(slave_out1);
    slaveAgent2.agent_to_slave(slave_out2);
    slaveAgent3.agent_to_slave(slave_out3);
  }
};
#endif //SYSTEMC_DUT_H
