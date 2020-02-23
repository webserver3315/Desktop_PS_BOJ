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
vector<int> parent;
vector<int> child[MAX];//한번써보고싶었다
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
/*아 ㅆㅂ
조금 더 생각해봤는데
루트노드만 없애면 전부 다 없어지는건데,
혼자 루트노드만 없어지고 2개 이상의 컴포넌트로 분해된다고 멋대로 생각했다

또 착각했음을 깨달았다
여러개의 컴포넌트가 주어질 수 있다고 상정하고 생각했는데
아니, 그런데 애초에 트리가 주어진다고 했지 단 하나의 트리가 주어진다는 언급은 없는데 너무 엉성한 문제 아닌가?
루트는 단 하나만 주어짐이 보장된 모양이다.*/