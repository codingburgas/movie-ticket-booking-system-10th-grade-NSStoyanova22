#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "../../BLL/include/register.h"

class Dashboard {
public:
	void display(PageHandler& pages);
	void actionHandler(PageHandler& pages);
	void setChoice();
private:
	int choice;
};