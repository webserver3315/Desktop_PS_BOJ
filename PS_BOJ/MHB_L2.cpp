#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool adj[6][6];
bool visited[6][6];

vector<int> went;

void setadj() {
	adj[1][2] = true; adj[1][3] = true; adj[1][5] = true;
	adj[2][1] = true; adj[2][3] = true; adj[2][5] = true;
	adj[3][1] = true; adj[3][2] = true; adj[3][4] = true; adj[3][5] = true;
	adj[4][3] = true; adj[4][5] = true;
	adj[5][1] = true; adj[5][2] = true; adj[5][3] = true; adj[5][4] = true;
}

void dfs(int cur, int depth) {
	if (depth == 8) {
		for (auto a : went) {
			cout << a;
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= 5; i++) {
		if (!visited[cur][i] && adj[cur][i] == true) {
			went.push_back(i);
			visited[cur][i] = true; visited[i][cur] = true;
			dfs(i, depth + 1);
			visited[cur][i] = false; visited[i][cur] = false;
			went.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	setadj();
	went.push_back(1);
	dfs(1, 0);
	went.pop_back();

	return 0;
}