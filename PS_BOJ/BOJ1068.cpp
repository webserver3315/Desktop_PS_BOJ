#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

/*
무방향 트리라는 변태적 상황을 제외하면, 트리에는 부모가 2개 이상 있어서는 안된다. 그러면 해당 노드로 가는 경로의 수가 unique하지 않기 때문이다.
이걸 이용해 풀자. 그냥 parent 를 끊어버리면 되는 것이다.
*/

class Tree {
public:
	int N;
	vector<int> parent;
	vector<vector<int>> child;
	Tree() :N(0) {}
	Tree(int n) :N(n) {
		parent.resize(N, -1);
		child.resize(N);
	}
	void append(int par, int chd) {
		parent[chd] = par;
		child[par].push_back(chd);
	}
	void korosu(int node) {//node를 호적에서 판다 // 생각해보니 이거 필요없네. 그냥 삭제노드 휘하의 잎노드개수 뽑은 뒤에 빼버리면 되잖아?
		int par = parent[node];
		for (int i = 0; i < child[par].size(); i++) {
			if (child[par][i] == node) {
				child[par].erase(child[par].begin() + i);
				break;
			}
		}
	}
	int CntLeaf(int node) {//node 휘하의 잎노드 개수 카운팅
		int cnt = 0;
		for (int i = 0; i < child[node].size(); i++) {
			int next = child[node][i];
			if (child[next].size() == 0) {//잎노드면
				//cout << next << " 노드가 잎노드" << endl;
				cnt++;
			}
			else {
				cnt += CntLeaf(next);
			}
		}
		if (child[node].size() == 0)//저격한 노드가 만일 잎 노드라면, cnt는 그냥 1이다.
			cnt = 1;
		return cnt;
	}
	/*착각했다. 단순히 전체 잎개수 - 해당 부분트리 잎 개수 하면 안된다. 그 경우, 노드가 하나 더 생길 가능성을 고려하지 못한다.*/
};

int main() {
	int n;
	cin >> n;
	Tree tree(n);
	for (int i = 0; i < n; i++) {
		int par;
		cin >> par;
		if (par != -1)
			tree.append(par, i);
	}
	int del;
	cin >> del;
	int original = tree.CntLeaf(0);
	//cout << "새로운 시작" << endl;
	int cutted = tree.CntLeaf(del);
	if (tree.child[tree.parent[del]].size() == 1)//-1 0 0 1 2 3 4 1 일 때 4를 삭제해도 2번노드가 잎이 되므로
		cutted--;
	cout << original - cutted << endl;
	return 0;
}