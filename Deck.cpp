/*
 * Name: Katherine Jeffrey
 * Date: 12/5/2015
 * Description: Deck object
 */

#include<string>
#include<stdlib.h> //rand
#include<time.h> //time
#include"Deck.h"
#include"Card.h"
#include<iostream>

/*****************************
 * Creates Deck of 52 cards
 * **************************/
Deck::Deck(){
   num_cards = 52; 
}

/**********************
 * num_cards mutator
 * *******************/
void Deck::set_num_cards(int set){
   num_cards = set;
}

/**********************
 * num_cards accessor
 * *******************/
int Deck::get_num_cards(){
   return num_cards;
}

card* Deck::get_deck(){
   return deck;
}

/*****************************
 * Fills deck with cards
 * **************************/
card* Deck::make_deck(){
   int c = 0;
   std::string suit[] = {"Spade", "Heart", "Club", "Diamond"};
   std::string rank[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 13; j++){
	 deck[c].suit = suit[i];
	 deck[c].rank = rank[j];
	 if(j < 10)
	    deck[c].value = j+1;
	 else
	    deck[c].value = 10;
	 deck[c].face = true;
	 c++;
      }
   }
   return deck;
}

/******************************
 * Shuffles deck into stack
 * ***************************/
void Deck::shuffle(){
   for(int i = num_cards-1; i > 0; i--){
      srand(time(NULL));
      int j = rand() % (i+1);//rand
      card temp = deck[i];
      deck[i] = deck[j];
      deck[j] = temp;
   }
   for(int i = 0; i <52; i++){
      card card = deck[i];
      deck[i] = card;//add to deck
   }
}

void Deck::print(){
   int count = 0;
   for(int c = 0; c < num_cards; c++){
      std::cout<<deck[c].suit <<" ";
      std::cout<<deck[c].rank <<", ";
      count++;
      if(count == 10){
	 std::cout<<std::endl;
	 count = 0;
      }
   }
   std::cout<<std::endl;
}

card Deck::remove_card(){
   num_cards--;
   return deck[num_cards];
}

/**********************
 * operator overloader
 * *******************/
void Deck::operator=(const Deck& other){
   num_cards = other.num_cards;
   for(int i = 0; i < num_cards; i++){
      deck[i] = other.deck[i];
   }
}

/***********************
 * Deck Destructor
 * ********************/
Deck::~Deck(){
   //std::cout<<"In deck destructor" <<std::endl;
}
