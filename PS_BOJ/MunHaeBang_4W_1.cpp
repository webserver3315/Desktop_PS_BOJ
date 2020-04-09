#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<int> vct;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n > 0) {
		int tmp = n % 10;
		n /= 10;
		vct.push_back(tmp);
	}
	sort(vct.begin(), vct.end(), greater<int>());
	for (int i : vct) {
		cout << i;
	}
	cout << endl;
	return 0;
}