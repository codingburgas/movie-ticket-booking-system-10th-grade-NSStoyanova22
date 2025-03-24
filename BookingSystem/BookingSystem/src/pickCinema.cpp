#include "../include/pickCinema.h"
using namespace std;

struct City {
	string name;
	vector<string> cinemas;
    City(const string& cityName) {
        name = cityName;
    }

    
    void addCinema(const string& cinema) {
        cinemas.push_back(cinema);
    }

    void displayCinemas() const {
        cout << "Cinemas in " << name << ":\n";
        for (const auto& cinema : cinemas) {
            cout << "- " << cinema << "\n";
        }
    }
};

void pickCinema() {
	// start message
    cout << "Ready to book your next movie?" << endl << "Pick a city!" << endl;
    // display and choose cities
    cout << "1. Burgas" << endl << "2. Sofia" << endl;
    int cityNum;
    cin >> cityNum;
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