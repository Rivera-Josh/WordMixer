#include <iostream>
#include <SFML/Network.hpp>

using namespace std;

int main() {
    sf::TcpListener listener;

    // bind the listener to a port
    if (listener.listen(53000) != sf::Socket::Status::Done)
    {
        cout << "listen error" << endl;
    }

    // accept a new connection
    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Status::Done)
    {
        cout << "accept error" << endl;
    }

    string data("whats a good hangman phrase");
    sf::Packet packet;
    packet << data;
    client.send(packet);

    cout << "Done" << endl;}