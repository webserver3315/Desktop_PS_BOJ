#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;

int ccw(pii a, pii b, pii c) {
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}
/*
선분교차판별알고리즘
*/
int isIntersect(pair<pii, pii> x, pair<pii, pii> y) {
	pii a = x.first;
	pii b = x.second;
	pii c = y.first;
	pii d = y.second;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d, w, x, y, z;
	cin >> a >> b >> c >> d;
	cin >> w >> x >> y >> z;
	if (isIntersect(mp(mp(a, b), mp(c, d)), mp(mp(w, x), mp(y, z)))) {
		cout << 1 << endl;
	}
	else
		cout << 0 << endl;

	return 0;
}
