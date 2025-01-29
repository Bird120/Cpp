//
// Created by bird on 25/01/25.
//

#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "System.hpp"
#include "Component.hpp"
#include "openfile.hpp"

class Processor {
private:
  System& _sys;
  bool _skipFirstLine;

public:
    Processor(System& sys);
    ~Processor() noexcept;
    std::ifstream readFile(const std::string& file);
    void process(const std::string& file);
    void treatFile(basic_ifstream<char>& myfile, System& sys);

};

#endif //PROCESSOR_HPP
