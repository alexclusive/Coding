#include <iostream>
using namespace std;

// uint32_t myPow(uint32_t base, uint32_t exp) {
//     uint32_t pow = base;
//     while (--exp > 0) {
//         pow *= base;
//     }
//     return pow;
// }

uint32_t pow(uint32_t base, uint32_t exp) {
	uint32_t result = 1;
	for (;;) {
		if (exp & 1)
			result *= base;
		exp >>= 1;
		if (!exp)
			break;
		base *= base;
	}
	return result;
}

int main() {
	uint8_t N;
	uint32_t P, sum = 0;
	cin >> N;
	while (cin >> P) {
		sum += pow(P/10, P%10);
	}
	cout << sum;
}