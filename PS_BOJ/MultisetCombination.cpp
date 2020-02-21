/*
N�� M 4
�ߺ�����
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
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

/*�ߺ������� ����������, �ߺ��� ����ϴ� visit �迭�� �ʿ����.
�ٸ�, �񳻸��������� �����Ǿ������Ƿ�, start�迭�� �����ؾ� �Ѵ�.
�׷��� �������� start+1�� �ƴ϶� start�� �ϸ� �ȴ�.
*/

int N, M;
vector<int> mystack;

void MultisetCombination(int Start, int SentakuKazu) {
	if(SentakuKazu == M) {
		for (int i : mystack)
			cout << i << ' ';
		cout << endl;
		return;
	}
	for (int i = Start; i <= N; i++) {/*���� i�� Start����, Start���� ū�� ������ �ʿ� ����! �׳� ������ ������ �����ȵǹǷ�, */
		mystack.push_back(i);
		MultisetCombination(i, SentakuKazu + 1);
		mystack.pop_back();
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	MultisetCombination(1, 0);


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}