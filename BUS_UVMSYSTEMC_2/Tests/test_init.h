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

#ifndef UVMSYSTEMC_TEST_INIT_H
#define UVMSYSTEMC_TEST_INIT_H

//#include <uvm>
#include "vip_components/testbench.h"
#include "sequence_init.h"
//#include "vip_components/Virtual_Sequence.h"
//using namespace uvm;

class test_init : public uvm_test {
public:
    testbench *tb;
    sequence_REQ<vip_trans_bus_req_t>* seq_Master;
    sequence_RSP<vip_trans_bus_resp_t>* seq_Slave0;
    sequence_RSP<vip_trans_bus_resp_t>* seq_Slave1;
    sequence_RSP<vip_trans_bus_resp_t>* seq_Slave2;
    sequence_RSP<vip_trans_bus_resp_t>* seq_Slave3;

    test_init(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_init)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_Master = sequence_REQ<vip_trans_bus_req_t>::type_id::create("seq_Master",this);
        seq_Slave0 = sequence_RSP<vip_trans_bus_resp_t>::type_id::create("seq_Slave0",this);
        seq_Slave1 = sequence_RSP<vip_trans_bus_resp_t>::type_id::create("seq_Slave1",this);
        seq_Slave2 = sequence_RSP<vip_trans_bus_resp_t>::type_id::create("seq_Slave2",this);
        seq_Slave3 = sequence_RSP<vip_trans_bus_resp_t>::type_id::create("seq_Slave3",this);
//        uvm_config_db<uvm_object_wrapper *>::set(this, "tb.virtual_sequencer.run_phase", "default_sequence",
//                                                 virt_sequence::type_id::get());

//        uvm_config_db<uvm_object_wrapper *>::set(this, "tb.uvc_master.agent.sequencer.run_phase", "default_sequence",
//                                                 sequence_REQ<vip_trans_bus_req_t>::type_id::get());
//        uvm_config_db<uvm_object_wrapper *>::set(this, "tb.uvc_slave0.agent.sequencer.run_phase", "default_sequence",
//                                                 sequence_RSP<vip_trans_bus_resp_t>::type_id::get());
//        uvm_config_db<uvm_object_wrapper *>::set(this, "tb.uvc_slave1.agent.sequencer.run_phase", "default_sequence",
//                                                 sequence_RSP<vip_trans_bus_resp_t>::type_id::get());
//        uvm_config_db<uvm_object_wrapper *>::set(this, "tb.uvc_slave2.agent.sequencer.run_phase", "default_sequence",
//                                                 sequence_RSP<vip_trans_bus_resp_t>::type_id::get());
//        uvm_config_db<uvm_object_wrapper *>::set(this, "tb.uvc_slave3.agent.sequencer.run_phase", "default_sequence",
//                                                 sequence_RSP<vip_trans_bus_resp_t>::type_id::get());
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("Init Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t Master Direction \t\t\t   ----   \t\t\t Slave Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_init::doMasterseq, this, &phase)),
                            sc_spawn(sc_bind(&test_init::doSlaveseq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_init::doSlaveseq, this, &phase, 1)),
                            sc_spawn(sc_bind(&test_init::doSlaveseq, this, &phase, 2)),
                            sc_spawn(sc_bind(&test_init::doSlaveseq, this, &phase, 3))
        SC_JOIN
    }

    void doMasterseq(uvm_phase* phase){
        phase->raise_objection(this,"Starting test");
        seq_Master->start(tb->uvc_master->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void doSlaveseq(uvm_phase* phase, int choice){
        if(choice == 0)
            seq_Slave0->start(tb->uvc_slave0->agent->sequencer);
        else if (choice == 1)
            seq_Slave1->start(tb->uvc_slave1->agent->sequencer);
        else if (choice == 2)
            seq_Slave2->start(tb->uvc_slave2->agent->sequencer);
        else if (choice == 3)
            seq_Slave3->start(tb->uvc_slave3->agent->sequencer);
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("Init Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};
#endif //UVMSYSTEMC_TEST_INIT_H