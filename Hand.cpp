#include<iostream>
#include"./Card.h"
#include"./Hand.h"

Hand::Hand(){
   num_cards = 0;
   cards = NULL;
   total = 0;
}

Hand::Hand(const Hand &h){
   num_cards = h.num_cards;
   for(int i = 0; i < num_cards; i++){
      cards[i] = h.cards[i];
   }
}

void Hand::add_card(card c){
   card* temp;
   num_cards++;
   temp = cards;
   cards = new card[num_cards];
   for(int i = 0; i < num_cards-1; i++)
      cards[i] = temp[i];
   delete [] temp;
   cards[num_cards-1] = c;
   total += c.value;
}

card* Hand::get_cards() const{
   return cards;
}

void Hand::create_cards(const int num){
   num_cards = num;
   cards = new card[num];
}

int Hand::get_num_cards() const{
   return num_cards;
}

void Hand::set_face(int n, bool b){
   cards[n].face = b;
}

void Hand::set_total(int n){
   total += n;
}

int Hand::get_total(){
   return total;
}

void Hand::print_hand(){
   //std::cout<<"PRINT" <<std::endl;
   for(int i = 0; i < num_cards; i++){
      if(cards[i].face == true){
	 std::cout<<cards[i].suit <<" ";
	 std::cout<<cards[i].rank <<", ";
      }
   }
   std::cout<<std::endl;
}

void Hand::operator=(const Hand &h){
   num_cards = h.num_cards;
   for(int i = 0; i < num_cards; i++){
      cards[i] = h.cards[i];
   }
}

Hand::~Hand(){
   //std::cout<<"In Hand destructor" <<std::endl;
   delete [] cards;
}
