//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 13.10.18.
//

#ifndef PROJECT_OPTIONS_H
#define PROJECT_OPTIONS_H

#include <iostream>
#include <iostream>
#include <boost/program_options.hpp>

struct Options {
    typedef unsigned int addr_t;

    Options &check_and_post_process() {
        mem_end_addr = mem_start_addr + mem_size;
        return *this;
    }

    std::string input_program;

    addr_t mem_size           = 1024*1024*32;  // 32 MB ram, to place it before the CLINT and run the base examples (assume memory start at zero) without modifications
    addr_t mem_start_addr     = 0x00000000;
    addr_t mem_end_addr       = mem_start_addr + mem_size;
//    addr_t clint_start_addr   = 0x02000000;
//    addr_t clint_end_addr     = 0x0200ffff;
//    addr_t term_start_addr    = 0x20000000;
//    addr_t term_end_addr      = term_start_addr + 16;
//    addr_t plic_start_addr    = 0x40000000;
//    addr_t plic_end_addr      = 0x40001000;
//    addr_t sensor_start_addr  = 0x50000000;
//    addr_t sensor_end_addr    = 0x50001000;
//    addr_t sensor2_start_addr = 0x50002000;
//    addr_t sensor2_end_addr   = 0x50004000;
//    addr_t dma_start_addr     = 0x70000000;
//    addr_t dma_end_addr       = 0x70001000;

    bool use_program = false;

    void show() {
        std::cout << "options {" << std::endl;
        std::cout << "  use program = " << use_program << std::endl;
        std::cout << "}" << std::endl;
    }
};


Options parse_command_line_arguments(int argc, char **argv) {
    // Note: first check for *help* argument then run *notify*, see: https://stackoverflow.com/questions/5395503/required-and-optional-arguments-using-boost-library-program-options
    try {
        Options opt;

        namespace po = boost::program_options;

        po::options_description desc("Options");

        desc.add_options()
                ("help", "produce help message")
                ("use-program", po::bool_switch(&opt.use_program), "use a test program to run on DUT")
                ("i", po::value<std::string>(&opt.input_program), "input file to use for execution")
                ;

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            exit(0);
        }

        po::notify(vm);

        if (vm["use-program"].as<bool>()) {
            opt.use_program = true;
        }

        return opt.check_and_post_process();
    } catch (boost::program_options::error &e) {
        std::cerr << "Error parsing command line options: " << e.what() << std::endl;
        exit(-1);
    }
}


#endif //PROJECT_OPTIONS_H
