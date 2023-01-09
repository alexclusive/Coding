#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char findCommon(string s1, string s2, string s3) {
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            for (int k = 0; k < s3.length(); k++) {
                if (s1[i] == s2[j] && s2[j] == s3[k]) {
                    return s1[i];
                }
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
            string l1 = line;
            string l2, l3;
            getline(in, l2);
            getline(in, l3);

            char c = findCommon(l1, l2, l3);

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