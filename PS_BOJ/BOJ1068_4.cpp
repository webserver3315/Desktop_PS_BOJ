#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 55
using namespace std;
/*
�̹��� ��������Ʈ�� �̿��ؼ� Ǯ���
*/


//vector<int> adjlist[MAX];
int N;
vector<int> parent;
vector<int> child[MAX];//�ѹ��Ẹ��;���
int leafcnt;

bool IsLeaf(int node) {
	if (child[node].size() == 0)
		return true;
	return false;
}

void delNode(int node) {
	int par = parent[node];
	parent[node] = -1;
	for (int i = 0; i < child[par].size(); i++) {
		if (child[par][i] == node) {
			child[par].erase(child[par].begin() + i);
			return;
		}
	}
}

void DFS(int node) {
	for (int i = 0; i < child[node].size(); i++) {
		int next = child[node][i];
		if (child[next].empty())
			leafcnt++;
		else
			DFS(next);
	}
}

int main() {
	cin >> N;
	parent.resize(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> parent[i];
		if (parent[i] != -1)
			child[parent[i]].push_back(i);
	}
	int del;
	cin >> del;
	if (del == 0) {
		cout << 0 << endl;
		return 0;
	}

	delNode(del);
	DFS(0);
	cout << leafcnt << endl;
	return 0;
}
/*�� ����
���� �� �����غôµ�
��Ʈ��常 ���ָ� ���� �� �������°ǵ�,
ȥ�� ��Ʈ��常 �������� 2�� �̻��� ������Ʈ�� ���صȴٰ� �ڴ�� �����ߴ�

�� ���������� ���޾Ҵ�
�������� ������Ʈ�� �־��� �� �ִٰ� �����ϰ� �����ߴµ�
�ƴ�, �׷��� ���ʿ� Ʈ���� �־����ٰ� ���� �� �ϳ��� Ʈ���� �־����ٴ� ����� ���µ� �ʹ� ������ ���� �ƴѰ�?
��Ʈ�� �� �ϳ��� �־����� ����� ����̴�.*/