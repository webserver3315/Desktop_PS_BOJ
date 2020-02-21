#include <iostream>
#include <cmath>
#define MAX (int)1e5+1
using namespace std;

int memo[MAX];
int n;

/*
DFS로 n!번 전수조사하는 것 외에는 아무 방안이 없다고 느꼈다.
그러나, 어차피 최적해는 해당 수 자체가 제곱수이거나, 그 외의 모든 경우에는
반드시 이전 데이터로부터 답을 도출할 수 있음이 자명하므로
DP로 풀 수 있다는 사실을 풀이를 보고 깨달았다.

DP의 발상조건: "이전 데이터로부터 현재 데이터가 도출가능한가? 즉, 이전데이터가 현재의 답을 구하는데 쓸모있는가?"

참고:https://wootool.tistory.com/102
*/

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (memo[i] > memo[i - j * j] + 1 || memo[i] == 0) {
				memo[i] = memo[i - j * j] + 1;
			}
		}
	}

	cout << memo[n] << endl;

	return 0;
}