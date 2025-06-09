#include "../include/pageHandler.h"

PageHandler::PageHandler() {
    exitApp = false;
    menuPageShouldDisplay = true;
    registerPageShouldDisplay = false;
    loginPageShouldDisplay = false;
    dashboardPageShouldDisplay = false;
    pickACinemaPageShouldDisplay = false;
}

PageHandler pages;