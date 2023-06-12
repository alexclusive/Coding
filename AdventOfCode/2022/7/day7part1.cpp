#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

class Directory {
	public:
		string name;
		long size;
		// list<long> filesizes;
		Directory* parent;

	Directory() {
		size = -1;
		name = "/";
		parent = 0;
	}

	Directory(Directory* p) {
		size = -1;
		parent = p;
	}

	void addFile(long s) {
		size += s;
		if (parent != 0) {
			parent->addFile(s);
		}
	}
};

int findNum(string command) {
	for (int i = 0; i < command.length(); i++) {
		if (command[i] == ' ') {
			return stoi(command.substr(0, i));
		}
	}
	return 0;
}

int main() {
	string filename = "example";
	ifstream in (filename);
	if (in.is_open()) {
		string command;
		getline(in, command);
		Directory home = new Directory();
		Directory cur;
		long sum = 0;
		// for now, assume no double ups of directories
		// list<string> dirs;
		// dirs.push_front("/");
		do {
			if (command[0] == '$') {
				if (command[2] == 'c') { // cd <dir>
					if (command[5] == '/') { // cd /
						cur = home;
					} else if (command[5] == '.') {
						cur = cur.parent;  
					} else {
						// string dir = command.substr(5);
						// if (!dirs.contains(dir)) {
						//     dirs.push_front(dir);
						//     cur = new Directory(cur);
						// }
						cur = new Directory(cur);
					}
				} else if (command[2] == 'l') { // ls
					getline(in, command);
					while (command[0] != '$') {
						if (command[0] != 'd') {
							int size = findNum(command);
							cur.addFile(size);
						}
						getline(in, command);
					}
					if (cur.size <= 100000) {
						sum += cur.size;
					}
				}
			}
		} while (getline(in, command));
		cout << sum << endl;
	}
}