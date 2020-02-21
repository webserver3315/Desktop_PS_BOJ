/*
���� 1e2��
���ڴ� 1e3��
���μ��� ��ǥ 1e3��, �� ���ڴ� 1e6
*/
#include <iostream>
#include <utility>
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
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
typedef std::pair <int, int> pii;
#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

vector<pii> boxZahyo;
int t;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		boxZahyo.clear();
		int n;
		cin >> n;

		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			pii tmppii = mp(x, y);
			boxZahyo.push_back(tmppii);
		}
		
		/*
		�ް��ϸ� ��ġ�� ������.
		�׷��� ���� �� ���� �ڽ� ������ �����ڸԱ�� �÷�����.
		�׷���, �ö��� �� �Ʒ����� �ڽ� ������ ����.
		��, �������������� ���� ��
		1,2 1,3 3,3 4,3 5,5
		0,1 1,0
		4,3
		�̷��� ���� �� y��ǥ ���� �ڿ����� �񳻸������� �Ǿ�� ��.
		*/
		sort(boxZahyo.begin(), boxZahyo.end());
		bool Kanou = true;
		for (int i = 1; i < n; i++) {
			if (boxZahyo[i - 1].ss > boxZahyo[i].ss) {
				Kanou = false;
			}
		}

		if (!Kanou) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		string kotae;
		int nowx = 0; int nowy = 0;
		for (int i = 0; i < n;) {//�ڽ� �ֿ췯 ������
			int xx = boxZahyo[i].ff; int yy = boxZahyo[i].ss;
			if (nowx < xx) {
				kotae.append("R");
				nowx++;
			}
			else if (nowy < yy) {
				kotae.append("U");
				nowy++;
			}
			else if (nowx == xx && nowy == yy) {//��������, nowx==xx�̰� nowy==yy�� ��
				i++;
			}
			else {
				cout << "ERROR" << endl;
				break;
			}
		}
		cout << kotae << endl;
	}



	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}