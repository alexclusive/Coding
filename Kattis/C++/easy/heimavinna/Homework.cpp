#include <iostream>
using namespace std;

int main() {
	int a, b, sum = 0;
	char sym;

	int n;
	while (cin >> n) {
		char ch;
		cin >> ch;
		if (ch == ';') {
			sum++;
		} else if (ch == '-') {
			int m;
			cin >> m;
			sum += m-n+1;
			cin >> ch;
		}
	}

	std::cout << sum << endl;

	return 0;
} 