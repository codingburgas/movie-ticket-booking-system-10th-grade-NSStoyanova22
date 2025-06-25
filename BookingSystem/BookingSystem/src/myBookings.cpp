#include "../include/myBookings.h"

void MyBookings::display(PageHandler& pages) {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|        My Bookings          |\n";
    std::cout << "+-----------------------------+\n\n";
    displayUserBookings();
}

void MyBookings::actionHandler(PageHandler& pages) {
    std::cout << "\n--------------------------------\n";
    std::cout << "Enter 'c' to cancel a booking or 'b' to go back: ";
    char choice;
    std::cin >> choice;

    if (choice == 'c') {
        cancelBooking();
        system("pause");
    }
    // Any other input will go back
    pages.myBookingsPageShouldDisplay = false;
    pages.dashboardPageShouldDisplay = true;
}

void MyBookings::displayUserBookings() {
    ordered_json bookings = getBookingsData();
    bool foundBookings = false;
    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        const auto& booking = it.value();
        if (booking["user_email"] == credentials::email) {
            foundBookings = true;
            std::cout << "Booking ID: " << it.key() << std::endl;
            std::cout << "  Movie:    " << booking["movie_title"] << std::endl;
            std::cout << "  Cinema:   " << booking["cinema_name"] << ", " << booking["city_name"] << std::endl;
            std::cout << "  Date:     " << booking["projection_datetime"] << std::endl;
            std::cout << "  Seats:    ";
            for (const auto& seat : booking["seats"]) {
                std::cout << "R" << seat["row"] << "C" << seat["col"] << " ";
            }
            std::cout << "\n--------------------------------\n";
        }
    }
    if (!foundBookings) {
        std::cout << "You have no active bookings.\n";
    }
}

void MyBookings::cancelBooking() {
    std::string bookingId;
    std::cout << "Enter the Booking ID to cancel: ";
    std::cin >> bookingId;

    ordered_json bookings = getBookingsData();
    if (bookings.find(bookingId) == bookings.end() || bookings[bookingId]["user_email"] != credentials::email) {
        std::cout << "Error: Booking ID not found or does not belong to you.\n";
        return;
    }

    ordered_json bookingToCancel = bookings[bookingId];

    // Step 1: Update cities.json to free the seats
    ordered_json cities = getCitiesData();
    for (auto& city : cities["cities"]) {
        if (city["name"] == bookingToCancel["city_name"]) {
            for (auto& cinema : city["cinemas"]) {
                if (cinema["name"] == bookingToCancel["cinema_name"]) {
                    for (auto& movie : cinema["movies"]) {
                        if (movie["title"] == bookingToCancel["movie_title"]) {
                            for (auto& proj : movie["projections"]) {
                                if (proj["datetime"] == bookingToCancel["projection_datetime"]) {
                                    for (const auto& cancelledSeat : bookingToCancel["seats"]) {
                                        for (auto& seat : proj["seats"]) {
                                            if (seat["row"] == cancelledSeat["row"] && seat["col"] == cancelledSeat["col"]) {
                                                seat["taken"] = false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Step 2: Remove the booking from bookings.json
    bookings.erase(bookingId);

    // Step 3: Save both files
    if (saveCitiesData(cities) && saveBookingsData(bookings)) {
        std::cout << "Booking " << bookingId << " has been successfully cancelled.\n";
    }
    else {
        std::cout << "Error: Could not finalize cancellation. Please contact support.\n";
    }
}