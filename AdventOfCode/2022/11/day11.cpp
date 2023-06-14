#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
using namespace std;

class Monkey {
	public:
		int id = 0;
		std::vector<long long> items;
		
		// operation
		bool opOld = false;
		int opMod = 0; // what to +/* by
		bool opMult = false; // + or *

		// test
		int testBy = 1;
		int ifTrue = 0;
		int ifFalse = 0;

		long long inspections = 0;

		string stringItems() {
			string str = "";
			for (int i = 0; i < items.size(); i++) {
				string end = ", ";
				if (i == items.size()-1) {
					end = "";
				}
				str += to_string(items[i]) + end;
			}
			return str;
		}

		string stringOperation() {
			string str = "new = old ";
			if (opMult) {
				str.append("* ");
			} else {
				str.append("+ ");
			}
			if (opOld) {
				str.append("old");
			} else {
				str.append(to_string(opMod));
			}
			return str;
		}

		long long doOp(long long item) {
			if (opOld) {
				if (opMult) {
					return item * item;
				}
				return item + item;
			}
			if (opMult) {
				return item * opMod;
			}
			return item + opMod;
		}

		void inspect(long div, bool part1) {
			++inspections;
			long long item = doOp(items.front());
			if (part1) {
				item /= 3;
			}
			// if (item < 0) {
			// 	cout << "Monkey " << id << " holding " << items.front() << " that became " << item << endl;
			// 	cout << stringOperation() << endl;
			// 	int a = 0/0;
			// }
			items.at(0) = item % div;
		}

		int check() {
			if (items.front() % testBy == 0) {
				return ifTrue;
			}
			return ifFalse;
		}
};

class Group {
	public:
		vector<Monkey> monkeys;
		long div = 1; // avoid overflow by modding by the product of all division checks

		void printDefs() {
			for (auto m : monkeys) {
				cout << "Monkey " << m.id << ":" << endl;
				cout << "  Starting items: " << m.stringItems() << endl;
				cout << "  Operation: " << m.stringOperation() << endl;
				cout << "  Test: divisible by " << m.testBy << endl;
				cout << "    If true: throw to monkey " << m.ifTrue << endl;
				cout << "    If false: throw to monkey " << m.ifFalse << endl;
				cout << endl;
			}
		}

		void print() {
			for (int i = 0; i < monkeys.size(); i++) {
				Monkey m = monkeys.at(i);
				cout << "Monkey " << m.id << ", inspected " << m.inspections << " holds " << m.stringItems() << endl;
			}
		}

		long long getBusiness() {
			long long top = 0;
			long long second = 0;
			for (int i = 0; i < monkeys.size(); i++) {
				long long insp = monkeys[i].inspections;
				if (insp > top) {
					second = top;
					top = insp;
				} else if (insp > second) {
					second = insp;
				}
			}
			long long mult = top * second;
			// cout << top << " * " << second << " = " << mult << endl;
			return mult;
		}

		void doRound(int round, bool part1) {
			for (int i = 0; i < monkeys.size(); ++i) {
				// cout << "\tMonkey " << monkeys[i].id << endl;
				while (monkeys[i].items.size() > 0) {
					// cout << round << " monkey " << monkeys[i].id << ": item " << monkeys[i].items.front() << endl;
					monkeys[i].inspect(div, part1);
					int to = monkeys[i].check();
					monkeys.at(to).items.push_back(monkeys[i].items.front());
					monkeys[i].items.erase(monkeys[i].items.begin());
				}
			}
		}

		string replace(string str, string remove) {
			return std::regex_replace(str, std::regex(remove), "");
		}

		string trimStart(string str) {
			auto begin = str.find_first_not_of(" ");
			return str.substr(begin);
		}

		vector<string> split(string str) {
			vector<string> line;
			string word = "";
			for (auto x : str) {
				if (x == ' ') {
					line.push_back(word);
					word = "";
				} else {
					word += x;
				}
			}
			line.push_back(word);
			return line;
		}

		vector<string> fixLine(string line) {
			vector<string> ret;
			if (line.size() > 0) {
				line = replace(line, ":");
				line = replace(line, ",");
				line = trimStart(line);
				ret = split(line);
			}
			return ret;
		}

		void read(ifstream &in) {
			string startLine = "";
			Monkey curr;
			while (getline(in, startLine)) {
				vector<string> line = fixLine(startLine);
				if (line.size() == 0) {
					continue;
				}
				
				if (line.at(0) == "Monkey") {

					curr.id = stoi(line.at(1));

				} else if (line.at(0) == "Starting") {

					vector<long long> items;
					for (int i = 2; i < line.size(); i++) {
						items.push_back(stoi(line.at(i)));
					}
					curr.items = items;

 				} else if (line.at(0) == "Operation") {

					curr.opMult = line.at(4) == "*";
					curr.opOld = line.at(5) == "old";
					if (!curr.opOld) {
						curr.opMod = stoi(line.at(5));
					}
					
				} else if (line.at(0) == "Test") {

					curr.testBy = stoi(line.at(3));
					div *= curr.testBy;
					
				} else if (line.at(0) == "If") {
					
					if (line.at(1) == "true") {
						curr.ifTrue = stoi(line.at(line.size()-1));
					} else {
						curr.ifFalse = stoi(line.at(line.size()-1));
						monkeys.push_back(curr);
					}
				}
			}
		}
};

long long getBusiness(Group group, int rounds, bool part1) {
	float r = rounds;
	for (int i = 1; i <= rounds; ++i) {
		// cout << "Round " << i << ": " << ((i/r)*100) << "%" << endl;
		group.doRound(i, part1);
		if (i == 1 || i == 20 || i%1000 == 0) {
			cout << "== After round " << i << " ==" << endl;
			group.print();
		}
	}
	// group.print();
	return group.getBusiness();
}

int main() {
	string filename = "input";
	ifstream in (filename);
	
	if (in.is_open()) {
		Group group;
		group.read(in);
		cout << group.div << endl;
		// group.printDefs();
		// group.print();
		// cout << "Business (1): " << getBusiness(group, 20, true) << endl;
		// cout << "Business (2): " << getBusiness(group, 10000, false) << endl;
	}
}