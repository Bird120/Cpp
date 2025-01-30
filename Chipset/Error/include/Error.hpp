//
// Created by bird on 17/01/25.
//

#ifndef ERROR_HPP
#define ERROR_HPP
#include <exception>
#include <string>
class Error: public std::exception
{
protected:
    std::string message;
    std::ostream& ostream;
public:
    Error(std::ostream& os, const std::string& msg) noexcept;
    virtual ~Error() noexcept;
};


#endif //ERROR_HPP
