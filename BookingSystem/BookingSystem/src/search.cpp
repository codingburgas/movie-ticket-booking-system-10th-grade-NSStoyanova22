#include "../include/search.h"

// Main display function for the search page. It shows the search options.
void Search::display(PageHandler& pages) {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|      Search for a Movie     |\n";
    std::cout << "+-----------------------------+\n";
    std::cout << "1 > Search by Title\n";
    std::cout << "2 > Search by Genre\n";
    std::cout << "3 > Search by Release Date\n\n";
    std::cout << "9 > Back to Dashboard\n";
}

// Handles the user's choice from the search menu.
void Search::actionHandler(PageHandler& pages) {
    int choice;
    std::cout << "\nChoose an option: ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the newline

    std::string query;
    std::vector<SearchResult> results;

    switch (choice) {
    case 1:
        std::cout << "Enter movie title to search for: ";
        getline(std::cin, query);
        searchByTitle(query, results);
        break;
    case 2:
        std::cout << "Enter genre to search for (e.g., Action, Sci-Fi): ";
        getline(std::cin, query);
        searchByGenre(query, results);
        break;
    case 3:
        std::cout << "Enter release date to search for (YYYY-MM-DD): ";
        getline(std::cin, query);
        searchByReleaseDate(query, results);
        break;
    case 9:
        pages.searchPageShouldDisplay = false;
        pages.dashboardPageShouldDisplay = true;
        return;
    default:
        std::cout << "Invalid option.\n";
        system("pause");
        return;
    }

    displayResults(results);
    std::cout << "\nPress any key to return to the search menu...\n";
    system("pause > nul"); // Waits for user keypress without showing "Press any key..."
}

// Helper to convert a string to lowercase for case-insensitive comparison
std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Iterates through all movies and adds title matches to the results vector.
void Search::searchByTitle(const std::string& query, std::vector<SearchResult>& results) {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    std::string lowerQuery = toLower(query);

    for (const auto& city : data["cities"]) {
        for (const auto& cinema : city["cinemas"]) {
            if (cinema.find("movies") == cinema.end() || cinema["movies"].is_null()) continue;

            for (const auto& movie : cinema["movies"]) {
                if (toLower(movie["title"]).find(lowerQuery) != std::string::npos) {
                    results.push_back({
                        movie["title"],
                        movie["genre"],
                        movie["language"],
                        movie["release_date"],
                        city["name"],
                        cinema["name"]
                        });
                }
            }
        }
    }
}

// Iterates through all movies and adds genre matches to the results vector.
void Search::searchByGenre(const std::string& query, std::vector<SearchResult>& results) {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    std::string lowerQuery = toLower(query);

    for (const auto& city : data["cities"]) {
        for (const auto& cinema : city["cinemas"]) {
            if (cinema.find("movies") == cinema.end() || cinema["movies"].is_null()) continue;

            for (const auto& movie : cinema["movies"]) {
                if (toLower(movie["genre"]) == lowerQuery) {
                    results.push_back({
                       movie["title"],
                       movie["genre"],
                       movie["language"],
                       movie["release_date"],
                       city["name"],
                       cinema["name"]
                        });
                }
            }
        }
    }
}

// Iterates through all movies and adds release date matches to the results vector.
void Search::searchByReleaseDate(const std::string& query, std::vector<SearchResult>& results) {
    ordered_json data = getCitiesData();
    if (data.empty()) return;

    for (const auto& city : data["cities"]) {
        for (const auto& cinema : city["cinemas"]) {
            if (cinema.find("movies") == cinema.end() || cinema["movies"].is_null()) continue;

            for (const auto& movie : cinema["movies"]) {
                if (movie["release_date"] == query) {
                    results.push_back({
                       movie["title"],
                       movie["genre"],
                       movie["language"],
                       movie["release_date"],
                       city["name"],
                       cinema["name"]
                        });
                }
            }
        }
    }
}

// Displays the search results in a clean, readable format.
void Search::displayResults(const std::vector<SearchResult>& results) {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|        Search Results       |\n";
    std::cout << "+-----------------------------+\n";

    if (results.empty()) {
        std::cout << "No movies found matching your criteria.\n";
        return;
    }

    for (const auto& r : results) {
        std::cout << "Title:    " << r.title << std::endl;
        std::cout << "Genre:    " << r.genre << " | Language: " << r.language << " | Released: " << r.releaseDate << std::endl;
        std::cout << "Location: " << r.cinemaName << ", " << r.cityName << std::endl;
        std::cout << "--------------------------------------------------------\n";
    }
}
