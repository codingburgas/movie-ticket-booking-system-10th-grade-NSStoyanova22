#include "../include/pickCinema.h"

void pickCinema::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Where would you like to watch a movie?\n";
    std::cout << "--------------------------------------\n";

    ordered_json data = getCitiesData();
    if (data.empty()) {
        std::cout << "Could not load cinema data.\n";
        return;
    }

 
    for (size_t i = 0; i < data["cities"].size(); ++i) {
        std::cout << i + 1 << " > " << data["cities"][i]["name"] << std::endl;
    }
}

void pickCinema::actionHandler(PageHandler& pages) {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    int cityIndex = 0;
    std::cout << "\nPick a city by number: ";
    std::cin >> cityIndex;
    cityIndex--; 

    if (std::cin.fail() || cityIndex < 0 || cityIndex >= data["cities"].size()) {
        std::cout << "Invalid city choice.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        return;
    }

  
    bookingInfo::city = data["cities"][cityIndex]["name"];

    system("CLS");
    std::cout << "--- Cinemas in " << bookingInfo::city << " ---\n";

    const auto& cinemas = data["cities"][cityIndex]["cinemas"];
    for (size_t i = 0; i < cinemas.size(); ++i) {
        std::cout << i + 1 << " > " << cinemas[i]["name"] << std::endl;
    }

    int cinemaIndex = 0;
    std::cout << "\nPick a cinema by number: ";
    std::cin >> cinemaIndex;
    cinemaIndex--;

    if (std::cin.fail() || cinemaIndex < 0 || cinemaIndex >= cinemas.size()) {
        std::cout << "Invalid cinema choice.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
       
        bookingInfo::city = "";
        return;
    }

  
    bookingInfo::cinema = cinemas[cinemaIndex]["name"];
    pages.pickACinemaPageShouldDisplay = false;
    pages.pickAMovieShouldDisplay = true;
}