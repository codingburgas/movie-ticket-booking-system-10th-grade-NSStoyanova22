
#include "../include/pch.h"
#include "../include/register.h"
#include "../include/login.h"
#include "../include/bookingSystem.h"


void BookingSystem::display(PageHandler& pages){

 
   
        backgroundPng = LoadTexture("../Files/BookingSystem.png");
  
        
        DrawTexture(backgroundPng, 0, 0, WHITE);

        DrawText("Tick", 83, 79, 82, RAYWHITE);
        DrawText("Book your \n\n\nnext movie!", 499, 157, 43, RAYWHITE);
        DrawText("click L to continue to login \n\n      or R to Register", 512, 475, 15, RAYWHITE);
        DrawText("Login", 550, 321, 33, RAYWHITE);
        DrawText("Register", 520, 405, 33, RAYWHITE);
        actionHandler(pages);
      
        unloadTexture();
     

}
void BookingSystem::actionHandler(PageHandler& pages) {
    if (IsKeyPressed(KEY_L)) {
        pages.loginPageShouldDisplay = true;
        pages.menuPageShouldDisplay = false;
    }

    if (IsKeyPressed(KEY_R)) {
        pages.registerPageShouldDisplay = true;
        pages.menuPageShouldDisplay = false;
    }
    UnloadTexture(backgroundPng);
}
void BookingSystem::unloadTexture() {
   
}
