#include <iostream>
#include <vector>
using namespace std;

/*
n개의 음이 아닌 정수배열을 받는다.
오르막/내리막 형태면 sharpened이다.
equal은 인정하지 않는다.
오르막 생략하고 내리막 가도 상관없다. 단, 이 경우 바로 내리막만 허용된다.
즉, 오르막모드에서 내리막모드로 일방통행으로써 전환이 단 한번만 허용된다.


*/

int t;
int n;
bool Decreasing;
vector<int> ivct;

void Initialize() {
	n = 0;
	Decreasing = false;
	ivct.clear();
	return;
}

/*
0203.02:32
간과한 부분 찾았다.
110
111
112
113
가 전부 No로 나오는데 정답은 Yes이다.

나는 0번째 수를 깎음으로써 오르막을 성사시킬 경우가 존재한다는 점을 간과했다.
1번째 수만 깎을 수 있는게 아니라, 내리막길이 아니라 오르막길의 경우 도리어 우측이 아니라 좌측의 원소를 깎는게 맞다.
*/
bool CanBeSharp() {
	if (n == 1) {
		return true;
	}
	for (int i = 1; i < n; i++) {
		if (ivct[i - 1] < ivct[i]) {//올라가는 중이면
			if(!Decreasing)//애초에 등산모드였다면 상관없으나
				continue;
			else {//하산모드였는데 올라가거나 유지중이라면 문제다. 깎아서라도 내려가야만 한다.
				ivct[i] = ivct[i - 1] - 1;//당장은 괜찮을지 몰라도, 최대한 천천히 미끄러질 때조차 0에 2 번 닿이게 된다면 ㅈㅈ이다.
				if (ivct[i] <= 0) {//하산도중 0에 닿였다면
					if (ivct[i] == 0)//1번은 용서한다
						continue;
					//2번은 용서안한다
					else
						return false;
				}
			}
		}
		else {//내려가거나 동일한 중이면
			Decreasing = true;
			if (ivct[i - 1] == ivct[i]) {//동등하다면
				ivct[i] = ivct[i - 1] - 1;//우측을 깎는다. ////여기서, 잘못되었다. 무작정 우측만 깎으면 답 안나올 경우가 존재한다.
				if (ivct[i] <= 0) {//하산도중 0에 닿였다면
					if (ivct[i] == 0)//1번은 용서한다
						continue;
					//2번은 용서안한다
					else
						return false;
				}
			}
			else {//순탄한 내리막이면 볼 것도 없다.
				//if (ivct[i] > 0)
				//	continue;
				//if (ivct[i] <= 0) {//하산도중 0에 닿였다면
				//	if (ivct[i] == 0)//1번은 용서한다
				//		continue;
				//	//2번은 용서안한다
				//	else
				//		return false;
				//}
				continue;
			}
		}
	}
	return true;
}

void solve() {
	Initialize();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ivct.push_back(tmp);
	}

	bool ans = CanBeSharp();
	if (ans == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}