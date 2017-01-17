#include<iostream>
#include<string>
#include"./Card.h"

#ifndef HAND_H
#define HAND_H

class Hand {
   private:
      int num_cards;
      card *cards;
      int total;
   public:
      Hand();
      Hand(const Hand &);
      void add_card(card);
      card* get_cards() const;
      void create_cards(const int);
      int get_num_cards() const;
      void set_face(int, bool);
      void set_total(int);
      int get_total();
      void print_hand();
      void operator=(const Hand &);
      ~Hand();
};

#endif
