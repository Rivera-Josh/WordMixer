#ifndef WINDOW_H
#define WINDOW_H

#include "word_magnet.h"

#include <SFML/Graphics.hpp>
sf::RenderWindow* setupGraphics(bool fullscreen);
void display(sf::RenderWindow* window);
void setBackground(sf::RenderWindow* window, sf::Color backgroundColor);
#endif