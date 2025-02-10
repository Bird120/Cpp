//
// Created by bird on 30/11/24.
//

#include "Reception.hpp"
#include "Kitchen.hpp"
#include <unistd.h>   // fork()



Reception::Reception(double multiplier, int cooks, int timeStockRecharge)
  : _multiplier(multiplier), _nbCooks(cooks), _timeStockRecharge(timeStockRecharge)
{
}


Reception::~Reception()
{
  _kitchens.shrink_to_fit();
  kitchenPids.shrink_to_fit();
}


void Reception::dispatchPizzas(const std::vector<Pizza>& pizzas)
{
  for (auto& pizza: pizzas) {
    bool assisgned = false;
    static int number = 0;
    std::unique_ptr<Kitchen> kitchen = std::make_unique<Kitchen>(_nbCooks, _timeStockRecharge, number);
	_kitchens.push_back(std::move(kitchen));
    for (auto& kitchen: _kitchens) {
      if (kitchen->canAcceptPizza() == true) {
        kitchen->addPizza(pizza);
        assisgned = true;
        break;
      	}
      }
      if (!assisgned) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
    }
  }
  return;
}

