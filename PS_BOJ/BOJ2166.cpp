#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
#define MAX 10001
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

/*
다각형의 면적
convex hull 임이 보장되어있으므로, 그냥 계속 외적때려도 문제없다.
사실, convex hull 아니어도 상관없는게, 부호가 음수인 삼각형은 다각형 바깥쪽 넓이를 빼주는 역할을 하기에
결과적으로 동일한 값이 나온다.
참조: https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-2166-%EB%8B%A4%EA%B0%81%ED%98%95%EC%9D%98-%EB%A9%B4%EC%A0%81
참조: https://kklyoon.tistory.com/223
*/

int N;
int result;
pii pts[MAX];

int ccw(pii a, pii b, pii c) {
	int x1 = a.ff; int y1 = a.ss;
	int x2 = b.ff; int y2 = b.ss;
	int x3 = c.ff; int y3 = c.ss;
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pts[i].ff >> pts[i].ss;
	}

	for (int i = 2; i <= N - 1; i++) {
		result += ccw(pts[1], pts[i], pts[i + 1]);
	}
	result = abs(result);
	bool oops = false;//0.5있는지
	if (result % 2) oops = true;
	result /= 2;
	cout << result;
	if (oops) cout << ".5" << endl;
	else cout << ".0" << endl;

	return 0;
}