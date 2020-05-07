/*
대회 or 인턴
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	n = n - n % 2;
	k = k - n % 2;

	int JoshiTeam = n / 2;
	int DanseiTeam = m;
	int MaxTeam = min(JoshiTeam, DanseiTeam);
	int IzimeJoshi = (JoshiTeam - MaxTeam) * 2;
	int IzimeDansei = (DanseiTeam - MaxTeam);
	k = k - IzimeJoshi - IzimeDansei;
	if (k <= 0) {
		printf("%d\n", MaxTeam);
		return 0;
	}
	/*이제 진또로 딱 떨어진 최적의 n과 m만이 남음*/

	printf("%d\n", MaxTeam - (int)ceil(k / 3.0));
}

int main2() {
	int n, m, k;
	cin >> n >> m >> k;
	int jt=n/2, dt=m;/*여자팀, 남자팀, 최대팀*/
	int st = min(jt, dt);
	int diff = abs(jt - dt);
	if (jt < dt) {
		int nokoriIntern = k - diff - jt % 2;
		int minus = ceil((float)nokoriIntern / 3);
		printf("%d\n", st - minus);
	}
	else if (jt > dt) {
		int nokoriIntern = k - diff * 2 - jt % 2;
		int minus = ceil((float)nokoriIntern / 3);
		printf("%d\n", st - minus);
	}
	else {
		int nokoriIntern = k - jt % 2;
		int minus = ceil((float)nokoriIntern / 3);
		printf("%d\n", st - minus);
	}
	return 0;
}