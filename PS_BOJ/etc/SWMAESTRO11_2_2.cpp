#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define pii pair<long,long>
#define mp(a,b) make_pair(a,b)
using namespace std;

int n, m;//사람수와 관계수
int pa[300001];
pii piiarr[300001];
int minx[300001];
int maxx[300001];
int miny[300001];
int maxy[300001];
bool done[300001];
int maxval;

int find(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = find(pa[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pa[b] = a;
}

int getlength(int i) {
	return 2 * ((maxx[i] - minx[i]) + (maxy[i] - miny[i]));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/*memset(minx, 100000001, sizeof(minx));
	memset(miny, 100000001, sizeof(miny));*/

	for (int i = 0; i < 300001; i++) {
		minx[i] = 100000001;
		miny[i] = 100000001;
	}

	cin >> n >> m;
	memset(pa, -1, sizeof(pa));
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		piiarr[i] = mp(x, y);
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		pii p = piiarr[i];
		int x = p.ff; int y = p.ss; int par = find(i);
		if (par == -1) {
			if (x < minx[i]) minx[i] = x;
			if (x > maxx[i]) maxx[i] = x;
			if (y < miny[i]) miny[i] = y;
			if (y > maxy[i]) maxy[i] = y;
		}
		else {
			if (x < minx[par]) minx[par] = x;
			if (x > maxx[par]) maxx[par] = x;
			if (y < miny[par]) miny[par] = y;
			if (y > maxy[par]) maxy[par] = y;
		}
	}

	for (int i = 1; i <= n; i++) {
		int par = find(i);
		if (done[par]) continue;
		done[par] = true;
		if (maxval < getlength(par)) {
			//cout << i << " 는 i, " << par << "에서 업데이트 발생" << endl;
			maxval = getlength(par);
		}
	}
	cout << maxval << endl;
	return 0;
}