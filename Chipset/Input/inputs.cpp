//
// Created by success on 02/12/24.
//
#include <iostream>
#include "Input.hpp"


Input::Input(const std::string& name)
    : _state(nts::Tristate::Undefined), _name(name)
{
}

Input::~Input()
{
}

nts::Tristate Input::get_state() const{
    return _state;
}

void Input::setState(nts::Tristate& states) {
    this->_state = states;
}



void Input::simulate(std::size_t tick) {
(void) tick;
}

nts::Tristate Input::compute(std::size_t pin) {

  (void) pin;
  return this->_state;
}

void Input::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) {

  (void) pin;
  _Object = &other;
  otherPin = otherPin;

}

nts::Tristate Input::getstate() {
  return this->_state;
}