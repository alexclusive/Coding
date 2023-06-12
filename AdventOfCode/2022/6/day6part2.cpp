#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool repeats(string str) {
	// cout << str << endl;
	for (int i = 0; i < str.length(); i++) {
		for (int j = i+1; j < str.length(); j++) {
			// cout << "i " << str[i] << " j " << str[j] << endl;
			if (str[i] == str[j]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	string filename = "input";
	ifstream in (filename);
	if (in.is_open()) {
		string input;
		getline(in, input);

		for (int i = 13; i < input.length(); i++) {
			if (!repeats(input.substr(i-13, 14))) {
				cout << i+1 << endl;
				break;
			}
		}
		cout << "end of stream" << endl;
	}
}