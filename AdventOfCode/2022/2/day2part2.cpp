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
            // 0=rock, 1=paper, 2=scissors
            char elf = line[0] - 'A'; // A rock, B paper, C scissors
            char out = line[2]; // X lose, Y draw, Z win

            char me;
            if (out == 'X') { // lose
                me = (elf + 2) % 3; // A->2 (rock->scissors)
            } else if (out == 'Y') { // draw
                me = elf;
            } else {
                me = (elf + 1) % 3; // A->1 (rock->paper)
            }

            score += me + 1;
            if (elf == me) {
                score += 3;
            } else if (me == (elf + 1) % 3) {
                score += 6;
            }
        }
        cout << score;
        in.close();
    }
}