#include <string>
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"
#include "Hand.h"
#include<iostream>
//#include <iomanip>
using namespace std;

#include <stdio.h>

vector< int >&  insertionsort(vector< int >& array){
    int i, key, j;
    for (i = 1; i < 5; i++){
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
            //cout<<"* ";//�����٦binsertionsort
        }
        array[j + 1] = key;
    }

	//cout<<"\n\n";
    //for (i = 0; i < 5; i++){
    //    cout<<array[i]<<" ";
    //}
	//cout<<"\n\n";

	return array;
}



int One_Num_Times(vector< int > arr, int num){
	int i = 0;
	int times = 0;
	for (i = 0; i < 5; i++){
		if (arr[i] == num){
			times++;
		}
	}
	return times;
}



// constructor takes 5 cards from Deck
//FIXME:把DECK前5個index的卡片傳給hand，並把那5個card從deck中移除。
Hand:: Hand( DeckOfCards &deck ){
    Card card_insert(1,1);  //vector.push_back()需要
	//用從deck中拿出來的5張卡片的值做hand手中的卡片的初始化
	//一開始會從洗好的牌組裡抽5張卡片
	for(int i=0;  i<5;  i++){
		card_insert.setSuit(  ((deck.get_deck_by_reference())[deck.get_currentCard() + i]).getSuit()  ); //card.suit = deck[currentCard].suit
		card_insert.setFace(  ((deck.get_deck_by_reference())[deck.get_currentCard() + i]).getFace()  );
		(*this).insert_CARD(card_insert); //!!內有push back，故可以自動擴充記憶體空間
		int insert_face = ((deck.get_deck_by_reference())[deck.get_currentCard() + i]).getFace();
		(*this).faceCount.push_back(insert_face);
	}
	unsigned temp_index = deck.get_currentCard();
	deck.set_currentCard(temp_index + 5);  //由於取出5張，因此照理來說，應該有5張消失了  //FIXME:需要這段嗎?

	////! testbench
	////!------------------------------------------------------------------------------------------------
	////int fa[5] = {1, 2, 3, 4, 5};
	////int su[5] = {0, 0, 0, 0, 0};
	//
	////int fa[5] = {1, 2, 3, 4, 5};
	////int su[5] = {1, 0, 0, 0, 0};
	//
	////int fa[5] = {10, 9, 0, 11, 12};
	////int su[5] = {1, 0, 0, 0, 0};
	//
	////int fa[5] = {9, 9, 9, 12, 9};
	////int su[5] = {1, 0, 0, 0, 0};
	//
    //Card card_insert(1,1);  //vector.push_back()需要
	////用從deck中拿出來的5張卡片的值做hand手中的卡片的初始化
	////一開始會從洗好的牌組裡抽5張卡片
	//for(int i=0;  i<5;  i++){
	//	card_insert.setSuit(su[i]);
	//	card_insert.setFace(fa[i]);
	//	(*this).insert_CARD(card_insert); //!!內有push back，故可以自動擴充記憶體空間
	//	(*this).faceCount.push_back(fa[i]);
	//}
	//unsigned temp_index = deck.get_currentCard();
	//deck.set_currentCard(temp_index + 5);  //由於取出5張，因此照理來說，應該有5張消失了  //FIXME:需要這段嗎?
	////!------------------------------------------------------------------------------------------------
}



// copy constructor   //FIXME:這是我額外多加的，是必要的嗎?
Hand:: Hand(const Hand & right){
	for (int i = 0;  i < right.hand.size();  i++){
		(*this).hand[i].setFace(  right.hand[i].getFace()  );
		(*this).hand[i].setSuit(  right.hand[i].getSuit()  );
	}
}

// display hand
void Hand:: print(void) const{
	cout << "In hand:\n";
	for(int i=0;   i < ((*this).hand.size());   i++)
		cout << i << "\t" << (*this).hand[i].toString();
    cout << "\n";
}


void Hand:: insert_CARD(const Card & insert_card){
	(*this).hand.push_back(insert_card);  //把一個Card object整個push back進去Hand object本身的hand vector裡面
}



//?--------------------------------------------------------------------------------------------------------------
// determine if we have the given scoring hand


bool Hand:: pair(void) const{  //1組2個數字相同
	int count[13][2];
	for(int i=0;  i<13;  i++){
		count[i][0] = i;
		count[i][1] = One_Num_Times((*this).faceCount,  i);
	}

	int max_times = 0;
	int num_for_max_times = 0;
	int second_max_times = 0;
	int second_num_for_max_times = 0;
	for(int i=0;  i<13;  i++){
		if(count[i][1]>max_times)  {
			max_times = count[i][1];
			num_for_max_times = count[i][0];
		}
		if((count[i][1]==2)&&(count[i][1]==max_times))  {
			second_max_times = count[i][1];
			second_num_for_max_times = count[i][0];
		}
	}
	//cout<<num_for_max_times<<" "<<max_times<<"\n";

	if((max_times==2) && (second_max_times!=2))return true;
	else return false;
}


bool Hand:: twoPair(void) const{  //2組各2個數字相同
	int count[13][2];
	for(int i=0;  i<13;  i++){
		count[i][0] = i;
		count[i][1] = One_Num_Times((*this).faceCount,  i);
	}

	int max_times = 0;
	int num_for_max_times = 0;
	int second_max_times = 0;
	int second_num_for_max_times = 0;
	for(int i=0;  i<13;  i++){
		if(count[i][1]>max_times)  {
			max_times = count[i][1];
			num_for_max_times = count[i][0];
		}
		if((count[i][1]==2)&&(count[i][1]==max_times))  {
			second_max_times = count[i][1];
			second_num_for_max_times = count[i][0];
		}
	}
	//cout<<num_for_max_times<<" "<<max_times<<"\n";

	if((max_times==2) && (second_max_times==2))return true;
	else return false;
}


bool Hand:: threeOfAKind(void) const{  //1組3個數字相同
	int count[13][2];
	for(int i=0;  i<13;  i++){
		count[i][0] = i;
		count[i][1] = One_Num_Times((*this).faceCount,  i);
	}

	int max_times = 0;
	int num_for_max_times = 0;
	for(int i=0;  i<13;  i++){
		if(count[i][1]>max_times)  {
			max_times = count[i][1];
			num_for_max_times = count[i][0];
		}
	}
	//cout<<num_for_max_times<<" "<<max_times<<"\n";

	if(max_times==3)return true;
	else return false;
}


bool Hand:: fourOfAKind(void) const{  //1組4個數字相同
	int count[13][2];
	for(int i=0;  i<13;  i++){
		count[i][0] = i;
		count[i][1] = One_Num_Times((*this).faceCount,  i);
	}

	int max_times = 0;
	int num_for_max_times = 0;
	for(int i=0;  i<13;  i++){
		if(count[i][1]>max_times)  {
			max_times = count[i][1];
			num_for_max_times = count[i][0];
		}
	}
	//cout<<num_for_max_times<<" "<<max_times<<"\n";

	if(max_times==4)return true;
	else return false;
}


bool Hand:: flush(void) const{  //5張花色都相同
	int suit_base = (*this).hand[0].getSuit();
	int flag = 0;
	//for(int i=0;  i<5;  i++){
	//	cout<< (*this).hand[i].getSuit() << "\n";
	//}
	for(int i=0;  i<5;  i++){
		if((*this).hand[i].getSuit() != suit_base) flag = 1;
	}

	if(flag==0) return true;
	else return false;
}


bool Hand:: straight(void) const{  //5張數字剛好連續 [x.....x+4]
	//計算數字出現次數
	int count[13][2];
	for(int i=0;  i<13;  i++){
		count[i][0] = i;
		count[i][1] = One_Num_Times((*this).faceCount,  i);
	}

	int max_times = 0;
	int num_for_max_times = 0;
	for(int i=0;  i<13;  i++){
		if(count[i][1]>max_times)  {
			max_times = count[i][1];
			num_for_max_times = count[i][0];
		}
	}
	//cout<<num_for_max_times<<" "<<max_times<<"\n";

	//確保每個數字最高出現次數為1次
	if(max_times==1){
		vector< int > ar = (*this).faceCount;
    	vector< int > arr = insertionsort(ar);
		//for(int i=0;  i<5;  i++){
		//	cout<< arr[i]<<"  ";
		//}
		int min = arr[0];
		int max = arr[4];
		if((max-min)==4)  return true;
		if (max==12){//k
			if(min==0){//1
				if(arr[1]==1 && arr[2]==2 && arr[3]==3)return true;
				if(arr[1]==1 && arr[2]==2 && arr[3]==11)return true;
				if(arr[1]==1 && arr[2]==10 && arr[3]==11)return true;
				if(arr[1]==9 && arr[2]==10 && arr[3]==11)return true;

				//1  2  3  4  k
				//1  2  3  Q  k
				//1  2  J  Q  K
				//1  10 J  Q  K

			}
		}
	}
	else
		return false;


  	return false;
}
//?--------------------------------------------------------------------------------------------------------------
