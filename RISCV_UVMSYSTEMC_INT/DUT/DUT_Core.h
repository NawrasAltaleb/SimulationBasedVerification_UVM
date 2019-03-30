#ifndef SYSTEMC_DUT_H
#define SYSTEMC_DUT_H

#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"
#include "ISA.h"
#include "Regs.h"
using namespace std;

class DUT_Core : public sc_module {
public:
  // Constructor
  SC_HAS_PROCESS(DUT_Core);

  Regs RF;
  ISA isa;

  blocking_out<CUtoME_IF> COtoME_port;
  blocking_in<MEtoCU_IF> MEtoCO_port;
  MasterSlave<RegfileType> fromRegsChannel;
  MasterSlave<RegfileWriteType> toRegsChannel;


  DUT_Core(sc_module_name name) :
    RF("RF_name"),
    isa("isa_name"),
    COtoME_port("COtoME_port_name"),
    MEtoCO_port("MEtoCO_port_name"),
    fromRegsChannel("fromRegsChannel_name"),
    toRegsChannel("toRegsChannel_name") {
    isa.toMemoryPort(COtoME_port);
    isa.fromMemoryPort(MEtoCO_port);
    RF.fromRegsPort(fromRegsChannel);
    isa.fromRegsPort(fromRegsChannel);
    isa.toRegsPort(toRegsChannel);
    RF.toRegsPort(toRegsChannel);
  }
};
#endif //SYSTEMC_DUT_H
