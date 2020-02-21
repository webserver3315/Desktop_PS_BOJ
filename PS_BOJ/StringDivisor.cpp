#include <string>

int StrDivInt(string a, int b) {//string a를 b로 나눠서 int로 출력. a가 너무 답도없이 길 때 사용. b까지 string 이어야만 할 경우는 따로 더 연구해야됨.
	int tmp = 0;
	int idx = 0;
	while (idx < a.length()) {
		while (tmp < b && idx < a.length()) {
			tmp = tmp * 10 + a[idx++] - '0';
		}
		tmp %= b;
	}
	return tmp;
}