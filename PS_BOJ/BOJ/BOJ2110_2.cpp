/*
������ ��ġ
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200005
using namespace std;

/*�� ��ǥ�� �ִ� 10�� 9���̴�. �ϴ��� int�� Ŀ���ɰͰ����� �����߸� longlong ��������
���� ������ 2���̻� 20�� ����. ������� �翬������ 2�� �̻� ������ ����.
��ǥ�� 1���� �����̴�.

���� ������ �������� �Ÿ��� �ִ�� �ϴ� ���α׷��� �ۼ��ϰ�, �� ���� �����������Ⱓ�� �Ÿ��� ����϶�.
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
	sort(houseposition.begin(), houseposition.end());//20���� ���̸� sort�ϴ� �͵� ���������� �ʴٸ�;

	/*�� ������ �����ִ� ���� ������ �����������Ⱓ�� �Ÿ��̴�. �� �����������Ⱓ�Ÿ��� �ִ��� PSEARCH�������� ���ϸ� �ȴ�.*/

	

	return 0;
}