#include "word_magnet.h"

WordMagnet::WordMagnet(string word, sf::Font* font)
{
    renderedText = sf::Text(sf::String("This can be spent or captured via Gateways"), *font, 16);
}

void WordMagnet::display(sf::RenderWindow* window, sf::Vector2f drawPos)
{
    
}