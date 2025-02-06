//
// Created by bird on 30/11/24.
//

#ifndef ERRORCOMMAND_HPP
#define ERRORCOMMAND_HPP

#include "Error.hpp"

class ErrorCommand : public Error {
public:
  ErrorCommand(std::ostream& ostream, const std::string& message) noexcept;
  ~ErrorCommand() noexcept;
  const char* what() const noexcept;
};

#endif //ERRORCOMMAND_HPP
