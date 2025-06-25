#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include <string>
#include <vector>
#include <algorithm>

struct SearchResult {
    std::string title;
    std::string genre;
    std::string language;
    std::string releaseDate;
    std::string cityName;
    std::string cinemaName;
};

class Search {
private:
    void searchByTitle(const std::string& query, std::vector<SearchResult>& results);
    void searchByGenre(const std::string& query, std::vector<SearchResult>& results);
    void searchByReleaseDate(const std::string& query, std::vector<SearchResult>& results);

    void displayResults(const std::vector<SearchResult>& results);

public:
    void display(PageHandler& pages);
    void actionHandler(PageHandler& pages);
};