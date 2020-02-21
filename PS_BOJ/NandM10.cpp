#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int m, n;
vector<int> vct;
vector<int> ans;
set<vector<int>> ansSet;
//bool visit[10];


void dfs(int depth, int start) {
	if (depth == n) {
		if (ansSet.find(ans) != ansSet.end()) {
			return;
		}
		for (int i : ans) {
			cout << i << ' ';
		}
		cout << endl;
		ansSet.insert(ans);
		return;
	}
	for (int i = start; i < m; i++) {
		ans.push_back(vct[i]);
		dfs(depth + 1, i + 1);
		ans.pop_back();
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
	}
	sort(vct.begin(), vct.end());
	dfs(0, 0);

	return 0;
}