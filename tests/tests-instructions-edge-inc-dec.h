#ifndef TESTS_INSTRUCTIONS_EDGE_INC_DEC_H
#define TESTS_INSTRUCTIONS_EDGE_INC_DEC_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> inc_dec_tests = {
    InstructionEdgeTest(
        "inc MIN",
        std::vector<int32_t>({6, 1, 0, std::numeric_limits<int>::min(), 96, 0, 0}),
        []() -> std::string {
            return std::string("-2147483647|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483647,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc  -9",
        std::vector<int32_t>({6, 1, 0, -9, 96, 0, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc  -8",
        std::vector<int32_t>({6, 1, 0, -8, 96, 0, 0}),
        []() -> std::string {
            return std::string("-7|ZF: FALSE, SF: TRUE, OF: FALSE"); //-7,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc  -1",
        std::vector<int32_t>({6, 1, 0, -1, 96, 0, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc   0",
        std::vector<int32_t>({6, 1, 0, 0, 96, 0, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc   1",
        std::vector<int32_t>({6, 1, 0, 1, 96, 0, 0}),
        []() -> std::string {
            return std::string("2|ZF: FALSE, SF: FALSE, OF: FALSE"); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc   8",
        std::vector<int32_t>({6, 1, 0, 8, 96, 0, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc   9",
        std::vector<int32_t>({6, 1, 0, 9, 96, 0, 0}),
        []() -> std::string {
            return std::string("10|ZF: FALSE, SF: FALSE, OF: FALSE"); //10,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "inc MAX",
        std::vector<int32_t>({6, 1, 0, 2147483647, 96, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec MIN",
        std::vector<int32_t>({6, 1, 0, std::numeric_limits<int>::min(), 93, 0, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483647,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec  -9",
        std::vector<int32_t>({6, 1, 0, -9, 93, 0, 0}),
        []() -> std::string {
            return std::string("-10|ZF: FALSE, SF: TRUE, OF: FALSE"); //-10,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec  -8",
        std::vector<int32_t>({6, 1, 0, -8, 93, 0, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec  -1",
        std::vector<int32_t>({6, 1, 0, -1, 93, 0, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec   0",
        std::vector<int32_t>({6, 1, 0, 0, 93, 0, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec   1",
        std::vector<int32_t>({6, 1, 0, 1, 93, 0, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec   8",
        std::vector<int32_t>({6, 1, 0, 8, 93, 0, 0}),
        []() -> std::string {
            return std::string("7|ZF: FALSE, SF: FALSE, OF: FALSE"); //7,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec   9",
        std::vector<int32_t>({6, 1, 0, 9, 93, 0, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "dec MAX",
        std::vector<int32_t>({6, 1, 0, 2147483647, 93, 0, 0}),
        []() -> std::string {
            return std::string("2147483646|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483646,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
};

#endif