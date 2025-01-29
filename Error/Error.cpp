//
// Created by bird on 14/01/25.
//

#include <iostream>
#include <stdexcept>
#include "Error.hpp"
#include <iostream>

Error::Error(std::ostream& os, const std::string& msg) noexcept
    : message(msg), ostream(os)
{

}

Error::~Error()
{

}

/*int main()
{
    try
    {
        throw ErrorLink(std::cerr, "erreur de link");
    }catch (const Error& e){
        std::cout << "catch dedans ?"<< std::endl;
        std::cout << e.what();
    }
    return 0;
}*/