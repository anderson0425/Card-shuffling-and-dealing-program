#include <vector>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards(){
	for(int i=0; i<52; i++){
		Card card(i% Card::totalFaces, i/Card::totalSuits);
		deck.push_back(card);
	}
}

void DeckOfCards::shuffle(){
	
	srand(time(0));
	int swapRandom[52];
	
	for(int i=1; i<52; i++){
		swapRandom[i]= int (rand())%52;
	}
	
	for(int i=0 ;i<52 ;i++){
		Card swapcard(0,0);
		swapcard=deck[i];
		deck[i]=deck[swapRandom[i]];
		deck[swapRandom[i]]=swapcard;
	}
}

Card DeckOfCards::dealCard(){
	return deck[currentCard++];
}

bool DeckOfCards::moreCards() const{
	if(currentCard<=52)
		return true;
	else
		return false;
}
