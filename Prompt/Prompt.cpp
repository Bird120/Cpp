//
// Created by bird on 24/01/25.
//



#include "Prompt.hpp"
#include <memory>
#include <unordered_map>
#include "ErrorInput.hpp"
#include "Input.hpp"
#include "nts.hpp"

Prompt::Prompt() {

}

Prompt::~Prompt() {

}

bool Prompt::checkCommand(const std::string& command){
    auto it = commands.find(command);
    if (it != commands.end())
      return it->second();
    return false;
}

void Prompt::displayPrompt()
{
    std::cout << "\n> ";
}

const std::string Prompt::getUserInput(){
    std::string input;
    if (!getline(std::cin, input))
        throw ErrorInput(std::cerr,"Error in input");
    return input;
}

void Prompt::circuit(System& sys, std::pair<const std::string, const std::string> element)
{
    auto inputObject = sys.getterInputObject(element.first);
    if (!inputObject) {
            throw Error(std::cerr, "Error no object");
    }

    if (std::stoul(element.second) == 1)
      {
        nts::Tristate state = nts::Tristate::False;
        inputObject->setState(state);
      }
    else if (std::stoul(element.second) == 0)
    {
      nts::Tristate state2 = nts::Tristate::False;
      inputObject->setState(state2);
      }
}

void Prompt::parseCommand(const std::string& command,fileParser& processor, System& sys)
{
    auto element = processor.analyze(command, '=');
    if (!processor.doesInputExist(element.first, sys))
      throw ErrorInput(std::cerr,"A component name is unknown.");
    circuit(sys, element);
}

