#ifndef SYSTEMC_DUT_H
#define SYSTEMC_DUT_H

#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"
#include "Control_unit.h"
#include "Data_path.h"
#include "Register_file.h"
using namespace std;

class DUT_Core : public sc_module {
public:
    // Constructor
    SC_HAS_PROCESS(DUT_Core);

    Control_unit CU;
    Data_path DP;
    Register_file RF;

    blocking_out<CUtoME_IF> COtoME_port;
    MasterSlave<CUtoDP_IF> CUtoDP_channel;
    MasterSlave<DPtoCU_IF> DPtoCU_channel;
    MasterSlave<DPtoRF_IF> DPtoRF_channel;
    blocking_in<MEtoCU_IF> MEtoCO_port;
    MasterSlave<RFtoDP_IF> RFtoDP_channel;


    DUT_Core(sc_module_name name) :
            CU("CU_name"),
            DP("DP_name"),
            RF("RF_name"),
            COtoME_port("COtoME_port_name"),
            CUtoDP_channel("CUtoDP_channel_name"),
            DPtoCU_channel("DPtoCU_channel_name"),
            DPtoRF_channel("DPtoRF_channel_name"),
            MEtoCO_port("MEtoCO_port_name"),
            RFtoDP_channel("RFtoDP_channel_name") {
        CU.CUtoME_port(COtoME_port);
        CU.CUtoDP_port(CUtoDP_channel);
        DP.CUtoDP_port(CUtoDP_channel);
        DP.DPtoCU_port(DPtoCU_channel);
        CU.DPtoCU_port(DPtoCU_channel);
        DP.DPtoRF_port(DPtoRF_channel);
        RF.DPtoRF_port(DPtoRF_channel);
        CU.MEtoCU_port(MEtoCO_port);
        RF.RFtoDP_port(RFtoDP_channel);
        DP.RFtoDP_port(RFtoDP_channel);
    }
};
#endif //SYSTEMC_DUT_H
