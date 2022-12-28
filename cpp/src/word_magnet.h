#include <string>
#include <SFML/Graphics.hpp>

#ifndef WORD_MAGNET_H
#define WORD_MAGNET_H

using namespace std;

class WordMagnet
{
public:
    sf::Text renderedText;
    WordMagnet(string word, sf::Font* font);
    void display(sf::RenderWindow* window, sf::Vector2f drawPos);
};

#endif // WORD_MAGNET_H