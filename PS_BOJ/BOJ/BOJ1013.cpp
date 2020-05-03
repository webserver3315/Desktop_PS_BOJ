#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

/*
(100~1~|01)~
100~1~ 또는 01의 무작위 유한반복이면 잠수함으로 판정가능. 그 외엔 전부 false.
일단 처음에 10박던지 01박고, 전자면 그 이후 0000000000000111111111111식으로 나와야 함.
근데, 문제는 10001이면 마지막 01을 후자로 착각해서는 안되고 전자의 마무리로 인식해야함.

스트링 길이는 150이하. 즉, 시간적 걱정인 현재 솔루션으로는 크게 걱정안해도 된다.
*/

int t;
int idx = 0;
string sound;

bool IsInBoundary(int i) {
	if (i >= sound.size()) {
		return false;
	}
	return true;
}

bool FirstOne() {//10부터 시작이면
	if (sound.size() - idx < 2)
		return false;
	bool flag = false;
	while (sound[idx] == '0') {
		flag = true;
		idx++;
		if (!IsInBoundary(idx))
			return false;
	}
	while (sound[idx] == '1') {
		if (!flag)
			return false;
		idx++;
	}
	return true;
}

bool IsSubmarine() {//첫 두 글자 받아서 어떤 모드인지 결정하고, 들어가야한다.
	while (idx < sound.size()) {
		string fs;
		if (idx == sound.size() - 1)//버퍼에 1글자만 남으면 노답.
			return false;
		fs += sound[idx++];//마지막에 중간컷당할 가능성, 따라서 잘못참조될 가능성 대비해야함. 일단 최소 2개는 읽을 수 있어야 함.
		fs += sound[idx++];
		if (fs == "10") {
			if (FirstOne()) {
				continue;
			}
			else {
				return false;
			}
		}
		else if (fs == "01") {
			continue;
		}
		else if (fs == "00") {
			if (idx < 3) {
				return false;
			}
			if (sound[idx - 3] == '1' && sound[idx - 4] == '1') {
				fs = "10";
				idx--;
				if (FirstOne()) {
					continue;
				}
				else {
					return false;
				}
			}
			else
				return false;
		}
		else {
			return false;
		}
	}
	if (idx == sound.size())
		return true;
	return false;
}

int main() {
	cin >> t;
	while (t--) {
		idx = 0;
		cin >> sound;
		if (IsSubmarine())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}