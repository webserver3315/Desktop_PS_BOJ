#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

/*
������ Ʈ����� ������ ��Ȳ�� �����ϸ�, Ʈ������ �θ� 2�� �̻� �־�� �ȵȴ�. �׷��� �ش� ���� ���� ����� ���� unique���� �ʱ� �����̴�.
�̰� �̿��� Ǯ��. �׳� parent �� ��������� �Ǵ� ���̴�.
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
	void korosu(int node) {//node�� ȣ������ �Ǵ� // �����غ��� �̰� �ʿ����. �׳� ������� ������ �ٳ�尳�� ���� �ڿ� �������� ���ݾ�?
		int par = parent[node];
		for (int i = 0; i < child[par].size(); i++) {
			if (child[par][i] == node) {
				child[par].erase(child[par].begin() + i);
				break;
			}
		}
	}
	int CntLeaf(int node) {//node ������ �ٳ�� ���� ī����
		int cnt = 0;
		for (int i = 0; i < child[node].size(); i++) {
			int next = child[node][i];
			if (child[next].size() == 0) {//�ٳ���
				//cout << next << " ��尡 �ٳ��" << endl;
				cnt++;
			}
			else {
				cnt += CntLeaf(next);
			}
		}
		if (child[node].size() == 0)//������ ��尡 ���� �� �����, cnt�� �׳� 1�̴�.
			cnt = 1;
		return cnt;
	}
	/*�����ߴ�. �ܼ��� ��ü �ٰ��� - �ش� �κ�Ʈ�� �� ���� �ϸ� �ȵȴ�. �� ���, ��尡 �ϳ� �� ���� ���ɼ��� ������� ���Ѵ�.*/
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
	//cout << "���ο� ����" << endl;
	int cutted = tree.CntLeaf(del);
	if (tree.child[tree.parent[del]].size() == 1)//-1 0 0 1 2 3 4 1 �� �� 4�� �����ص� 2����尡 ���� �ǹǷ�
		cutted--;
	cout << original - cutted << endl;
	return 0;
}