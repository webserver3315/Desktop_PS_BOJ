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
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�
//#define mp(x,y) make_pair(x,y)//���ι���

using namespace std;

/*�������� �¿�� �����ϰ� �����Ǿ��ִ�.
���� ���� ������ ��� ���뿡�� ������, �� �Ǵ� �� â���� ������ �� �ش� ������ ���� ��� 2�̻��� �̰ݰŸ��� Ȯ���Ǹ� �������� Ȯ���ȴٰ� ���Ѵ�.
���� ������ �־��� ��, �׸��� �� ���� 1������ �� �� �������� Ȯ���� ������ ���� ���϶�.
������ ���� 1000 ����, �� ������ ���̴� �ִ� 255�̸� �� ���� 2ĭ�� �� ������ 2ĭ���� �ǹ��� �������� �ʴ´�.

*/

/*�׽�Ʈ���̽� ���� T, #���� Ʈ��ŷ�ϴ°� ��������
�� T������ ���α��̸� N�̶�� ����
idx�� 0���� N-1���� ��ȸ��Ű��
�ش� ������ �������� 0(==�ٴ�)�� �� �� ���� ����. ��Ȯ���� [height[idx],0) ���̱����� ��Ī�Ѵ�.
�� ������ ����, 

�ƴϸ� �¿� ���� �������� Ȯ���Ǵ� Max ���̸� ���ϴ� �Լ��� ������ �� ���� �� ���ϰ��� �̿��ϴ� �͵� �����ϴ�.


*/

int T;

int SightMaginot(int idx, int yoko, vector<int>& buildings) {/*��1��2ĭ, ��1��2ĭ�� ������ �� �ִ밡�ü�Ȯ�� ��������̸� ���Ѵ�.*/
	/*�ٹ� 2ĭ �̳����� ���� ū ������ ���̸� ���Ѵ�. �� ���� �����뼱�̴�.*/
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