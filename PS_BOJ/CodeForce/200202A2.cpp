#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/*
�� �ڸ����� ���� ¦������, �� ���� ¦���� �ƴ϶�� ����׼���� �Ѵ�.
���� �ƴ� ���� s�� �־�����, �� ������ n�ڸ����̸�
���� �� ���ڵ��� ���������ϴ�. �׷��� ����׼��� ���� �� �ֵ�.
�׷��� ������ ������ �ٲ� ���� ����.

���� ���� ���� ù �ڸ����� 0�̾ �ȵȴ�.

�־��� ���κ��� ���Ⱑ���� �ƹ� ����׼��� ����϶�.
���� �Ұ����ϸ� -1�� ����϶�.

*/

int t;
int n;
string str;

/*
��츦 ���� �� �ִ�.
1. ¦���ΰ� Ȧ���ΰ�
2. �� �ڸ����� ���� ¦���ΰ� Ȧ���ΰ�.
*/

bool ZzinEven() {//�� ¦������ �Ǻ�. string�� ������ �ڸ����� ¦������ Ȧ�������� �Ǻ��ϸ� �ȴ�.
	if ((str.back() - '0') % 2 == 0)
		return true;
	return false;
}

bool YusaEven() {//���� ¦������ �Ǻ�. �� �ڸ����� ���� ¦������ Ȧ�������� �Ǻ��ϸ� �ȴ�.
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		sum += str[i] - '0';
	}
	if (sum % 2 == 0)
		return true;
	return false;
}

void Initialize() {
	int n = 0;
	str.clear();
	return;
}

//���ϴ� ��: Ȧ���̸鼭 ���ڸ��� ���� ¦��
void solve() {
	Initialize();
	cin >> n;
	cin >> str;
	if (ZzinEven() == true) {//������, ���ڸ����� Ȧ�����ö����� ��ġ�� pop
		while (ZzinEven() == true) {
			if (str == "0") {
				cout << -1 << endl;
				return;
			}
			str.pop_back();
			if (str.empty() == true) {
				cout << -1 << endl;
				return;
			}
		}
	}

	//�ϴ� Ȧ���� �������, �������ڸ� lock�� �� �����۾� ����
	if (YusaEven() == true) {//�̹� �������� ��ť��
		cout << str << endl;
		return;
	}
	else {//�� �ڸ��� ���� Ȧ����, Ȧ���� ���� ¦���� ������ �Ѵ�. �� ��, ������ �� �ֿ����� �����ϰ� ���� 0�ۿ� ���ٸ� -1�����̴�.
		//��� �������� ����־�� �ϱ� ������, �������� Ȧ���� ¦���Ŀ� ���� ������.
		//�������� ¦���� �ӻ� �� Ȧ���� ���ٸ� ����.
		//�������� Ȧ���� �ӻ� �� 0�� �ƴ� � ���� ������ ����
		int zeros = 0;
		int evens = 0;
		int odds = 0;
		int evenidx = -1;
		int oddidx = -1;
		for (int i = 0; i < str.length() - 1; i++) {
			int tmp = str[i] - '0';
			if (tmp % 2 == 0) {
				if (tmp == 0)
					zeros++;
				else {
					evens++;
					evenidx = i;
				}
			}
			else {
				odds++;
				oddidx = i;
			}
		}
		if (odds > 1) {//Ȧ���� 2�� �̻��̸� ������ �͵� ����. ������ Ȧ�� ���� �ȴ�.
			if (str.empty() == false) {//Ȥ�ÿ���������
				str.erase(oddidx, 1);
				cout << str << endl;
				return;
			}
			else {
				cout << "ERROR" << endl;
				return;
			}
		}
		else {//odds�� 1�� or �ƿ� ����
			if (odds == 1) {//1���� ������, �װ� ��������� �ƴϸ鼭�� ¦�����Ұ� �ϳ��� �ֱ⸦ ������Ѵ�.
				if (evens == 0) {//������, ���Ĺ游 Ȧ�� ������ ���� 0
					cout << -1 << endl;
					return;
				}
				else {//Ȧ�� �� ¦�� ���� ����. �밡���� Ȧ������ ¦�������� �Ҹ�.
					if ((str.front() - '0') % 2 != 0) {//�밡���� Ȧ����, ��򰡿��� ¦���� �ִ�. �밡�� �����ϰ� ¦���� �Ӹ��� ����.
						int secondone = 0;
						for (int i = 1; i <= evenidx; i++) {
							if (str[i] != 0) {
								secondone = i;
								break;
							}
						}
						for (int i = secondone; i < str.length(); i++) {
							cout << str[i];
						}
						cout << endl;
						return;
					}
					else {//�밡���� ¦���̰�, Ȧ���� �����ϸ�
						int secondone = 0;
						for (int i = 1; i <= oddidx; i++) {
							if (str[i] != 0) {
								secondone = i;
								break;
							}
						}
						str.erase(secondone, 1);
						cout << str << endl;
						return;
					}
				}
			}
			else {//�ƿ� ������ ���
				cout << -1 << endl;
				return;
			}
		}


		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}