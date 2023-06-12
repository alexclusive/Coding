#include <iostream>
using namespace std;

int main() {
	int X, months;
	cin >> X >> months;

	int spent;
	int totalSpent = 0;
	while (cin >> spent) {
		totalSpent += spent;
	}
	cout << X*(months+1) - totalSpent;
}