This README gives an overview of the test suite built using UVMSYSTEMC and used with ESL implementations of Bus with 1 Master and 4 Slaves.

**Content:**
- *Golden_Reference*: Simple ESL implementation of Bus that is used as a reference model when testing.
- *Tests*: a scenarios that could be used as series of master requests to the DUT.
- *vip_components*: includes the universal verification components used by the test suite regardless of what test is running.
- *Top.cpp*: includes the configurations for what test to run and what implementation to test.

# Universal Verification Methodology (UVM) and UVMSYSTEMC:

UVM is used to create modular, scalable, configurable and reusable testbenches based on verification components with standardized interfaces. it's also an Environment
supporting migration from directed testing towards Coverage Driven Verification (CDV) which consists of automated stimulus generation, independent result checking and
coverage collection. But the application is responsible for coverage and randomization definition; UVM only offers the hooks and technology (classes).

### Main concepts of UVM

-   Clear separation of test stimuli (sequences) and test bench:
    - Sequences are treated as ‘transient objects’ and thus independent from the test bench construction and composition.
    - In this way, sequences can be developed and reused independently.
-   Introducing test bench abstraction levels:
    - Communication between test bench components based on transaction level modeling (TLM).
    - Register abstraction layer (RAL) using register model, adapters, and predictors.
-   Reusable verification components based on standardized interfaces and responsibilities:
    - Universal Verification Components (UVCs) offer sequencer, driver and monitor functionality with clearly defined (TLM) interfaces.
-   Non-intrusive test bench configuration and customization:
    - Hierarchy independent configuration and resource database to store and retrieve properties everywhere in the environment.
    - Factory design pattern introduced to easily replace UVM components or objects for specific tests.
    - User-defined callbacks to extend or customize UVC functionality.
-   Well defined execution and synchronization process:
    - Simulation based on phasing concept: build, connect, run, extract, check and report. UVM offers additional refined run-time phases.
    - Objection and event mechanism to manage phase transitions.
-   Independent result checking:
    - Coverage collection, signal monitoring and independent result checking in scoreboard are running autonomously.


### Why UVM in SystemC?
-   Elevate verification beyond block-level towards system-level:
    - System verification and Software-driven verification are executed by teams not familiar with SystemVerilog and its simulation environment.
    - Trend: Tests coded in C or C++. System and SW engineers use an (open source) tool-suite for embedded system design and SW dev.
-   Structured ESL verification environment:
    - The verification environment to develop Virtual Platforms and Virtual Prototypes is currently ad-hoc and not well architected.
    - Beneficial if the first system-level verification environment is UVM compliant and can be reused later by the IC verification team.
-   Extendable, fully open source, and future proof:
    - Based on Accellera’s Open Source SystemC simulator.
    - As SystemC is C++, a rich set of C++ libraries can be integrated easily.
-   Support analogue DUTs with SystemC AMS
-   Reuse tests and test benches across verification (simulation) and validation (HW-prototyping) platforms:
    - requires portable language like C++ to run tests on HW prototypes, measurement equipment, ....
    - Enables Hardware-in-the-Loop simulation and Rapid Control Prototyping.



### UVM Layered Architecture

- The top-level (e.g. sc_main) contains the test(s), the DUT and its interfaces.
- The DUT interfaces are stored in a configuration database, so it can be used by the UVCs to connect to the DUT.
- The test bench contains the UVCs, register model, adapter, scoreboard and (virtual) sequencer to execute the stimuli and check the result.
- The test to be executed is either defined by the test class instantiation or by the member function run_test.

![](Documentation/UVM_Layered_Architecture_1.png)



# UVMSYSTEMC structure with Bus implementations

This UVMSYSTEMC testing suite was created for testing various implementations of a Bus. 
These implementations should have similar communication ports with the environment same as the one used in the golden 
reference for this suite, which includes a master and 4 slaves. 
The main implementations in question is of a Wishbone bus.

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

The main idea of testing such implementations is by sending a sequence of random requests from the master 
(on the *master_in* port) and checking the series of requests forwarded towered each slave (on *slave_outx* ports). 
And from the other side sending random responses from the slaves (on *slave_inx* ports) and checking the series of
 responses forwarded towered the master (on *master_out* port).
 
 ### Structure for 1-cycle implementations

We refer here to implementations that has one to one behavior between inputs and outputs as **1-cycle** implementations.
 The meaning of one to one behavior is that the DUT reacts to input (e.g. master request) directly before asking for 
 new input.
These implementations behavior resembles the golden model behavior. For this reason, it's possible to compare the 
outputs of the DUT instantly with the outputs of the GM.

As a result, we have designed the testing suite with five *active* **UVC**s. One **UVC** *drives* master's requests and 
*monitor* it's responses while the others four do the opposite for each slave. All *driven* sequences (master's requests
 and slave's responses) need to be exported to the scoreboard in order to run the same scenario on the golden model. 
 At the same time, all *monitored* output to the environment (slave's requests and master's response) will be exported 
 to the scoreboard as well in order to compare with golden model's outputs. The designed UVMSYSTEMC test suite for such
  bus implementations can be seen in the figure below.


![](Documentation/uvm_archBUS.png)




# Test Coverage:

As mentioned earlier, UVM provide an environment for Coverage Driven Verification (CDV). But it leaves for the verification engineer the responsibilty for coverage and
randomization definition; UVM only offers the hooks and technology (classes).




