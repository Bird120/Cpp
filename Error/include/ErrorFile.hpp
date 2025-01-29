//
// Created by bird on 18/01/25.
//

#ifndef ERRORFILE_HPP
#define ERRORFILE_HPP

#include <iostream>
#include "Error.hpp"

class ErrorFile : public Error
{
public:
    ErrorFile(std::ostream& os, const std::string& msg) noexcept;
    ~ErrorFile() noexcept;
    const char* what() const noexcept;
};
#endif //ERRORFILE_HPP
