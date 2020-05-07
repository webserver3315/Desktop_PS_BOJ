#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
using namespace std;

class Tree {
public:
	int ndkz;//nodekazu
	vector<int> parent;
	vector<vector<int>> child;//2진트리라는 말이 없으므로 vector<pair>가 아니라 vector<vector<int>>를 썼다.
	Tree():ndkz(0){}
	Tree(int n) :ndkz(n) {
		parent.resize(ndkz, -1);
		child.resize(ndkz);
	}
	void appendChild(int root, int chd) {
		child[root].push_back(chd);
		parent[chd] = root;
	}

};

int main() {
	int n;
	cin >> n;
	Tree tree(n);
	for (int i = 0; i < n - 1; i++) {
		int a; int b;
		cin >> a >> b;
		tree.appendChild(a, b);
	}
	for (int i = 1; i < tree.ndkz; i++) {
		cout << tree.parent[i] << endl;
	}
	return 0;
}