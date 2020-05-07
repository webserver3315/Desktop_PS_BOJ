/*
Perfect Team
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int q, cnt;
int c, m, x;

int Min(int a, int b) {
	return a >= b ? b : a;
}
int Max(int a, int b) {
	return a <= b ? b : a;
}

int Max_Team() {
	if (c >= 1 && m >= 1 && x >= 1) {
		int Ichidan_Team = Min(Min(c, m), x);
		c -= Ichidan_Team, m -= Ichidan_Team, x -= Ichidan_Team;
		cnt += Ichidan_Team;
		Max_Team();
	}
	else if (c >= 1 && m >= 1 && x == 0) {
		if (Min(c, m) * 2 <= Max(c, m)) {
			cnt += Min(c, m);
			return 0;
		}
	}
	else if (c < 1 || m < 1) {/*코더나 수학자 두 분야중 1명이라도 인원이 없다면*/
		return 0;
	}
	else {
		if (x > 0) {/*비전공자가 남아있다면, 걔부터 소모한다.*/
			--c, --m, --x, ++cnt;
			Max_Team();
		}
		else {/*비전공자 전멸*/
			--c, --m;
			if (c > 0 && c >= m) {
				--c, cnt++;
				Max_Team();
			}
			else if (m > 0 && m >= c) {
				--m, cnt++;
				Max_Team();
			}
			else {
				return 0;
			}
		}
	}
}

int main() {
	cin >> q;
	while (q--) {
		cnt = 0;
		scanf("%d %d %d", &c, & m, &x);
		Max_Team();
		printf("%d\n", cnt);
	}
	return 0;
}