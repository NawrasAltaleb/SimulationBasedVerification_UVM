//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 13.10.18.
//

#ifndef RISCV_ISA_MEMORY_H
#define RISCV_ISA_MEMORY_H

#include <stdint.h>
#include <iostream>
#include "systemc"

class Memory : public sc_module {
public:
    SC_HAS_PROCESS(Memory);
    uint8_t *mem;
    uint32_t size;

    Memory(sc_core::sc_module_name, uint32_t size) :
    mem(new uint8_t[size]()),
    size(size) {}

};

#endif //RISCV_ISA_MEMORY_H
