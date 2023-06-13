#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string inputFile = "input";
	bool escape = false;
	if (argc > 1) {
		int idx = 1;
		while (idx < argc) {
			if (argv[idx] && argv[idx][0] == '-') {
				if (argv[idx][1] == 'f' && argv[++idx]) { 	// open file
					inputFile = argv[idx];
				} else if (argv[idx][1] == 'e') { 			// escape
					escape = true;
				}
			}
			idx++;
		}
	}
	
	ifstream in (inputFile);
	if (in.is_open()) {
		string line;
		if (escape) {
			string fileString = "";
			while (getline(in, line)) {
				fileString += line;
			}
			long pos = 0;
			string outString = "";
			while (char ch = fileString[pos++]) {
				if (ch == '"') {
					outString += '\\';
				}
				outString += ch;
			}
			cout << outString;
		} else {
			int lineNum = 1;
			while (getline(in, line)) {
				int i = lineNum++;
				string rowNumber = to_string(i);
				while (i < 1000) {
					rowNumber = '0' + rowNumber;
					i *= 10;
				}
				string outLine = "\"_NS#CyclicalRoute\",General,1,\"CONFIG/" + rowNumber + line + "\",,\"";
				cout << outLine << endl;
			}
		}
	}
}