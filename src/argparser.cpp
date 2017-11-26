#include <iostream>
#include "argparser.h"


std::string ArgParser::parse_args(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cout<<"Must provide image path as input argument to program"<<std::endl;
        return "";
    }


    std::string filename0(argv[1]);



    return filename0;
}
