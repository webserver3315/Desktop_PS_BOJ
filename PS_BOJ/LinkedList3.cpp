#include <iostream>
#include <string>
/*
멍청한 짓이긴 하지만, B형 대비를 위해 연결리스트로 풀어보도록 하자.
*/

using namespace std;

const int NODE_SIZE = (int)3e5;
const int PUSH_BACK = 0;
const int PUSH_FRONT = 1;
const int INSERT = 2;
const int POP_BACK = 3;
const int POP_FRONT = 4;
const int ERASE = 5;

struct NODE {
	int prev;
	int next;
	int val;
};

struct MY_LIST {
	int pos;
	NODE nodes[NODE_SIZE + 2];
	int HEAD = NODE_SIZE;
	int TAIL = NODE_SIZE + 1;

	MY_LIST() {
		pos = 0;
		nodes[HEAD].next = TAIL;
		nodes[TAIL].prev = HEAD;
	}

	void push_back(int data) {
		int next = TAIL;
		int prev = nodes[TAIL].prev;

		nodes[pos].next = next;
		nodes[pos].prev = prev;
		nodes[pos].val = data;
		nodes[next].prev = pos;
		nodes[prev].next = pos;
		pos++;
	}
	void pop_back() {
		int target = nodes[TAIL].prev;
		int prev = nodes[target].prev;
		int next = nodes[target].next;

		nodes[prev].next = next;
		nodes[next].prev = prev;
	}

	void push_front(int data) {
		int next = nodes[HEAD].next;
		int prev = HEAD;

		nodes[pos].next = next;
		nodes[pos].prev = prev;
		nodes[pos].val = data;
		nodes[next].prev = pos;
		nodes[prev].next = pos;
		pos++;
	}

	void pop_front() {
		int target = nodes[HEAD].next;
		int prev = nodes[target].prev;
		int next = nodes[target].next;

		nodes[prev].next = next;
		nodes[next].prev = prev;
	}

	void erase(int p) {
		int target = nodes[HEAD].next;
		for (int i = 0; i < p; i++) {
			target = nodes[target].next;
		}
		int prev = nodes[target].prev;
		int next = nodes[target].next;
		nodes[prev].next = next;
		nodes[next].prev = prev;
	}

	void insert(int p, int data) {
		int next = nodes[HEAD].next;
		for (int i = 0; i < p; i++) {
			next = nodes[next].next;
		}
		int prev = nodes[next].prev;

		nodes[pos].val = data;
		nodes[pos].prev = prev;
		nodes[pos].next = next;
		nodes[prev].next = pos;
		nodes[next].prev = pos;
		pos++;
	}	
};

string order;
MY_LIST psdstk;//pseudo_stack written by linked list

int solve() {
	if (order == "NUM") {
		int tmp;
		cin >> tmp;
		psdstk.push_back(tmp);
	}
	else if (order == "POP") {
		psdstk.pop_back();
	}
	else if (order == "INV") {

	}
	else if (order == "DUP") {

	}
	else if (order == "SWP") {

	}
	else if (order == "ADD") {

	}
	else if (order == "SUB") {

	}
	else if (order == "MUL") {

	}
	else if (order == "DIV") {

	}
	else if (order == "MOD") {

	}
	else {
		cout << "ERROR" << endl;
		return -1;
	}
	return 0;
}

int main() {
	cin >> order;
	while (order != "QUIT") {
		solve();
	}


	return 0;
}