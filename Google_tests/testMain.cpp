//----------------------------------------------------------------------------------------------------------------------
//                                                     Test Main
//
// This file defines int main for Google Test.
//
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "../FloatTools.h"
#include <gtest/gtest.h>

int main (int argv, char* argc[]) {
    std::cout << "Running tests" << std::endl;
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
