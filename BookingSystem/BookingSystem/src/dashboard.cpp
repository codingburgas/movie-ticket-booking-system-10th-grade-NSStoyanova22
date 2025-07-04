#include "../include/dashboard.h"


void Dashboard::display(PageHandler& pages) {
    system("CLS");
    checkForNewMovies();
    std::cout << "Hello, " << credentials::firstName << " " << credentials::lastName << std::endl;
    std::cout << "What can we help you with today? \n";
    std::cout << "1 > Search for a movie\n";
    std::cout << "2 > Book a ticket\n";
    std::cout << "3 > View my bookings\n";
    std::cout << "4 > Cancel a booking\n";
    std::cout << "5 > Browse cinema programs\n\n";

    if (ifAdmin(credentials::username)) {
        std::cout << "--- Admin Options ---\n";
        std::cout << "6 > Go to Admin Panel\n\n";
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
        pages.dashboardPageShouldDisplay = false;
        pages.searchPageShouldDisplay = true; 
        break;
    case 2:
        pages.pickACinemaPageShouldDisplay = true;
        pages.dashboardPageShouldDisplay = false;
        break;
    case 3:
        pages.dashboardPageShouldDisplay = false;
        pages.myBookingsPageShouldDisplay = true;
        break;
    case 4:
        pages.dashboardPageShouldDisplay = false;
        pages.myBookingsPageShouldDisplay = true;
        break;
    case 5:
        pages.dashboardPageShouldDisplay = false;
        pages.browsePageShouldDisplay = true;
        break;
    case 6:
        if (ifAdmin(credentials::username)) {
            pages.dashboardPageShouldDisplay = false;
            pages.adminPageShouldDisplay = true;
        }
        else {
            std::cout << "Invalid option.\n";
            system("pause");
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
        std::cout << "You have been signed out!\n\n";
        return;
    default:
        std::cout << "Invalid option.\n";
    }
}

void Dashboard::checkForNewMovies() {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    std::vector<std::string> newMovies;
    std::string latestMovieTitle = "";

    for (const auto& city : data["cities"]) {
        for (const auto& cinema : city["cinemas"]) {
            if (cinema.contains("movies") && !cinema["movies"].empty()) {
                latestMovieTitle = cinema["movies"].back()["title"];
            }
        }
    }

    if (!latestMovieTitle.empty()) {
        std::cout << "!!! NEW MOVIE OUT NOW: " << latestMovieTitle << " !!!\n\n";
    }
}
