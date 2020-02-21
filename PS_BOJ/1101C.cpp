/*빌런이 타자기를 손봐서

w를 uu, m을 nn으로 출력하게 만들었다.

내가 편지를 받았는데 뭔 개소린지 모르겠는데, 이게 빌런이 손봐서 그런건지 아니면 송신자가 언어장애인건지 판단이 안섬
판단을 세우기 위해 모든 경우의 수를 종이 1장당 1케이스씩 적을 것임.
얼마나 많은 종이가 필요할까?
종의의 수가 너무 많을 경우를 대비하여, 10의 9승 더하기 7로 나누라.
modx(a+b) == modx (modx(a) + modx(b))

의심할 여지가 없다면 0장이 필요하므로 0을 출력하라.
시간은 1초이며, 편지의 글자수는 10의 5승 이하이다. 오로지 소문자만이 보장된다.


풀기 위해서 중요한 키가 되는 철자는 u와 n의 숫자이다.
참고로, w나 m이 보였다면 그건 절대불가능한 것이므로 바로 0 출력하면 된다. 빌런은 반드시 타자기를 건드렸다.
문제의 포인트는 uuu, nnn처럼 연속된 키철자를 발견할 때 어떻게 처리를 하느냐이다.

없으면 0이다
n은 0이다.
nn은 nn, m 두 가지가 가능하다
nnn은 nnn, nm, mn 세 가지가 가능하다
nnnn은 nnnn, nnm, nmn, mnn, mm 총 다섯가지가 가능하다.
nnnnn은 nnnnn, nnnm, nnmn, nmnn, mnnn, nmm, mnm, mmn 총 여덟가지가 가능하다
이거 피보나치아님?
당연하네, nnn에 m을 삽입하는 경우의 수와 nnnn에 n을 삽입하는 경우의 수(append말하는거다)다.

이렇게 얻은 모든 경우의 수를 각각 곱해주면 된다.
예를들어 nnnannnn이면 3*5=15이다.

그 와중에, m이나 w를 식별하면 당장 폭파시켜야한다.
*/

#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define DIV 1000000007
#define int long long
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

int memo[10005] = { 0,0,2,3 };
int fibo(int n) {
	if (n < 2)
		return 0;
	else if (memo[n])
		return memo[n];
	else {
		memo[n] = (fibo(n - 1) + fibo(n - 2)) % DIV;
		return memo[n];
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	string letter;
	cin >> letter;
	vector<int> cross;

	/*for (int i = 0; i <= 100; i++) {
		cout << fibo(i) << ' ';
	}*/

	int cnt = 0;
	char beforech = 'A';
	/*for (char ch : letter) {
		if (ch == 'w' || ch == 'm') {
			cout << "0" << endl;
			return 0;
		}
		else if (ch == 'u') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if (cnt != 0)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else if (ch == 'n') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if(cnt!=0)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else {
			if (beforech == 'u' || beforech == 'n') {
				if (cnt != 0)
					cross.push_back(fibo(cnt));
				cnt = 0;
				beforech = ch;
				continue;
			}
			beforech = ch;
			continue;
		}
	}*/

	for (int idx = 0; idx <= letter.size(); idx++) {
		char ch = letter[idx];
		if (ch == 'w' || ch == 'm') {
			cout << "0" << endl;
			return 0;
		}
		else if (ch == 'u') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if (cnt != 0 && cnt != 1)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else if (ch == 'n') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if (cnt != 0 && cnt != 1)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else {
			if (beforech == 'u' || beforech == 'n') {
				if (cnt != 0 && cnt != 1)
					cross.push_back(fibo(cnt));
				cnt = 0;
				beforech = ch;
				continue;
			}
			beforech = ch;
			continue;
		}
	}

	int ans = 1;
	for (int tmp : cross) {
		ans *= tmp;
		ans %= DIV;
	}
	cout << ans << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}