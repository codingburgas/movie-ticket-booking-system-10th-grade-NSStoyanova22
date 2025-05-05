#include "../include/app.h"

App::App() {
	while (running) {
		pageHandler();
	}
}

void App::pageHandler() {
	if (pages.menuPageShouldDisplay) {
		menu.display();
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