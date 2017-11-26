#include "gtest/gtest.h"
#include "../reader.h"
#include <string>

// A file that does not exist returns false
TEST (Reader, DoesNotExist) {
    std::string bad_file_name = "soiaeghwm+%en";
    Reader R;
    ASSERT_EQ(false, R.import_file(bad_file_name));
}


// A file that does exist returns true
TEST (Reader, DoesExist) {
    std::string bad_file_name = "../ignite.png";
    Reader R;
    ASSERT_EQ(true, R.import_file(bad_file_name));
}
