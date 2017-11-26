#include "gtest/gtest.h"
#include "tests/argparser_tests.h"
#include "tests/reader_tests.h"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
