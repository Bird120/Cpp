//
// Created by bird on 18/01/25.
//

#ifndef ERROROUTPUT_HPP
#define ERROROUTPUT_HPP

#include "Error.hpp"
#include <iostream>
class ErrorOutput: public Error
{
public:
    ErrorOutput(std::ostream& os, const std::string& msg) noexcept;
    ~ErrorOutput() noexcept;
    const char* what() const noexcept;
};
#endif //ERROROUTPUT_HPP
