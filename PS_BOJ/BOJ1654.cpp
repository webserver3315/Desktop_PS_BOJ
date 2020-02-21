/*
���� �ڸ���
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*������ ���̷� �߶�� �ϹǷ�
���ɹ����� �ϴ� 0~�ִܰ� �����̴�.
������ġ ����*/

#define MAX 10005

int N, K;
int minlan, maxlan, kouhou;
//int lan[MAX];
vector<int> lan;//��������for�� ���� ���� ���ͷ�

void psearch() {/*min�� max�� ��հ��� kouhou�� ��� ������ ������ �� ������ ������ �����Ǵ��� ���
			   ����, max�� min�� ���������ų� �����Ǹ� �ش� ���̸� ����
			   ����, �����ϸ� max�� kouhou, kouhou�� min�� ��հ����� kouhou�� ������Ʈ�� �� �ٽ� ����
			   ����, ���ϸ� min�� kouhou, kouhou�� max�� ��հ����� kouhou�� ������Ʈ�� �� �ٽ� ����  
			   ���������� ���Ǵ� �ִ��� kouhou���� ã�� ���̴�
			   */
	while (minlan <= maxlan) {
		int lankazu = 0;
		for (int length : lan) {
			lankazu += length / kouhou;
		}
		if (lankazu < K) {//������ ���� ������. kouhou�� ª�� �ؼ� �� �߰� �߶����
			//cout << "minlan: " << minlan << " kouhou: " << kouhou << " maxlan: " << maxlan << " lankazu: " << lankazu << " ������ ���� ������. kouhou�� maxlen ���Դϴ�" << endl;
			maxlan = kouhou - 1;
			kouhou = (minlan + maxlan) / 2;
		}
		else{//������ ���� ������. ���ϰ� ª�� �ڸ� ���̹Ƿ� �����ʿ�
			//cout << "minlan: " << minlan << " kouhou: " << kouhou << " maxlan: " << maxlan << " lankazu: " << lankazu << " ������ ���� ������. kouhou�� minlen �ø��ϴ�" << endl;
			minlan = kouhou + 1;
			kouhou = (minlan + maxlan) / 2;
		}
	}
}

/*������, K�� N���� ���� �ÿ��� ��� ���� ���̳� �ϴ� ��.*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		lan.push_back(tmp);
	}
	sort(lan.begin(), lan.end());
	//maxlan = lan[0];
	maxlan = lan.back();
	kouhou = (minlan + maxlan) / 2;
	
	psearch();

	cout << kouhou << endl;

	return 0;
}