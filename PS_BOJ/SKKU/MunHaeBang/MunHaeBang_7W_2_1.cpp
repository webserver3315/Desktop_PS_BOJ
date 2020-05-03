#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int k;
vector<int> vct;

bool isSKKU(int n) {
	int sum1 = 0; int sum2 = 0;
	int n1 = n; int n2 = n;
	while (n1 != 0) {
		sum1 += n1 % 10;
		n1 /= 10;
	}
	for (int a : vct) {
		while (a != 0) {
			sum2 += a % 10;
			a /= 10;
		}
	}
	if (vct.size() == 1) return false;
	else if (sum1 == sum2) return true;
	else return false;
}

void factorize(int n){
	while (n % 2 == 0){
		vct.push_back(2);
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2){
		while (n % i == 0){
			vct.push_back(i);
			n = n / i;
		}
	}
	if (n > 2)
		vct.push_back(n);
}

bool solve(int n) {
	factorize(n);
	return isSKKU(n);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	k++;
	while (solve(k) == false) {
		k++;
		vct.clear();
	}
	cout << k << endl;

	return 0;
}