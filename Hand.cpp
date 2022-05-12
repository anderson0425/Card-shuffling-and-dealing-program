#include <string>
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"
#include "Hand.h"
using namespace std;

// constructor takes 5 cards from Deck
//FIXME:把DECK前5個index的卡片傳給hand，並把那5個card從deck中移除。
Hand:: Hand( DeckOfCards &deck ){   

	//用從deck中拿出來的5張卡片的值做hand手中的卡片的初始化
	//一開始會從洗好的牌組裡抽5張卡片
	for(int i=0;  i<5;  i++){
		(*this).hand[i].suit = deck.deck[deck.currentCard + i].suit;  //這在Hand object裡面，因此hand可以直接取用，但是deck[i]裡面的值則應該不能直接取
		(*this).hand[i].face = deck.deck[deck.currentCard + i].face;  //這在Hand object裡面，因此hand可以直接取用，但是deck[i]裡面的值則應該不能直接取
    	
		(*this).faceCount[i] = deck.deck[deck.currentCard + i].face;  //同index的卡片的數字，但不知道為何要額外存
	}  

	deck.currentCard += 5  //由於取出5張，因此照理來說，應該有5張消失了  //FIXME:需要這段嗎?

	//將deck中拿出來的那5張卡片從牌組中移除--要pop嗎?還是只需要把deck.currentCard的值加5即可?  //FIXME:我猜只需要加5就好

	//印出手牌
	(*this).print();
}

// copy constructor   //FIXME:這是我額外多加的，是必要的嗎?
Hand:: Hand(const Hand & right){
	for (int i = 0;  i < (*this).hand.size();  i++){
		(*this).hand[i].face = right.hand[i].face;
		(*this).hand[i].suit = right.hand[i].suit;
	}
}

// display hand
void Hand:: print(void) const{ 
	cout << "In hand:\n";
	for(int i=0;   i < ((*this).hand.size());   i++)
		cout << i << "  " << (*this).hand[i].toString(); 
    cout << "\n";
}






//?--------------------------------------------------------------------------------------------------------------
// determine if we have the given scoring hand


bool Hand:: pair() const{

}


bool Hand:: twoPair() const{

}


bool Hand:: threeOfAKind() const{

}


bool Hand:: fourOfAKind() const{

}


bool Hand:: flush() const{

}


bool Hand:: straight() const{

}
//?--------------------------------------------------------------------------------------------------------------