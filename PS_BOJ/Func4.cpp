#include <bits/stdc++.h>
using namespace std;

int func4(int edx, int esi, int edi) {
	int eax = edx;//4
	eax -= esi;//6
	int ecx = eax;//8
	ecx >>= 0x1f;//10
	ecx += eax;//13
	ecx >>= 1;//15
	ecx += esi;//17
	if (ecx > edi) {//19,21
		edx = ecx - 1;//37
		eax = func4(edx, esi, edi);//40
		eax += eax;//45
		return eax;//47,32,36
	}
	else {//23
		eax = 0;//23
		if (ecx < edi) {//28, 30
			esi = ecx + 1;//49
			eax = func4(edx, esi, edi);//52
			eax = eax * 2 + 1;//57
			return eax;
		}
		else {//32
			return eax;
		}
	}
}

int main() {
	for (int i = 0; i < 15; i++) {//eax를 2를 만들어야한다.
		printf("if edi is %d, eax = %d\n", i, func4(14, 0, i));
	}
	return 0;
}