#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vct;
int minval = (int)1e9 + 1;
int maxval;
bool AllMultiple = true;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
		if (maxval < tmp)
			maxval = tmp;
		if (minval > tmp)
			minval = tmp;
	}

	int g = vct[0];
	for (int i = 1; i < N; i++) {
		g = gcd(g, vct[i]);
		if (g == 1) {
			AllMultiple = false;
			break;
		}
	}

	if (AllMultiple)
		maxval /= g;

	int kanken = maxval - N;
	if (kanken % 2)
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;
	return 0;
}