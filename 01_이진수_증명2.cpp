#include <iostream>
#include <cmath>
using namespace std;



unsigned long long int SumOfBitLength(unsigned long long int n)
{
	
	unsigned long long int K = (unsigned long long int)log2(n);
	unsigned long long int sum = (n+1)*(K+1);
	for (int i = 0; i <=K; i++) {
		sum -= (1ULL << i);
	}
	return sum;

	// 해답 코드
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