#ifndef TESTS_INSTRUCTIONS_EDGE_NOT_H
#define TESTS_INSTRUCTIONS_EDGE_NOT_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> not_tests = {
    InstructionEdgeTest(
        "not MIN",
        std::vector<int32_t>({6, 1, 0, std::numeric_limits<int>::min(), 126, 0, 0}),
        []() -> std::string {
            return std::string("2147483647"); //2147483647
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not  -9",
        std::vector<int32_t>({6, 1, 0, -9, 126, 0, 0}),
        []() -> std::string {
            return std::string("8"); //8
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not  -8",
        std::vector<int32_t>({6, 1, 0, -8, 126, 0, 0}),
        []() -> std::string {
            return std::string("7"); //7
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not  -1",
        std::vector<int32_t>({6, 1, 0, -1, 126, 0, 0}),
        []() -> std::string {
            return std::string("0"); //0
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not   0",
        std::vector<int32_t>({6, 1, 0, 0, 126, 0, 0}),
        []() -> std::string {
            return std::string("-1"); //-1
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not   1",
        std::vector<int32_t>({6, 1, 0, 1, 126, 0, 0}),
        []() -> std::string {
            return std::string("-2"); //-2
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not   8",
        std::vector<int32_t>({6, 1, 0, 8, 126, 0, 0}),
        []() -> std::string {
            return std::string("-9"); //-9
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not   9",
        std::vector<int32_t>({6, 1, 0, 9, 126, 0, 0}),
        []() -> std::string {
            return std::string("-10"); //-10
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not 0x40000000",
        std::vector<int32_t>({6, 1, 0, 1073741824, 126, 0, 0}),
        []() -> std::string {
            return std::string("-1073741825"); //-1073741825
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not 0xC0000000",
        std::vector<int32_t>({6, 1, 0, -1073741824, 126, 0, 0}),
        []() -> std::string {
            return std::string("1073741823"); //1073741823
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not 0xE0000000",
        std::vector<int32_t>({6, 1, 0, -536870912, 126, 0, 0}),
        []() -> std::string {
            return std::string("536870911"); //536870911
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
    InstructionEdgeTest(
        "not MAX",
        std::vector<int32_t>({6, 1, 0, 2147483647, 126, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648"); //-2147483648
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX))); //vm => [std::to_string(vm.getReg(EAX))]
        }
    ),
};

#endif