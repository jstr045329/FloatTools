//----------------------------------------------------------------------------------------------------------------------
//                                             Unit Tests for FloatTools
//----------------------------------------------------------------------------------------------------------------------
#include <cmath>
#include "../FloatTools.h"
#include <gtest/gtest.h>
#include <vector>
#include <iostream>

//----------------------------------------------------------------------------------------------------------------------
//                                                Test approxEquals()
//----------------------------------------------------------------------------------------------------------------------
TEST(FloatTools, testApproxEqual01) {
    // Test the 2 parameter version:
    ASSERT_TRUE(FloatTools::approx_equal(0.0, 1E-10));
    ASSERT_FALSE(FloatTools::approx_equal(0.0, 1E-6));

    // Test the 3 parameter version:
    ASSERT_TRUE(FloatTools::approx_equal(0.0, 1E-6, 1E-5));
    ASSERT_FALSE(FloatTools::approx_equal(0.0, 1E-3, 1E-4));
}

//----------------------------------------------------------------------------------------------------------------------
//                                                 Test randFloat()
//
// Ensure the NaN symbol never appears. (NaN, or Not a Number, is signalled by exponent bits all 1's.) This test
// bitwise AND's each randFloat() output with a mask and then checks if the result is equal to the mask. The number
// of tests was chosen so that, on average, the random generator should use all 256 8-bit patterns roughly 100 times
// each. That way, you don't need to try to force the random number generator into a state that is known to contain
// the forbidden sequence.
//
//----------------------------------------------------------------------------------------------------------------------
TEST(FloatTools, testRandFloat01) {
    // Use enough trials that random generator should use all 8-bit patterns approximately 100 times each:
    const int num_tests = 25600;
    const int my_random_seed = 1;
    int exponent_bits = 0x7f800000;
    float float_version;
    int *int_version;

    // Set random seed so that test is reproducible:
    srand(my_random_seed);

    for (int i = 0; i < num_tests; ++i) {
        float_version = FloatTools::rand_float();
        int_version = (int*) &float_version;
        bool success = ((*int_version) & exponent_bits) != exponent_bits;
        if (!success) {
            std::cout << "Here is a failure" << std::endl;
            std::stringstream stream;
            stream << std::endl << std::hex << (*int_version) << std::endl << exponent_bits << std::endl;
            std::string result( stream.str() );
            std::cout << result << std::endl;
            std::cout << "Set a breakpoint here if you like" << std::endl;
        }
        ASSERT_TRUE(success);
    }
}

//----------------------------------------------------------------------------------------------------------------------
//                                                 Test randFloat()
//
// Fill a buffer with 1000 random numbers, and make sure the same number does not appear too many times. 2 or 3
// occurrences of the same number is to be expected from time to time, but 100 of the same thing indicates a problem.
// (Especially since were setting the random seed, which produces a known-good sequence.\) Note that for this test, we
// intentionally don't use approximate equality, since what we're interested in is the uniqueness of bit sequences.
//
//----------------------------------------------------------------------------------------------------------------------
TEST(FloatTools, testRandFloat02) {
    const int num_nums = 1000;
    const int my_rand_seed = 3245879;
    const int max_allowable_occurrences = 10;
    int qty = 0;
    std::vector<float> my_numbers;

    // Set random seed so test is reproducible:
    srand(my_rand_seed);

    // Fill a container with random floats:
    for (int i = 0; i < num_nums; ++i) {
        my_numbers.push_back(FloatTools::rand_float());
    }

    for (int i = 0; i < num_nums; ++i) {
        qty = 0;
        for (int j = i; j < num_nums; ++j) {
            if (my_numbers.at(i) == my_numbers.at(j)) {
                qty++;
            }
            ASSERT_TRUE(qty < max_allowable_occurrences);
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
//                                                 Test randDouble()
//
// Ensure NaN symbol is absent.
//
//----------------------------------------------------------------------------------------------------------------------
TEST(FloatTools, testRandDouble01) {
    // Use enough trials that random generator should use all 11-bit patterns approximately 100 times each:
    const int num_tests = 204800;
    const int my_random_seed = 1;
    long exponent_bits = 0x7ff0000000000000;
    double float_version;
    long *int_version;

    // Set random seed so that test is reproducible:
    srand(my_random_seed);

    for (int i = 0; i < num_tests; ++i) {
        float_version = FloatTools::rand_double();
        int_version = (long*) &float_version;
        bool success = ((*int_version) & exponent_bits) != exponent_bits;
        if (!success) {
            std::cout << "Here is a failure" << std::endl;
            std::stringstream stream;
            stream << std::endl << std::hex << (*int_version) << std::endl << exponent_bits << std::endl;
            std::string result( stream.str() );
            std::cout << result << std::endl;
            std::cout << "Set a breakpoint here if you like" << std::endl;
        }
        ASSERT_TRUE(success);
    }
}

//----------------------------------------------------------------------------------------------------------------------
//                                                 Test randDouble()
//
// Ensure same number does not appear too many times.
//
//----------------------------------------------------------------------------------------------------------------------
TEST(FloatTools, testRandDouble02) {
    const int num_nums = 1000;
    const int my_rand_seed = 3245999;
    const int max_allowable_occurrences = 10;
    int qty = 0;
    std::vector<double> my_numbers;

    // Set random seed so test is reproducible:
    srand(my_rand_seed);

    // Fill a container with random floats:
    for (int i = 0; i < num_nums; ++i) {
        my_numbers.push_back(FloatTools::rand_double());
    }

    for (int i = 0; i < num_nums; ++i) {
        qty = 0;
        for (int j = i; j < num_nums; ++j) {
            if (my_numbers.at(i) == my_numbers.at(j)) {
                qty++;
            }
        }
        if (qty >= max_allowable_occurrences) {
            std::cout << "set breakpoint here" << std::endl;
        }
        ASSERT_LT(qty, max_allowable_occurrences);
    }
}
