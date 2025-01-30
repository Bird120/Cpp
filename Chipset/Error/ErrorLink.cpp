//
// Created by bird on 17/01/25.
//

#include "ErrorLink.hpp"

//exemple throw NAME ERROK(std::cerr,message);
ErrorLink::ErrorLink(std::ostream& os, const std::string& msg) noexcept
    : Error(os, msg)
{
}


ErrorLink::~ErrorLink() noexcept
{
}

const char* ErrorLink::what() const noexcept
{
    return message.c_str();
}
