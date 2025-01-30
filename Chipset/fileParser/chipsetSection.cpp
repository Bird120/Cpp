//
// Created by success on 13/12/24.
//

#include "openfile.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "System.hpp"
#include <typeinfo>
#include <cstring>
#include "Component.hpp"

void Component::chipsetSection(std::pair<const std::string, const std::string> element, System& sys) {
    //add inputs outputs on class assembly
    if (element.first == "input"){
        //create a Input for each input
        std::unique_ptr<nts::IComponent> input = std::make_unique<Input>(element.second);
        sys.setterInput(element.second, std::move(input));
    }
    else if (std::strcmp("output", element.first.c_str()) == 0)
    {
        std::unique_ptr<nts::IComponent> output = std::make_unique<Output>(element.second);
        sys.setterOutput(element.second, std::move(output));
    }
}

