//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//
/**
 * \class: Top
 *      - The top-level (e.g. sc_main) contains the test(s) and the DUT
 *              Remark: we might send the requested tests names through commandline arguments
 *      - The interface to which the DUT is connected is stored in the configuration database, so it can be used by the UVCs to connect to the DUT.
 *      - The test to be executed is either defined by the test class instantiation or by the argument of the member function run_test.
 *              Remark: run_test("arg") will be our way to present the commandline argument (desired test) to decide what test to be executed.
 */

#include <uvm>

#include "vip_components/vip_if.h"
#include "DUT/Original/Bus.h"
#include "Golden_Reference/Bus.h"
#include "Tests/test_init.h"

int sc_main(int argc, char* argv[])
{
    /// initiate an instance of your DUT
    GoldenBus* my_gm = new GoldenBus("my_gm");
    Bus* my_dut = new Bus("my_dut");
//    DUT_Core* my_dut = new DUT_Core("my_dut");
    uvm::uvm_test* my_test = new test_init("my_test");


    //define the connections types and configure which one is used in which agent
    auto* vif_Master_out = new vip_if_BUS_REQ;
    auto* vif_Master_in = new vip_if_BUS_RSP;

    auto* vif_Slave0_in = new vip_if_BUS_REQ;
    auto* vif_Slave0_out = new vip_if_BUS_RSP;
    auto* vif_Slave1_in = new vip_if_BUS_REQ;
    auto* vif_Slave1_out = new vip_if_BUS_RSP;
    auto* vif_Slave2_in = new vip_if_BUS_REQ;
    auto* vif_Slave2_out = new vip_if_BUS_RSP;
    auto* vif_Slave3_in = new vip_if_BUS_REQ;
    auto* vif_Slave3_out = new vip_if_BUS_RSP;


    auto* gm_Master_REQ = new vip_if_BUS_REQ;
    auto* gm_Master_RSP = new vip_if_BUS_RSP;

    auto* gm_Slave0_REQ = new vip_if_BUS_REQ;
    auto* gm_Slave0_RSP = new vip_if_BUS_RSP;
    auto* gm_Slave1_REQ = new vip_if_BUS_REQ;
    auto* gm_Slave1_RSP = new vip_if_BUS_RSP;
    auto* gm_Slave2_REQ = new vip_if_BUS_REQ;
    auto* gm_Slave2_RSP = new vip_if_BUS_RSP;
    auto* gm_Slave3_REQ = new vip_if_BUS_REQ;
    auto* gm_Slave3_RSP = new vip_if_BUS_RSP;

    /// register interface using the configuration database
    ///     Remark: remember to specify which interface will go to which agent!
    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_master.*","vif_MasterToBus",vif_Master_out);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_master.*","vif_BusToMaster",vif_Master_in);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave0.*","vif_BusToSlave",vif_Slave0_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave0.*","vif_SlaveToBus",vif_Slave0_out);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave1.*","vif_BusToSlave",vif_Slave1_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave1.*","vif_SlaveToBus",vif_Slave1_out);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave2.*","vif_BusToSlave",vif_Slave2_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave2.*","vif_SlaveToBus",vif_Slave2_out);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave3.*","vif_BusToSlave",vif_Slave3_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave3.*","vif_SlaveToBus",vif_Slave3_out);

    /// same thing for Golden Model
    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_gm_master.*","vif_MasterToBus",gm_Master_REQ);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_gm_master.*","vif_BusToMaster",gm_Master_RSP);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_gm_slave0.*","vif_BusToSlave",gm_Slave0_REQ);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_gm_slave0.*","vif_SlaveToBus",gm_Slave0_RSP);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_gm_slave1.*","vif_BusToSlave",gm_Slave1_REQ);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_gm_slave1.*","vif_SlaveToBus",gm_Slave1_RSP);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_gm_slave2.*","vif_BusToSlave",gm_Slave2_REQ);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_gm_slave2.*","vif_SlaveToBus",gm_Slave2_RSP);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_gm_slave3.*","vif_BusToSlave",gm_Slave3_REQ);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_gm_slave3.*","vif_SlaveToBus",gm_Slave3_RSP);

    /// Connect DUT to the interface
    my_dut->master_in(vif_Master_out->BUS_REQ);
    my_dut->slave_out0(vif_Slave0_in->BUS_REQ);
    my_dut->slave_out1(vif_Slave1_in->BUS_REQ);
    my_dut->slave_out2(vif_Slave2_in->BUS_REQ);
    my_dut->slave_out3(vif_Slave3_in->BUS_REQ);
    my_dut->slave_in0(vif_Slave0_out->BUS_RSP);
    my_dut->slave_in1(vif_Slave1_out->BUS_RSP);
    my_dut->slave_in2(vif_Slave2_out->BUS_RSP);
    my_dut->slave_in3(vif_Slave3_out->BUS_RSP);
    my_dut->master_out(vif_Master_in->BUS_RSP);

    my_gm->master_in(gm_Master_REQ->BUS_REQ);
    my_gm->slave_out0(gm_Slave0_REQ->BUS_REQ);
    my_gm->slave_out1(gm_Slave1_REQ->BUS_REQ);
    my_gm->slave_out2(gm_Slave2_REQ->BUS_REQ);
    my_gm->slave_out3(gm_Slave3_REQ->BUS_REQ);
    my_gm->slave_in0(gm_Slave0_RSP->BUS_RSP);
    my_gm->slave_in1(gm_Slave1_RSP->BUS_RSP);
    my_gm->slave_in2(gm_Slave2_RSP->BUS_RSP);
    my_gm->slave_in3(gm_Slave3_RSP->BUS_RSP);
    my_gm->master_out(gm_Master_RSP->BUS_RSP);

    /// Dynamically instantiates the test if given as argument and start it
    uvm::run_test();

//    std::cout<<"Coverage: \n";
//    std::cout<<"clk: "<<my_dut->clk.coveragePointsCount*100/my_dut->clk.coveragePointsTotal<<"%\n";
//    std::cout<<"interconnect: "<<my_dut->interconnect.coveragePointsCount*100/my_dut->interconnect.coveragePointsTotal<<"%\n";
//    std::cout<<"masterAgent: "<<my_dut->masterAgent.coveragePointsCount*100/my_dut->masterAgent.coveragePointsTotal<<"%\n";
//    std::cout<<"slaveAgent0: "<<my_dut->slaveAgent0.coveragePointsCount*100/my_dut->slaveAgent0.coveragePointsTotal<<"%\n";
//    std::cout<<"slaveAgent1: "<<my_dut->slaveAgent1.coveragePointsCount*100/my_dut->slaveAgent1.coveragePointsTotal<<"%\n";
//    std::cout<<"slaveAgent2: "<<my_dut->slaveAgent2.coveragePointsCount*100/my_dut->slaveAgent2.coveragePointsTotal<<"%\n";
//    std::cout<<"slaveAgent3: "<<my_dut->slaveAgent3.coveragePointsCount*100/my_dut->slaveAgent3.coveragePointsTotal<<"%\n";
//
//    for(int i=1;i<my_dut->masterAgent.coveragePointsTotal;i++){
//        if(!my_dut->masterAgent.coveragePoints["MasterAgent_"+to_string(i)])
//            std::cout<<"Uncovered: "<<"MasterAgent_"+to_string(i)<<"\n";
//    }
    return 0;
}
