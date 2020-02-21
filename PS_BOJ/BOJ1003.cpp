/*
�Ǻ���ġ ����
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
#define ff first
#define ss second
typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�


/*�Ǻ���ġ ��������, ��������� �Լ��� ȣ���� �� �ᱹ fibo(1), fibo(0) �� ȣ���ϰ� �ȴ�.
fibo(N)�� ȣ������ ��, 1�� 0 ������ �Լ��� �� �� ���� ȣ��Ǵ����� ���Ͻÿ�

�ð��� �����ϴ�. 0.25�ʸ� �־�����.

ù �ٿ� �׽�Ʈ���̽��� ���� T�� �־�����
�� ���̽��� �� �ٷ� �̷������ 40���� ���� N�� �μ��� �־�����.
*/

int T, N;
int ZeroKazu, OneKazu;//ȣ��Ƚ��
vector<pii> Memoization(42);//idx ��ǲ �� 0, 1�� ȣ��Ƚ�� ����. (42) �� reserve(42)�� �����ϴ�. ��, ������ �ִ°� �ƴ϶� �Ҵ縸 �س��°Ŵ�. Ȥ�� ��������ؼ� �ϴ� �Ϲݹ迭�� �غ��� �̰� ����Ÿ�� ����.
bool visited[42];
int MemoizationFibo[42];
//pii Memoization[42];

/*�� �� ȣ��Ǵ��� ����� �ϴ� ���� ���� ���̴�.
pii�� �����ؼ� ù ���ڴ� �ش� ��ǲ���� ZeroKazu, ss�� OneKazu�� �����ϵ���.

*/

int fibo(int n) {
	if (n == 0) {
		ZeroKazu++;
		return 0;
	}
	else if (n == 1) {
		OneKazu++;
		return 1;
	}
	else {
		if (visited[n] == true) {
			return MemoizationFibo[n];
		}
		else {//ó���������̸�
			MemoizationFibo[n] = fibo(n - 1) + fibo(n - 2);
			Memoization[n].ff = Memoization[n - 1].ff + Memoization[n - 2].ff;
			Memoization[n].ss = Memoization[n - 1].ss + Memoization[n - 2].ss;
			visited[n] = true;
			return MemoizationFibo[n];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	
	

	cin >> T;

	Memoization[0].ff = 1; Memoization[0].ss = 0; visited[0] = true;
	Memoization[1].ff = 0; Memoization[1].ss = 1; visited[1] = true;

	while (T--) {
		ZeroKazu = 0; OneKazu = 0;
		cin >> N;
		if (visited[N] == true) {/*�̺κ��� fibo ���� ���� �� �ִٸ� �ξ� �������� �������ϴ� �ƽ����� �ִ�.*/
			cout << Memoization[N].ff << ' ' << Memoization[N].ss << endl;
		}
		else {
			fibo(N);
			cout << Memoization[N].ff << ' ' << Memoization[N].ss << endl;
		}
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}