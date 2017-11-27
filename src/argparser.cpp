#include "argparser.h"

std::vector<std::string> ArgParser::parse_args(int argc, char* argv[]) {
    std::vector<std::string> files;

    if (argc < 2) {
        return files;
    }

    for (int a=0; a<argc-1; a++) {
        std::string s(argv[a+1]);
        files.push_back(s);
    }
    return files;
}
