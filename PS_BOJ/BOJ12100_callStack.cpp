/*
2048(EASY)

>>>충돌/겹침 상황을 해결해야하는 격자맵 문제는 굉장히 빈출된다.
어떻게 일반적으로 풀지 그 해결법을 모색해보자.

상하좌우 4개의 선지르 5번 반복하는것이므로, 2의 10승 즉 1000가지밖에 안된다.
시뮬레이션 구현시켜놓고 브루트포스 돌리면 된다.
단, 1초이므로 케이스당 1만번 연산 내로 끝내야한다
*/

#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 25
using namespace std;

int N;
int field_Original[MAX][MAX];
//int field_Ima[MAX][MAX];
int maxval;
vector<vector<int>> dfsway;

void fieldInitialize(int**& field_Ima) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			field_Ima[r][c] = field_Original[r][c];
		}
	}
}

void GoDown(int r, int c, int**& field_Ima) {
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (rr < N && !field_Ima[rr + 1][c]) {//정상이나 부딪히기 전까지 상승시킨다
		rr++;
	}
	if (rr == N) {//정상까지 갔으면
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
	}
	else if (field_Ima[rr + 1][cc]) {//부딪혀서 멈췄으면
		int rrr = rr + 1; int ccc = c;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//동일한 수면 병합한다
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
		}
		else {//아니면 옮긴 채 그대로 둔다.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
}

void GoRight(int r, int c, int**& field_Ima) {
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (cc < N && !field_Ima[rr][c + 1]) {//정상이나 부딪히기 전까지 상승시킨다
		cc++;
	}
	if (cc == N) {//정상까지 갔으면
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
	}
	else if (field_Ima[rr][cc + 1]) {//부딪혀서 멈췄으면
		int rrr = rr; int ccc = cc + 1;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//동일한 수면 병합한다
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
		}
		else {//아니면 옮긴 채 그대로 둔다.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
}

void GoLeft(int r, int c, int**& field_Ima) {
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (cc > 1 && !field_Ima[rr][cc - 1]) {//정상이나 부딪히기 전까지 상승시킨다
		cc--;
	}
	if (cc == 1) {//정상까지 갔으면
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
	}
	else if (field_Ima[rr][cc - 1]) {//부딪혀서 멈췄으면
		int rrr = rr; int ccc = cc - 1;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//동일한 수면 병합한다
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
		}
		else {//아니면 그대로 둔다.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
}

void GoUp(int r, int c, int**& field_Ima) {//r c의 칸을 가능한 한 상승시킨다
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (rr > 1 && !field_Ima[rr - 1][c]) {//정상이나 부딪히기 전까지 상승시킨다
		rr--;
	}

	if (rr == 1) {//정상까지 갔으면
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
		return;
	}
	else if (field_Ima[rr - 1][c]) {//부딪혀서 멈췄으면
		int rrr = rr - 1; int ccc = c;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//동일한 수면 병합한다
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
			return;
		}
		else {//아니면 그대로 둔다.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
			return;
		}
	}
	else {
		cout << "ERROR" << endl;
		return;
	}
}

void printfieldIma(int**& field_Ima) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << field_Ima[r][c] << ' ';
		}
		cout << endl;
	}
	maxval = 0;
}

void AllGo(int d, int** field_Ima) {//d가 1,2,3,4 각각 상,하,좌,우
	if (d == 1) {
		for (int r = 1; r < N; r++) {
			for (int c = 1; c <= N; c++) {
				GoUp(r, c, field_Ima);
			}
		}
	}
	else if (d == 2) {
		for (int r = N; r > 1; r--) {
			for (int c = N; c > 1; c--) {
				GoDown(r, c, field_Ima);
			}
		}
	}
	else if (d == 3) {
		for (int r = 1; r < N; r++) {
			for (int c = 1; c <= N; c++) {
				GoLeft(r, c, field_Ima);
			}
		}
	}
	else if (d == 4) {
		for (int r = N; r > 1; r--) {
			for (int c = N; c > 1; c--) {
				GoRight(r, c, field_Ima);
			}
		}
	}
}

/*재야하는 모든 경우의 수는 1000가지.
각 경우를 시행할 때마다 일단 초기화하는데에만 400의 연산 소모
상하좌우 각 경우 이동하는데마다 최소 400의 연산 소모
굉장히 연산량 아슬아슬한데
*/

int DFS(int depth) {
	if (depth == 5) {
		return;
	}
	int tmpfield[MAX][MAX];
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			tmpfield[r][c]=
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> field_Original[r][c];
		}
	}
	


	return 0;
}