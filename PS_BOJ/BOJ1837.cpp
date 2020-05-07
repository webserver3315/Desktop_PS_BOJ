#include <iostream>
#define MAX ((int)1e6)+1
using namespace std;

/*
정답 봤다.
내가 간과한 것은, 1e100 의 한계인데 int로 받았다는 것이다.
100승이면, 사실 long long으로도 커버 안되고 string으로 받아야 하는 수준이다.
*/

bool isNotPrime[MAX] = { true,true, };
int t;

void MakeEratos() {
	for (int i = 2; i < MAX; i++) {
		if (isNotPrime[i] == false){
			int tmp = i;
			while (tmp + i < MAX) {
				tmp += i;
				isNotPrime[tmp] = true;
			}
		}
	}
	return;
}

int IsGood(int p, int k) {//좋은 소수이면 0 리턴. 나쁜 소수이면 문제의 작은소수 리턴
	for (int i = 2; i < k; i++) {
		if (isNotPrime[i] == true)
			continue;
		else {
			if (p % i == 0) {//i가 p의 작은 키소수이면서 k 보다 작으면
				return i;
			}
			else
				continue;
		}
	}
	return 0;
}

void solve(int p, int k) {
	MakeEratos();
	int ans = IsGood(p, k);
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
	int p, k;
	while (t--) {
		cin >> p >> k;
		solve(p, k);
	}

	return 0;
}