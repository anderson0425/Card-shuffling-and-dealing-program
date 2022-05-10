//! 測試 Card object

#include "Card.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    Card

    DeckOfCards myDeckOfCards;
    myDeckOfCards.shuffle(); // place Cards in random order

    Hand hand( myDeckOfCards ); // deal a hand from the deck
    hand.print(); // display hand

    // check for each type of hand by decreasing ranking
    if ( hand.fourOfAKind() )
        cout << "Hand contains four of a kind" << endl;
    else if ( hand.flush() )
        cout << "Hand contains a flush" << endl;
    else if ( hand.straight() )
        cout << "Hand contains a straight" << endl;
    else if ( hand.threeOfAKind() )
        cout << "Hand contains three of a kind" << endl;
    else if ( hand.twoPair() )
        cout << "Hand contains two pairs" << endl;
    else if ( hand.pair() )
        cout << "Hand contains a pair" << endl;
      
} // end main



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
       int face;//這1張卡片的數字
       int suit;//這1張卡片的花色

       static const string faceNames[ totalFaces ];//這1張卡片的數字對應的數字string
       static const string suitNames[ totalSuits ];//這1張卡片的花色對應的花色string

}; // end class Card



					
   												
#endif