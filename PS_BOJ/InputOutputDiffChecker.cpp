#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;


int t;
vector<string> input;
vector<string> output;


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		string tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	for (int i = 0; i < t; i++) {
		string tmp;
		cin >> tmp;
		output.push_back(tmp);
	}
	for (int i = 0; i < t; i++) {
		cout << input[i] << ' ' << output[i] << endl;
	}

	return 0;
}