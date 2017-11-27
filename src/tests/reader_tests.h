#include "gtest/gtest.h"
#include "../reader.h"
#include <string>

// A file that does not exist returns -1
TEST (Reader, DoesNotExist) {
    std::string bad_file_name = "soiaeghwm+%en";
    Reader R;
    ASSERT_EQ(-1, R.import_file(bad_file_name));
}


// A file that does exist returns zeros as status code
TEST (Reader, DoesExist) {
    std::string bad_file_name = "../ignite.png";
    Reader R;
    ASSERT_EQ(0, R.import_file(bad_file_name));
}

// A file with bad data/invalid format should return -2
TEST (Reader, BadFormat) {
    std::string bad_format = "reader.h";
    Reader R;
    ASSERT_EQ(-2, R.import_file(bad_format));
}


