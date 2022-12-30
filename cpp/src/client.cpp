
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include "window.h"
#include "word_magnet.h"
#include "getWord.h"
using namespace std;



int main(){
    sf::Color BACKGROUND_COLOR(0,150,0);
    sf::RenderWindow* window = setupGraphics(false);

    vector<string> wordList(getWordList());

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(sf::IpAddress(127,0,0,1), 53000);
    if (status != sf::Socket::Status::Done){
        cout << "Error: Cannot connect" << endl;
    }
    else{
        cout << "Connected!" << endl;
    }

    sf::Font font;
    
    // word player must guess
    string word;

    //creates an empty packet
    sf::Packet packet;
    //looks for a packet to recieve from this socket connection
    socket.receive(packet);
    //packet now holds the word which is stored in word
    packet >> word;
    cout << word << endl;
    if(!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")){
        throw runtime_error("Font not loaded");
    };
    //list to store chosen words
    vector<WordMagnet> wordMagnetList;
    //set magnet words into a class
    for (int i=0; i<40; i++){
        
        wordMagnetList.push_back(WordMagnet(wordList[i], &font));

    }

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
        setBackground(window, BACKGROUND_COLOR);

        sf::Vector2u windowSize(window->getSize());


        sf::Vector2f drawPosition(20,20);
        for (int i =0; i < 40; i++){
            
            wordMagnetList[i].draw(window, drawPosition);
            drawPosition.x += wordMagnetList[i].magnetBox.getSize().x+20;
            if (drawPosition.x > (windowSize.x-wordMagnetList[i].magnetBox.getSize().x)){
                drawPosition.x=20;
                drawPosition.y+= wordMagnetList[i].magnetBox.getSize().y+20;
            }
        }
        display(window);
    }
}


