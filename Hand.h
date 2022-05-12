// Exercise 10.11 Solution: Hand.h
//todo:  Stores and calculates attributes of a hand of cards.
//!手上目前的所有卡片的特質

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

      Hand(const Hand & right); // copy constructor   //FIXME:這是我額外多加的，是必要的嗎?

      // determine if we have the given scoring hand
      bool pair() const;
      bool twoPair() const;
      bool threeOfAKind() const;
      bool fourOfAKind() const;
      bool flush() const;
      bool straight() const;

   private:
      //!想像成array
      vector< Card > hand; // our hand  //!想像成一個array，只是dtype是Card object    目前手上的卡片
      vector< int > faceCount; // number of each face  //!想像成一個array，只是dtype是int

}; // end class Hand

#endif



