//
// Created by bird on 07/01/25.
//

#include "System.hpp"
#include <iostream>
#include <unordered_map>
#include "ErrorInput.hpp"


System::~System()
{
}



std::size_t System::checkTypeVariable(const std::string& name)
{
	if (name == gettername()) return 0;
    bool inInputs = _inputs.find(name) != _inputs.end();
    bool inOutputs = _outputs.find(name) != _outputs.end();
    if (inInputs && inOutputs){
      throw ErrorInput(std::cerr, "Both an Input and Output, impossible");
    }
   	return inInputs ? 1 : 2;

}

nts::IComponent* System::getterObject(const std::unordered_map<std::string, std::pair<std::unique_ptr<nts::IComponent>, std::size_t>> &map, const std::string& nameInput)
{
/*	auto it = _inputs.find(nameInput);
	if (it != _inputs.end())
		return it->second.first;
	return nullptr;*/

    auto it = map.find(nameInput);
    if (it != map.end()) {
        if (it->second.first == nullptr) {
            std::cerr << "ERREUR: L'objet " << nameInput << " est NULL !" << std::endl;
            return nullptr;
        }
        return it->second.first.get();
    }
    std::cerr << "ERREUR: L'élément " << nameInput << " n'a pas été trouvé dans la map." << std::endl;
    return nullptr;
}

nts::IComponent* System::getterInputObject(const std::string& nameInput){
	return getterObject(_inputs, nameInput);
}


nts::IComponent* System::getterOutputObject(const std::string& nameInput){
	return getterObject(_outputs, nameInput);
}


void System::addGateToInput(const std::string& name, std::size_t pin)
{
    auto it = _inputs.find(name);
    if (it != _inputs.end())
      it->second.second = pin;

}

void System::setterInput(const std::string& name, std::unique_ptr<nts::IComponent> other)
{
 _inputs[name]= {std::move(other), 0};
}



void System::setterOutput(const std::string& name, std::unique_ptr<nts::IComponent> other)
{
 _outputs[name] = {std::move(other), 0};

}

void System::simulate(std::size_t tick){}

nts::Tristate System::compute(std::size_t pin)
{
    return nts::True;
}
void System::setLink(std::size_t pin ,nts::IComponent & other ,std::size_t otherPin) {}

void System::setterStructChipset(std::unique_ptr<nts::IComponent> objectChipset, const std::string& name) const noexcept
{
  structChipset->objectChipset = std::move(objectChipset);
  structChipset->name = name;
}


nts::IComponent* System::getterStructChipset() const noexcept
{
      if (!structChipset) {
        std::cerr << "ERREUR: structChipset est NULL !" << std::endl;
        return nullptr;
    }
    if (!structChipset->objectChipset) {
        std::cerr << "ERREUR: objectChipset est NULL !" << std::endl;
        return nullptr;
    }

    return structChipset->objectChipset.get();
  //return structChipset->objectChipset ? structChipset->objectChipset.get() : nullptr;
}

const std::string System::gettername() const noexcept
{
    return structChipset->name;
}

void System::setState(nts::Tristate& states)
{
}
