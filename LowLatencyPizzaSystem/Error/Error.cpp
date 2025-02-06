//
// Created by bird on 30/11/24.
//

#include "Error.hpp"
#include <stdexcept>
#include <iostream>

#include "Error.hpp"

Error::Error(std::ostream& ostream, const std::string& message) noexcept
	:os(ostream), msg(message)
{
}


Error::~Error()
{
}