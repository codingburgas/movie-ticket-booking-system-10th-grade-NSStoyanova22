#include "../include/dashboard.h"


void Dashboard::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Hello, " << credentials::firstName << " " << credentials::lastName << std::endl;
    std::cout << "What can we help you with today? \n";
    std::cout << "1 > Search for a movie\n";
    std::cout << "2 > Book a ticket\n";
    std::cout << "3 > View my bookings\n";
    std::cout << "4 > Cancel a booking\n\n";

    if (ifAdmin(credentials::username)) {
        std::cout << "Admin options: \n";
        std::cout << "5 > Manage movies\n";
        std::cout << "6 > Manage shows\n";
        std::cout << "7 > View all bookings\n\n";
    }

    std::cout << "9 > Log out\n";


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Dashboard::setChoice();
}
void Dashboard::setChoice() {
    std::cout << "Choose an option: ";
    std::cin >> choice;
}
void Dashboard::actionHandler(PageHandler& pages) {
  

    switch (choice) {
    case 0:
        if (ifAdmin(credentials::username)) {

        }
        else {
            std::cout << "Invalid option.\n";
        }
        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        if (ifAdmin(credentials::username)) {

        }
        else {
            std::cout << "Invalid option.\n";
        }
        break;
    case 6:
        if (ifAdmin(credentials::username)) {

        }
        else {
            std::cout << "Invalid option.\n";
        }
        break;
    case 7:
        if (ifAdmin(credentials::username)) {

        }
        else {
            std::cout << "Invalid option.\n";
        }
        break;
    case 9:
        credentials::username = "";
        credentials::firstName = "";
        credentials::lastName = "";
        credentials::email = "";
        credentials::password = "";
        pages.menuPageShouldDisplay = true;
        pages.dashboardPageShouldDisplay = false;
        system("CLS");
        std::cout << "You have been signed out!\n";
        return;
    default:
        std::cout << "Invalid option.\n";
    }
}

