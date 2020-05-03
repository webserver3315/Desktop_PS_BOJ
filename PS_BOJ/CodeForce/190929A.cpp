/*
A. Distinct Digits
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int l, r;
bool exist[10];

int ExistClear() {
	for (int i = 0; i < 10; i++) {
		exist[i] = false;
	}
	return 0;
}

bool IsUnique(int num) {
	ExistClear();
	string numstr = to_string(num);
	for (int i = numstr.length() - 1; i >= 0; i--) {
		if (exist[numstr[i]-'0']==true) {
			return false;
		}
		exist[numstr[i]-'0'] = true;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (IsUnique(i)) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}