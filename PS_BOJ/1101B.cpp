/*
n�� ���� ������� ����. a,b,c�� ���� �ƴ� ������� �ϸ� �׵��� ���� n�̴�.
������������ ���� ���� �ϴµ� ���� a b c ������� ������� ������ �ִ�.
���� ���� �̱� Ƚ����� ���и� ������. ���� �����̶�� ���� �й�� �����Ѵ�.
�ִ� 100���ϸ�, �ٸ����� �� ���� 100�� �̳��̴�. �ݵ�� ���� ���� ���� ���� ��ġ�Ѵ�.


���ɴ� 100�� ����. 1�ʴϱ� ��ǻ� 10�� 6�³��� �ذ������.
���ɰ� �־����� ���� Ƚ�� �� ������� ������ �־���.
������ �ٿ��� ���� ���� ������ ������� �־���.
���� �ٸ����� ������ �ִٸ�, YES, ���� ���̱�ٸ� No �� ����϶�.
YES�� ���, �ٸ����� �̱� �� �ִ� ��츦 �����϶�.
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


/*�ϴ� ���� ���� ���� string���� �ް�, R C P�� ���� ���� ī�����ؾ��Ѵ�.
���� �й��� Ƚ���� ���ݼ��� �Ǵ� ���� �� �� �͵� ���� ���� �й��.
�ϴ� ������ ���� �ִ��� �̱�� �������� �Ҹ��Ѵ�. �� �̻� �����а� ���ٸ� ���ǳ��ش�.
���� ���� ���� ���ݼ��� �Ǹ� ���� �й��.
*/

int T;
int n, r, p, s, br, bp, bs, orr , orp, ors;

bool IsAliceWin(string& bob) {
	br = 0; bp = 0; bs = 0;//��
	for (char ch : bob) {
		if (ch == 'R')
			br++;
		else if (ch == 'P')
			bp++;
		else if (ch == 'S')
			bs++;
	}
	int win_p = min(br, p); int win_s = min(bp, s); int win_r = min(bs, r);//�̱� �ִ�Ƚ��
	r -= win_r; s -= win_s; p -= win_p;
	br -= win_p; bs -= win_r; bp -= win_s;
	if (win_p + win_s + win_r > n / 2)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//std::cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	while (T--) {
		if (T == 0) {
			int tmp;
			tmp = 1;
			cout << tmp;
			tmp += 1;
		}
		string bob;
		cin >> n;
		cin >> r >> p >> s;
		orr = r; orp = p; ors = s;
		cin >> bob;
		if (!IsAliceWin(bob)) {
			std::cout << "NO" << endl;
			continue;//�� �ù� ���⼭ �������θ� �ھƹ����� �����þ�
		}
		std::cout << "YES" << endl;
		for (char ch : bob) {
			if (ch == 'R') {
				if (p >= 0) {
					std::cout << "P";
					p--;
				}
				else if (r < s) {
					std::cout << "S";
				}
				else {
					std::cout << "R";
				}
			}
			else if (ch == 'P') {
				if (s >= 0) {
					std::cout << "S";
					s--;
				}
				else if (p < r) {
					std::cout << "R";
				}
				else {
					std::cout << "P";
				}
			}
			else if (ch == 'S') {
				if (r >= 0) {
					std::cout << "R";
					r--;
				}
				else if (s < p) {
					std::cout << "P";
				}
				else {
					std::cout << "S";
				}
			}
		}
		std::cout << endl;
	}
	/*
	R 10 P 1 S 10
	RRPPPPPPPPPSSSSSSSSSS
	*/

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//std::cout << ctime_duration << " ms" << endl;
	return 0;
}