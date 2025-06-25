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
    };
    extern std::vector<Seat> selectedSeats;
}