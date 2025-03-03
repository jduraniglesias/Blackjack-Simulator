#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class MainMenu
{

public:
	MainMenu(float width, float height);
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int MainMenuPressed() {
		return MainMenuSelected;
	}
	~MainMenu();
private:
	int MainMenuSelected;
	Font font;
	vector<Text> mainMenu;
};

