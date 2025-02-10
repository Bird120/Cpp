//
// Created by bird on 30/11/24.
//

#include <iostream>
#include "Kitchen.hpp"
#include "Pizza.hpp"
#include <chrono>
//#include <condition_variable>
#include <thread>
Kitchen::Kitchen(int cooks, int stockRecharge, int kitchenNumber)
    : _nbCooks(static_cast<std::size_t>(std::max(0, cooks)) * 2),  _stockRecharge(stockRecharge), stopKitchen(false), kitchenNumber(kitchenNumber) {
    lastTime = std::chrono::steady_clock::now();
	for (int i = 0; i < cooks * 2; ++i) {
          //Create a cook for each jthread
          _cooks.push_back(std::jthread(&Kitchen::processOrders, this, i));
	}
    //monitorThread = std::jthread(&Kitchen::monitorInactivity, this);
}

Kitchen::~Kitchen()
{
}



// add order to the vector of order of type : Pizza
void Kitchen::addPizza(const Pizza& order) {
 //lock to allow only one thread to this scoop
 // in order to not let several threads push at the same time
  std::lock_guard<std::mutex> lock(queueMutex);
  {
    //send a order to the queue(FIFO)
  	pizzaQueue.push(order);
  }
  // send a sign to one only thread from all threads waiting
  condition.notify_one();
}


//method to check if the Kitchen can take more order
//Reception call this method to dispatch correctly the orders
bool Kitchen::canAcceptPizza() {
	std::lock_guard<std::mutex> lock(queueMutex);
	//check size vector jthread
	return  pizzaQueue.size() < (2 * static_cast<std::size_t>(_nbCooks)) ? true : false;
}

//cooking order, retrieve the right time from the order
void Kitchen::cookPizza(Pizza &order, int cookId) {
  {
        std::unique_lock<std::mutex> lock(queueMutex);
        std::cout << "Cooker " << cookId <<  " starts : " << order.type << " " << order.size << std::endl;
  }
     std::this_thread::sleep_for(std::chrono::milliseconds(20));
  {
        std::unique_lock<std::mutex> lock(queueMutex);
        std::cout << "Cooker " << cookId << " ends : " << order.type << " " << order.size << std::endl;
  }
}

// Action to closed the kitchen
void Kitchen::stopCooking() {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        stopKitchen = true;
    }
    // notify cooks that stopKitchen = true
    condition.notify_all();
}

void Kitchen::processOrders(int cookId) {
    while (!stopKitchen) {
      Pizza order(Regina, S, 0);
		{
            //lock the thread in order to access ressource one threead after the other
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this] { return !pizzaQueue.empty() || stopKitchen; });
            if (stopKitchen && pizzaQueue.empty()) break;
            order = pizzaQueue.front();
            pizzaQueue.pop();
		}
            cookPizza(order, cookId);
            if (pizzaQueue.empty())
              stopCooking();
    }
    	std::cout << "Kitchen closed."  << std::endl;
		return;
}


