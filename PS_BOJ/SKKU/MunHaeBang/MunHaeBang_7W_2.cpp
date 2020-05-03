#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;

bool isSKKU(int k) {
	int ko = k;
	int sum1 = 0; int sum2 = 0;
	vector<int> vct;
	for (int i = 2; i * i <= k; i++) {
		while (k % i == 0) {
			k /= i;
			while (i > 9) {
				sum1 += i % 10;
			}
			sum1 += i;
		}
	}
	if (k != 1) {
		while (k > 9) {
			sum1 += k % 10;
			k /= 10;
		}
		sum1 += k;
	}
	while (ko % 10 != 0) {
		sum2 += ko % 10;
		ko /= 10;
	}
	if (sum1 == sum2) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	n++;
	while (isSKKU(n) == false) {
		n++;
	}
	cout << n << endl;

	return 0;
}