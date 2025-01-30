# Compiler
CXX = g++
# Compiler Flags
CXXFLAGS = -std=c++17 -Wall -Werror

# Include directories (headers)
INCLUDE_DIRS = -Iinclude -ISystem/include -IInput/include -IfileParser/include \
 			   -IGates -IOutput/include -IComponent/include	-IError/include \
			   -IGates/include -IPrompt/include -IProcessor/include

CXXFLAGS += $(INCLUDE_DIRS)

# Directories
SRC_DIRS = ./ System Input fileParser Gates Output Error Component Prompt Processor

SRC = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))


MAIN = ./main.cpp


ALL_SRC = $(MAIN) $(filter-out $(MAIN), $(SRC))
# Object files
OBJ = $(ALL_SRC:.cpp=.o)

# executable
TARGET = chipset

# Build the executable
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
# Run the program
run: $(TARGET)
	./$(TARGET)  /home/bird/Téléchargements/nanotekspice30dec/or_gate.nts

# Phony targets
.PHONY: all clean

