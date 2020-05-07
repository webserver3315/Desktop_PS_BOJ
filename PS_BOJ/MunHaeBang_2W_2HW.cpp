#include <bits/stdc++.h>
using namespace std;

vector<int> path;
bool visited[6][6];
bool edge[6][6];

void makeGraph() {
	edge[1][2] = true;	edge[1][3] = true;	edge[1][5] = true;
	edge[2][1] = true;	edge[2][3] = true;	edge[2][5] = true;
	edge[3][1] = true;	edge[3][2] = true;	edge[3][4] = true;	edge[3][5] = true;
	edge[4][3] = true;	edge[4][5] = true;
	edge[5][1] = true;	edge[5][2] = true;	edge[5][3] = true;	edge[5][4] = true;
}

void dfs(int cur, int depth) {
	if (depth == 8) {
		for (int i : path)
			cout << i;
		cout << endl;
		return;
	}
	for (int next = 1; next <= 5; next++) {
		if (edge[cur][next] && !visited[cur][next]) {
			visited[cur][next] = true; visited[next][cur] = true;
			path.push_back(next);
			dfs(next, depth + 1);
			visited[cur][next] = false;	visited[next][cur] = false;
			path.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	makeGraph();
	path.push_back(1);
	dfs(1, 0);

	return 0;
}