//
// Created by tobias on 02.07.17.
//

#ifndef PROJECT_MASTERDUMMY_H
#define PROJECT_MASTERDUMMY_H
#include "systemc.h"
#include "../../SingleMasterMultiSlave/ESL/Compound.h"
#include "Interfaces.h"

struct MasterDummy : public sc_module {
public:

    //Out-port
    blocking_out <bus_req_t> bus_req;
    blocking_in <bus_resp_t> bus_resp;


    //Variables
    bus_resp_t resp;
    bus_req_t req;

    int cnt;
    //Constructor
    SC_HAS_PROCESS(MasterDummy);

    MasterDummy(sc_module_name name) :
            bus_req("bus_req"),
            bus_resp("bus_resp"){
        SC_THREAD(fsm);
    }

    bus_req_t input[20] = {
            {36, SINGLE_READ, -705135422},
            {32, SINGLE_WRITE, 1520647498},
            {5,  SINGLE_WRITE, -762535591},
            {27, SINGLE_WRITE, -1239748464},
            {21, SINGLE_WRITE, 760494375},
            {34, SINGLE_WRITE, 483504764},
            {0,  SINGLE_WRITE, -1118861164},
            {6,  SINGLE_READ, -181460345},
            {13, SINGLE_READ, 863294356},
            {29, SINGLE_READ, -927046839},
            {10, SINGLE_READ, -576279734},
            {23, SINGLE_WRITE, -1331369439},
            {13, SINGLE_WRITE, -527794744},
            {23, SINGLE_WRITE, 1343524008},
            {27, SINGLE_WRITE, -427827550},
            {24, SINGLE_WRITE, 1426654581},
            {32, SINGLE_WRITE, 388041233},
            {1,  SINGLE_WRITE, -2045895206},
            {2,  SINGLE_WRITE, -1824598568},
            {27, SINGLE_WRITE, -447021920}
    };

    void fsm() {

        for (int i = 0; i < 20; ++i) {
            bus_req->write(input[i]);
            bus_resp->read(resp);
            std::cout << "Simulated " << resp.data << " ack " << resp.ack << std::endl;

            wait(SC_ZERO_TIME);

        }

//        while (true) {
//
//            if(cnt == 10000000){
//                std::cout << "Simulated " << cnt << " bus cycles" << std::endl;
//                sc_stop();
//                cnt = 10000000;
//            }else{
//                ++cnt;
//            }
//
//            req.data = cnt;
//
//            if(req.addr == 0){
//                req.addr = 8;
//            }else if(req.addr == 8){
//                req.addr = 16;
//            }else if(req.addr == 16){
//                req.addr = 25;
//            }else if(req.addr == 25){
//                req.addr = 0;
//            }else {
//                req.addr = 0;
//            }
//
//            if(req.trans_type == SINGLE_READ) req.trans_type = SINGLE_WRITE;
//            else req.trans_type = SINGLE_READ;
//
//
//            bus_req->write(req);
//            bus_resp->read(resp);
//
//            wait(SC_ZERO_TIME);
//        }
    }
};
#endif //PROJECT_MASTERDUMMY_H
