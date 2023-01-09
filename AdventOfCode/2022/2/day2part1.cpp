#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in ("input");
    if (in.is_open()) {
        string line;
        int score = 0;
        while (getline(in, line)) {
            char elf = line[0]; // A rock, B paper, C scissors
            char me = line[2]; // X rock, Y paper, Z scissors
            score += me - 'W'; // convert X/Y/Z to 1/2/3 from ascii
            if (elf - 'A' == me - 'X') {
                score += 3;
            } else if (me == 'X' && elf == 'C'
                || me == 'Y' && elf == 'A'
                || me == 'Z' && elf == 'B') {
                score += 6;
            }
        }
        cout << score;
        in.close();
    }
}