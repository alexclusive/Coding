#include <iostream>
#include <cstring>
using namespace std;

int main() {
	// version 1
	// runtime error for Kattis, can't recreate
	// char * s;
	// cin >> s;
	// int e = (strlen(s)-2) << 1;
	// cout << 'h';
	// while (e--) {
	//     cout << 'e';
	// }
	// cout << 'y';

	// version 2
	string s;
	cin >> s;
	cout << "h" + string((s.size()-2)<<1,'e') + "y";
}