#include <iostream>
#include <fstream>
#include <string>
#include "../../include/myHeader.h"
using namespace std;

// #define boolToString(b) (b?"true":"false")

string settableString = "default";
int settableInt = 1;
bool settableBool = false;

void readArgs(int argc, char** argv) {
	if (argc > 1) { // has any arguments
		int i = 1;
		while (i < argc) {
			char* current = argv[i++];
			if (current && current[0] == '-') {
				// we have an option
				char* arg = argv[i];
				switch (current[1]) {
					case 's':
						// option "-s"
						// arg is string
						if (arg) {
							i++;
							settableString = arg;
						}
						break;
					case 'i':
						// option "-i"
						// arg is int
						if (arg) {
							i++;
							settableInt = atoi(arg);
						}
						break;
					case 'b':
						// option "-b"
						// no arg
						settableBool = true;
						break;
				}
			}
		}
	}
}

void printArgs() {
	cout << "String: \"" << settableString << "\"" << endl;
	cout << "Int: " << settableInt << "" << endl;
	cout << "Bool: " << boolToString(settableBool) << endl;
}

int main(int argc, char *argv[]) {
	readArgs(argc, argv);
	printArgs();
}