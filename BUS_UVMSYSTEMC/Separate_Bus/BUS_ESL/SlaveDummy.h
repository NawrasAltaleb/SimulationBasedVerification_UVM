//
// Created by tobias on 02.07.17.
//

#ifndef PROJECT_SLAVEDUMMY_H
#define PROJECT_SLAVEDUMMY_H


#include "systemc.h"

#include "../../SingleMasterMultiSlave/ESL/Compound.h"
#include "Interfaces.h"

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


    bus_resp_t input0[6] = {
            {-736440799, OK},
            {-249562876, OK},
            {1174858848, OK},
            {240333070, OK},
            {-1750431831, OK},
            {141345978, OK}
    };

    bus_resp_t input1[4] = {
            {-997937484, OK},
            {61403724, OK},
            {-2107339224, OK},
            {503013552, OK}
    };

    bus_resp_t input2[4] = {
            {-704534310, OK},
            {1495738078, OK},
            {-1043828814, OK},
            {-1362012851, OK}
    };

    bus_resp_t input3[5] = {
            {-1395479935, OK},
            {1540121371, OK},
            {1348605056, OK},
            {-1044249059, OK},
            {671448484, OK}
    };

    int input0_c = 0;
    int input1_c = 0;
    int input2_c = 0;
    int input3_c = 0;

    void fsm() {
        while (true) {

            bus_req->read(req);
//            std::cout << this->name() << "received msg" << std::endl;
//            resp.data = req.data;
//            resp.ack = OK;
//            bus_resp->write(resp);
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
//            std::cout << this->name() << " send msg " << resp.data << std::endl;

            wait(SC_ZERO_TIME);
        }
    }
};

#endif //PROJECT_SLAVEDUMMY_H
