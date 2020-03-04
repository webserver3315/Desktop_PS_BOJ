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
vector<bool> visited(MAX, false);
vector<int> adj[MAX];
//vector<int> parent(MAX, -1);
//vector<int> child[MAX];

/*
An=�ñ׸�(2�����Ʒ� ������ ��忡 ���� �ڽĵ�(=3�����Ʒ�)maxBest����VS�ش����� maxBest�� �� ū ��)
*/

int DP(int nd) {
	if (N < nd)
		return 0;
	cout << nd << " �� ����� memo�� Ž���� �湮" << endl;
	if (visited[nd])
		return memo[nd];

	visited[nd] = true;
	int firkurabe = 0; int seckurabe = 0; int thrkurabe = 0;
	for (int firchd : adj[nd]) {
		if (visited[firchd])
			continue;
		for (int secchd : adj[firchd]) {
			//seckurabe = 0;
			seckurabe = DP(secchd);
			thrkurabe = 0;
			for (int thrchd : adj[secchd]) {
				thrkurabe += DP(thrchd);
			}
		}
		firkurabe += seckurabe < thrkurabe ? thrkurabe : seckurabe;
	}
	int ans = firkurabe + population[nd];
	cout << nd << " �� ����� �޸��� " << firkurabe << " �� ������ " << ans << " �� �Ǿ����ϴ�" << endl;
	memo[nd] = ans;
	return ans;
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
	int ans1, ans2 = 0;
	//visited[1] = true;
	ans1 = DP(1);
	for (int firchd : adj[1])
		ans2 += DP(firchd);
	int ans3 = ans1 < ans2 ? ans2 : ans1;
	cout << ans3 << endl;
	return 0;
}