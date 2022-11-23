#include <iostream>
using namespace std;

int main() {
    short n, count = 0;
    cin >> n;
    ++n;
    while (++count != n) 
        cout << count << " Abracadabra" << endl;
}