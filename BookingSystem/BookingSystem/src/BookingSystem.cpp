#include "../include/pch.h"
#include "../include/register.h"
#include "../include/login.h"
int main()
{
    Register registerPage;
    Login loginPage;
    std::cout << "=======================\n";
    std::cout  << "Ready to book your next movie?\n";
    std::cout << "=======================\n";
    std::cout << "Press 'R' to register or 'L' to login: \n";
    char key;
    std::cin >> key;
    if (key == 'r' || key == 'R') {
        registerPage.display();
    }
    else if (key == 'l' || key == 'L') {
        loginPage.display();
    }
    else {
        std::cout << "\nInvalid key. Try again!\n";
    }
	
}

