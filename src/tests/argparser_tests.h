#include "gtest/gtest.h"
#include "../argparser.h"
#include <string>
#include <vector>

TEST (Usage, ZeroArgs) {
    char * argv[1];
    char fname[5] = "name";
    argv[0] = fname;

    std::vector<std::string> fnames;

    ArgParser AP;
    ASSERT_EQ(fnames, AP.parse_args(1, argv));  
}


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

