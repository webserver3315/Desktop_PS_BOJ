#include <iostream>
#include <vector>
#define endl '\n'//endl 그대로 써버리면 버퍼 비우는 비용때문에 시간초과뜬다;; 실화냐
using namespace std;

int n, m;
bool visited[10];
vector<int> vct;

void DFS(int depth) {
	if (depth == n) {
		for (int i : vct) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		vct.push_back(i);
		DFS(depth + 1);
		visited[i] = false;
		vct.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);//이 세 줄 붙이면 통과하려나?
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	DFS(0);

	return 0;
}