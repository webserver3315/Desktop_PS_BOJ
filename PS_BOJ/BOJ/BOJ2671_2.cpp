#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int t;
int idx;
//
//string makeToken(string& str, int begin, int end) {//[begin,end) �� ��ū ��Ʈ���� ��ȯ�Ѵ�.
//	string token;
//	for (int i = begin; i < end; i++) {
//		token.append(str[i]);
//	}
//
//}

void plus(string& str) {//�ӵ��� ���� ������ �� ������, str �ǵ��� �� ��. str�� �ݺ��Ǵ� �� idx�� �ø���.
	string buffer;
	int len = str.length();
	buffer = str.substr(idx, len);
	while (buffer == str) {
		idx += len;
		buffer = str.substr(idx, len);
	}

}

int main() {
	cin >> t;
	while (t--) {
		idx = 0;


	}

	return 0;
}