//
// Created by bird on 18/01/25.
//

#include "ErrorPin.hpp"

ErrorPin::ErrorPin(std::ostream& os, const std::string& msg) noexcept
    : Error(os, msg)
{
}

ErrorPin::~ErrorPin() noexcept
{

}

const char* ErrorPin::what() const noexcept
{
    return message.c_str();
}