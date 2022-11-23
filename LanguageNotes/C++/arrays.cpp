#include <iostream>
using namespace std;

int main() {
    // Initialisations
    int arr1[3];
    std::cout << "int arr[3]:" << endl;
    cout << "arr[0]: " << arr1[0] << endl;
    cout << "arr[1]: " << arr1[1] << endl;
    cout << "arr[2]: " << arr1[2] << endl;

    int arr2[] = {0, 1, 2};
    std::cout << "int arr[3]:" << endl;
    cout << "arr[0]: " << arr2[0] << endl;
    cout << "arr[1]: " << arr2[1] << endl;
    cout << "arr[2]: " << arr2[2] << endl;

    int n = 3;
    int *arr3 = new int[n]();
    std::cout << "int n = 3" << endl << "int *arr = new int[n]();" << endl;
    cout << "arr[0]: " << arr3[0] << endl;
    cout << "arr[1]: " << arr3[1] << endl;
    cout << "arr[2]: " << arr3[2] << endl;
}