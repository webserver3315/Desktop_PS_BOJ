#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

/*
���Ǹ� ���� string���� �ȹް� �������� 10������ �����Ѵ�.
*/

string strA;
string strB;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> strA >> strB;
	
	while (strA != "0" || strB != "0") {
		int cnt = 0;
		reverse(strA.begin(), strA.end()); reverse(strB.begin(), strB.end());
		if (strB.length() > strA.length()) {//������ A�� ��ų� ���� ó���Ѵ�.
			swap(strA, strB);
		}
		for (int i = 0; i < strB.length(); i++) {
			strA[i] += strB[i];//digit�� char�� 48~57�̹Ƿ�, 2�趧���� 127 �ʰ��ؼ� �����÷ο쳪�� �� ������ �����Ƿ� �̷��� �ص� �ȴ�. 
		}

		for (int i = 0; i < strA.length(); i++) {
			if (strA[i] > '9' + '0') {
				cnt++;
				if (strA[i] > '9' + '0')
					strA[i] -= (':');
				if (i != strA.length() - 1)
					strA[i + 1] += '1';//555 555�� �����÷ο� ����
				else
					strA.append("1");
			}
			else
				strA[i] -= '0';
		}
		/*if (cnt == 0)
			cout << "No carry operation." << endl;
		else if (cnt == 1)
			cout << cnt << " carry operation." << endl;
		else
			cout << cnt << " carry operations." << endl;*/
		cout << cnt << endl;
		cin >> strA >> strB;
	}

	return 0;
}