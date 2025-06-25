#include "../include/seatSelection.h"

bookingInfo::Seat seatSelection::findSeatDetails(const ordered_json& projection, int row, int col) {
    for (const auto& seat : projection["seats"]) {
        if (seat["row"] == row && seat["col"] == col) {
            return { seat["row"], seat["col"], seat["price"], seat["type"] };
        }
    }
    return { -1, -1, 0.0, "" }; 
}

bool seatSelection::isSeatTaken(const ordered_json& projection, int row, int col) {
    for (const auto& seat : projection["seats"]) {
        if (seat["row"] == row && seat["col"] == col) {
            return seat["taken"];
        }
    }
    return true;
}

bool seatSelection::isSeatAlreadySelected(int row, int col) {
    for (const auto& seat : bookingInfo::selectedSeats) {
        if (seat.row == row && seat.col == col) {
            return true;
        }
    }
    return false;
}



void seatSelection::display(PageHandler& pages) {
    system("CLS");
    std::cout << "Booking for: " << bookingInfo::movie << " at " << bookingInfo::projectionDatetime << " in " << bookingInfo::hall << std::endl;
    std::cout << "--------------------------------------------------------------------------\n";
    std::cout << "Seating Plan ([ ] = Available, [S] = Your Selection, [X] = Taken)\n\n";

    ordered_json data = getCitiesData();
    if (data.empty()) return;

    for (const auto& city : data["cities"])
        if (city["name"] == bookingInfo::city)
            for (const auto& cinema : city["cinemas"])
                if (cinema["name"] == bookingInfo::cinema)
                    for (const auto& movie : cinema["movies"])
                        if (movie["title"] == bookingInfo::movie)
                            for (const auto& projection : movie["projections"])
                                if (projection["datetime"] == bookingInfo::projectionDatetime) {
                                    int maxRow = 0, maxCol = 0;
                                    for (const auto& seat : projection["seats"]) {
                                        if (seat["row"] > maxRow) maxRow = seat["row"];
                                        if (seat["col"] > maxCol) maxCol = seat["col"];
                                    }

                                    std::vector<std::vector<char>> seatGrid(maxRow + 1, std::vector<char>(maxCol + 1, ' '));

                                    for (const auto& seat : projection["seats"]) {
                                        char status = ' '; 
                                        if (seat["taken"]) {
                                            status = 'X';
                                        }
                                        else if (isSeatAlreadySelected(seat["row"], seat["col"])) {
                                            status = 'S'; 
                                        }
                                        seatGrid[seat["row"]][seat["col"]] = status;
                                    }

                                    for (int r = 1; r <= maxRow; ++r) {
                                        std::cout << "Row " << r << "  ";
                                        for (int c = 1; c <= maxCol; ++c) {
                                            std::cout << "[" << seatGrid[r][c] << "] ";
                                        }
                                        std::cout << std::endl;
                                    }
                                    return;
                                }
}

void seatSelection::actionHandler(PageHandler& pages) {
    // Reset selections from any previous attempt
    bookingInfo::selectedSeats.clear();
    bookingInfo::totalCost = 0.0;

    ordered_json data = getCitiesData();
    ordered_json projectionData;

    // Pre-load the projection data so we don't search for it repeatedly
    for (const auto& city : data["cities"]) if (city["name"] == bookingInfo::city)
        for (const auto& cinema : city["cinemas"]) if (cinema["name"] == bookingInfo::cinema)
            for (const auto& movie : cinema["movies"]) if (movie["title"] == bookingInfo::movie)
                for (const auto& projection : movie["projections"]) if (projection["datetime"] == bookingInfo::projectionDatetime)
                    projectionData = projection;

    if (projectionData.is_null()) {
        std::cout << "Error: Could not load projection data.\n";
        system("pause");
        pages.seatSelectionPageShouldDisplay = false;
        pages.dashboardPageShouldDisplay = true;
        return;
    }

    int row, col;
    char action;

    while (true) {
        display(pages); // Refresh display
        std::cout << "\n--------------------------------------------------------------------------\n";
        std::cout << "Your selection: ";
        for (const auto& s : bookingInfo::selectedSeats) std::cout << "R" << s.row << "C" << s.col << " ";
        std::cout << "\nTotal Cost: $" << std::fixed << std::setprecision(2) << bookingInfo::totalCost << std::endl;
        std::cout << "\nEnter 's' to select, 'u' to unselect, 'd' when done: ";
        std::cin >> action;

        if (action == 'd') {
            break;
        }

        if (action == 's' || action == 'u') {
            std::cout << "Enter Row: ";
            std::cin >> row;
            std::cout << "Enter Column: ";
            std::cin >> col;

            if (std::cin.fail()) {
                std::cout << "Invalid input.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                continue;
            }

            if (action == 's') {
                if (isSeatTaken(projectionData, row, col)) {
                    std::cout << "This seat is already taken! Please choose another.\n";
                }
                else if (isSeatAlreadySelected(row, col)) {
                    std::cout << "You have already selected this seat.\n";
                }
                else {
                    bookingInfo::Seat newSeat = findSeatDetails(projectionData, row, col);
                    if (newSeat.row != -1) {
                        bookingInfo::selectedSeats.push_back(newSeat);
                        bookingInfo::totalCost += newSeat.price;
                    }
                    else {
                        std::cout << "Seat not found.\n";
                    }
                }
            }
            else {
                auto it = std::remove_if(bookingInfo::selectedSeats.begin(), bookingInfo::selectedSeats.end(),
                    [row, col, &projectionData](const bookingInfo::Seat& seat) {
                        if (seat.row == row && seat.col == col) {
                            bookingInfo::totalCost -= seat.price; 
                            return true;
                        }
                        return false;
                    });
                bookingInfo::selectedSeats.erase(it, bookingInfo::selectedSeats.end());
            }
        }
        else {
            std::cout << "Invalid action.\n";
        }
        system("pause");
    }

    if (bookingInfo::selectedSeats.empty()) {
        pages.seatSelectionPageShouldDisplay = false;
        pages.dashboardPageShouldDisplay = true;
    }
    else {
      
        pages.seatSelectionPageShouldDisplay = false;
        pages.paymentPageShouldDisplay = true;
    }
}

