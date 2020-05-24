#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "SiSoSil1_Final_1.h"
#define NUMBER_OF_DECK 4

//idx%13�� 0�̸� 1�̹Ƿ� �ϴ� 11���, 1�̸� 2, ... 9�̸� 10, 10�̸� J, 11�̸� Q, 12�� K
int deck[NUMBER_OF_DECK * 13];//spade, heart, diamond, clover, ���ڴ� idx%14

void resetDeck() {//�� �ٽ� �� ä���ֱ�, �����õ尪 �ʱ�ȭ
	memset(deck, 0, sizeof(deck));
	srand((unsigned int)time(NULL));
}

int isDepleted(int n) {//n�� �ε����� ���Ǿ�����?
	if (deck[n] == NUMBER_OF_DECK) return 1;//yes, it is depleted
	else return 0;//no, it still exists
}

int getNum(int n) {//n�� �ε����� ���ڸ� �߷�����.
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
	int card = rand(); card %= NUMBER_OF_DECK * 13;
	return card;
}

int main() {


	return 0;
}