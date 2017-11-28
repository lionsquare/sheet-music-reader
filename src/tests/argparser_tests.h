#include "gtest/gtest.h"
#include "../argparser.h"
#include <string>
#include <vector>


// no input args and no flags returns empty vector
TEST (Usage, ZeroArgs) {
    char * argv[1];
    char pname[5] = "name";
    argv[0] = pname;

    std::vector<std::string> fnames;

    ArgParser AP;
    ASSERT_EQ(fnames, AP.parse_args(1, argv));  
}

// one flag with no input args returns empty vector
TEST (Usage, OneFlagZeroArgs) {
    char * argv[2];
    char pname[5] = "name";
    char display_flag[13] = "--no-display";
    argv[0] = pname;
    argv[1] = display_flag;

    std::vector<std::string> fnames;

    ArgParser AP;
    ASSERT_EQ(fnames, AP.parse_args(2, argv));  
}

// TODO convert this to a test fixture
// one arg returns vector of size 1
// one arg returns vector with the first filename
TEST (Usage, OneArgReturnsInput) {
    
    char * argv[2];
    char pname[6] = "pname";
    char fname[6] = "fname";
    argv[0] = pname;
    argv[1] = fname;

    ArgParser AP;
    std::vector<std::string> filenames = AP.parse_args(2, argv);
    ASSERT_EQ(1, filenames.size());
    ASSERT_EQ("fname", filenames[0]);
}


// TODO convert this to a test fixture
// one arg and display flag returns vector of size 1
// one arg and display flag returns vector with the first filename
// one arg and display flag sets the display flag to false
TEST (Usage, OneArgOneFlagReturnsInput) {
    
    char * argv[3];
    char pname[6] = "pname";
    char fname[6] = "fname";
    char display_flag[13] = "--no-display";
    argv[0] = pname;
    argv[1] = fname;
    argv[2] = display_flag;

    ArgParser AP;
    std::vector<std::string> filenames = AP.parse_args(3, argv);
    ASSERT_EQ(1, filenames.size());
    ASSERT_EQ("fname", filenames[0]);
    ASSERT_EQ(false, AP.get_display_flag());
}

// order change in flag is okay
TEST (Usage, OneFlagOneArgReturnsInput) {
    
    char * argv[3];
    char pname[6] = "pname";
    char fname[6] = "fname";
    char display_flag[13] = "--no-display";
    argv[0] = pname;
    argv[2] = fname;
    argv[1] = display_flag;

    ArgParser AP;
    std::vector<std::string> filenames = AP.parse_args(3, argv);
    ASSERT_EQ(1, filenames.size());
    ASSERT_EQ("fname", filenames[0]);
    ASSERT_EQ(false, AP.get_display_flag());
}


// default display flag is true
TEST (Usage, DefaultDisplayFlagIsTrue) {
    ArgParser AP;
    ASSERT_EQ(true, AP.get_display_flag());
}

