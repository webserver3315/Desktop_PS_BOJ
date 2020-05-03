/*
ȸ�ǽ� ����
*/

/*
ȸ�Ǵ� ����int ����int�� ������ pair�� �����ϰ�
2��° ���ڸ� key�� �� �ּ����� �̿��� �켱���� ť�� �����Ѵ�
�ٸ�, �Ǻ��������� �˵� ù ���ڰ� ������ 2��° ���ں��� �۴ٸ� �Ⱒ�̴�. �ٽ� ���Ѵ�.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int > Time;

int n, cnt;
Time kouhou;
Time now = pair<int, int>(0, 0);

//priority_queue< pair<int, int >, vector<int>, pair_second_compare() > TimeList;
priority_queue<Time, vector<Time>, greater<Time>> pq;/*�ּ����̴�*/

int main() {
	cin >> n;
	while (n--) {
		int fir, sec;
		scanf("%d %d", &fir, &sec);
		pq.push(Time(sec, fir));/*����!!! ù �׿� ENDTIME��, ���׿� STARTTIME�� �Էµȴ�!*/
	}
	while (!pq.empty()) {
		kouhou = pq.top();
		if (kouhou.second < now.first) {/*�˵� �ĺ�ȸ���� ���۽ð��� ���� ȸ������ð����� �̸� ���*/
			pq.pop();
		}
		else {
			now = kouhou;
			pq.pop();
			++cnt;
		}
	}
	printf("%d\n", cnt);
	return 0;
}