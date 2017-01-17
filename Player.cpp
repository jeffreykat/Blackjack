#include"./Player.h"
#include"./Hand.h"
#include<string.h>
#include<iostream>

Player::Player(){
   name = "";
   playing_total = 0;
   card_total = 0;
   bet = 0;
}

void Player::set_name(std::string s){
   name = s;
}

std::string Player::get_name(){
   return name;
}

void Player::set_p_hand(Deck& cards){
   p_hand.add_card(cards.remove_card());
   card_total++;
}

Hand Player::get_p_hand(){
   return p_hand;
}

void Player::set_initial_p_hand(Deck& cards){
   p_hand.add_card(cards.remove_card());
   card_total++;
   p_hand.add_card(cards.remove_card());
   card_total++;
}

void Player::set_playing_total(double p){
   playing_total = p;
}

double Player::get_playing_total(){
   return playing_total;
}

void Player::set_card_total(int c){
   card_total = c;
}

int Player::get_card_total(){
   return card_total;
}

void Player::set_bet(double b){
   bet = b;
}

double Player::get_bet(){
   return bet;
}

int Player::get_hand_total(){
   int s = p_hand.get_total();
   return s;
}

void Player::print(){
   p_hand.print_hand();
}

void Player::operator=(const Player& other){
   playing_total = other.playing_total;
   card_total = other.card_total;
   bet = other.bet;
   name = other.name;
   p_hand = other.p_hand;
}

Player::~Player(){
   //std::cout<<"In Player destructor"<<std::endl;
}
