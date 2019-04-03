cmake_minimum_required(VERSION 3.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

set (SYSTEMC_PATH /usr/local/systemc)
include_directories(${SYSTEMC_PATH}/include)
find_library(systemc systemc ${SYSTEMC_PATH}/lib-linux64)
link_directories(${SYSTEMC_PATH}/lib-linux64)

set (SCV_PATH /usr/local/scv)
include_directories(${SCV_PATH}/include)
find_library(scv scv ${SCV_PATH}/lib-linux64)
link_directories(${SCV_PATH}/lib-linux64)

set (UVM_PATH /usr/local/uvm-systemc)
include_directories(${UVM_PATH}/include)
find_library(scv scv ${UVM_PATH}/lib-linux64)
link_directories(${UVM_PATH}/lib-linux64)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(BUS_UVMSYSTEMC_1)
add_subdirectory(BUS_UVMSYSTEMC_2)
add_subdirectory(BUS_UVMSYSTEMC_3)
#add_subdirectory(RISCV_UVMSYSTEMC)
add_subdirectory(RISCV_UVMSYSTEMC)
