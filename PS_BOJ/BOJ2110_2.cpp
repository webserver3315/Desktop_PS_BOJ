/*
공유기 설치
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200005
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
bool routerExist[MAX];

void psearch() {
	while (lp < rp) {

	}
}

int minRouterDist() {
	int minDist = INT_MAX;
	for (int i = 0; i < N-1; i++) {
		if (routerExist[i]) {
			for (int j = i + 1; j < N; j++) {
				if (routerExist[j]) {
					if (minDist > houseposition[j] - houseposition[i]) {
						minDist = houseposition[j] - houseposition[i];
						break;
					}
				}
			}
		}
	}
	return minDist;
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

	/*이 문제가 관심있는 것은 오로지 최인접공유기간의 거리이다. 그 최인접공유기간거리의 최댓값을 PSEARCH연산으로 구하면 된다.*/

	

	return 0;
}