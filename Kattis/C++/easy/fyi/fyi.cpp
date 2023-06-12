#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string num;
	cin >> num;
	if (num[0] == '5' && num[1] == '5' && num[2] == '5')
		cout << 1;
	else
		cout << 0;
}