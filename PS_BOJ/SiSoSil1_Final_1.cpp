#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "SiSoSil1_Final_1.h"
#define NUMBER_OF_DECK 4

typedef struct myNode {
	int card;
	struct myNode* next;
	struct myNode* prev;
}Node;

typedef struct myPlayer {
	
	int money;
}Player;

//idx%13이 0이면 1이므로 일단 11취급, 1이면 2, ... 9이면 10, 10이면 J, 11이면 Q, 12면 K
int deck[NUMBER_OF_DECK * 13];//spade, heart, diamond, clover, 숫자는 idx%14
int N;
Player* Gamers;

void resetDeck() {//덱 다시 다 채워넣기, 랜덤시드값 초기화
	memset(deck, 0, sizeof(deck));
	srand((unsigned int)time(NULL));
}

int isDepleted(int n) {//n번 인덱스가 고갈되었는지?
	if (deck[n] == NUMBER_OF_DECK) return 1;//yes, it is depleted
	else return 0;//no, it still exists
}

int getNum(int n) {//n번 인덱스의 숫자만 추려낸다.
	n %= 13;
	if (n == 0) {
		return 11;
	}
	else if (n >= 9) {
		return 10;
	}
	else {
		return n + 1;
	}
}

int getCard() {
	int card;
	while (1) {//플레이어 수 관계상, 절대 모든 덱이 고갈날 일은 없다.
		card = rand();
		card %= NUMBER_OF_DECK * 13;	
		if (isDepleted) continue;
		else break;
	}
	return card;
}

int playerAI() {

}

int dealerAI() {

}

int main() {
	printf("Number of Players: ");
	scanf("%d", &N);
	Gamers = (Player*)malloc(sizeof(Player) * N);



	free(Gamers);
	return 0;
}