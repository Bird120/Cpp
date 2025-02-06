# compiler has jthread
CXX = g++-13
# Compiler Flags
CXXFLAGS = -std=c++20 -Wall -Werror -pthread

# include directories (headers)
INCLUDE_DIRS = -IPizza/include -IKitchen/include -IParser/include \
 			   -IReception/include -IStock/include  -IError/include

CXXFLAGS += $(INCLUDE_DIRS)

# directories
SRC_DIRS = ./ Stock Reception Parser Kitchen  Error Pizza Prompt

SRC = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))


MAIN = ./main.cpp


ALL_SRC = $(MAIN) $(filter-out $(MAIN), $(SRC))

# object files
OBJ = $(ALL_SRC:.cpp=.o)
# executable
TARGET = pizza

# build the executable
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
# run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean

