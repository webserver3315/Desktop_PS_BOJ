#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

int n;//�־��� ���ڿ��� ���� ��
int maxlen;//������ ���� �� ���ڿ��� ����
vector<string> strvct;
int freqTable[10][12];//[���ĺ�][12�ڸ����� �ڸ����� ����Ƚ��]
int allocated[10];//�ش� ���ĺ��� ���� �Ҵ�Ǿ�����. ���Ҵ�� -1.
bool allocatednum[10];//�ش� ���ڰ� �Ҵ�Ǿ��ִ���.
int maxval;//���� �� ����.

/*
DFS�� Ž���Ѵ�.
�ϴ�, �����̺��� �� ���ĺ��� �ֿ������Һ��� Ž���Ѵ�.
�ϴ� 0�� �ƴ� ������ �� �ݵ�� �Ҵ�ȴ�.
�׷���, �ߺ��Ǵ� ���� ���� ���, �Ǵ��� ���������Ҹ� ���� ������ �����Ѵ�.
�� �������� ��Ͱ� �̷���� �����̴�.
����, �� ���ĺ��� �󵵰� 0�� �ε������� ���� ������ ���Ұ��� ���� ���, ���� ���� ū ���� �ƹ����Գ� ���� �Ҵ��Ѵ�.

�ƴ�, �����غ��ϱ� ��Ʈ��ŷ�� �������� ���� �Ÿ��⸦ �����ϸ� ����Ž���̾��ݾ�?
�ϴ� ���ĺ��� ���ڸ� �Ҵ��ϰ�, �ƴϸ� ���� ������ 10! �ݺ��ؾ� �Ѵ�.
�����غ��� �ƹ��� �־��� ���� 10!, �� 360������ ������ ���̽��� ���ϸ� �ȴ�.

���� ���Ʈ�ϰ� Ǯ��Ҵ�.
*/

int ctoi(char c) {
	return c - 'A';//����� �����ٸ� �ݵ�� ����� ���;� ��.
}

void makeTable() {//���� ���� �ڸ����� 0���ε������� ä������. �� ���ĺ��� ����Ƚ���� ä��������.
	for (int strno = 0; strno < n; strno++) {
		for (int i = 0; i < 12; i++) {
			if (strvct[strno][i]<'A' || strvct[strno][i]>'J')
				break;
			int alphabet = ctoi(strvct[strno][i]);
			freqTable[alphabet][i]++;
		}
	}
}

int CalcSum() {//allocated �迭�� �����ؼ� ���� ���Ѵ�.
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

void DFS(int depth, int putted) {//�Ҵ�Ϸ�� ����Ƚ��, 
	//cout << depth << " " << putted << endl;
	if (depth == 10) {
		//cout << "depth�� 10�̶�, �Ѱ��: ";
		//printAllocated();
		int tmpval = CalcSum();
		if (maxval < tmpval) {
			//cout << "maxval ������Ʈ : " << tmpval << endl;
			maxval = tmpval;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {//0���� 9�� �ε������� �Ҵ� �ȵ� �ε��� ������ 0���� �ִ´�.
		if (allocated[i] != -1)//�Ҵ�� ���ĺ��̶�� �Ÿ���
			continue;
		for (int j = putted; j < 10; j++) {//�Ҵ�ȵ� ���ĺ��̶��, 0���� 9���� �Ҵ� �ȵ� ���ڸ� �ڿ����� �Ҵ��Ѵ�.
			if (allocatednum[j] == true)
				continue;
			allocated[i] = j;
			//cout << "allocated[" << i << "] �� " << j << " �Ҵ�! " << endl;
			allocatednum[j] = true;
			DFS(depth + 1, j + 1);
			//cout << "allocated[" << i << "] �� " << j << " ����! " << endl;
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