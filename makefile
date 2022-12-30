CXX = g++
CXXFLAGS = -g -Wall -std=c++17

INC=-I/usr/include -I../common -I./
LIB=-L/usr/local/lib -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window -lbox2d

all: pre-build main-build

main-build: client server

client: bin/client

server: bin/server

clean:
	rm -f cpp/obj/*
	rm -rf bin/*
	rm -rf dist/*

pre-build:
	mkdir -p cpp/obj
	mkdir -p bin/
	mkdir -p dist/

cpp/obj/%.o: cpp/src/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@ $(INC)

bin/client: cpp/obj/client.o cpp/obj/window.o cpp/obj/word_magnet.o cpp/obj/getWord.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIB)

bin/server: cpp/obj/server.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIB)