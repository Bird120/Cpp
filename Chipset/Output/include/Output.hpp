//
// Created by success on 04/12/24.
//

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <unordered_map>
#include <iostream>
#include "nts.hpp"

class Output : public nts::IComponent {
private:
    nts::Tristate _state = nts::Tristate::Undefined;
    std::string _name;
public:
    Output(const std::string& name);
    ~Output();
    //operations
    void simulate(std::size_t tick) override;
    nts::Tristate compute(std::size_t pin) override;
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    void setState(nts::Tristate& states) override;
    const std::string findName(std::size_t pinGate);
};

#endif //OUTPUT_HPP
