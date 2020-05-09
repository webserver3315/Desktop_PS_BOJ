#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t;
int n;
vector<int> vct;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		vct.clear();
		cin >> n;
		for (int i = 0; i < 5; i++) {
			int tmp = n % 10;
			n /= 10;
			if (tmp == 0) continue;
			for (int j = 0; j < i; j++) {
				tmp *= 10;
			}
			vct.push_back(tmp);
		}
		cout << vct.size() << endl;
		for (int i : vct) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}