/*
���� 2��
�� ��ǲ������ 9�¹̸�.
��, �̰� �������� �������� �������ϴٰ��� ������ �ð��ʰ���.
�Ҽ��θ� �������ϳ�... �װ� Ʋ����.
2��6�µ� �����ϱ� �����̴�.
�׷���, �ȵǴ� ���� �̹� �湮���� �� ���̴�.
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
#define MAX 31625
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

int t;
int n;
vector<int> kotae;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		kotae.clear();
		cin >> n;
		int cnt = 0;
		int rootval = (int)sqrt(n) + 1;
		for (int div = 2; div < rootval && cnt < 2; div++) {
			if (n % div == 0) {
				cnt++;
				n /= div;
				kotae.push_back(div);
				continue;
			}
		}

		if (cnt >= 2) {
			if (kotae.back() >= n) {
				cout << "NO" << endl;
				continue;
			}
			else {
				cout << "YES" << endl;
				for (int i = 0; i < kotae.size(); i++) {
					cout << kotae[i] << ' ';
				}
				cout << n << ' ';
				cout << endl;
				continue;
			}
		}
		else {
			cout << "NO" << endl;
			continue;
		}
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}