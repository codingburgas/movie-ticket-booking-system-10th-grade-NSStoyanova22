#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/utils.h"

class Browse {
private:
    void displayCinemaProgram(const ordered_json& cinemaData);

public:
    void display(PageHandler& pages);
    void actionHandler(PageHandler& pages);
};
