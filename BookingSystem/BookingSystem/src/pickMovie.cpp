#include "../include/pickCinema.h"



void pickCinema::display(PageHandler& pages) {
    system("CLS");
    std::cout << bookingInfo::city << std::endl << bookingInfo::cinema << std::endl;
    ordered_json data = getCitiesData(); 
    for (const auto& city : data["cities"]) {
        if (city["name"] == bookingInfo::city) {
            for (const auto& cinema : city["cinemas"]) {
                if (cinema["name"] == bookingInfo::cinema) {
                    std::cout << "Available movies:\n";
                    int i = 1;
                    for (const auto& movie : cinema["movies"]) {
                        std::cout << i++ << " > " << movie["title"] << std::endl;
                    }

                    int choice;
                    std::cout << "\nPick a movie by number: ";
                    std::cin >> choice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (choice < 1 || choice > cinema["movies"].size()) {
                        std::cout << "Invalid choice.\n";
                        return;
                    }

                    std::string selectedMovie = cinema["movies"][choice - 1]["title"];
                    bookingInfo::movie = selectedMovie;
                   
                   
                    return;
                }
            }
        }
    }

    std::cout << "Cinema not found in city.\n";
}


void pickCinema::actionHandler(PageHandler& pages) {


}

