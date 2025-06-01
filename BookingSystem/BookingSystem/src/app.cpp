#include "../include/app.h"

App::App() {
	InitWindow(800, 600, "Tick");
	SetTargetFPS(30);
	update();
}
void App::update() {
	while (!WindowShouldClose()) {
		display();
	}
	CloseWindow();
}
void App::display() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	pageHandler();
	EndDrawing();
}
void App::pageHandler() {
	if (pages.menuPageShouldDisplay) {
		menu.display(pages);
		menu.actionHandler(pages);
		return;
	}
	if (pages.registerPageShouldDisplay) {
		reg.display(pages);
		return;
	}
	if (pages.loginPageShouldDisplay) {
		login.display(pages);
		return;
	}
	if (pages.exitApp) {
		running = false;
		return;
	}
}