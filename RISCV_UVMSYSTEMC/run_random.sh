#!/bin/bash
export SYSTEMC_DISABLE_COPYRIGHT_MESSAGE=1
export UVM_SYSTEMC_DISABLE_COPYRIGHT_MESSAGE=1
export PROJECT_DIR=$HOME/Projects/SimulationBasedVerification_UVM

#Running Random Test
echo -e "\e[30;48;5;82mRunning Random Test\e[0m";
cd ${SCAM_DIR}/bin
    /usr/bin/time "${PROJECT_DIR}/bin/RISCV_UVMSYSTEMC_test" --i test_mini > ${PROJECT_DIR}/bin/Coverage/test_random.txt

#Update Coverage report
echo -e "\e[30;48;5;82mUpdate Coverage report\e[0m";
    python3.6 ${PROJECT_DIR}/RISCV_UVMSYSTEMC/analize_log_file.py -i ${PROJECT_DIR}/bin/Coverage/test_random.txt -o ${PROJECT_DIR}/bin/Coverage/DUT_Core.xml

echo -e "\e[30;48;5;82mDone!\e[0m";
