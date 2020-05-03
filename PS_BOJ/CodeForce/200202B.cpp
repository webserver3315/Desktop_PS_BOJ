#include <iostream>
#include <vector>
using namespace std;

/*
n���� ���� �ƴ� �����迭�� �޴´�.
������/������ ���¸� sharpened�̴�.
equal�� �������� �ʴ´�.
������ �����ϰ� ������ ���� �������. ��, �� ��� �ٷ� �������� ���ȴ�.
��, ��������忡�� ���������� �Ϲ��������ν� ��ȯ�� �� �ѹ��� ���ȴ�.


*/

int t;
int n;
bool Decreasing;
vector<int> ivct;

void Initialize() {
	n = 0;
	Decreasing = false;
	ivct.clear();
	return;
}

/*
0203.02:32
������ �κ� ã�Ҵ�.
110
111
112
113
�� ���� No�� �����µ� ������ Yes�̴�.

���� 0��° ���� �������ν� �������� �����ų ��찡 �����Ѵٴ� ���� �����ߴ�.
1��° ���� ���� �� �ִ°� �ƴ϶�, ���������� �ƴ϶� ���������� ��� ������ ������ �ƴ϶� ������ ���Ҹ� ��°� �´�.
*/
bool CanBeSharp() {
	if (n == 1) {
		return true;
	}
	for (int i = 1; i < n; i++) {
		if (ivct[i - 1] < ivct[i]) {//�ö󰡴� ���̸�
			if(!Decreasing)//���ʿ� ����忴�ٸ� ���������
				continue;
			else {//�ϻ��忴�µ� �ö󰡰ų� �������̶�� ������. ��Ƽ��� �������߸� �Ѵ�.
				ivct[i] = ivct[i - 1] - 1;//������ �������� ����, �ִ��� õõ�� �̲����� ������ 0�� 2 �� ���̰� �ȴٸ� �����̴�.
				if (ivct[i] <= 0) {//�ϻ굵�� 0�� �꿴�ٸ�
					if (ivct[i] == 0)//1���� �뼭�Ѵ�
						continue;
					//2���� �뼭���Ѵ�
					else
						return false;
				}
			}
		}
		else {//�������ų� ������ ���̸�
			Decreasing = true;
			if (ivct[i - 1] == ivct[i]) {//�����ϴٸ�
				ivct[i] = ivct[i - 1] - 1;//������ ��´�. ////���⼭, �߸��Ǿ���. ������ ������ ������ �� �ȳ��� ��찡 �����Ѵ�.
				if (ivct[i] <= 0) {//�ϻ굵�� 0�� �꿴�ٸ�
					if (ivct[i] == 0)//1���� �뼭�Ѵ�
						continue;
					//2���� �뼭���Ѵ�
					else
						return false;
				}
			}
			else {//��ź�� �������̸� �� �͵� ����.
				//if (ivct[i] > 0)
				//	continue;
				//if (ivct[i] <= 0) {//�ϻ굵�� 0�� �꿴�ٸ�
				//	if (ivct[i] == 0)//1���� �뼭�Ѵ�
				//		continue;
				//	//2���� �뼭���Ѵ�
				//	else
				//		return false;
				//}
				continue;
			}
		}
	}
	return true;
}

void solve() {
	Initialize();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ivct.push_back(tmp);
	}

	bool ans = CanBeSharp();
	if (ans == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return;
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