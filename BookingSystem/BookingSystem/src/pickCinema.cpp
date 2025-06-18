#include "../include/pickCinema.h"



void pickCinema::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Where would you like to watch a movie?\n";

    ordered_json data = getCitiesData();
    if (data.empty()) return;

    
    int cityIndex = 0;
    for (size_t i = 0; i < data["cities"].size(); ++i) {
        std::cout << i + 1 << " > " << data["cities"][i]["name"] << std::endl;
    }

  
    std::cout << "\nPick a city by number: ";
    std::cin >> cityIndex;
    cityIndex--; 

    if (cityIndex < 0 || cityIndex >= data["cities"].size()) {
        std::cout << "Invalid city choice.\n";
        return;
    }

    
    bookingInfo::city = data["cities"][cityIndex]["name"];
    std::cout << "\n--- " << bookingInfo::city << " ---\n";


    const auto& cinemas = data["cities"][cityIndex]["cinemas"];
    for (size_t i = 0; i < cinemas.size(); ++i) {
        std::cout << i + 1 << " > " << cinemas[i] << std::endl;
    }

 
    int cinemaIndex = 0;
    std::cout << "\nPick a cinema by number: ";
    std::cin >> cinemaIndex;
    cinemaIndex--;

    if (cinemaIndex < 0 || cinemaIndex >= cinemas.size()) {
        std::cout << "Invalid cinema choice.\n";
        return;
    }
    else {
        pages.pickACinemaPageShouldDisplay = false;
        pages.pickAMovieShouldDisplay = true;
    }
   
    bookingInfo::cinema = cinemas[cinemaIndex].get<std::string>();
    
    
  
}


void pickCinema::actionHandler(PageHandler& pages) {


}

