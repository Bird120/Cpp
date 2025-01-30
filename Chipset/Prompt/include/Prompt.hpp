//
// Created by bird on 24/01/25.
//

#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <functional>
#include <iostream>
#include <memory>
#include "openfile.hpp"
#include "Input.hpp"

class Prompt {
public:
    Prompt();
    ~Prompt();
    void displayPrompt();
    const std::string getUserInput();
    std::size_t checkExist(const std::string& command);
    static const std::unordered_map<std::string, std::function<bool()>> commands;
    static bool handleLoopCommand();
    static bool handleSimulateCommand();
    static bool handleDisplayCommand();
    static bool handleExitCommand();
    bool checkCommand(const std::string& command);
    void parseCommand(const std::string& command,fileParser& processor, System& sy);
    void circuit(System& sys, std::pair<const std::string, const std::string> element);
};



#endif //PROMPT_HPP