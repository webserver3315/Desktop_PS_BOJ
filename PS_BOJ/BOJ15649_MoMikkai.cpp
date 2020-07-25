#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
vector<int> vct;
deque<int>
//stack<int> stk;
bool visited[10]; //false∑Œ √ ±‚»≠µ 

void printvct() {
	for (auto& a : vct) {
		cout << a << " ";
	}
	cout << endl;
}

void Combination(int cur, int depth) {
	if (vct.size() == M) {
		printvct();
		//cout << endl;
		return;
	}
	for (int i = cur; i <= N; i++) {
		if (visited[i] == true) {
			continue;
		}
		visited[i] = true;
		vct.push_back(i);
		Combination(cur+1,depth + 1);
		vct.pop_back();
		visited[i] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	Combination(1,0);

	vector[vector.size()-1]
		vector.back()
		vector.front()==vector[0]
		vector.empty()

	return 0;
}