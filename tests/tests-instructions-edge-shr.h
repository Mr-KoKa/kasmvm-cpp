#ifndef TESTS_INSTRUCTIONS_EDGE_SHR_H
#define TESTS_INSTRUCTIONS_EDGE_SHR_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> shr_tests = {
    InstructionEdgeTest(
        "shr MIN,  -1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,  -2",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("2|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN, -15",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("16384|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16384,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN, -31",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("1073741824|ZF: FALSE, SF: FALSE, OF: TRUE"); //1073741824,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,   0",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-2147483648,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,   1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("1073741824|ZF: FALSE, SF: FALSE, OF: TRUE"); //1073741824,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,   2",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("536870912|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //536870912,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,   8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("8388608|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //8388608,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,   9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("4194304|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //4194304,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,  15",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("65536|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //65536,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,  16",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("32768|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32768,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,  17",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("16384|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16384,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,  31",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,  32",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-2147483648,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN,  33",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("1073741824|ZF: FALSE, SF: FALSE, OF: TRUE"); //1073741824,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN, MAX-1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("2|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr MIN, MAX",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  -1",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  -2",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9, -15",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("32767|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32767,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9, -31",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("2147483643|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483643,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,   0",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("-9|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,   1",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("2147483643|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483643,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,   2",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("1073741821|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1073741821,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,   8",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("16777215|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16777215,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,   9",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("8388607|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //8388607,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  15",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("131071|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //131071,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  16",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("65535|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //65535,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  17",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("32767|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32767,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  31",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  32",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("-9|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9,  33",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("2147483643|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483643,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9, MAX-1",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -9, MAX",
        std::vector<int32_t>({7, 1, 0, -9, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  -1",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  -2",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8, -15",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("32767|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32767,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8, -31",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("2147483644|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483644,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,   0",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("-8|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,   1",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("2147483644|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483644,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,   2",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("1073741822|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1073741822,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,   8",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("16777215|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16777215,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,   9",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("8388607|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //8388607,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  15",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("131071|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //131071,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  16",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("65535|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //65535,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  17",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("32767|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32767,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  31",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  32",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("-8|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8,  33",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("2147483644|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483644,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8, MAX-1",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -8, MAX",
        std::vector<int32_t>({7, 1, 0, -8, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  -1",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  -2",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1, -15",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("32767|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32767,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1, -31",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483647,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,   0",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("-1|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,   1",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483647,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,   2",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("1073741823|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1073741823,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,   8",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("16777215|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16777215,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,   9",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("8388607|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //8388607,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  15",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("131071|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //131071,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  16",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("65535|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //65535,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  17",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("32767|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32767,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  31",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  32",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("-1|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1,  33",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: TRUE"); //2147483647,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1, MAX-1",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr  -1, MAX",
        std::vector<int32_t>({7, 1, 0, -1, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  -1",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  -2",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0, -15",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0, -31",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,   0",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,   1",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,   2",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,   8",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,   9",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  15",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  16",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  17",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  31",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  32",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0,  33",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0, MAX-1",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   0, MAX",
        std::vector<int32_t>({7, 1, 0, 0, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  -1",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  -2",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1, -15",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1, -31",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,   0",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,   1",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,   2",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,   8",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,   9",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  15",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  16",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  17",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  31",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  32",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1,  33",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1, MAX-1",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   1, MAX",
        std::vector<int32_t>({7, 1, 0, 1, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  -1",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  -2",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8, -15",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8, -31",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("4|ZF: FALSE, SF: FALSE, OF: FALSE"); //4,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,   0",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("8|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,   1",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("4|ZF: FALSE, SF: FALSE, OF: FALSE"); //4,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,   2",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("2|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,   8",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,   9",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  15",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  16",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  17",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  31",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  32",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("8|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8,  33",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("4|ZF: FALSE, SF: FALSE, OF: FALSE"); //4,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8, MAX-1",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   8, MAX",
        std::vector<int32_t>({7, 1, 0, 8, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  -1",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  -2",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9, -15",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9, -31",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("4|ZF: FALSE, SF: FALSE, OF: FALSE"); //4,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,   0",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("9|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,   1",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("4|ZF: FALSE, SF: FALSE, OF: FALSE"); //4,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,   2",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("2|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,   8",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,   9",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  15",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  16",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  17",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  31",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  32",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("9|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9,  33",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("4|ZF: FALSE, SF: FALSE, OF: FALSE"); //4,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9, MAX-1",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr   9, MAX",
        std::vector<int32_t>({7, 1, 0, 9, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  -1",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  -2",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000, -15",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("8192|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //8192,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000, -31",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("536870912|ZF: FALSE, SF: FALSE, OF: FALSE"); //536870912,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,   0",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,   1",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("536870912|ZF: FALSE, SF: FALSE, OF: FALSE"); //536870912,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,   2",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("268435456|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //268435456,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,   8",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("4194304|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //4194304,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,   9",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("2097152|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //2097152,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  15",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("32768|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32768,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  16",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("16384|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16384,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  17",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("8192|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //8192,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  31",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  32",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000,  33",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("536870912|ZF: FALSE, SF: FALSE, OF: FALSE"); //536870912,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x20000000, MAX",
        std::vector<int32_t>({7, 1, 0, 1073741824, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  -1",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  -2",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000, -15",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("24576|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //24576,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000, -31",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("1610612736|ZF: FALSE, SF: FALSE, OF: TRUE"); //1610612736,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,   0",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,   1",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("1610612736|ZF: FALSE, SF: FALSE, OF: TRUE"); //1610612736,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,   2",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("805306368|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //805306368,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,   8",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("12582912|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //12582912,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,   9",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("6291456|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //6291456,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  15",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("98304|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //98304,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  16",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("49152|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //49152,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  17",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("24576|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //24576,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  31",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  32",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000,  33",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("1610612736|ZF: FALSE, SF: FALSE, OF: TRUE"); //1610612736,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0x40000000, MAX",
        std::vector<int32_t>({7, 1, 0, -1073741824, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  -1",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  -2",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000, -15",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("28672|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //28672,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000, -31",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("1879048192|ZF: FALSE, SF: FALSE, OF: TRUE"); //1879048192,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,   0",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("-536870912|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-536870912,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,   1",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("1879048192|ZF: FALSE, SF: FALSE, OF: TRUE"); //1879048192,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,   2",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("939524096|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //939524096,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,   8",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("14680064|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //14680064,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,   9",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("7340032|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //7340032,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  15",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("114688|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //114688,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  16",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("57344|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //57344,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  17",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("28672|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //28672,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  31",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  32",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("-536870912|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //-536870912,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000,  33",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("1879048192|ZF: FALSE, SF: FALSE, OF: TRUE"); //1879048192,ZF: FALSE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("3|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //3,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xC0000000, MAX",
        std::vector<int32_t>({7, 1, 0, -536870912, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  -1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  -2",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, -2, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000, -15",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, -15, 0}),
        []() -> std::string {
            return std::string("16383|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16383,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000, -31",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, -31, 0}),
        []() -> std::string {
            return std::string("1073741823|ZF: FALSE, SF: FALSE, OF: FALSE"); //1073741823,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,   0",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 0, 0}),
        []() -> std::string {
            return std::string("2147483647|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //2147483647,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,   1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 1, 0}),
        []() -> std::string {
            return std::string("1073741823|ZF: FALSE, SF: FALSE, OF: FALSE"); //1073741823,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,   2",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 2, 0}),
        []() -> std::string {
            return std::string("536870911|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //536870911,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,   8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 8, 0}),
        []() -> std::string {
            return std::string("8388607|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //8388607,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,   9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 9, 0}),
        []() -> std::string {
            return std::string("4194303|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //4194303,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  15",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 15, 0}),
        []() -> std::string {
            return std::string("65535|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //65535,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  16",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 16, 0}),
        []() -> std::string {
            return std::string("32767|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //32767,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  17",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 17, 0}),
        []() -> std::string {
            return std::string("16383|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //16383,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  31",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  32",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 32, 0}),
        []() -> std::string {
            return std::string("2147483647|" + InstructionsEdgeTests::vmInitFlagsState.toString() + ""); //2147483647,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000,  33",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 33, 0}),
        []() -> std::string {
            return std::string("1073741823|ZF: FALSE, SF: FALSE, OF: FALSE"); //1073741823,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateFFI.toString() + ""); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "shr 0xE0000000, MAX",
        std::vector<int32_t>({7, 1, 0, 2147483647, 114, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::InstructionsEdgeTests::vmInitFlagsStateTFI.toString() + ""); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
};

#endif