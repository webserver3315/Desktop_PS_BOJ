#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<string> vct;

bool mycmp(const string& a, const string& b) {
	if (a.length() > b.length())
		return false;
	else if (a.length() < b.length())
		return true;
	else
		return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		vct.push_back(tmp);
	}
	sort(vct.begin(), vct.end(), mycmp);
	string before;
	for (auto a : vct) {
		if (before != a) {
			cout << a << endl;
			before = a;
		}
	}

	return 0;
}