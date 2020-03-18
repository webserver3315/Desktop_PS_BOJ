#include <bits/stdc++.h>
using namespace std;


int main() {
	int cnt = 0;
	while (1) {		
		int tmp;
		cout << "Input the weight of the egg = ";
		cin >> tmp;
		if (tmp >= 300)
			cout << "I have " << cnt++ << " eggs in my eggbox!" << endl;
		else//to use break continue command
			if (cnt >= 30)
				break;
			else
				continue;
	}
	cout << "The eggbox is full!" << endl;
	return 0;
}