#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int R, C;
int field[1001][1001];
int memo[1001][1001];
int maxval;

bool isIn(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C)
		return false;
	return true;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			scanf("%1d", &field[r][c]);
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (isIn(r - 1, c - 1) && field[r][c] && field[r - 1][c] && field[r][c - 1] && field[r-1][c-1]) {
				//memo[r][c] = memo[r - 1][c - 1] + 1;
				memo[r][c] = min(memo[r - 1][c - 1], min(memo[r - 1][c], memo[r][c - 1])) + 1;
				if (memo[r][c] > maxval)
					maxval = memo[r][c];
			}
			else if (field[r][c]) {
				memo[r][c] = 1;
				if (memo[r][c] > maxval) maxval = memo[r][c];
			}
			else
				memo[r][c] = 0;
		}
	}

	cout << maxval * maxval << endl;

	return 0;
}