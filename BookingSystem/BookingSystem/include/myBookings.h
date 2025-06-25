#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"

class MyBookings {
private:
    void displayUserBookings();
    void cancelBooking();

public:
    void display(PageHandler& pages);
    void actionHandler(PageHandler& pages);
};