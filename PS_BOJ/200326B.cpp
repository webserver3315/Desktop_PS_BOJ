#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {		
		int n;
		int th;
		cin >> n >> th;
		vector<char> vct;
		for (int i = 0; i < n - 2; i++) {
			vct.push_back('a');
		}
		vct.push_back('b');
		vct.push_back('b');
		while (--th) {
			next_permutation(vct.begin(), vct.end());
		}
		for (auto c : vct)
			cout << c;
		cout << endl;
	}

	return 0;
}