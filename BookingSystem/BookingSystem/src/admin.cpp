#include "../include/admin.h"

// Main entry point for the Admin panel
void Admin::display(PageHandler& pages) {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|         Admin Panel         |\n";
    std::cout << "+-----------------------------+\n";
    std::cout << "1 > Manage Movies\n";
    std::cout << "2 > Manage Shows\n\n";
    std::cout << "9 > Back to Dashboard\n";
}

void Admin::actionHandler(PageHandler& pages) {
    int choice;
    std::cout << "Choose an option: ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

    switch (choice) {
    case 1:
        displayManageMoviesMenu();
        handleManageMoviesAction();
        break;
    case 2:
        displayManageShowsMenu();
        handleManageShowsAction();
        break;
    case 9:
        pages.adminPageShouldDisplay = false;
        pages.dashboardPageShouldDisplay = true;
        break;
    default:
        std::cout << "Invalid option.\n";
        system("pause");
    }
}

// --- Movie Management ---
void Admin::displayManageMoviesMenu() {
    system("CLS");
    std::cout << "--- Manage Movies ---\n";
    std::cout << "1 > Add Movie\n";
    std::cout << "2 > Delete Movie\n\n";
    std::cout << "9 > Back to Admin Panel\n";
}

void Admin::handleManageMoviesAction() {
    int choice;
    std::cout << "Choose an option: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
    case 1: addMovie(); break;
    case 2: deleteMovie(); break;
    case 9: return;
    default: std::cout << "Invalid option.\n";
    }
    system("pause");
}

void Admin::addMovie() {
    // This is a complex operation. For now, we'll outline the steps.
    // A full implementation would require getting all details from the admin.
    std::cout << "\nFunction to add a movie is a work in progress.\n";
    std::cout << "You would need to:\n";
    std::cout << "1. Select a city and cinema.\n";
    std::cout << "2. Enter all movie details (title, genre, etc.).\n";
    std::cout << "3. Create a new movie object in the JSON.\n";
}

void Admin::deleteMovie() {
    std::cout << "\nFunction to delete a movie is a work in progress.\n";
}


// --- Show Management ---
void Admin::displayManageShowsMenu() {
    system("CLS");
    std::cout << "--- Manage Shows ---\n";
    std::cout << "1 > Add Show\n";
    std::cout << "2 > Delete Show\n\n";
    std::cout << "9 > Back to Admin Panel\n";
}

void Admin::handleManageShowsAction() {
    int choice;
    std::cout << "Choose an option: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
    case 1: addShow(); break;
    case 2: deleteShow(); break;
    case 9: return;
    default: std::cout << "Invalid option.\n";
    }
    system("pause");
}

void Admin::addShow() {
    std::cout << "\nFunction to add a show is a work in progress.\n";
}

void Admin::deleteShow() {
    std::cout << "\nFunction to delete a show is a work in progress.\n";
}


