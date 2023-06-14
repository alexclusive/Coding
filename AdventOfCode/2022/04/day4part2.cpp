#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool contained(int min1, int max1, int min2, int max2) {
	return min1 >= min2 && min1 <= max2
		|| max1 >= min2 && max1 <= max2;
}

int main() {
	ifstream in ("input");
	if (in.is_open()) {
		int sum = 0;
		int min1, min2, max1, max2;
		char buf;
		while(in >> min1 >> buf >> max1 >> buf >> min2 >> buf >> max2) {
			// cout << min1 << '-' << max1 << ',' << min2 << '-' << max2 << endl;
			if (contained(min1,max1,min2,max2) || contained(min2,max2,min1,max1)) {
				++sum;
			}
		}
		cout << sum;
		in.close();
	}
}