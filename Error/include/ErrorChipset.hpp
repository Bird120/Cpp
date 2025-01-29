//
// Created by bird on 24/01/25.
//

#ifndef ERRORCHIPSET_HPP
#define ERRORCHIPSET_HPP

#include <iostream>
#include "Error.hpp"
class ErrorChipset : public Error {
public:
  ErrorChipset(std::ostream& os, const std::string& msg);
  ~ErrorChipset();
  const char* what() const noexcept;

};

#endif //ERRORCHIPSET_HPP
