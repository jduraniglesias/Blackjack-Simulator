#include <SFML/Graphics.hpp>
#include "MainMenu.h"

// TO:DO Error with running code, planning on taking a look tmmr (3/3/25)

int main()
{
    sf::RenderWindow menu(sf::VideoMode({ 960, 720 }), "Main Menu");
    MainMenu mainMenu(menu.getSize().x, menu.getSize().y);
    RectangleShape background;
    background.setSize(Vector2f(960.f, 720.f));
    Texture backgroundImage;
    backgroundImage.loadFromFile("assets/mainMenuBackground.jpg");
    background.setTexture(&backgroundImage);

    while (menu.isOpen())
    {
        while (auto event = menu.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                menu.close();
            }

            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                if (keyReleased->scancode == sf::Keyboard::Scancode::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if (keyReleased->scancode == sf::Keyboard::Scancode::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if (keyReleased->scancode == sf::Keyboard::Scancode::Enter) {
                    RenderWindow Play(VideoMode({ 960, 720 }), "blackjack_menu");
                    RenderWindow Simulate(VideoMode({ 960, 720 }), "blackjack_simulate_menu");
                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) {
                        while (Play.isOpen()) {
                            
                            while (auto event = Play.pollEvent()) {
                                if (event->is <sf::Event::Closed>()) {
                                    Play.close();
                                }
                                if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                                    if (keyReleased->scancode == sf::Keyboard::Scancode::Escape) {
                                        Play.close();
                                    }
                                }
                            }
                            Play.clear();
                            Play.display();
                        }
                    }
                    if (x == 1) {
                        while (Simulate.isOpen()) {
                            while (auto event = Simulate.pollEvent()) {
                                if (event->is <sf::Event::Closed>()) {
                                    Simulate.close();
                                }
                                if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                                    if (keyReleased->scancode == sf::Keyboard::Scancode::Escape) {
                                        Play.close();
                                    }
                                }
                            }
                            Play.close();
                            Simulate.clear();
                            Simulate.display();
                        }
                    }
                    if (x == 2) {
                        menu.close();
                    }
                    break;
                }
            }
        }

        menu.clear();
        menu.draw(background);
        mainMenu.draw(menu);
        menu.display();
    }
}