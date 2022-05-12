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
      //string array的size
      static const int totalFaces = 13; // total number of faces      //! 數字1-13
      static const int totalSuits = 4;  // total number of suits花色   //! spade 黑桃    heart 紅心    diamond 方塊    club 梅花

      Card(int cardFace, int cardSuit); // constructor: initialize face and suit
      Card(const Card & right); // copy constructor   //FIXME:這是我額外多加的，是必要的嗎?

      int getFace(void) const;// get the card's face
      int getSuit(void) const;// get the card's suit

      void setFace(int fa);// set the card's face  //?我自己新增的，因為那兩個是private，外部改不了值，會讓deck constructor無法做事
      void setSuit(int su);// set the card's suit  //?我自己新增的，因為那兩個是private，外部改不了值，會讓deck constructor無法做事

      string toString(void)const; // returns a string representation of a Card  //?hi 10 const

   private:
      int face;//這張卡的數字對應的index---用來從string Array中取出face string
      int suit;//這張卡的花色對應的index---用來從string Array中取出suit string //!這邊預設        0-spade 黑桃      1-heart 紅心      2-diamond 方塊      3-club 梅花

      //dtype為string的Array
      static const string faceNames[ totalFaces ];
      static const string suitNames[ totalSuits ];

}; // end class Card

#endif
