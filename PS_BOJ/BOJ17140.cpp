/*
이차원배열의 연산
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
#include <ctime>
#include <climits>
#define endl '\n'
//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

using namespace std;


/*배열에 대해서 행할 수 있는 연산은 2가지가 있다. R과 C 연산이다.
R연산은 모든 ROW에 대해 정렬을 수행한다. R의 갯수가 C의 갯수보다 같거나 커야만 적용된다.
C연산은 모든 COLUMN에 대해 정렬을 수행한다. C의 갯수가 R의 갯수보다 커야 적용된다.

정렬결과를 배열에 넣을때는 수와 등장횟수를 모두 넣고, 순서는 수가 먼저나옴. 수-등장횟수 순서가 유지.
예를 들어, 3,1,1에는 3이 1번, 1이 2번 등장. 따라서 정렬은 3,1,1,2 가 된다.
이걸 또 정렬하면 3이 1번 1이 2번 2가 1번이므로 3,1,1,2,2,1 이 된다. 아니, 근데 왜 2,1,3,1,1,2가 되는건가?
정렬기준은 다음과 같다.

제1기준: 수의 등장횟수를 오름차순으로
제2기준: 제1기준이 동일하다면, 수 자체를 오름차순으로

정렬된 결과를 배열에 다시 넣으면 R이나 C의 크기가 커질 수 있다. R연산의 경우 R이 커지고, C 연산의 경우 C가 커진다.
커진 곳에는 0이 채워진다. 수를 정렬할 때 0은 무시한다.
예를 들어, 3,2,0,0 을 정렬한 결과는 3,2 를 정렬한 결과와 동일하다.

R이나 C의 크기가 100을 넘어가면 처음 100개를 제외한 나머지를 버린다.
배열 A에 들어있는 수와 r,c,k가 주어졌을 때 A[r][c] 에 들어있는 값이 k가 되기 위한 최소시간을 구하라.
*/

/*문제 이해하는데만 20분 넘게 걸렸다...
일단 점점 늘어나는 정렬문제다.
100초까지 돌리되, 100초 타임오버되면 
특이하게 행/열 최대제한인 100줄을 오버하면 기존 것을 삭제하는게 아니라, 기존 것을 유지하고 새로운 인풋을 씹는 듯 하다.
그래도 일단 100초돌릴때까지 하는게 편하다. 그래도 알아서 터질테니까.

이 문제를 나눠보자.
1. 비교함수 제작
2. 비교함수를 이용해서 정렬하는, R 및 C 연산을 각각 구현한 함수 제작
3. 100번 상한으로 R 및 C 연산을 반복시키는 함수 제작

제일 중요한 뼈대가 될 자료구조선택을 어떻게 하느냐...
행과 열의 최대크기가 100이라고 상한되어있으니 그냥 100*100 배열 선언도 나쁘진 않다. 배열 상위호환인 벡터를 쓸까... 아니다. 그래도 배열이 편할 듯 하다.
비교함수 만드는 것은 어떻게 할까. 일단 true, false 로 리턴시키면 그렇게 큰 문제는 아닐 것이다. sort stl에서 비교함수 항을 이용하면 일단 편할 것이다.

*/

int gr, gc, gk;//global r, c, k
int R = 3; int C = 3;
int Table[102][102];//문제편의상 0row0column은 버린다

bool IsPriorThan(int num1, int num1Kazu, int num2, int num2Kazu) {/*전자가 우선이면 true, 아니면 false 반환. 완전히 동일할 리는 없으니 == 반환 경우는 고려할 필요가 없다.*/
	if (num1Kazu > num2Kazu)
		return false;
	else if (num1Kazu == num2Kazu) {
		return num1 > num2 ? false : true;
	}
	else
		return true;
}

void R_Function() {

}

void C_Function() {

}

int Solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> gr >> gc >> gk;
	for (int r = 1; r <= 3; r++) {
		for (int c = 1; c <= 3; c++) {
			cin >> Table[r][c];
		}
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}