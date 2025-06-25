#include "../include/pageHandler.h"

PageHandler::PageHandler() {
    exitApp = false;
    menuPageShouldDisplay = true;
    registerPageShouldDisplay = false;
    loginPageShouldDisplay = false;
    dashboardPageShouldDisplay = false;
    pickACinemaPageShouldDisplay = false;
    pickAMovieShouldDisplay = false;
    pickAShowPageShouldDisplay = false;     
    seatSelectionPageShouldDisplay = false;
    searchPageShouldDisplay = false;
}

PageHandler pages;