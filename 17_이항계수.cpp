#include <iostream>
#include <algorithm>



using namespace std;
int B[1001][1001];

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {

		int n, k;
		cin >> n >> k;

		for (int i = 0; i <= n;i++) {
			int Min = min(i, k);
			for (int j = 0; j <= Min;j++) {
				if (j == 0 || j == i) {
					B[i][j] = 1; // base case
				}
				else {
					B[i][j] = (B[i - 1][j - 1] + B[i - 1][j])% 10007;
				}
				
			}
		}
		cout << B[n][k] % 10007 << "\n";;
	}

}