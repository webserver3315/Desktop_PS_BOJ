/*#609 Div2 A*/

#include <iostream>
#include <cmath>
#define MAX (int)1e8
using namespace std;

/*���� n�� �ǵ��� ����� �ռ��� n�� ã�ƶ�. ���� ������ �����ϰ� �ƹ��ų� ã���� �ȴ�.
�ϴ� �Ҽ��Ǻ��� �����佺ü�� �̿��ؼ� ���� ���ϴ°� �����ϴ�.
�Ҽ����̺� ���� �ڿ� ��¿����?
�ϴ�, a,b�� ������ 10�� 9�º��� �۴�. ���귮�� 8���̴� �Ϲ����� ������ �ȸ����ٰ� ���� �ȴ�.
10�� 9�±��� �׳� ���̺� ���������°� ���� �������ʳ�?
�ð��� �ϴ� 3�ʰɸ���,
���̺� ���� �ڷδ� ���� �����ϴ�.
*/

int n;
bool IsComposite[MAX + 1];

void makeEratos() {
	for (int i = 2; i < sqrt(MAX + 1); i++) {
		if (IsComposite[i] == true)
			continue;
		else {
			for (int j = i*2; j < MAX + 1; j+=i) {
				//printf("%d �� �Ҽ��� �ƴմϴ�\n", j);
				IsComposite[j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	makeEratos();
	for (int i = 2; i <= MAX-n; i++) {
		if (IsComposite[i] == true && IsComposite[i + n] == true) {
			cout << i + n << ' ' << i << endl;
			return 0;
		}
	}

	return 0;
}