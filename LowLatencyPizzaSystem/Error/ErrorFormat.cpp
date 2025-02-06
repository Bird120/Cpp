//
// Created by bird on 02/02/25.
//
#include "ErrorFormat.hpp"
#include <iostream>

ErrorFormat::ErrorFormat(std::ostream& ostream, const std::string& message) noexcept
    : Error(ostream, message)
{
}

ErrorFormat::~ErrorFormat() noexcept
{
}


const char* ErrorFormat::what() const noexcept
{
   return msg.c_str();
}