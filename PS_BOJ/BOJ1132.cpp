#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define pci pair<char,int>
using namespace std;

int n;
vector<string> TasuMono;
int AlphabetKazu[12][10];//�ڸ������� ��� ���ĺ��� ��� �󵵷� ��Ÿ������ ����
int Allocated[10];//A���� J������ � ���� �Ҵ�Ǿ������� ��Ÿ��
bool visited[10];
vector<pci> psivct;
/*
101
110
011
*/

//AllocatedValue(0,9);
void AllocateValue(int idx, int kouhou) {//���� �ڸ�, �Ҵ�� ��
	for (int i = kouhou; i >= 0; i--) {
		
	}
}

void solve() {
	for (int i = 0; i < TasuMono.size(); i++) {
		string str = TasuMono[i];
		for (int j = 0; j < str.length(); j++) {
			AlphabetKazu[j][str[j]-'A']++;
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 10; j++) {
			/*
			�Ҵ����: �������ڸ����� �ֺ���ĺ������� ���� ����.
			�׷���, �ֺ���ĺ��� �� �̻��� ���, ���� ĭ���� �� �� ��� ���ĺ��� �� ����Ǵ��� üũ.
			���� abc acb bac ó�� ������ a+b+c�� ���� ������ ��츦 �����, �������ڸ����� ���⵵�� ������ ��� ���� ������ �̾Ƽ� ����.
			>>>��Ͱ� �����غ���.
			*/
		}
	}


}

int main() {
	cin >> n;
	while (n--) {
		string tmp;
		cin >> tmp;
		TasuMono.push_back(tmp);
	}
	solve();

	return 0;
}