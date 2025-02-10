//
// Created by bird on 30/11/24.
//

#include "Parser.hpp"
#include <iostream>
#include "Pizza.hpp"
#include <cstddef>
#include "ErrorFormat.hpp"

Parser::Parser(){

}

Parser::~Parser(){}

PizzaType Parser::convert_to_pizza_type(const std::string& type) {
    if (type == "regina") return Regina;
    if (type == "margarita") return Margarita;
    if (type == "americana") return Americana;
    if (type == "fantasia") return Fantasia;
    throw ErrorFormat(std::cerr, "Invalid pizza type: " + type);
}

PizzaSize Parser::convert_to_pizza_size(const std::string& size) {
    if (size == "S") return S;
    if (size == "M") return M;
    if (size == "L") return L;
    if (size == "XL") return XL;
    if (size == "XXL") return XXL;
    throw ErrorFormat(std::cerr,"Invalid pizza size: " + size);
}




std::vector<Pizza> Parser::separeCommands(const std::string& line){

std::istringstream pizza_stream(line);
std::string order;
std::vector<Pizza> pizzas;

while (getline(pizza_stream, order, ';')){
  //create the input in std::cin in order to facilite parsing
  std::istringstream order_stream(order);
  std::string type_pizza, size_pizza, quantity_pizza;

  if (!(order_stream >> type_pizza >> size_pizza >> quantity_pizza))
    throw ErrorFormat(std::cerr, "Error Format" + type_pizza);
  PizzaType type = convert_to_pizza_type(type_pizza);
  PizzaSize size = convert_to_pizza_size(size_pizza);
  std::size_t num_pizzas = std::stoul(quantity_pizza.substr(1));
 // create X NUMBERS of Pizza from quantity_pizza input.
  for (std::size_t i = 0; i < num_pizzas; i++){
    pizzas.push_back(Pizza(type, size, 1));
      }
	}
return pizzas;
}