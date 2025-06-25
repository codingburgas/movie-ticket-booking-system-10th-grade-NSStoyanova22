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
	if (pages.dashboardPageShouldDisplay) {
		dash.display(pages);
		dash.actionHandler(pages);
		return;
	}
	if (pages.pickACinemaPageShouldDisplay) {
		pickC.display(pages);
		pickC.actionHandler(pages);
	}if (pages.pickAMovieShouldDisplay) {
		pickM.display(pages);
		pickM.actionHandler(pages);
	}
	if (pages.pickAShowPageShouldDisplay) {
		pickS.display(pages);
		pickS.actionHandler(pages);
		return;
	}
	if (pages.seatSelectionPageShouldDisplay) {
		seatS.display(pages);
		seatS.actionHandler(pages);
		return;
	}
	if (pages.exitApp) {
		running = false;
		return;
	}
}