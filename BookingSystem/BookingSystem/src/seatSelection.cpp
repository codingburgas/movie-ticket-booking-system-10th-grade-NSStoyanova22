#include "../include/seatSelection.h"

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
    int row, col;
    char action;

    while (true) {
        display(pages); 
        std::cout << "\n--------------------------------------------------------------------------\n";
        std::cout << "Your selection: ";
        for (const auto& s : bookingInfo::selectedSeats) std::cout << "R" << s.row << "C" << s.col << " ";
        std::cout << "\n\nEnter 's' to select a seat, 'u' to unselect, 'd' when done: ";
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
                bookingInfo::selectedSeats.push_back({ row, col });
            }
            else { 
                bookingInfo::selectedSeats.erase(
                    std::remove_if(bookingInfo::selectedSeats.begin(), bookingInfo::selectedSeats.end(),
                        [row, col](const bookingInfo::Seat& seat) {
                            return seat.row == row && seat.col == col;
                        }),
                    bookingInfo::selectedSeats.end());
            }
        }
        else {
            std::cout << "Invalid action.\n";
            system("pause");
        }
    }


    if (bookingInfo::selectedSeats.empty()) {
        std::cout << "No seats selected. Returning to dashboard.\n";
    }
    else {
        if (updateSeatStatusInJson()) {
            system("CLS");
            std::cout << "+-----------------------------+\n";
            std::cout << "|    BOOKING CONFIRMED!       |\n";
            std::cout << "+-----------------------------+\n";
            std::cout << "You have successfully booked seat(s): ";
            for (const auto& s : bookingInfo::selectedSeats) std::cout << "R" << s.row << "C" << s.col << " ";
            std::cout << "\nFor " << bookingInfo::movie << " at " << bookingInfo::projectionDatetime << std::endl;
        }
        else {
            std::cout << "Error: Could not complete booking. Please try again.\n";
        }
    }

    bookingInfo::selectedSeats.clear();
    pages.seatSelectionPageShouldDisplay = false;
    pages.dashboardPageShouldDisplay = true;
    system("pause");
}
