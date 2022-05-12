#include <vector>
#include <cstdlib> // #include <stdlib.h>
#include <ctime>  // #include<time.h>
#include "Card.h"
#include "DeckOfCards.h"
#include<iostream>
using namespace std;
#include <stdio.h>
//#include <iomanip>

// constructor initializes deck
DeckOfCards:: DeckOfCards(void){ //!52張卡片，因此會生成有52個card object，並且初始化花色跟數字兩個int。 (0-12跟0-3)

    //查看目前分配到的記憶體空間大小
    cout << "\nSize : " << (*this).deck.size()<<"\n";
    cout << "Capacity : " << (*this).deck.capacity()<<"\n";
    cout << "Max_Size : " << (*this).deck.max_size()<<"\n";

    // fill the array with the values in order.
    //? i / 13 = j
    //? i % 13 = k
    int i=0;
    Card card_insert(1,1);  //vector.push_back()需要
	for(i=0;  i<52;  i++){  //?i = j * 13 + k
		card_insert.setSuit(i/13); //j
		card_insert.setFace(i%13); //k
        (*this).deck.push_back(card_insert);  //插入值且自動擴充記憶體  裡面要放符合dtype的資料，在這裡就是card object
	} 

	//for(int i=0;  i<52;  i++){  //?i = j * 13 + k
    //    for(int j=0;  j<13;  j++){ //0-12
    //        for(int k=0;  k<4;  k++){//0-4
	//	        (*this).deck[(13 * j + k)].setSuit(j); 
	//	        (*this).deck[(13 * j + k)].setFace(k); 
    //            //不能這樣寫  (*this).deck[(13*j+k)].suit = j;  //hi999 會出錯error  因為'int Card::suit' is private within this context
    //            //不能這樣寫  (*this).deck[(13*j+k)].face = k;  //hi999 會出錯error  因為'int Card::face' is private within this context
    //
    //        }
    //    }
	//} 
    // i = j * 13 + k
    // (*this).deck[i].suit = j;  (*this).deck[i].face = k;

    ////印出最一開始的牌組
    //cout<<"after constructed, DeckofCards now is...\n\n";
	//(*this).print_DeckOfCards();

    //todo:      unsigned currentCard;   這裡要怎麼設定?又是什麼意思?
    (*this).currentCard = 0;  //FIXME:假設牌組最上面的牌的index=0，這裡將下一個抽牌的index設為0------使得接下抽出的牌是(*this).deck[i]

    //查看目前分配到的記憶體空間大小
    cout << "\nSize : " << (*this).deck.size()<<"\n";
    cout << "Capacity : " << (*this).deck.capacity()<<"\n";
    cout << "Max_Size : " << (*this).deck.max_size()<<"\n";

}

//自己新增的--印出牌組
void DeckOfCards:: print_DeckOfCards(void) const{
	for(int i=0;   i < ((*this).deck.size());   i++)
		cout << i << "\t" << (*this).deck[i].toString(); 
    cout << "\n";
    cout << "currentCard of Deck: " << (*this).currentCard << "\n\n";
}

// 洗牌
//currentCard = 0，表示沒有牌被取走。
//currentCard = 2，表示2張卡片被取走，因此接下來洗牌只能從currentCard開始洗
void DeckOfCards:: shuffle(void){

    //洗牌演算法
    //    Go through the array and exchange each element 
    //    with the randomly chosen element in the range 
    //    from itself to the end.
    int random_index = 0;
    int temp_suit, temp_face;
    srand(time(0));  //seed
    for(int i = (*this).currentCard;   i<52;   i++){  //修掉  for(int i=0;  i<52;  i++){
        //使隨機數在自身index到51之間------0: 0-51     1: 1-51     50: 50-51
        random_index = (i + (rand()%(52-i)));  //限制隨機數範圍在 " i 到 51 之間" (不包含52)

        ////swap deck[i] with deck[random_index],  where random_index >= i.
        //temp_suit = (*this).deck[i].suit; //hi999 會出錯error  因為'int Card::suit' is private within this context
        //temp_face = (*this).deck[i].face; //hi999 會出錯error  因為'int Card::face' is private within this context
        //(*this).deck[i].suit = (*this).deck[random_index].suit; //hi999 會出錯error  因為'int Card::suit' is private within this context
        //(*this).deck[i].face = (*this).deck[random_index].face; //hi999 會出錯error  因為'int Card::face' is private within this context
        //(*this).deck[random_index].suit = temp_suit; //hi999 會出錯error  因為'int Card::suit' is private within this context
        //(*this).deck[random_index].face = temp_face; //hi999 會出錯error  因為'int Card::face' is private within this context


        //swap deck[i] with deck[random_index],  where random_index >= i.
        temp_suit = (*this).deck[i].getSuit(); //hi999 會出錯error  因為'int Card::suit' is private within this context
        temp_face = (*this).deck[i].getFace(); //hi999 會出錯error  因為'int Card::face' is private within this context
        (*this).deck[i].setSuit(  (*this).deck[random_index].getSuit()  ); //hi999 會出錯error  因為'int Card::suit' is private within this context
        (*this).deck[i].setFace(  (*this).deck[random_index].getFace()  ); //hi999 會出錯error  因為'int Card::face' is private within this context
        (*this).deck[random_index].setSuit(  temp_suit  ); //hi999 會出錯error  因為'int Card::suit' is private within this context
        (*this).deck[random_index].setFace(  temp_face  ); //hi999 會出錯error  因為'int Card::face' is private within this context
    }
}

//發牌   //FIXME:可能發超過1張??
Card DeckOfCards:: dealCard(void){ 
    //int current_index = (*this).currentCard;
    //((*this).currentCard) ++;  //next-index
    //
    ////把那時候在牌組最上面的那一張卡片拿出來---跑去hand object
    //return (*this).deck[current_index]; 

    return deck[ (*this).currentCard ++ ];  //先return，currentCard再做+1
}


//若是為true，表示牌組還有卡片  //FIXME:這裡的操作有點類似stack，雖然會把某個東西的值累加，但是deck內的值沒有被消失
bool DeckOfCards:: moreCards(void) const{
    // checks if DeckOfCards is empty or not
    if ((*this).currentCard < 52){  // if ((*this).deck.empty() == false){
        //cout << "\nDeckOfCards is not empty\n";
        cout << "\nnow index of Deck is: "<<(*this).currentCard <<"\n";
        return true;
    }   
    else{  //(*this)currentCard >= 52
        cout << "\nDeckOfCards is empty\n";
        return false;
    }
}
//-----------------------------------------------------------------------------------------------------------------


//DeckOfCards::DeckOfCards(){
//	for(int i=0; i<52; i++){
//		Card card(i% Card::totalFaces, i/Card::totalSuits);
//		deck.push_back(card);
//	}
//}

//void DeckOfCards::shuffle(){
//	
//	srand(time(0));
//	int swapRandom[52];
//	
//	for(int i=1; i<52; i++){
//		swapRandom[i]= int (rand())%52;
//	}
//	
//	for(int i=0 ;i<52 ;i++){
//		Card swapcard(0,0);
//		swapcard=deck[i];
//		deck[i]=deck[swapRandom[i]];
//		deck[swapRandom[i]]=swapcard;
//	}
//}