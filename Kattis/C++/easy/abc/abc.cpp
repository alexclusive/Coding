#include <iostream>
using namespace std;

int main() {
	// need 16bits because input treated as characters not numbers
	uint16_t arr[3]; 
	cin >> arr[0] >> arr[1] >> arr[2];

	if (arr[0] > arr[1]) 
		swap(arr[0], arr[1]);
	if (arr[1] > arr[2]) {
		swap(arr[1], arr[2]);
		if (arr[0] > arr[1])
			swap(arr[0], arr[1]);
	}

	char next;
	while (cin >> next) {
		cout << arr[next-'A'] << ' ';
	}
}

/*
// with notes
// #include <time.h>
int main() {
	// clock_t start, end;

	// start = clock();
	uint8_t a, b, c;
	cin >> a >> b >> c;
	
	// swap then assign to array
	if (a > b) 
		swap(a, b);
	if (b > c) {
		swap(b, c);
		if (a > b)
			swap(a, b);
	}

	uint8_t arr[] = {a, b, c};

	// about 2000ms for this way
	// about 500ms slower to make an array and sort
	// ends up faster overall for the printing later
	uint8_t arr[] = {a, b, c};
	sort(arr, arr+3);
	std::cout << arr[0] << b << arr[3] << endl;

	// about 1500-1600ms for this way
	if (a > b) 
		swap(a, b); // a <= b
	if (b > c) {
		swap(b, c); // b <= c
		if (a > b)
			swap(a, b);
	}
	std::cout << a << b << c << endl;

	// end = clock();
	// std::cout << end-start;

	char next;
	while (cin >> next) {
		cout << arr[next-'A'];
	}
}
*/