cmake_minimum_required(VERSION 2.8)
project(BUS_UVMSYSTEMC C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXX_FLAGS} -fpermissive ")
set(CMAKE_MODULE_LINKER_FLAGS "-L/usr/lib -L/usr/local/lib -rt -dl -tinfo -pthread -z")

FILE(GLOB BUS_UVMSYSTEMC_1
        vip_components/subscriber.cpp
                            *.cpp *.hpp *.h)

# add executables
add_executable(BUS_UVMSYSTEMC_1_test ${BUS_UVMSYSTEMC_1})

# link libraries
target_link_libraries(BUS_UVMSYSTEMC_1_test systemc)
target_link_libraries(BUS_UVMSYSTEMC_1_test uvm-systemc)
target_link_libraries(BUS_UVMSYSTEMC_1_test scv)

# add macros
target_compile_definitions(BUS_UVMSYSTEMC_1_test PRIVATE TEST=1)