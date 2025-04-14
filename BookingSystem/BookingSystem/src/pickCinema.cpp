#include "../include/pickCinema.h"


struct City {
	std::string name;
    std::vector<std::string> cinemas;
    City(const std::string& cityName) {
        name = cityName;
    }

    
    void addCinema(const std::string& cinema) {
        cinemas.push_back(cinema);
    }

    void displayCinemas() const {
        std::cout << "Cinemas in " << name << ":\n";
        for (const auto& cinema : cinemas) {
            std::cout << "- " << cinema << "\n";
        }
    }
};

void pickCinema() {
	// start message
    std::cout << "Ready to book your next movie?" << std::endl << "Pick a city!" << std::endl;
    // display and choose cities
    std::cout << "1. Burgas" << std::endl << "2. Sofia" << std::endl;
    int cityNum;
    std::cin >> cityNum;
    // add info to struct
    City burgas("Burgas");
    burgas.addCinema("Cinema City Burgas");
    burgas.addCinema("Arena Burgas");
    City sofia("Sofia");
    sofia.addCinema("Cinema City Sofia");
    sofia.addCinema("Cine Grand");
    sofia.addCinema("Odeon Grand");
    if (cityNum == 1) {
        // clear screen and display cinemas
        system("CLS");
        burgas.displayCinemas();
    }
    if (cityNum == 2) {
        // clear screen and display cinemas
        system("CLS");
        sofia.displayCinemas();
    }

}