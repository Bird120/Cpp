//
// Created by success on 03/12/24.
//

#ifndef NTS_HPP
#define NTS_HPP
#include <unordered_map>
#include <functional>
#include "Constants.hpp"

namespace nts {
    enum Tristate {
        Undefined = ( - true ) ,
        True = true ,
        False = false
    };
    class IComponent {
        public :
        virtual ~ IComponent() = default ;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
        virtual void setState(nts::Tristate& state) = 0;
        void create4081() const;
        void create4071() const;
    };
}

enum class ComponentType: int {
        AND4081 = 4081,
        OR4071 = 4071
};


#endif //NTS_HPP
