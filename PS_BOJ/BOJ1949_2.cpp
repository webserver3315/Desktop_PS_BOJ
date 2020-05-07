#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#define MAX (int)1e4+5
#define endl '\n'

using namespace std;

int N;
vector<int> population(MAX, -1);
vector<int> memo(MAX, -1);//�ش� ��带 �ݵ�� �� �� ����Ʈ������ �ִ� ����� ����α�����
vector<bool> tmpvisited(MAX, false);
vector<bool> visited(MAX, false);
vector<int> adj[MAX];
vector<int> parent(MAX, -1);
vector<int> child[MAX];

/*
An=�ñ׸�(2�����Ʒ� ������ ��忡 ���� �ڽĵ�(=3�����Ʒ�)maxBest����VS�ش����� maxBest�� �� ū ��)
*/

int DP(int nd) {
	if (N < nd)
		return 0;
	//cout << nd << " �� ����� memo�� Ž���� �湮" << endl;
	if (visited[nd])
		return memo[nd];

	int firkurabe = 0; int seckurabe = 0; int thrkurabe = 0;
	for (int firchd : child[nd]) {
		for (int secchd : child[firchd]) {
			//seckurabe = 0;
			seckurabe = DP(secchd);
			thrkurabe = 0;
			for (int thrchd : child[secchd]) {
				thrkurabe += DP(thrchd);
			}
			firkurabe += seckurabe < thrkurabe ? thrkurabe : seckurabe;
		}
	}
	int ans = firkurabe + population[nd];
	//cout << nd << " �� ����� �޸��� " << firkurabe << " �� ������ " << ans << " �� �Ǿ����ϴ�" << endl;
	memo[nd] = ans;
	visited[nd] = true;
	return ans;
}

void makeAdjTree(int nd) {//Adj���ͷ� ��Ʈ�� 1�� �ϴ� parent, child Ʈ���� �ϼ���Ų��.
	for (int chd : adj[nd]) {
		if (tmpvisited[chd])
			continue;
		tmpvisited[chd] = true;
		parent[chd] = nd;
		child[nd].push_back(chd);
		makeAdjTree(chd);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> population[i];
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	tmpvisited[1] = true;
	makeAdjTree(1);
	int ans1, ans2 = 0;
	ans1 = DP(1);
	for (int firchd : child[1])
		ans2 += DP(firchd);
	int ans3 = ans1 < ans2 ? ans2 : ans1;
	cout << ans3 << endl;
	return 0;
}