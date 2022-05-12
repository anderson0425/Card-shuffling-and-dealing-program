// 測試 Hand object
#include <iostream>
#include <iomanip>
#include "Card.h"
#include "DeckOfCards.h" // DeckOfCards class definition
using namespace std;

int main(){

    DeckOfCards D1; //牌組
    D1.print_DeckOfCards();

    D1.shuffle(); //洗牌
    D1.print_DeckOfCards();

    Card c1 = D1.dealCard(); //抽牌--這裡INDEX=0的值，應該要在接下來的抽牌前後都不會變動

    D1.shuffle(); //洗牌
    D1.print_DeckOfCards();

    Card c2;
    int i=0;
    while (1){
        c2 = D1.dealCard();
        i++;

        if(i==50)  cout <<"at"<< i << D1.moreCards();
        else if(i==51)  cout <<"at"<< i << D1.moreCards();
        else break;

        if(D1.moreCards()==false){
            cout<< "empty at "<< i <<"\n"; 
            break;
        }
    }
    
}



//Card dealCard(); 
