#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example";
    ifstream in (filename);
    if (in.is_open()) {
        int size = 0;
        string tmp;
        getline(in, tmp);
        size = tmp.size(); // hopefully its square

        string arr[size];
        arr[0] = tmp;
        for (int i = 1; i < size; i++) {
            getline(in, arr[i]);
            // cout << arr[i] << endl;
        }

        int count = 0;
        for (int i = 1; i < size-1; i++) {
            for (int j = 1; j < size-1; j++) {
                int current = arr[i][j] - '0';

                bool visible = true;
                for (int x = 0; x < j; x++) { // left
                    if (current <= arr[i][x] - '0') {
                        cout << x << i << ' ';
                        cout << current << ' ' << arr[i][x] - '0';
                        visible = false;
                        break;
                    }
                }
                cout << endl;
                if (!visible) { // don't need to check if it was not visible
                    for (int x = j + 1; x < size; x++) { // right
                        if (current <= arr[i][x] - '0') {
                            visible = false;
                            break;
                        }
                    }
                }
                if (!visible) {
                    for (int y = 0; y < i; y++) { // top
                        if (current <= arr[y][j] - '0') {
                            visible = false;
                            break;
                        }
                    }
                }
                if (!visible) {
                    for (int y = i + 1; y < size; y++) { // bottom
                        if (current <= arr[y][j] - '0') {
                            visible = false;
                            break;
                        }
                    }
                }

                if (visible) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}