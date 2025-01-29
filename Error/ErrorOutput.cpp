//
// Created by bird on 18/01/25.
//
#include "ErrorOutput.hpp"


//exemple throw NAME ERROK(std::cerr,message);
ErrorOutput::ErrorOutput(std::ostream& os, const std::string& msg) noexcept
    : Error(os, msg)
{
}


ErrorOutput::~ErrorOutput() noexcept
{
}

const char* ErrorOutput::what() const noexcept
{
    return message.c_str();
}
