
#include "../include/pch.h"
#include "../include/register.h"
#include "../include/login.h"
#include "raylib.h"
#include "../include/bookingSystem.h"

void BookingSystem::display()


{
    
    std::cout << "=======================\n";
    std::cout  << "Ready to book your next movie?\n";
    std::cout << "=======================\n";
   
	
}

void BookingSystem::actionHandler(PageHandler& pages) {
    std::cout << "Press 'R' to register or 'L' to login: \n";
    char key;
    std::cin >> key;
    if (key == 'r' || key == 'R') {
        pages.menuPageShouldDisplay = false;
        pages.registerPageShouldDisplay = true;
    }
    else if (key == 'l' || key == 'L') {
        pages.menuPageShouldDisplay = false;
        pages.loginPageShouldDisplay = true;
    }
    else {
        std::cout << "\nInvalid key. Try again!\n";
    }
}



