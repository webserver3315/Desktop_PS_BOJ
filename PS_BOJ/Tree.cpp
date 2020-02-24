#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

class Tree {
public:
	int N;
	vector<int> parent;
	vector<vector<int>> children;
	Tree():N(0){}
	Tree(int n) :N(n) {
		parent.resize(N, -1);
		children.resize(N);
	}
	void appendChild(int a, int b) {//두 노드 모두 처음보는 노드고, 추후 통합될 것이었다면 답이 없긴 한데,
		int root = visited[a] ? a : b;
		int chd = visited[a] ? b : a;
		child[root].push_back(chd);
		parent[chd] = root;
		visited[chd] = true;
	}

	void print() {
		for (int i = 0; i < N; i++) {
			cout << "노드: " << i << ": parent(";
			if (parent[i] != -1)
				cout << parent[i];
			else
				cout << "-";
			cout << "), children(";
			for (int j = 0; j < children[i].size(); j++) {
				cout << children[i][j];
				if (j < children[i].size() - 1)
					cout << ", ";
			}
			cout << ")" << endl;
		}
	}
	//Tree makeTree(int root) {//완전그래프에서 트리 만들기
	//	Tree T(N);
	//	vector<bool> visited(N, false);//길이 N짜리 방문체크용 bool배열을 전부 false로 초기화.
	//	queue<int> Q;
	//	visited[root] = true;
	//	Q.push(root);
	//	while (!Q.empty()) {
	//		int curr = Q.front();
	//		Q.pop();
	//		for (int next : adj[curr]) {//adj: 인접테이블
	//			if (!visited[next]) {
	//				visited[next] = true;
	//				Q.push(next);
	//				T.parent[next] = curr;
	//				T.children[curr].push_back(next);
	//			}
	//		}
	//	}
	//	return T;
	//}
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


	return 0;
}