#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define pci pair<char,int>
using namespace std;

int n;
vector<string> TasuMono;
int AlphabetKazu[12][10];//자릿수별로 어느 알파벳이 어느 빈도로 나타났는지 유지
int Allocated[10];//A부터 J까지가 어떤 수로 할당되었는지를 나타냄
bool visited[10];
vector<pci> psivct;
/*
101
110
011
*/

//AllocatedValue(0,9);
void AllocateValue(int idx, int kouhou) {//현재 자리, 할당될 수
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
			할당기준: 최좌측자리에서 최빈알파벳순으로 수를 배정.
			그러나, 최빈알파벳이 둘 이상일 경우, 다음 칸에서 둘 중 어느 알파벳이 더 빈출되는지 체크.
			만일 abc acb bac 처럼 총합이 a+b+c로 전부 동일할 경우를 대비해, 마지막자리까지 빈출도가 동일할 경우 남은 수에서 뽑아서 배정.
			>>>재귀가 적절해보임.
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