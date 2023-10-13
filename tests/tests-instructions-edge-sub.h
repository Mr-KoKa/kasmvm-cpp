#ifndef TESTS_INSTRUCTIONS_EDGE_SUB_H
#define TESTS_INSTRUCTIONS_EDGE_SUB_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> sub_tests = {
    InstructionEdgeTest(
        "sub MIN, MIN",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN,  -9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("-2147483639|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483639,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN,  -8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("-2147483640|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483640,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN,  -1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483647|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483647,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN,   0",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN,   1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483647,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN,   8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("2147483640|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483640,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN,   9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("2147483639|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483639,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MIN, MAX",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: TRUE"); //1,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9, MIN",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("2147483639|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483639,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9,  -9",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9,  -8",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9,  -1",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9,   0",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9,   1",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("-10|ZF: FALSE, SF: TRUE, OF: FALSE"); //-10,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9,   8",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("-17|ZF: FALSE, SF: TRUE, OF: FALSE"); //-17,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9,   9",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("-18|ZF: FALSE, SF: TRUE, OF: FALSE"); //-18,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -9, MAX",
        std::vector<int32_t>({7, 1, 0, -9, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483640|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483640,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8, MIN",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("2147483640|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483640,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8,  -9",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8,  -8",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8,  -1",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("-7|ZF: FALSE, SF: TRUE, OF: FALSE"); //-7,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8,   0",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8,   1",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8,   8",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("-16|ZF: FALSE, SF: TRUE, OF: FALSE"); //-16,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8,   9",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("-17|ZF: FALSE, SF: TRUE, OF: FALSE"); //-17,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -8, MAX",
        std::vector<int32_t>({7, 1, 0, -8, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483641|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483641,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1, MIN",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1,  -9",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1,  -8",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("7|ZF: FALSE, SF: FALSE, OF: FALSE"); //7,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1,  -1",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1,   0",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1,   1",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1,   8",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1,   9",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("-10|ZF: FALSE, SF: TRUE, OF: FALSE"); //-10,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub  -1, MAX",
        std::vector<int32_t>({7, 1, 0, -1, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0, MIN",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0,  -9",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0,  -8",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0,  -1",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0,   0",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0,   1",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0,   8",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0,   9",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   0, MAX",
        std::vector<int32_t>({7, 1, 0, 0, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483647|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483647,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1, MIN",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483647|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483647,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1,  -9",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("10|ZF: FALSE, SF: FALSE, OF: FALSE"); //10,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1,  -8",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1,  -1",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("2|ZF: FALSE, SF: FALSE, OF: FALSE"); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1,   0",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1,   1",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1,   8",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("-7|ZF: FALSE, SF: TRUE, OF: FALSE"); //-7,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1,   9",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   1, MAX",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483646|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483646,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8, MIN",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483640|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483640,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8,  -9",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("17|ZF: FALSE, SF: FALSE, OF: FALSE"); //17,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8,  -8",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("16|ZF: FALSE, SF: FALSE, OF: FALSE"); //16,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8,  -1",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8,   0",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8,   1",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("7|ZF: FALSE, SF: FALSE, OF: FALSE"); //7,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8,   8",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8,   9",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   8, MAX",
        std::vector<int32_t>({7, 1, 0, 8, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483639|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483639,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9, MIN",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483639|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483639,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9,  -9",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("18|ZF: FALSE, SF: FALSE, OF: FALSE"); //18,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9,  -8",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("17|ZF: FALSE, SF: FALSE, OF: FALSE"); //17,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9,  -1",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("10|ZF: FALSE, SF: FALSE, OF: FALSE"); //10,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9,   0",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9,   1",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9,   8",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9,   9",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub   9, MAX",
        std::vector<int32_t>({7, 1, 0, 9, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483638|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483638,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX, MIN",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: TRUE"); //-1,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX,  -9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, -9, 0}),
        []() -> std::string {
            return std::string("-2147483640|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483640,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX,  -8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, -8, 0}),
        []() -> std::string {
            return std::string("-2147483641|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483641,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX,  -1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX,   0",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, 0, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX,   1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, 1, 0}),
        []() -> std::string {
            return std::string("2147483646|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483646,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX,   8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, 8, 0}),
        []() -> std::string {
            return std::string("2147483639|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483639,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX,   9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, 9, 0}),
        []() -> std::string {
            return std::string("2147483638|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483638,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "sub MAX, MAX",
        std::vector<int32_t>({7, 1, 0, 2147483647, 60, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
};

#endif