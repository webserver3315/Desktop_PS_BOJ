#include <iostream>
#define MAX (int)1e8+1
using namespace std;

/*BST�� ���� ����� �ְ�, �迭�� ��¥�� ���� ����� �ִ�.
int�� 4����Ʈ�̹Ƿ� 8�¶����� �����ϴ�.
bool�� 1����Ʈ�̹Ƿ� 8�¶����� 256�ް� ���� ���´�.
��Ʈ����ũ�� 1��Ʈ�̹Ƿ� ���� ������ ���̴�.
*/

int A, B;
bool visitA[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		int tmp;
		cin >> tmp;
		visitA[tmp] = true;
	}

	int cross = 0;//��ġ�� ����
	for (int i = 0; i < B; i++) {
		int tmp;
		cin >> tmp;
		if (visitA[tmp])
			cross++;
	}
	cout << A + B - 2 * cross << endl;

	return 0;
}