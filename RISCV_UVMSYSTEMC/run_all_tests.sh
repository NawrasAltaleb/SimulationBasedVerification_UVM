#!/bin/bash
export SYSTEMC_DISABLE_COPYRIGHT_MESSAGE=1
export UVM_SYSTEMC_DISABLE_COPYRIGHT_MESSAGE=1
export PROJECT_DIR=$HOME/Projects/SimulationBasedVerification_UVM
export EXAMPLES_DIR=$HOME/Projects/RISCV_InterruptsHandler/Examples

echo -e "\e[30;48;5;82mCreate the elf files\e[0m";
cd ${EXAMPLES_DIR}/Instruction_Tests
make
cd ${EXAMPLES_DIR}/Mini_Programs
make
cd ${EXAMPLES_DIR}/Mini_Programs/BubbleSort_c
make
cd ${EXAMPLES_DIR}/Mini_Programs/Fibonacci_c
make
cd ${EXAMPLES_DIR}/Mini_Programs/Programs/Prime_c
make
echo -e "\e[30;48;5;82mFinished creating the elf files\e[0m";

#Running Programs Tests
echo -e "\e[30;48;5;82mRunning Programs Tests\e[0m";
cd ${EXAMPLES_DIR}/Instruction_Tests
for f in $(ls *.elf)
do
    /usr/bin/time "${PROJECT_DIR}/bin/RISCV_UVMSYSTEMC_test" --use-program --i "$f" > ${PROJECT_DIR}/bin/Coverage/${f%.elf}.txt
done

cd ${EXAMPLES_DIR}/Mini_Programs
for f in $(ls *.elf)
do
    /usr/bin/time "${PROJECT_DIR}/bin/RISCV_UVMSYSTEMC_test" --use-program --i "$f" > ${PROJECT_DIR}/bin/Coverage/${f%.elf}.txt
done

cd ${EXAMPLES_DIR}/Mini_Programs/BubbleSort_c
for f in $(ls *.elf)
do
    /usr/bin/time "${PROJECT_DIR}/bin/RISCV_UVMSYSTEMC_test" --use-program --i "$f" > ${PROJECT_DIR}/bin/Coverage/${f%.elf}.txt
done

cd ${EXAMPLES_DIR}/Mini_Programs/Fibonacci_c
for f in $(ls *.elf)
do
    /usr/bin/time "${PROJECT_DIR}/bin/RISCV_UVMSYSTEMC_test" --use-program --i "$f" > ${PROJECT_DIR}/bin/Coverage/${f%.elf}.txt
done

cd ${EXAMPLES_DIR}/Mini_Programs/Prime_c
for f in $(ls *.elf)
do
    /usr/bin/time "$${PROJECT_DIR}/bin/RISCV_UVMSYSTEMC_test" --use-program --i "$f" > ${PROJECT_DIR}/bin/Coverage/${f%.elf}.txt
done


#Update Coverage report
echo -e "\e[30;48;5;82mUpdate Coverage report\e[0m";
for f in $(ls *.txt)
do
    python3.6 ${PROJECT_DIR}/RISCV_UVMSYSTEMC/analize_log_file.py -i "$f" -o ${PROJECT_DIR}/bin/Coverage/DUT_Core.xml
done



#DELETE generated elf ans asm files
echo -e "\e[30;48;5;82mDeleting generated elf and asm files\e[0m";
cd ${EXAMPLES_DIR}/Instruction_Tests
make clean
cd ${EXAMPLES_DIR}/Mini_Programs
make clean
cd ${EXAMPLES_DIR}/Mini_Programs/BubbleSort_c
make clean
cd ${EXAMPLES_DIR}/Mini_Programs/Fibonacci_c
make clean
cd ${EXAMPLES_DIR}/Mini_Programs/Prime_c
make clean


echo -e "\e[30;48;5;82mDone!\e[0m";
