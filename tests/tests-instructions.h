#include <functional>
#include <sstream>

#include "tests-constants.h"
#include "helper.h"
#include "vm.h"

struct InstructionTest {
    InstructionTest(std::string name, std::vector<int32_t> machineCode, std::function<bool(VM&, std::string)> check, int32_t steps = 0, const VMError *vmError = nullptr): name(name), machineCode(machineCode), check(check), steps(steps), vmError(vmError) {};
    std::string name;
    std::vector<int32_t> machineCode;
    std::function<bool(VM&, std::string)> check;
    const VMError *vmError = nullptr;
    int32_t steps = steps;
};

struct InstructionsTests {
    static const int32_t TEST_COUNT = 376;   
    static InstructionTest tests[TEST_COUNT];

    static bool Run(){
        std::cout << "Start: InstructionsTests" << std::endl;

        std::streambuf *cout = std::cout.rdbuf();
        std::streambuf *cin = std::cin.rdbuf();
        
        std::istringstream str("QA\n");
        std::cin.rdbuf(str.rdbuf());

        for(InstructionTest *test = InstructionsTests::tests; test != InstructionsTests::tests + InstructionsTests::TEST_COUNT; ++test){
            std::cout << test->name << "..." << std::endl;                
            VM vm(0);
            try {
                str.seekg(0);
                vm.loadFromMemory(test->machineCode);                              
                              
                std::stringstream buffer;
                std::cout.rdbuf(buffer.rdbuf());
                vm.run(test->steps);
                std::cout.rdbuf(cout);
                
                if(!test->check(vm, buffer.str())){
                    vm.dump();
                    std::cout << "vm.getStackLength(): " << vm.getStackLength() << std::endl;
                    std::cout << "vm.getStack()[-1]: " << vm.getStack()[-1] << std::endl;
                    throw VMError("Check failed.");
                }
            } catch(const VMError &e){
                std::cout.rdbuf(cout);
                if(test->vmError){
                    if(test->vmError->code == e.code){
                        continue;
                    }

                    std::cout << "Test \"" << test->name << "\" failed with error: \"" << e.error << "\" but was expected to fail with error: \"" << test->vmError->error << "\"." << std::endl;
                    return false;
                }

                std::cout << "Test \"" << test->name << "\" failed with error: \"" << e.error << "\"" << std::endl;
                return false;
            }
        }

        std::cout << "End: InstructionsTests" << std::endl;

        return true;
    }
};

InstructionTest InstructionsTests::tests[InstructionsTests::TEST_COUNT] = {
    InstructionTest(
        "$ test",
        std::vector<int32_t>({30, 1, 0, 2, 233, 4, 237, 1, 1, 8, 197, 44, 235, 30, 197, 44, 235, 31, 197, 44, 235, 32, 197, 44, 235, 33, 197, 44, 235, 34, 0, 0, 3, 5, 6, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2 && vm.getReg(EBX) == 8 && _stdout == "4,0,3,5,6,6";
        }
    ),
    InstructionTest(
        "$$ test",
        std::vector<int32_t>({25, 235, 25, 197, 44, 235, 26, 197, 44, 235, 27, 197, 44, 235, 28, 197, 44, 235, 29, 197, 44, 235, 30, 197, 44, 0, 0, 1, 2, 3, 4, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "0,1,2,3,4,5,";
        }
    ),
    InstructionTest(
        "$$ test rb",
        std::vector<int32_t>({29, 235, 29, 197, 44, 235, 30, 197, 44, 235, 31, 197, 44, 235, 32, 197, 44, 235, 33, 197, 44, 235, 34, 197, 44, 235, 35, 197, 44, 0, 0, 1, 0, 0, 0, 5, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "0,1,0,0,0,5,6,";
        }
    ),
    InstructionTest(
        "$$ test rb with 2nd argument",
        std::vector<int32_t>({29, 235, 29, 197, 44, 235, 30, 197, 44, 235, 31, 197, 44, 235, 32, 197, 44, 235, 33, 197, 44, 235, 34, 197, 44, 235, 35, 197, 44, 0, 0, 1, 255, 255, 255, 5, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "0,1,255,255,255,5,6,";
        }
    ),
    InstructionTest(
        "mov_reg_int",
        std::vector<int32_t>({4, 1, 0, std::numeric_limits<int>::min(), 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_reg_ptr",
        std::vector<int32_t>({4, 2, 0, 4, 0, std::numeric_limits<int>::min()}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_reg_regptr",
        std::vector<int32_t>({7, 1, 1, 7, 3, 0, 1, 0, std::numeric_limits<int>::min()}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_reg_reg",
        std::vector<int32_t>({7, 1, 1, std::numeric_limits<int>::min(), 4, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_ptr_int",
        std::vector<int32_t>({7, 5, 7, std::numeric_limits<int>::min(), 2, 0, 7, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_ptr_ptr",
        std::vector<int32_t>({7, 6, 7, 8, 2, 0, 7, 0, 0, std::numeric_limits<int>::min()}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 11, 7, 10, 1, 2, 0, 10, 0, 0, std::numeric_limits<int>::min()}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_ptr_reg",
        std::vector<int32_t>({10, 1, 1, std::numeric_limits<int>::min(), 8, 10, 1, 2, 0, 10, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_regptr_int",
        std::vector<int32_t>({10, 1, 1, 10, 9, 1, std::numeric_limits<int>::min(), 2, 0, 10, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_regptr_ptr",
        std::vector<int32_t>({10, 1, 1, 10, 10, 1, 11, 2, 0, 10, 0, 0, std::numeric_limits<int>::min()}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_regptr_regptr",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, 14, 11, 1, 2, 2, 0, 13, 0, 0, std::numeric_limits<int>::min()}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "mov_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, std::numeric_limits<int>::min(), 12, 1, 2, 2, 0, 13, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == COMPILER_MIN_INT;
        }
    ),
    InstructionTest(
        "jmp_reg",
        std::vector<int32_t>({12, 1, 0, 1, 1, 0, 1, 1, 1, 3, 13, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 4
    ),
    InstructionTest(
        "jmp_ptr",
        std::vector<int32_t>({9, 1, 0, 1, 1, 0, 1, 14, 9, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 3
    ),
    InstructionTest(
        "jmp_regptr",
        std::vector<int32_t>({9, 1, 0, 9, 1, 1, 1, 15, 0, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 3
    ),
    InstructionTest(
        "jmp_int",
        std::vector<int32_t>({9, 1, 0, 1, 1, 1, 1, 16, 3, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 3
    ),
    InstructionTest(
        "cmp_int_int -",
        std::vector<int32_t>({7, 17, 1, 5, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_int_int +",
        std::vector<int32_t>({7, 17, 5, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_int_int 0",
        std::vector<int32_t>({7, 17, 5, 5, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_int_ptr -",
        std::vector<int32_t>({7, 18, 1, 7, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_int_ptr +",
        std::vector<int32_t>({7, 18, 5, 7, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_int_ptr 0",
        std::vector<int32_t>({7, 18, 5, 7, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_int_reg -",
        std::vector<int32_t>({10, 1, 0, 5, 19, 1, 0, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_int_reg +",
        std::vector<int32_t>({10, 1, 0, 1, 19, 5, 0, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_int_reg 0",
        std::vector<int32_t>({10, 1, 0, 5, 19, 5, 0, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_int_regptr -",
        std::vector<int32_t>({10, 1, 0, 10, 20, 1, 0, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_int_regptr +",
        std::vector<int32_t>({10, 1, 0, 10, 20, 5, 0, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_int_regptr 0",
        std::vector<int32_t>({10, 1, 0, 10, 20, 5, 0, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_ptr_ptr -",
        std::vector<int32_t>({7, 22, 7, 8, 1, 3, 123, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_ptr_ptr +",
        std::vector<int32_t>({7, 22, 7, 8, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_ptr_ptr 0",
        std::vector<int32_t>({7, 22, 7, 8, 1, 3, 123, 0, 5, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_ptr_int -",
        std::vector<int32_t>({7, 21, 7, 5, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_ptr_int +",
        std::vector<int32_t>({7, 21, 7, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_ptr_int 0",
        std::vector<int32_t>({7, 21, 7, 5, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "cmp_ptr_reg -",
        std::vector<int32_t>({10, 1, 0, 5, 23, 10, 0, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_ptr_reg +",
        std::vector<int32_t>({10, 1, 0, 1, 23, 10, 0, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_ptr_reg 0",
        std::vector<int32_t>({10, 1, 0, 5, 23, 10, 0, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_ptr_ptrreg -",
        std::vector<int32_t>({10, 1, 0, 11, 24, 10, 0, 1, 3, 123, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_ptr_ptrreg +",
        std::vector<int32_t>({10, 1, 0, 11, 24, 10, 0, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_ptr_ptrreg 0",
        std::vector<int32_t>({10, 1, 0, 11, 24, 10, 0, 1, 3, 123, 0, 5, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_reg_int -",
        std::vector<int32_t>({10, 1, 0, 1, 25, 0, 5, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_reg_int +",
        std::vector<int32_t>({10, 1, 0, 5, 25, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_reg_int 0",
        std::vector<int32_t>({10, 1, 0, 5, 25, 0, 5, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_reg_ptr -",
        std::vector<int32_t>({10, 1, 0, 1, 26, 0, 10, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_reg_ptr +",
        std::vector<int32_t>({10, 1, 0, 5, 26, 0, 10, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_reg_ptr 0",
        std::vector<int32_t>({10, 1, 0, 5, 26, 0, 10, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_reg_reg -",
        std::vector<int32_t>({13, 1, 0, 1, 1, 1, 5, 27, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_reg_reg +",
        std::vector<int32_t>({13, 1, 0, 5, 1, 1, 1, 27, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_reg_reg 0",
        std::vector<int32_t>({13, 1, 0, 5, 1, 1, 5, 27, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_reg_regptr -",
        std::vector<int32_t>({13, 1, 0, 1, 1, 1, 13, 28, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_reg_regptr +",
        std::vector<int32_t>({13, 1, 0, 5, 1, 1, 13, 28, 0, 1, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_reg_regptr 0",
        std::vector<int32_t>({13, 1, 0, 5, 1, 1, 13, 28, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_regptr_int -",
        std::vector<int32_t>({10, 1, 0, 10, 29, 0, 5, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_regptr_int +",
        std::vector<int32_t>({10, 1, 0, 10, 29, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_regptr_int 0",
        std::vector<int32_t>({10, 1, 0, 10, 29, 0, 5, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_regptr_ptr -",
        std::vector<int32_t>({10, 1, 0, 10, 30, 0, 11, 1, 3, 123, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_regptr_ptr +",
        std::vector<int32_t>({10, 1, 0, 10, 30, 0, 11, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_regptr_ptr 0",
        std::vector<int32_t>({10, 1, 0, 10, 30, 0, 11, 1, 3, 123, 0, 5, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "cmp_regptr_reg -",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 5, 31, 0, 1, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_regptr_reg +",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 1, 31, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_regptr_reg 0",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 5, 31, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_regptr_regptr -",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 14, 32, 0, 1, 1, 3, 123, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_regptr_regptr +",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 14, 32, 0, 1, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "cmp_regptr_regptr 0",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 14, 32, 0, 1, 1, 3, 123, 0, 5, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "jz_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 33, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jz_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 33, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jz_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 33, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jnz_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 34, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jnz_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 34, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jnz_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 34, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "js_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 35, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "js_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 35, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "js_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 35, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jns_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 36, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jns_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 36, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jns_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 36, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jo_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 37, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jo_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 37, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jo_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 37, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jo_int overflow + -> -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2147483647, -2147483647, 37, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jo_int overflow - -> +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, -2147479553, 2147479552, 37, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jno_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 38, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jno_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 38, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jno_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 38, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jno_int overflow + -> -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2147483647, -2147483647, 38, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jno_int overflow - -> +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, -2147479553, 2147479552, 38, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "je_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 39, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "je_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 39, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "je_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 39, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jne_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 40, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jne_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 40, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jne_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 40, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jg_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 41, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jg_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 41, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jg_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 41, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jge_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 42, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jge_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 42, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jge_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 42, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jl_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 43, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jl_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 43, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jl_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 43, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "jle_int 0",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 1, 44, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jle_int -",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 1, 2, 44, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 3;
        }, 5
    ),
    InstructionTest(
        "jle_int +",
        std::vector<int32_t>({18, 1, 0, 1, 1, 0, 1, 1, 0, 1, 17, 2, 1, 44, 3, 1, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getControl() == 14;
        }, 5
    ),
    InstructionTest(
        "add_reg_reg",
        std::vector<int32_t>({10, 1, 0, 1, 1, 1, 5, 45, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 1, 46, 0, 7, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 1, 1, 1, 10, 47, 0, 1, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_reg_int",
        std::vector<int32_t>({7, 1, 0, 1, 48, 0, 5, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_ptr_reg",
        std::vector<int32_t>({10, 1, 1, 5, 49, 10, 1, 2, 0, 10, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_ptr_ptr",
        std::vector<int32_t>({7, 50, 7, 8, 2, 0, 7, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 11, 51, 10, 1, 2, 0, 10, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_ptr_int",
        std::vector<int32_t>({7, 52, 7, 5, 2, 0, 7, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, 5, 53, 1, 2, 2, 0, 13, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_regptr_ptr",
        std::vector<int32_t>({10, 1, 1, 10, 54, 1, 11, 2, 0, 10, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_regptr_regptr",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, 14, 55, 1, 2, 2, 0, 13, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "add_regptr_int",
        std::vector<int32_t>({10, 1, 1, 10, 56, 1, 5, 2, 0, 10, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "sub_reg_reg",
        std::vector<int32_t>({10, 1, 0, 1, 1, 1, 5, 57, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 1, 58, 0, 7, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 1, 1, 1, 10, 59, 0, 1, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_reg_int",
        std::vector<int32_t>({7, 1, 0, 1, 60, 0, 5, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_ptr_reg",
        std::vector<int32_t>({10, 1, 1, 5, 61, 10, 1, 2, 0, 10, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_ptr_ptr",
        std::vector<int32_t>({7, 62, 7, 8, 2, 0, 7, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 11, 63, 10, 1, 2, 0, 10, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_ptr_int",
        std::vector<int32_t>({7, 64, 7, 5, 2, 0, 7, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, 5, 65, 1, 2, 2, 0, 13, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_regptr_ptr",
        std::vector<int32_t>({10, 1, 1, 10, 66, 1, 11, 2, 0, 10, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_regptr_regptr",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, 14, 67, 1, 2, 2, 0, 13, 0, 1, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "sub_regptr_int",
        std::vector<int32_t>({10, 1, 1, 10, 68, 1, 5, 2, 0, 10, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "push_reg",
        std::vector<int32_t>({6, 1, 0, 15, 69, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getStack()[-1] == 15;
        }
    ),
    InstructionTest(
        "push_ptr",
        std::vector<int32_t>({3, 70, 3, 0, 15}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getStack()[-1] == 15;
        }
    ),
    InstructionTest(
        "push_regptr",
        std::vector<int32_t>({6, 1, 0, 6, 71, 0, 0, 15}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getStack()[-1] == 15;
        }
    ),
    InstructionTest(
        "push_int",
        std::vector<int32_t>({3, 72, 15, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getStack()[-1] == 15;
        }
    ),
    InstructionTest(
        "pop_reg",
        std::vector<int32_t>({5, 72, 15, 73, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 0 && vm.getReg(EAX) == 15;
        }
    ),
    InstructionTest(
        "pop_ptr",
        std::vector<int32_t>({8, 72, 15, 74, 8, 2, 0, 8, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 0 && vm.getReg(EAX) == 15;
        }
    ),
    InstructionTest(
        "pop_regptr",
        std::vector<int32_t>({11, 72, 15, 1, 1, 11, 75, 1, 2, 0, 11, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 0 && vm.getReg(EAX) == 15;
        }
    ),
    InstructionTest(
        "call_int",
        std::vector<int32_t>({15, 16, 6, 1, 0, 0, 80, 1, 0, 2, 1, 1, 14, 76, 2, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getReg(EAX) == vm.getControl() && vm.getReg(EBX) == vm.getStack()[-1];
        }, 4
    ),
    InstructionTest(
        "call_reg",
        std::vector<int32_t>({15, 16, 6, 1, 0, 0, 80, 1, 0, 2, 1, 1, 14, 77, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getReg(EAX) == vm.getControl() && vm.getReg(EBX) == vm.getStack()[-1];
        }, 4
    ),
    InstructionTest(
        "call_ptr",
        std::vector<int32_t>({18, 5, 18, 5, 16, 9, 1, 0, 0, 80, 1, 0, 5, 1, 1, 17, 78, 18, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getReg(EAX) == vm.getControl() && vm.getReg(EBX) == vm.getStack()[-1];
        }, 5
    ),
    InstructionTest(
        "call_regptr",
        std::vector<int32_t>({18, 1, 3, 18, 16, 9, 1, 0, 0, 80, 1, 0, 5, 1, 1, 17, 79, 3, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 1 && vm.getReg(EAX) == vm.getControl() && vm.getReg(EBX) == vm.getStack()[-1];
        }, 5
    ),
    InstructionTest(
        "ret_",
        std::vector<int32_t>({18, 16, 6, 1, 3, 123, 80, 1, 0, 14, 1, 1, 1, 76, 2, 1, 3, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getStackLength() == 0 && vm.getReg(EAX) == vm.getControl() && vm.getReg(EDX) == 123 && vm.getReg(EAX) == vm.getStack()[0];
        }, 6
    ),
    InstructionTest(
        "db string",
        std::vector<int32_t>({1, 0, 116, 104, 105, 115, 32, 105, 115, 32, 97, 32, 34, 115, 116, 114, 105, 110, 103, 34, 32, 128522}),
        [](VM &vm, std::string _stdout) -> bool {
            return UnicodeToUTF8(vm.getMemory() + 1, vm.getMemory() + 21) == "this is a \"string\" 😊";
        }
    ),
    InstructionTest(
        "equ",
        std::vector<int32_t>({4, 1, 0, 255, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 255;
        }
    ),
    InstructionTest(
        "int_int",
        std::vector<int32_t>({15, 1, 0, 4, 1, 1, 1, 1, 2, 15, 1, 3, 13, 81, 128, 0, 116, 101, 115, 116, 32, 115, 116, 114, 105, 110, 103, 32, 128522}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "test string 😊";
        }, 5
    ),
    InstructionTest(
        "int_reg",
        std::vector<int32_t>({15, 1, 0, 4, 1, 1, 1, 1, 2, 15, 1, 3, 128, 82, 3, 0, 116, 101, 115, 116, 32, 115, 116, 114, 105, 110, 103, 32, 128522, 32, 49, 50, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "test string 😊 120123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF";
        }, 5
    ),
    InstructionTest(
        "int_ptr",
        std::vector<int32_t>({15, 1, 0, 4, 1, 1, 1, 1, 2, 15, 1, 3, 13, 83, 28, 0, 116, 101, 115, 116, 32, 115, 116, 114, 105, 110, 103, 32, 128522, 128}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "test string 😊";
        }, 5
    ),
    InstructionTest(
        "int_regptr",
        std::vector<int32_t>({15, 1, 0, 4, 1, 1, 1, 1, 2, 15, 1, 3, 13, 84, 2, 0, 128, 101, 115, 116, 32, 115, 116, 114, 105, 110, 103, 32, 128522, 128}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "est string 😊";
        }, 5
    ),
    InstructionTest(
        "mul_int",
        std::vector<int32_t>({6, 1, 0, 10, 85, 5, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 50;
        }
    ),
    InstructionTest(
        "mul_reg",
        std::vector<int32_t>({9, 1, 0, 10, 1, 1, 5, 86, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 50;
        }
    ),
    InstructionTest(
        "mul_ptr",
        std::vector<int32_t>({6, 1, 0, 10, 87, 6, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 50;
        }
    ),
    InstructionTest(
        "mul_regptr",
        std::vector<int32_t>({9, 1, 0, 10, 1, 1, 9, 88, 1, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 50;
        }
    ),
    InstructionTest(
        "div_int",
        std::vector<int32_t>({6, 1, 0, 11, 89, 5, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2 && vm.getReg(EDX) == 1;
        }
    ),
    InstructionTest(
        "div_reg",
        std::vector<int32_t>({9, 1, 0, 12, 1, 1, 5, 90, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2 && vm.getReg(EDX) == 2;
        }
    ),
    InstructionTest(
        "div_ptr",
        std::vector<int32_t>({6, 1, 0, 13, 91, 6, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2 && vm.getReg(EDX) == 3;
        }
    ),
    InstructionTest(
        "div_regptr",
        std::vector<int32_t>({9, 1, 0, 14, 1, 1, 9, 92, 1, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2 && vm.getReg(EDX) == 4;
        }
    ),
    InstructionTest(
        "div 0",
        std::vector<int32_t>({6, 1, 0, 10, 89, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return false;
        },
        0,
        &VM::ERROR_DIVISION_BY_ZERO
    ),
    InstructionTest(
        "dec_reg",
        std::vector<int32_t>({6, 1, 0, 11, 93, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 10;
        }
    ),
    InstructionTest(
        "dec_ptr",
        std::vector<int32_t>({6, 94, 6, 2, 0, 6, 0, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "dec_regptr",
        std::vector<int32_t>({9, 1, 1, 9, 95, 1, 2, 0, 9, 0, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "inc_reg",
        std::vector<int32_t>({6, 1, 0, 11, 96, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 12;
        }
    ),
    InstructionTest(
        "inc_ptr",
        std::vector<int32_t>({6, 97, 6, 2, 0, 6, 0, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 8;
        }
    ),
    InstructionTest(
        "inc_regptr",
        std::vector<int32_t>({9, 1, 1, 9, 98, 1, 2, 0, 9, 0, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 8;
        }
    ),
    InstructionTest(
        "neg_reg +",
        std::vector<int32_t>({6, 1, 0, -11, 99, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11;
        }
    ),
    InstructionTest(
        "neg_reg -",
        std::vector<int32_t>({6, 1, 0, 11, 99, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -11;
        }
    ),
    InstructionTest(
        "neg_ptr +",
        std::vector<int32_t>({6, 100, 6, 2, 0, 6, 0, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -7;
        }
    ),
    InstructionTest(
        "neg_ptr -",
        std::vector<int32_t>({6, 100, 6, 2, 0, 6, 0, -7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "neg_regptr +",
        std::vector<int32_t>({9, 1, 1, 9, 101, 1, 2, 0, 9, 0, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -7;
        }
    ),
    InstructionTest(
        "neg_regptr -",
        std::vector<int32_t>({9, 1, 1, 9, 101, 1, 2, 0, 9, 0, -7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "shl_reg_int",
        std::vector<int32_t>({7, 1, 0, 3, 102, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "shl_reg_reg",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 2, 103, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 12;
        }
    ),
    InstructionTest(
        "shl_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 3, 104, 0, 7, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 96;
        }
    ),
    InstructionTest(
        "shl_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 10, 105, 0, 1, 0, 4}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 48;
        }
    ),
    InstructionTest(
        "shl_ptr_int",
        std::vector<int32_t>({7, 106, 7, 1, 2, 0, 7, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "shl_ptr_reg",
        std::vector<int32_t>({10, 1, 1, 2, 107, 10, 1, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 12;
        }
    ),
    InstructionTest(
        "shl_ptr_ptr",
        std::vector<int32_t>({7, 108, 8, 7, 2, 0, 8, 0, 5, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 96;
        }
    ),
    InstructionTest(
        "shl_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 10, 109, 11, 1, 2, 0, 11, 0, 4, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 48;
        }
    ),
    InstructionTest(
        "shl_regptr_int",
        std::vector<int32_t>({10, 1, 1, 10, 110, 1, 1, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 6;
        }
    ),
    InstructionTest(
        "shl_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, 2, 111, 1, 2, 2, 0, 13, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 12;
        }
    ),
    InstructionTest(
        "shl_regptr_ptr",
        std::vector<int32_t>({10, 1, 1, 11, 112, 1, 10, 2, 0, 11, 0, 5, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 96;
        }
    ),
    InstructionTest(
        "shl_regreg_regptr",
        std::vector<int32_t>({13, 1, 2, 14, 1, 1, 13, 113, 2, 1, 2, 0, 14, 0, 4, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 48;
        }
    ),
    InstructionTest(
        "shr_reg_int",
        std::vector<int32_t>({7, 1, 0, 6, 114, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_reg_reg",
        std::vector<int32_t>({10, 1, 0, 12, 1, 1, 2, 115, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 96, 116, 0, 7, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 48, 1, 1, 10, 117, 0, 1, 0, 4}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_ptr_int",
        std::vector<int32_t>({7, 118, 7, 1, 2, 0, 7, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_ptr_reg",
        std::vector<int32_t>({10, 1, 1, 2, 119, 10, 1, 2, 0, 10, 0, 12}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_ptr_ptr",
        std::vector<int32_t>({7, 120, 8, 7, 2, 0, 8, 0, 5, 96}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 10, 121, 11, 1, 2, 0, 11, 0, 4, 48}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_regptr_int",
        std::vector<int32_t>({10, 1, 1, 10, 122, 1, 1, 2, 0, 10, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 13, 1, 2, 2, 123, 1, 2, 2, 0, 13, 0, 12}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_regptr_ptr",
        std::vector<int32_t>({10, 1, 1, 11, 124, 1, 10, 2, 0, 11, 0, 5, 96}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "shr_regreg_regptr",
        std::vector<int32_t>({13, 1, 2, 14, 1, 1, 13, 125, 2, 1, 2, 0, 14, 0, 4, 48}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 3;
        }
    ),
    InstructionTest(
        "neg_ptr",
        std::vector<int32_t>({6, 100, 6, 2, 0, 6, 0, 4}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "neg_reg",
        std::vector<int32_t>({6, 1, 0, 3, 99, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -3;
        }
    ),
    InstructionTest(
        "neg_regptr",
        std::vector<int32_t>({9, 1, 1, 9, 101, 1, 2, 0, 9, 0, 2}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -2;
        }
    ),
    InstructionTest(
        "not_ptr",
        std::vector<int32_t>({6, 127, 6, 2, 0, 6, 0, 4}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -5;
        }
    ),
    InstructionTest(
        "not_reg",
        std::vector<int32_t>({6, 1, 0, 3, 126, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -4;
        }
    ),
    InstructionTest(
        "not_regptr",
        std::vector<int32_t>({9, 1, 1, 9, 128, 1, 2, 0, 9, 0, 2}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == -3;
        }
    ),
    InstructionTest(
        "and_reg_int",
        std::vector<int32_t>({7, 1, 0, 3, 129, 0, 6, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_reg_reg",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 6, 130, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 3, 131, 0, 7, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 10, 132, 0, 1, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_ptr_int",
        std::vector<int32_t>({7, 133, 7, 6, 2, 0, 7, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_ptr_reg",
        std::vector<int32_t>({10, 1, 1, 6, 134, 10, 1, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_ptr_ptr",
        std::vector<int32_t>({7, 135, 7, 8, 2, 0, 7, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 11, 136, 10, 1, 2, 0, 10, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_regptr_int",
        std::vector<int32_t>({10, 1, 2, 10, 137, 2, 6, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 6, 1, 2, 13, 138, 2, 1, 2, 0, 13, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_regptr_ptr",
        std::vector<int32_t>({10, 1, 2, 10, 139, 2, 11, 2, 0, 10, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "and_regptr_regptr",
        std::vector<int32_t>({13, 1, 1, 14, 1, 2, 13, 140, 2, 1, 2, 0, 13, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 2;
        }
    ),
    InstructionTest(
        "or_reg_int",
        std::vector<int32_t>({7, 1, 0, 3, 141, 0, 6, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_reg_reg",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 6, 142, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 3, 143, 0, 7, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 10, 144, 0, 1, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_ptr_int",
        std::vector<int32_t>({7, 145, 7, 6, 2, 0, 7, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_ptr_reg",
        std::vector<int32_t>({10, 1, 1, 6, 146, 10, 1, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_ptr_ptr",
        std::vector<int32_t>({7, 147, 7, 8, 2, 0, 7, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 11, 148, 10, 1, 2, 0, 10, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_regptr_int",
        std::vector<int32_t>({10, 1, 2, 10, 149, 2, 6, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 6, 1, 2, 13, 150, 2, 1, 2, 0, 13, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_regptr_ptr",
        std::vector<int32_t>({10, 1, 2, 10, 151, 2, 11, 2, 0, 10, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "or_regptr_regptr",
        std::vector<int32_t>({13, 1, 1, 14, 1, 2, 13, 152, 2, 1, 2, 0, 13, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 7;
        }
    ),
    InstructionTest(
        "xor_reg_int",
        std::vector<int32_t>({7, 1, 0, 3, 153, 0, 6, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_reg_reg",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 6, 154, 0, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 3, 155, 0, 7, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 3, 1, 1, 10, 156, 0, 1, 0, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_ptr_int",
        std::vector<int32_t>({7, 157, 7, 6, 2, 0, 7, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_ptr_reg",
        std::vector<int32_t>({10, 1, 1, 6, 158, 10, 1, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_ptr_ptr",
        std::vector<int32_t>({7, 159, 7, 8, 2, 0, 7, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_ptr_regptr",
        std::vector<int32_t>({10, 1, 1, 11, 160, 10, 1, 2, 0, 10, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_regptr_int",
        std::vector<int32_t>({10, 1, 2, 10, 161, 2, 6, 2, 0, 10, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_regptr_reg",
        std::vector<int32_t>({13, 1, 1, 6, 1, 2, 13, 162, 2, 1, 2, 0, 13, 0, 3}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_regptr_ptr",
        std::vector<int32_t>({10, 1, 2, 10, 163, 2, 11, 2, 0, 10, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "xor_regptr_regptr",
        std::vector<int32_t>({13, 1, 1, 14, 1, 2, 13, 164, 2, 1, 2, 0, 13, 0, 3, 6}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 5;
        }
    ),
    InstructionTest(
        "test_int_int -",
        std::vector<int32_t>({7, 165, -1, -5, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_int_int +",
        std::vector<int32_t>({7, 165, 5, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_int_int 0",
        std::vector<int32_t>({7, 165, 5, 8, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_int_ptr -",
        std::vector<int32_t>({7, 166, -1, 7, 1, 3, 123, 0, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_int_ptr +",
        std::vector<int32_t>({7, 166, 5, 7, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_int_ptr 0",
        std::vector<int32_t>({7, 166, 5, 7, 1, 3, 123, 0, 8}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_int_reg -",
        std::vector<int32_t>({10, 1, 0, -5, 167, -1, 0, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_int_reg +",
        std::vector<int32_t>({10, 1, 0, 1, 167, 5, 0, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_int_reg 0",
        std::vector<int32_t>({10, 1, 0, 8, 167, 5, 0, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_int_regptr -",
        std::vector<int32_t>({10, 1, 0, 10, 168, -1, 0, 1, 3, 123, 0, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_int_regptr +",
        std::vector<int32_t>({10, 1, 0, 10, 168, 5, 0, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_int_regptr 0",
        std::vector<int32_t>({10, 1, 0, 10, 168, 5, 0, 1, 3, 123, 0, 8}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_ptr_ptr -",
        std::vector<int32_t>({7, 170, 7, 8, 1, 3, 123, 0, -1, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_ptr_ptr +",
        std::vector<int32_t>({7, 170, 7, 8, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_ptr_ptr 0",
        std::vector<int32_t>({7, 170, 7, 8, 1, 3, 123, 0, 5, 8}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_ptr_int -",
        std::vector<int32_t>({7, 169, 7, -5, 1, 3, 123, 0, -1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_ptr_int +",
        std::vector<int32_t>({7, 169, 7, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_ptr_int 0",
        std::vector<int32_t>({7, 169, 7, 8, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 2
    ),
    InstructionTest(
        "test_ptr_reg -",
        std::vector<int32_t>({10, 1, 0, -5, 171, 10, 0, 1, 3, 123, 0, -1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_ptr_reg +",
        std::vector<int32_t>({10, 1, 0, 1, 171, 10, 0, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_ptr_reg 0",
        std::vector<int32_t>({10, 1, 0, 8, 171, 10, 0, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_ptr_ptrreg -",
        std::vector<int32_t>({10, 1, 0, 11, 172, 10, 0, 1, 3, 123, 0, -1, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_ptr_ptrreg +",
        std::vector<int32_t>({10, 1, 0, 11, 172, 10, 0, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_ptr_ptrreg 0",
        std::vector<int32_t>({10, 1, 0, 11, 172, 10, 0, 1, 3, 123, 0, 5, 8}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_reg_int -",
        std::vector<int32_t>({10, 1, 0, -1, 173, 0, -5, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_reg_int +",
        std::vector<int32_t>({10, 1, 0, 5, 173, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_reg_int 0",
        std::vector<int32_t>({10, 1, 0, 5, 173, 0, 8, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_reg_ptr -",
        std::vector<int32_t>({10, 1, 0, -1, 174, 0, 10, 1, 3, 123, 0, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_reg_ptr +",
        std::vector<int32_t>({10, 1, 0, 5, 174, 0, 10, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_reg_ptr 0",
        std::vector<int32_t>({10, 1, 0, 5, 174, 0, 10, 1, 3, 123, 0, 8}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_reg_reg -",
        std::vector<int32_t>({13, 1, 0, -1, 1, 1, -5, 175, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_reg_reg +",
        std::vector<int32_t>({13, 1, 0, 5, 1, 1, 1, 175, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_reg_reg 0",
        std::vector<int32_t>({13, 1, 0, 5, 1, 1, 8, 175, 0, 1, 1, 3, 123, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_reg_regptr -",
        std::vector<int32_t>({13, 1, 0, -1, 1, 1, 13, 176, 0, 1, 1, 3, 123, 0, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_reg_regptr +",
        std::vector<int32_t>({13, 1, 0, 5, 1, 1, 13, 176, 0, 1, 1, 3, 123, 0, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_reg_regptr 0",
        std::vector<int32_t>({13, 1, 0, 8, 1, 1, 13, 176, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_regptr_int -",
        std::vector<int32_t>({10, 1, 0, 10, 177, 0, -5, 1, 3, 123, 0, -1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_regptr_int +",
        std::vector<int32_t>({10, 1, 0, 10, 177, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_regptr_int 0",
        std::vector<int32_t>({10, 1, 0, 10, 177, 0, 8, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_regptr_ptr -",
        std::vector<int32_t>({10, 1, 0, 10, 178, 0, 11, 1, 3, 123, 0, -1, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_regptr_ptr +",
        std::vector<int32_t>({10, 1, 0, 10, 178, 0, 11, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_regptr_ptr 0",
        std::vector<int32_t>({10, 1, 0, 10, 178, 0, 11, 1, 3, 123, 0, 5, 8}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 3
    ),
    InstructionTest(
        "test_regptr_reg -",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, -5, 179, 0, 1, 1, 3, 123, 0, -1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_regptr_reg +",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 1, 179, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_regptr_reg 0",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 8, 179, 0, 1, 1, 3, 123, 0, 5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_regptr_regptr -",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 14, 180, 0, 1, 1, 3, 123, 0, -1, -5}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == true && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_regptr_regptr +",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 14, 180, 0, 1, 1, 3, 123, 0, 5, 1}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == false && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "test_regptr_regptr 0",
        std::vector<int32_t>({13, 1, 0, 13, 1, 1, 14, 180, 0, 1, 1, 3, 123, 0, 5, 8}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagSign == false && vm.flagZero == true && vm.flagOverflow == false && vm.getReg(EDX) == 123;
        }, 4
    ),
    InstructionTest(
        "rdtsc_",
        std::vector<int32_t>({2, 181, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) != 0;
        }
    ),
    InstructionTest(
        "rdtsc_reg",
        std::vector<int32_t>({3, 182, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) != 0;
        }
    ),
    InstructionTest(
        "rdtsc_ptr",
        std::vector<int32_t>({6, 183, 6, 2, 1, 6, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) != 0;
        }
    ),
    InstructionTest(
        "rdtsc_regptr",
        std::vector<int32_t>({9, 1, 2, 9, 184, 2, 2, 1, 9, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) != 0;
        }
    ),
    InstructionTest(
        "xrnd_",
        std::vector<int32_t>({7, 185, 25, 0, 0, 33, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) != 0;
        }
    ),
    InstructionTest(
        "xrnd_reg",
        std::vector<int32_t>({8, 186, 1, 25, 1, 0, 33, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) != 0;
        }
    ),
    InstructionTest(
        "xrnd_ptr",
        std::vector<int32_t>({11, 187, 11, 21, 11, 0, 33, 0, 2, 1, 11, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) != 0;
        }
    ),
    InstructionTest(
        "xrnd_regptr",
        std::vector<int32_t>({14, 1, 2, 14, 188, 2, 21, 14, 0, 33, 3, 2, 1, 14, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) != 0;
        }
    ),
    InstructionTest(
        "xslp_int",
        std::vector<int32_t>({4, 193, 100, 189, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) >= 100 && vm.getReg(EAX) < 150;
        }
    ),
    InstructionTest(
        "xslp_reg",
        std::vector<int32_t>({7, 1, 1, 100, 195, 1, 189, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) >= 100 && vm.getReg(EAX) < 150;
        }
    ),
    InstructionTest(
        "xslp_ptr",
        std::vector<int32_t>({4, 194, 4, 189, 0, 100}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) >= 100 && vm.getReg(EAX) < 150;
        }
    ),
    InstructionTest(
        "xslp_regptr",
        std::vector<int32_t>({7, 1, 1, 7, 196, 1, 189, 0, 100}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) >= 100 && vm.getReg(EAX) < 150;
        }
    ),
    InstructionTest(
        "xtime_reg",
        std::vector<int32_t>({5, 193, 100, 190, 1, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) >= 100 && vm.getReg(EBX) < 150;
        }
    ),
    InstructionTest(
        "xtime_ptr",
        std::vector<int32_t>({8, 193, 100, 191, 8, 2, 1, 8, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) >= 100 && vm.getReg(EBX) < 150;
        }
    ),
    InstructionTest(
        "xtime_regptr",
        std::vector<int32_t>({11, 1, 2, 11, 193, 100, 192, 2, 2, 1, 11, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) >= 100 && vm.getReg(EBX) < 150;
        }
    ),
    InstructionTest(
        "xwr_int",
        std::vector<int32_t>({3, 197, 65, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "A";
        }
    ),
    InstructionTest(
        "xwr_reg",
        std::vector<int32_t>({6, 1, 0, 65, 198, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "A";
        }
    ),
    InstructionTest(
        "xwr_ptr",
        std::vector<int32_t>({3, 199, 3, 0, 65}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "A";
        }
    ),
    InstructionTest(
        "xwr_regptr",
        std::vector<int32_t>({6, 1, 0, 6, 200, 0, 0, 65}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "A";
        }
    ),
    InstructionTest(
        "xwr_int_int",
        std::vector<int32_t>({4, 201, 4, 8, 0, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_int_reg",
        std::vector<int32_t>({7, 1, 0, 8, 202, 7, 0, 0, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_int_ptr",
        std::vector<int32_t>({4, 203, 5, 4, 0, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_int_regptr",
        std::vector<int32_t>({7, 1, 0, 7, 204, 8, 0, 0, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_reg_int",
        std::vector<int32_t>({7, 1, 3, 7, 205, 3, 8, 0, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_reg_reg",
        std::vector<int32_t>({10, 1, 0, 8, 1, 3, 10, 206, 3, 0, 0, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_reg_ptr",
        std::vector<int32_t>({7, 1, 3, 8, 207, 3, 7, 0, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_reg_regptr",
        std::vector<int32_t>({10, 1, 0, 10, 1, 3, 11, 208, 3, 0, 0, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_ptr_int",
        std::vector<int32_t>({4, 209, 4, 8, 0, 5, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_ptr_reg",
        std::vector<int32_t>({7, 1, 0, 8, 210, 7, 0, 0, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_ptr_ptr",
        std::vector<int32_t>({4, 211, 4, 5, 0, 6, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_ptr_regptr",
        std::vector<int32_t>({7, 1, 0, 8, 212, 7, 0, 0, 9, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_regptr_int",
        std::vector<int32_t>({7, 1, 3, 7, 213, 3, 8, 0, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_regptr_reg",
        std::vector<int32_t>({10, 1, 0, 8, 1, 3, 10, 214, 3, 0, 0, 11, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_regptr_ptr",
        std::vector<int32_t>({7, 1, 3, 7, 215, 3, 8, 0, 9, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwr_regptr_regptr",
        std::vector<int32_t>({10, 1, 0, 11, 1, 3, 10, 216, 3, 0, 0, 12, 8, 97, 32, 115, 116, 114, 105, 110, 103}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "a string";
        }
    ),
    InstructionTest(
        "xwi_int",
        std::vector<int32_t>({3, 233, 65, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "65";
        }
    ),
    InstructionTest(
        "xwi_reg",
        std::vector<int32_t>({6, 1, 0, 65, 234, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "65";
        }
    ),
    InstructionTest(
        "xwi_ptr",
        std::vector<int32_t>({3, 235, 3, 0, 65}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "65";
        }
    ),
    InstructionTest(
        "xwi_regptr",
        std::vector<int32_t>({6, 1, 0, 6, 236, 0, 0, 65}),
        [](VM &vm, std::string _stdout) -> bool {
            return _stdout == "65";
        }
    ),
    InstructionTest(
        "xrd_int_int",
        std::vector<int32_t>({13, 217, 13, 2, 2, 2, 13, 2, 3, 14, 2, 1, 15, 0, 0, 0, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_int_ptr",
        std::vector<int32_t>({13, 219, 13, 17, 2, 2, 13, 2, 3, 14, 2, 1, 15, 0, 0, 0, 0, 0, 2}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_int_reg",
        std::vector<int32_t>({16, 1, 0, 2, 218, 16, 0, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_int_regptr",
        std::vector<int32_t>({16, 1, 0, 20, 220, 16, 0, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0, 2}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_reg_int",
        std::vector<int32_t>({16, 1, 1, 16, 221, 1, 2, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_reg_ptr",
        std::vector<int32_t>({16, 1, 1, 16, 223, 1, 20, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0, 2}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_reg_reg",
        std::vector<int32_t>({19, 1, 0, 2, 1, 1, 19, 222, 1, 0, 2, 2, 19, 2, 3, 20, 2, 1, 21, 0, 0, 0, 0, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_reg_regptr",
        std::vector<int32_t>({19, 1, 0, 23, 1, 1, 19, 224, 1, 0, 2, 2, 19, 2, 3, 20, 2, 1, 21, 0, 0, 0, 0, 0, 2}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_ptr_int",
        std::vector<int32_t>({13, 225, 17, 2, 2, 2, 13, 2, 3, 14, 2, 1, 15, 0, 0, 0, 0, 0, 13}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_ptr_ptr",
        std::vector<int32_t>({13, 227, 18, 17, 2, 2, 13, 2, 3, 14, 2, 1, 15, 0, 0, 0, 0, 0, 2, 13}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_ptr_reg",
        std::vector<int32_t>({16, 1, 0, 2, 226, 20, 0, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0, 16}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_ptr_regptr",
        std::vector<int32_t>({16, 1, 0, 20, 228, 21, 0, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0, 2, 16}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_regptr_int",
        std::vector<int32_t>({16, 1, 0, 20, 229, 0, 2, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0, 16}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_regptr_ptr",
        std::vector<int32_t>({16, 1, 0, 21, 231, 0, 20, 2, 2, 16, 2, 3, 17, 2, 1, 18, 0, 0, 0, 0, 0, 2, 16}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_regptr_reg",
        std::vector<int32_t>({19, 1, 0, 2, 1, 1, 23, 230, 1, 0, 2, 2, 19, 2, 3, 20, 2, 1, 21, 0, 0, 0, 0, 0, 19}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xrd_regptr_regptr",
        std::vector<int32_t>({19, 1, 0, 23, 1, 1, 24, 232, 1, 0, 2, 2, 19, 2, 3, 20, 2, 1, 21, 0, 0, 0, 0, 0, 2, 19}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EBX) == 0 && vm.getReg(ECX) == 81 && vm.getReg(EDX) == 65;
        }
    ),
    InstructionTest(
        "xflush_",
        std::vector<int32_t>({2, 237, 0}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flushed == true;
        }
    ),
    InstructionTest(
        "xti error 0",
        std::vector<int32_t>({4, 254, 4, 10, 0, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == true && vm.getReg(EAX) == 0;
        }
    ),
    InstructionTest(
        "xti error 1",
        std::vector<int32_t>({4, 254, 4, 1, 0, 65}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == true && vm.getReg(EAX) == 1;
        }
    ),
    InstructionTest(
        "xti_int_int",
        std::vector<int32_t>({4, 254, 4, 11, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_int_reg",
        std::vector<int32_t>({7, 1, 0, 11, 255, 7, 0, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_int_ptr",
        std::vector<int32_t>({4, 256, 4, 15, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_int_regptr",
        std::vector<int32_t>({7, 1, 0, 18, 257, 7, 0, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_reg_int",
        std::vector<int32_t>({7, 1, 0, 7, 258, 0, 11, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_reg_reg",
        std::vector<int32_t>({10, 1, 0, 10, 1, 1, 11, 259, 0, 1, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_reg_ptr",
        std::vector<int32_t>({7, 1, 0, 7, 260, 0, 18, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_reg_regptr",
        std::vector<int32_t>({10, 1, 1, 21, 1, 0, 10, 261, 0, 1, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_ptr_int",
        std::vector<int32_t>({4, 262, 15, 11, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 4}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_ptr_reg",
        std::vector<int32_t>({7, 1, 0, 11, 263, 18, 0, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_ptr_ptr",
        std::vector<int32_t>({4, 264, 16, 15, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11, 4}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_ptr_regptr",
        std::vector<int32_t>({7, 1, 0, 18, 265, 19, 0, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_regptr_int",
        std::vector<int32_t>({7, 1, 0, 18, 266, 0, 11, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_regptr_reg",
        std::vector<int32_t>({10, 1, 1, 11, 1, 0, 21, 267, 0, 1, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 10}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_regptr_ptr",
        std::vector<int32_t>({7, 1, 0, 19, 268, 0, 18, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11, 7}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xti_regptr_regptr",
        std::vector<int32_t>({10, 1, 1, 21, 1, 0, 22, 269, 0, 1, 0, 45, 50, 49, 52, 55, 52, 56, 51, 54, 52, 56, 11, 10}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.flagOverflow == false && vm.getReg(EAX) == std::numeric_limits<int>::min();
        }
    ),
    InstructionTest(
        "xts error 0",
        std::vector<int32_t>({7, 1, 0, 10, 238, 7, 1, 0, 48}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 0;
        }
    ),
    InstructionTest(
        "xts_int_int",
        std::vector<int32_t>({14, 1, 0, std::numeric_limits<int>::min(), 238, 14, 11, 69, 0, 201, 14, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_int_reg",
        std::vector<int32_t>({17, 1, 0, std::numeric_limits<int>::min(), 1, 1, 11, 239, 17, 1, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_int_ptr",
        std::vector<int32_t>({14, 1, 0, std::numeric_limits<int>::min(), 240, 14, 25, 69, 0, 201, 14, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_int_regptr",
        std::vector<int32_t>({17, 1, 0, std::numeric_limits<int>::min(), 1, 1, 28, 241, 17, 1, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_reg_int",
        std::vector<int32_t>({17, 1, 1, 17, 1, 0, std::numeric_limits<int>::min(), 242, 1, 11, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_reg_reg",
        std::vector<int32_t>({20, 1, 1, 20, 1, 0, std::numeric_limits<int>::min(), 1, 2, 11, 243, 1, 2, 69, 0, 201, 20, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_reg_ptr",
        std::vector<int32_t>({17, 1, 1, 17, 1, 0, std::numeric_limits<int>::min(), 244, 1, 28, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_reg_regptr",
        std::vector<int32_t>({20, 1, 1, 20, 1, 0, std::numeric_limits<int>::min(), 1, 2, 31, 245, 1, 2, 69, 0, 201, 20, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_ptr_int",
        std::vector<int32_t>({14, 1, 0, std::numeric_limits<int>::min(), 246, 25, 11, 69, 0, 201, 14, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 14}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_ptr_reg",
        std::vector<int32_t>({17, 1, 0, std::numeric_limits<int>::min(), 1, 1, 11, 247, 28, 1, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 17}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_ptr_ptr",
        std::vector<int32_t>({14, 1, 0, std::numeric_limits<int>::min(), 248, 26, 25, 69, 0, 201, 14, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11, 14}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_ptr_regptr",
        std::vector<int32_t>({17, 1, 0, std::numeric_limits<int>::min(), 1, 1, 28, 249, 29, 1, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11, 17}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_regptr_int",
        std::vector<int32_t>({17, 1, 0, std::numeric_limits<int>::min(), 1, 1, 28, 250, 1, 11, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 17}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_regptr_reg",
        std::vector<int32_t>({20, 1, 0, std::numeric_limits<int>::min(), 1, 1, 11, 1, 2, 31, 251, 2, 1, 69, 0, 201, 20, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 20}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_regptr_ptr",
        std::vector<int32_t>({17, 1, 0, std::numeric_limits<int>::min(), 1, 1, 29, 252, 1, 28, 69, 0, 201, 17, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11, 17}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    ),
    InstructionTest(
        "xts_regptr_regptr",
        std::vector<int32_t>({20, 1, 0, std::numeric_limits<int>::min(), 1, 1, 31, 1, 2, 32, 253, 2, 1, 69, 0, 201, 20, 11, 73, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 11, 20}),
        [](VM &vm, std::string _stdout) -> bool {
            return vm.getReg(EAX) == 11 && _stdout == "-2147483648";
        }
    )
};