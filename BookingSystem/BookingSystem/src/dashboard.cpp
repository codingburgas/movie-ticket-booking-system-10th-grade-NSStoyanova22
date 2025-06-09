#include "../include/dashboard.h"


void Dashboard::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Hello, " << credentials::firstName << " " << credentials::lastName << std::endl;
    std::cout << "What can we help you with today? \n";
    std::cout << "1 > Search for a movie\n";
    std::cout << "2 > Book a ticket\n";
    std::cout << "3 > View my bookings\n";
    std::cout << "4 > Cancel a booking\n";

    if (ifAdmin(credentials::username)) {
        std::cout << "5 > Manage movies\n";
        std::cout << "6 > Manage shows\n";
        std::cout << "7 > View all bookings\n";
    }

    std::cout << "9 > Log out\n";


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void Dashboard::actionHandler(PageHandler& pages) {

}

