#include <iostream>
#include <cmath>


using namespace std;

unsigned long long int SumOfBitLength(unsigned long long int n)
{
	// 해답 코드

	unsigned long long int lgn = 0;
	unsigned long long int tmp = n;
	while (tmp > 1) {
		tmp >>= 1;
		lgn++;
	}

	unsigned long long int sum = n * lgn + n + lgn - (1ULL << (lgn + 1)) + 2;
	return sum;
	
}

int main()
{
	int num_test_cases;
	unsigned long long int n;
	cin >> num_test_cases;
	while (num_test_cases--) {
		cin >> n;
		cout << SumOfBitLength(n) << endl;
	}
	return 0;
}
