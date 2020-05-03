#include <iostream>
#include <vector>
#include <stdlib.h>
#define endl '\n'
using namespace std;

/*
������ Ʈ����� ������ ��Ȳ�� �����ϸ�, Ʈ������ �θ� 2�� �̻� �־�� �ȵȴ�. �׷��� �ش� ���� ���� ����� ���� unique���� �ʱ� �����̴�.
�̰� �̿��� Ǯ��. �׳� parent �� ��������� �Ǵ� ���̴�.

Ȥ�� �� ���� ������Ʈ�� �������� ��쵵 ����ؾ��ϳ�?
���� �´� �� ������...? ���� ������Ʈ ���� ���� ��쵵 ����ؾ� �� �� ������?
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
	void korosu(int node) {//node�� ȣ������ �Ǵ�.
		int par = parent[node];
		if (par == -1) {//��Ʈ��带 ����� �� ���

		}
		for (int i = 0; i < child[par].size(); i++) {
			if (child[par][i] == node) {//�θ� unique���� ����ǰ�, �ش� �θ�κ��� node��� �ڽ� ����
				child[par].erase(child[par].begin() + i);
				return;
			}
		}
		cout << "ERROR" << endl;
		exit(1);
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
	cout << "Ʈ���� ���� �ڽ� ���� : " << tree.CntLeaf(0) << endl;
	tree.korosu(del);
	int cutted = tree.CntLeaf(0);
	cout << cutted << endl;
	//int original = tree.CntLeaf(0);
	//cout << "���ο� ����" << endl;
	//cout << original - cutted << endl;
	
	return 0;
}