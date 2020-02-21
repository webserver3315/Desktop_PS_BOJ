#include <iostream>
#define MAX 101
using namespace std;

int N;
int field[MAX][MAX];
int cnt;

void DFS(int r, int c) {
	if (field[r][c] == 0) {
		cnt++;
		return;
	}
	else {//하로, 우로
		int jump = field[r][c];
		if (r + jump < N)
			DFS(r + jump, c);
		if (c + jump < N)
			DFS(r, c + jump);
	}
}

int main() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
		}
	}
	DFS(0, 0);
	cout << cnt << endl;
	return 0;
}