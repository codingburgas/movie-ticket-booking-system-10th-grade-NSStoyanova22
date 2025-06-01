#include "../include/login.h"
#include <string>
#include <limits>
#include "raylib.h"



void Login::display(PageHandler& pages) {
   
    
   backgroundPng = LoadTexture("../Files/login.png");
   
        ClearBackground(RAYWHITE);

        DrawTexture(backgroundPng, 0, 0, WHITE);


   
        unloadTexture();
    
}

void Login::unloadTexture() {
    UnloadTexture(backgroundPng);
}



 