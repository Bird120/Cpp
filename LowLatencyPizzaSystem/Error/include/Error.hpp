//
// Created by bird on 30/11/24.
//

#ifndef ERROR_HPP
#define ERROR_HPP
#include <iostream>
#include <exception>

class Error: public std::exception {
protected:
	std::ostream& os;
    std::string msg;
public:
  Error(std::ostream& ostream, const std::string& message) noexcept;
  virtual ~Error()  noexcept;
};

#endif //ERROR_HPP
