//
// Created by bird on 20/01/25.
//
//
// Created by success on 12/12/24.
//

#include <stdexcept>
#include <unordered_map>
#include <functional>
#include <memory>
#include "Component.hpp"
#include "Error.hpp"

const std::unordered_map<std::string,std::function<std::unique_ptr<nts::IComponent>()>> Component::componentCreator = {
    {"4081", []() { return std::make_unique<AndGate>(); }},
    {"4071", []() { return std::make_unique<OrGate>(); }}
};

std::unique_ptr<nts::IComponent> Component::createComponent(const std::string& type) {
    auto it = componentCreator.find(type);
    if(it != componentCreator.end()) {
        return it->second();
    }
    else
      throw Error(std::cerr, " Chipset" + type + "does not exist:");
    return nullptr;
}
