#include <iostream>
// #include <algorithm>
using namespace std;

void printArr(int* arr, int length) {
	cout << "array:" << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

/**
 * @param arr 
 * @param length length of array
 * @param target target to find in array
 * @param flag true: find target, false: find non-target
 * @return int 
 */
int indexOf(int* arr, int length, int target, bool flag) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == target ^ !flag) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n, g, i = 0;
	cin >> n;
	while (cin >> g) {
		// int arr[g];
		int *arr = new int[g];
		// cant do it this way because we need the index
		// WE DONT NEED THE INDEX WE WANT THE NUMBER SO I COULD HAVE DONE IT THIS WAY AAAA
		// for (int max = g; max <= g; cin >> arr[(max--)-g]);
		// sort(arr, arr+g);
		
		for (int current, i = 0; i < g; i++) {
			cin >> current;
			int idx = indexOf(arr, g, current, true);
			if (idx != -1) {
				arr[i] = -1;
				arr[idx] = -1;
			} else {
				arr[i] = current;
			}
			
		}
		// printArr(arr, g);
		int idx = indexOf(arr, g, -1, false);
		cout << "Case #" << ++i << ": " << arr[idx] << endl;
	}
}