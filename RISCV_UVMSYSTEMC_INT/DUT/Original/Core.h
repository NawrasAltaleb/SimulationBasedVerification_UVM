//
// Created by paulius on 06.14.18.
//

#ifndef RISCV_CORE_H_
#define RISCV_CORE_H_

// Adjusts code to be appropriate for the SCAM tool
// 0 : Working ESL-Description
// 1 : Properties can be generated
#define SCAM 0


#include "systemc.h"
#include "Interfaces.h"
#include "CPU_Interfaces.h"
#include "ISA.h"
#include "regs.h"

#if SCAM == 0

class Core : public sc_module {
public:
    // Constructor
    SC_HAS_PROCESS(Core);

    // Ports (Memory Interface)
    blocking_out<CUtoME_IF> COtoME_port;
    blocking_in<MEtoCU_IF> MEtoCO_port;

    // Components
    ISA isa;
    Regs RF;

    MasterSlave<RegfileWriteType> toRegsChannel;
    MasterSlave<RegfileType> fromRegsChannel;

    Core(sc_module_name name) :
            isa("isa"),
            RF("RF"),
            toRegsChannel("toRegsChannel"),
            fromRegsChannel("fromRegsChannel"),
            COtoME_port("coreOutPort"),
            MEtoCO_port("coreInPort")
    {

        // Module port binding:
        isa.fromRegsPort(fromRegsChannel);
        RF.fromRegsPort(fromRegsChannel);
        isa.toRegsPort(toRegsChannel);
        RF.toRegsPort(toRegsChannel);

        // Memory interface forwarded to outside
        isa.toMemoryPort(COtoME_port);
        isa.fromMemoryPort(MEtoCO_port);
    }
};

#elif SCAM == 1

int sc_main(int, char **) {

    // Components
    ISA isa("isa");
    Regs RF("RF");

    // Ports (Memory Interface)
    blocking_out<CUtoME_IF> COtoME_port("coreOutPort");
    blocking_in<MEtoCU_IF> MEtoCO_port("coreInPort");


    MasterSlave<RegfileWriteType> toRegsChannel("toRegsChannel");
    MasterSlave<RegfileType> fromRegsChannel("fromRegsChannel");


    // Module port binding:
    isa.fromRegsPort(fromRegsChannel);
    RF.fromRegsPort(fromRegsChannel);
    isa.toRegsPort(toRegsChannel);
    RF.toRegsPort(toRegsChannel);

    // Memory interface forwarded to outside
    isa.toMemoryPort(COtoME_port);
    isa.fromMemoryPort(MEtoCO_port);

    sc_start();
};

#endif

#endif //RISCV_CORE_H_