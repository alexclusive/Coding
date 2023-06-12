#include <iostream>
#include <string>
using namespace std;

string translate(string str) {
	
	return str;
}

int main() {
	int n;
	cin >> n;
	string str;
	for(int i = 1; i<=n; i++) {
		cout << "Case #" << i << ": ";
		getline(std::cin, str);
		cout << translate(str) << endl;
	}
}