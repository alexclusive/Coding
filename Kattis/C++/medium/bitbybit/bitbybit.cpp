#include <iostream>
#include <string>
using namespace std;

void printInt(int* integer) {
	for (int i = 31; i>= 0; --i) {
		if (integer[i] == 2)
			cout << '?';
		else
			cout << integer[i];
	}
	cout << endl;
}

void instructions(int* integer, char inst) {
	int i, j;
	if (inst == 'C') {           // CLEAR i
		cin >> i;
		integer[i] = 0;
	} else if (inst == 'S') {    // SET i
		cin >> i;
		integer[i] = 1;
	} else if (inst == 'O') {    // OR i j
		cin >> i >> j;
		if (integer[i] == 2 || integer[j] == 2)
			integer[i] = 2;
		else
			integer[i] |= integer[j];
	} else {                     // AND i j
		cin >> i >> j;
		if (integer[i] == 2 || integer[j] == 2)
			integer[i] = 2;
		else
			integer[i] &= integer[j];
	}
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) 
			break;
		int integer[] = { // 2 == unknown
			2, 2, 2, 2, 2, 2, 2, 2, 
			2, 2, 2, 2, 2, 2, 2, 2, 
			2, 2, 2, 2, 2, 2, 2, 2, 
			2, 2, 2, 2, 2, 2, 2, 2
		};
		string inst;
		while (n-- > 0) {
			cin >> inst;
			instructions(integer, inst[0]);
		}
		printInt(integer);
	}
}