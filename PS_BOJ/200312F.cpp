#include <iostream>
#include <vector>
//#include <string>
#define endl '\n'
#define MAX (int)2e5+1
using namespace std;

int n;
bool isWhite[MAX];
int memo[MAX];
vector<int> child[MAX];
int parent[MAX];
vector<int> adj[MAX];
bool visited[MAX];

void postorder(int n) {
	visited[n] = true;
	for (int ch : adj[n]) {
		if (visited[ch])
			continue;
		child[n].push_back(ch);
		parent[ch] = n;
		postorder(ch);
	}
}

//����: n ��尡 ���� �� �ִ� �ڽĳ�� ���� �ִ�
int kaikei(int n) {//������ȸ�� ���
	if (isWhite[n])
		memo[n] = 1;
	else
		memo[n] = -1;
	for (int ch : child[n]) {
		if (kaikei(ch) > 0)
			memo[n] += memo[ch];
	}
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> isWhite[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a; int b;
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(parent, -1, sizeof(parent));
		mem(memo)
		child->clear();
		memset(visited, false, sizeof(visited));
		postorder(i);//1��Ʈ���� ��Ʈ�� �ϴ� ����Ʈ�� ����
		kaikei(i);
		cout << memo[i] << endl;
	}

	//�� ������ȸ n�������°� ���ΰ�?
	return 0;
}