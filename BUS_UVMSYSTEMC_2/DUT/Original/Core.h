// Adjusts code to be appropriate for the SCAM tool
// 0 : Working ESL-Description
// 1 : Properties can be generated
#define SCAM 0
//#define DEBUG


#include "systemc.h"
#include "MasterAgent.h"
#include "SlaveAgent.h"
#include "Interconnect.h"
#include "Clk.h"

using namespace std;

#if SCAM == 0
class DUT_Core : public sc_module {
public:
    // Constructor
    SC_HAS_PROCESS(DUT_Core);

    /// Connections to the Environment
    //In-port
    blocking_in<bus_req_t> master_in;
    blocking_in<bus_resp_t> slave_in0;
    blocking_in<bus_resp_t> slave_in1;
    blocking_in<bus_resp_t> slave_in2;
    blocking_in<bus_resp_t> slave_in3;


    //Out-por
    blocking_out<bus_resp_t> master_out;
    blocking_out<bus_req_t> slave_out0;
    blocking_out<bus_req_t> slave_out1;
    blocking_out<bus_req_t> slave_out2;
    blocking_out<bus_req_t> slave_out3;


    /// Sub-Modules
    Clk clk; /// CLK has to be ahead of other instantiations
    MasterAgent masterAgent;
    SlaveAgent slaveAgent0;
    SlaveAgent slaveAgent1;
    SlaveAgent slaveAgent2;
    SlaveAgent slaveAgent3;
    Interconnect interconnect;

    /// Internal Channels
    MasterSlave<bool> clk1;
    MasterSlave<bool> clk2;
    MasterSlave<bool> clk3;
    MasterSlave<bool> clk4;
    MasterSlave<bool> clk5;
    MasterSlave<bool> clk6;
    Shared<master_signals> masterAgentToBus;
    Shared<slave_signals> busToMasterAgent;
    Shared<master_signals> InterConnToSlaveAgent0;
    Shared<master_signals> InterConnToSlaveAgent1;
    Shared<master_signals> InterConnToSlaveAgent2;
    Shared<master_signals> InterConnToSlaveAgent3;
    Shared<slave_signals> SlaveAgentTOInterconn0;
    Shared<slave_signals> SlaveAgentTOInterconn1;
    Shared<slave_signals> SlaveAgentTOInterconn2;
    Shared<slave_signals> SlaveAgentTOInterconn3;

    DUT_Core(sc_module_name name) :
            master_in("master_in"),
            slave_in0("slave_in0"),
            slave_in1("slave_in1"),
            slave_in2("slave_in2"),
            slave_in3("slave_in3"),
            master_out("master_out"),
            slave_out0("slave_out0"),
            slave_out1("slave_out1"),
            slave_out2("slave_out2"),
            slave_out3("slave_out3"),
            masterAgent("masterAgent"),
            slaveAgent0("slaveAgent0"),
            slaveAgent1("slaveAgent1"),
            slaveAgent2("slaveAgent2"),
            slaveAgent3("slaveAgent3"),
            interconnect("interconnect"),
            clk("clk"),
            clk1("clk1"),
            clk2("clk2"),
            clk3("clk3"),
            clk4("clk4"),
            clk5("clk5"),
            clk6("clk6"),
            masterAgentToBus("masterAgentToBus"),
            busToMasterAgent("busToMasterAgent"),
            InterConnToSlaveAgent0("InterConnToSlaveAgent0"),
            InterConnToSlaveAgent1("InterConnToSlaveAgent1"),
            InterConnToSlaveAgent2("InterConnToSlaveAgent2"),
            InterConnToSlaveAgent3("InterConnToSlaveAgent3"),
            SlaveAgentTOInterconn0("SlaveAgentTOInterconn0"),
            SlaveAgentTOInterconn1("SlaveAgentTOInterconn1"),
            SlaveAgentTOInterconn2("SlaveAgentTOInterconn2"),
            SlaveAgentTOInterconn3("SlaveAgentTOInterconn3") {
        //CLK
        masterAgent.clk(clk1);
        clk.clk1(clk1);

        interconnect.clk(clk2);
        clk.clk2(clk2);

        slaveAgent0.clk(clk3);
        clk.clk3(clk3);

        slaveAgent1.clk(clk4);
        clk.clk4(clk4);

        slaveAgent2.clk(clk5);
        clk.clk5(clk5);

        slaveAgent3.clk(clk6);
        clk.clk6(clk6);

        masterAgent.agent_to_bus(masterAgentToBus);
        interconnect.master_input(masterAgentToBus);
        masterAgent.bus_to_agent(busToMasterAgent);
        interconnect.master_output(busToMasterAgent);

        interconnect.slave_out0(InterConnToSlaveAgent0);
        slaveAgent0.bus_to_agent(InterConnToSlaveAgent0);
        interconnect.slave_out1(InterConnToSlaveAgent1);
        slaveAgent1.bus_to_agent(InterConnToSlaveAgent1);
        interconnect.slave_out2(InterConnToSlaveAgent2);
        slaveAgent2.bus_to_agent(InterConnToSlaveAgent2);
        interconnect.slave_out3(InterConnToSlaveAgent3);
        slaveAgent3.bus_to_agent(InterConnToSlaveAgent3);

        interconnect.slave_in0(SlaveAgentTOInterconn0);
        slaveAgent0.agent_to_bus(SlaveAgentTOInterconn0);
        interconnect.slave_in1(SlaveAgentTOInterconn1);
        slaveAgent1.agent_to_bus(SlaveAgentTOInterconn1);
        interconnect.slave_in2(SlaveAgentTOInterconn2);
        slaveAgent2.agent_to_bus(SlaveAgentTOInterconn2);
        interconnect.slave_in3(SlaveAgentTOInterconn3);
        slaveAgent3.agent_to_bus(SlaveAgentTOInterconn3);


        masterAgent.master_to_agent(master_in);
        masterAgent.agent_to_master(master_out);


        slaveAgent0.agent_to_slave(slave_out0);
        slaveAgent0.slave_to_agent(slave_in0);

        slaveAgent1.agent_to_slave(slave_out1);
        slaveAgent1.slave_to_agent(slave_in1);

        slaveAgent2.agent_to_slave(slave_out2);
        slaveAgent2.slave_to_agent(slave_in2);

        slaveAgent3.agent_to_slave(slave_out3);
        slaveAgent3.slave_to_agent(slave_in3);
    }
};

#elif SCAM == 1

int sc_main(int, char **) {

    /// Connections to the Environment
    //In-port
    blocking_in<bus_req_t> master_in("master_in");
    blocking_in<bus_resp_t> slave_in0("slave_in0");
    blocking_in<bus_resp_t> slave_in1("slave_in1");
    blocking_in<bus_resp_t> slave_in2("slave_in2");
    blocking_in<bus_resp_t> slave_in3("slave_in3");


    //Out-por
    blocking_out<bus_resp_t> master_out("master_out");
    blocking_out<bus_req_t> slave_out0("slave_out0");
    blocking_out<bus_req_t> slave_out1("slave_out1");
    blocking_out<bus_req_t> slave_out2("slave_out2");
    blocking_out<bus_req_t> slave_out3("slave_out3");

    /// Sub-Modules
    MasterAgent masterAgent("masterAgent");
    SlaveAgent slaveAgent0("slaveAgent0");
    SlaveAgent slaveAgent1("slaveAgent1");
    SlaveAgent slaveAgent2("slaveAgent2");
    SlaveAgent slaveAgent3("slaveAgent3");
    Interconnect interconnect("interconnect");

    /// Internal Channels
    Clk clk("clk1");
    MasterSlave<bool> clk1("clk1");
    MasterSlave<bool> clk2("clk2");
    MasterSlave<bool> clk3("clk3");
    MasterSlave<bool> clk4("clk4");
    MasterSlave<bool> clk5("clk5");
    MasterSlave<bool> clk6("clk6");
    Shared<master_signals> masterAgentToBus("masterAgentToBus");
    Shared<slave_signals> busToMasterAgent("busToMasterAgent");
    Shared<master_signals> InterConnToSlaveAgent0("InterConnToSlaveAgent0");
    Shared<master_signals> InterConnToSlaveAgent1("InterConnToSlaveAgent1");
    Shared<master_signals> InterConnToSlaveAgent2("InterConnToSlaveAgent2");
    Shared<master_signals> InterConnToSlaveAgent3("InterConnToSlaveAgent3");
    Shared<slave_signals> SlaveAgentTOInterconn0("SlaveAgentTOInterconn0");
    Shared<slave_signals> SlaveAgentTOInterconn1("SlaveAgentTOInterconn1");
    Shared<slave_signals> SlaveAgentTOInterconn2("SlaveAgentTOInterconn2");
    Shared<slave_signals> SlaveAgentTOInterconn3("SlaveAgentTOInterconn3");

    //CLK
    masterAgent.clk(clk1);
    clk.clk1(clk1);

    interconnect.clk(clk2);
    clk.clk2(clk2);

    slaveAgent0.clk(clk3);
    clk.clk3(clk3);

    slaveAgent1.clk(clk4);
    clk.clk4(clk4);

    slaveAgent2.clk(clk5);
    clk.clk5(clk5);

    slaveAgent3.clk(clk6);
    clk.clk6(clk6);

    masterAgent.agent_to_bus(masterAgentToBus);
    interconnect.master_input(masterAgentToBus);
    masterAgent.bus_to_agent(busToMasterAgent);
    interconnect.master_output(busToMasterAgent);

    interconnect.slave_out0(InterConnToSlaveAgent0);
    slaveAgent0.bus_to_agent(InterConnToSlaveAgent0);
    interconnect.slave_out1(InterConnToSlaveAgent1);
    slaveAgent1.bus_to_agent(InterConnToSlaveAgent1);
    interconnect.slave_out2(InterConnToSlaveAgent2);
    slaveAgent2.bus_to_agent(InterConnToSlaveAgent2);
    interconnect.slave_out3(InterConnToSlaveAgent3);
    slaveAgent3.bus_to_agent(InterConnToSlaveAgent3);

    interconnect.slave_in0(SlaveAgentTOInterconn0);
    slaveAgent0.agent_to_bus(SlaveAgentTOInterconn0);
    interconnect.slave_in1(SlaveAgentTOInterconn1);
    slaveAgent1.agent_to_bus(SlaveAgentTOInterconn1);
    interconnect.slave_in2(SlaveAgentTOInterconn2);
    slaveAgent2.agent_to_bus(SlaveAgentTOInterconn2);
    interconnect.slave_in3(SlaveAgentTOInterconn3);
    slaveAgent3.agent_to_bus(SlaveAgentTOInterconn3);


    masterAgent.master_to_agent(master_in);
    masterAgent.agent_to_master(master_out);


    slaveAgent0.agent_to_slave(slave_out0);
    slaveAgent0.slave_to_agent(slave_in0);

    slaveAgent1.agent_to_slave(slave_out1);
    slaveAgent1.slave_to_agent(slave_in1);

    slaveAgent2.agent_to_slave(slave_out2);
    slaveAgent2.slave_to_agent(slave_in2);

    slaveAgent3.agent_to_slave(slave_out3);
    slaveAgent3.slave_to_agent(slave_in3);
};

#endif
