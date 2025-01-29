//
// Created by bird on 24/01/25.
//

#include "ErrorChipset.hpp"

ErrorChipset::ErrorChipset(std::ostream& os, const std::string& msg)
    :Error(os, msg) {
 }
 ErrorChipset::~ErrorChipset() {

 }

 const char* ErrorChipset::what() const noexcept
 {
     return message.c_str();
 }