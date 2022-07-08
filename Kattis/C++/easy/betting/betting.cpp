#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a;
    cin >> a;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << 100/a << endl << 100/(100-a);
}