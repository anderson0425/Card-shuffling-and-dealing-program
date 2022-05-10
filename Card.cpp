#include <string>
#include "Card.h"
using namespace std;

Card::Card(int cardFace, int cardSuit){
	face=cardFace;
	suit=cardSuit;
}

string Card::toString() {
	return faceNames[getFace()] + "of" + suitNames[getSuit()];
}

const string Card::faceNames[ totalFaces ]={"Ace","Deuce","Three","Four","Five","Six",
   											"Seven","Eight","Nine","Ten","Jack","Queen","King"};
const string Card::suitNames[ totalSuits ]={"spade",  "heart",  "diamond",  "club"};  //?spade 黑桃    heart 紅心    diamond 方塊    club 梅花

