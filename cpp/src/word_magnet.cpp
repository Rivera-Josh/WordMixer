#include "word_magnet.h"
#include <iostream>
using namespace std;
WordMagnet::WordMagnet(string word, sf::Font* font){

    renderedText = sf::Text(sf::String(word), *font, 16);
    renderedText.setFillColor(sf::Color::Black);

    sf::Vector2f rectSize(renderedText.getLocalBounds().width+20, renderedText.getLocalBounds().height+30);

    magnetBox = sf::RectangleShape(rectSize);
    //magnetBox.setSize(rectSize);
    
    magnetBox.setFillColor(sf::Color::White);
}


void WordMagnet::draw(sf::RenderWindow* window, sf::Vector2f drawPos){

    magnetBox.setPosition(sf::Vector2f(drawPos.x-10, drawPos.y-15));
    renderedText.setPosition(drawPos);
    window->draw(magnetBox);
    window->draw(renderedText);
}