#include "event.hpp"
#include <iostream>

std::vector<Event> chargeEvents() {
    return {
            {"Merger", "AAPL", "2024-10-20", 5.0},
            {"Financial report", "GOOG", "2024-10-25", -2.0},
            {"Dividendes", "TSLA", "2024-11-01", 1.5}
    };
}

void actifEvent(const std::vector<Event> &events, const std::unordered_map<std::string, Asset> &portfolio) {
    for (const auto& event : events) {
        if (portfolio.find(event.company) != portfolio.end()) {
            std::cout << "Event detected for the asset: " << event.company << std::endl;
            std::cout << "Type: " << event.type << ", Date: " << event.date << ", Estimated impact: " << event.estimated_impact << "%" << std::endl;
        }
    }
}

void modifyPortfolio(const Event& event, std::unordered_map<std::string, Asset>& portfolio) {
    Asset& asset = portfolio[event.company];
    double change = asset.price * (event.estimated_impact / 100.0);

    if (event.estimated_impact > 0) {
        std::cout << "Buy more shares of " << event.company << std::endl;
        asset.quantity += 10;
    } else {
        std::cout << "Sell shares of " << event.company << std::endl;
        asset.quantity -= 10;
    }

    asset.price += change;
}
