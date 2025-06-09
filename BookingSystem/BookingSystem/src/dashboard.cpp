#include "../include/dashboard.h"


void Dashboard::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Hello, \n" << credentials::firstName << " " << credentials::lastName << std::endl;
    if (ifAdmin(credentials::username)) {
        std::cout << "ADMIN!!!!!!!!!!!!";
    }



}

