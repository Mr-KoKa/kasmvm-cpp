#ifndef TESTS_INSTRUCTIONS_EDGE_TEST_H
#define TESTS_INSTRUCTIONS_EDGE_TEST_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> test_tests = {
    InstructionEdgeTest(
        "test MIN, MIN",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN,  -9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN,  -8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN,  -1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN,   0",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: TRUE, SF: FALSE, OF: FALSE"); //-2147483648,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN,   1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: TRUE, SF: FALSE, OF: FALSE"); //-2147483648,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN,   8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: TRUE, SF: FALSE, OF: FALSE"); //-2147483648,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN,   9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: TRUE, SF: FALSE, OF: FALSE"); //-2147483648,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MIN, MAX",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: TRUE, SF: FALSE, OF: FALSE"); //-2147483648,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9, MIN",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9,  -9",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9,  -8",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9,  -1",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9,   0",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("-9|ZF: TRUE, SF: FALSE, OF: FALSE"); //-9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9,   1",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: FALSE, OF: FALSE"); //-9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9,   8",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("-9|ZF: TRUE, SF: FALSE, OF: FALSE"); //-9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9,   9",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: FALSE, OF: FALSE"); //-9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -9, MAX",
        std::vector<int32_t>({7, 1, 0, -9, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: FALSE, OF: FALSE"); //-9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8, MIN",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8,  -9",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8,  -8",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8,  -1",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8,   0",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("-8|ZF: TRUE, SF: FALSE, OF: FALSE"); //-8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8,   1",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("-8|ZF: TRUE, SF: FALSE, OF: FALSE"); //-8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8,   8",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: FALSE, OF: FALSE"); //-8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8,   9",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: FALSE, OF: FALSE"); //-8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -8, MAX",
        std::vector<int32_t>({7, 1, 0, -8, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: FALSE, OF: FALSE"); //-8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1, MIN",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1,  -9",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1,  -8",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1,  -1",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1,   0",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("-1|ZF: TRUE, SF: FALSE, OF: FALSE"); //-1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1,   1",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: FALSE, OF: FALSE"); //-1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1,   8",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: FALSE, OF: FALSE"); //-1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1,   9",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: FALSE, OF: FALSE"); //-1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test  -1, MAX",
        std::vector<int32_t>({7, 1, 0, -1, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: FALSE, OF: FALSE"); //-1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0, MIN",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0,  -9",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0,  -8",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0,  -1",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0,   0",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0,   1",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0,   8",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0,   9",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   0, MAX",
        std::vector<int32_t>({7, 1, 0, 0, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1, MIN",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("1|ZF: TRUE, SF: FALSE, OF: FALSE"); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1,  -9",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1,  -8",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("1|ZF: TRUE, SF: FALSE, OF: FALSE"); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1,  -1",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1,   0",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("1|ZF: TRUE, SF: FALSE, OF: FALSE"); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1,   1",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1,   8",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("1|ZF: TRUE, SF: FALSE, OF: FALSE"); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1,   9",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   1, MAX",
        std::vector<int32_t>({7, 1, 0, 1, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8, MIN",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("8|ZF: TRUE, SF: FALSE, OF: FALSE"); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8,  -9",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("8|ZF: TRUE, SF: FALSE, OF: FALSE"); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8,  -8",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8,  -1",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8,   0",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("8|ZF: TRUE, SF: FALSE, OF: FALSE"); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8,   1",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("8|ZF: TRUE, SF: FALSE, OF: FALSE"); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8,   8",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8,   9",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   8, MAX",
        std::vector<int32_t>({7, 1, 0, 8, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9, MIN",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("9|ZF: TRUE, SF: FALSE, OF: FALSE"); //9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9,  -9",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9,  -8",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9,  -1",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9,   0",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("9|ZF: TRUE, SF: FALSE, OF: FALSE"); //9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9,   1",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9,   8",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9,   9",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test   9, MAX",
        std::vector<int32_t>({7, 1, 0, 9, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX, MIN",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: TRUE, SF: FALSE, OF: FALSE"); //2147483647,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX,  -9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, -9, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX,  -8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, -8, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX,  -1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, -1, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX,   0",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, 0, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: TRUE, SF: FALSE, OF: FALSE"); //2147483647,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX,   1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, 1, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX,   8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, 8, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX,   9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, 9, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "test MAX, MAX",
        std::vector<int32_t>({7, 1, 0, 2147483647, 173, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),

};

#endif