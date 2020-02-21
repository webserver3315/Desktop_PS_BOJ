#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;

int m, n;
vector<int> vct;
bool visit[10];
set<vector<int>> answerSet;
vector<int> answer;

//1799

void dfs(int depth) {
	if (depth == n) {
		if (answerSet.find(answer) != answerSet.end())//한 번 나온 답안일 경우
			return;
		for (int i : answer) {
			cout << i << ' ';
		}
		cout << endl;
		answerSet.insert(answer);
		return;
	}
	for (int i = 0; i < vct.size(); i++) {
		if (visit[i])
			continue;
		visit[i] = true;
		answer.push_back(vct[i]);
		dfs(depth + 1);
		visit[i] = false;
		answer.pop_back();
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
	dfs(0);
	return 0;
}