//
// Created by bird on 30/11/24.
//

#ifndef PIZZA_HPP
#define PIZZA_HPP

//values adding for potentiel bonus
enum PizzaType {
	Regina = 1,
	Margarita = 2,
	Americana = 4,
	Fantasia = 8
};

//values adding for potentiel bonus
enum PizzaSize {
	S = 1,
	M = 2,
	L = 4,
	XL = 8,
	XXL= 16
};

class Pizza {
public:
	PizzaType type;
	PizzaSize size;
	double timeBaking;
    double multiplier;
	Pizza(PizzaType type_, PizzaSize size_, double multiplier_);
	double calculateTimeBanking();
	double getTime();
};


#endif //PIZZA_HPP
