// Exercise 10.11 Solution: ex10_11.cpp
// Card shuffling and dealing program.
//! driver program

#include <iostream>
#include <iomanip>
#include "DeckOfCards.h" // DeckOfCards class definition
#include "Hand.h" // Hand class definition
using namespace std;

int main(){

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