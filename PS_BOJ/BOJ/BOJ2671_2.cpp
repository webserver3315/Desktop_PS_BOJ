#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int t;
int idx;
//
//string makeToken(string& str, int begin, int end) {//[begin,end) 의 토큰 스트링을 반환한다.
//	string token;
//	for (int i = begin; i < end; i++) {
//		token.append(str[i]);
//	}
//
//}

void plus(string& str) {//속도를 위해 참조자 단 것으로, str 건들지 말 것. str이 반복되는 한 idx를 늘린다.
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