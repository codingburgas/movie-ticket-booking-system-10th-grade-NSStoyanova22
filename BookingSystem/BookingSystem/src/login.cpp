#include "../include/login.h"

void Login::display() {
        system("CLS");
        std::cout << "+-----------------------------+\n";
        std::cout << "|           Welcome !         |\n";
        std::cout << "+-----------------------------+\n";
       

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Login::inputCreds();



    }

void Login::inputCreds() {
    std::cout << "Username: ";
    getline(std::cin, credentials::username);
    while (credentials::username.empty()) {
        std::cout << "Username cannot be empty!\n";
        std::cout << "Username: ";
        getline(std::cin, credentials::username);
    }

    std::cout << "Email: ";
    getline(std::cin, credentials::email);
    while (!checkEmail(credentials::email)) {
        std::cout << "Input valid email!\n";
        std::cout << "Email: ";
        getline(std::cin, credentials::email);
    }

    std::cout << "Password: ";
    hidePassword(credentials::password);
    while (!checkPassword(credentials::password)) {
        std::cout << "Invalid password!\n";
        std::cout << "Password: ";
        hidePassword(credentials::password);
    }

    Login::checkCreds();
}

void Login::checkCreds() {

    if (!loginUser(credentials::username, credentials::email, credentials::password)) {
        system("CLS");
        std::cout << "+-----------------------------+\n";
        std::cout << "|           Welcome !         |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "Incorrect credentials. Try again!\n";
        credentials::username = "";
        credentials::firstName = "";
        credentials::lastName = "";
        credentials::email = "";
        credentials::password = "";

        Login::inputCreds();
    }
}

