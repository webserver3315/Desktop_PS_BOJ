/*���ָ��ø鼭 �ɾ��*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct Convini {
	int x;
	int y;
	bool visit;
};

vector<Convini> ConviniVct;
pair<int, int> start, end;
int t, n;

int Distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

bool BeerJubunn(int x1, int y1, int x2, int y2) {/*��ǥ�� ���� 1000 ���ϸ� �����ϹǷ� ��, �ƴϸ� �������̹Ƿ� ���� ����*/
	if (1000 >= abs(x1 - x2) + abs(y1 - y2))
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	
	cin >> t;
	while (t--) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		start.first = tmp1;
		start.second = tmp2;
		for (int i = 0; i < n; i++) {
			cin >> tmp1 >> tmp2;
			ConviniVct.push_back(Convini(tmp1, tmp2, false));
		}

	}

}