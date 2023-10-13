#ifndef TESTS_INSTRUCTIONS_EDGE_SHL_H
#define TESTS_INSTRUCTIONS_EDGE_SHL_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> shl_tests = {
    InstructionEdgeTest(
        "shl MIN,  -1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,  -2",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN, -15",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN, -31",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: TRUE"); //0,ZF: TRUE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,   0",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //std::numeric_limits<int>::min(),ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,   1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: TRUE"); //0,ZF: TRUE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,   2",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,   8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,   9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,  15",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,  16",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,  17",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,  31",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,  32",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //std::numeric_limits<int>::min(),ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN,  33",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: TRUE"); //0,ZF: TRUE, SF: FALSE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN, MAX-1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl MIN, MAX",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  -1",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  -2",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9, -15",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("-1179648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1179648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9, -31",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("-18|ZF: FALSE, SF: TRUE, OF: FALSE"); //-18,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,   0",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("-9|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,   1",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("-18|ZF: FALSE, SF: TRUE, OF: FALSE"); //-18,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,   2",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("-36|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-36,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,   8",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("-2304|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-2304,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,   9",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("-4608|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-4608,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  15",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("-294912|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-294912,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  16",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("-589824|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-589824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  17",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("-1179648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1179648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  31",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  32",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("-9|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9,  33",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("-18|ZF: FALSE, SF: TRUE, OF: FALSE"); //-18,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9, MAX-1",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -9, MAX",
        std::vector<int32_t>({7, 1, 0, -9, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  -1",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  -2",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8, -15",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("-1048576|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1048576,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8, -31",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("-16|ZF: FALSE, SF: TRUE, OF: FALSE"); //-16,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,   0",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("-8|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,   1",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("-16|ZF: FALSE, SF: TRUE, OF: FALSE"); //-16,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,   2",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("-32|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-32,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,   8",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("-2048|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-2048,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,   9",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("-4096|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-4096,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  15",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("-262144|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-262144,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  16",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("-524288|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-524288,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  17",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("-1048576|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1048576,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  31",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  32",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("-8|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8,  33",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("-16|ZF: FALSE, SF: TRUE, OF: FALSE"); //-16,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8, MAX-1",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -8, MAX",
        std::vector<int32_t>({7, 1, 0, -8, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  -1",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  -2",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1, -15",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("-131072|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-131072,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1, -31",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,   0",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("-1|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,   1",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,   2",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("-4|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-4,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,   8",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("-256|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-256,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,   9",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("-512|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-512,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  15",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("-32768|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-32768,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  16",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("-65536|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-65536,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  17",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("-131072|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-131072,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  31",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  32",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("-1|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1,  33",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1, MAX-1",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl  -1, MAX",
        std::vector<int32_t>({7, 1, 0, -1, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  -1",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  -2",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0, -15",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0, -31",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,   0",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,   1",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,   2",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,   8",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,   9",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  15",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  16",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  17",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  31",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  32",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0,  33",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0, MAX-1",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   0, MAX",
        std::vector<int32_t>({7, 1, 0, 0, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  -1",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  -2",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1073741824,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1, -15",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("131072|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //131072,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1, -31",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("2|ZF: FALSE, SF: FALSE, OF: FALSE"); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,   0",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,   1",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("2|ZF: FALSE, SF: FALSE, OF: FALSE"); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,   2",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("4|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //4,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,   8",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("256|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //256,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,   9",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("512|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //512,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  15",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("32768|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //32768,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  16",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("65536|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //65536,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  17",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("131072|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //131072,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  31",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  32",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("1|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //1,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1,  33",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("2|ZF: FALSE, SF: FALSE, OF: FALSE"); //2,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1, MAX-1",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1073741824,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   1, MAX",
        std::vector<int32_t>({7, 1, 0, 1, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  -1",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  -2",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8, -15",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("1048576|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1048576,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8, -31",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("16|ZF: FALSE, SF: FALSE, OF: FALSE"); //16,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,   0",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("8|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,   1",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("16|ZF: FALSE, SF: FALSE, OF: FALSE"); //16,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,   2",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("32|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //32,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,   8",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("2048|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //2048,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,   9",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("4096|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //4096,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  15",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("262144|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //262144,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  16",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("524288|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //524288,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  17",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("1048576|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1048576,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  31",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  32",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("8|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //8,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8,  33",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("16|ZF: FALSE, SF: FALSE, OF: FALSE"); //16,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8, MAX-1",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   8, MAX",
        std::vector<int32_t>({7, 1, 0, 8, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  -1",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  -2",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1073741824,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9, -15",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("1179648|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1179648,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9, -31",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("18|ZF: FALSE, SF: FALSE, OF: FALSE"); //18,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,   0",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("9|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,   1",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("18|ZF: FALSE, SF: FALSE, OF: FALSE"); //18,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,   2",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("36|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //36,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,   8",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("2304|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //2304,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,   9",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("4608|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //4608,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  15",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("294912|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //294912,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  16",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("589824|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //589824,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  17",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("1179648|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1179648,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  31",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  32",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("9|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //9,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9,  33",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("18|ZF: FALSE, SF: FALSE, OF: FALSE"); //18,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9, MAX-1",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFFI.toString()); //1073741824,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl   9, MAX",
        std::vector<int32_t>({7, 1, 0, 9, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  -1",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  -2",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000, -15",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000, -31",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: TRUE"); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,   0",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,   1",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: TRUE"); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,   2",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,   8",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,   9",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  15",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  16",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  17",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  31",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  32",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000,  33",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: TRUE"); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x20000000, MAX",
        std::vector<int32_t>({7, 1, 0, 1073741824, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  -1",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  -2",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000, -15",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000, -31",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,   0",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,   1",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,   2",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,   8",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,   9",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  15",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  16",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  17",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  31",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  32",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-1073741824,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000,  33",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0x40000000, MAX",
        std::vector<int32_t>({7, 1, 0, -1073741824, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  -1",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  -2",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000, -15",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000, -31",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("-1073741824|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,   0",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("-536870912|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-536870912,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,   1",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("-1073741824|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,   2",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,   8",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,   9",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  15",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  16",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  17",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  31",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  32",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("-536870912|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //-536870912,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000,  33",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("-1073741824|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xC0000000, MAX",
        std::vector<int32_t>({7, 1, 0, -536870912, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("0|" + InstructionsEdgeTests::vmInitFlagsStateTFI.toString()); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  -1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, -1, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  -2",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, -2, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000, -15",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, -15, 0}),
        []() -> std::string {
            return std::string("-131072|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-131072,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000, -31",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, -31, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,   0",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 0, 0}),
        []() -> std::string {
            return std::string("2147483647|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //2147483647,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,   1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 1, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,   2",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 2, 0}),
        []() -> std::string {
            return std::string("-4|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-4,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,   8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 8, 0}),
        []() -> std::string {
            return std::string("-256|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-256,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,   9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 9, 0}),
        []() -> std::string {
            return std::string("-512|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-512,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  15",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 15, 0}),
        []() -> std::string {
            return std::string("-32768|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-32768,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  16",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 16, 0}),
        []() -> std::string {
            return std::string("-65536|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-65536,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  17",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 17, 0}),
        []() -> std::string {
            return std::string("-131072|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-131072,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  31",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 31, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  32",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 32, 0}),
        []() -> std::string {
            return std::string("2147483647|" + InstructionsEdgeTests::vmInitFlagsState.toString()); //2147483647,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000,  33",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 33, 0}),
        []() -> std::string {
            return std::string("-2|ZF: FALSE, SF: TRUE, OF: TRUE"); //-2,ZF: FALSE, SF: TRUE, OF: TRUE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000, MAX-1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 2147483646, 0}),
        []() -> std::string {
            return std::string("-1073741824|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //-1073741824,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
    InstructionEdgeTest(
        "shl 0xE0000000, MAX",
        std::vector<int32_t>({7, 1, 0, 2147483647, 102, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-2147483648|" + InstructionsEdgeTests::vmInitFlagsStateFTI.toString()); //std::numeric_limits<int>::min(),ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [vm.getReg(EAX), new FlagsState(vm)]
        }
    ),
};

#endif