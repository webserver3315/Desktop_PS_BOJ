#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX (int)2e5+1
using namespace std;

/*
1부터 n까지의 몬스터가 줄서있다.
i번 몬스터는 hi의 체력을 가진다.
나는 a의 공격력을 가진다.
다른 플레이어(?)는 b의 공격력을 가진다.

나와 상대는 이 몬스터를 다구리한다.
체력이 0 또는 음수가 되면 몬스터는 죽는다.

내가 몬스터 막타칠때마다 1포인트를 얻는다.
상대가 몬스터 막타치면 포인트 못얻는다.
공격은 내가 먼저, 상대방이 두 번째로 진행된다.
너는 최대 k번만큼 상대방의 공격을 훼방놓을 수 있다.

훼방을 최대한 적절하게 놓아서 뽑을 수 있는 최대경험치를 구하라.
*/

int t;
int n, a, b, k;
int MonHealth[MAX];

int floatdiv(int a, int b) {
	if (a % b == 0)
		return a / b;
	if (a % b != 0)
		return (a / b) + 1;
}

int main() {
	//cin >> t;
	t = 1;
	while (t--) {
		cin >> n >> a >> b >> k;
		int cnt = 0;
		vector<int> nokoriHP;
		for (int i = 0; i < n; i++) {
			cin >> MonHealth[i];
			MonHealth[i] %= (a + b);
			if (MonHealth[i] == 0)
				MonHealth[i] = a + b;
			if (MonHealth[i] <= a) {
				cnt++;
			}
			else {
				nokoriHP.push_back(MonHealth[i]);
			}
		}
		sort(nokoriHP.begin(), nokoriHP.end());
		for (int i = 0; i < nokoriHP.size(); i++) {
			int nowMon = nokoriHP[i] - a;
			if (k >= floatdiv(nowMon , a)) {//훼방스킬이 남아있다면
				k -= floatdiv(nowMon , a);
				cnt++;
			}
			else
				break;
		}
		cout << cnt << endl;
	}
	return 0;
}