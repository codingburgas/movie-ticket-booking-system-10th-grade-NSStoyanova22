#include "../include/admin.h"

// --- Main Admin Panel Display/Action ---
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
    std::cout << "\nChoose an option: ";
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
        break;
    case 2:
        displayManageShowsMenu();
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
    int choice;
    do {
        system("CLS");
        std::cout << "--- Manage Movies ---\n";
        std::cout << "1 > Add Movie\n";
        std::cout << "2 > Delete Movie\n\n";
        std::cout << "9 > Back to Admin Panel\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: addMovie(); system("pause"); break;
        case 2: deleteMovie(); system("pause"); break;
        case 9: break;
        default: std::cout << "Invalid option.\n"; system("pause");
        }
    } while (choice != 9);
}

void Admin::addMovie() {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    std::string cityName, cinemaName, title, genre, lang, releaseDate;

    std::cout << "Enter City Name: ";
    getline(std::cin, cityName);
    std::cout << "Enter Cinema Name: ";
    getline(std::cin, cinemaName);

    // Find the target cinema
    for (auto& city : data["cities"]) {
        if (city["name"] == cityName) {
            for (auto& cinema : city["cinemas"]) {
                if (cinema["name"] == cinemaName) {
                    std::cout << "Enter Movie Title: ";
                    getline(std::cin, title);
                    std::cout << "Enter Genre: ";
                    getline(std::cin, genre);
                    std::cout << "Enter Language: ";
                    getline(std::cin, lang);
                    std::cout << "Enter Release Date (YYYY-MM-DD): ";
                    getline(std::cin, releaseDate);

                    ordered_json newMovie = {
                        {"title", title},
                        {"genre", genre},
                        {"language", lang},
                        {"release_date", releaseDate},
                        {"projections", json::array()} // Starts with no shows
                    };

                    cinema["movies"].push_back(newMovie);

                    if (saveCitiesData(data)) {
                        std::cout << "\nMovie '" << title << "' added successfully!\n";
                    }
                    else {
                        std::cout << "\nError: Could not save movie.\n";
                    }
                    return;
                }
            }
        }
    }
    std::cout << "Error: City or Cinema not found.\n";
}

void Admin::deleteMovie() {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    std::string cityName, cinemaName, movieTitle;
    std::cout << "Enter City Name: ";
    getline(std::cin, cityName);
    std::cout << "Enter Cinema Name: ";
    getline(std::cin, cinemaName);
    std::cout << "Enter Title of Movie to Delete: ";
    getline(std::cin, movieTitle);

    for (auto& city : data["cities"]) {
        if (city["name"] == cityName) {
            for (auto& cinema : city["cinemas"]) {
                if (cinema["name"] == cinemaName) {
                    auto& movies = cinema["movies"];
                    // Erase-remove idiom to delete the movie
                    auto it = std::remove_if(movies.begin(), movies.end(), [&](const auto& movie) {
                        return movie["title"] == movieTitle;
                        });

                    if (it != movies.end()) {
                        movies.erase(it, movies.end());
                        if (saveCitiesData(data)) {
                            std::cout << "\nMovie '" << movieTitle << "' deleted successfully!\n";
                        }
                        else {
                            std::cout << "\nError: Could not save changes after deletion.\n";
                        }
                    }
                    else {
                        std::cout << "Error: Movie not found.\n";
                    }
                    return;
                }
            }
        }
    }
    std::cout << "Error: City or Cinema not found.\n";
}


// --- Show Management ---
void Admin::displayManageShowsMenu() {
    int choice;
    do {
        system("CLS");
        std::cout << "--- Manage Shows ---\n";
        std::cout << "1 > Add Show\n";
        std::cout << "2 > Delete Show\n\n";
        std::cout << "9 > Back to Admin Panel\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: addShow(); system("pause"); break;
        case 2: deleteShow(); system("pause"); break;
        case 9: break;
        default: std::cout << "Invalid option.\n"; system("pause");
        }
    } while (choice != 9);
}

void Admin::addShow() {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    std::string cityName, cinemaName, movieTitle, datetime, hall;
    int rows, cols;

    std::cout << "Enter City Name: ";
    getline(std::cin, cityName);
    std::cout << "Enter Cinema Name: ";
    getline(std::cin, cinemaName);
    std::cout << "Enter Movie Title to add show to: ";
    getline(std::cin, movieTitle);

    for (auto& city : data["cities"]) {
        if (city["name"] == cityName) {
            for (auto& cinema : city["cinemas"]) {
                if (cinema["name"] == cinemaName) {
                    for (auto& movie : cinema["movies"]) {
                        if (movie["title"] == movieTitle) {
                            std::cout << "Enter Projection DateTime (YYYY-MM-DD HH:MM): ";
                            getline(std::cin, datetime);
                            std::cout << "Enter Hall Name (e.g., Hall 5): ";
                            getline(std::cin, hall);
                            std::cout << "Enter number of rows for seating: ";
                            std::cin >> rows;
                            std::cout << "Enter number of columns for seating: ";
                            std::cin >> cols;

                            ordered_json newShow = {
                                {"datetime", datetime},
                                {"hall", hall},
                                {"seats", json::array()}
                            };

                            for (int r = 1; r <= rows; ++r) {
                                for (int c = 1; c <= cols; ++c) {
                                    newShow["seats"].push_back({ {"row", r}, {"col", c}, {"taken", false} });
                                }
                            }

                            movie["projections"].push_back(newShow);
                            if (saveCitiesData(data)) {
                                std::cout << "\nShow added successfully!\n";
                            }
                            else {
                                std::cout << "\nError saving new show.\n";
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Error: Could not find specified City, Cinema, or Movie.\n";
}

void Admin::deleteShow() {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    std::string cityName, cinemaName, movieTitle, datetime;
    std::cout << "Enter City Name: ";
    getline(std::cin, cityName);
    std::cout << "Enter Cinema Name: ";
    getline(std::cin, cinemaName);
    std::cout << "Enter Movie Title: ";
    getline(std::cin, movieTitle);
    std::cout << "Enter DateTime of show to delete (YYYY-MM-DD HH:MM): ";
    getline(std::cin, datetime);

    for (auto& city : data["cities"]) {
        if (city["name"] == cityName) {
            for (auto& cinema : city["cinemas"]) {
                if (cinema["name"] == cinemaName) {
                    for (auto& movie : cinema["movies"]) {
                        if (movie["title"] == movieTitle) {
                            auto& projections = movie["projections"];
                            auto it = std::remove_if(projections.begin(), projections.end(), [&](const auto& proj) {
                                return proj["datetime"] == datetime;
                                });

                            if (it != projections.end()) {
                                projections.erase(it, projections.end());
                                if (saveCitiesData(data)) {
                                    std::cout << "\nShow deleted successfully!\n";
                                }
                                else {
                                    std::cout << "\nError saving after deleting show.\n";
                                }
                            }
                            else {
                                std::cout << "Error: Show with that datetime not found.\n";
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Error: Could not find specified City, Cinema, or Movie.\n";
}