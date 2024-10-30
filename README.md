Basic C Calculator
This is a basic calculator program written in C that allows you to perform the following operations:

Addition
Subtraction
Multiplication
Division
Power
Square root
Operations history
Project files
calculator.c: Contains the main code and the user interface.
functions.c: Implements the mathematical and history functions.
functions.h: Declarations of functions, structures and constants used.
Compilation and execution
To compile and run the program, use the following commands in the terminal:

bash
Copy code
gcc calculator.c functions.c -o calculator -lm
./calculator
Note: The -lm flag is required to link the maths library.

Compiler version
This program was compiled and tested with:

yaml
Copy code
Apple clang version 16.0.0 (clang-1600.0.26.3)
Target: x86_64-apple-darwin24.0.0
Thread model: posix
Usage
When you run the program, an interactive menu will appear where you can select the operation you want to perform and enter the corresponding numbers. You can also view the history of operations performed during the session.

Translated with DeepL.com (free version)
