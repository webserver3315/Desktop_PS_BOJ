#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int N, M, K;
int parent[10001];
int price[10001];

int find(int n) {
	if (parent[n] < 0)
		return n;
	parent[n] = find(parent[n]);
	return parent[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (price[a] < price[b]) {
		parent[a] += parent[b];
		parent[b] = a;
	}
	else {
		parent[b] += parent[a];
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	memset(parent, -1, sizeof(parent));
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	int tanko = 0;
	for (int i = 1; i <= N; i++) {
		if (parent[i] < 0)
			tanko += price[i];
	}

	if (tanko > K)
		cout << "Oh no" << endl;
	else
		cout << tanko << endl;

	return 0;
}