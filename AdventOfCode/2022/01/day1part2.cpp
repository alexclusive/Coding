#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream in ("input");
	if (in.is_open()) {
		string line;
		int max[3];
		max[0] = 0;
		max[1] = 0;
		max[2] = 0;
		int sum = 0;
		while (getline(in, line)) {
			if (line == "") {
				if (sum > max[0]) {
					max[2] = max[1];
					max[1] = max[0];
					max[0] = sum;
				} else if (sum > max[1]) {
					max[2] = max[1];
					max[1] = sum;
				} else if (sum > max[2]) {
					max[2] = sum;
				}
				sum = 0;
			} else {
				sum += stoi(line);
			}
		}
		if (sum > max[0]) {
			max[2] = max[1];
			max[1] = max[0];
			max[0] = sum;
		} else if (sum > max[1]) {
			max[2] = max[1];
			max[1] = sum;
		} else if (sum > max[2]) {
			max[2] = sum;
		}
		cout << max[0]+max[1]+max[2];
	}
}