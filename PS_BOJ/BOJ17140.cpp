/*
�������迭�� ����
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


/*�迭�� ���ؼ� ���� �� �ִ� ������ 2������ �ִ�. R�� C �����̴�.
R������ ��� ROW�� ���� ������ �����Ѵ�. R�� ������ C�� �������� ���ų� Ŀ�߸� ����ȴ�.
C������ ��� COLUMN�� ���� ������ �����Ѵ�. C�� ������ R�� �������� Ŀ�� ����ȴ�.

���İ���� �迭�� �������� ���� ����Ƚ���� ��� �ְ�, ������ ���� ��������. ��-����Ƚ�� ������ ����.
���� ���, 3,1,1���� 3�� 1��, 1�� 2�� ����. ���� ������ 3,1,1,2 �� �ȴ�.
�̰� �� �����ϸ� 3�� 1�� 1�� 2�� 2�� 1���̹Ƿ� 3,1,1,2,2,1 �� �ȴ�. �ƴ�, �ٵ� �� 2,1,3,1,1,2�� �Ǵ°ǰ�?
���ı����� ������ ����.

��1����: ���� ����Ƚ���� ������������
��2����: ��1������ �����ϴٸ�, �� ��ü�� ������������

���ĵ� ����� �迭�� �ٽ� ������ R�̳� C�� ũ�Ⱑ Ŀ�� �� �ִ�. R������ ��� R�� Ŀ����, C ������ ��� C�� Ŀ����.
Ŀ�� ������ 0�� ä������. ���� ������ �� 0�� �����Ѵ�.
���� ���, 3,2,0,0 �� ������ ����� 3,2 �� ������ ����� �����ϴ�.

R�̳� C�� ũ�Ⱑ 100�� �Ѿ�� ó�� 100���� ������ �������� ������.
�迭 A�� ����ִ� ���� r,c,k�� �־����� �� A[r][c] �� ����ִ� ���� k�� �Ǳ� ���� �ּҽð��� ���϶�.
*/

/*���� �����ϴµ��� 20�� �Ѱ� �ɷȴ�...
�ϴ� ���� �þ�� ���Ĺ�����.
100�ʱ��� ������, 100�� Ÿ�ӿ����Ǹ� 
Ư���ϰ� ��/�� �ִ������� 100���� �����ϸ� ���� ���� �����ϴ°� �ƴ϶�, ���� ���� �����ϰ� ���ο� ��ǲ�� �ô� �� �ϴ�.
�׷��� �ϴ� 100�ʵ��������� �ϴ°� ���ϴ�. �׷��� �˾Ƽ� �����״ϱ�.

�� ������ ��������.
1. ���Լ� ����
2. ���Լ��� �̿��ؼ� �����ϴ�, R �� C ������ ���� ������ �Լ� ����
3. 100�� �������� R �� C ������ �ݺ���Ű�� �Լ� ����

���� �߿��� ���밡 �� �ڷᱸ�������� ��� �ϴ���...
��� ���� �ִ�ũ�Ⱑ 100�̶�� ���ѵǾ������� �׳� 100*100 �迭 ���� ������ �ʴ�. �迭 ����ȣȯ�� ���͸� ����... �ƴϴ�. �׷��� �迭�� ���� �� �ϴ�.
���Լ� ����� ���� ��� �ұ�. �ϴ� true, false �� ���Ͻ�Ű�� �׷��� ū ������ �ƴ� ���̴�. sort stl���� ���Լ� ���� �̿��ϸ� �ϴ� ���� ���̴�.

*/

int gr, gc, gk;//global r, c, k
int R = 3; int C = 3;
int Table[102][102];//�������ǻ� 0row0column�� ������

bool IsPriorThan(int num1, int num1Kazu, int num2, int num2Kazu) {/*���ڰ� �켱�̸� true, �ƴϸ� false ��ȯ. ������ ������ ���� ������ == ��ȯ ���� ����� �ʿ䰡 ����.*/
	if (num1Kazu > num2Kazu)
		return false;
	else if (num1Kazu == num2Kazu) {
		return num1 > num2 ? false : true;
	}
	else
		return true;
}

void R_Function() {

}

void C_Function() {

}

int Solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> gr >> gc >> gk;
	for (int r = 1; r <= 3; r++) {
		for (int c = 1; c <= 3; c++) {
			cin >> Table[r][c];
		}
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}