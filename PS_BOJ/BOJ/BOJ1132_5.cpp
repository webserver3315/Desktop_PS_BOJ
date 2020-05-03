#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

int n;//주어질 문자열의 라인 수
int maxlen;//제공된 가장 긴 문자열의 길이
vector<string> strvct;
int freqTable[10][12];//[알파벳][12자리까지 자릿수별 출현횟수]
int allocated[10];//해당 알파벳이 뭘로 할당되었는지. 미할당시 -1.
bool allocatednum[10];//해당 숫자가 할당되어있는지.
int maxval;//답이 될 숫자.

/*
DFS로 탐색한다.
일단, 빈도테이블의 각 알파벳별 최우측원소부터 탐색한다.
일단 0이 아닌 수들은 다 반드시 할당된다.
그러나, 중복되는 수가 있을 경우, 판단을 차우측원소를 비교할 때까지 유보한다.
이 과정에서 재귀가 이루어질 예정이다.
만일, 두 알파벳의 빈도가 0번 인덱스까지 전부 동일한 원소값을 지닐 경우, 남은 가장 큰 값을 아무에게나 각각 할당한다.

아니, 생각해보니까 백트래킹은 제한적인 가지 거르기를 제외하면 완전탐색이었잖아?
일단 알파벳에 숫자를 할당하고, 아니면 빼는 과정을 10! 반복해야 한다.
생각해보니 아무리 최악의 경우라도 10!, 즉 360만가지 정도의 케이스만 비교하면 된다.

완전 브루트하게 풀어보았다.
*/

int ctoi(char c) {
	return c - 'A';//제대로 쓰였다면 반드시 양수가 나와야 함.
}

void makeTable() {//가장 우측 자릿수를 0번인덱스부터 채워나감. 각 알파벳별 출현횟수를 채워나간다.
	for (int strno = 0; strno < n; strno++) {
		for (int i = 0; i < 12; i++) {
			if (strvct[strno][i]<'A' || strvct[strno][i]>'J')
				break;
			int alphabet = ctoi(strvct[strno][i]);
			freqTable[alphabet][i]++;
		}
	}
}

int CalcSum() {//allocated 배열을 참조해서 합을 구한다.
	int sum = 0;
	for (int i = 0; i < 12; i++) {
		for (int a = 0; a < 10; a++) {
			sum += pow(10, i) * allocated[a] * freqTable[a][i];
		}
	}
	return sum;
}

void printAllocated() {
	for (int i : allocated) {
		cout << i << ' ';
	}
	cout << endl;
	return;
}

void DFS(int depth, int putted) {//할당완료된 누적횟수, 
	//cout << depth << " " << putted << endl;
	if (depth == 10) {
		//cout << "depth가 10이라, 총결산: ";
		//printAllocated();
		int tmpval = CalcSum();
		if (maxval < tmpval) {
			//cout << "maxval 업데이트 : " << tmpval << endl;
			maxval = tmpval;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {//0부터 9번 인덱스까지 할당 안된 인덱스 있으면 0부터 넣는다.
		if (allocated[i] != -1)//할당된 알파벳이라면 거른다
			continue;
		for (int j = putted; j < 10; j++) {//할당안된 알파벳이라면, 0부터 9까지 할당 안된 한자리 자연수를 할당한다.
			if (allocatednum[j] == true)
				continue;
			allocated[i] = j;
			//cout << "allocated[" << i << "] 에 " << j << " 할당! " << endl;
			allocatednum[j] = true;
			DFS(depth + 1, j + 1);
			//cout << "allocated[" << i << "] 에 " << j << " 해제! " << endl;
			allocated[i] = -1;
			allocatednum[j] = false;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < 10; i++) {
		allocated[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		string tmpstr;
		cin >> tmpstr;
		reverse(tmpstr.begin(), tmpstr.end());
		strvct.push_back(tmpstr);
		if (maxlen < tmpstr.length()) {
			maxlen = tmpstr.length();
		}
	}
	makeTable();
	DFS(0, 0);
	cout << maxval << endl;
	return 0;
}