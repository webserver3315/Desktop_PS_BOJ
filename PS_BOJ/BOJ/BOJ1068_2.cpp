#include <iostream>
#include <vector>
#include <stdlib.h>
#define endl '\n'
using namespace std;

/*
무방향 트리라는 변태적 상황을 제외하면, 트리에는 부모가 2개 이상 있어서는 안된다. 그러면 해당 노드로 가는 경로의 수가 unique하지 않기 때문이다.
이걸 이용해 풀자. 그냥 parent 를 끊어버리면 되는 것이다.

혹시 이 문제 컴포넌트가 여러개인 경우도 고려해야하나?
ㅅㅂ 맞는 것 같은데...? ㄹㅇ 컴포넌트 여러 개인 경우도 고려해야 할 것 같은데?
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
	void korosu(int node) {//node를 호적에서 판다.
		int par = parent[node];
		if (par == -1) {//루트노드를 지우려 한 경우

		}
		for (int i = 0; i < child[par].size(); i++) {
			if (child[par][i] == node) {//부모가 unique함이 보장되고, 해당 부모로부터 node라는 자식 삭제
				child[par].erase(child[par].begin() + i);
				return;
			}
		}
		cout << "ERROR" << endl;
		exit(1);
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
	cout << "트리의 원래 자식 개수 : " << tree.CntLeaf(0) << endl;
	tree.korosu(del);
	int cutted = tree.CntLeaf(0);
	cout << cutted << endl;
	//int original = tree.CntLeaf(0);
	//cout << "새로운 시작" << endl;
	//cout << original - cutted << endl;
	
	return 0;
}