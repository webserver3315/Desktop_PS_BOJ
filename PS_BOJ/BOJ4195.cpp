#include <iostream>
#include <cstring>
#include <string>
#include <map>
#define MAX (int)1e5+1
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;

int T, N;
map<string, int> dict;
int parent[MAX];

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
	parent[a] += parent[b];
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		memset(parent, -1, sizeof(parent));
		dict.clear();
		string a, b;
		cin >> N;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			if (dict.find(a) == dict.end()) {
				dict.insert(mp(a, cnt++));
			}
			if (dict.find(b) == dict.end()) {
				dict.insert(mp(b, cnt++));
			}
			int aidx = dict.find(a)->second; int bidx = dict.find(b)->second;
			merge(aidx, bidx);
			cout << -1 * parent[find(aidx)] << endl;
		}
	}

	return 0;
}