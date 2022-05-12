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

//?整個牌組
// DeckOfCards class definition
class DeckOfCards{

   public:
      DeckOfCards(void); // constructor initializes deck //!52張卡片，因此會生成有52個card object，並且初始化花色跟數字兩個int。 (0-12跟0-3)
      void shuffle(void); // shuffles cards in deck //FIXME:應該是不會改變整個牌組內容，但是會把currentCard這個INDEX重選一個數字  //!洗牌---會把DeckOfCards object內所有的card按照隨機數去重新排列------
      Card dealCard(void); // deals cards in deck //FIXME:如何給HAND?  //!抽牌?  回傳一張卡片到Hand object 
      bool moreCards(void) const; // are there any more cards left  //!牌組是否還有剩下的髂片，還是抽完了--------若是為1，表示還有卡片
      void print_DeckOfCards(void) const; //自己新增的

   private:
      vector< Card > deck; // represents deck of cards  //!DeckOfCards object一開始會有52個card objects
      unsigned currentCard; // index of next card to be dealt //FIXME:下一個被抽得牌的index，這裡有點看不懂意思

}; // end class DeckOfCards

#endif