#include <iostream>
#include <vector>
using namespace std;

int m, n;
//bool visited[10];
vector<int> vct;

void DFS(int depth, int start) {
	if (depth == n) {
		for (int i : vct) {
			cout << i << ' ';
		}
		cout << endl;
		return;//여기에 리턴 까먹고 안박았는데 어떻게 정답판정이 나온거야?!?!
	}
	for (int i = start; i <= m; i++) {
		vct.push_back(i);
		DFS(depth + 1, i + 1);
		vct.pop_back();
	}
	return;
}

int main() {
	cin >> m >> n;
	DFS(0, 1);
	return 0;
}