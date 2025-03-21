#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "SimulateMenu.h"
#include "PlayMenu.h"
#include "Game.h"

enum class GameState { MAIN_MENU, PLAY, SIMULATE, GAME };

int main() {
    sf::RenderWindow window(sf::VideoMode({ 960, 720 }), "Game");
    sf::RectangleShape menuBackground;
    sf::RectangleShape settingsBackground;
    sf::RectangleShape gameBackground;
    menuBackground.setSize(sf::Vector2f(960.f, 720.f));
    settingsBackground.setSize(sf::Vector2f(960.f, 720.f));
    gameBackground.setSize(sf::Vector2f(960.f, 720.f));
    sf::Texture menuBackgroundImage;
    sf::Texture settingsBackgroundImage;
    sf::Texture gameBackgroundImage;
    menuBackgroundImage.loadFromFile("assets/mainMenuBackground.jpg");
    settingsBackgroundImage.loadFromFile("assets/settingsBackground.png");
    gameBackgroundImage.loadFromFile("assets/gameBackground.png");
    menuBackground.setTexture(&menuBackgroundImage);
    settingsBackground.setTexture(&settingsBackgroundImage);
    gameBackground.setTexture(&gameBackgroundImage);

    MainMenu mainMenu(960, 720);
    SimulateMenu simulateMenu(960, 720);
    PlayMenu playMenu(960, 720);
    Game gameScreen(960, 720);
    
    GameState currState = GameState::MAIN_MENU;

    window.setMouseCursorVisible(true);
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            switch (currState) {
            case GameState::MAIN_MENU:
                mainMenu.handleEvent(*event, window);
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButton->button == sf::Mouse::Button::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        MainMenu::Option selected = mainMenu.getSelectedOption();
                        if (mainMenu.getSelectedOptionPos().contains(static_cast<sf::Vector2f>(mousePos))) {
                            if (selected == MainMenu::Option::PLAY) {
                                currState = GameState::PLAY;
                            }
                            else if (selected == MainMenu::Option::SIMULATE) {
                                currState = GameState::SIMULATE;
                            }
                            else if (selected == MainMenu::Option::EXIT) {
                                window.close();
                            }
                        }
                    }
                }
                break;

            case GameState::SIMULATE:
                simulateMenu.handleEvent(*event, window);
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButton->button == sf::Mouse::Button::Left) {
                        SimulateMenu::Option selected = simulateMenu.getSelectedOption();
                        if (selected == SimulateMenu::Option::BACK) {
                            currState = GameState::MAIN_MENU;
                        }
                    }
                }
                break;

            case GameState::PLAY:
                playMenu.handleEvent(*event, window);
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButton->button == sf::Mouse::Button::Left) {
                        PlayMenu::Option selected = playMenu.getSelectedOption();
                        if (selected == PlayMenu::Option::BACK) {
                            currState = GameState::MAIN_MENU;
                        }
                        else if (selected == PlayMenu::Option::START) {
                            currState = GameState::GAME;
                        }
                    }
                }
                break;
            case GameState::GAME:
                gameScreen.handleEvent(*event, window);
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButton->button == sf::Mouse::Button::Left) {
                        Game::Option selected = gameScreen.getSelectedOption();
                        if (selected == Game::Option::SKIP) {
                            currState = GameState::MAIN_MENU;
                        }
                    }
                }
                break;
            }
            
        }

        window.clear();
        switch (currState) {
        case GameState::MAIN_MENU:
            window.draw(menuBackground);
            mainMenu.draw(window);
            break;
        case GameState::SIMULATE:
            window.draw(settingsBackground);
            simulateMenu.draw(window);
            break;
        case GameState::PLAY:
            window.draw(settingsBackground);
            playMenu.draw(window);
            break;
        case GameState::GAME:
            window.draw(gameBackground);
            gameScreen.draw(window);
            break;
        }

        window.display();
    }
    return 0;
}
