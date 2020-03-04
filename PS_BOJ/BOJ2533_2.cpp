/*
�󸮾���Ͱ� �����ؾ߸� ���� �� �ִ� �����ذ� �ִٸ�, �� ������ �ݷʰ� �ȴ�.
����:https://jaimemin.tistory.com/592
�ش� ������ ������ �ٽ� Ǯ���.
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#define MAX (int)1e6+5
#define endl '\n'
using namespace std;

int N;
//vector<int> parent(MAX, -1);
vector<int> child[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int cnt1;//1�� ���� ���� ������ ����
int cnt2;//1�� ���� �ٸ� ������ ����
int memo[MAX][2];//0: �̳�, 1: ��

void makeTree(int n, int depth) {
	visited[n] = true;
	for (int ch : adj[n]) {
		if (!visited[ch]) {
			//parent[ch] = n;
			child[n].push_back(ch);
			makeTree(ch, depth + 1);
		}
	}
}

int DP(int n, bool isEarly) {
	/*
	�ش� ��Ʈ�� ĥ�� ��, ���� �� �ִ� �ּ��� �󸮾���� ���� ���� ����Ѵ�.
	���� ��Ʈ�� �󸮾���Ͷ��, �ڽĵ� �󸮾���Ϳ��� �������.
		min(DP(ch, isEarly),DP(ch, !isEarly))�� ��� ���� ��, ��Ʈ�� ���̹Ƿ� +1�Ѵ�.
	�ٸ�, ��Ʈ�� �̳��̸� �ڽ� ���ΰ� �󸮾���Ϳ��߸� �Ѵ�.
		DP(ch, isEarly) �� ��� ���� ��, ��Ʈ�� �̳��̹Ƿ� +1 ���Ѵ�.
	�� ��Ģ�� ��Ʈ���� �ٸ� ��尡 ���͵� �ϰ�����ȴ�.
	*/
	int& ret = memo[n][isEarly];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int chd : child[n]) {
		if (isEarly) {
			int add = min(DP(chd, true), DP(chd, false));
			ret += add;
		}
		else {
			int add = DP(chd, true);
			ret += add;
		}
	}
	if (isEarly)
		ret += 1;
	return ret;
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
	memset(memo, -1, sizeof(memo));
	makeTree(1, 1);

	cnt1 = DP(1, true);
	cnt2 = DP(1, false);
	cout << min(cnt1, cnt2) << endl;

	return 0;
}