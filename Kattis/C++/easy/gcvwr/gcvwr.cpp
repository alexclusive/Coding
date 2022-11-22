#include <iostream>
using namespace std;

int main() {
    int gcvwr, truck, items;
    cin >> gcvwr >> truck >> items;
    auto cap = (gcvwr-truck)*0.9;
    int item;
    while (cin >> item) {
        cap -= item;
    }
    cout << cap;
}