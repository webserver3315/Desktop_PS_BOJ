#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, m;
vector<int> vct;
vector<int> ans;
set<vector<int>> ansSet;

void dfs(int depth, int start) {
	if (depth == m) {
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
	for (int i = start; i < n; i++) {
		ans.push_back(vct[i]);
		dfs(depth + 1, i);
		ans.pop_back();
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
	}
	sort(vct.begin(), vct.end());
	dfs(0, 0);
	return 0;
}