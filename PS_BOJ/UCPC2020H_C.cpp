#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi graph[1010101];
vi st;

int D;

bool visited[1010101];
int parent[1010101];
vi children[1010101];
vi stk1;
vi stk2;

void dfs(int f) {
	stk1.push_back(f);
	while (!stk1.empty()) {
		int u = stk1.back();
		stk1.pop_back();

		if (visited[u])
			continue;

		visited[u] = true;
		for (auto v : graph[u]) {
			if (!visited[v]) {
				children[u].push_back(v);
				stk1.push_back(v);
			}
		}
	}
}

void dfs2(int f) {
	st.push_back(f);
	stk2.push_back(f);
	while (!stk2.empty()) {
		int u = stk2.back();

		for (auto v : children[u]) {
			parent[v] = st[max(int(st.size() - D), 0)];
			dfs2(v);
		}
		st.pop_back();
	}
	return;
}

int main() {
	int N, S;

	cin >> N >> S >> D;
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(S);
	parent[S] = S;
	dfs2(S);

	set<int> s;

	for (int i = 1; i <= N; ++i) {
		s.insert(parent[i]);
	}

	cout << 2 * s.size() - 2;

	return 0;
}