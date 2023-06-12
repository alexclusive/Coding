#include <iostream>
#include <cmath>
using namespace std;

int main() {
	short n, w, h, d, m; // width, height, diagonal
	cin >> n >> w >> h;
	d = sqrt(w*w + h*h);
	while (cin >> m) {
		if (m <= d) {
			cout << "DA" << endl;
		} else {
			cout << "NE" << endl;
		}
	}
}