#include <iostream>
#include <string>
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
bool nodap;
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
	nodap = true;
	str.clear();
	return;
}

//���ϴ� ��: Ȧ���̸鼭 ���ڸ��� ���� ¦��
void solve() {
	Initialize();
	cin >> str;
	if (ZzinEven() == true) {//������, ���ڸ����� Ȧ�����ö����� ��ġ�� pop
		while (ZzinEven() == true) {
			str.pop_back();
		}
	}

	//�ϴ� Ȧ���� �������, �������ڸ� lock�� �� �����۾� ����
	if (YusaEven() == true) {//�̹� �������� ��ť��
		cout << str << endl;
		return;
	}
	else {//�� �ڸ��� ���� Ȧ����, Ȧ���� ���� ¦���� ������ �Ѵ�. �� ��, ������ �� �ֿ����� �����ϰ� ���� 0�ۿ� ���ٸ� -1�����̴�.
		for (int i = 1; i < str.length() - 1; i++) {//ù�ڸ� ������ �ϴ� �����ϱ� ���� i�� 1���� ���۽�Ŵ
			if ((str[i] - '0') % 2 == 0) {
				if (str[i] - '0' != 0)//�߰����� �߿��� 0�� �ƴ� ���� �ϳ��� ������ �ϴ� ����� �ƴ�.
					nodap = false;
				continue;
			}
			else {
				str.erase(i, 1);
				cout << str << endl;
				return;
			}
		}
		//����, ù�ڸ� �� ������ �ڸ����� �����ϰ� ���� ¦�����, 
		if (nodap) {
			cout << -1 << endl;
			return;
		}
		else {

		}

		return;
	}
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}