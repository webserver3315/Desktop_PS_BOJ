/*
n을 양의 정수라고 하자. a,b,c를 음이 아닌 정수라고 하며 그들의 합은 n이다.
가위바위보를 갑과 을이 하는데 갑은 a b c 갯수대로 묵찌빠를 가지고 있다.
갑과 을이 이긴 횟수대로 승패를 가른다. 만일 동점이라면 갑의 패배로 간주한다.
최대 100판하며, 앨리스의 패 또한 100판 이내이다. 반드시 판의 수와 패의 수는 일치한다.


테케는 100번 이하. 1초니까 사실상 10의 6승내로 해결봐야함.
테케가 주어지고 판의 횟수 및 묵찌빠의 개수가 주어짐.
마지막 줄에는 을이 내는 순서가 공백없이 주어짐.
만일 앨리스가 가망이 있다면, YES, 절대 못이긴다면 No 를 출력하라.
YES일 경우, 앨리스가 이길 수 있는 경우를 설명하라.
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
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용


/*일단 을이 내는 경우는 string으로 받고, R C P의 수를 각각 카운팅해야한다.
갑이 패배한 횟수가 과반수가 되는 순간 더 볼 것도 없이 갑의 패배다.
일단 만나는 족족 최대한 이기는 방향으로 소모한다. 더 이상 대응패가 없다면 그판내준다.
내준 판의 수가 과반수가 되면 갑의 패배다.
*/

int T;
int n, r, p, s, br, bp, bs, orr , orp, ors;

bool IsAliceWin(string& bob) {
	br = 0; bp = 0; bs = 0;//밥
	for (char ch : bob) {
		if (ch == 'R')
			br++;
		else if (ch == 'P')
			bp++;
		else if (ch == 'S')
			bs++;
	}
	int win_p = min(br, p); int win_s = min(bp, s); int win_r = min(bs, r);//이긴 최대횟수
	r -= win_r; s -= win_s; p -= win_p;
	br -= win_p; bs -= win_r; bp -= win_s;
	if (win_p + win_s + win_r > n / 2)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//std::cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	while (T--) {
		if (T == 0) {
			int tmp;
			tmp = 1;
			cout << tmp;
			tmp += 1;
		}
		string bob;
		cin >> n;
		cin >> r >> p >> s;
		orr = r; orp = p; ors = s;
		cin >> bob;
		if (!IsAliceWin(bob)) {
			std::cout << "NO" << endl;
			continue;//하 시발 여기서 리턴제로를 박아버리냐 ㅅㅂ련아
		}
		std::cout << "YES" << endl;
		for (char ch : bob) {
			if (ch == 'R') {
				if (p >= 0) {
					std::cout << "P";
					p--;
				}
				else if (r < s) {
					std::cout << "S";
				}
				else {
					std::cout << "R";
				}
			}
			else if (ch == 'P') {
				if (s >= 0) {
					std::cout << "S";
					s--;
				}
				else if (p < r) {
					std::cout << "R";
				}
				else {
					std::cout << "P";
				}
			}
			else if (ch == 'S') {
				if (r >= 0) {
					std::cout << "R";
					r--;
				}
				else if (s < p) {
					std::cout << "P";
				}
				else {
					std::cout << "S";
				}
			}
		}
		std::cout << endl;
	}
	/*
	R 10 P 1 S 10
	RRPPPPPPPPPSSSSSSSSSS
	*/

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//std::cout << ctime_duration << " ms" << endl;
	return 0;
}