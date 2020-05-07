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

int DP(int cur, int ed) {//cur���� ed�� ���� ���� �ʿ��� �ּҺ�� ���
	//cout << "���� dp�Լ�: " << cur << " ���� " << ed << "������ �Լ��� ���� " << endl;
	if (cur<1 || cur>N || ed<1 || ed>N)//�����ʰ��� �� �ʿ䵵 ����
		return -10000000;
	if (done[cur][ed])
		return memo[cur][ed];

	done[cur][ed] = true;
	visited[cur] = true;
	if (cur == ed) {
		//cout << "Bob ����� ������. ��������� ��" << endl;
		memo[cur][ed] = 0;
		return 0;
	}
	//�⺻������ �����ظ� ã�� ����, BFS�� DP�Ѵ�. �ƴ� �ٵ� ��ͷ� BFS? ���� �ȵǴµ�?
	int mincost = INTINF;
	int maxcost = -5;
	for (string selection : adj[cur]) {//selection�� ������ ���������, ���δ� false��� 
		//cout << "[���ο� �б�Ž���� ����]" << selection << " ������ �ٸ����� ����ٰ� ġ��" << endl;
		for (char c : selection) {//��� �ش� ������ �������� -1 ���
			int next = atoi(c);
			if (visited[next]) {
				//cout << next << "�� ���� �� �� �鷶�� ����̹Ƿ� �Ÿ���" << endl;
				continue;
			}
			int ans = DP(next, ed);
			if (ans == -1) {
				//cout << next << " ����� ����尡, �ش� ������ �б� �� ����尡 �ֱ⿡ �Ÿ���" << endl;
				break;
			}
			else {
				if (ans > maxcost)
					maxcost = ans;
			}
		}
		//cout << "max��: " << maxcost << endl;
		if (maxcost != -5 && maxcost < mincost)
			mincost = maxcost;
		//cout << "min��: " << mincost << endl;
	}
	if (maxcost == -5) {
		//cout << "memo[" << cur << "][" << ed << "]�� " << -1 << endl;
		memo[cur][ed] = -1;
	}
	else {
		//cout << "memo[" << cur << "][" << ed << "]�� " << mincost << '+' << 1 << endl;
		memo[cur][ed] = mincost + 1;//�ش� ���κ����� ��� ���� ������ �������
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