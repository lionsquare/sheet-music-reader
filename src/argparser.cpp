#include "argparser.h"

ArgParser::ArgParser(void) {
    ArgParser::display_flag = true;
}

bool ArgParser::get_display_flag(void) {
    return ArgParser::display_flag;
}

std::vector<std::string> ArgParser::parse_args(int argc, char* argv[]) {
    std::vector<std::string> files;

    if (argc < 2) {
        return files;
    }

    for (int a=0; a<argc-1; a++) {
        std::string s(argv[a+1]);

        // check for display flag
        if (s == "--no-display") {
            ArgParser::display_flag = false;
        }
        else {
            files.push_back(s);
        }
    }
    return files;
}
