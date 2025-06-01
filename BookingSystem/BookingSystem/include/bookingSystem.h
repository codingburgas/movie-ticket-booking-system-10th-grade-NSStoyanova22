#pragma once
#include "pch.h"



class BookingSystem {
public:
	void display(PageHandler& pages);
	void actionHandler(PageHandler& pages);

private:
	Texture2D  backgroundPng;
	void unloadTexture();
};