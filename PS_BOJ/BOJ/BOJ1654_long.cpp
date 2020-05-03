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

long long K, N;
long long minlan = 1, maxlan, kouhou;//����, �ʱⰪ minlan ���� 1�� �ƴ϶� 0���� ��Ƴ��� ��Ÿ�ӿ����߳�?
//long long lan[MAX];
vector<long long> lan;//��������for�� ���� ���� ���ͷ�

void psearch() {/*min�� max�� ��հ��� kouhou�� ��� ������ ������ �� ������ ������ �����Ǵ��� ���
			   ����, max�� min�� ���������ų� �����Ǹ� �ش� ���̸� ����
			   ����, �����ϸ� max�� kouhou, kouhou�� min�� ��հ����� kouhou�� ������Ʈ�� �� �ٽ� ����
			   ����, ���ϸ� min�� kouhou, kouhou�� max�� ��հ����� kouhou�� ������Ʈ�� �� �ٽ� ����
			   ���������� ���Ǵ� �ִ��� kouhou���� ã�� ���̴�
			   */
	while (minlan <= maxlan) {
		long long lankazu = 0;
		for (long long length : lan) {
			lankazu += length / kouhou;
		}
		if (lankazu < N) {//������ ���� ������. kouhou�� ª�� �ؼ� �� �߰� �߶����
			//cout << "minlan: " << minlan << " kouhou: " << kouhou << " maxlan: " << maxlan << " lankazu: " << lankazu << " ������ ���� ������. kouhou�� maxlen ���Դϴ�" << endl;
			maxlan = kouhou - 1;
			kouhou = (minlan + maxlan) / 2;
		}
		else {//������ ���� ������. ���ϰ� ª�� �ڸ� ���̹Ƿ� �����ʿ�
			//cout << "minlan: " << minlan << " kouhou: " << kouhou << " maxlan: " << maxlan << " lankazu: " << lankazu << " ������ ���� ������. kouhou�� minlen �ø��ϴ�" << endl;
			minlan = kouhou + 1;
			kouhou = (minlan + maxlan) / 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N;
	for (long long i = 0; i < K; i++) {
		long long tmp;
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