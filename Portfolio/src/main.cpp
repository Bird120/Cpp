#include <iostream>
#include "event.hpp"
#include "portfolio.hpp"

int main() {
    // Load events and the portfolio
    const auto events = chargeEvents();
    auto portfolio = chargePortfolio();

    // Display the portfolio before adjustment
    displayPortfolio(portfolio);

    // Detect relevant events for the portfolio
    actifEvent(events, portfolio);

    // Simulate the investment strategy based on events
    simulateStrategie(events, portfolio);

    // Display the portfolio after adjustment
    std::cout << "\nPortfolio after adjustment: " << std::endl;
    displayPortfolio(portfolio);

    return 0;
}
