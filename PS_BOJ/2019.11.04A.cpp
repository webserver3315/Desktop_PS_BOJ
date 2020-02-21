/*
#598 Div3 A
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
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

/*n���� ���� a���� �ְ� 1���� ���� b���� �ִ�
��Ȯ�� �Ž��������� �����ϰ��� �� ��

��ǲ�� a,b,n,S

n, 1������ ���� x,y�� �Ἥ S���� ���� �� ����? �Ұ���?
���� q


*/

int q, a, b, n, S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> q;
	while (q--) {
		cin >> a >> b >> n >> S;
		/*while (a-- && S >= n) {
			S -= n;
		}*/
		int div = min(S / n, a);
		a -= div;
		S -= n * div;
		/*
		while (b-- && S > 0) {
			S -= 1;
		}*/

		if (b >= S)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}