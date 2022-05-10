// Exercise 10.10 Solution: DeckOfCards.h
//todo:  Class DeckOfCards represents a deck of 52 playing cards.

//* 最大

#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "Card.h"
using namespace std;

// DeckOfCards class definition
class DeckOfCards{

   public:
      DeckOfCards(); // constructor initializes deck
      void shuffle(); // shuffles cards in deck
      Card dealCard(); // deals cards in deck
      bool moreCards() const; // are there any more cards left

   private:
      vector< Card > deck; // represents deck of cards
      unsigned currentCard; // index of next card to be dealt

}; // end class DeckOfCards




#endif
