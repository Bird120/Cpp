cmake_minimum_required(VERSION 3.28)
project(Portfolio)

set(CMAKE_CXX_STANDARD 17)

# Add the header file directory
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Portfolio src/main.cpp
        src/event.cpp
        src/portfolio.cpp
        src/strategie.cpp
        include/event.hpp
        include/portfolio.hpp)
