/*
피보나치 수열
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
#define ff first
#define ss second
typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용


/*피보나치 수열에서, 재귀적으로 함수를 호출할 시 결국 fibo(1), fibo(0) 을 호출하게 된다.
fibo(N)을 호출했을 때, 1과 0 인자의 함수가 몇 번 각각 호출되는지를 구하시오

시간이 부족하다. 0.25초만 주어진다.

첫 줄에 테스트케이스의 갯수 T가 주어진다
각 케이스는 한 줄로 이루어지고 40보다 작은 N이 인수로 주어진다.
*/

int T, N;
int ZeroKazu, OneKazu;//호출횟수
vector<pii> Memoization(42);//idx 인풋 시 0, 1의 호출횟수 유지. (42) 은 reserve(42)과 동일하다. 즉, ㄹㅇ로 넣는게 아니라 할당만 해놓는거다. 혹시 에러뜰듯해서 일단 일반배열로 해보고 이건 마루타로 하자.
bool visited[42];
int MemoizationFibo[42];
//pii Memoization[42];

/*몇 번 호출되는지 기록을 하는 편이 좋을 것이다.
pii로 선언해서 첫 인자는 해당 인풋시의 ZeroKazu, ss는 OneKazu를 유지하도록.

*/

int fibo(int n) {
	if (n == 0) {
		ZeroKazu++;
		return 0;
	}
	else if (n == 1) {
		OneKazu++;
		return 1;
	}
	else {
		if (visited[n] == true) {
			return MemoizationFibo[n];
		}
		else {//처음가본곳이면
			MemoizationFibo[n] = fibo(n - 1) + fibo(n - 2);
			Memoization[n].ff = Memoization[n - 1].ff + Memoization[n - 2].ff;
			Memoization[n].ss = Memoization[n - 1].ss + Memoization[n - 2].ss;
			visited[n] = true;
			return MemoizationFibo[n];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	
	

	cin >> T;

	Memoization[0].ff = 1; Memoization[0].ss = 0; visited[0] = true;
	Memoization[1].ff = 0; Memoization[1].ss = 1; visited[1] = true;

	while (T--) {
		ZeroKazu = 0; OneKazu = 0;
		cin >> N;
		if (visited[N] == true) {/*이부분을 fibo 내에 넣을 수 있다면 훨씬 빨라지지 않을까하는 아쉬움이 있다.*/
			cout << Memoization[N].ff << ' ' << Memoization[N].ss << endl;
		}
		else {
			fibo(N);
			cout << Memoization[N].ff << ' ' << Memoization[N].ss << endl;
		}
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}