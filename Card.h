/*
 * Name: Katherine Jeffrey
 * Date: 12/3/2015
 * Description: Header file for Card struct
 */

#include<string>

#ifndef CARD_H
#define CARD_H

struct card {
   std::string suit;
   std::string rank;
   bool face;//true is up
   int value;
} ;

#endif
