#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

char itoC(int i) {
	return i + 'A';
}

int Ctoi(char c) {
	return c - 'A';
}

class Tree {
public:
	int nodeKazu;
	vector<int> parent;
	vector<pii> children;//ff:lc,ss:rc
	Tree() :nodeKazu(0) {}
	Tree(int n) :nodeKazu(n) {
		parent.resize(nodeKazu, -1);
		children.resize(nodeKazu);
	}
	void appendChild(char prnt, char lc, char rc) {
		int curr = Ctoi(prnt);
		if (lc == '.')
			children[curr].ff = -1;
		else
			children[curr].ff = Ctoi(lc);
		if (rc == '.')
			children[curr].ss = -1;
		else
			children[curr].ss = Ctoi(rc);
	}
	void preorder(int root) {//전위순회: 루트 좌자 우자
		cout << itoC(root);
		if (children[root].ff != -1)
			preorder(children[root].ff);
		if (children[root].ss != -1)
			preorder(children[root].ss);
	}
	void inorder(int root) {//중위: 좌자 루트 우자
		if (children[root].ff != -1)
			inorder(children[root].ff);
		cout << itoC(root);
		if (children[root].ss != -1)
			inorder(children[root].ss);
	}
	void postorder(int root) {//후위: 좌자 우자 루트
		if (children[root].ff != -1)
			postorder(children[root].ff);
		if (children[root].ss != -1)
			postorder(children[root].ss);
		cout << itoC(root);
	}
};

int main() {
	int n;
	cin >> n;
	Tree tree(n);
	for (int i = 0; i < n; i++) {
		string a, b, c;
		cin >> a >> b >> c;
		char ca, cb, cc;
		ca = a[0]; cb = b[0]; cc = c[0];
		tree.appendChild(ca, cb, cc);
	}
	tree.preorder(0);
	cout << endl;
	tree.inorder(0);
	cout << endl;
	tree.postorder(0);
	cout << endl;
	return 0;
}