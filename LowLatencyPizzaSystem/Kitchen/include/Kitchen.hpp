//
// Created by bird on 30/11/24.
//

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <iostream>
#include "Pizza.hpp"
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

class Kitchen {
private:
    std::size_t _nbCooks;
    int _stockRecharge;
    bool stopKitchen = false;
    std::vector<std::jthread> _cooks;
    std::queue<Pizza> pizzaQueue;
    std::mutex queueMutex;
    std::condition_variable condition;
    std::chrono::steady_clock::time_point lastTime;
    std::jthread monitorThread;
    int kitchenNumber;

public:
    Kitchen(int cooks, int stockRecharge, int kitchenNumber);
    ~Kitchen();
    void addPizza(const Pizza& order);
    bool canAcceptPizza();
    void cookPizza(Pizza &order, int cookId);
    void stopCooking();
    void monitorInactivity();
    void processOrders(int cookId);

};
#endif //KITCHEN_HPP
