#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int t;
int n;
int mindiff = 2e5 + 1;
int max = 2e5 + 1;
int min;
string str;
vector<int> Ridx;
vector<int> Lidx;
vector<int> Uidx;
vector<int> Didx;

/*
R-L+U-D == 0�� �����ϴ�
���� ª�� �������� [a,b]�� ã���� �ȴ�.
*/
//����: 0�ε��� ������ ��½ÿ��� 1�ε������ ǥ���ؾ��Ѵ�.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> str;
		min = 0;
		max = 2e5 + 1;
		mindiff = 2e5 + 1;

	}
	return 0;
}