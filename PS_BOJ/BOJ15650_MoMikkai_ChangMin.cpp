#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
vector<int> vct;
//stack<int> stk;
bool visited[10]; //false∑Œ √ ±‚»≠µ 

void printvct() {
	for (auto& a : vct) {
		cout << a << " ";
	}
	cout << endl;
}

void Permutation(int depth) {
	if (vct.size() == M) {
		printvct();
		//cout << endl;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) {
			continue;
		}
		visited[i] = true;
		vct.push_back(i);
		Permutation(depth + 1);
		vct.pop_back();
		//visited[i] = false;
		for (int j = i + 1; j <= N; j++) {
			visited[j] = false;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	Permutation(0);

	return 0;
}