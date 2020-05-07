#include <bits/stdc++.h>
using namespace std;

/*
보드의 크기는 malloc으로써 동적으로 받아야 한다.
이 때, 2차원으로 선언해야 하는데 2차원 포인터를 [][]로 접근이 가능한지에 대해서는 좀 더 생각해볼 필요가 있다.
BFS를 사용하는게 가장 편리하긴 한데, 문제는 큐를 구현하는 것이다. 환형큐를 구현하는 것이 가장 안전하기는 한데, C로 환형 큐를 구현하기에는 좀 꺼림찍하다.

field의 R이 1일 경우도 고려해야함. 이 경우, 시작하자마자 도착지이므로 0을 리턴해야할 듯 하다.
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
int front, back;//back에 넣고 front에서 나온다.

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
					if (rrr == 0) return sec;//도달했으면 바로 터트리기
					else {
						pushback(rrr, ccc); memo[rrr][ccc] = sec;
					}
				}
			}
		}
		sec++;
	}
	return -1;//못찾음
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
		memset(field[r], 0, sizeof(int) * (C + 1));//stdlib 에 있는지 불확실. 없어도 크게 상관없기는 함.
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