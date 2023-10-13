#ifndef TESTS_INSTRUCTIONS_EDGE_MOV_H
#define TESTS_INSTRUCTIONS_EDGE_MOV_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> mov_tests = {
    InstructionEdgeTest(
        "mov +",
        std::vector<int32_t>({13, 1, 0, 2147483647, 1, 1, 2147483647, 1, 2, 1, 1, 3, 1, 0}),
        []() -> std::string {
            return std::string("2147483647|2147483647|1|1"); //2147483647,2147483647,1,1
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX)) + "|" + std::to_string(vm.getReg(EDX))); //vm => [std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX)) + "|" + std::to_string(vm.getReg(EDX))]
        }
    ),
    InstructionEdgeTest(
        "mov -",
        std::vector<int32_t>({13, 1, 0, std::numeric_limits<int>::min(), 1, 1, -1, 1, 2, -1, 1, 3, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483648|-1|-1|-2147483648"); //-2147483648,-1,-1,-2147483648
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX)) + "|" + std::to_string(vm.getReg(EDX))); //vm => [std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX)) + "|" + std::to_string(vm.getReg(EDX))]
        }
    ),
    InstructionEdgeTest(
        "mov arithmetic a",
        std::vector<int32_t>({10, 1, 0, 2147483646, 1, 1, -1, 1, 2, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483646|-1|2147483647"); //2147483646,-1,2147483647
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX))); //vm => [std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX))]
        }
    ),
    InstructionEdgeTest(
        "mov arithmetic b",
        std::vector<int32_t>({10, 1, 0, std::numeric_limits<int>::min(), 1, 1, 0, 1, 2, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|0|-1"); //-2147483648,0,-1
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX))); //vm => [std::to_string(vm.getReg(EAX)) + "|" + std::to_string(vm.getReg(EBX)) + "|" + std::to_string(vm.getReg(ECX))]
        }
    ),
    InstructionEdgeTest(
        "init vm flags state",
        std::vector<int32_t>({4, 4, 0, 0, 0}),
        []() -> std::string {
            return std::string(InstructionsEdgeTests::vmInitFlagsState.toString()); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [new FlagsState(vm)]
        }
    ),
};

#endif