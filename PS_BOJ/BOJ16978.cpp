/*
������ ���� 22
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct node {
	int val;
	int start_node, end_node;//[start,end)�� ����
	int nodeNum;
	int leftNum, rigntNum;//��,�������ڽ� ����ȣ
	node(int start_node, int end_node, int nodeNum) {
		val = 0;
		this->start_node = start_node;
		this->end_node = end_node;
		this->nodeNum = nodeNum;
		leftNum = -1; rigntNum = -1;
	}
};

struct persistentSegTree {

};

int main() {


	return 0;
}