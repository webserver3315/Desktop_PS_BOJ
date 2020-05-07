/*
N과M(1)
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

bool visited[10];
vector<int> GlobalList;
int N, M;

int printAll(vector<int>& Chosen) {
	for (int c : Chosen) {
		//cout << c << ' ';
		printf("%d ", c);
	}
	//cout << '\n';
	printf("\n");
	return 0;
}

int DFS(vector<int>& Chosen, int startidx, int Picked) {
	//cout << "DFS(" << startidx << ", " << Picked << ") 새로운 함수호출되었고, 호출시점 벡터 총 원소 : ";
	//printAll(Chosen);
	//cout << '\n';
	if (Picked == M) {
		//cout << startidx << ' ' << Picked << " Now Print All!!!\n" << endl;
		printAll(Chosen);
		//cout << '\n' << '\n' << endl;
		return 0;
	}
	else if (startidx == N) {
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			Chosen.push_back(GlobalList[i]);
			visited[i] = true;
			//cout << GlobalList[i] << " has been pushed\n" << endl;
			DFS(Chosen, i + 1, Picked + 1);
			visited[i] = false;
			Chosen.pop_back();
			//cout << GlobalList[i] << " has been popped\n" << endl;
			//DFS(Chosen, startidx + 1, Picked);
			//cout << '\n' << '\n' << endl;
		}
		else
			continue;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		GlobalList.push_back(i);
	}
	vector<int> Chosen;
	DFS(Chosen, 0, 0);
	return 0;
}