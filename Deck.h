/*
 * Name: Katherine Jeffrey
 * Date: 12/5/2015
 * Description: Deck class
 */

#include"./Card.h"

#ifndef DECK_H
#define DECK_H

class Deck{
   public:
      Deck();//object
      card* make_deck();
      card* get_deck();
      void set_num_cards(int);
      int get_num_cards();
      void shuffle();
      void print();
      card remove_card();
      void operator=(const Deck&);
      ~Deck();
   private:
      card deck[52];
      int num_cards;
};

#endif
