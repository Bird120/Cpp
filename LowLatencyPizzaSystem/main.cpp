
#include "Parser.hpp"
#include <iostream>
#include "ErrorCommand.hpp"
 #include "Reception.hpp"

void prompt(){
      std::cout << "> ";
}

const std::string getUserInput(){
  std::string line;
  if (!getline(std::cin, line))
    throw ErrorCommand(std::cerr, "Invalid command");
  return line ;
}


int execute(char* argv[]){
  Parser* parser = new Parser();
  Reception* reception = new Reception(std::stod(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]));
  bool keepRunning = true;
  while (keepRunning){
      prompt();
	  const std::string line = getUserInput();
          reception->dispatchPizzas(parser->separeCommands(line));
          break;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
	return 1;
  }
  execute(argv);

}