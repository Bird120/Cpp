#ifndef PORTFOLIO_HPP
#define PORTFOLIO_HPP

#include "event.hpp"
#include <unordered_map>

std::unordered_map<std::string, Asset> chargePortfolio();
void displayPortfolio(const std::unordered_map<std::string, Asset>& porfolio);
void simulateStrategie(const std::vector<Event>& events, std::unordered_map<std::string, Asset>& portfolio);


#endif //PORTFOLIO_HPP
