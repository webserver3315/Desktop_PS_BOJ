#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t;
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int i1 = 0; int i2 = 0;
		while (((i1 + 1) * i1) / 2 < b)
			i1++;
		i2 = i1 - (((i1 + 1) * i1) / 2) + b - 1;
		for (int i = a-1; i >=0; i--) {
			if (i != i1 && i != i2)
				cout << 'a';
			else
				cout << 'b';
		}
		cout << endl;
	}

	return 0;
}