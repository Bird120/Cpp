#include "portfolio.hpp"
#include <iostream>

void simulateStrategie(const std::vector<Event>& events, std::unordered_map<std::string, Asset>& portfolio) {
    for (const auto& event : events) {
        if (portfolio.find(event.company) != portfolio.end()) {
            modifyPortfolio(event, portfolio);
        }
    }
}