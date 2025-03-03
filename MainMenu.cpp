#include "MainMenu.h"


MainMenu::MainMenu(float width, float height) {
	if (!font.openFromFile("ttfFont.ttf")) {
		cout << "Font not found!" << endl;
	}

	//Play
	Text playText(font, "Play", 70);
	playText.setFillColor(Color::White);
	playText.setPosition(Vector2f(400.f, 200.f));

	//Simulate
	Text simulateText(font, "Simulate", 70);
	simulateText.setFillColor(Color::White);
	simulateText.setPosition(Vector2f(400.f, 300.f));

	//Exit
	Text simulateText(font, "Exit", 70);
	simulateText.setFillColor(Color::White);
	simulateText.setPosition(Vector2f(400.f, 400.f));

	mainMenu.push_back(playText);
	mainMenu.push_back(simulateText);

	MainMenuSelected = -1;
}

MainMenu::~MainMenu() {

}

void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp() {
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 3) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}