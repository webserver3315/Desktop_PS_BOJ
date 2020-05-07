#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

/*
4 0 11 11 11
��ġ�� �ʾҴ� �� �� ���� ū ���� ���� �տ�.
�� ������ ������ �������.
*/

int n;
vector<int> arr;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), desc);

	/*
	
	*/
	int now = arr[0];
	int koreda = -1;
	for (int i = 0; i < arr.size() - 1; i++) {
		if (now != arr[i + 1]) {//�������� �ٸ���
			if (i > 0 && now == arr[i - 1]) {//�������͵� ���ٸ�, ������ ���� �ƴϴ�.
				now = arr[i+1];
				continue;
			}
			koreda = now;//�������� ���ų� �������� �ٸ��ٸ�, ������ ����.
			break;
		}
		now = arr[i+1];
	}
	if (koreda != -1) {
		cout << koreda << ' ';
		for (int i : arr) {
			if (i != koreda)
				cout << i << ' ';
		}
		cout << endl;
	}
	else {
		for (int i : arr) {
			cout << i << ' ';
		}
		cout << endl;
	}

	return 0;
}