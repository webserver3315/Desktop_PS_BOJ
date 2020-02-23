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
bool IsVoid[MAX];//��尡 ����������� ����
vector<int> parent;
vector<int> child[MAX];//�ѹ��Ẹ��;���

bool IsLeaf(int node) {
	if (child[node].size() == 0)
		return true;
	return false;
}

void delNode(int node) {
	IsVoid[node] = true;
	int par = parent[node];
	parent[node] = -1;
	for (int i = 0; i < child[par].size(); i++) {
		if (child[par][i] == node) {
			child[par].erase(child[par].begin() + i);
			for (int i : child[node]) {
				delNode(i);
			}
			return;
		}
	}
}

int main() {
	cin >> N;
	parent.resize(N,-1);
	for (int i = 0; i < N; i++) {
		cin >> parent[i];
		if (parent[i] != -1)
			child[parent[i]].push_back(i);
	}
	int del;
	cin >> del;
	delNode(del);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!IsVoid[i] && IsLeaf(i)) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
/*�� ����
���� �� �����غôµ�
��Ʈ��常 ���ָ� ���� �� �������°ǵ�,
ȥ�� ��Ʈ��常 �������� 2�� �̻��� ������Ʈ�� ���صȴٰ� �ڴ�� �����ߴ�*/