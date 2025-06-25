#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/register.h"

class Admin {
private:
    void displayManageMoviesMenu();
    void handleManageMoviesAction();
    void addMovie();
    void deleteMovie();

    void displayManageShowsMenu();
    void handleManageShowsAction();
    void addShow();
    void deleteShow();

public:
    void display(PageHandler& pages);
    void actionHandler(PageHandler& pages);
};

