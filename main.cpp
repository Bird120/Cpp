//
// Created by success on 22/11/24.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <memory>
//#include<vector>
#include <typeinfo>
using namespace std;


#include "ErrorFile.hpp"
#include <fstream>
#include "openfile.hpp"
#include "Output.hpp"
#include "nts.hpp"
#include "Input.hpp"
#include "AndGate.hpp"
#include "System.hpp"
#include "OrGate.hpp"
#include "Prompt.hpp"
#include "Processor.hpp"
#include "Error.hpp"

fileParser::fileParser(System& sys)
    : _sys(sys)
{
}


fileParser::fileParser(States& states, System& sys, Component& component)
    : _states(&states), _sys(sys), _component(&component), _skipFirstLine(false)
{
}


fileParser::~fileParser() {
}

std::unique_ptr<System> System::instance = nullptr;
std::once_flag System::initInstanceFlag;

void fileParser::process(const std::string line, System& sys, Component& chipset)
{
      if ((*_states).links)
    {
        sectionLinks(line, *_states, sys);
    }
    else
        sectionChipset(line, sys, chipset);
}

bool fileParser::processLine(const std::string line){
bool skipLine;

  skipLine = checkComponents(line, *_states);
  return skipLine ? true : false;
}


void fileParser::getLine(std::ifstream& myfile, System& sys)
{
    std::string line;
    std::unique_ptr<Component> chipset = std::make_unique<Component>();
    bool skipLine;
    while(myfile)
    {
      getline(myfile, line);
      skipLine = processLine(line);
      if (skipLine)
        continue;
      process(line, sys, *chipset);
    }
}

void userCommand(const std::string& command, Prompt& prompt, bool& keepRunning)
{
	if(prompt.checkCommand(command))
          keepRunning = false;
}



void executions(System& sys)
{
    fileParser processor(sys);
    Prompt prompt;

    bool keepRunning = true;
    std::string command;
    while (keepRunning)
    {
      	prompt.displayPrompt();
		command = prompt.getUserInput();
        userCommand(command, prompt, keepRunning);
		prompt.parseCommand(command, processor, sys);
    }
}

void process(const std::string& file){
  std::unique_ptr<System>& sys = System::getInstance();
  if (!sys)
    throw Error(std::cerr, "System instance is null");
  std::unique_ptr<Processor> processor = std::make_unique<Processor>(*sys);
  if (!processor)
    throw Error(std::cerr, "Processor instance is nul");
  std::ifstream myfile = processor->readFile(file);
    if (!myfile.is_open())
        throw Error(std::cerr,"Failed to open file: " + file);
  processor->treatFile(myfile, *sys);
  executions(*sys);
}







int main (int argc, char* argv[]) {
    try{
        if (argc < 2)
            throw ErrorFile(std::cerr, "Error: File not found");
        else if (argc == 2){
        process(argv[1]);
        }
    } catch (const Error& e){
        std::cerr  << e.what() << std::endl;
        return 84;
    }
    return 0;
}