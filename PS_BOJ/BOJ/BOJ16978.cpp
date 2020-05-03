/*
수열과 쿼리 22
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct node {
	int val;
	int start_node, end_node;//[start,end)의 구간
	int nodeNum;
	int leftNum, rigntNum;//왼,오른쪽자식 노드번호
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