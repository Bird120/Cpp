//
// Created by bird on 02/02/25.
//

#ifndef ERRORFORMAT_HPP
#define ERRORFORMAT_HPP
#include "Error.hpp"
#include <iostream>

class ErrorFormat : public Error {
  public:
   ErrorFormat(std::ostream& ostream, const std::string& message) noexcept;
   ~ErrorFormat();
   const char* what() const noexcept;
};


#endif //ERRORFORMAT_HPP
