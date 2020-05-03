/*
공유기 설치

각 간격을 기준으로 일일이 확인하는 것이 아닌 이분 탐색의 방식을 이용하는 것이다.

"공유기의 수를 키로 삼을 수 있겠군"

	특정 간격을 기준으로 가능한 위치에 공유기를 설치한다.
	설치한 후에는 다음과 판단한다.
	공유기 수가 더 설치되어야 한다면, 간격을 줄인다.
	공유기 수를 줄여야한다면, 간격을 늘린다.



출처: https://mygumi.tistory.com/301 [마이구미의 HelloWorld]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ld, rd, md;//최저간격, 최대간격, 현재유지중인간격
int N, C;
int RouterNum;

vector<int> housePosition;

void psearch() {
	while (RouterNum != C) {

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		housePosition.push_back(tmp);
	}
	sort(housePosition.begin(), housePosition.end());

	ld = 1; rd = housePosition.back() - housePosition.front(); /*md = (ld + rd) / C;*/


	psearch();

	return 0;
}