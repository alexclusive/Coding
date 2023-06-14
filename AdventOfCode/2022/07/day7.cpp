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
			for (int i = 0; i < files.size(); i++) {
				files[i].print(indent + "\t");
			}
		}

		void calculateSize() {
			// cout << "name: '" << name << "', directory: " << directory << endl;
			if (directory) {
				long sum = 0;
				for (int i = 0; i < files.size(); i++) {
					files[i].calculateSize();
					sum += files[i].size;
				}
				size = sum;
				// cout << "'" << name << "': " << size << endl;
			}
		}

		long sumLessThan(long less) {
			if (!directory) {
				return 0;
			}

			long thisSum = 0;
			long ret = 0;
			for (int i = 0; i < files.size(); i++) {
				ret += files[i].sumLessThan(less);
				thisSum += files[i].size;
			}

			if (thisSum < less) {
				ret += thisSum;
			}

			return ret;
		}

		void findGreater(long great, vector<File*> &candidates) {
			if (size >= great) {
				// cout << "Dir '" << name << "' is " << size << endl;
				candidates.push_back(this);
			}
			for (int i = 0; i < files.size(); i++) {
				if (files[i].directory) {
					files[i].findGreater(great, candidates);
				}
			}
		}
};

File readIn(ifstream &in) {
	File outermost;
	outermost.name = "/";
	outermost.directory = true;

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
				newFile.directory = true;
				newFile.parent = current;
			} else {
				newFile.name = getName(command);
				newFile.size = getSize(command);
				newFile.parent = current;
			}
			current->files.push_back(newFile);
		}
	}

	return outermost;
}

void part1(File outermost) {
	cout << "Sum: " << outermost.sumLessThan(100000) << endl;
}

void part2(File outermost) {
	long disk = 70000000;

	long unused = disk - outermost.size;
	long need = 30000000 - unused; // we want to delete this much at least

	// cout << "Used: " << used << endl;
	// cout << "Unused: " << unused << endl;
	// cout << "Delete: " << need << endl;

	vector<File*> candidates;
	outermost.findGreater(need, candidates);
	// cout << "size " << candidates.size() << endl;
	long min = outermost.size;
	for (auto file : candidates) {
		// cout << "File '" << file->name << "': " << file->size << endl;
		if (file->size < min) {
			min = file->size;
		}
	}
	cout << "Delete: " << min << endl;
}

int main() {
	string filename = "input";
	ifstream in (filename);
	
	if (in.is_open()) {
		File outer = readIn(in);
		outer.calculateSize();
		// outer.print("");
		part1(outer);
		part2(outer);
	}
}