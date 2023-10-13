#ifndef TESTS_INSTRUCTIONS_EDGE_OR_H
#define TESTS_INSTRUCTIONS_EDGE_OR_H

#include "tests-constants.h"
#include "tests-instructions-edge--init.h"

std::vector<InstructionEdgeTest> or_tests = {
    InstructionEdgeTest(
        "or MIN, MIN",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN,  -9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN,  -8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN,  -1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN,   0",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN,   1",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("-2147483647|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483647,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN,   8",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("-2147483640|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483640,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN,   9",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("-2147483639|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483639,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MIN, MAX",
        std::vector<int32_t>({7, 1, 0, std::numeric_limits<int>::min(), 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9, MIN",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9,  -9",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9,  -8",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9,  -1",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9,   0",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9,   1",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9,   8",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9,   9",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -9, MAX",
        std::vector<int32_t>({7, 1, 0, -9, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8, MIN",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8,  -9",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8,  -8",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8,  -1",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8,   0",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8,   1",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("-7|ZF: FALSE, SF: TRUE, OF: FALSE"); //-7,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8,   8",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8,   9",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("-7|ZF: FALSE, SF: TRUE, OF: FALSE"); //-7,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -8, MAX",
        std::vector<int32_t>({7, 1, 0, -8, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1, MIN",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1,  -9",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1,  -8",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1,  -1",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1,   0",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1,   1",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1,   8",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1,   9",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or  -1, MAX",
        std::vector<int32_t>({7, 1, 0, -1, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0, MIN",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483648|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483648,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0,  -9",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0,  -8",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0,  -1",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0,   0",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("0|ZF: TRUE, SF: FALSE, OF: FALSE"); //0,ZF: TRUE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0,   1",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0,   8",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0,   9",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   0, MAX",
        std::vector<int32_t>({7, 1, 0, 0, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1, MIN",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483647|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483647,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1,  -9",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-9|ZF: FALSE, SF: TRUE, OF: FALSE"); //-9,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1,  -8",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-7|ZF: FALSE, SF: TRUE, OF: FALSE"); //-7,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1,  -1",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1,   0",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1,   1",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("1|ZF: FALSE, SF: FALSE, OF: FALSE"); //1,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1,   8",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1,   9",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   1, MAX",
        std::vector<int32_t>({7, 1, 0, 1, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8, MIN",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483640|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483640,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8,  -9",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8,  -8",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-8|ZF: FALSE, SF: TRUE, OF: FALSE"); //-8,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8,  -1",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8,   0",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8,   1",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8,   8",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("8|ZF: FALSE, SF: FALSE, OF: FALSE"); //8,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8,   9",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   8, MAX",
        std::vector<int32_t>({7, 1, 0, 8, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9, MIN",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-2147483639|ZF: FALSE, SF: TRUE, OF: FALSE"); //-2147483639,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9,  -9",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9,  -8",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-7|ZF: FALSE, SF: TRUE, OF: FALSE"); //-7,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9,  -1",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9,   0",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9,   1",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9,   8",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9,   9",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("9|ZF: FALSE, SF: FALSE, OF: FALSE"); //9,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or   9, MAX",
        std::vector<int32_t>({7, 1, 0, 9, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX, MIN",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, std::numeric_limits<int>::min(), 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX,  -9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, -9, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX,  -8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, -8, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX,  -1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, -1, 0}),
        []() -> std::string {
            return std::string("-1|ZF: FALSE, SF: TRUE, OF: FALSE"); //-1,ZF: FALSE, SF: TRUE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX,   0",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, 0, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX,   1",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, 1, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX,   8",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, 8, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX,   9",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, 9, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),
    InstructionEdgeTest(
        "or MAX, MAX",
        std::vector<int32_t>({7, 1, 0, 2147483647, 141, 0, 2147483647, 0}),
        []() -> std::string {
            return std::string("2147483647|ZF: FALSE, SF: FALSE, OF: FALSE"); //2147483647,ZF: FALSE, SF: FALSE, OF: FALSE
        },
        [](VM &vm, std::string _stdout) -> std::string {
            return std::string(std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()); //vm => [std::to_string(vm.getReg(EAX)) + "|" + VMFlagsState(vm).toString()]
        }
    ),

};

#endif