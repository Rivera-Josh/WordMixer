#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "window.h"
sf::RenderWindow* setupGraphics(bool fullscreen)
{
    // if (!font.loadFromFile("Andale_Mono.ttf"))
    //     throw runtime_error("Can't load main font");

    auto flags =
        fullscreen ? sf::Style::Close | sf::Style::Fullscreen
                   : sf::Style::Close | sf::Style::Titlebar;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(1280, 720), 24), "Word Mixer", flags);
    window->setKeyRepeatEnabled(false);

    return window;
}

void display(sf::RenderWindow* window)
{
    sf::Color backgroundColor(0, 0, 50);
    window->clear(backgroundColor);

    // sf::CircleShape circle(10);
    // circle.setPosition(sf::Vector2f(x, 20));
    // circle.setFillColor(sf::Color::Red);
    // window->draw(circle);

    window->display();
}