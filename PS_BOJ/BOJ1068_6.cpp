#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 55
using namespace std;

int N;
int root;
vector<int> parent;
vector<vector<int>> child;
bool visited[MAX];

int CountLeaf(int nd) {
	int count = 0;
	int cndnum = 0;
	for (int i = 0; i < child[nd].size(); i++) {
		if (!visited[child[nd][i]])
			cndnum++;
	}
	if (cndnum == 0)
		return ++count;
	for (int i = 0; i < child[nd].size(); i++) {
		int chd = child[nd][i];
		if (visited[chd])
			continue;
		else if (child[chd].size() == 0) {
			//cout << nd << " 에서 잎 노드 하나 발견: " << chd << endl;
			visited[chd] = true;
			count++;
		}
		else {
			visited[chd] = true;
			count += CountLeaf(chd);
		}
	}
	return count;
}

int main() {
	cin >> N;
	parent.resize(N, -1);
	child.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> parent[i];
		if (parent[i] != -1)
			child[parent[i]].push_back(i);
		else {
			root = i;
		}
	}
	int del;
	cin >> del;
	visited[del] = true;
	if (visited[root])
		cout << 0 << endl;
	else {
		int ans = CountLeaf(root);
		cout << ans << endl;
	}
	return 0;
}