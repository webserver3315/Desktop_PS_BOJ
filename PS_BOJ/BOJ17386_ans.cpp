#include <bits/stdc++.h>

using namespace std;

#define ll long long

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

	if (temp > 0) return 1; // �ݽð�
	else if (temp == 0) return 0; // ������
	else if (temp < 0) return -1; // �ð�
}

bool chk(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d)
{
	int abc = ccw(a, b, c);
	int abd = ccw(a, b, d);
	int cda = ccw(c, d, a);
	int cdb = ccw(c, d, b);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		return a <= d && c <= b;
	}

	return abc * abd <= 0 && cda * cdb <= 0;
}

int main(void)
{	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		if (i == 13) {
			cout << 1010101010 << endl;
			cout << 1010101010 << endl;
			printf("stop");
			cout << 1010101010 << endl;
		}
		pair<ll, ll> xy[4];

		for (int i = 0; i < 4; i++)
			scanf("%lld %lld", &xy[i].first, &xy[i].second);

		if (chk(xy[0], xy[1], xy[2], xy[3])) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
