#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int t;
int n;
int minval = 1e6 + 1;
vector<int> arr;

/*
�ϴ� �ѹ� ������ Ǯ���.
���Ʈ�ϰ� Ǫ�°Ŵ�.
*/

/*
C���� �⺻������ ������ ��� ������ �����, �� �������� ���ǵ� �ش� ������ ���̰� �ִ�.
��, ���� �����ؾ��Ѵ�.
*/

int myMod(int a, int b) {//a%b
	return a - b * ((a / b) - 1);
}

/*
b*tmp�� a���� �ݵ�� ũ�ų� ������ �����. a=b*tmp+R���� R�� ������ ������ �ǹǷ�.
�׷���, �� ���������� R�� ������ ����� �Ǿ�� �Ѵ�.
��, ������ �������� a-b*tmp �� ǥ���ȴٸ�
������ �������� a-b*(tmp-1) �� �ȴ�.
��, a-b*((a/b)-1) �� �Ǵ� ���̴�.
�ٸ�, �� ����� b�� �����ϰ� ���� ��� �������� 0���� ����������Ѵ�.
*/

int main() {
	t = 1;
	while (t--) {
		cin >> n;
		arr.clear();
		minval = 1e6 + 1;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (minval > tmp)
				minval = tmp;
			arr.push_back(tmp);
		}

		sort(arr.begin(), arr.end());

		for (int nowDiv = arr.back(); nowDiv > 0; nowDiv--) {
			bool dameda = false;
			int flag = myMod(arr.front(), nowDiv);
			for (int i = 0; i < n; i++) {
				if (flag != myMod(arr[i], nowDiv)) {
					dameda = true;
					break;
				}
			}
			if (!dameda) {
				cout << nowDiv << endl;
				break;
			}
		}
	}
	return 0;
}