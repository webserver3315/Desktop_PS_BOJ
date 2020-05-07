/*
즉, a-b 의 절댓값이 정확히 x, 또는 x의 홀수배 배수가 되도록 만들 수 있는가?
양 변을 3x씩 빼는 것은 가능하다

이거 유일한 조건이 혹시 동일인가?

일단 아니라는 가정 하에 생각해보자.

일단 a b 두 수가 2배이상 차이나면 절대 동시에 못되돌린다. 둘중하나가 먼저 음수에 도달하기 대문.
일단 둘 모두 1이면 리타이어다.

둘 모두 1이 아니면서 차이도 2배거나 2배를 넘지 않는데 동시도달불가능할 수가 있나?

2 3
1 1

1 2
2 1
둘 중 하나에 도달해야함

2배를 넘지 않으면서 1이 아닌 최소공약수의 배수만큼 차이가 나야 하나?
8 12



*/

#include <iostream>
#define endl '\n'
using namespace std;

int a, b, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (a * 2 < b || b * 2 < a) {
			cout << "NO" << endl;
			continue;
		}
		if (a == 1 && b == 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
}