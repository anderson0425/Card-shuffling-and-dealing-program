// 測試 Hand object
#include <iomanip>
#include "Card.h"
#include "DeckOfCards.h" // DeckOfCards class definition
#include<iostream>
using namespace std;
#include <vector>  //FIXME:這個要加嗎?

int main(){

    
    DeckOfCards D1; //牌組
    cout << "\n>>after DeckOfCards constructed: \n";
    cout << "\nthe Deck: \n";
    D1.print_DeckOfCards();

    
    D1.shuffle(); //洗牌
    cout << "\n>>after shuffle: \n";
    cout << "\nthe Deck: \n";
    D1.print_DeckOfCards();

    
    Card c1 = D1.dealCard(); //抽牌--這裡INDEX=0的值，應該要在接下來的抽牌前後都不會變動
    cout << "\n>>after deal Card: \n";
    cout << "\nthe Deck: \n";
    D1.print_DeckOfCards();
    cout << "the dealt Card: \t";
    cout << c1.toString();


    D1.shuffle(); //洗牌
    cout << "\n>>after shuffle: \n";
    cout << "\nthe Deck: \n";
    D1.print_DeckOfCards();
//
//    int i=0;
//    while (1){
//        c1 = D1.dealCard();
//        i++;
//
//        if(i==50)  cout <<"at"<< i << D1.moreCards();
//        else if(i==51)  cout <<"at"<< i << D1.moreCards();
//        else break;
//
//        if(D1.moreCards()==false){
//            cout<< "empty at "<< i <<"\n";
//            break;
//        }
//    }

}



//Card dealCard();
