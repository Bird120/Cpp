//
// Created by bird on 18/01/25.
//
#include "ErrorFile.hpp"


//exemple throw NAME ERROK(std::cerr,message);
ErrorFile::ErrorFile(std::ostream& os, const std::string& msg) noexcept
    : Error(os, msg)
{
}


ErrorFile::~ErrorFile() noexcept
{
}

const char* ErrorFile::what() const noexcept
{
    return message.c_str();
}
