#include "MainMenu.h"


MainMenu::MainMenu(float width, float height) {
	if (!font.openFromFile("assets/ttfFont.ttf")) {
		cout << "Font not found!" << endl;
	}

	// Play
	Text playText(font, "Play", 70);
	playText.setFillColor(Color::White);
	playText.setPosition(Vector2f(100.f, 200.f));

	// Simulate
	Text simulateText(font, "Simulate", 70);
	simulateText.setFillColor(Color::White);
	simulateText.setPosition(Vector2f(100.f, 300.f));

	// Exit
	Text exitText(font, "Exit", 70);  // Changed variable name to exitText
	exitText.setFillColor(Color::White);
	exitText.setPosition(Vector2f(100.f, 400.f));

	mainMenu.push_back(playText);
	mainMenu.push_back(simulateText);
	mainMenu.push_back(exitText);  // Now you have three items

	MainMenuSelected = 0;
	if (!mainMenu.empty()) {
		mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
	}
 }


MainMenu::~MainMenu() {

}

void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp() {
	mainMenu[MainMenuSelected].setFillColor(Color::White);
	if (MainMenuSelected == 0) {
		MainMenuSelected = mainMenu.size() - 1;
	}
	else {
		MainMenuSelected--;
	}	
	mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
}

void MainMenu::MoveDown() {
	mainMenu[MainMenuSelected].setFillColor(Color::White);
	MainMenuSelected = (MainMenuSelected + 1) % mainMenu.size();
	mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
}