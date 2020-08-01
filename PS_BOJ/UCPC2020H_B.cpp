#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int R, C, K;

char board[26][200000];
vector<int> horizontal;
vector<int> vertical;
int total_count = 0;
//string str;

signed main() {
	cin >> R >> C >> K;

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	

	//cin >> str;
	//char ch = str[0];
	char ch;
	cin >> ch;
	int n = ch - 65;

	horizontal.push_back(C - 1);
	for (int c = C - 2; c >= 0; c--) {
		if (board[n][c] == 'R') {
			horizontal.push_back(c);
		}
		else {
			break;
		}
	}
	total_count += horizontal.size();

	for (int r = 1; r < R; r++) {
		int horizontal_size = horizontal.size();
		if (horizontal_size == 0) {
			break;
		}

		cin >> ch;
		n = ch - 65;
		for (int c = 0; c < horizontal_size; c++) {
			if (board[n][horizontal.back()] == 'U') {
				vertical.push_back(horizontal.back());
			}
			horizontal.pop_back();
		}

		int vertical_size = vertical.size();
		for (int c = 0; c < vertical_size; c++) {
			int nn = vertical.back();
			vertical.pop_back();
			horizontal.push_back(nn);
			for (int k = nn - 1; k > -1; k--) {
				if (board[n][k] == 'R') {
					horizontal.push_back(k);
				}
				else {
					break;
				}
			}
		}
		total_count += horizontal.size();
	}

	cout << total_count;

	return 0;
}