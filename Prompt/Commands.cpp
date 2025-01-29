//
// Created by bird on 24/01/25.
//

#include "Prompt.hpp"

bool Prompt::handleDisplayCommand(){
    return false;
}

bool Prompt::handleSimulateCommand(){
    return false;
}

bool Prompt::handleLoopCommand(){
    return false;
}

bool Prompt::handleExitCommand(){
    return true;
}

const std::unordered_map<std::string, std::function<bool()>> Prompt::commands = {
    {"display", []() { return handleDisplayCommand(); }},
    {"simulate", []() { return handleSimulateCommand(); }},
    {"loop", []() {return handleLoopCommand(); }},
    {"exit", []() { return handleExitCommand(); }},
    };