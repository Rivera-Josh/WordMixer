
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "window.h"
using namespace std;




int main(){
    sf::RenderWindow* window = setupGraphics(false);

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(sf::IpAddress(127,0,0,1), 53000);
    if (status != sf::Socket::Status::Done){
        cout << "Error: Cannot connect" << endl;
    }
    else{
        cout << "Connected!" << endl;
    }
    
    // word player must guess
    string word;

    //creates an empty packet
    sf::Packet packet;
    //looks for a packet to recieve from this socket connection
    socket.receive(packet);
    //packet now holds the word which is stored in word
    packet >> word;
    cout << word << endl;

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
        display(window);
    }
}


