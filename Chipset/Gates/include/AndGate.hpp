//
// Created by success on 10/12/24.
//

#ifndef ANDGATE_HPP
#define ANDGATE_HPP

#include "nts.hpp"
#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <memory>

struct Connect {
    nts::IComponent& component;
};


class AndGate: public nts::IComponent {
private:
    std::size_t __attribute__((unused)) tick = 0;
    struct Arguments{
        nts::IComponent*  _Object;
        std::size_t _pin;
        std::size_t _otherPin;
     };
    Arguments _args;
    Arguments _connections[14];
public:
    AndGate();
    explicit AndGate(const Arguments& args);
    ~AndGate();
    void setLink(std::size_t pin, nts::IComponent& component, std::size_t otherpin) override;
    nts::Tristate compute(std::size_t pin) override;
    void simulate(std::size_t tick) override;
    nts::Tristate evaluatepair(const nts::Tristate& inputA, const nts::Tristate& inputB);
    void checkGate(std::size_t pin);
    void setState(nts::Tristate& states) override;

};


#endif //ANDGATE_HPP
