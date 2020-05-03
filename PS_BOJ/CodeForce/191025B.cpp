/*
B
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

/*
n������ 2����Ʈ���� �־��� ��
��Ʈ���� �� 1�� 0�� ���� ��������.
�׸���, ��Ʈ���� ���̸� �����س���.
¦���� 1 �Ǵ� 0�� ¦�������� �Ҹ��ؾ� �ϰ�
Ȧ���� 1 �Ǵ� 0�� ¦�������� �Ҹ��ϸ鼭 �߰��� 0 �Ǵ� 1 �ƹ��ų� �ܵ����� �Ҹ��ϸ� ȸ���� �ϼ��ȴ�.

�������, �� ���� ª�� ��Ʈ������ ȸ������ �������°� �켱�� �׸����� �����̴�.

*/

int Q;

int Solve(int n) {
	int OneKazu = 0; int ZeroKazu = 0;
	vector<string> strings;
	vector<int> sizes;
	int palindrome = 0;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		strings.push_back(tmp);
		for (char c : tmp) {
			if (c == '1')
				OneKazu++;
			else if (c == '0')
				ZeroKazu++;
		}
		sizes.push_back(tmp.size());
	}
	sort(sizes.begin(), sizes.end());
	
	for (int sizeFromMin : sizes) {

		int sacrifice = sizeFromMin / 2;
		int sacrifice2 = 1;

		if (sizeFromMin % 2 == 0) {//¦�����
			while (sacrifice) {
				if (max(OneKazu, ZeroKazu) < 2)//sacrifice ������Ű�� ���� 1, 0�� ������ ��� ���⼭ ���͸���.
					break;
				bool OneIsOoi = OneKazu > ZeroKazu;
				if (OneIsOoi) {
					OneKazu -= 2;
				}
				else {
					ZeroKazu -= 2;
				}
				sacrifice--;
			}
		}
		else {//Ȧ�����
			while (sacrifice) {
				if (max(OneKazu, ZeroKazu) < 2)//sacrifice ������Ű�� ���� 1, 0�� ������ ��� ���⼭ ���͸���.
					break;
				bool OneIsOoi = OneKazu > ZeroKazu;
				if (OneIsOoi) {
					OneKazu -= 2;
				}
				else {
					ZeroKazu -= 2;
				}
				sacrifice--;
			}
			if (sacrifice == 0) {//Ȧ���� sacrifice�� �������ѵ� �� ���� ������ �� �����ִ�.
				bool OneIsOoi = OneKazu > ZeroKazu;
				if (max(OneKazu, ZeroKazu) < 1)//���� 1 ������Ű�� ���� 1, 0�� ������ ��� ���⼭ ���͸���.
					return palindrome;
				if (OneIsOoi) {
					OneKazu--;
				}
				else {
					ZeroKazu--;
				}
			}
		}
		if(sacrifice==0)
			palindrome++;
		else {//�����̸� ��������.
			return palindrome;
		}
	}

	return palindrome;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int stringNumber;
		cin >> stringNumber;
		int ans = Solve(stringNumber);
		cout << ans << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}