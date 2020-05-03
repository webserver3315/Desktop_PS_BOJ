#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#define MAX (int)1e6+5
#define endl '\n'
using namespace std;

int N;
vector<int> parent(MAX,-1);
vector<int> child[MAX];
vector<int> adj[MAX];
bool visited[MAX];
bool visited2[MAX];
int level[MAX];//�� ��庰 ���̸� ����
deque<int> buffer;
int cnt1;//1�� ���� ���� ������ ����
int cnt2;//1�� ���� �ٸ� ������ ����


//int getLevel(int n) {//��Ʈ��� ���� �� Ʈ����ü�� Height�� ���ϴ� �Լ�����, �� ����� depth�� ���ϴ� �Լ��� �ƴϴ�!
//	if (level[n] != -1)
//		return level[n];
//	int result = 1;
//	for (int ch : child[n]) {
//		result = max(result, getLevel(ch) + 1);
//	}
//	level[n] = result;
//	return result;
//}
//
//int getLevel(int n) {
//	visited2[n] = true;
//
//}

void makeTree(int n, int depth) {
	visited[n] = true;
	level[n] = depth;
	if (depth % 2 == 0)
		cnt2++;
	else
		cnt1++;
	for (int ch : adj[n]) {
		if (!visited[ch]) {
			parent[ch] = n;
			child[n].push_back(ch);
			makeTree(ch, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	memset(level, -1, sizeof(level));
	makeTree(1, 1);

	cout << min(cnt1, cnt2) << endl;

	return 0;
}