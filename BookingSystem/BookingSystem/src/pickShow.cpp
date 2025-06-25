#include "../include/pickShow.h"

void pickShow::display(PageHandler& pages) {
    system("CLS");
    std::cout << "City: " << bookingInfo::city << " > Cinema: " << bookingInfo::cinema << " > Movie: " << bookingInfo::movie << std::endl;
    std::cout << "--------------------------------------------------------------------------\n";

    ordered_json data = getCitiesData();
    if (data.empty()) return;

    for (const auto& city : data["cities"]) {
        if (city["name"] == bookingInfo::city) {
            for (const auto& cinema : city["cinemas"]) {
                if (cinema["name"] == bookingInfo::cinema) {
                    for (const auto& movie : cinema["movies"]) {
                        if (movie["title"] == bookingInfo::movie) {
                            std::cout << "Available projections:\n";
                            int i = 1;
                            for (const auto& projection : movie["projections"]) {
                                std::cout << i++ << " > Date & Time: " << projection["datetime"] << ", Hall: " << projection["hall"] << std::endl;
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
}

void pickShow::actionHandler(PageHandler& pages) {
    int choice;
    std::cout << "\nPick a projection by number (or 0 to go back): ";
    std::cin >> choice;

    if (std::cin.fail() || choice < 0) {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        return;
    }

    if (choice == 0) {
        pages.pickAShowPageShouldDisplay = false;
        pages.pickAMovieShouldDisplay = true;
        return;
    }

    ordered_json data = getCitiesData();
    if (data.empty()) return;

    for (const auto& city : data["cities"]) {
        if (city["name"] == bookingInfo::city) {
            for (const auto& cinema : city["cinemas"]) {
                if (cinema["name"] == bookingInfo::cinema) {
                    for (const auto& movie : cinema["movies"]) {
                        if (movie["title"] == bookingInfo::movie) {
                            if (choice > 0 && choice <= movie["projections"].size()) {
                                const auto& selectedProjection = movie["projections"][choice - 1];
                                bookingInfo::projectionDatetime = selectedProjection["datetime"];
                                bookingInfo::hall = selectedProjection["hall"];

                                pages.pickAShowPageShouldDisplay = false;
                                pages.seatSelectionPageShouldDisplay = true;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << "Invalid projection choice.\n";
    system("pause");
}

