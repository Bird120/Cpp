//
// Created by success on 15/12/24.
//

#include "nts.hpp"
#include "OrGate.hpp"
#include <stdexcept>
#include <iostream>
#include "ErrorInput.hpp"

void OrGate::setLink(std::size_t pin, nts::IComponent& component, std::size_t otherpin){
    if( pin < 	Constants::MIN_PIN && pin > Constants::MAX_PIN && pin == Constants::POWER_MIN_PIN && pin == Constants::POWER_MAX_PIN)
        throw ErrorInput(std::cerr, "Invalid pin (out of bounds or power gate pin): " + std::to_string(pin));
    _connections[pin - 1] = {&component, otherpin};
}

nts::Tristate OrGate::getOutputGate(std::size_t pinGate)
{
    return compute(pinGate);
}

OrGate::OrGate() {
}

OrGate::OrGate(const Arguments& args)
       :_args{args._Object, args._pin, args._otherPin}
{
}

OrGate::~OrGate() {
}

nts::Tristate OrGate::evaluatepair(const nts::Tristate& inputA, const nts::Tristate& inputB) {
    // Table de vérité pour l'opérateur OR
    static const std::array<std::array<nts::Tristate, 3>, 3> truthTable = {{
        // inputB = False, True, Undefined
        {nts::Tristate::False, nts::Tristate::True,  nts::Tristate::Undefined},  // inputA = False
        {nts::Tristate::True,  nts::Tristate::True,  nts::Tristate::True},       // inputA = True
        {nts::Tristate::Undefined, nts::Tristate::True, nts::Tristate::Undefined} // inputA = Undefined
    }};

    auto convert = [](nts::Tristate state) -> std::size_t {
        return (state == nts::Tristate::Undefined) ? 2 : static_cast<std::size_t>(state);
    };

    // Retourne le résultat en utilisant la table de vérité
    return truthTable[convert(inputA)][convert(inputB)];

}

nts::Tristate OrGate::compute(std::size_t pin) {


    if (pin ==  3)
        return evaluatepair(_connections[0]._Object->compute(pin), _connections[1]._Object->compute(pin));
    if (pin == 4)
        return evaluatepair(_connections[4]._Object->compute(pin), _connections[5]._Object->compute(pin));
    if (pin == 10)
        return  evaluatepair(_connections[7]._Object->compute(pin), _connections[8]._Object->compute(pin));
    if (pin == 11)
        return  evaluatepair(_connections[11]._Object->compute(pin), _connections[12]._Object->compute(pin));

    return nts::Tristate::Undefined;
}




void OrGate::simulate(std::size_t tick) {
}

void OrGate::setState(nts::Tristate& states)
{
}
