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
	void print() {
		for (int i = 0; i < N; i++) {
			cout << "���: " << i << ": parent(";
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
	//Tree makeTree(int root) {//�����׷������� Ʈ�� �����
	//	Tree T(N);
	//	vector<bool> visited(N, false);//���� N¥�� �湮üũ�� bool�迭�� ���� false�� �ʱ�ȭ.
	//	queue<int> Q;
	//	visited[root] = true;
	//	Q.push(root);
	//	while (!Q.empty()) {
	//		int curr = Q.front();
	//		Q.pop();
	//		for (int next : adj[curr]) {//adj: �������̺�
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
	void preorder(int root) {
		cout << root << ' ';
		if(lc[root])
	}
	void inorder(int root) {

	}
	void postorder(int root) {

	}
	void levelorder(int root) {

	}
};

int main() {


	return 0;
}