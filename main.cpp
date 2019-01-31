/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: evan
 *
 * Created on January 28, 2019, 5:19 PM
 */
#include "FrameAllocator.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

std::string bts(bool val) {
    if (val) {
        return "T";
    }
    return "F";
}

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " file_name " << std::endl;
        return 1;
    }
    std::string file_name(argv[1]);
    
    FrameAllocator* a = nullptr;
    std::vector<std::vector<uint32_t>> processes(4);
    
    std::ifstream f(file_name, std::ios::binary);
    if (!f.is_open()) {
        std::cout << "Couldn't open " << file_name << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(f, line)) {
        std::istringstream sline(line);
        
        std::string command;
        std::string processStr, countStr;
        sline >> command;
        
        std::cout << "|" << line << std::endl;
        
        if (command == "P") {
            std::cout << a->get_avaliable_list_string() << std::endl;
        } else if (command == "A" || command == "R") {
            sline >> processStr;
            unsigned long process = std::stoul(processStr, nullptr, 16);
            sline >> countStr;
            unsigned long count = std::stoul(countStr, nullptr, 16);
            bool result = false;
            if (command == "A") {
                result = a->allocate(count, processes[process]);
            } else if (command == "R") {
                result = a->release(count, processes[process]);
            }
            uint32_t remaining_frames = a->get_avaliable();
            std::cout << " " << bts(result) << " " << std::hex << remaining_frames << std::endl;
        } else {
            unsigned long page_count = std::stoul(command, nullptr, 16);
            a = new FrameAllocator(page_count);
        }
    }
    if (f.bad()) {
        std::cout << "Issues reading " << file_name << std::endl;
        return 1;
    }
    f.close();
    
    delete a;
    
    return 0;
}

