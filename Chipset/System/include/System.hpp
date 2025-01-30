//
// Created by bird on 07/01/25.
//

#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include "nts.hpp"
#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
#include <mutex>

class System: public nts::IComponent
{
private:
	System(const System&) = delete;
	System& operator=(const System&) = delete;

	// Private constructor to prevent external instantiation

	// Delete copy and move constructors/operators to enforce singleton
	System(System&&) = delete;
	System& operator=(System&&) = delete;
	static std::unique_ptr<System> instance;
	static std::once_flag initInstanceFlag;

    struct Chipset{
  		std::unique_ptr<nts::IComponent> objectChipset;
  		std::string name;
	 };
     std::unique_ptr<Chipset> structChipset = std::make_unique<Chipset>();

public:
     System() = default;
     ~System();
     std::unordered_map<std::string, std::pair<std::unique_ptr<nts::IComponent>, std::size_t>> _inputs;
     std::unordered_map<std::string, std::pair<std::unique_ptr<nts::IComponent>, std::size_t>> _outputs;

     // Public method to get the singleton instance
     static std::unique_ptr<System>& getInstance() {
          if(!instance)
              instance = std::make_unique<System>();
          return instance;
     }
	 void setterStructChipset(std::unique_ptr<nts::IComponent> objectChipset, const std::string& name) const noexcept;
     nts::IComponent* getterStructChipset() const noexcept;
     const std::string gettername() const noexcept;
	 nts::IComponent* getterObject(const std::unordered_map<std::string, std::pair<std::unique_ptr<nts::IComponent>, std::size_t>> &map, const std::string& nameInput);

	 nts::IComponent* getterInputObject(const std::string& nameInput);
	 nts::IComponent* getterOutputObject(const std::string& nameInput);
     void addGateToInput(const std::string& name, std::size_t pin);

     std::size_t checkTypeVariable(const std::string& name);
     void setterInput(const std::string& name, std::unique_ptr<nts::IComponent> other);
     void setterOutput(const std::string& name, std::unique_ptr<nts::IComponent> other);
     void simulate(std::size_t tick) override;
     nts::Tristate compute(std::size_t pin) override;
     void setLink(std::size_t pin ,nts::IComponent & other ,std::size_t otherPin) override;
     void setState(nts::Tristate& states) override;
};

#endif //SYSTEM_HPP
