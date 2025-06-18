#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "../../BLL/include/bookingInfo.h"
#include "../../BLL/include/register.h"
#include "../../DAL/include/files.h"

class pickMovie {
public:
	void display(PageHandler& pages);
	void actionHandler(PageHandler& pages);


};
