#ifndef TESTS_INSTRUCTIONS_EDGE_H
#define TESTS_INSTRUCTIONS_EDGE_H

#include "tests-instructions-edge--init.h"
#include "tests-instructions-edge-mov-misc.h"
#include "tests-instructions-edge-add.h"
#include "tests-instructions-edge-and.h"
#include "tests-instructions-edge-cmp.h"
#include "tests-instructions-edge-inc-dec.h"
#include "tests-instructions-edge-neg.h"
#include "tests-instructions-edge-not.h"
#include "tests-instructions-edge-or.h"
#include "tests-instructions-edge-sub.h"
#include "tests-instructions-edge-test.h"
#include "tests-instructions-edge-xor.h"
#include "tests-instructions-edge-shl.h"
#include "tests-instructions-edge-shr.h"

std::map<std::string, std::vector<InstructionEdgeTest>> InstructionsEdgeTests::tests = {
    {"mov_misc", mov_tests},
    {"add", add_tests},
    {"and", and_tests},
    {"cmp", cmp_tests},
    {"inc_dec", inc_dec_tests},
    {"neg", neg_tests},
    {"not", not_tests},
    {"or", or_tests},
    {"sub", sub_tests},
    {"test", test_tests},
    {"xor", xor_tests},
    {"shl", shl_tests}, 
    {"shr", shr_tests},
};

#endif