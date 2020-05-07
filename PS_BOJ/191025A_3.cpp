/*
A
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

/*���峭 Ű����� �ݵ�� �ߺ��Է�. ����ȳ�Ű����� �׳��Է�.
string�� ó������ ������ �����ϴµ�, ���� ������ ���ڰ� Ȧ���� �ݺ��ȴٸ�(1���� ����) �� ���ڴ� map�� �ִ´�.


*/

int T;


/*������ �Ѵ�. 
1�� �ε������� �����ϸ�, �ڽ� �����װ� ���Ѵ�.
�ڽ� �����װ� �����ϸ� KurikaesiCount�� ����
�ٸ��� ���� ���� ��Ʈ����.

�� �� ��ü������ ¥��.
�ϴ� ũ�Ⱑ 1�������� �����Ѵ�. 1�̸� �׳� �װ� ����ϰ� ��Ʈ����.
���� ũ�Ⱑ 2 �̻��̶��, �����װ� ������ ���縦 �ݺ��ϰ� �ȴ�.
����, �����װ� �����ϴٸ�: �ݺ�ī��Ʈ ++ // �ƴϴ�. ������ �յ� �Ѵ� ���ؾ߸� �Ѵ�. // �ƴϴ�. ���ڰ� �ٲ𶧸��� insert �Ǵ��ϴ� ������ �Ѵٸ� �������.
�����̰ų�, �ٸ��ٸ�: �ݺ�ī��Ʈ++�ϰ� �ݺ�ī��Ʈ ����. ���� Ȧ���� �ݺ��� ��Ȳ�̸�insert, ���ٸ� ��������
*/
void solve(string answer) {
	if (answer.size() == 1) {
		cout << answer << endl;
		return;
	}
	//answer.push_back('E');
	set<char> Kakusin;
	char Kioku = answer.front();
	int KurikaesiCount = 1;
	for (int idx = 1; idx <= answer.size();idx++) {//�� ������ �ȶ���? idx==answer.size() �ε� answer[idx]�� �����ϸ� �Ұ����� ������� ������ ���� ���ݾ�? ��, �ƿ� ���ǵ��� ���� ���̽��� �������� ���� �ʴ°ǰ�;
		char c = answer[idx];//��, ������ �ȶ��. �ֳ��ϸ�, size�� ������ idx�� �����ϴ� ��� \0�� ���������� c�� ����Ǳ� �����̴�. �������� �������� ����Ѵ�. �׷���, ���� �� �����ؼ� \0 �� �������� ��� ������ string�� ���ұ������� ��������� �� �� �����Ϸ����ؿ��� ��� �� ������ ���������� ���α׷��� ��Ʈ����.
		if (c != Kioku) {
			//KurikaesiCount++;
			if (KurikaesiCount % 2) {
				Kakusin.insert(Kioku);
				//cout << Kioku << " �� Ȧ���� �ݺ��Ǿ����Ƿ� ����" << endl;
			}
			Kioku = c;
			KurikaesiCount = 1;
		}
		else {
			KurikaesiCount++;
		}
	}
	/*if (answer.back() != Kioku) {
		if (KurikaesiCount % 2)
			Kakusin.insert(c);
		KurikaesiCount = 1;
		Kioku = c;
	}*/
	for (char c : Kakusin) {
		cout << c;
	}
	cout << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	for (int i = 0; i < T; i++) {
		string answer;
		cin >> answer;
		solve(answer);
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}