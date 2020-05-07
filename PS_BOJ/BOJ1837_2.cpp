#include <iostream>
#define MAX ((int)1e6)+1
using namespace std;

/*
도저히 모순점이 안보여서 정답 봤다.
방법이 문제였던게 아니라, 수단이 문제였는데
내가 간과한 것은, 1e100 의 한계인데 int로 받았다는 것이다.
100승이면, 사실 long long으로도 커버 안되고 string으로 받아야 하는 수준이다.
*/

bool isNotPrime[MAX] = { true,true, };
int t;

void MakeEratos() {
	for (int i = 2; i < MAX; i++) {
		if (isNotPrime[i] == false) {
			int tmp = i;
			while (tmp + i < MAX) {
				tmp += i;
				isNotPrime[tmp] = true;
			}
		}
	}
	return;
}

int StrDivInt(string a, int b) {//string a를 b로 나눠서 int로 출력
	int tmp = 0;
	int idx = 0;
	while (idx < a.length()) {
		while (tmp < b && idx < a.length()) {
			tmp = tmp * 10 + a[idx++] - '0';
		}
		tmp %= b;
	}
	return tmp;
}

int IsGood(string p, int k) {//좋은 소수이면 0 리턴. 나쁜 소수이면 문제의 작은소수 리턴
	for (int i = 2; i < k; i++) {
		if (isNotPrime[i] == true)
			continue;
		else {
			if (StrDivInt(p, i) == 0) {//i가 p의 작은 키소수이면서 k 보다 작으면
				return i;
			}
			else
				continue;
		}
	}
	return 0;
}

void solve(string p, int k) {
	MakeEratos();
	int ans = IsGood(p, k);
	//cout << "ans = " << ans << endl;
	if (ans == 0) {
		cout << "GOOD" << endl;
	}
	else {
		cout << "BAD " << ans << endl;
	}
}

int main() {
	//cin >> t;
	t = 1;
	string p;
	int k;
	while (t--) {
		cin >> p >> k;
		solve(p, k);
	}

	return 0;
}