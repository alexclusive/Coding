#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	// int arr[n];
	int *arr = new int[n];
	for (int i = 0; i <= n; i++, cin >> arr[i]);
	sort(arr,arr+n);
	cout << arr[0];
}