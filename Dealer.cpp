#include"Dealer.h"
#include<iostream>

/*****************
 * constructor
 * **************/
Dealer::Dealer(){
   card_total = 0;
}

void Dealer::set_d_hand(Deck& cards){
   d_hand.add_card(cards.remove_card());
   card_total++;
   d_hand.add_card(cards.remove_card());
   card_total++;
   d_hand.set_face(1, false);
}

void Dealer::end_hand(Deck& cards){
   d_hand.set_face(1, true);
   if(d_hand.get_total() < 17){
      d_hand.add_card(cards.remove_card());
      card_total++;
   }
}

Hand Dealer::get_d_hand(){
   return d_hand;
}

void Dealer::set_card_total(int c){
   card_total = c;
}

int Dealer::get_card_total(){
   return card_total;
}

int Dealer::get_hand_total(){
   int s = d_hand.get_total();
   return s;
}

void Dealer::dealer_print(){
   std::cout<<"Dealer: cards: ";
   std::cout<<card_total <<" ";
   std::cout<<"hand:" <<std::endl;
   d_hand.print_hand();
}

/**********************
 * operator overloader
 * *******************/
void Dealer::operator=(const Dealer& other){
   d_hand = other.d_hand;
   card_total = other.card_total;
}

/****************
 * destructor
 * *************/
Dealer::~Dealer(){
   //std::cout<<"In dealer destructor"<<std::endl;
}
