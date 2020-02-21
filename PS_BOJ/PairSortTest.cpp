/*
아기상어
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define MAX 21
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> pii;

/*
물고기 크기를 키로 하여 우선순위큐를 만들면 조금 더 빨라질지 모르겠으나, 일단 naive하게 풀어보자.
케이스 나눌 필요도 없이 이건 딱 정해진 규칙대로 움직이게끔만 하면 된다.
*/
int N;
int field[MAX][MAX];
int sec;
int ssize = 2;//상어크기
int eatcnt;
int sr, sc;//상어위치

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pii> testvct;
	testvct.push_back({ 1,2 });
	testvct.push_back({ 2,3 });
	testvct.push_back({ 2,4 });
	testvct.push_back({ 1,3 });
	testvct.push_back({ 2,5 });
	testvct.push_back({ 3,1 });
	testvct.push_back({ 3,2 });
	sort(testvct.begin(), testvct.end());

	for (auto tmp : testvct) {
		cout << tmp.ff << ' ' << tmp.ss << endl;
	}

	return 0;
}