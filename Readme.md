# Parking Lot System

A simple command-line based parking lot system implemented in C++.

## Description

This project is a simulation of a parking lot system. It can handle different types of vehicles like cars, trucks, motorcycles, and bicycles. The parking lot has a fixed number of spots for each vehicle type. The system can park and remove vehicles from the parking lot and display the remaining spots.

## Getting Started

### Prerequisites

-   A C++ compiler that supports C++11 (e.g., g++)
-   `make`
-   `gtest` (for running tests)

### Installation

1.  Clone the repository:
    ```bash
    git clone https://github.com/sagar/parking_lot_system.git
    ```
2.  Navigate to the project directory:
    ```bash
    cd parking_lot_system
    ```

## Usage

To build and run the main application, run the following command from the root directory:

```bash
make -C src all
./src/build/parking_lot_system
```

## Running the tests

To run the unit tests, you need to have `gtest` installed. On Debian/Ubuntu, you can install it using:

```bash
sudo apt-get install libgtest-dev
```

Then, run the following command from the root directory:

```bash
make -C src test
```

This will build and run the tests. The test results will be displayed on the console.