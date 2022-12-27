#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
sf::RenderWindow* setupGraphics(bool fullscreen);
void display(sf::RenderWindow* window);
#endif