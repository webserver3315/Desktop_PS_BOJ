/*
N°úM(2)
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

vector<int> GlobalList;
vector<int> Chosen;
int N, M;

void printAll() {
	for (int c : Chosen) {
		cout << c << ' ';
	}
	cout << '\n';
	return;
}

int DFS(int startidx, int Picked) {
	if (Picked == M) {
		printAll();
		return 0;
	}
	else if(startidx == N) {
		return 0;
	}
	for (int i = 1; i < N; i++) {
		Chosen.push_back(GlobalList[i]);
		DFS(i, Picked + 1);
		Chosen.pop_back();
		//DFS(Chosen, startidx + 1, Picked);
	}
	return 0;
}

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		GlobalList.push_back(i);
	}
	DFS(0, 0);
	return 0;
}