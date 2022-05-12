// 測試 Hand object
#include <iostream>
#include <iomanip>
#include <string>
#include "DeckOfCards.h" // DeckOfCards class definition
#include "Hand.h" // Hand class definition
using namespace std;

int main(){

    DeckOfCards D1; //牌組
    cout << "\n>>after DeckOfCards constructed: \n";
    cout << "\nthe Deck: \n";
    D1.print_DeckOfCards();

    //Hand( DeckOfCards &deck );
    Hand h1(D1); //手牌: 一開始按照牌組的currentCard去抽依序的5張牌  [currentCard........(currentCard + 4)]      //FIXME:是這樣解讀嗎?
    h1.print();

//    D1.shuffle(); //洗牌
//    cout << "\n>>after shuffle: \n";
//    cout << "\nthe Deck: \n";
//    D1.print_DeckOfCards();
//
//    //Hand( DeckOfCards &deck );
//    Hand h1(D1); //手牌: 一開始按照牌組的currentCard去抽依序的5張牌  [currentCard........(currentCard + 4)]      //FIXME:是這樣解讀嗎?
//    h1.print();
}

