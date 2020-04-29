#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
bool visited[11];
vector<int> vct;

void dfs(int depth) {
	if (depth == 5) {
		for (auto a : vct) {
			cout << a << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vct.push_back(i);
			dfs(depth + 1);
			visited[i] = false;
			vct.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	dfs(0);

	return 0;
}