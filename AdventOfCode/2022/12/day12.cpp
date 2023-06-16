#include <iostream>
#include <string>
#include <vector>

#include "../../../include/aocBase.h"
using namespace std;

class Point {
	int i = 0;
	int j = 0;
};

class Path {
	bool complete = false;
	int steps = 0;
	vector<Point> path = {}; 

};

int main() {
	string filename = "example";
	vector<string> file = readFile(filename);
	vector<vector<char>> layout = breakDownStringVector(file);
	// print2D(layout);
	Point start;
	// recursively bruteforce
}