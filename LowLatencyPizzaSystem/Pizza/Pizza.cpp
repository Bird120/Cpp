//
// Created by bird on 30/11/24.
//

#include "Pizza.hpp"
#include <unordered_map>

Pizza::Pizza(PizzaType type_, PizzaSize size_, double multiplier_)
	: type(type_), size(size_), multiplier(multiplier_)
{
	timeBaking =  calculateTimeBanking();
}

double Pizza::calculateTimeBanking(){
    static const std::unordered_map<PizzaType, double> bakingMap = {
        {Regina, 2000}, {Americana, 2000}, {Margarita, 1000}, {Fantasia, 4000}
    };

	auto it = bakingMap.find(type);
    double baseTime = (it != bakingMap.end()) ? it->second : 0;

    return baseTime * multiplier;
}


double Pizza::getTime(){
  return timeBaking;
}
