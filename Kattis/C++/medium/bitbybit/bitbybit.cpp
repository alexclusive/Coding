#include <iostream>
using namespace std;

int main() {
    char integer[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1, -1, -1
    };

    char n;
    cin >> n;
    while (n != 0) {
        --n;
        string inst;
        cin >> inst;
        char i, j;
        if (inst[0] == 'C') {           // CLEAR i
            cin >> i;
            integer[i] = 0;
        } else if (inst[0] == 'S') {    // SET i
            cin >> i;
            integer[i] = 1;
        } else if (inst[0] == 'O') {    // OR i j
            cin >> i >> j;
            integer[i] |= integer[j];
        } else {                        // AND i j
            cin >> i >> j;
            integer[i] &= integer[j];
        }
        cout << n << endl;
        if (n == 0) {
            cin >> n;
        }
    }

}