#include "gtest/gtest.h"
#include "../argparser.h"
#include <string>

TEST (Usage, ZeroArgs) {
    char * argv[1];
    char fname[5] = "name";
    argv[0] = fname;

    
    ArgParser AP;
    ASSERT_EQ("", AP.parse_args(1, argv));  
}

TEST (Usage, OneArgReturnsInput) {
    
    char * argv[2];
    char pname[6] = "pname";
    char fname[6] = "fname";
    argv[0] = pname;
    argv[1] = fname;

    ArgParser AP;
    ASSERT_EQ("fname", AP.parse_args(2, argv));
}

