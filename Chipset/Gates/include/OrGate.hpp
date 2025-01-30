//
// Created by success on 12/12/24.
//

#ifndef ORGATE_HPP
#define ORGATE_HPP
#include "nts.hpp"
#include <iostream>
#include <memory>
#include <map>
#include <set>

class OrGate: public nts::IComponent {
private:
    struct Arguments{
        nts::IComponent*  _Object;
        std::size_t _pin;
        std::size_t _otherPin;
    };
    Arguments _args;
    Arguments _connections[14];
public:
    OrGate();
    explicit OrGate(const Arguments& args);
    ~OrGate();
    //const std::map<std::set<std::size_t>, std::size_t> commandes;
    nts::Tristate evaluatepair(const nts::Tristate& inputA, const nts::Tristate& inputB);
    void setLink(std::size_t pin,nts::IComponent& component, std::size_t otherpin) override;
    nts::Tristate compute(std::size_t pin) override;
    void simulate(std::size_t tick) override;
    nts::Tristate getOutputGate(std::size_t pinGate);
    void setState(nts::Tristate& states) override;
    const std::map<std::set<std::size_t>, std::size_t> commandes = {
    {{1, 2}, 3},
    {{5, 6}, 4},
    {{10, 9}, 8}
};
};

constexpr std::size_t MIN_PIN = 1;
constexpr std::size_t MAX_PIN = 14;
constexpr std::size_t POWER_MIN_PIN = 7;
constexpr std::size_t POWER_MAX_PIN = 14;

#endif //ORGATE_HPP