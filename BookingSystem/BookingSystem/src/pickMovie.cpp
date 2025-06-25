#include "../include/pickMovie.h"

void pickMovie::display(PageHandler& pages) {
    system("CLS");
    std::cout << "City: " << bookingInfo::city << " > Cinema: " << bookingInfo::cinema << std::endl;
    std::cout << "------------------------------------------\n";

    ordered_json data = getCitiesData();
    if (data.empty()) return;

    
    for (const auto& city : data["cities"]) {
        if (city["name"] == bookingInfo::city) {
            for (const auto& cinema : city["cinemas"]) {
                if (cinema["name"] == bookingInfo::cinema) {
                    std::cout << "Available movies:\n";
                    if (cinema["movies"].empty()) {
                        std::cout << "No movies currently showing at this location.\n";
                        return;
                    }
                   
                    int i = 1;
                    for (const auto& movie : cinema["movies"]) {
                        std::cout << i++ << " > " << movie["title"] << std::endl;
                    }
                    return;
                }
            }
        }
    }
}

void pickMovie::actionHandler(PageHandler& pages) {
    int choice;
    std::cout << "\nPick a movie by number (or 0 to go back): ";
    std::cin >> choice;

    if (std::cin.fail() || choice < 0) {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (choice == 0) {
        pages.pickAMovieShouldDisplay = false;
        pages.pickACinemaPageShouldDisplay = true; 
        return;
    }

    ordered_json data = getCitiesData();
    if (data.empty()) return;

    for (const auto& city : data["cities"]) {
        if (city["name"] == bookingInfo::city) {
            for (const auto& cinema : city["cinemas"]) {
                if (cinema["name"] == bookingInfo::cinema) {
                    if (choice > 0 && choice <= cinema["movies"].size()) {
                        bookingInfo::movie = cinema["movies"][choice - 1]["title"];

                        std::cout << "\nYou have selected: " << bookingInfo::movie << std::endl;
                        system("pause");

                        pages.pickAMovieShouldDisplay = false;
                        pages.pickAShowPageShouldDisplay = true;
                        return;
                    }
                }
            }
        }
    }

    std::cout << "Invalid movie choice.\n";
    system("pause");
}