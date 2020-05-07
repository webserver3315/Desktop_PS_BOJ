#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define endl '\n'
#define INTINF 987654321
using namespace std;

int N;
vector<string> adj[27];
int memo[27][27];
bool done[27][27];
bool visited[27];

int atoi(char a) {
	return a - 'a' + 1;
}

int DP(int cur, int ed) {//cur에서 ed로 가기 위해 필요한 최소비용 출력
	//cout << "현재 dp함수: " << cur << " 에서 " << ed << "까지의 함수에 진입 " << endl;
	if (cur<1 || cur>N || ed<1 || ed>N)//범위초과면 볼 필요도 없다
		return -10000000;
	if (done[cur][ed])
		return memo[cur][ed];

	done[cur][ed] = true;
	visited[cur] = true;
	if (cur == ed) {
		//cout << "Bob 사살이 가능함. 장담인지는 모름" << endl;
		memo[cur][ed] = 0;
		return 0;
	}
	//기본적으로 최적해를 찾기 위해, BFS로 DP한다. 아니 근데 재귀로 BFS? 말이 안되는데?
	int mincost = INTINF;
	int maxcost = -5;
	for (string selection : adj[cur]) {//selection의 선지가 복수개라면, 전부다 false라야 
		//cout << "[새로운 분기탐색의 시작]" << selection << " 선지를 앨리스가 골랐다고 치자" << endl;
		for (char c : selection) {//모두 해당 선지가 외통수라면 -1 출력
			int next = atoi(c);
			if (visited[next]) {
				//cout << next << "번 노드는 한 번 들렀던 노드이므로 거른다" << endl;
				continue;
			}
			int ans = DP(next, ed);
			if (ans == -1) {
				//cout << next << " 노드의 노답노드가, 해당 선지의 분기 중 노답노드가 있기에 거른다" << endl;
				break;
			}
			else {
				if (ans > maxcost)
					maxcost = ans;
			}
		}
		//cout << "max값: " << maxcost << endl;
		if (maxcost != -5 && maxcost < mincost)
			mincost = maxcost;
		//cout << "min값: " << mincost << endl;
	}
	if (maxcost == -5) {
		//cout << "memo[" << cur << "][" << ed << "]는 " << -1 << endl;
		memo[cur][ed] = -1;
	}
	else {
		//cout << "memo[" << cur << "][" << ed << "]는 " << mincost << '+' << 1 << endl;
		memo[cur][ed] = mincost + 1;//해당 노드로부터의 모든 선지 소진시 노답판정
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	//memset(memo, 0, sizeof(memo));
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
			//cout << DP(r,c) << ' ';
			DP(r, c);
		}
		//cout << endl;
	}
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << memo[r][c] << ' ';
		}
		cout << endl;
	}

	return 0;
}