#include "../include/payment.h"

void Payment::display(PageHandler& pages) {
    system("CLS");
    std::cout << "+-----------------------------+\n";
    std::cout << "|      Payment Summary        |\n";
    std::cout << "+-----------------------------+\n\n";
    std::cout << "Booking for: " << bookingInfo::movie << " at " << bookingInfo::projectionDatetime << std::endl;
    std::cout << "Seats Selected:\n";
    for (const auto& s : bookingInfo::selectedSeats) {
        std::cout << "  - Row " << s.row << ", Col " << s.col << " (" << s.type << "): $" << std::fixed << std::setprecision(2) << s.price << std::endl;
    }
    std::cout << "\n--------------------------------\n";
    std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << bookingInfo::totalCost << std::endl;
    std::cout << "--------------------------------\n";
}

void Payment::actionHandler(PageHandler& pages) {
    // c = "credit card"
    char paymentChoice = 'c'; 
    bool isCash = false;
    std::string cc_number;
    std::cout << "\nEnter credit card number to confirm (simulation): ";
    std::cin >> cc_number;

    if (ifAdmin(credentials::username)) {
        std::cout << "\nSelect payment method: (c) Credit Card, (s) Cash Reservation: ";
        std::cin >> paymentChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (paymentChoice == 's' && ifAdmin(credentials::username)) {
        isCash = true;
        
    }
    else {
        std::string cc_number;
        std::cout << "\nEnter credit card number to confirm (simulation): ";
        getline(std::cin, cc_number);
    }

    if (updateSeatStatusInJson()) { 
        saveNewBooking(isCash);

        system("CLS");
        std::cout << "+-----------------------------+\n";
        if (isCash) {
            std::cout << "|    RESERVATION CREATED!     |\n";
        }
        else {
            std::cout << "|    BOOKING CONFIRMED!       |\n";
        }
        std::cout << "+-----------------------------+\n";
        std::cout << "You have successfully booked seat(s): ";
        for (const auto& s : bookingInfo::selectedSeats) std::cout << "R" << s.row << "C" << s.col << " ";
        std::cout << "\nFor " << bookingInfo::movie << " at " << bookingInfo::projectionDatetime << std::endl;
        std::cout << "A total of $" << std::fixed << std::setprecision(2) << bookingInfo::totalCost << " was charged.\n";
        std::cout << "A confirmation has been sent to your email (simulation).\n\n";
    }
    else {
        std::cout << "Error: Could not complete booking. Please try again.\n";
    }

    bookingInfo::selectedSeats.clear();
    bookingInfo::totalCost = 0.0;
    pages.paymentPageShouldDisplay = false;
    pages.dashboardPageShouldDisplay = true;
    system("pause");
}
