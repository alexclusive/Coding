#include <iostream>
using namespace std;

int main() {
    int a, b, sum = 0;
    char sym;

    cin >> a;
    while (cin >> sym) {
        if (sym == '-') {
            cin >> b;
            sum += b-a + 1;
        } else if (sym == ';') {
            sum++;
        }
    }

    std::cout << sum << endl; // doesn't count the last number if it is after a semicolon

    return 0;
}