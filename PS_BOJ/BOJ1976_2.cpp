#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int parent[201];

int find(int n) {
	if (parent[n] < 0)
		return n;
	parent[n] = find(parent[n]);//find 안에 n이 아니라 parent[n]다!
	return parent[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	parent[a] += parent[b];
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	memset(parent, -1, sizeof(parent));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int tmp; cin >> tmp;
			if (tmp == 1)
				merge(r, c);
		}
	}

	int kijun = find(1);
	for (int i = 2; i < N; i++) {
		if (kijun != find(i)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}