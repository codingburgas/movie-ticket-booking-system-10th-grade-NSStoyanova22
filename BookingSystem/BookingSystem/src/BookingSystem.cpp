#include "../include/pch.h"

int main()
{
    std::cout << "=======================\n";
    std::cout  << "Ready to book your next movie?\n";
    std::cout << "=======================\n";
    std::cout << "Press 'R' to register or 'L' to login: \n";
    char key = _getch();
    if (key == 'r' || key == 'R') {
     
    }
    else if (key == 'l' || key == 'L') {

    }
    else {
        std::cout << "\nInvalid key. Try again!\n";
    }
	
}

