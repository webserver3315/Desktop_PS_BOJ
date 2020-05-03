/*
브루트하게 풀려고 했으나
최대공약수를 이용한 수학적 해법으로 풀어보기로 했다.

이 아이디어는
https://m.blog.naver.com/kyaryunha/221191076960
을 참조했다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int n;
vector<int> arr;
vector<int> diff;

int myabs(int a) {
	if (a < 0)
		return -a;
	return a;
}

int gcd(int a, int b) {//잊지말고 기억해두자.
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < n - 1; i++) {
		int tmp = myabs(arr[i] - arr[i + 1]);
		if (tmp == 0)
			continue;
		diff.push_back(tmp);
	}

	/*
	diff의 모든 원소의 최대공약수를 구하기만 하면 된다.
	*/
	int gcdtmp = gcd(diff[0], diff[1]);
	for (int i = 2; i < diff.size(); i++) {
		gcdtmp = gcd(gcdtmp, diff[i]);
	}
	cout << gcdtmp << endl;

	return 0;
}