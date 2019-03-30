cmake_minimum_required(VERSION 2.8)
project(BUS_UVMSYSTEMC C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXX_FLAGS} -fpermissive ")
set(CMAKE_MODULE_LINKER_FLAGS "-L/usr/lib -L/usr/local/lib -rt -dl -tinfo -pthread -z")

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/../../Interfaces)
include_directories(${CMAKE_SOURCE_DIR}/example/SingleMasterMultiSlave/ESL/)
link_directories(${CMAKE_SOURCE_DIR}/lib)

FILE(GLOB BUS_UVMSYSTEMC
        vip_components/subscriber.cpp
                            *.cpp *.hpp *.h)

# add executables
add_executable(BUS_UVMSYSTEMC_test ${BUS_UVMSYSTEMC})

# link libraries
target_link_libraries(BUS_UVMSYSTEMC_test systemc)
target_link_libraries(BUS_UVMSYSTEMC_test uvm-systemc)
target_link_libraries(BUS_UVMSYSTEMC_test scv)

# add macros
target_compile_definitions(BUS_UVMSYSTEMC_test PRIVATE TEST=1)

add_subdirectory(Separate_Bus/BUS_ESL)
add_subdirectory(Separate_Bus/Wishbone_ESL)