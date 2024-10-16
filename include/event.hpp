#ifndef EVENEMENT_HPP
#define EVENEMENT_HPP

#include <string>
#include <vector>
#include <unordered_map>

struct Event {
    std::string type;
    std::string company;
    std::string date;
    double estimated_impact;
};

struct Asset {
    std::string symbol;
    double price;
    double quantity;
};

std::vector<Event> chargeEvents();
void actifEvent(const std::vector<Event>& events, const std::unordered_map<std::string, Asset>& portfolio);
void modifyPortfolio(const Event& event, std::unordered_map<std::string, Asset>& portfolio);

#endif //EVENEMENT_HPP
