#include "../include/login.h"
#include <string>
#include <limits>
#include "raylib.h"




bool CheckCollisionTextBox(Rectangle box, Vector2 mousePos) {
    return CheckCollisionPointRec(mousePos, box);
}

void DrawTextBox(Rectangle box, const std::string& text, bool isActive, bool isPassword = false) {
    DrawRectangleRec(box, isActive ? LIGHTGRAY : GRAY);
    std::string displayText = isPassword ? std::string(text.length(), '*') : text;
    DrawText(displayText.c_str(), (int)box.x + 5, (int)box.y + 8, 20, BLACK);
    DrawRectangleLines((int)box.x, (int)box.y, (int)box.width, (int)box.height, DARKGRAY);
}

void Login::display() {

    SetTargetFPS(60);
    
    Texture2D  backgroundPng = LoadTexture("../Files/login.png");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundPng, 0, 0, WHITE);
        EndDrawing();
    }
   
    UnloadTexture(backgroundPng);
}


 