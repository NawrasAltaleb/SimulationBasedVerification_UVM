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
#include "DUT/Original/Core.h"
#include "Tests/test_init.h"

int sc_main(int argc, char* argv[])
{
    /// initiate an instance of your DUT
    DUT_Core* my_dut = new DUT_Core("my_dut");
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


    /// register interface using the configuration database
    ///     Remark: remember to specify which interface will go to which agent!
    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*","vif_MasterToBus",vif_Master_out);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*","vif_BusToMaster",vif_Master_in);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave0.*","vif_BusToSlave",vif_Slave0_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave0.*","vif_SlaveToBus",vif_Slave0_out);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave1.*","vif_BusToSlave",vif_Slave1_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave1.*","vif_SlaveToBus",vif_Slave1_out);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave2.*","vif_BusToSlave",vif_Slave2_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave2.*","vif_SlaveToBus",vif_Slave2_out);

    uvm_config_db<vip_if_BUS_REQ*>::set(NULL,"*.uvc_slave3.*","vif_BusToSlave",vif_Slave3_in);
    uvm_config_db<vip_if_BUS_RSP*>::set(NULL,"*.uvc_slave3.*","vif_SlaveToBus",vif_Slave3_out);


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

    /// Dynamically instantiates the test if given as argument and start it
    uvm::run_test();
    return 0;
}
