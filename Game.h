#include"Card.h"
#include"Deck.h"
#include"Player.h"
#include"Dealer.h"
#include<iostream>

class Game {
   private:
      Deck game_deck;
      Player *players;
      Dealer game_dealer;
      int num_players;
   public:
      /*constructor*/
      Game();
      /*makes and shuffles deck*/
      void set_game_deck(Deck);
      /*returns deck*/
      Deck get_game_deck();
      /*creates all players*/
      void set_players(Player*);
      /*returns player array*/
      Player* get_players();
      /*returns dealer*/
      Dealer get_game_dealer();
      /*returns number of players*/
      int get_num_players();
      /*sets number of players*/
      void set_num_players(int);
      /*get and validate bets*/
      void player_bets();
      /*initialize hands*/
      void start_round();
      /*deals cards to players*/
      void deal();
      /*checks for hands > 21*/
      void check_hands();
      /*ending*/
      void conclusion();
      /*print players info*/
      void players_print();
      /*operator overloader*/
      void operator=(const Game&);
      /*destructor*/
      ~Game();
};
