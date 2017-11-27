#include "argparser.h"

std::string ArgParser::parse_args(int argc, char* argv[]) {
    
    if (argc < 2) {
        return "";
    }
    std::string filename0(argv[1]);
    return filename0;
}
