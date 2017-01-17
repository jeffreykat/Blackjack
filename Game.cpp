#include<iostream>
#include<string.h>
#include"./Card.h"
#include"./Deck.h"
#include"Hand.h"
#include"./Game.h"

/******************************
 * Program: Game.cpp
 * Name: Katherine Jeffrey
 * Date: 4/25/2016
 * Description: Blackjack game
 * ***************************/


/******************
 * constructor
 * ***************/
Game::Game(){
   num_players = 0;
   players = NULL;
}

void Game::set_game_deck(Deck d){
   game_deck = d;
}

Deck Game::get_game_deck(){
   return game_deck;
}

void Game::set_players(Player* p){
   players = p;
}

Player* Game::get_players(){
   return players;
}

Dealer Game::get_game_dealer(){
   return game_dealer;
}

void Game::set_num_players(int num){
   num_players = num;
}

int Game::get_num_players(){
   return num_players;
}

void Game::operator=(const Game& other){
   game_deck = other.game_deck;
   players = other.players;
   game_dealer = other.game_dealer;
   num_players = other.num_players;
}

/***************
 * destructor
 * ************/
Game::~Game(){
   //std::cout<<"in Game destructor"<<std::endl;
   delete [] players;
}

void Game::player_bets(){
   double b;
   for(int i = 0; i < num_players; i++){
      do{
	 std::cout<<"Enter bet for " <<players[i].get_name() <<": ";
	 std::cin>>b;
	 if(b > players[i].get_playing_total())
	    std::cout<<"Bet is too high" <<std::endl;
      }
      while(b > players[i].get_playing_total());
      players[i].set_bet(b);
   }
}

void Game::start_round(){
   for(int i = 0; i < num_players; i++){
      players[i].set_initial_p_hand(game_deck); 
   }
   game_dealer.set_d_hand(game_deck);
}

void Game::deal(){
   std::string a;
   for(int i = 0; i < num_players; i++){
      do{
	 std::cout<<players[i].get_name() <<" card or pass? ";
	 std::cin>>a;
	 if(a == "card"){
	    players[i].set_p_hand(game_deck);
	    players[i].print();
	    std::cout<<players[i].get_hand_total() <<std::endl;
	 }
      }
      while(a == "card");
   }
   game_dealer.end_hand(game_deck);
   players_print();
   std::cout<<game_dealer.get_hand_total() <<std::endl;
}

void Game::check_hands(){
   for(int i = 0; i < num_players; i++){
      if(players[i].get_hand_total() > 21){
	 std::cout<<players[i].get_name() <<" loses." <<std::endl;
	 players[i].set_playing_total(players[i].get_playing_total() - players[i].get_bet());
      }
      if(players[i].get_hand_total() == 21){
	 std::cout<<players[i].get_name() <<" blackjack." <<std::endl;
	 players[i].set_playing_total(players[i].get_playing_total() + (players[i].get_bet()*1.5));
      }
   }
}

void Game::players_print(){
   std::cout<<std::endl;
   for(int i = 0; i < num_players; i++){
      std::cout<<players[i].get_name() <<": ";
      std::cout<<"amount total: " <<players[i].get_playing_total() <<", ";
      std::cout<<"cards: " <<players[i].get_card_total() <<", ";
      std::cout<<"hand: " <<players[i].get_hand_total() <<std::endl;;
      players[i].print();
      std::cout<<std::endl;
   }
   game_dealer.dealer_print();
   std::cout<<std::endl;
}

Player* player_info(int k){
   Player* temp = new Player[k];
   std::string n;
   double a;
   for(int i = 0; i < k; i++){
      std::cout<<"Enter Player's name: ";
      std::cin.ignore();
      std::getline(std::cin, n);
      temp[i].set_name(n);
      std::cout<<"Enter amount of money player starts with: ";
      std::cin>>a;
      temp[i].set_playing_total(a);
   }
   return temp;
}

void Game::conclusion(){
   if(game_dealer.get_hand_total() > 21){
      for(int i = 0; i < num_players; i++){
	 if(players[i].get_hand_total() < 21){
	    players[i].set_playing_total(players[i].get_playing_total() + players[i].get_bet());
	    std::cout<<players[i].get_name() <<" wins." <<std::endl;
	 }
      }
   }
   else{
      for(int j = 0; j < num_players; j++){
	 if(players[j].get_hand_total() < game_dealer.get_hand_total()){
	    players[j].set_playing_total(players[j].get_playing_total() - players[j].get_bet());
	    std::cout<<players[j].get_name() <<" loses." <<std::endl;
	 }
	 if(players[j].get_hand_total() > game_dealer.get_hand_total()){
	    players[j].set_playing_total(players[j].get_playing_total() + players[j].get_bet());
	    std::cout<<players[j].get_name() <<" wins." <<std::endl;
	 }
      }
   }
}

/**************
 * driver
 * ***********/
int main() {
   std::cout<<std::endl;
   std::cout<<"Welcome"<<std::endl;
   std::cout<<std::endl;
   Game game;
   Deck d;
   d.make_deck();
   d.shuffle();
   game.set_game_deck(d);
   game.get_game_deck().print();

   int n;
   std::cout<<"Enter number of players: ";
   std::cin>>n;
   game.set_num_players(n);
   Player* p = player_info(n);
   game.set_players(p);
   game.player_bets();
   game.start_round();

   game.players_print();
   game.get_game_deck().print();
   game.deal();
   game.check_hands();
   game.conclusion();
   game.players_print();

   return 0;
}
