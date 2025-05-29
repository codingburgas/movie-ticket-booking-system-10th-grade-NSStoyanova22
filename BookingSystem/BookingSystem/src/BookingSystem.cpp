#include "../include/pch.h"
#include "../include/register.h"
#include "../include/login.h"
#include "raylib.h"



int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tick");
    SetTargetFPS(60);
    Texture2D  backgroundPng = LoadTexture("../Files/BookingSystem.png");
    Register registerPage;
    Login loginPage;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundPng, 0, 0, WHITE);

        DrawText("Tick", 83, 79, 82, RAYWHITE);
        DrawText("Book your \n\n\nnext movie!", 499, 157, 43, RAYWHITE);
        DrawText("click L to continue to login \n\n      or R to Register", 512, 475, 15, RAYWHITE);
        DrawText("Login", 550, 321, 33, RAYWHITE);
       
        if (IsKeyPressed(KEY_L)) {
            loginPage.display();
        }

        DrawText("Register", 520, 405, 33, RAYWHITE);

        if (IsKeyPressed(KEY_R)) {
            registerPage.display();
        }
        EndDrawing();
    }

    UnloadTexture(backgroundPng);



    



}


