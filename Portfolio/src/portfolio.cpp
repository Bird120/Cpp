#include "portfolio.hpp"
#include <iostream>

std::unordered_map<std::string, Asset> chargePortfolio() {
    return {
            {"AAPL", {"AAPL", 150.0, 100}},
            {"GOOG", {"GOOG", 2800.0, 50}},
            {"TSLA", {"TSLA", 700.0, 75}}
    };
}

void displayPortfolio(const std::unordered_map<std::string, Asset> &portfolio) {
    std::cout << "Current portfolio: " << std::endl;
    for (const auto& asset : portfolio) {
        std::cout << "Symbol: " << asset.second.symbol << ", Price: " << asset.second.price << ", Quantity: "
        << asset.second.quantity << std::endl;
    }
}