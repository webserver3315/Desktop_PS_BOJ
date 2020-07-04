#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
bool visited[10];
vector<int> ret;

void p(int cur, int depth) {
	if (ret.size() == M) {
		for (auto i : ret) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		ret.push_back(i);
		p(1, depth + 1);
		visited[i] = false;
		ret.pop_back();
	}
	return;
}

void c(int cur, int depth) {
	if (ret.size() == M) {
		for (auto i : ret) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = cur; i <= N; i++) {
		ret.push_back(i);
		c(i+1, depth + 1);
		ret.pop_back();
	}
	return;
}

void Pi(int cur, int depth) {
	if (ret.size() == M) {
		for (auto i : ret) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= N; i++) {
		ret.push_back(i);
		h(1, depth + 1);
		ret.pop_back();
	}
	return;
}


void h(int cur, int depth) {
	if (ret.size() == M) {
		for (auto i : ret) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = cur; i <= N; i++) {
		ret.push_back(i);
		c(i + 1, depth + 1);
		ret.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	//p(1, 0);
	//c(1, 0);
	Pi(1, 0);

	return 0;
}