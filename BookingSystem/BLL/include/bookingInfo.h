#pragma once
#include <iostream>
#include<vector>

namespace bookingInfo {
    extern std::string city;
    extern std::string cinema;
    extern std::string movie;
    extern std::string projectionDatetime;
    extern std::string hall;


    struct Seat {
        int row;
        int col;
        double price;
        std::string type;
    };
    extern std::vector<Seat> selectedSeats;
    extern double totalCost;
}