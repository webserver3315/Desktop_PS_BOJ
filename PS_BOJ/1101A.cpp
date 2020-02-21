/*
a,b의 수를 준다.
0인덱스는 흰색, 흰색인 인덱스로부터 a 또는 b를 더한 인덱스 또한 흰색.
그런식으로 계속 나아갈 때

만약 3 5이면
0 3 5 6 8 9(여기서 8이 배수가 답이 아니라는 방증이 됨)...
이렇게 흰칠된다.

일단 간단하게 2 3 박아보자.
0 2 3 4 5 6 8 9 10 12

테스트케이스는 100개 이하로 주어지고, a와 b는 각각 1000 이하의 자연수이다. 즉 케이스당 실질적인 연산은 10의 6승 내로 끝내야 한다.
하지만 이는 a*b까지 가기도 벅차다. 수학적 해법이 절실하다.

만일 전부 흰색이 칠해진다면, 그 것은 finite이다. 그 외의 모든 경우는 infinite이다.

왜 7 3이 infinite이지? 서로소라서 그런가?
0 3 6 7 9 10 12 14 15 18 21 27 28 30 33 36

x 이상의 모든 수에 대해 x-7*n1-3*n2==0이 성립함을 보이면 된다.
만일 1을 만들 수 있다면 게임 끝이다.
7과 3을 어떻게든 빼고 더해서 그 결과로 1을 만들면 된다. 그리고 그 두 수는 그게 가능하다. 7에서 3 두 번 빼면 1이니까.
하지만 그게 과연 unique한가? 장담할 수 있나?

만일 2를 만들 수 있어도 그게 성립한다고 할 수 있나? 일단 아닐 것이다.
만일 3 11이라면
22-21=1이니까 이것 또한 ㄱㄴ하다. 하지만, 바로 출력은 못한다. 11을 두 배 하는 과정이 있어야 한다.
계산상한선은 최대공배수로써 차이가 0이 될 때 까지로 보면 될 듯 하다.

1초라서 좀 빡세긴한데 공배수 구한 뒤 
13 9773이라면;
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



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();




	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}