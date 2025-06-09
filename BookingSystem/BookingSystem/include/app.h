#pragma once
#include "pageHandler.h"
#include "pch.h"
#include "register.h"
#include "login.h"
#include "dashboard.h"
#include "bookingSystem.h"

class App {
public:
	App();

private:
	void pageHandler();
	BookingSystem menu;
	Login login;
	Register reg;
	Dashboard dash;
	PageHandler pages;

	bool running = true;
};