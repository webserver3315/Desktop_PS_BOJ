#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 55
using namespace std;
/*
이번엔 인접리스트를 이용해서 풀어보자
*/


//vector<int> adjlist[MAX];
int N;
bool IsVoid[MAX];//노드가 사라졌는지의 여부
vector<int> parent;
vector<int> child[MAX];//한번써보고싶었다

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
/*아 ㅆㅂ
조금 더 생각해봤는데
루트노드만 없애면 전부 다 없어지는건데,
혼자 루트노드만 없어지고 2개 이상의 컴포넌트로 분해된다고 멋대로 생각했다*/