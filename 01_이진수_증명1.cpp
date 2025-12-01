#include <iostream>
#include <math.h>
#include <cmath>


using namespace std;

unsigned long long int SumOfBitLength(unsigned long long int n) {
	unsigned long long int sum = 0;
	unsigned long long int lgn = 0;
	unsigned long long int tmp = n;
	while (tmp > 1) {
		tmp >>= 1;
		lgn++;
	}
	for (unsigned long long int i = 1; i <= lgn; i++) {
		sum += i * (1ULL << (i - 1));
	}
	sum += (n - (1ULL << lgn) + 1) * (lgn + 1);
	return sum;
}


int main() {

	int num_test_case;
	unsigned long long int n;
	cin >> num_test_case;
	while (num_test_case--) {
		cin >> n;
		cout << SumOfBitLength(n) << "\n";
	}

}