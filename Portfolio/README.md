# Event-Driven Asset Management - C++ Project

## Overview

This project simulates an event-driven asset management system. The system monitors specific corporate events (e.g., mergers, earnings reports, dividend announcements) and simulates investment strategies based on these events, adjusting a portfolio accordingly.

## Features

- Monitors corporate events such as mergers, earnings reports, and dividends.
- Detects relevant events for a given portfolio.
- Simulates investment strategies (buy/sell actions) based on the impact of the event on asset prices.
- Displays alerts and portfolio adjustments.

## Project Structure

- `src/`: Contains the source files for the project.
    - `main.cpp`: The main program.
    - `event.cpp`: Implements functions for event handling.
    - `portfolio.cpp`: Implements functions for portfolio adjustment.
    - `strategie.cpp`: Implements the investment strategy based on detected events.
- `include/`: Contains the header files for the project.
    - `event.hpp`: Defines the structures for events and assets.
    - `portfolio.hpp`: Functions related to portfolio management.
- `data/`: Placeholder for data files (such as CSV) that will be used for events and assets in future updates (not yet utilized).

## How to Run

1. **Generate Build Files Using CMake:**
   Open a terminal and navigate to the root of the project directory. Run the following command to create a build directory and generate the necessary files:

```bash
mkdir build                    # Create a build directory at the root of the project folder
```

```bash
cd build                       # Change to the build directory
```

```bash
cmake ..                       # Configure the project and generate makefiles
```

```bash
make                           # Compile the project
```

```bash
./Portfolio                    # Run the compiled executable
```
2. **IDE Automation:**
  For users utilizing IDEs such as CLion, there is no need to manually do  1., as the IDE handles this automatically."
