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

    D1.shuffle(); //洗牌
    cout << "\n>>after shuffle: \n";
    cout << "\nthe Deck: \n";
    D1.print_DeckOfCards();

    //抽5張牌(抽到的5張是牌組最上方的5張)
    //Hand( DeckOfCards &deck );
    Hand h1(D1); //手牌: 一開始按照牌組的currentCard去抽依序的5張牌  [currentCard........(currentCard + 4)] //!hand construction要成功超級困難，但成功了ㄏㄏ
    h1.print();  //印出5張手牌

    //接下來要測試
    cout<<"\n";
    if(h1.pair()==true)         cout<<"got pair !!\t";
    if(h1.twoPair()==true)      cout<<"got twoPair !!\t";
    if(h1.threeOfAKind()==true) cout<<"got threeOfAKind !!\t";
    if(h1.fourOfAKind()==true)  cout<<"got fourOfAKind !!\t";
    if(h1.flush()==true)        cout<<"got flush !!\t";
    if(h1.straight()==true)     cout<<"got straight !!\t";
    cout<<"\n";

}

