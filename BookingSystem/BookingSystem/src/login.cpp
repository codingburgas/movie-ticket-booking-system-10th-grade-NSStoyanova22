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


void Login::display(PageHandler& pages) {
    const int screenWidth = 800;
    const int screenHeight = 600;


    InitWindow(screenWidth, screenHeight, "Raylib Login Screen");
    SetTargetFPS(60);

    Rectangle usernameBox = { 300, 150, 200, 40 };
    Rectangle emailBox = { 300, 210, 200, 40 };
    Rectangle passwordBox = { 300, 270, 200, 40 };
    Rectangle submitBtn = { 350, 330, 100, 40 };

    int activeField = 0;
    bool error = false;

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionTextBox(usernameBox, mousePos)) activeField = 1;
            else if (CheckCollisionTextBox(emailBox, mousePos)) activeField = 2;
            else if (CheckCollisionTextBox(passwordBox, mousePos)) activeField = 3;
            else activeField = 0;
        }

        int key = GetCharPressed();
        while (key > 0) {
            if (key >= 32 && key <= 125) {
                switch (activeField) {
                case 1: credentials::username += (char)key; break;
                case 2: credentials::email += (char)key; break;
                case 3: credentials::password += (char)key; break;
                }
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            switch (activeField) {
            case 1: if (!credentials::username.empty()) credentials::username.pop_back(); break;
            case 2: if (!credentials::email.empty()) credentials::email.pop_back(); break;
            case 3: if (!credentials::password.empty()) credentials::password.pop_back(); break;
            }
        }

        if (CheckCollisionPointRec(mousePos, submitBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (!loginUser(credentials::username, credentials::email, credentials::password)) {
                error = true;
                credentials::username.clear();
                credentials::email.clear();
                credentials::password.clear();
            }
            else {
                error = false;
             
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("+-----------------------------+", 240, 50, 20, DARKBLUE);
        DrawText("|        Welcome !           |", 250, 80, 20, DARKBLUE);
        DrawText("+-----------------------------+", 240, 110, 20, DARKBLUE);

        DrawText("Username:", 200, 160, 20, BLACK);
        DrawText("Email:", 200, 220, 20, BLACK);
        DrawText("Password:", 200, 280, 20, BLACK);

        DrawTextBox(usernameBox, credentials::username, activeField == 1);
        DrawTextBox(emailBox, credentials::email, activeField == 2);
        DrawTextBox(passwordBox, credentials::password, activeField == 3, true);

        DrawRectangleRec(submitBtn, DARKBLUE);
        DrawText("Login", (int)submitBtn.x + 20, (int)submitBtn.y + 10, 20, WHITE);

        if (error) {
            DrawText("Incorrect credentials. Try again!", 250, 400, 20, RED);
        }

        EndDrawing();
    }

}
