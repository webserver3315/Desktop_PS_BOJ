#include <bits/stdc++.h>
using namespace std;

int t;
int a, b;
int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		float div = (float)a / b;
		cout << b * (int)ceil(div) - a << endl;
	}
	return 0;
}