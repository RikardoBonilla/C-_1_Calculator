# Calculator Project in C

## Overview

This project is a **Basic Calculator** implemented in the C programming language. It performs simple arithmetic operations such as addition, subtraction, multiplication, and division. The calculator has been extended to include advanced operations like exponentiation and square root, a history of operations, and an improved user interface.

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation and Execution](#compilation-and-execution)
- [Usage](#usage)
- [Examples](#examples)
- [Version Information](#version-information)
- [Future Improvements](#future-improvements)
- [License](#license)

## Features

- **Basic Arithmetic Operations:**
  - Addition
  - Subtraction
  - Multiplication
  - Division
- **Advanced Operations:**
  - Exponentiation
  - Square Root
- **Operation History:**
  - Keeps a record of all operations performed during the session.
- **Improved User Interface:**
  - Clear and formatted output.
  - Color-coded messages (if supported by the terminal).
  - Input validation and error handling.
- **Modular Code Structure:**
  - Separation of concerns using multiple source and header files.

## Project Structure

The project consists of the following files:

- `calculadora.c`: Main program file containing the `main` function and user interaction logic.
- `funciones.c`: Implementation of mathematical functions and utility functions.
- `funciones.h`: Header file declaring functions, constants, and data structures used across the project.
- `README.md`: Project documentation.
- `.gitignore`: Specifies intentionally untracked files to ignore.

## Getting Started

### Prerequisites

- **Operating System:** macOS (development environment)
- **Compiler:** Apple clang version 16.0.0 (clang-1600.0.26.3)
- **Tools:**
  - Command Line Tools for Xcode (includes `gcc` and `make`)

### Compilation and Execution

#### Step 1: Clone the Repository

```bash
git clone https://github.com/your_username/calculadora.git
cd calculadora
gcc -o calculadora calculadora.c funciones.c -lm
./calculadora

