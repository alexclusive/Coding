#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    bool odd = true;
    string str;
    while (cin >> str) {
        if (odd)
            cout << str << endl;
        odd = !odd;
    }
}