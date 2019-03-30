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

#include <tinyxml/tinyxml.h>
#include <uvm>
#include "options.h"
#include "vip_components/vip_if.h"
#include "Golden_Reference/GOLDEN_Core.h"
//#include "DUT/DUT_Core.h"
//#include "DUT/Original/Core.h"
//#include "DUT_INT/Original/Core.h"
//#include "../RISCV_Pipelined/ESL/Core.h"
//#include "DUT_pipelined/PrintPercentage/DUT_Core.h"
#include "DUT_pipelined/DUT_Core.h"
//#include "DUT_pipelined/Original/Core.h"
//#include "../RISCV_ISA/ESL/Core.h"
#include "Tests/Single_Type_Tests/Single_Type_Tests.h"
#include "Tests/test_init.h"
#include "Tests/Program_Test/test_program.h"
using namespace uvm;

int sc_main(int argc, char* argv[])
{
    /// initiate an instance of your DUT
    G_Core* my_GM = new G_Core("my_GM");

    DUT_Core* my_dut = new DUT_Core("my_dut");
//    Core* my_dut = new Core("my_dut");
    uvm::uvm_test* my_test;

    Options opt = parse_command_line_arguments(argc, argv);
    if(opt.use_program) {
        my_test = new test_program("my_test");
        uvm::uvm_config_db<string>::set(NULL, "my_test.*", "input_program", opt.input_program);
        uvm::uvm_config_db<unsigned int>::set(NULL, "my_test.*", "mem_size", opt.mem_size);
        uvm::uvm_config_db<unsigned int>::set(NULL, "my_test.*", "mem_start_addr", opt.mem_start_addr);
    } else {
        if (opt.input_program == "test_R")
            my_test = new test_R("my_test");
        else if (opt.input_program == "test_I_I")
            my_test = new test_I_I("my_test");
        else if (opt.input_program == "test_I_L")
            my_test = new test_I_L("my_test");
        else if (opt.input_program == "test_I_J")
            my_test = new test_I_J("my_test");
        else if (opt.input_program == "test_S")
            my_test = new test_S("my_test");
        else if (opt.input_program == "test_B")
            my_test = new test_B("my_test");
        else if (opt.input_program == "test_U")
            my_test = new test_U("my_test");
        else if (opt.input_program == "test_J")
            my_test = new test_J("my_test");
        else if (opt.input_program == "test_mini")
            my_test = new test_mini("my_test");
//        else if (opt.input_program == "test_hex")
//            my_test = new test_hex("my_test");
//        else
//            my_test = new test_init("my_test");
    }



    auto* g_vif_fromMemory = new vip_if_fromMemory;
    auto* g_vif_toMemory = new vip_if_toMemory;
    uvm_config_db<vip_if_fromMemory*>::set(NULL, "*.uvc_gm.*", "vif_fromMemory", g_vif_fromMemory);
    uvm_config_db<vip_if_toMemory*>::set(NULL, "*.uvc_gm.*", "vif_toMemory", g_vif_toMemory);

    //define the connections types and configure which one is used in which agent
    auto* vif_fromMemory = new vip_if_fromMemory;
    auto* vif_toMemory = new vip_if_toMemory;
    /// register interface using the configuration database
    ///     Remark: remember to specify which interface will go to which agent!
    uvm_config_db<vip_if_fromMemory*>::set(NULL, "*.uvc.*", "vif_fromMemory", vif_fromMemory);
    uvm_config_db<vip_if_toMemory*>::set(NULL, "*.uvc.*", "vif_toMemory", vif_toMemory);


    my_GM->MEtoCO_port(g_vif_fromMemory->fromMemory_Port);
    my_GM->COtoME_port(g_vif_toMemory->toMemory_Port);
    /// Connect DUT to the interface
    my_dut->MEtoCO_port(vif_fromMemory->fromMemory_Port);
    my_dut->COtoME_port(vif_toMemory->toMemory_Port);
    /// Dynamically instantiates the test if given as argument and start it

    uvm::run_test();

    std::cout<<"Coverage: \n";
    std::cout<<"CU: "<<my_dut->CU.coveragePointsCount*100/my_dut->CU.coveragePointsTotal<<"%\n";
    std::cout<<"DP: "<<my_dut->DP.coveragePointsCount*100/my_dut->DP.coveragePointsTotal<<"%\n";
    std::cout<<"RF: "<<my_dut->RF.coveragePointsCount*100/my_dut->RF.coveragePointsTotal<<"%\n";
    return 0;
}