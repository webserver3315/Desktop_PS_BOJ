#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#define pic pair<int, char>
#define ff first
#define ss second
using namespace std;

/*
�ڿ������� ���� �ϰ�
*/

int n;
int top = 9;
vector<string> everything;


void allocate(int idx) {//idx��° �ڸ����� �ش��ϴ� ��� ���ڿ��� �����ϴ� �͵��� ���Ѵ�.
	int cnt_alphabet[10];
	fill_n(cnt_alphabet, 10, 0);//��� �迭���� 0���� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		if (everything[i][idx]<'A' || everything[i][idx]>'J')
			continue;
		int nowidx = everything[i][idx] - 'A';
		cnt_alphabet[nowidx]++;
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmpstr;
		cin >> tmpstr;
		reverse(tmpstr.begin(), tmpstr.end());
		everything.push_back(tmpstr);
	}



	return 0;
}