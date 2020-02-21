/*
계단 오르기
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

/*한 번에 두 계단씩 오를 수 없으며, 0번계단에서 출발해 마지막 계단은 반드시 밟아야 한다.
처음을 제외하고는 두 번 연속 하나씩은 오를 수 없다. 엄밀히는 연속된 세 개의 계단을 밟는게 금지다.
가능한 총점의 최댓값은?
계단은 300개이하, 점수는 각각 10000이하.

점화식 - An = Max(A(n-2),A(n-3)+arr[n-1])+arr[n]
*/


/*최적부분문제가 성립하는가? 
*/

/*애초에 3계단 단위로 이동하는걸 기본단위로 삼으면 되잖은가. 2계단씩 연속으로 이동하는 경우는 절대 없으니.
4번째칸 그렇게 갈 바에야 1칸 2칸 1칸 움직이는게 반드시 유리하기에.
따라서, 일단 기본적으로 번갈아 이동하되, 
소대중중
소중대소
소소대소
소소소대
대소소소
소대소소
소소대소대대
소소소대대소대

해당 아이디어를 기점으로 점화식 찾았다.
An = Max( A(n-2), A(n-3)+arr[n-1] ) + arr[n]
*/

int arr[303];//계단별 점수
int memo[303];
int s;//stair

int DP(int n) {
	if (n <= 0)
		return 0;
	else if (n < 3)
		return memo[n];
	else
		if (!memo[n]) //memo가 안되어있다면
			memo[n] = max(DP(n - 2), DP(n - 3) + arr[n - 1]) + arr[n];
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> s;
	for (int i = 1; i <= s; i++) {
		cin >> arr[i];
	}
	memo[1] = arr[1];
	memo[2] = arr[1] + arr[2];

	cout << DP(s) << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}