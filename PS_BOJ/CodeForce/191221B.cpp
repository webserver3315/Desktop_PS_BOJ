#include <iostream>
#include <algorithm>
#define MAXARR (int)2001;
#define endl '\n'
using namespace std;


int a[2001];
int b[2001];
int n, m;
int cnt;

void plusx() {
	cnt++;
	for (int i = 0; i < n; i++) {
		a[i]++;
		if (a[i] == m)
			a[i] = 0;
	}
}

bool IsEqual() {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[i] = tmp;
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		b[i] = tmp;
	}

	sort(a, a + n);
	sort(b, b + n);

	for (int i = 0; i < m; i++) {
		if (IsEqual()) {
			cout << cnt << endl;
			return 0;
		}
		plusx();
		sort(a, a + n);
	}

	return 0;
}