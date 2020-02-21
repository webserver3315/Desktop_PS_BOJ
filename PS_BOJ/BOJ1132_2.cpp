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
뒤에서부터 세야 하고
*/

int n;
int top = 9;
vector<string> everything;


void allocate(int idx) {//idx번째 자릿수에 해당하는 모든 문자열에 대응하는 것들을 더한다.
	int cnt_alphabet[10];
	fill_n(cnt_alphabet, 10, 0);//모든 배열원소 0으로 초기화
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