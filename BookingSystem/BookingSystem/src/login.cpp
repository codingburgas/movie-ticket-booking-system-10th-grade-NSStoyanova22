#include "../include/login.h"

void Login::display() {
        system("CLS");
        std::cout << "+-----------------------------+\n";
        std::cout << "|           Welcome !         |\n";
        std::cout << "+-----------------------------+\n";

        std::string email, password;


       
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

