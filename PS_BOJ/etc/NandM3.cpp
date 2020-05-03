#include <iostream>
#include <vector>
using namespace std;

int m, n;
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
		vct.push_back(i);
		DFS(depth + 1);
		vct.pop_back();
	}
	return;
}

int main() {
	cin >> m >> n;
	DFS(0);
	return 0;
}