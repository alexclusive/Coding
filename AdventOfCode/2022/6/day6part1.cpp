#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string filename = "input";
	ifstream in (filename);
	if (in.is_open()) {
		string input;
		getline(in, input);

		for (int i = 3; i < input.length(); i++) {
			// 4th is not repeated
			if (input[i] != input[i-1] &&
				input[i] != input[i-2] &&
				input[i] != input[i-3]) {
					// 3rd is not repeated
					if (input[i-1] != input[i-2] &&
						input[i-1] != input[i-3]) {
							// 2nd not repeated
							if (input[i-2] != input[i-3]) {
								cout << i+1 << endl;
								break;
							}
					}
					
			}
		}
		cout << "end of stream" << endl;
	}
}