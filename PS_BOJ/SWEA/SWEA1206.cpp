/*
View
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

/*빌딩들은 좌우로 빽빽하게 밀집되어있다.
강에 대한 조망은 모든 세대에서 좋지만, 좌 또는 우 창문을 열었을 때 해당 층에서 양쪽 모두 2이상의 이격거리가 확보되면 조망권이 확보된다고 말한다.
여러 빌딩이 주어질 때, 그리고 각 층을 1세대라고 할 때 조망권이 확보된 세대의 수를 구하라.
빌딩의 수는 1000 이하, 각 빌딩의 높이는 최대 255이며 맨 왼쪽 2칸과 맨 오른쪽 2칸에는 건물이 지어지지 않는다.

*/

/*테스트케이스 수를 T, #으로 트래킹하는거 잊지말고
각 T마다의 가로길이를 N이라고 하자
idx를 0부터 N-1까지 순회시키고
해당 빌딩의 꼭대기부터 0(==바닥)이 될 때 까지 ㄱㄱ. 정확히는 [height[idx],0) 높이구간을 서칭한다.
각 층수에 대해, 

아니면 좌우 전부 조망권이 확보되는 Max 높이를 구하는 함수를 제작한 뒤 그저 그 리턴값을 이용하는 것도 가능하다.


*/

int T;

int SightMaginot(int idx, int yoko, vector<int>& buildings) {/*좌1및2칸, 우1및2칸이 존재할 시 최대가시선확보 마지노높이를 구한다.*/
	/*근방 2칸 이내에서 가장 큰 빌딩의 높이를 구한다. 그 것이 마지노선이다.*/
	int MaginotHeight = 0;
	if (idx - 2 >= 0) {
		if (MaginotHeight < buildings[idx - 2])
			MaginotHeight = buildings[idx - 2];
	}
	if (idx - 1 >= 0) {
		if (MaginotHeight < buildings[idx - 1])
			MaginotHeight = buildings[idx - 1];
	}
	if (idx + 1 < yoko) {
		if (MaginotHeight < buildings[idx + 1])
			MaginotHeight = buildings[idx + 1];
	}
	if (idx + 2 < yoko) {
		if (MaginotHeight < buildings[idx + 2])
			MaginotHeight = buildings[idx + 2];
	}
	
	int returnval = buildings[idx] - MaginotHeight;
	if (returnval < 0)
		returnval = 0;

	return returnval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	for (int i = 0; i < 10; i++) {
		int yoko;
		int cnt = 0;
		vector<int> buildings;
		buildings.reserve(1000);
		cin >> yoko;
		for (int i = 0; i < yoko; i++) {
			int tmp;
			cin >> tmp;
			buildings.push_back(tmp);
		}
		
		for (int idx = 0; idx < yoko; idx++) {
			cnt += SightMaginot(idx, yoko, buildings);
		}
		cout << "#" << i + 1 << ' ' << cnt << endl;
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}