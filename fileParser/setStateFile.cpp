//
// Created by success on 14/12/24.
//


#include "openfile.hpp"
#include <cstring>
int fileParser::checkLinks(const char* const& line, States& states) {
    const char* chipset = ".links:";
    if (std::strcmp(chipset, line) == 0) {
        return 0;
    }
    return 1;
}

size_t fileParser::checkChipsets(const std::string& line, States& states) {
    const char* chipset = ".chipsets:";
    if (std::strcmp(chipset, line.c_str()) == 0)
        return 0;
    return 1;
}

bool fileParser::checkComponents(const std::string& line, States& states) {
    if (checkChipsets(line, states) == 0) {
        states.setChipset((true));
        return true;
    }
    else if (checkLinks(line.c_str(), states) == 0) {
        states.setLink((true));
        return true;
    }
    return false ;
}