#include <iostream>
using namespace std;

int main() {
    uint_least16_t kg, q, r, b, kt, p;
    cin >> kg >> q >> r >> b >> kt >> p;
    std::cout << 1-kg << ' ' << 1-q << ' ' 
        << 2-r << ' ' << 2-b << ' ' 
        << 2-kt << ' ' << 8-p;
}