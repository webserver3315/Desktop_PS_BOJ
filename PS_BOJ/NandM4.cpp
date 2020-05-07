#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<int> vct;

void DFS(int depth, int start) {
	if (depth == n) {
		for (int i : vct) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= m; i++) {
		vct.push_back(i);
		DFS(depth + 1, i);
		vct.pop_back();
	}

}

int main() {
	cin >> m >> n;
	DFS(0, 1);

	return 0;
}