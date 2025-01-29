//
// Created by bird on 25/01/25.
//

#include "Processor.hpp"
#include "ErrorFile.hpp"
#include "Prompt.hpp"

Processor::Processor(System& sys)
    : _sys(sys), _skipFirstLine(false)
{

}
Processor::~Processor() noexcept
{

}


std::ifstream Processor::readFile(const std::string& file){
    std::ifstream myfile(file);
    if (!myfile.is_open())
        throw ErrorFile(std::cerr, "File could not be opened: " + file);
    return myfile;
}


void Processor::treatFile(basic_ifstream<char>& myfile, System& sys)
{
    States states;
    Component chipset;
    std::unique_ptr<fileParser> processor = std::make_unique<fileParser>(states, sys, chipset);

    processor->getLine(myfile, sys);
}

