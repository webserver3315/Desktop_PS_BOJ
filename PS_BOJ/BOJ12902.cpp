#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vct;
int minval = (int)1e9 + 1;
int maxval;
bool AllCoprime = true;

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

	int g;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((g = gcd(i, j)) != 1) {
				AllCoprime = false;
				break;
			}
		}
	}

	if (AllCoprime) {
		int kanken = maxval - N;
		if (kanken % 2) {
			cout << "Alice" << endl;
		}
		else {
			cout << "Bob" << endl;
		}
	}
	else {
		maxval /= g;
		minval /= g;
		int kanken = maxval - minval;
		if (kanken % 2) {
			cout << "Alice" << endl;
		}
		else {
			cout << "Bob" << endl;
		}
	}

	return 0;
}