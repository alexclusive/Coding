#include <iostream>
using namespace std;

unsigned int ssd(int b, int n) {
    int sum = 0;
    while (n) {
        sum += (n%b) * (n%b);
        n /= b;
    }
    return sum;
}

int main() {
    unsigned int p, k, b, n;
    cin >> p;
    while (cin >> k >> b >> n) {
        cout << k << ' ' << ssd(b, n) << endl;
    }
}