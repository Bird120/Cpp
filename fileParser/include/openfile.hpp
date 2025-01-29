//
// Created by success on 22/11/24.
//

#ifndef OPENFILE_HPP
#define OPENFILE_HPP

#include <string>
#include <iostream>
#include "nts.hpp"
#include "Component.hpp"
#include "System.hpp"
#include <fstream>

using namespace std;

struct States {
    bool chipsets = false;
    bool links = false;

    void setChipset(bool value) {
        chipsets = value;
        links = !value;
    }

    void setLink(bool value) {
        links = value;
        chipsets = !value;
    }
};




class fileParser {
private:
  States* _states = nullptr;
  System& _sys;
  Component* _component;
  bool _skipFirstLine = false;

public:
    fileParser(States& states, System& sys, Component& component);
    fileParser(System& sys);
    ~fileParser();
    bool checkInput(std::pair<const std::string, const std::string> input, System& sys);
    bool doesInputExist(const std::string& input, System& sys);
    void doesGateExist(const std::pair<const std::string, const std::string> gate, System& sys);
    std::size_t checkIfEmpty(const std::pair<std::string, std::string>& element);
    std::pair<std::string, std::string> analyze(const std::string& line, const char& separator);
    void analyzeLink(std::pair<const std::string, const std::string>& element, System& sys);
	bool isPairEmpty(std::pair<const std::string, const std::string>& element);

    bool skipLine(const std::string& line);
    void process(const std::string line, System& sys, Component& chipset);
    bool processLine(const std::string line);
    void getLine(std::ifstream& myfile, System& sys);
    void stocker(const std::string& line, States& states, nts::IComponent& object);
	bool doesOutputExist(const std::string& outputName, System& sys);

    bool checkComponents(const std::string& line, States& states);
    static int checkLinks(const char* const& line, States& states);
    static size_t checkChipsets(const std::string& line, States& states);

    void treatFile(basic_ifstream<char>& myfile);
    void executions();


    void sectionLinks(const std::string& line, States& states, System& sys);
    void sectionChipset(const std::string& line, System& sys,  Component& chipset);
};

using ParserPtr = fileParser*;
//extern std::string nameChipset;
//extern std::string codeChipset;


#endif //OPENFILE_HPP
