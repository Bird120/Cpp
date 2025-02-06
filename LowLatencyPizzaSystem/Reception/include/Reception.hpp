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
    std::vector<Kitchen*> _kitchens;

public:
    Reception(double multiplier, int cooks, int timeStockRecharge);
    ~Reception();
    int ckeckArguments(char **argv);
    void dispatchPizzas(const std::vector<Pizza>& pizzas);
    void run();
    const std::string getUserInput();
    void checkArguments(char **argv);

};


#endif //RECEPTION_HPP
