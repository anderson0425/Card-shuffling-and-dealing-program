// 測試 Card object

#include "Card.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){

    //Card(int cardFace = 12 , int cardSuit = 0)
    Card c1(0,  3); //  "Ace",      "club"
    Card c2(11, 2); //  "Queen",    "diamond"
    Card c3(12, 0); //  "King",     "spade"

    cout<< "\nc1: " << c1.toString() << "\n";
    cout<< "\nc2: " << c2.toString() << "\n";
    cout<< "\nc3: " << c3.toString() << "\n";

} // end main

