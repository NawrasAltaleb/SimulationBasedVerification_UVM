#ifndef SYSTEMC_DUT_H
#define SYSTEMC_DUT_H

#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"
#include "ALU.h"
#include "Cpath.h"
#include "Decoder.h"
#include "Regs.h"
using namespace std;

class DUT_Core : public sc_module {
public:
  // Constructor
  SC_HAS_PROCESS(DUT_Core);

  Regs RF;
  ALU alu;
  Cpath cpath;
  Decoder decoder;

  MasterSlave<ALUtoCtl_IF> ALUtoCtl_channel;
  blocking_out<CUtoME_IF> COtoME_port;
  MasterSlave<CtlToALU_IF> CtlToALU_channel;
  MasterSlave<CtlToRegs_IF> CtlToRegs_channel;
  blocking_in<MEtoCU_IF> MEtoCO_port;
  MasterSlave<RegsToCtl_IF> RegsToCtl_channel;
  MasterSlave<unsigned> control_to_decoder;
  MasterSlave<DecodedInstr> decoder_to_control;


  DUT_Core(sc_module_name name) :
    RF("RF_name"),
    alu("alu_name"),
    cpath("cpath_name"),
    decoder("decoder_name"),
    ALUtoCtl_channel("ALUtoCtl_channel_name"),
    COtoME_port("COtoME_port_name"),
    CtlToALU_channel("CtlToALU_channel_name"),
    CtlToRegs_channel("CtlToRegs_channel_name"),
    MEtoCO_port("MEtoCO_port_name"),
    RegsToCtl_channel("RegsToCtl_channel_name"),
    control_to_decoder("control_to_decoder_name"),
    decoder_to_control("decoder_to_control_name") {
    alu.ALUtoCtl_port(ALUtoCtl_channel);
    cpath.ALUtoCtl_port(ALUtoCtl_channel);
    cpath.CtlToMem_port(COtoME_port);
    cpath.CtlToALU_port(CtlToALU_channel);
    alu.CtlToALU_port(CtlToALU_channel);
    cpath.CtlToRegs_port(CtlToRegs_channel);
    RF.CtlToRegs_port(CtlToRegs_channel);
    cpath.MemToCtl_port(MEtoCO_port);
    RF.RegsToCtl_port(RegsToCtl_channel);
    cpath.RegsToCtl_port(RegsToCtl_channel);
    cpath.CtlToDec_port(control_to_decoder);
    decoder.CtlToDec_port(control_to_decoder);
    decoder.DecToCtl_port(decoder_to_control);
    cpath.DecToCtl_port(decoder_to_control);
  }
};
#endif //SYSTEMC_DUT_H
