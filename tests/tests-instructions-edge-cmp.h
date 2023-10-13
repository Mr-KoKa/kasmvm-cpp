#ifndef TESTS_INSTRUCTIONS_EDGE_CMP_H
#define TESTS_INSTRUCTIONS_EDGE_CMP_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> cmp_tests = {
    InstructionEdgeTest(
        "cmp MIN, MIN",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN,  -9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN,  -8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN,  -1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN,   0",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN,   1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: TRUE"); //ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN,   8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: TRUE"); //ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN,   9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: TRUE"); //ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MIN, MAX",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: TRUE"); //ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9, MIN",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9,  -9",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9,  -8",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9,  -1",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9,   0",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9,   1",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9,   8",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9,   9",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -9, MAX",
        std::vector<int32_t>({7, 1, 0, -9, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: TRUE"); //ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8, MIN",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8,  -9",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8,  -8",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8,  -1",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8,   0",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8,   1",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8,   8",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8,   9",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -8, MAX",
        std::vector<int32_t>({7, 1, 0, -8, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: TRUE"); //ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1, MIN",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1,  -9",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1,  -8",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1,  -1",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1,   0",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1,   1",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1,   8",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1,   9",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp  -1, MAX",
        std::vector<int32_t>({7, 1, 0, -1, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0, MIN",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0,  -9",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0,  -8",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0,  -1",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0,   0",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0,   1",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0,   8",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0,   9",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   0, MAX",
        std::vector<int32_t>({7, 1, 0, 0, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1, MIN",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1,  -9",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1,  -8",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1,  -1",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1,   0",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1,   1",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1,   8",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1,   9",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   1, MAX",
        std::vector<int32_t>({7, 1, 0, 1, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8, MIN",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8,  -9",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8,  -8",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8,  -1",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8,   0",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8,   1",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8,   8",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8,   9",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   8, MAX",
        std::vector<int32_t>({7, 1, 0, 8, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9, MIN",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9,  -9",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9,  -8",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9,  -1",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9,   0",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9,   1",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9,   8",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9,   9",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp   9, MAX",
        std::vector<int32_t>({7, 1, 0, 9, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: FALSE"); //ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX, MIN",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX,  -9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, -9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX,  -8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, -8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX,  -1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, -1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: TRUE, OF: TRUE"); //ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX,   0",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, 0, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX,   1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, 1, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX,   8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, 8, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX,   9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, 9, 0}),
        []() -> std::string {
            return std::string("ZF: FALSE, SF: FALSE, OF: FALSE"); //ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "cmp MAX, MAX",
        std::vector<int32_t>({7, 1, 0, 2147483647, 25, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("ZF: TRUE, SF: FALSE, OF: FALSE"); //ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(VMFlagsState(vm).toString()); //vm => [VMFlagsState(vm).toString()]
        }
    ),
};

#endif