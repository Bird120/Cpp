//
// Created by success on 10/12/24.
//

#include "AndGate.hpp"
#include <iostream>
#include "nts.hpp"
#include <stdexcept>
#include "ErrorPin.hpp"



AndGate::AndGate(): _args{nullptr, 0, 0}
{
}

AndGate::AndGate(const Arguments& args)
       :_args{args._Object, args._pin, args._otherPin}
{
}

AndGate::~AndGate()
{
}

void AndGate::checkGate(std::size_t pin){
    if (Constants::POWER_MIN_PIN == pin || Constants::POWER_MAX_PIN == pin)
        throw ErrorPin(std::cerr, "Pin: " + std::to_string(pin) + " use for supply power");
    if (pin < Constants::MIN_PIN || Constants::MAX_PIN < pin)
        throw ErrorPin(std::cerr, "Pin: " + std::to_string(pin) + " out of range");
}

void AndGate::setLink(std::size_t pin, nts::IComponent& component, std:: size_t otherpin) {
    if (Constants::POWER_MIN_PIN == pin || Constants::POWER_MAX_PIN == pin)
       throw ErrorPin(std::cerr, "Pin: " + std::to_string(pin) + " use for supply power");
    if (pin < Constants::MIN_PIN || Constants::MAX_PIN < pin)
       throw ErrorPin(std::cerr, "Pin: " + std::to_string(pin) + " out of range");
    _connections[pin - 1]._Object = &component;
    _connections[pin - 1]._pin = pin;
    _connections[pin - 1]._otherPin = otherpin;
}


nts::Tristate AndGate::compute(std::size_t pin) {
    if (pin == 3)
        return evaluatepair(_connections[0]._Object->compute(pin), _connections[1]._Object->compute(pin));
    if (pin == 4)
        return evaluatepair(_connections[4]._Object->compute(pin), _connections[3]._Object->compute(pin));
    if (pin == 10)
        return evaluatepair(_connections[7]._Object->compute(pin), _connections[8]._Object->compute(pin));
    if (pin == 11)
        return evaluatepair(_connections[11]._Object->compute(pin), _connections[12]._Object->compute(pin));
    return nts::Tristate::Undefined;
}

nts::Tristate AndGate::evaluatepair(const nts::Tristate& inputA, const nts::Tristate& inputB) {
    // Table de vérité pour l'opérateur AND
    static const std::array<std::array<nts::Tristate, 3>, 3> truthTable = {{
        // inputB = False, True, Undefined
        {nts::Tristate::False, nts::Tristate::False, nts::Tristate::False},    // inputA = False
        {nts::Tristate::False, nts::Tristate::True,  nts::Tristate::Undefined},// inputA = True
        {nts::Tristate::False, nts::Tristate::Undefined, nts::Tristate::Undefined} // inputA = Undefined
    }};

  auto convert = [](nts::Tristate state) -> std::size_t {
    return (state == nts::Tristate::Undefined) ? 2 : static_cast<std::size_t>(state);
    };
  return truthTable[convert(inputA)][convert(inputB)];
}

void AndGate::simulate(std::size_t tick) {
    tick++;
}

void AndGate::setState(nts::Tristate& states)
{
}
