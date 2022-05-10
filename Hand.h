// Exercise 10.11 Solution: Hand.h
//todo:  Stores and calculates attributes of a hand of cards.
//!5張卡片的特質

//* 中間

#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

class Hand{

   public:
      // constructor takes 5 cards from Deck
      Hand( DeckOfCards &deck );
      void print() const; // display hand

      // determine if we have the given scoring hand
      bool pair() const;
      bool twoPair() const;
      bool threeOfAKind() const;
      bool fourOfAKind() const;
      bool flush() const;
      bool straight() const;

   private:
      vector< Card > hand; // our hand
      vector< int > faceCount; // number of each face

}; // end class Hand

#endif



