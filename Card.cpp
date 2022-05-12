#include <string>
#include "Card.h"
using namespace std;

// constructor
//0-12 跟 0-3
Card:: Card(int cardFace = 0 , int cardSuit = 0){  //!這邊預設        0-spade 黑桃      1-heart 紅心      2-diamond 方塊      3-club 梅花
	(*this).face = cardFace;
	(*this).suit = cardSuit;
}

// copy constructor  //FIXME:這是我額外多加的，是必要的嗎?
Card:: Card(const Card & right){
	(*this).face = right.face;
	(*this).suit = right.suit;
}

int Card:: getFace(void) const{
   return (*this).face;  //int 0-12
}

int Card:: getSuit(void) const{
   return (*this).suit; //int 0-3
}

// set the card's face  //?我自己新增的，因為那兩個是private，外部改不了值，會讓deck constructor無法做事
void Card:: setFace(int fa){
	(*this).face = fa;
};

// set the card's suit  //?我自己新增的，因為那兩個是private，外部改不了值，會讓deck constructor無法做事
void Card:: setSuit(int su){
	(*this).suit = su;
};

//return type: string
string Card:: toString(void) const {  //?hi 10 const
	return (*this).faceNames[getFace()] + " of " + (*this).suitNames[getSuit()] + "\n";
	//ex:  faceNames[0] + "of" + suitNames[1];
}

//static const string initialization
//----------------------------------------------------------------------------------------------------
const string Card:: faceNames[ totalFaces ]={
	"Ace",  "Deuce",  "Three",  "Four",  "Five",	// decimal number 0-4
	"Six",  "Seven",  "Eight",  "Nine",  "Ten",     // decimal number 5-9
	"Jack", "Queen",  "King" 						// decimal number 10-12
};

const string Card:: suitNames[ totalSuits ]={  //?spade 黑桃    heart 紅心    diamond 方塊    club 梅花
	"spade",    // decimal number  0
	"heart",    // decimal number  1
	"diamond",  // decimal number  2
	"club"		// decimal number  3
};
//----------------------------------------------------------------------------------------------------
