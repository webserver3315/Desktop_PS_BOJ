#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#define MAX (int)1e4+2
#define INTINF 987654321
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

class Tree {
public:
	int N;
	vector<int> parent;
	vector<pii> child;

	int x_num = 1;
	int maxLev;
	int maxLevDist;
	int maxdepth = 0;
	vector<int> x_val;
	vector<int> level;
	vector<pii> level_MinAndMax;
	vector<int> level_dist;

	Tree() :N(0) {}
	Tree(int n) :N(n) {
		parent.resize(N, -1);
		child.resize(N);
		x_val.resize(N, -1);
		pii tmp = mp(987654321, 0);
		level.resize(N, -1);
		level_MinAndMax.resize(N, tmp);
		level_dist.resize(N, -1);
	}
	void appendChild(int p, int l, int r) {
		child[p].ff = l; child[p].ss = r;
		if (l != -1)
			parent[l] = p;
		if (r != -1)
			parent[r] = p;
	}
	void x_update(int root, int lev) {//중위순회로 돌면 x축순으로 돈다. 그걸 이용해서 x값을 노드별로 기록한다.
		if (child[root].ff != -1)
			x_update(child[root].ff, lev + 1);

		x_val[root] = x_num++;
		level[root] = lev;
		if (maxdepth < lev)
			maxdepth = lev;
		if (x_val[root] < level_MinAndMax[lev].ff)
			level_MinAndMax[lev].ff = x_val[root];
		if (level_MinAndMax[lev].ss < x_val[root])
			level_MinAndMax[lev].ss = x_val[root];
		if (level_MinAndMax[lev].ss - level_MinAndMax[lev].ff > level_dist[lev]) {
			level_dist[lev] = level_MinAndMax[lev].ss - level_MinAndMax[lev].ff + 1;
		}

		if (child[root].ss != -1)
			x_update(child[root].ss, lev + 1);
	}
};

int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	N++;
	Tree tree(N);
	N--;
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree.appendChild(a, b, c);
	}
	tree.x_update(1, 1);

	int ans = 1;
	for (int i = 1; i <= tree.maxdepth; i++) {
		if (tree.level_MinAndMax[ans].ff - tree.level_MinAndMax[ans].ss < tree.level_MinAndMax[i].ss - tree.level_MinAndMax[i].ff)
			ans = i;
	}

	cout << ans << ' ' << tree.level_MinAndMax[ans].ff - tree.level_MinAndMax[ans].ss + 1 << endl;

	return 0;
}