#pragma once
#include "pageHandler.h"
#include "pch.h"
#include "register.h"
#include "login.h"
#include "bookingSystem.h"
#include "raylib.h"

class App {
public:
	App();

private:
	void pageHandler();
	void update();
	void display();
	BookingSystem menu;
	Login login;
	Register reg;
	PageHandler pages;

	bool running = true;
};