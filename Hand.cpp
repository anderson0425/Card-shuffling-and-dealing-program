#include <string>
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"
#include "Hand.h"
using namespace std;

Hand::Hand(DeckOfCards &deck){
	for(int i=0;i<5;i++){
		faceCount.at(i)=deck.;
		hand.push_back(deck);
	}
}

void Hand::print()const{
	;
}








//?--------------------------------------------------------------------------------------------------------------

// constructor takes 5 cards from Deck
Hand:: Hand( DeckOfCards &deck ){
	for(int i=0;  i<5;  i++){
		hand[i].suit = deck[i].suit;
		hand[i].face = deck[i].face;
	}  
	hand[0].suit = deck[0].suit

	//vector< Card > hand;            //!(*this).hand 可以想成Array  元素都是card obj
	//vector< int > faceCount;        //!(*this).faceCount 可以想成Array  元素都是int  //TODO: 猜測應該是跟卡片同index對應的卡片數字(1-13    0-12)

	// Reserve 52 card objects space for hand vector
	((*this).hand).reserve(52);      //保留52個card object的記憶體空間，但目前沒值
	((*this).faceCount).reserve(52);

	//初始化值
    for (int i = 0;  i < ((*this).hand).size();  i++){
		((*this).hand)[i] = ;
	}
        
	
	((*this).hand)
	((*this).faceCount)
}



		//hand
    	vector< Card > hand; // our hand  //!想像成一個array，只是dtype是Card object    目前手上的卡片
      	vector< int > faceCount; // number of each face  //!想像成一個array，只是dtype是int


		//card
      	int face;//這張卡的數字對應的index---用來從string Array中取出face string
      	int suit;//這張卡的花色對應的index---用來從string Array中取出suit string //!這邊預設        0-spade 黑桃      1-heart 紅心      2-diamond 方塊      3-club 梅花



void Hand:: print() const{ // display hand
    // Assign vector
    //vector<int> v;
	(*this).hand = 

    // fill the array with 10 five times
    v.assign(5, 10);
  
    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

// determine if we have the given scoring hand
bool Hand:: pair() const{

}

bool Hand:: twoPair() const{

}

bool Hand:: threeOfAKind() const{

}

bool Hand:: fourOfAKind() const{

}

bool Hand:: flush() const{

}

bool Hand:: straight() const{

}


//?--------------------------------------------------------------------------------------------------------------
































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



