#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER_OF_DECK 4

typedef struct myCard {
	int val;
	struct myCard* next;
} Card;

typedef struct myHold {
	int size;
	Card* first;
	Card* last;
} Hold;

typedef struct myHuman {
	Hold hold;        //��
	int motteruCard;  //���� ���忡�� �������� ī���
	int Score;
	int isDealer;  //��������
} Human;

int N;             //�÷��̾� ��. ���������� �� N+1�� ����.
int deck[4 * 13];  //0�� ���̽�, 1�� 2, ..., 9�� 10, 10�� ��, 11�� ��, 12�� ŷ, ���� �����̵� ��Ʈ ���̾� Ŭ�ι���
int nokoriCardCnt = 208;
int Round;
Human player[7];  //0���� ����, 1���� �÷��̾�

Card* create_node(Card* from, int val) {
	Card* new_node = (Card*)malloc(sizeof(Card));
	new_node->val = val;
	new_node->next = NULL;
	return new_node;
}

int holdIndexAccess(Human h, int idx) {
	Card* cur = h.hold.first;
	for (int i = 0; i < idx; i++) {
		cur = cur->next;
	}
	int ret = cur->val;
	return ret;
}

void holdReset(Human h) {  //h.hold ���� �Ҵ����� �� ũ��0����
	Card* cur = h.hold.first;
	while (cur->next != NULL) {
		Card* before = cur;
		cur = cur->next;
		free(before);
	}
	free(cur);
	h.hold.size = 0;
}

void holdAppend(Human h, int val) {
	Hold head = h.hold;
	if (head.last == NULL) {
		head.last = create_node(NULL, val);
		head.first = head.last;
	}
	else {
		Card* p = head.last;
		p->next = create_node(head.last, val);
		head.last = p->next;
	}
	h.hold.size++;
}

void printScore() {
	printf("------SCORE---------\n");
	for (int i = 1; i <= N; i++) {
		printf("Player %d : player[i].Score\n");
	}
	printf("---------SCORE END--------\n");
}

int getCard() {
	if (nokoriCardCnt == 0) return -1;
	int card;
	while (1) {  //�÷��̾� �� �����, ���� ��� ���� ���� ���� ����.
		card = rand();
		card %= NUMBER_OF_DECK * 13;
		if (deck[card])
			break;
		else if (nokoriCardCnt == 0)
			break;
		else
			break;
	}
	nokoriCardCnt--;  //�� �� ����
	return card;
}

void PunPai() {                     //ī�� �ʱ� �й�
	for (int i = 0; i <= N; i++) {  //���ڿ��� ī����
		if (nokoriCardCnt) {
			int c1 = getCard();
			// player[i].hold.push_back(c1);
			holdAppend(player[i], c1);
			player[i].motteruCard++;
		}
		if (nokoriCardCnt) {
			int c2 = getCard();
			// player[i].hold.push_back(c2);
			holdAppend(player[i], c2);
			player[i].motteruCard++;
		}
	}
}

int getCardPoint(const Human h) {
	int ret = 0;
	int aceNum = 0;
	for (int i = 0; i < h.hold.size; i++) {
		int cur = holdIndexAccess(h, i);
		int pict = cur / 4;
		int num = cur % 13;
		if (num == 0) {
			aceNum++;
			ret++;
		}
		else if (num >= 10) {
			ret += 10;
		}
		else {
			ret += num + 1;
		}
	}
	while (aceNum) {          //10 a a a �� ��, �׸����ϰ� 10 10 a a �ߴٰ��� �������. ���� 1�� �� ���ϰ� ���Ŀ� 9 ������.
		if (ret + 9 <= 21) {  //9���ص� ��Ƽ�� a �ϳ��� 10���� ��Ƣ��.
			ret += 9;
			aceNum--;
		}
		else
			break;
	}
	return ret;
}

char* translate(int i) {
	char* pict; char* numch;
	pict = malloc(20);
	numch = malloc(10);
	if (i / 13 == 0) {
		strcat(pict, "Spade ");
	}
	else if (i / 13 == 1) {
		strcat(pict, "Heart ");
	}
	else if (i / 13 == 2) {
		strcat(pict, "Diamond ");
	}
	else if (i / 13 == 3) {
		strcat(pict, "Clover ");
	}

	int num = (i % 13) + 1;
	if (num == 1) {
		numch = "A";
	}
	else if (num == 11) {
		numch = "J";
	}
	else if (num == 12) {
		numch = "Q";
	}
	else if (num == 13) {
		numch = "K";
	}
	else {
		sprintf(numch, "%d", num);
	}

	char* ret = malloc(30);
	strcat(ret, pict);
	strcat(ret, numch);

	free(pict);
	free(numch);
	return ret;
}

void ShowCard(int hide) {
	printf("----------SHOW CARD------------\n");
	for (int i = 0; i <= N; i++) {
		printf("Player %d's Cards : ");
		if (player[i].isDealer) {
			if (hide)
				printf("(�������� �Ⱥ���), ");
			else {
				char* name = translate(holdIndexAccess(player[i], 0));
				printf("%s, ", name);
				free(name);
			}
			for (int j = 1; j < player[i].hold.size; j++) {
				char* name = translate(holdIndexAccess(player[i], j));
				printf("%s, ", name);
				free(name);
			}
		}
		else {
			for (int j = 0; j < player[i].hold.size; j++) {
				char* name = translate(holdIndexAccess(player[i], j));
				printf("%s, ", name);
				free(name);
			}
		}
		printf("\n");
	}
	printf("----------SHOW CARD END------------\n");
	printf("\n");
}

void DrawEveryone() {
	int hit = 1;
	int i = 1;
	while (1) {  //�÷��̾�
		ShowCard(1);
		printf("hit �Ϸ��� 1��, stand �Ϸ��� 0�� �Է��ϼ���\n");
		scanf("%d", &hit);
		if (!hit) break;
		int cur = getCard();
		if (cur == -1) {
			printf("�� ��!!!\n");
			break;
		}
		else {
			// player[i].hold.push_back(cur);
			holdAppend(player[i], cur);
			player[i].motteruCard++;
			printf("You Drawed %d\n", translate(cur));
			if (getCardPoint(player[i]) == 21) {
				printf("BlackJack!!!\n");
				break;
			}
			else if (getCardPoint(player[i]) > 21) {
				printf("Bust!!!!!!!!!!\n");
				break;
			}
		}
	}
	for (i = 2; i <= N; i++) {                  //�ΰ�����_��Ʈ? ���ĵ�?
		while (getCardPoint(player[i]) < 14) {  //14�̸��� ������ hit
			int cur = getCard();
			if (cur == -1) {
				printf("�� ��!!!\n");
				break;
			}
			else {
				// player[i].hold.push_back(cur);
				holdAppend(player[i], cur);
				player[i].motteruCard++;
				if (getCardPoint(player[i]) == 21) {
					printf("Player %d BlackJack!!!\n", i);
					break;
				}
				else if (getCardPoint(player[i]) > 21) {
					printf("Player %d Bust!!!!!!!!!!\n", i);
					break;
				}
				else {
					printf("Player %d Drawed %d\n", i, cur);
				}
			}
		}
		if (getCardPoint(player[i]) <= 17) {  //14~17�̸� ����Ȯ�� ��Ʈ
			hit = rand() % 2;
			if (hit) {
				int cur = getCard();
				if (cur == -1) {
					printf("�� ��!!!\n");
				}
				else {
					// player[i].hold.push_back(cur);
					holdAppend(player[i], cur);
					player[i].motteruCard++;
					if (getCardPoint(player[i]) == 21) {
						printf("Player %d BlackJack!!!\n", i);
					}
					else if (getCardPoint(player[i]) > 21) {
						printf("Player %d Bust!!!!!!!!!!\n", i);
					}
					else {
						printf("Player %d Drawed %d\n", i, cur);
					}
				}
			}
		}
		else
			continue;  //17 �ʰ��� ������ ����
	}
	i = 0;                                  //����
	while (getCardPoint(player[i]) < 17) {  //16 ���ϴ� ������ hit
		int cur = getCard();
		if (cur == -1) {
			printf("�� ��!!!\n");
			break;
		}
		else {
			// player[i].hold.push_back(cur);
			holdAppend(player[i], cur);
			player[i].motteruCard++;
			if (getCardPoint(player[i]) == 21) {
				printf("BlackJack!!!\n");
				break;
			}
			else if (getCardPoint(player[i]) > 21) {
				printf("Bust!!!!!!!!!!\n");
				break;
			}
			else {
				printf("Drawed %d\n", cur);
			}
		}
	}
	printf("-------�̹� ���� ī���� �������--------\n");
	ShowCard(0);
}

void Kaikei() {  //���
	int kekka[7];
	for (int i = 0; i <= N; i++) {
		if (getCardPoint(player[i]) > 21)
			kekka[i] = 2;
		else if (getCardPoint(player[i]) == 21)
			kekka[i] = 1;
		else {
			kekka[i] = 0;
		}
	}
	if (getCardPoint(player[0]) > 21) {  //������ ����Ʈ��
		for (int i = 1; i <= N; i++) {
			if (getCardPoint(player[i]) > 21) {
				player[i].Score -= 100;
			}
			else if (getCardPoint(player[i]) == 21) {
				player[i].Score += 200;
			}
			else {
				player[i].Score += 100;
			}
		}
	}
	else if (getCardPoint(player[0]) == 21) {  //������ �����̸�
		for (int i = 1; i <= N; i++) {
			if (getCardPoint(player[i]) > 21) {
				player[i].Score -= 100;
			}
			else if (getCardPoint(player[i]) == 21) {  //���
				continue;
			}
			else {
				player[i].Score -= 100;
			}
		}
	}
	else {  //������ ��Ÿ��
		for (int i = 1; i <= N; i++) {
			if (getCardPoint(player[i]) > 21) {
				player[i].Score -= 100;
			}
			else if (getCardPoint(player[i]) == 21) {
				player[i].Score += 200;
			}
			else {
				if (getCardPoint(player[0]) < getCardPoint(player[i])) {
					player[i].Score += 100;
				}
				else if (getCardPoint(player[0]) > getCardPoint(player[i])) {
					player[i].Score -= 100;
				}
			}
		}
	}
	printf("-------------�̹����� ���-------------\n");
	for (int i = 1; i <= N; i++) {
		if (kekka[i] == 0) {
			printf("Player %d Stood!\n", i);
		}
		else if (kekka[i] == 1) {
			printf("Player %d is BlackJack!!!!!!!!\n", i);
		}
		else if (kekka[i] == 2) {
			printf("Player %d has been Busted...\n", i);
		}
	}
	int i = 0;
	if (kekka[i] == 0) {
		printf("Dealer Stood!\n");
	}
	else if (kekka[i] == 1) {
		printf("Dealer is BlackJack !!!!!!!!\n");
	}
	else if (kekka[i] == 2) {
		printf("Dealer has been Busted...\n");
	}
}

void endRound() {
	for (int i = 0; i <= N; i++) {
		// player[i].hold.clear();
		holdReset(player[i]);
		player[i].motteruCard = 0;
	}
}

void startRound() {
	Round++;
	printf("This Round is %d\n", Round);
	printScore();
	PunPai();
	DrawEveryone();
	Kaikei();
	endRound();
}

int main() {
	srand((unsigned int)time(NULL));
	printf("Number of Players: ");
	scanf("%d", &N);
	for (int i = 0; i < 4 * 13; i++) {
		deck[i] = NUMBER_OF_DECK;  //������ 52���ε�, �̰͵��� 4�徿 ����.
	}
	for (int i = 0; i <= N; i++) {
		if (i == 0) {
			player[i].isDealer = 1;  //�������� ���ھ�� ���ǹ�������..
		}
		else {
			player[i].isDealer = 0;
		}
		player[i].motteruCard = 0;
		player[i].Score = 500;  //500�� �ʱ��ں����� �ְ� ��������
		player[i].hold.size = 0;
		player[i].hold.first = NULL;
		player[i].hold.last = NULL;
	}

	while (nokoriCardCnt >= (N + 1) * 5) {
		startRound();
	}

	return 0;
}