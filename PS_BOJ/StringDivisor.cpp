#include <string>

int StrDivInt(string a, int b) {//string a�� b�� ������ int�� ���. a�� �ʹ� �䵵���� �� �� ���. b���� string �̾�߸� �� ���� ���� �� �����ؾߵ�.
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