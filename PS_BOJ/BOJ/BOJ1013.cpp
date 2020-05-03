#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

/*
(100~1~|01)~
100~1~ �Ǵ� 01�� ������ ���ѹݺ��̸� ��������� ��������. �� �ܿ� ���� false.
�ϴ� ó���� 10�ڴ��� 01�ڰ�, ���ڸ� �� ���� 0000000000000111111111111������ ���;� ��.
�ٵ�, ������ 10001�̸� ������ 01�� ���ڷ� �����ؼ��� �ȵǰ� ������ �������� �ν��ؾ���.

��Ʈ�� ���̴� 150����. ��, �ð��� ������ ���� �ַ�����δ� ũ�� �������ص� �ȴ�.
*/

int t;
int idx = 0;
string sound;

bool IsInBoundary(int i) {
	if (i >= sound.size()) {
		return false;
	}
	return true;
}

bool FirstOne() {//10���� �����̸�
	if (sound.size() - idx < 2)
		return false;
	bool flag = false;
	while (sound[idx] == '0') {
		flag = true;
		idx++;
		if (!IsInBoundary(idx))
			return false;
	}
	while (sound[idx] == '1') {
		if (!flag)
			return false;
		idx++;
	}
	return true;
}

bool IsSubmarine() {//ù �� ���� �޾Ƽ� � ������� �����ϰ�, �����Ѵ�.
	while (idx < sound.size()) {
		string fs;
		if (idx == sound.size() - 1)//���ۿ� 1���ڸ� ������ ���.
			return false;
		fs += sound[idx++];//�������� �߰��ƴ��� ���ɼ�, ���� �߸������� ���ɼ� ����ؾ���. �ϴ� �ּ� 2���� ���� �� �־�� ��.
		fs += sound[idx++];
		if (fs == "10") {
			if (FirstOne()) {
				continue;
			}
			else {
				return false;
			}
		}
		else if (fs == "01") {
			continue;
		}
		else if (fs == "00") {
			if (idx < 3) {
				return false;
			}
			if (sound[idx - 3] == '1' && sound[idx - 4] == '1') {
				fs = "10";
				idx--;
				if (FirstOne()) {
					continue;
				}
				else {
					return false;
				}
			}
			else
				return false;
		}
		else {
			return false;
		}
	}
	if (idx == sound.size())
		return true;
	return false;
}

int main() {
	cin >> t;
	while (t--) {
		idx = 0;
		cin >> sound;
		if (IsSubmarine())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}