//
// Created by bird on 30/11/24.
//

#include "ErrorCommand.hpp"

ErrorCommand::ErrorCommand(std::ostream& ostream, const std::string& message) noexcept
    : Error(ostream, message)
{}

ErrorCommand::~ErrorCommand() noexcept
{}

const char* ErrorCommand::what() const noexcept
{
    return msg.c_str();
}