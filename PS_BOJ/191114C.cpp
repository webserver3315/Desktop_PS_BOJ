/*

*/
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
//#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define MAX (int)2e5+5
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

/*
�ϴ� ���� 2���� ����. ���� ��迭 ���̰� 2 �̸��̸� �翬�� �Ұ��̹Ƿ� -1 ���
���� 2�� �����̶��(==���ӵ� ���ϼ��� ���ٸ�) ���� 3 ����
���� 3�� �����̶�� ... ���� n���� ����
*/


/*���� 3 ������ �翬�� ������ ���ϱ��ڴ� �迭�� ���ٴ� ���� ������ �Ѵٰ� ���� ����.
��, abc �Ǵ� aba ����� ����� ���� ����. false�� abc�� �����ϰ�, true�� aba�� �����ϴ�.
���� 4 ������, �翬�� 3���� false ���ٴ� ������ �����Ƿ� abca �� �����ϴ�.
��, ���ϼ��� ���´ٸ� �� �������� ������ ���� ���̴�.
��, ���ϼ����� �ּҰ����� ���ϸ� �ȴ�.

33221�̶��
2 ����̴�. �ֳ��ϸ� 3���� �ɷ����⿡, �� �ּ����� ���̸� ���ϱ⿡.

���� 32231�̶�� ���� �ɷ�����. 2����.*/

int t;
int n;
int arr[MAX];
bool visit[MAX];

bool hasSubarray(int size, int searchlength) {
	for (int startidx = 0; startidx <= size - searchlength; startidx++) {//idx���� �����Ѵ�
		memset(visit + startidx, false, searchlength);
		for (int pp = 0; pp < searchlength; pp++) {
			int idx = startidx + pp;
			if (visit[arr[idx]])
				return true;
			else
				visit[arr[idx]] = true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		bool done = false;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 2; i <= n; i++) {
			if (hasSubarray(n, i)) {
				cout << i << endl;
				done = true;
				break;
			}
			else {
				memset(visit, false, n);
				continue;
			}
		}
		if (!done)
			cout << -1 << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}