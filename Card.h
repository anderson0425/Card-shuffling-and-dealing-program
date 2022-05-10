// Exercise 10.10 Solution: Card.h
//todo: Class Card represents the face and suit of a card.
//! 什麼是the face and suit of a card?

//* 最小

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card{

   public:
        static const int totalFaces = 13; // total number of faces      //! 數字1-13
        static const int totalSuits = 4; // total number of suits花色   //! spade 黑桃    heart 紅心    diamond 方塊    club 梅花

      Card( int , int ); // initialize face and suit
      string toString(); // returns a string representation of a Card

      // get the card's face
      int getFace() const{
         return face;
      } // end function getFace

      // get the card's suit
      int getSuit() const{
         return suit;
      } // end function getSuit

   private:
      int face;
      int suit;

      static const string faceNames[ totalFaces ];
      static const string suitNames[ totalSuits ];

}; // end class Card



					
   												
#endif