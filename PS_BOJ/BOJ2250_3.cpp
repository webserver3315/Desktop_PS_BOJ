#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#define MAX (int)1e4+1
#define INTINF 987654321
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

int N;
int xcnt;
int maxdepth;
vector<int> x_val;
vector<int> parent;
vector<pii> child;
vector<pii> dist;

void inorder(int rt, int lev) {
	int& left = child[rt].ff;
	int& right = child[rt].ss;
	if (maxdepth < lev)
		maxdepth = lev;

	if (left != -1)
		inorder(left, lev + 1);

	x_val[rt] = xcnt++;
	if (x_val[rt] < dist[lev].ff) {
		dist[lev].ff = x_val[rt];
	}
	if (x_val[rt] > dist[lev].ss) {
		dist[lev].ss = x_val[rt];
	}

	if (right != -1)
		inorder(right, lev + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	x_val.resize(N + 1, -1);
	parent.resize(N + 1, -1);
	pii init = mp(INTINF, -1);
	child.resize(N + 1);
	dist.resize(N + 1, init);
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		child[a] = mp(b, c);// child[a].ff = b; child[a].ss = c;
		if (b != -1)
			parent[b] = a;
		if (c != -1)
			parent[c] = a;
	}

	int root;
	for (int i = 1; i <= N; i++) {
		if (parent[i] == -1) {
			root = i;
			break;
		}
	}

	/*root가 반드시 1이라는 보장이 없다는걸 타블로그 풀이보고서야 1시간30분만에 깨달았다 ㅆㅂ;;*/
	inorder(root, 1);

	int ans = 1;
	for (int i = 1; i <= maxdepth; i++) {
		if (dist[ans].ss - dist[ans].ff < dist[i].ss - dist[i].ff)
			ans = i;
	}

	cout << ans << ' ' << dist[ans].ss - dist[ans].ff + 1 << endl;

	return 0;
}