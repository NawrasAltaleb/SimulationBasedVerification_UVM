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
            uvm_config_db<int>::set(NULL, "tb.*", "seq_type", 1);
            uvm_config_db<instr_constraint_type>::set(NULL, "tb.*", "constraint_type", Reg_Reg);
    - Tests can be selected (passed) as command line option
        * Thought it's said that this is not yet available in UVM-SystemC but we can do this manually
 */

#ifndef UVMSYSTEMC_SINGLE_TYPE_TESTS_H
#define UVMSYSTEMC_SINGLE_TYPE_TESTS_H

#include <uvm>
#include "vip_components/testbench.h"
#include "Single_Type_Sequences.h"
//#include "vip_components/Virtual_Sequence.h"
using namespace uvm;

class test_R : public uvm_test {
public:
    testbench *tb;
    sequence_R<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_R<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_R(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_R)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_R<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_R<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("R_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_R::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_R::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("R_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

class test_I_I : public uvm_test {
public:
    testbench *tb;
    sequence_I_I<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_I_I<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_I_I(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_I_I)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_I_I<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_I_I<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("I_I_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_I_I::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_I_I::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("I_I_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

class test_I_L : public uvm_test {
public:
    testbench *tb;
    sequence_I_L<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_I_L<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_I_L(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_I_L)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_I_L<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_I_L<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("I_L_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_I_L::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_I_L::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("I_L_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

class test_I_J : public uvm_test {
public:
    testbench *tb;
    sequence_I_J<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_I_J<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_I_J(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_I_J)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_I_J<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_I_J<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("I_J_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_I_J::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_I_J::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("I_J_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

class test_S : public uvm_test {
public:
    testbench *tb;
    sequence_S<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_S<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_S(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_S)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_S<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_S<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("S_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_S::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_S::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("S_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

class test_B : public uvm_test {
public:
    testbench *tb;
    sequence_B<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_B<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_B(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_B)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_B<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_B<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("B_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_B::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_B::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("B_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

class test_U : public uvm_test {
public:
    testbench *tb;
    sequence_U<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_U<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_U(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_U)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_U<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_U<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("U_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_U::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_U::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("U_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

class test_J : public uvm_test {
public:
    testbench *tb;
    sequence_J<vip_trans_fromMemory, vip_trans_toMemory> *seq_dut;
    sequence_J<vip_trans_fromMemory, vip_trans_toMemory> *seq_gm;

    test_J(uvm_component_name name) : uvm_test(name) {}

    UVM_COMPONENT_UTILS(test_J)

    void build_phase(uvm_phase &phase) {
        uvm_test::build_phase(phase);
        tb = testbench::type_id::create("tb", this);
        seq_dut = sequence_J<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_dut",this);
        seq_gm = sequence_J<vip_trans_fromMemory, vip_trans_toMemory>::type_id::create("seq_gm",this);
        seq_dut->seedNUM = 555;
        seq_gm->seedNUM = 555;
    }

    void end_of_elaboration_phase(uvm_phase &phase) {
        uvm_report_info("J_Type Test", "**************************** UVM TEST STARTED ****************************", uvm::UVM_NONE);
        std::cout << "\n\n\n\n\t\t\t toMemory Direction \t\t\t   ----   \t\t\t fromMemory Direction \n";
    }

    void run_phase(uvm::uvm_phase &phase) {
        SC_FORK
                            sc_spawn(sc_bind(&test_J::doSeq, this, &phase, 0)),
                            sc_spawn(sc_bind(&test_J::doSeq, this, &phase, 1))
        SC_JOIN
    }

    void doSeq(uvm_phase* phase, int choice){
        phase->raise_objection(this,"Starting test");
        if(choice == 0)
            seq_dut->start(tb->uvc->agent->sequencer);
        else if (choice == 1)
            seq_gm->start(tb->uvc_gm->agent->sequencer);
        phase->drop_objection(this,"Finishing test");
    }

    void report_phase(uvm_phase &phase) {
        std::cout << "\n\n\n";
        uvm_report_info("J_Type Test", "**************************** UVM TEST ENDED ****************************", uvm::UVM_NONE);
    }
};

#endif //UVMSYSTEMC_SINGLE_TYPE_TESTS_H