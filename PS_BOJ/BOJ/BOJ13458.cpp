/*
���� ����
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
//typedef pair <long long, long long> P;
//P mypair = make_pair(1.2);//�������
//pair<long long, long long> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�
//#define mp(x,y) make_pair(x,y)//���ι���
using namespace std;


/*N���� �������� �ְ� ���� �����ڵ��� ����.
i�� �����忡 Ai���� �����ڰ� �ִ�.
�������� �� �濡 B����, �ΰ������� �� �濡 C���� ������ �� �ִ� �ɷ��� ������ �ִ�.
������ �����忡 �Ѱ������� ���� 1���̴�. �ΰ������� ���� �����ϴ�.
�� �� �ʿ��� ������ ���� �ּڰ��� ���϶�.

ù �ٿ��� �������� ���� N
�Ѥ� �ٿ��� �� �����忡 �ִ� �������� �� Ai(���� �� �ٸ���)
��°�ٿ��� ���������Ķ������ B, C�� �־�����.

*/

long long N, B, C;
vector<long long> Class;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;
	for (long long i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		Class.push_back(tmp);
	}
	cin >> B >> C;

	long long Main_Kantoku = 0; long long Sub_Kantoku = 0;

	for (long long& nokori : Class) {
		nokori -= B;
		if (nokori < 0)
			nokori = 0;
	}
	Main_Kantoku += Class.size();

	for (long long& nokori : Class) {
		long long hitsuyou = (long long)ceil(nokori / (float)C);
		Sub_Kantoku += hitsuyou;
	}

	long long Total_Kantoku = Main_Kantoku + Sub_Kantoku;
	cout << Total_Kantoku << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}
/*long long���� ó���� �����༭ int �Ѱ谪�� �ʰ��ع����� Ʋ�Ƚ��ϴٰ� ���Դ� ����̴�.
�������� �״� 100���� �Ѵ� ���� ����Ѵٸ� long long ����.
ġ�������� �̷��Զ� ����� ���߷��� �ϳ�����.*/