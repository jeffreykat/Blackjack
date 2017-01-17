CXX = g++

default: Game.h Game.cpp Deck.h Deck.cpp Hand.h Hand.cpp Player.h Player.cpp Dealer.h Dealer.cpp
	${CXX} Game.cpp Deck.cpp Hand.cpp Player.cpp Dealer.cpp -o play

Game.o: Game.cpp
	${CXX} Game.cpp -c

Deck.o: Deck.cpp
	${CXX} Deck.cpp -c

Hand.o: Hand.cpp
	${CXX} Hand.cpp -c
