#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char findCommon(string s1, string s2) {
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                return s1[i];
            }
        }
    }
    return 0;
}

int main() {
    ifstream in ("input");
    if (in.is_open()) {
        string line;
        int sum = 0;
        while (getline(in, line)) {
            int len = line.length();
            char c = findCommon(line.substr(0,len/2),line.substr(len/2,len));
            int pts = 0;
            if (c >= 'A' && c <= 'Z') {
                pts = c - 'A' + 27;
            } else {
                pts = c - 'a' + 1;
            }
            sum += pts;
        }
        cout << sum;
        in.close();
    }
}