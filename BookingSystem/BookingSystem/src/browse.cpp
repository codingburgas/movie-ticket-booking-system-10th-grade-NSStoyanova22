#include "../include/browse.h"

void Browse::display(PageHandler& pages) {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|    Browse Cinema Program    |\n";
    std::cout << "+-----------------------------+\n";
}

void Browse::actionHandler(PageHandler& pages) {
    ordered_json data = getCitiesData();
    if (data.empty()) {
        std::cout << "Could not load cinema data.\n";
        system("pause");
        pages.browsePageShouldDisplay = false;
        pages.dashboardPageShouldDisplay = true;
        return;
    }

    std::cout << "\n--- Select a City ---\n";
    for (size_t i = 0; i < data["cities"].size(); ++i) {
        std::cout << i + 1 << " > " << data["cities"][i]["name"] << std::endl;
    }
    int cityIndex = getIntegerInput("\nPick a city by number (or 0 to go back): ");
    if (cityIndex == 0) {
        pages.browsePageShouldDisplay = false;
        pages.dashboardPageShouldDisplay = true;
        return;
    }
    cityIndex--; 

    if (cityIndex < 0 || cityIndex >= data["cities"].size()) {
        std::cout << "Invalid city choice.\n";
        system("pause");
        return;
    }

    const auto& selectedCity = data["cities"][cityIndex];

    system("CLS");
    std::cout << "--- Cinemas in " << selectedCity["name"] << " ---\n";
    const auto& cinemas = selectedCity["cinemas"];
    for (size_t i = 0; i < cinemas.size(); ++i) {
        std::cout << i + 1 << " > " << cinemas[i]["name"] << std::endl;
    }
    int cinemaIndex = getIntegerInput("\nPick a cinema by number (or 0 to go back): ");
    if (cinemaIndex == 0) {
        return; 
    }
    cinemaIndex--;

    if (cinemaIndex < 0 || cinemaIndex >= cinemas.size()) {
        std::cout << "Invalid cinema choice.\n";
        system("pause");
        return;
    }

    const auto& selectedCinema = cinemas[cinemaIndex];
    displayCinemaProgram(selectedCinema);

    std::cout << "\nPress any key to return to the dashboard...\n";
    system("pause > nul");
    pages.browsePageShouldDisplay = false;
    pages.dashboardPageShouldDisplay = true;
}
void Browse::displayCinemaProgram(const ordered_json& cinemaData) {
    system("CLS");
    std::cout << "========================================================\n";
    std::cout << "Program for: " << cinemaData["name"] << std::endl;
    std::cout << "========================================================\n\n";

    if (cinemaData.find("movies") == cinemaData.end() || cinemaData["movies"].empty()) {
        std::cout << "There are currently no movies scheduled for this cinema.\n";
        return;
    }

    for (const auto& movie : cinemaData["movies"]) {
        std::cout << "--- " << movie["title"] << " ---\n";
        std::cout << "  Genre: " << movie["genre"] << " | Language: " << movie["language"] << " | Released: " << movie["release_date"] << std::endl;
        std::cout << "  Showtimes:\n";
        if (movie["projections"].empty()) {
            std::cout << "    - No showtimes listed.\n";
        }
        else {
            for (const auto& proj : movie["projections"]) {
                std::cout << "    - " << proj["datetime"] << " in " << proj["hall"] << std::endl;
            }
        }
        std::cout << "\n--------------------------------------------------------\n\n";
    }
}