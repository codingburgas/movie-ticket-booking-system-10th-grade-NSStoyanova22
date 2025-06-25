#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "../../BLL/include/register.h"
#include "../../DAL/include/files.h"


class Dashboard {
public:
	void display(PageHandler& pages);
	void actionHandler(PageHandler& pages);
	void setChoice();
private:
	int choice;
};