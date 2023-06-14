#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	bool input = false;
	string filename = "example";
	if (input) {
		filename = "input";
	}
	ifstream in (filename);
	if (in.is_open()) {
		int size = 5;
		if (input) {
			size = 99;
		}

		int **arr = new int*[size];
		for(int i = 0; i < size; ++i) {
			string tmp;
			getline(in, tmp);
			arr[i] = new int[size];
			for (int j = 0; j < size; j++) {
				arr[i][j] = tmp[j] - '0';
			}
			cout << endl;
		}

		int count = 0;
		for (int x = 1; x < size-1; x++) {
			for (int y = 1; y < size-1; y++) {
				int current = arr[x][y];

				bool obstructed = false;
				for (int i = 0; i < x; i++) {
					cout << i << ' ' << y << endl;
					// cout << current << ' ' << arr[i][y] << endl;
					if (current <= arr[i][y]) {
						// cout << "obstructed" << endl;
						obstructed = true;
						break;
					}
				}
				// if (!obstructed) {
				//     count++;
				//     continue;
				// }
				// cout << endl;
				// for (int x = i + 1; x < size; x++) { // right
				//     cout << current << ' ' << arr[x][j] << endl;
				//     if (current <= arr[x][j]) {
				//         cout << "obstructed" << endl;
				//         obstructed = true;
				//         break;
				//     }
				// }
				// if (!obstructed) {
				//     count++;
				//     continue;
				// }
				// cout << endl;
				// for (int y = 0; y < j; y++) { // top
				//     cout << current << ' ' << arr[i][y] << endl;
				//     if (current <= arr[i][y]) {
				//         cout << "obstructed" << endl;
				//         obstructed = true;
				//         break;
				//     }
				// }
				// if (!obstructed) {
				//     count++;
				//     continue;
				// }
				// cout << endl;
				// for (int y = j + 1; y < size; y++) { // bottom
				//     cout << current << ' ' << arr[i][y] << endl;
				//     if (current <= arr[i][y]) {
				//         cout << "obstructed" << endl;
				//         obstructed = true;
				//         break;
				//     }
				// }
				// if (!obstructed) {
				//     count++;
				//     continue;
				// }
				// cout << endl;
			}
		}
		cout << endl << endl << count << endl;
		cout << (count + (size - 1) * 4) << endl;
	}
}