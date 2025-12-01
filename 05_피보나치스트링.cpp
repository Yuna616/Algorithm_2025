#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> FiboLength(50,0);

char getFiboChara(int n, unsigned long long p) {
	if (n == 1) {
		return 'b';
	}
	if (n == 2) {
		return 'a';
	}
	// 피보 나치 n의 스트링은 (n-1)피보 스트링 + (n-2) 피보 스트링 으로 구성되어 있음
	// 1. 만약 구하려는 위치 p 가 바로 이전 피보(n-1)의 길이보다 크다면
	// -> 해당 피보의 위치는 전전 피보(n-2)의 문자열의 위치에 해당함. 
	//  ---> 즉 n-2 피보의 위치
	// 2. 만약 구하려는 위치가 이전 피보의(n-1) 길이보다 작거나 같다면 
	// -> 해당 피보의 위치는 전 피보의 문자열의 위치에 해당함.
	//  ---> 즉 n-1 피보의 위치
	
	// recursion 하게 n-1 피보에 위치한 경우로 이동하거나
	// n-2 피보에 위치한 경우로 이동하는데, 
	// n-2의 피보로 이동하는 경우 앞에 n-1은 없애고 생각해야 하니까 p -(n-1)피보의 길이를 한 값을 p값으로 수정함.

	if (p < FiboLength[n-1]) {
		// 2번인 경우
		return getFiboChara(n - 1,p);
	}
	else {
		//1번인 경우
		return getFiboChara(n - 2, p - FiboLength[n - 1]);
	}

}

void FillFiboLength(int n) {
	FiboLength[1] = 1;
	FiboLength[2] = 1;

	for (int i = 3; i <= n; i++) {
		FiboLength[i] = FiboLength[i - 1] + FiboLength[i - 2];
	}
}


int main() {

	int test_case;
	cin >> test_case;
	FillFiboLength(49);
	while (test_case--) {
		int k;
		unsigned long long p;
		cin >> k >> p;
		char pibo;
		pibo = getFiboChara(k,p);
		cout << pibo << "\n";

	}


}