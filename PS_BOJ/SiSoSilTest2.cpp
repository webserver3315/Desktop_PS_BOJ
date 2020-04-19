#include <bits/stdc++.h>
using namespace std;

/*
������ ũ��� malloc���ν� �������� �޾ƾ� �Ѵ�.
�� ��, 2�������� �����ؾ� �ϴµ� 2���� �����͸� [][]�� ������ ���������� ���ؼ��� �� �� �����غ� �ʿ䰡 �ִ�.
BFS�� ����ϴ°� ���� ���ϱ� �ѵ�, ������ ť�� �����ϴ� ���̴�. ȯ��ť�� �����ϴ� ���� ���� �����ϱ�� �ѵ�, C�� ȯ�� ť�� �����ϱ⿡�� �� �������ϴ�.

field�� R�� 1�� ��쵵 ����ؾ���. �� ���, �������ڸ��� �������̹Ƿ� 0�� �����ؾ��� �� �ϴ�.
*/

typedef struct mypii {
	int ff;
	int ss;
}pii;


int dr[8] = { -2,-1,1,2,2,1,-1,-2 };
int dc[8] = { 1,2,2,1,-1,-2,-2,-1 };
int R, C;
int KC;//Knight Column
int** field;
int** memo;
pii Queue[1000000];
int QueueSize;
int front, back;//back�� �ְ� front���� ���´�.

int InBoundary(int a, int b) {
	if (a >= R || b >= C || a < 0 || b < 0)
		return 0;
	return 1;
}

void pushback(int a, int b) {
	if (back == 1000000) {
		printf("Queue MaxSize 1e6 has been Exceeded\n");
		return;
	}
	Queue[back].ff = a; Queue[back].ss = b; back++;
	QueueSize++;
}

void popfront() {
	if (QueueSize == 0) {
		printf("There are no elements at Queue\n");
		return;
	}
	front++; QueueSize--;
}

int IsEmpty() {
	if (QueueSize == 0) {
		return 1;
	}
	else if (QueueSize > 0) {
		return 0;
	}
	else {
		printf("Error");
		return -1;
	}
}

pii readfront() {
	return Queue[front];
}

int BFS() {
	int cnt, sec;
	sec = 1;
	while (!IsEmpty()) {
		cnt = QueueSize;
		while (cnt--) {
			pii now = readfront();
			popfront();
			int rr = now.ff; int cc = now.ss;
			for (int i = 0; i < 8; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBoundary(rrr, ccc) && field[rrr][ccc] == 0 && memo[rrr][ccc] == 0) {
					if (rrr == 0) return sec;//���������� �ٷ� ��Ʈ����
					else {
						pushback(rrr, ccc); memo[rrr][ccc] = sec;
					}
				}
			}
		}
		sec++;
	}
	return -1;//��ã��
}

void printfield() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			printf("%d ", field[r][c]);
		}
		printf("\n");
	}
}

void printmemo() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			printf("%d ", memo[r][c]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &C, &R);
	scanf("%d", &KC);
	if (R == 1) {
		printf("answer: 0\n");
		return 0;
	}
	field = (int**)malloc(sizeof(int*) * (R + 1));
	memo = (int**)malloc(sizeof(int*) * (R + 1));
	for (int r = 0; r < R; r++) {
		field[r] = (int*)malloc(sizeof(int) * (C + 1));
		memo[r] = (int*)malloc(sizeof(int) * (C + 1));
		memset(field[r], 0, sizeof(int) * (C + 1));//stdlib �� �ִ��� ��Ȯ��. ��� ũ�� �������� ��.
		memset(memo[r], 0, sizeof(int) * (C + 1));
	}
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			scanf("%d", &field[r][c]);
		}
	}
	memo[R - 1][KC] = -1;

	printfield();
	printf("\n");
	printmemo();

	pushback(R - 1, KC);
	printf("answer: %d\n", BFS());

	printfield();
	printf("\n");
	printmemo();

	for (int r = 0; r < R; r++) {
		free(field[r]);
		free(memo[r]);
	}
	free(field);
	free(memo);
	return 0;
}