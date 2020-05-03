#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, S, cnt;
vector<int> GlobalVct;

void BackTracking(int depth, int sum) {
	if (depth >= N) {
		return;
	}
	if (sum + GlobalVct[depth] == S) {
		cnt++;
	}
	BackTracking(depth + 1, sum + GlobalVct[depth]);
	BackTracking(depth + 1, sum);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		GlobalVct.push_back(tmp);
	}
	BackTracking(0, 0);
	cout << cnt << endl;
	return 0;
}