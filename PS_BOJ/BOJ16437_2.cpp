#include <iostream>
#include <string>
#include <vector>
#define MAX 123459
#define endl '\n'
#define int long long
using namespace std;

/*
�ð��ʰ� �ذ��
1. ���ʿ� leaf ���鿡 ���ؼ��� Rush �Լ� ������
2. visited ���
*/

class Island {
public:
	bool isWolf;
	int population;
};

class Tree {
public:
	int N;
	vector<Island> country;//�� ��ü
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
				cout << i << "��° ������ ���� �α��� " << country[i].population << endl;
			else
				cout << i << "��° ������ �� �α��� " << country[i].population << endl;
		}
		cout << endl;
	}
};

void Rush(Tree& tree, int from) {//from �����κ��� 1�� ������ ����
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
	else {//�� ���̸�
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
	//vector<int> leafBuffer;//�ٳ�� �ӽ��������
	for (int i = 2; i <= N; i++) {
		if (tree.child[i].size() == 0) {//�ٳ���
			Rush(tree, i);
		}
		//tree.printPopulation();
	}
	cout << tree.country[1].population << endl;
	return 0;
}
//�ð��ʰ�����. 123456���� ����� Ʈ���ε� ������ DFS�� �����⿡�� �ð��� ���� ���������. VISITED�� �Ἥ �ð��� ���� �ʿ䰡 �ִ�.