#pragma once
#include <iostream>
#include <limits>
#include <string>

// it handles when they type text instead of numbers
inline int getIntegerInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.good()) {
            // good input so i clear the rest of the line and return
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        // bad input
        std::cin.clear(); // clear the error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // get rid of the bad input
        std::cout << "Invalid input. Please enter a valid number.\n";
        system("pause");
        // the loop will go again
    }
}