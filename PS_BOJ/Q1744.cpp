/*
������
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> positive_list;
vector<int> negative_list;
int n, sum;
int start_idx;/*��������ε���*/

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0)
			positive_list.push_back(tmp);
		else
			negative_list.push_back(tmp);
	}
	sort(positive_list.begin(), positive_list.end());
	sort(negative_list.begin(), negative_list.end());

	int ns = (int)negative_list.size();
	int ps = (int)positive_list.size();

	for (int i = 0; i < ns; i++) {
		if (i + 1 < ns) {
			sum += negative_list[i] * negative_list[i+1];
			i++;
		}
		else {
			sum += negative_list[i];
		}
	}

	for (int i = ps-1; i >=0; i--) {
		if (i >= 1) {
			if (positive_list[i] == 1 || positive_list[i - 1] == 1) {
				sum += positive_list[i] + positive_list[i - 1];
				--i;
			}
			else {
				sum += positive_list[i] * positive_list[i - 1];/*������� �ǵ���� �۵��ϴ��� ��Ȯ��. �ȵǳ�. �и��ؼ� ����. �Ƹ� i -- �����ǰ� i, i-1 ���� �� �ѵ�..*/
				--i;
			}
		}
		else {
			sum += positive_list[i];
		}
	}
	cout << sum << endl;
	return 0;
}