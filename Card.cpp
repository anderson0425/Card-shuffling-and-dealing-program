#include <string>
#include "Card.h"
using namespace std;

//0-12 跟 0-3
Card::Card(int cardFace = 0 , int cardSuit = 0){  //!這邊預設        0-spade 黑桃      1-heart 紅心      2-diamond 方塊      3-club 梅花
	(*this).face = cardFace;
	(*this).suit = cardSuit;
}

int Card::getFace(void) const{
   return (*this).face;  //int 0-12
}

int Card::getSuit(void) const{
   return (*this).suit; //int 0-3
}

//return type: string
string Card::toString(void) {
	return (*this).faceNames[getFace()] + " of " + (*this).suitNames[getSuit()];
	//ex:  faceNames[0] + "of" + suitNames[1];
}

//static const string initialization
//----------------------------------------------------------------------------------------------------
const string Card::faceNames[ totalFaces ]={
	"Ace",  "Deuce",  "Three",  "Four",  "Five",	// decimal number 0-4
	"Six",  "Seven",  "Eight",  "Nine",  "Ten",     // decimal number 5-9
	"Jack", "Queen",  "King" 						// decimal number 10-12
};

const string Card::suitNames[ totalSuits ]={  //?spade 黑桃    heart 紅心    diamond 方塊    club 梅花
	"spade",    // decimal number  0
	"heart",    // decimal number  1
	"diamond",  // decimal number  2
	"club"		// decimal number  3
};
//----------------------------------------------------------------------------------------------------
