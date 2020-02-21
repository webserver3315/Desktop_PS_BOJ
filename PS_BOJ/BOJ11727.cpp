/*
2*N 타일링
*/

#include <iostream>

using namespace std;

/*2*n 직사각형을 2*1, 2*2 사각형으로 채우는 경우의 수를 구하라.
최장직사각형의 가로길이가 주어진다

*/

int N;
int memo[1005] = { 0,1,3,5, };
bool visit[1005] = { false, true, true, true, };
#define DIV 10007

/*최적부분집합의 성질을 가진다. 즉, DP로 풀 수 있다. 점화식을 찾기만 한다면.
가로 N일 때 경우의 수를 fN이라고 할 때
f(n)=f(n-2)*2 + f(n-1) 과 동일하다고 추정된다.
f(1)=1, f(2)=3, f(3)=5, f(4) = 
*/

int DP(int n) {
	if (visit[n]) {
		return memo[n];
	}
	visit[n] = true;
	memo[n] = (DP(n - 1) + DP(n - 2) * 2) % DIV;//10007로 나누는 테크닉 익혀둘 것
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cout << DP(N) << endl;
	return 0;
}