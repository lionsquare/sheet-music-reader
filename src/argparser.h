#pragma once
#include <vector>
#include <string>

class ArgParser {
    private:
        bool display_flag;
    public:
        ArgParser();
        std::vector<std::string> parse_args(int argc, char* argv[]);
        bool get_display_flag(void);
};
