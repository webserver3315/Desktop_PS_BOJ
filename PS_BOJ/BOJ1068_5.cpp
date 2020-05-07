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

//void DeleteNode(int del) {
//	int par = parent[del];
//	for (int i = 0; i < child[par].size(); i++) {
//		int chd = child[par][i];
//		if (chd == del) {
//			child[par].erase(child[par].begin() + i);
//			break;
//		}
//	}
//}
void DeleteNode(int del) {
	int par = parent[del];
	for (int i = 0; i < child[par].size(); i++) {
		int chd = child[par][i];
		if (chd == del) {
			child[par].erase(child[par].begin() + i);
			break;
		}
	}
}

int CountLeaf(int nd) {
	int count = 0;
	for (int i = 0; i < child[nd].size(); i++) {
		int chd = child[nd][i];
		if (child[chd].size() == 0) {
			//cout << nd << " 에서 잎 노드 하나 발견: " << chd << endl;
			count++;
		}
		else {
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
	DeleteNode(del);
	if (del == root)
		cout << 0 << endl;
	else {
		cout << CountLeaf(root) << endl;
	}
	return 0;
}