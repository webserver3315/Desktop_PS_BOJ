/*

*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		int sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
		}
		if (sum % n == 0) {
			cout << sum / n << endl;
		}
		else {
			cout << sum / n + 1 << endl;
		}
	}
	return 0;
}