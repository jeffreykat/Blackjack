#include"./Card.h"
#include"./Deck.h"
#include"./Hand.h"
#include<string.h>
#include<iostream>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
   public:
      /*constructor*/
      Player();
      /*sets player name*/
      void set_name(std::string);
      /*returns player name*/
      std::string get_name();
      void set_p_hand(Deck&);
      Hand get_p_hand();
      void set_initial_p_hand(Deck&);
      void set_playing_total(double);
      double get_playing_total();
      void set_card_total(int);
      int get_card_total();
      void set_bet(double);
      double get_bet();
      int get_hand_total();
      void print();
      void operator=(const Player&);
      ~Player();
   private:
      std::string name;
      Hand p_hand;
      double playing_total;
      int card_total;
      double bet;
};

#endif
