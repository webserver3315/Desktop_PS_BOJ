#include <bits/stdc++.h>
#define pis pair<int, string>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;

int n;
vector<pis> vct;

/*
stable sort
*/
bool mycmp(const pis& a, const pis& b) {//cpp에서는 swap해야한다면 true반환하는게 국룰.
	if (a.ff < b.ff)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; string b;
		cin >> a >> b;
		vct.push_back(mp(a, b));
	}
	stable_sort(vct.begin(), vct.end(), mycmp);
	for (auto a : vct) {
		cout << a.ff << ' ' << a.ss << endl;
	}

	return 0;
}