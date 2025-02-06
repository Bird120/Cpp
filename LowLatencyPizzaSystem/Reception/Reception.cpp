//
// Created by bird on 30/11/24.
//

#include "Reception.hpp"
#include "Kitchen.hpp"

Reception::Reception(double multiplier, int cooks, int timeStockRecharge)
  : _multiplier(multiplier), _nbCooks(cooks), _timeStockRecharge(timeStockRecharge)
{
}

Reception::~Reception()
{
  //destruction of the objects (contents) and free the memory allocated inside each objects
  for (auto kitchen: _kitchens)
    delete kitchen;
  // in order to return to 0 the capacity (space allocate: Reserved Space) from std::vector()
  _kitchens.shrink_to_fit();
}




void Reception::dispatchPizzas(const std::vector<Pizza>& pizzas)
{
  for (auto& pizza: pizzas) {
    bool assisgned = false; // order not distributed yet
    for (auto& kitchen: _kitchens) {
      if (kitchen->canAcceptPizza()) { //if kitchen not full
        kitchen->addPizza(pizza); // send pizza
        assisgned = true;   //now order distributed
        break;
        }
      }
      if (!assisgned) { // no cuisine available , create one
        Kitchen* newKitchen = new Kitchen(_nbCooks, _timeStockRecharge);
        _kitchens.push_back(newKitchen);
        newKitchen->addPizza(pizza);
    }
  }
}

