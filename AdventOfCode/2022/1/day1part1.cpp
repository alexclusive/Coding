#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in ("input");
    if (in.is_open()) {
        string line;
        int maxSum = 0;
        int sum = 0;
        while (getline(in, line)) {
            if (line == "") {
                if (sum > maxSum) {
                    maxSum = sum;
                }
                sum = 0;
            } else {
                sum += stoi(line);
            }
        }
        cout << maxSum;
    }
}