//
// Created by success on 11/12/24.
//



#include <algorithm>
#include <iostream>
#include "memory"
#include "openfile.hpp"
#include "nts.hpp"
#include "Component.hpp"
#include "System.hpp"
#include "ErrorChipset.hpp"
#include "ErrorInput.hpp"
#include "ErrorOutput.hpp"

std::pair<std::string, std::string> fileParser::analyze(const std::string& line, const char& separator) {
    size_t pos = line.find(separator);
    if(pos != std::string::npos) {
        const std::string first_part = line.substr(0,pos);
        const std::string second_part = line.substr(pos + 1);
        return {first_part, second_part};
    }
    return {"", ""};
}



bool fileParser::doesOutputExist(const std::string& outputName, System& sys){
  const std::string name = sys.gettername();
  return (outputName == name) ? true : false;
}

bool fileParser::doesInputExist(const std::string& input,  System& sys){
  auto it = sys._inputs.find(input);
  return (it != sys._inputs.end()) ?  true :false;
}



bool fileParser::isPairEmpty(std::pair<const std::string, const std::string>& element)
{
  return element.first.empty() && element.second.empty() ? true : false;
}

void fileParser::analyzeLink(std::pair<const std::string, const std::string>& element, System& sys) {
    //From the link definition separate the line in 2 categories: input and gate
    std::pair<const std::string, const std::string> input = analyze(element.first, ':');
    std::pair<const std::string, const std::string> gate = analyze(element.second, ':');
    if(isPairEmpty(input)) return;// Ignore empty input pairs

    // Validate that at least one component in the link exists
    if (!doesInputExist(input.first, sys) && !doesOutputExist(gate.first, sys))
       throw ErrorInput(std::cerr, "A component name is unknown.");


    auto Object = sys.getterStructChipset();  // Retrieve the current chipset instance
   	auto response = sys.checkTypeVariable(input.first);  // Determine the type of input

    if (response == 1){  // Case: Input component
      auto other = sys.getterInputObject(input.first);
      	Object->setLink(std::stoul(gate.second), *other, std::stoul(input.second));
        sys.addGateToInput(input.first, std::stoul(gate.second));
      }
      else if (response == 2){  // Case: Output component
        auto other = sys.getterOutputObject(input.first);
        Object->setLink(std::stoi(gate.second), *other, std::stoi(input.second));

      }
      else if (response == 3){  // Case: Internal component (self-linking)
        Object->setLink(std::stoi(gate.second), *Object, std::stoi(input.second));
        return;
      }

}


void fileParser::sectionLinks(const std::string& line, States& states,  System& sys)
{
   if(line.empty()) return; // Ignore empty lines

   // Make sure a chipset exists before processing links
   if (!sys.getterStructChipset())
      throw ErrorChipset(std::cerr, "No found Chipset");

   std::pair<const std::string, const std::string> element = analyze(line, ' ');
   analyzeLink(element, sys);// Process the extracted link
}


void fileParser::sectionChipset(const std::string& line, System& sys, Component& component)
{
    std::pair<const std::string, const std::string> element = analyze(line, ' ');
    auto it = component.componentCreator.find(element.first);
    if(it != component.componentCreator.end())
    {
      sys.setterStructChipset(component.createComponent(element.first), element.second);
    }
    component.chipsetSection(element, sys);
}

