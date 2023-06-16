#include <iostream>
#include <string>
#include <vector>

#include "../../../include/aocBase.h"
using namespace std;

int main() {
	string filename = "example";
	vector<string> file = readFile(filename);
	for (auto row : file) {
		cout << row << endl;
	}
}