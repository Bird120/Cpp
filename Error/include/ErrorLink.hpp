//
// Created by bird on 17/01/25.
//

#ifndef ERRORLINK_HPP
#define ERRORLINK_HPP

#include <iostream>
#include <ostream>

#include "Error.hpp"

class ErrorLink : public Error
{
public:
    ErrorLink(std::ostream &os, const std::string& msg) noexcept;
    ~ErrorLink() noexcept;
    const char* what() const noexcept override;
};
#endif //ERRORLINK_HPP
