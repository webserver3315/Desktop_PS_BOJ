#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
string s;

string solve() {
	for (int i = 0; i <= s.length() - n; i++) {
		string pars = "";
		for (int j = 0; j < n; j++) {
			pars.push_back(s[i + j]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;


	return 0;
}