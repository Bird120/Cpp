//
// Created by bird on 30/11/24.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include "Pizza.hpp"
#include <vector>
#include <sstream>

class Parser {
public:
  Parser();
  ~Parser();
  std::vector<Pizza> separeCommands(const std::string& line);
  Pizza orderToPizza(std::string order);
  PizzaType convert_to_pizza_type(const std::string& type);
  PizzaSize convert_to_pizza_size(const std::string& size);
private:


};
#endif //PARSER_HPP
