#include"Card.h"
#include"Hand.h"
#include"Deck.h"

class Dealer{
   private:
      Hand d_hand;
      int card_total;
   public:
      Dealer();
      void set_d_hand(Deck&);
      void end_hand(Deck&);
      Hand get_d_hand();
      void set_card_total(int);
      int get_card_total();
      int get_hand_total();
      void dealer_print();
      void operator=(const Dealer&);
      ~Dealer();
};
