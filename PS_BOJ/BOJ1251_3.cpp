#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;//���̴� 50 ����. ��, 2�� �ݺ��� ģ�ٰ� �ص�, 51C2 �� 51*25�� �̸��ۿ� �ȵȴ�. �������� �������̴�.
string minstr;

string swapstr(int a, int b) {//1����: 0~a-1, 2����: a~b-1, 3����: b~n-1, �� x+1 ĭ�� ���� ģ��.
	int idx = 0;
	string tmp;
	string tmptmp;
	tmp.reserve(51);
	for (int i = 0; i < a; i++) {
		tmp.append(1, str[i]);
	}
	reverse(tmp.begin(), tmp.end());
	tmptmp.append(tmp);
	tmp.clear();

	for (int i = a; i < b; i++) {
		tmp.append(1, str[i]);
	}
	reverse(tmp.begin(), tmp.end());
	tmptmp.append(tmp);
	tmp.clear();

	for (int i = b; i < str.length(); i++) {
		tmp.append(1, str[i]);
	}
	reverse(tmp.begin(), tmp.end());
	tmptmp.append(tmp);
	tmp.clear();

	//cout << "This time, " << tmptmp << " �� ���Դ�." << endl;
	return tmptmp;
}

int main() {
	cin >> str;
	minstr = str;
	for (int i = 1; i < str.length() - 1; i++) {
		for (int j = i + 1; j < str.length(); j++) {
			string nowswaped;
			nowswaped = swapstr(i, j);
			if (nowswaped < minstr)
				minstr = nowswaped;
		}
	}
	cout << minstr;
	return 0;
}