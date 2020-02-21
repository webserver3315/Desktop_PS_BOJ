#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define int long long
using namespace std;

int n;
vector<string> sikki;
int kaisu[26];

bool desc(int a, int b) {
	return a > b;
}

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		reverse(tmp.begin(),tmp.end());
		sikki.push_back(tmp);
	}

	for (auto str : sikki) {
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			signed idx = c - 'A';
			int plus = pow(10, i);
			kaisu[idx] += plus;
		}
	}

	sort(kaisu, kaisu + 26, desc);

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += (9 - i) * kaisu[i];
	}
	cout << sum << endl;
	return 0;
}