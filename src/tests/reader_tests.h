#include "gtest/gtest.h"
#include "../reader.h"
#include <opencv2/core.hpp>
#include <string>

// A file that does not exist returns -1
TEST (ReaderTests, DoesNotExist) {
    std::string bad_file_name = "soiaeghwm+%en";
    Reader R;
    ASSERT_EQ(-1, R.import_file(bad_file_name));
}


// A file that does exist returns zeros as status code
TEST (ReaderTests, DoesExist) {
    std::string bad_file_name = "../ignite.png";
    Reader R;
    ASSERT_EQ(0, R.import_file(bad_file_name));
}

// A file with bad data/invalid format should return -2
TEST (ReaderTests, BadFormat) {
    std::string bad_format = "reader.h";
    Reader R;
    ASSERT_EQ(-2, R.import_file(bad_format));
}

// If image is empty/not initialized, display should return false
TEST (ReaderTests, DisplayEmpty) {
    Reader R;
    ASSERT_EQ(false, R.display_image());
}

// If image is empty/not initialized, preprocess should return false
TEST (ReaderTests, PreProcessEmpty) {
    Reader R;
    ASSERT_EQ(false, R.preprocess());
}

// If image is empty/not initialized, process should return false
TEST (ReaderTests, ProcessEmpty) {
    Reader R;
    ASSERT_EQ(false, R.process());
}

// If image is not empty, display should return true
TEST (ReaderTests, DisplayInitialized) {
    Reader R;
    R.set_image(cv::Mat::zeros(10, 10, CV_64F));
    ASSERT_EQ(true, R.display_image());
}

// If image is not empty, preprocess should return true
TEST (ReaderTests, PreProcessInitialized) {
    Reader R;
    R.set_image(cv::Mat::zeros(10, 10, CV_64F));
    ASSERT_EQ(true, R.preprocess());
}

// If image is not empty, process should return true
TEST (ReaderTests, ProcessInitialized) {
    Reader R;
    R.set_image(cv::Mat::zeros(10, 10, CV_64F));
    ASSERT_EQ(true, R.process());
}

