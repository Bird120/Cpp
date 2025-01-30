//
// Created by bird on 20/01/25.
//

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "nts.hpp"
#include <memory>
#include <iostream>
#include <unordered_map>
#include <functional>
#include "OrGate.hpp"
#include "AndGate.hpp"
#include "System.hpp"

class Component
{
  public:
    static const std::unordered_map<std::string,std::function<std::unique_ptr<nts::IComponent>()>> componentCreator;
    static std::unique_ptr<nts::IComponent> createComponent(const std::string& type);
    void chipsetSection(std::pair<const std::string, const std::string> element, System& sys);

};

#endif //COMPONENT_HPP
