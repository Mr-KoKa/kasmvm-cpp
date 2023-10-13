#ifndef TESTS_INSTRUCTIONS_EDGE_NEG_H
#define TESTS_INSTRUCTIONS_EDGE_NEG_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> neg_tests = {
    InstructionEdgeTest(
        "neg MIN",
        std::vector<int32_t>({6, 1, 0, std::numeric_limits<int>::min(), 99, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg  -9",
        std::vector<int32_t>({6, 1, 0, -9, 99, 0, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg  -8",
        std::vector<int32_t>({6, 1, 0, -8, 99, 0, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg  -1",
        std::vector<int32_t>({6, 1, 0, -1, 99, 0, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg   0",
        std::vector<int32_t>({6, 1, 0, 0, 99, 0, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg   1",
        std::vector<int32_t>({6, 1, 0, 1, 99, 0, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg   8",
        std::vector<int32_t>({6, 1, 0, 8, 99, 0, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg   9",
        std::vector<int32_t>({6, 1, 0, 9, 99, 0, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "neg MAX",
        std::vector<int32_t>({6, 1, 0, 2147483647, 99, 0, 0}),
        []() -> std::string {
            return std::string("-2147483647|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483647,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
};

#endif