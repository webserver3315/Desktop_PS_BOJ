#include <iostream>
using namespace std;

const int PN = 23;
const int MAX = 10000;

int table[MAX][50];
int hash_size = 0;
char hash_raw[30000][100];

char input[30000][100];

bool strcmp(char* a, char* b) {//������ true
	int idx = 0;
	while (a[idx]) {
		if (a[idx] != b[idx]) {
			return false;
		}
		idx++;
	}
	return true;
}

void strcpy(char* a, char* b) {//b�� a�� ����
	int idx = 0;
	while (b[idx]) {
		a[idx] = b[idx];
		idx++;
	}
	a[idx] = 0;
	return;
}

unsigned int get_key(char str[]) {
	unsigned int key = 0, p = 1;

	for (int i = 0; str[i] != 0; ++i) {
		key += (str[i] * p);
		p *= PN;
	}

	return (key % MAX);
}

struct NODE {
	int val;
	char key[30];
	NODE* next;
}LIST[100000];

struct BUCKET {
	int cnt;
	NODE* TAIL;
}HashTable[MAX];

int pos;

NODE* makenode() {
	return &LIST[pos++];
}

void add(int val, char* key) {
	unsigned int realkey = get_key(key);
	NODE* addr = makenode();
	addr->val = val;
	strcpy(addr->key, key);
	if (HashTable[realkey].cnt!=0) {
		addr->next = HashTable[realkey].TAIL;
	}
	HashTable[realkey].TAIL = addr;
	HashTable[realkey].cnt++;
	return;
}

int find(char* key) {//�ش� Ű�� �ش��ϴ� value�� ��ȯ
	unsigned int realkey = get_key(key);
	NODE* target = HashTable[realkey].TAIL;
	while (target != 0) {
		if (strcmp(target->key, key)) {
			return target->val;
		}
		target = target->next;
	}
	return -1;
}

bool del(char* key) {
	unsigned int realkey = get_key(key);
	NODE* target = HashTable[realkey].TAIL;
	NODE* prev = 0;
	while (target != 0) {
		if (strcmp(target->key, key)) {//����
			if (target != HashTable[realkey].TAIL) {//���� ���� �ִ� ���Ұ� ������ �ƴϸ� prev ���Ұ� ��������Ƿ�
				prev->next = target->next;
				HashTable[realkey].cnt--;
				return true;
			}
			else {
				HashTable[realkey].TAIL = target->next;
				HashTable[realkey].cnt--;
				return true;
			}
		}
		else {
			prev = target;
			target = target->next;
		}
	}
	return false;//0 ������ ���
}

int main() {
	char orders[8][30] = { "aaa","bbb","ccc","ddd","eee","fff","ggg","hhh" };
	for (int i = 0; i < 8; i++) {
		add(i + 1, orders[i]);
	}
	for (int i = 0; i < 8; i++) {
		cout << find(orders[i]) << endl;
	}
	for (int i = 7; i >= 0; i--) {
		del(orders[i]);
		cout << find(orders[i]) << endl;
	}

	return 0;
}