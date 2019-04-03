//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 10/24/18.
//

#ifndef UVMSYSTEMC_VIP_IF_H
#define UVMSYSTEMC_VIP_IF_H

#include "Interfaces.h"
#include "Compound.h"


class vip_if_MasterToBus
{
public:
    Blocking<bus_req_t> MasterToBus;
    vip_if_MasterToBus() : MasterToBus("MasterToBus") {}
};

class vip_if_BusToMaster
{
public:
    Blocking<bus_resp_t> BusToMaster;
    vip_if_BusToMaster() : BusToMaster("BusToMaster") {}
};


class vip_if_BUS_REQ
{
public:
    Blocking<bus_req_t> BUS_REQ;
    vip_if_BUS_REQ() : BUS_REQ("BUS_REQ") {}
};

class vip_if_BUS_RSP
{
public:
    Blocking<bus_resp_t> BUS_RSP;
    vip_if_BUS_RSP() : BUS_RSP("BUS_RSP") {}
};


#endif //UVMSYSTEMC_VIP_IF_H
