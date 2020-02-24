#include <iostream>
#include <string>
#include <vector>
#define MAX 123459
#define endl '\n'
#define int long long
using namespace std;

/*
시간초과 해결안
1. 애초에 leaf 노드들에 한해서만 Rush 함수 때리기
2. visited 사용
*/

class Island {
public:
	bool isWolf;
	int population;
};

class Tree {
public:
	int N;
	vector<Island> country;//섬 전체
	vector<int> parent;
	vector<vector<int>> child;
	//vector<bool> visited;
	Tree() :N(0) {}
	Tree(int n) :N(n + 1) {
		country.resize(N);
		parent.resize(N, -1);
		child.resize(N);
		//visited.resize(N, false);
	}
	void appendChild(int p, int c) {
		parent[c] = p;
		child[p].push_back(c);
	}
	void printPopulation() {
		for (int i = 1; i < N; i++) {
			if (country[i].isWolf)
				cout << i << "번째 나라의 늑대 인구는 " << country[i].population << endl;
			else
				cout << i << "번째 나라의 양 인구는 " << country[i].population << endl;
		}
		cout << endl;
	}
};

void Rush(Tree& tree, int from) {//from 섬으로부터 1번 섬으로 러쉬
	int next = tree.parent[from];
	if (next == -1)
		return;
	if (tree.country[from].isWolf) {
		Rush(tree, next);
	}
	else if (tree.country[next].isWolf) {
		tree.country[next].population -= tree.country[from].population;
		if (tree.country[next].population <= 0) {
			tree.country[next].isWolf = false;
			tree.country[next].population *= -1;
		}
		tree.country[from].population = 0;
		Rush(tree, next);
	}
	else {//양 섬이면
		tree.country[next].population += tree.country[from].population;
		tree.country[from].population = 0;
		Rush(tree, next);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int N;
	cin >> N;
	Tree tree(N);
	for (int i = 2; i <= N; i++) {
		string a; int b; int c; bool d;
		cin >> a >> b >> c;
		if (a == "W")
			d = true;
		else
			d = false;
		tree.country[i].isWolf = d;
		tree.country[i].population = b;
		tree.parent[i] = c;
		tree.child[c].push_back(i);
	}
	tree.country[1].population = 0;
	//vector<int> leafBuffer;//잎노드 임시저장버퍼
	for (int i = 2; i <= N; i++) {
		if (tree.child[i].size() == 0) {//잎노드면
			Rush(tree, i);
		}
		//tree.printPopulation();
	}
	cout << tree.country[1].population << endl;
	return 0;
}
//시간초과떴다. 123456개의 노드의 트리인데 뇌비우고 DFS로 돌리기에는 시간이 많이 들었나보다. VISITED라도 써서 시간을 줄일 필요가 있다.