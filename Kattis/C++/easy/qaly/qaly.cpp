#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    float q, y;
    float quality = 0;
    while (num-- > 0) {
        cin >> q;
        cin >> y;
        quality += q * y;
    }
    cout << quality << endl;
}