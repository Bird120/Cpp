//
// Created by success on 02/12/24.
//

#ifndef INPUT_HPP
#define INPUT_HPP

#include "openfile.hpp"
#include "nts.hpp"
#include <unordered_map>

class Input : public nts::IComponent {
private:
    nts::Tristate _state = nts::Tristate::Undefined;
    std::string _name;
    nts::IComponent*  _Object = nullptr;
    std::size_t _otherPin;

public:
    Input(const std::string& name);
    ~Input();

    void setInput(const std::string& inputName, const std::pair<std::size_t,std::size_t>& gates);
    std::unordered_map<std::string, std::pair<std::size_t, std::size_t>> getInputVariables();

    //Operations
    void simulate(std :: size_t tick) override;
    nts::Tristate compute(std :: size_t pin) override;
    void setLink(std::size_t pin ,nts::IComponent& other ,std::size_t otherPin) override;

    //Input value management
    void add_value(nts::Tristate& value);
    void input(const std::string& line);
    void checkInputExist(std::string& element, nts::IComponent& component);
    void setState(nts::Tristate& states) override;
    nts::Tristate get_state() const;
    nts::Tristate getstate();

};

#endif //INPUT_HPP
