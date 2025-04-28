#include "../include/register.h"

void Register::display() {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|           Welcome !         |\n";
    std::cout << "+-----------------------------+\n";

    std::string username, firstName, lastName, email, password;


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Username: ";
    getline(std::cin, username);
    while (username.empty()) {
        std::cout << "Username cannot be empty!\n";
        std::cout << "Username: ";
        getline(std::cin, username);
    }

    std::cout << "First name: ";
    getline(std::cin, firstName);
    while (firstName.empty()) {
        std::cout << "First name cannot be empty!\n";
        std::cout << "First name: ";
        getline(std::cin, firstName);
    }

    std::cout << "Last name: ";
    getline(std::cin, lastName);
    while (lastName.empty()) {
        std::cout << "Last name cannot be empty!\n";
        std::cout << "Last name: ";
        getline(std::cin, lastName);
    }

    std::cout << "Email: ";
    getline(std::cin, email);
    while (email.empty()) {
        std::cout << "Email cannot be empty!\n";
        std::cout << "Email: ";
        getline(std::cin, email);
    }

    std::cout << "Password: ";
    getline(std::cin, password);
    while (password.empty()) {
        std::cout << "Password cannot be empty!\n";
        std::cout << "Password: ";
        getline(std::cin, password);
    }



}