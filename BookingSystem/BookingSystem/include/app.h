#pragma once
#include "pageHandler.h"
#include "pch.h"
#include "register.h"
#include "login.h"
#include "bookingSystem.h"

class App {
public:
	App();

private:
	void pageHandler();
	BookingSystem menu;
	Login login;
	Register reg;
	PageHandler pages;

	bool running = true;
};