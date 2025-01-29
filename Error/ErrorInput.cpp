//
// Created by bird on 18/01/25.
//

#include "ErrorInput.hpp"


//exemple throw NAME ERROK(std::cerr,message);
ErrorInput::ErrorInput(std::ostream& os, const std::string& msg) noexcept
    : Error(os, msg)
{
}


ErrorInput::~ErrorInput() noexcept
{
}

const char* ErrorInput::what() const noexcept
{
    return message.c_str();
}
