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
	cout << "현재 dp함수: " << cur << " 에서 " << ed << "까지의 함수에 진입 " << endl;
	if (cur<1 || cur>N || ed<1 || ed>N)//범위초과면 볼 필요도 없다
		return -10000000;
	if (done[cur][ed])
		return memo[cur][ed];

	visited[cur] = true;
	if (cur == ed) {
		cout << "[똑같다]: memo[" << cur << "][" << ed << "]는 " << 0 << endl;
		memo[cur][ed] = 0;
		done[cur][ed] = true;
		visited[cur] = false;
		return 0;
	}

	int mincost = INTINF;
	for (string selection : adj[cur]) {//selection의 선지가 복수개라면, 전부다 false라야 
		cout << "[새로운 분기탐색의 시작]" << selection << " 선지를 앨리스가 골랐다고 치자" << endl;
		int maxcost = INTMININF;
		if (cur == 2 && ed == 1 && selection == "ad")
			cout << "kokoda" << endl;
		for (char c : selection) {//모두 해당 선지가 외통수라면 -1 출력
			int next = atoi(c);
			if (visited[next]) {
				cout << selection << " 선지는 방문한 노드가 포함되어있으므로 거른다" << endl;
				maxcost = INTMININF;
				break;
			}
			
			int ans = DP(next, ed, false) + 1;
			if (ans == 0) {
				cout << selection << " 선지는 노답이라고 이미 알려져있으므로 거른다" << endl;
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
			cout << "일단 최소최대비용 " << mincost << " 기억" << endl;
		}
	}

	visited[cur] = false;
	if (isFirst) {
		done[cur][ed] = true;
		if (mincost == INTINF) {
			cout << "memo[" << cur << "][" << ed << "]는 " << -1 << endl;
			memo[cur][ed] = -1;
			return -1;
		}
		else {
			cout << "memo[" << cur << "][" << ed << "]는 " << mincost << endl;
			memo[cur][ed] = mincost;//해당 노드로부터의 모든 선지 소진시 노답판정
			return memo[cur][ed];
		}
	}
	else {
		if (mincost == INTINF) {
			return -1;
		}
		else {
			cout << cur << " " << ed << " 에서 " << mincost + 1 << " 을 저장은 하지않고 그냥 리턴만 함" << endl;
			return mincost;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	memset(memo, 0, sizeof(memo));
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
			if (r == 2 && c == 1)
				cout << "kokoda" << endl;
			DP(r, c, true);
			cout << endl;
		}
	}
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << memo[r][c] << ' ';
		}
		cout << endl;
	}

	return 0;
}