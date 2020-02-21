/*
�޸���
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

/*
���׸�Ʈ Ʈ���� �� ���Դ°�?
���� ����� �ٲ�� �迭���� �̿��� �׵��� ������ �ʿ䰡 ���� ��, �չ迭�ε� ����ȭ�� �Ұ����� ��츦 ������ �˻��ϱ� �����̴�.
*/

/*
���� ���� 5e5 ����. ��ġ�� �Ƿ� ����.
*/

/*
�ƴ�, �̰� �׳� ����������� sort�� ��, ���� ��ġ�� �������� �� ��ġ �� min�� ����ϸ� �ȵǳ�?
�ȵȴ�. ���� �Ƿ��ڰ� �ڽ��� ��ġ�� �ʾҴٴ� ������ �ʿ��ϴ�.
�׷��ٸ�, �ڽź��� 1������� ���ؼ��� ������ �Ǵ� �� �ƴѰ�?
�׷���, �׷��ٰ� �ϸ� ������ ������ ���� ���� sort�� �������ϴµ�, log5e5�� 5e5�� �ݺ��ϰ� �ǹǷ� 30e5�� �ȴ�. 3e6�̹Ƿ� 1�ʸ� �������ϱ� �ѵ�...
sort ������, �ڱ� ����ִ��� ã��, �װ� �ݺ�.
logN * logN(����) * N = 180e5�ϱ� �ƽ��ƽ��ϱ���.
�ƴ�, �׷��� �����غ��ϱ� ���� �迭 ������ �ʿ䵵 ����. 1����������, 2����������, 3���������� �̷��� �� �� ���� ���� ���ĵ�ä�� �������.
����Ʈ������ ������.
*/

int n;
vector<int> players;
//vector<int> saikono_junban;

void print_players() {
	for (int player : players) {
		cout << player << ' ';
	}
	cout << endl;
	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		players.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		vector<int>::iterator vctstart = players.begin();
		int motono_idx = i;//���� �ε���
		int jitsuryoku = players[i];
		//cout << jitsuryoku << " �� �Ƿ��� ������ �ִ� ������ �����ұ��???" << endl;
		sort(vctstart, vctstart + i + 1, greater<int>());
		vector<int>::iterator now_iter = find(vctstart, vctstart + i, jitsuryoku);
		int now_idx = distance(vctstart, now_iter);
		//print_players();
		cout << min(motono_idx, now_idx) + 1 << endl;
		//cout << endl;
	}

	return 0;
}

/*
�׽�Ʈ���̽������� ������ ������,
�� �������� �������ε� Ǯ�� ��ü�� ������ ���������
�ð��ʰ��� �ߴ°ɷ� ���� �����ڰ� ���ʿ� �� Ǯ�̸� ���ο� �ΰ� �ð��� �� �� ����.
����Ʈ���� ���� ���� �� ���� �Ǿ���.
�ٵ� ��� �����϶��...���� �޶��̴� ���̽��ε�
*/