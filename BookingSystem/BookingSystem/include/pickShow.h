#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/bookingInfo.h"

class pickShow {
public:
    void display(PageHandler& pages);
    void actionHandler(PageHandler& pages);
};