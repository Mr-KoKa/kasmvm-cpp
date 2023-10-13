#ifndef TESTS_INSTRUCTIONS_EDGE_INIT_H
#define TESTS_INSTRUCTIONS_EDGE_INIT_H

#include <vector>
#include <string>
#include <functional>
#include <map>

#include "vm.h"

struct VMFlagsState {
    VMFlagsState(){};
    VMFlagsState(VM &vm): flagZero(vm.flagZero), flagSign(vm.flagSign), flagOverflow(vm.flagOverflow){};
    VMFlagsState(bool flagZero, bool flagSign, bool flagOverflow): flagZero(flagZero), flagSign(flagSign), flagOverflow(flagOverflow){};

    std::string toString(){
        return std::string(std::string("ZF: ") + (this->flagZero? "TRUE" : "FALSE") + ", SF: " + (this->flagSign? "TRUE" : "FALSE") + ", OF: " + (this->flagOverflow? "TRUE" : "FALSE"));
    }

    bool flagZero = false;
    bool flagSign = false;
    bool flagOverflow = false;
};

struct InstructionEdgeTest {
    InstructionEdgeTest(){};
    InstructionEdgeTest(std::string name, std::vector<int32_t> machineCode, std::function<std::string()> check, std::function<std::string(VM&, std::string)> result): name(name), machineCode(machineCode), check(check), result(result) {};
    std::string name;
    std::vector<int32_t> machineCode;
    std::function<std::string()> check;
    std::function<std::string(VM&, std::string)> result;
};

struct InstructionsEdgeTests {    
    static std::map<std::string, std::vector<InstructionEdgeTest>> tests;
    static VMFlagsState vmInitFlagsState;
    static VMFlagsState vmInitFlagsStateTFI;
    static VMFlagsState vmInitFlagsStateFTI;
    static VMFlagsState vmInitFlagsStateFFI;
    
    static void SwapInitialVMFlagsState(){
        std::cout << "Swapping VM initial flags state." << std::endl;
        InstructionsEdgeTests::vmInitFlagsState.flagZero = !InstructionsEdgeTests::vmInitFlagsState.flagZero;
        InstructionsEdgeTests::vmInitFlagsState.flagSign = !InstructionsEdgeTests::vmInitFlagsState.flagSign;
        InstructionsEdgeTests::vmInitFlagsState.flagOverflow = !InstructionsEdgeTests::vmInitFlagsState.flagOverflow;

        InstructionsEdgeTests::vmInitFlagsStateTFI.flagOverflow = InstructionsEdgeTests::vmInitFlagsState.flagOverflow;
        InstructionsEdgeTests::vmInitFlagsStateFTI.flagOverflow = InstructionsEdgeTests::vmInitFlagsState.flagOverflow;
        InstructionsEdgeTests::vmInitFlagsStateFFI.flagOverflow = InstructionsEdgeTests::vmInitFlagsState.flagOverflow;
    }

    static bool Run(){
        VM vmInstance(0);

        InstructionsEdgeTests::vmInitFlagsState = VMFlagsState(vmInstance);
        InstructionsEdgeTests::vmInitFlagsStateTFI = VMFlagsState(true, false, vmInstance.flagOverflow);
        InstructionsEdgeTests::vmInitFlagsStateFTI = VMFlagsState(false, true, vmInstance.flagOverflow);
        InstructionsEdgeTests::vmInitFlagsStateFFI = VMFlagsState(false, false, vmInstance.flagOverflow);

        for(int i = 0; i < 2; i++){
            for(const auto& testsGroup : InstructionsEdgeTests::tests){
                std::cout << "Group: " << testsGroup.first << "..." << std::endl;
                for(const auto& test : testsGroup.second){
                    std::cout << "  " << test.name << "...";
                    VM vm(0);
                    vm.flagZero = InstructionsEdgeTests::vmInitFlagsState.flagZero;
                    vm.flagSign = InstructionsEdgeTests::vmInitFlagsState.flagSign;
                    vm.flagOverflow = InstructionsEdgeTests::vmInitFlagsState.flagOverflow;
                    vm.loadFromMemory(test.machineCode);

                    try {
                        vm.run(0);
                        if(test.result(vm, "") != test.check()){
                            std::cout << std::endl;
                            vm.dump();
                            std::cout << "Test \"" << test.name << "\" from group \"" << testsGroup.first << "\" failed. Test result does not match expected value." << std::endl;
                            std::cout << "Result:   " << test.result(vm, "") << std::endl; 
                            std::cout << "Expected: " << test.check() << std::endl;
                            return false;
                        }
                    } catch(const VMError &e){
                        std::cout << std::endl;
                        vm.dump();
                        std::cout << "Test \"" << test.name << "\" from group \"" << testsGroup.first << "\" failed with error: \"" << e.error << "\"" << std::endl;
                        return false;
                    }
                    std::cout << " OK" << std::endl;
                }
                std::cout << "Group: " << testsGroup.first << " OK" << std::endl;
            }

            if(i == 0){
                InstructionsEdgeTests::SwapInitialVMFlagsState();
            }
        }

        return true;
    }
};

VMFlagsState InstructionsEdgeTests::vmInitFlagsState;
VMFlagsState InstructionsEdgeTests::vmInitFlagsStateTFI;
VMFlagsState InstructionsEdgeTests::vmInitFlagsStateFTI;
VMFlagsState InstructionsEdgeTests::vmInitFlagsStateFFI;

#endif