//
// Created by bird on 30/11/24.
//

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <iostream>
#include <vector>

#include "Kitchen.hpp"
#include <vector>
#include "Pizza.hpp"

class Reception
{
private:
    double _multiplier;
    int _nbCooks;
    int _timeStockRecharge;
    //std::vector<Kitchen*> _kitchens;
    std::vector<std::unique_ptr<Kitchen>> _kitchens;
    std::vector<pid_t> kitchenPids;
public:
    Reception(double multiplier, int cooks, int timeStockRecharge);
    ~Reception();
    int ckeckArguments(char **argv);
    void dispatchPizzas(const std::vector<Pizza>& pizzas);
    void run();
    const std::string getUserInput();
    void checkArguments(char **argv);
    void createKitchen(const Pizza& pizza, int number);


};


#endif //RECEPTION_HPP
