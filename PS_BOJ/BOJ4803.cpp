#include <iostream>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;

int n;//노드 수
int m;//간선 수

class Tree {
public:
	int N;
	vector<int> parent;
	vector<vector<int>> children;
	set<int> numberOfTree;
	Tree():N(0){}
	Tree(int n) :N(n) {
		parent.resize(N, -1);
		children.resize(N);
	}
	int findRoot(int node) {
		if (parent[node] == -1)
			return node;
		return findRoot(parent[node]);
	}
};

int main() {
	cin >> n >> m;
	while (n != 0 && m != 0) {
		Tree tree;
		for (int i = 0; i < m; i++) {
			int a; int b;
			cin >> a >> b;
		}


		cin >> n >> m;
	}
}