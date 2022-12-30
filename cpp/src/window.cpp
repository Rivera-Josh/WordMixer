#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "window.h"
#include "word_magnet.h"


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
void setBackground(sf::RenderWindow* window, sf::Color backgroundColor){
    window->clear(backgroundColor);
}
//void draw(sf::RenderWindow* window, )
void display(sf::RenderWindow* window)
{
    sf::Color backgroundColor(0, 150, 0);

    

    window->display();
}