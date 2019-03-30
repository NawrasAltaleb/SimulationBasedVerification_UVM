//
// Created by tobias on 02.07.17.
//

#ifndef PROJECT_MASTERDUMMY_H
#define PROJECT_MASTERDUMMY_H
#include "systemc.h"
#include "Compound_Bus.h"
#include "../../SingleMasterMultiSlave/ESL/Compound.h"
#include "../../Interfaces/Interfaces.h"

#define NUM_REQ 20

struct MasterDummy : public sc_module {
public:

    //Out-port
    blocking_out <bus_req_t> bus_req;
    blocking_in <bus_resp_t> bus_resp;


    //Variables
    bus_resp_t resp;
    bus_req_t req;

    int cnt;
    int resp_cnt = 0;
    //Constructor
    SC_HAS_PROCESS(MasterDummy);

    MasterDummy(sc_module_name name) :
            bus_req("bus_req"),
            bus_resp("bus_resp"){
        SC_THREAD(fsm_request);
        SC_THREAD(fsm_response);
    }

    bus_req_t input[NUM_REQ] = {
            {1, SINGLE_READ, 51},
            {8, SINGLE_READ, 52},
            {16, SINGLE_READ, 53},
            {24, SINGLE_READ, 54},
            {2,  SINGLE_WRITE, 21},
            {9, SINGLE_WRITE, 22},
            {17, SINGLE_WRITE, 23},
            {25, SINGLE_WRITE, 24},
            {3,  SINGLE_READ, 41},
            {10,  SINGLE_READ, 42},

            {18, SINGLE_READ, 43},
            {26, SINGLE_READ, 44},
            {4, SINGLE_WRITE, 81},
            {11, SINGLE_WRITE, 82},
            {19, SINGLE_WRITE, 83},
            {27, SINGLE_WRITE, 84},
            {5, SINGLE_READ, 91},
            {12, SINGLE_READ, 92},
            {20, SINGLE_READ, 93},
            {28, SINGLE_READ, 94}
    };

    void fsm_request() {
        while (cnt < NUM_REQ) {
            req = input[cnt];
            bus_req->write(req);
            std::cout << "Request " << req.addr << " and cnt=" << cnt << std::endl;
            cnt++;
            wait(SC_ZERO_TIME);
        }
    }

    void fsm_response() {
        while(resp_cnt < NUM_REQ) {
            bus_resp->read(resp);
            std::cout << "\t\t\t\t\t\tResponse " << resp.data << " ack " << resp.ack << std::endl;
            resp_cnt++;
            wait(SC_ZERO_TIME);
        }
        sc_stop();
    }
};
#endif //PROJECT_MASTERDUMMY_H
