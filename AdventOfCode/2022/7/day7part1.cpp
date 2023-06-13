#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string getName(string cmd) {
	int i = 0;
	while (i < cmd.size()) {
		if (cmd[i] == ' ') {
			return cmd.substr(i+1);
		}
		i++;
	}
}

long getSize(string cmd) {
	int i = 0;
	while (i < cmd.size()) {
		if (cmd[i] == ' ') {
			return stol(cmd.substr(0, i));
		}
		i++;
	}
}

class File {
	public:
		string name = "";
		File* parent = NULL;

		bool directory = false;
		vector<File> files;

		long size = 0;

		long getSize() {
			if (directory) {
				long dirSize = 0;
				for (File file : files) {
					dirSize += file.getSize();
				}
				return dirSize;
			} else {
				return size;
			}
		}

		File* findFile(string name) {
			for (int i = 0; i < files.size(); i++) {
				if (files[i].name == name) {
					return &files[i];
				}
			}
			return this;
		}

		void print(string indent) {
			cout << indent << "- " << name << " (" << size << ")" << endl;
			for (File file : files) {
				file.print(indent + "\t");
			}
		}

		void calculateSize() {
			long currentSize = 0;
			for (auto file : files) {
				if (file.directory) {
					file.calculateSize();
				}
				currentSize += file.size;
			}
			cout << name << " " << currentSize << endl;
			if (directory) {
				size = currentSize;
			}
		}

		long sumLessThan(long less) {
			long sum = 0;
			if (directory) {
				if (size < less) {
					sum += size;
				}
				for (auto file : files) {
					if (file.directory) {
						sum += file.sumLessThan(less);
					}
				}
			}
			return sum;
		}
};

void part1(ifstream &in) {
	File outermost;
	outermost.name = "/";

	File* current = &outermost;

	string command;
	while (getline(in, command)) {
		// cout << command << endl;
		if (command[0] == '$') {
			if (command[2] == 'c') {
				string dirName = command.substr(5);
				if (dirName == "/") {			// home
					current = &outermost;
				} else if (dirName == "..") {	// out
					current = current->parent;
				} else {						// in
					current = current->findFile(dirName);
				}
			}
			// ignore "ls"
		} else {
			File newFile;
			if (command.substr(0,3) == "dir") {
				newFile.name = command.substr(4);
				newFile.parent = current;
			} else {
				newFile.name = getName(command);
				newFile.size = getSize(command);
				newFile.parent = current;
			}
			current->files.push_back(newFile);
		}
	}

	outermost.calculateSize();
	// outermost.print("");
	
	cout << "Sum: " << outermost.sumLessThan(10000) << endl;
}

int main() {
	string filename = "example";
	ifstream in (filename);
	
	if (in.is_open()) {
		part1(in);
	}
}