/*������ Ÿ�ڱ⸦ �պ���

w�� uu, m�� nn���� ����ϰ� �������.

���� ������ �޾Ҵµ� �� ���Ҹ��� �𸣰ڴµ�, �̰� ������ �պ��� �׷����� �ƴϸ� �۽��ڰ� �������ΰ��� �Ǵ��� �ȼ�
�Ǵ��� ����� ���� ��� ����� ���� ���� 1��� 1���̽��� ���� ����.
�󸶳� ���� ���̰� �ʿ��ұ�?
������ ���� �ʹ� ���� ��츦 ����Ͽ�, 10�� 9�� ���ϱ� 7�� ������.
modx(a+b) == modx (modx(a) + modx(b))

�ǽ��� ������ ���ٸ� 0���� �ʿ��ϹǷ� 0�� ����϶�.
�ð��� 1���̸�, ������ ���ڼ��� 10�� 5�� �����̴�. ������ �ҹ��ڸ��� ����ȴ�.


Ǯ�� ���ؼ� �߿��� Ű�� �Ǵ� ö�ڴ� u�� n�� �����̴�.
�����, w�� m�� �����ٸ� �װ� ����Ұ����� ���̹Ƿ� �ٷ� 0 ����ϸ� �ȴ�. ������ �ݵ�� Ÿ�ڱ⸦ �ǵ�ȴ�.
������ ����Ʈ�� uuu, nnnó�� ���ӵ� Űö�ڸ� �߰��� �� ��� ó���� �ϴ����̴�.

������ 0�̴�
n�� 0�̴�.
nn�� nn, m �� ������ �����ϴ�
nnn�� nnn, nm, mn �� ������ �����ϴ�
nnnn�� nnnn, nnm, nmn, mnn, mm �� �ټ������� �����ϴ�.
nnnnn�� nnnnn, nnnm, nnmn, nmnn, mnnn, nmm, mnm, mmn �� ���������� �����ϴ�
�̰� �Ǻ���ġ�ƴ�?
�翬�ϳ�, nnn�� m�� �����ϴ� ����� ���� nnnn�� n�� �����ϴ� ����� ��(append���ϴ°Ŵ�)��.

�̷��� ���� ��� ����� ���� ���� �����ָ� �ȴ�.
������� nnnannnn�̸� 3*5=15�̴�.

�� ���߿�, m�̳� w�� �ĺ��ϸ� ���� ���Ľ��Ѿ��Ѵ�.
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
#define DIV 1000000007
#define int long long
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

int memo[10005] = { 0,0,2,3 };
int fibo(int n) {
	if (n < 2)
		return 0;
	else if (memo[n])
		return memo[n];
	else {
		memo[n] = (fibo(n - 1) + fibo(n - 2)) % DIV;
		return memo[n];
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	string letter;
	cin >> letter;
	vector<int> cross;

	/*for (int i = 0; i <= 100; i++) {
		cout << fibo(i) << ' ';
	}*/

	int cnt = 0;
	char beforech = 'A';
	/*for (char ch : letter) {
		if (ch == 'w' || ch == 'm') {
			cout << "0" << endl;
			return 0;
		}
		else if (ch == 'u') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if (cnt != 0)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else if (ch == 'n') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if(cnt!=0)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else {
			if (beforech == 'u' || beforech == 'n') {
				if (cnt != 0)
					cross.push_back(fibo(cnt));
				cnt = 0;
				beforech = ch;
				continue;
			}
			beforech = ch;
			continue;
		}
	}*/

	for (int idx = 0; idx <= letter.size(); idx++) {
		char ch = letter[idx];
		if (ch == 'w' || ch == 'm') {
			cout << "0" << endl;
			return 0;
		}
		else if (ch == 'u') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if (cnt != 0 && cnt != 1)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else if (ch == 'n') {
			if (beforech == ch) {
				cnt++;
				continue;
			}
			if (cnt != 0 && cnt != 1)
				cross.push_back(fibo(cnt));
			cnt = 1;
			beforech = ch;
		}
		else {
			if (beforech == 'u' || beforech == 'n') {
				if (cnt != 0 && cnt != 1)
					cross.push_back(fibo(cnt));
				cnt = 0;
				beforech = ch;
				continue;
			}
			beforech = ch;
			continue;
		}
	}

	int ans = 1;
	for (int tmp : cross) {
		ans *= tmp;
		ans %= DIV;
	}
	cout << ans << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}