
//
// Created by success on 04/12/24.
//

#include "Output.hpp"


Output::Output(const std::string& name)
    :_name(name)
{
}

Output::~Output(){}

void Output::simulate(std::size_t tick [[maybe_unused]]){

}

nts :: Tristate Output::compute(std::size_t pin[[maybe_unused]]) {
    return nts::Tristate::Undefined;
}

void Output::setLink(std::size_t pin ,nts::IComponent& other ,std::size_t otherPin) {
    nts::Tristate value  __attribute__((unused)) = other.compute(otherPin);
}

void Output::setState(nts::Tristate& states)
{
  this->_state = states;
}