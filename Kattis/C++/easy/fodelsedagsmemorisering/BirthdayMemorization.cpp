#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	Friend* friends = new Friend[N]; // an array of size N
	for (int i = 0; i < N; i++) {
		cin >> friends[i].name >> friends[i].level; // wtf c++
	}
}

class Friend {
	public:
		string name;
		int level;
		int day;
		int month;    
};