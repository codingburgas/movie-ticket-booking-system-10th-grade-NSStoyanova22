#pragma once
#include "pageHandler.h"
#include "pch.h"
#include "register.h"
#include "login.h"
#include "dashboard.h"
#include "bookingSystem.h"
#include"pickCinema.h"
#include "pickMovie.h"
#include "pickShow.h"
#include "seatSelection.h"
#include "search.h" 
#include "admin.h" 
#include "payment.h"

class App {
public:
	App();

private:
	void pageHandler();
	BookingSystem menu;
	Login login;
	Register reg;
	Dashboard dash;
	pickCinema pickC;
	pickMovie pickM;
	PageHandler pages;
	pickShow pickS;               
	seatSelection seatS;
	Search searchPage;
	Admin adminPage;
	Payment paymentPage;
	bool running = true;
};