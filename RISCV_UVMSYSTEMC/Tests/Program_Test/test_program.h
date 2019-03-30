//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/22/18.
//
/**
 * \class: UVM test
    - Each UVM test is defined as a dedicated test class, which instantiates the testbench and defines the test sequence(s).
        * exp. test for Register type instructions
        * in some tests we might change the testbench used. i.e. when we are including interrupts as signals to the DUT.
    - Reuse of tests and topologies is possible by deriving tests from a test base class.
        * creating future test can be much easier because you only need to change the sequences (scenarios) for the test.
    - The configuration and factory concept can be used to configure or override UVM components, sequences or sequence items
        * something like this:
            uvm::uvm_config_db<int>::set(NULL, "tb.*", "seq_type", 1);
            uvm::uvm_config_db<instr_constraint_type>::set(NULL, "tb.*", "constraint_type", Reg_Reg);
    - Tests can be selected (passed) as command line option
        * Thought it's said that this is not yet available in UVM-SystemC but we can do this manually
 */

#ifndef UVMSYSTEMC_TEST_PROGRAM_H
#define UVMSYSTEMC_TEST_PROGRAM_H

#include <uvm>
#include "vip_components/testbench.h"
#include "sequence_program.h"
using namespace uvm;
#include "Tests/Program_Test/ELFstyle/elf_loader.h"
#include "Tests/Program_Test/ELFstyle/memory.h"

class test_program : public uvm_test
{
public:
    testbench* tb;
    sequence_program<vip_trans_fromMemory, vip_trans_toMemory>* my_seq;
    std::string input_program;
    unsigned int mem_size;
    unsigned int mem_start_addr;

    test_program( uvm_component_name name ) : uvm_test( name ) {}

    UVM_COMPONENT_UTILS(test_program)
    void build_phase( uvm_phase& phase )
    {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb",this);
        my_seq = sequence_program<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("my_seq",this);

        uvm_config_db<string>::get(this, "*", "input_program", input_program);
        uvm_config_db<unsigned int>::get(this, "*", "mem_size", mem_size);
        uvm_config_db<unsigned int>::get(this, "*", "mem_start_addr", mem_start_addr);
        ELFLoader loader(input_program.c_str());
        Memory ME("ME", mem_size);
        loader.load_executable_image(ME.mem, ME.size, mem_start_addr);

        my_seq->size = mem_size;
        my_seq->mem = ME.mem;
    }


    void end_of_elaboration_phase( uvm_phase& phase){
        uvm_report_info( "Program Test: " + input_program, "************** UVM TEST STARTED **************", uvm::UVM_NONE );
        std::cout<< "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        phase.raise_objection(this,"Starting test");
//        my_seq->start(tb->agent->sequencer);
        my_seq->start(tb->uvc->agent->sequencer);
        phase.drop_objection(this,"Finishing test");
    }

    void report_phase( uvm_phase& phase )
    {
        std::cout<< "\n\n\n";
        uvm_report_info( "Program Test: " + input_program, "************** UVM TEST ENDED **************", uvm::UVM_NONE );
    }
};

#endif //UVMSYSTEMC_TEST_PROGRAM_H