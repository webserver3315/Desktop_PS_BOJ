#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define endl '\n'
#define INTINF 987654321
#define INTMININF -987654321
using namespace std;

int N;
vector<string> adj[27];
int memo[27][27];
bool done[27][27];
bool visited[27];

int atoi(char a) {
	return a - 'a' + 1;
}

int DP(int cur, int ed, bool isFirst) {//cur에서 ed로 가기 위해 필요한 최소비용 출력
	if (done[cur][ed])
		return memo[cur][ed];

	visited[cur] = true;
	if (cur == ed) {
		memo[cur][ed] = 0;
		done[cur][ed] = true;
		visited[cur] = false;
		return 0;
	}

	int mincost = INTINF;
	for (string selection : adj[cur]) {//selection의 선지가 복수개라면, 전부다 false라야 
		int maxcost = INTMININF;
		for (char c : selection) {//모두 해당 선지가 외통수라면 -1 출력
			int next = atoi(c);
			if (visited[next]) {
				maxcost = INTMININF;
				break;
			}

			int ans = DP(next, ed, false) + 1;
			if (ans == 0) {
				maxcost = INTMININF;
				break;
			}
			else {
				if (ans > maxcost)
					maxcost = ans;
			}
		}
		if (maxcost != INTMININF && maxcost < mincost) {
			mincost = maxcost;
		}
	}

	visited[cur] = false;
	if (isFirst) {
		done[cur][ed] = true;
		if (mincost == INTINF) {
			memo[cur][ed] = -1;
			return -1;
		}
		else {
			memo[cur][ed] = mincost;//해당 노드로부터의 모든 선지 소진시 노답판정
			return memo[cur][ed];
		}
	}
	else {
		if (mincost == INTINF) {
			return -1;
		}
		else {
			return mincost;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		while (num--) {
			string selection;
			cin >> selection;
			adj[i].push_back(selection);
		}
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			memset(visited, false, sizeof(visited));
			cout << DP(r, c, true) << ' ';
		}
		cout << endl;
	}

	return 0;
}