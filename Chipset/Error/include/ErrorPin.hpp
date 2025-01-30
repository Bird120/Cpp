//
// Created by bird on 18/01/25.
//

#ifndef ERRORPIN_HPP
#define ERRORPIN_HPP

#include <iostream>
#include "Error.hpp"
class ErrorPin : public Error
{
public:
    ErrorPin(std::ostream& os, const std::string& msg) noexcept;
    ~ErrorPin() noexcept;
    const char* what() const noexcept;
};
#endif //ERRORPIN_HPP
