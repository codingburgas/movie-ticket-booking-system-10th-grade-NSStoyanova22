#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/register.h"
#include "../../BLL/include/bookingInfo.h"


class Payment {
public:
    void display(PageHandler& pages);
    void actionHandler(PageHandler& pages);
};