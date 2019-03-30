//
// Created by tobias on 02.07.17.
//

#ifndef PROJECT_SLAVEDUMMY_H
#define PROJECT_SLAVEDUMMY_H


#include "systemc.h"
#include "Compound_Bus.h"
#include "../../SingleMasterMultiSlave/ESL/Compound.h"
#include "../../Interfaces/Interfaces.h"

struct SlaveDummy : public sc_module {
public:

    //Out-port
    blocking_in <bus_req_t> bus_req;
    blocking_out <bus_resp_t> bus_resp;


    //Variables
    bus_resp_t resp;
    bus_req_t req;

    int cnt;
    //Constructor
    SC_HAS_PROCESS(SlaveDummy);

    SlaveDummy(sc_module_name name) :
            bus_req("bus_req"),
            bus_resp("bus_resp"){
        SC_THREAD(fsm);
    }


    bus_resp_t input0[5] = {
            {11, OK},
            {12, OK},
            {13, OK},
            {14, OK},
            {15, OK}
    };

    bus_resp_t input1[5] = {
            {21, OK},
            {22, OK},
            {23, OK},
            {24, OK},
            {25, OK}
    };

    bus_resp_t input2[5] = {
            {31, OK},
            {32, OK},
            {33, OK},
            {34, OK},
            {35, OK}
    };

    bus_resp_t input3[5] = {
            {41, OK},
            {42, OK},
            {43, OK},
            {44, OK},
            {45, OK}
    };

    int input0_c = 0;
    int input1_c = 0;
    int input2_c = 0;
    int input3_c = 0;

    void fsm() {
        while (true) {

            bus_req->read(req);
            std::string name = this->name();

            if(name == "slaveDummy0") {
                resp = input0[input0_c];
                bus_resp->write(resp);
                input0_c++;
            }
            else if(name == "slaveDummy1") {
                resp = input1[input1_c];
                bus_resp->write(resp);
                input1_c++;
            }
            else if(name == "slaveDummy2") {
                resp = input2[input2_c];
                bus_resp->write(resp);
                input2_c++;
            }
            else if(name == "slaveDummy3") {
                resp = input3[input3_c];
                bus_resp->write(resp);
                input3_c++;
            }
            wait(SC_ZERO_TIME);
        }
    }
};

#endif //PROJECT_SLAVEDUMMY_H
