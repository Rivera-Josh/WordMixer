
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "window.h"
using namespace std;




int main(){
    sf::RenderWindow* window = setupGraphics(false);


    sf::Event e;

    while (window->isOpen()) { // This is the program's main loop

        while (window->pollEvent(e)) { // Event handling
            switch (e.type) {
                case sf::Event::MouseButtonPressed:
                    break;
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    break;
                default:
                    break;
            }
        }
    }
}


