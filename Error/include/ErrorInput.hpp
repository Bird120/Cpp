//
// Created by bird on 18/01/25.
//

#ifndef ERRORINPUT_HPP
#define ERRORINPUT_HPP

#include <iostream>
#include "Error.hpp"

class ErrorInput : public Error
{
public:
    ErrorInput(std::ostream& os, const std::string& msg) noexcept;
    ~ErrorInput() noexcept;
    const char* what() const noexcept;
};
#endif //ERRORINPUT_HPP
