/*
N°ú M(1)
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
using namespace std;

int N, M;
vector<int> stack;
bool visited[10];

void DFS(int depth, int Picked) {
	if (Picked == M) {
		for (int tmp : stack) {
			cout << tmp << ' ';
		}
		cout << '\n';
		return;
	}
	else if (depth == N) {
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			stack.push_back(i);
			visited[i] = true;
			DFS(depth + 1, Picked + 1);
			visited[i] = false;
			stack.pop_back();
		}
		else {
			continue;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	//cin.tie(NULL);

	cin >> N >> M;

	DFS(0, 0);
	return 0;
}