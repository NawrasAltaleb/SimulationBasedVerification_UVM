//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#ifndef UVMSYSTEMC_DATA_EXT_H
#define UVMSYSTEMC_DATA_EXT_H

#include "scv.h"
#include "Compound.h"

template<>
class scv_extensions<trans_t> : public scv_enum_base<trans_t> {
public:
    SCV_ENUM_CTOR(trans_t) {
        SCV_ENUM(SINGLE_READ);
        SCV_ENUM(SINGLE_WRITE);
    }
};

template<>
class scv_extensions<ack_t> : public scv_enum_base<ack_t> {
public:
    SCV_ENUM_CTOR(ack_t) {
        SCV_ENUM(OK);
        SCV_ENUM(RTY);
        SCV_ENUM(ERR);
    }
};

template<>
class scv_extensions<bus_req_t> : public scv_extensions_base<bus_req_t> {
public:
    scv_extensions<int> addr;
    scv_extensions<trans_t> trans_type;
    scv_extensions<int> data;

    SCV_EXTENSIONS_CTOR(bus_req_t) {
            //must be in order
            SCV_FIELD(addr);
            SCV_FIELD(trans_type);
            SCV_FIELD(data);
    }
};


template<>
class scv_extensions<bus_resp_t> : public scv_extensions_base<bus_resp_t> {
public:
    scv_extensions<int> data;
    scv_extensions<ack_t> ack;

    SCV_EXTENSIONS_CTOR(bus_resp_t) {
            //must be in order
            SCV_FIELD(data);
            SCV_FIELD(ack);
    }
};
#endif //UVMSYSTEMC_DATA_EXT_H
