#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define MAX (int)1e5+1
#define endl '\n'
using namespace std;

bool visited[MAX];

class Tree {
public:
	int ndkz;//nodekazu
	vector<int> parent;
	vector<vector<int>> child;//2��Ʈ����� ���� �����Ƿ� vector<pair>�� �ƴ϶� vector<vector<int>>�� ���.
	
	Tree() :ndkz(0) {
		/*memset(visited, false, MAX);*/
		visited[1] = true;//��Ʈ����ε���==1
	}
	Tree(int n) :ndkz(n) {
		parent.resize(ndkz+1, -1);
		child.resize(ndkz+1);
		//memset(visited, false, MAX);
		visited[1] = true;
	}
	void appendChild(int a, int b) {//�� ��� ��� ó������ ����, ���� ���յ� ���̾��ٸ� ���� ���� �ѵ�,
		int root = visited[a] ? a : b;
		int chd = visited[a] ? b : a;
		child[root].push_back(chd);
		parent[chd] = root;
		visited[chd] = true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	Tree tree(n);
	for (int i = 0; i < n - 1; i++) {
		int a; int b;
		cin >> a >> b;
		tree.appendChild(a, b);
	}
	for (int i = 2; i <= tree.ndkz; i++) {
		cout << tree.parent[i] << endl;
	}
	return 0;
}