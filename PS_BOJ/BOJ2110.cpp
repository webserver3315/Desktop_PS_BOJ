/*
������ ��ġ
*/

#include <iostream>
#include <vector>
#include <algorithm>

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
	sort(houseposition.begin(), houseposition.end());//20���� ���̸� sort�ϴ� �͵� ���������� �ʴٸ�;
	
	/*rh = houseposition.back();
	mid = (lh + rh) / 2;*/

	//for (int i = 0; i < houseposition.size() - 1; i++) {
	//	int diff = houseposition[i + 1] - houseposition[i];
	//	if (lh > diff)
	//		lh = diff;
	//}//�ּҰŸ����� lh�� ����
	//rh = houseposition.back() - houseposition.front();//�ִ�Ÿ����� rh�� ����

	/*�ƴ� �׳� ������ �Ÿ��� �迭�� �����ұ�.*/
	for (int i = 0; i < houseposition.size() - 1; i++) {
		int diff = houseposition[i + 1] - houseposition[i];
		distance_house.push_back(diff);
	}
	rp = distance_house.size() - 1;
	mp = (lp + rp) / C;
	psearch();

	return 0;
}