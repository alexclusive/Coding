#include <iostream>
using namespace std;

int main() {
    int N, len, total = 0;
    cin >> N;

    while (cin >> len) {
        total+=len;
    }
    cout << total-N+1; // +1 because the first rod doesn't lose length
}