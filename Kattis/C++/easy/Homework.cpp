#include <iostream>
using namespace std;

int main() {
    int a, b, sum = 0;
    char sym;

    while (cin >> a >> sym) {
        if (sym == '-') {
            cin >> b >> sym;
            sum += b-a + 1;
        } else if (sym == ';') {
            sum++;
        }
    }

    std::cout << sum << endl;

    return 0;
} 