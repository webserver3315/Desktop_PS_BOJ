/*
N과 M(2)

두 번째 풀이
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

void DFS(int startnum, int nokori) {
	if (nokori == 0) {
		for (int tmp : stack) {
			cout << tmp << ' ';
		}
		cout << '\n';
		return;
	}
	else if (startnum == N + 1)
		return;
	for (int i = startnum; i <= N; i++) {
		stack.push_back(i);
		//DFS(startnum + 1, nokori - 1);
		DFS(i + 1, nokori - 1);
		stack.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	DFS(1, M);

	return 0;
}