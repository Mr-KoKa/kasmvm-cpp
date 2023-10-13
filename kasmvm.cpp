/**
 * Use VS2022 developer command, cd to workdir and run "code ."
 */

#include <iostream>
#include <limits>
#include <thread>
#include <filesystem>

namespace fs = std::filesystem;
#ifdef _WIN32
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
#endif

#include "helper.h"
#include "vm.h"
#include "instructions.h"

#ifdef TESTS
#include "tests/tests-instructions.h"
#include "tests/tests-instructions-edge.h"
#endif

int main(int argc, char *argv[]){
    #ifdef _WIN32
    if(timeBeginPeriod(1) != TIMERR_NOERROR){
        std::cout << "Failed to set timer resolution." << std::endl;
    }
    #endif

    #ifdef TESTS
    do {        
        if(!InstructionsTests::Run()){
            break;
        }

        if(!InstructionsEdgeTests::Run()){
            break;
        }
    } while(false);
    #else
    std::string filename = "";
    bool protectProgram = true;
    bool protectStack = true;
    bool dumpBefore = false;
    bool dumpOnError = false;
    bool skim = true;
    bool exec = true;
    bool time = false;
    int32_t memorySize = 0;

    std::string arg;
    if(argc == 2){        
        arg = argv[1];

        if(arg == "/?" || arg == "-help" || arg == "--help"){
            std::cout << "Usage:" << std::endl;
            std::cout << "kasmvm.exe filename" << std::endl << std::endl;
            std::cout << "\t-protectprogram on/off - Protect program memory. Default on" << std::endl;
            std::cout << "\t-protectstack on/off   - Protect stack memory. Default on" << std::endl;
            std::cout << "\t-mem|-memory number    - Amount of VM memory. Default 0, which is binary size * 1.1" << std::endl;
            std::cout << "\t-noskim                - Skip program skimming that checks if all program instructions have proper" << std::endl;
            std::cout << "\t                         argument count and program ends with halt instruction before data memory" << std::endl;
            std::cout << "\t-dump                  - Dumps virtual memory before execution" << std::endl;
            std::cout << "\t-dumprterr             - Dumps virtual memory on virtual machine runtime error" << std::endl;
            std::cout << "\t-noexec                - Skips execution, if you want just to dump memory or/and skim the program" << std::endl;
            std::cout << "\t-time                  - Measure and display execution time." << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Set code page to utf8 by chcp 65001 to display unicode characters properly." << std::endl;
            std::cout << "For test U+1F60A SMILING FACE WITH SMILING EYES should be displayed here: " << UnicodeToUTF8(128522) << std::endl;


            return 0;
        }
    }

    for(int i = 1; i < argc; i++){
        arg = argv[i];
        if(arg.length() == 0){
            continue;
        }

        if(arg[0] == '-'){
            if(arg == "-protectprogram" || arg == "-protectstack"){
                if(i == argc - 1){
                    std::cout << "Missing value for \"" << arg << "\" param." << std::endl;
                    return 1;
                }

                i++;
                std::string argValue = argv[i];

                bool argBoolValue = (argValue == "1" || argValue == "true" || argValue == "on");
                if(!argBoolValue && argValue != "0" || argValue != "off" || argValue != "false"){
                    std::cout << "\"" << arg << "\" is not valid value for \"" << arg << "\". Valid are 1, true, on, 0, false and off." << std::endl;
                    return 1;
                }

                if(arg == "-protectprogram"){
                    protectProgram = argBoolValue;
                } else {
                    protectStack = argBoolValue;
                }
            } else if(arg == "-mem" || arg == "-memory"){
                if(i == argc - 1){
                    std::cout << "Missing number for memory size param." << std::endl;
                    return 1;
                }

                i++;
                arg = argv[i];

                if(!to_int(arg, &memorySize)){
                    std::cout << "\"" << arg << "\" is not valid integer value." << std::endl;
                    return 1;
                }
            } else if(arg == "-time"){
                time = true;
            } else if(arg == "-dump"){
                dumpBefore = true;
            } else if(arg == "-dumprterr"){
                dumpOnError = true;
            } else if(arg == "-noskim"){
                skim = false;
            } else {
                std::cout << "Invalid param \"" << arg << "\"." << std::endl;
            }
        } else {
            filename = arg;
        }
    }

    if(filename.length() == 0){
        std::cout << "Program file is not specified." << std::endl;
        return 1;
    }

    if(!fs::exists(filename)){
        std::cout << "Program file \"" << filename << "\" does not exists." << std::endl;
        return 1;
    }
    
    try {
        VM vm(memorySize);        
        vm.setProgramProtection(protectProgram);
        vm.setStackProtection(protectStack);

        vm.loadFromFile(filename, skim);

        if(dumpBefore){
            vm.dump();
        }

        if(!exec){
            return 0;
        }

        try {
            auto execStart = std::chrono::high_resolution_clock::now();

            vm.run();

            if(time){
                auto execEnd = std::chrono::high_resolution_clock::now();
                auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(execEnd - execStart);
                double milliseconds = static_cast<double>(duration_ns.count()) / 1000000;                
                std::cout << "Execution time: " << std::fixed << std::setprecision(3) << milliseconds << " ms" << std::endl;
            }
        } catch(const VMError &e){
            if(dumpOnError){
                vm.dump();
            }
            std::cout << std::endl << "[Runtime Error]" << std::endl << e.error << std::endl;
        }
    } catch(const VMError &e){
        if(VM::ERROR_FILE_OPEN.code == e.code){
            std::cout << "Failed to open program file \"" << filename << "\"." << std::endl;
            return 1;
        }

        std::cout << e.error << std::endl;
    }
    #endif

    return 0;
}