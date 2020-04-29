#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int gcd(int a, int b, int* x, int* y) {
	int x1, y1;
	int g;
	if (b > a) return gcd(b, a, y, x);
	if (b == 0) {
		*x = 1; *y = 0;
		return a;
	}
	g = gcd(b, a % b, &x1, &y1);
	*x = y1;
	*y = (x1 - floor(a / b) * y1);
	return g;
}

int gcdextend(int a, int b, int* x, int* y) {
	if (b > a) return gcdextend(b, a, y, x);
	if (a == 0) {
		*x = 0; *y = 1;
		return b;
	}
	int x1, y1;
	int g = gcdextend(b % a, a, &x1, &y1);
	*x = y1 - (b - a) * x1;
	*y = x1;
	return g;
}

//최대공약수를 구하고, ax + by 가 최대공약수가 되도록 만족하는 x와 y를 출력하는 문제인데, x<=y는 무시해도 된다.
//x의 절댓값과 y의 절댓값의 합이 최소가 되도록 만들면 된다.
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y;
	int a, b;
	cin >> a >> b;
	//int g = gcdextend(a, b, &x, &y);
	int g = gcd(a, b, &x, &y);
	cout << x << " " << y << " " << g << endl;

	return 0;
}