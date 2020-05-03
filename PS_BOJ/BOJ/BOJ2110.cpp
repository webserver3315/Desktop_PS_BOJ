/*
공유기 설치
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*집 좌표가 최대 10의 9승이다. 일단은 int로 커버될것같은데 에러뜨면 longlong 염두하자
집의 개수는 2개이상 20만 이하. 공유기는 당연하지만 2개 이상 집개수 이하.
좌표는 1부터 시작이다.

가장 인접한 공유기의 거리를 최대로 하는 프로그램을 작성하고, 그 때의 최인접공유기간의 거리를 출력하라.
*/


vector<int> houseposition;
vector<int> distance_house;
//int lh = INT_MAX, rh, mid;
int N, C;
int lp, rp, mp;//left point, right point, mid point

void psearch() {
	while (lp < rp) {

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		houseposition.push_back(tmp);
	}
	sort(houseposition.begin(), houseposition.end());//20만의 길이를 sort하는 것도 저렴하지는 않다만;
	
	/*rh = houseposition.back();
	mid = (lh + rh) / 2;*/

	//for (int i = 0; i < houseposition.size() - 1; i++) {
	//	int diff = houseposition[i + 1] - houseposition[i];
	//	if (lh > diff)
	//		lh = diff;
	//}//최소거리값이 lh에 저장
	//rh = houseposition.back() - houseposition.front();//최대거리값이 rh에 저장

	/*아니 그냥 집간의 거리를 배열로 유지할까.*/
	for (int i = 0; i < houseposition.size() - 1; i++) {
		int diff = houseposition[i + 1] - houseposition[i];
		distance_house.push_back(diff);
	}
	rp = distance_house.size() - 1;
	mp = (lp + rp) / C;
	psearch();

	return 0;
}