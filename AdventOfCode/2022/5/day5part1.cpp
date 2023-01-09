#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int numStacks = 9;
    string infile = "input";
    ifstream in (infile);
    if (in.is_open()) {
        stack<string> buffer;
        string line;
        int height = 0;
        // buffer the stacks for later, go down to see the stack numbers
        // to see how many stacks we need
        while (line[1] != '1') {
            getline(in, line);
            buffer.push(line);
            height++;
        }

        buffer.pop();
        getline(in, line);
        stack<char> arr[numStacks];

        // fill the stacks backwards using the buffered items
        for (int i = 0; i < height-1; i++) {
            cout << buffer.top() << endl; // show each row of the buffered items
            // go through buffered row and push to the right stack
            string row = buffer.top();
            for (int i = 1, stack = 0; i < row.length(); i+=4, stack++) {
                char item = row[i]; // i is the col in the string that holds the number
                if (item >= 'A' && item <= 'Z') {
                    arr[stack].push(item);
                }
            }

            // old attempt
            // for (int i = 1, s = 0; i <= numStacks; i+=4, s++) {
            //     char item = buffer.top()[i];
            //     // cout << buffer.top()[i] << endl;
            //     if (item != ' ') {   // I don't think space was the right representation for a blank
            //         arr[s].push(item);
            //     }
            // }
            buffer.pop();
        }

        // for (int i = 0; i < numStacks; i++) {
        //     cout << i << endl;
        //     cout << arr[i].top() << endl;
        //     arr[i].pop();
        // }

        // read and move instructions
        int num, from, to;
        string buf;
        while (in >> buf >> num >> buf >> from >> buf >> to) {
            from--;
            to--;
            for (int i = 0; i < num; i++) {
                // cout << arr[from].top() << endl;
                arr[to].push(arr[from].top());
                arr[from].pop();
            }
        }

        for (int i = 0; i < numStacks; i++) {
            cout << arr[i].top();
            arr[i].pop();
        }

        in.close();
    }

}