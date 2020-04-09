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
		cin >> n;
		string x;
		cin >> x;
		string a, b;
		for (char c : x) {
			if (c == '2') {
				a.push_back('1');
				b.push_back('1');
			}
			else if (c == '0') {
				a.push_back('0');
				b.push_back('0');
			}
			else {
				a.push_back('1');
				b.push_back('0');
				break;
			}
		}
		for (int i = a.length(); i < n; i++) {
			a.push_back('0');
			b.push_back(x[i]);
		}
		cout << a << endl;
		cout << b << endl;
	}

	return 0;
}