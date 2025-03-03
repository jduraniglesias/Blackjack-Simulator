#include <SFML/Graphics.hpp>
#include "MainMenu.h"

// TO:DO Error with running code, planning on taking a look tmmr (3/3/25)

int main()
{
    sf::RenderWindow menu(sf::VideoMode({ 960, 720 }), "Main Menu");
    MainMenu mainMenu(menu.getSize().x, menu.getSize().y);

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
                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) {
                        while (Play.isOpen()) {
                            
                            while (auto event2 = Play.pollEvent()) {
                                if (event2->is < sf::Event::Closed>()) {
                                    Play.close();
                                }
                                if (const auto* keyReleased2 = event2->getIf<sf::Event::KeyReleased>()) {
                                    if (keyReleased2->scancode == sf::Keyboard::Scancode::Escape) {
                                        Play.close();
                                    }
                                }
                            }
                            Play.clear();
                            Play.display();
                        }
                    }
                }
            }
        }

        menu.clear();
        mainMenu.draw(menu);
        menu.display();
    }
}