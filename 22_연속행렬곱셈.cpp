#include <iostream>
#include <climits>
using namespace std;

void printAns(int i, int j, int K[][101]) {
	if (i == j) {
		cout << 'M' << i;
	}
	else {
		int k = K[i][j];
		cout << "(";
		printAns(i, k, K);
		printAns(k + 1, j, K);
		cout << ")";
	}
}

int main() {

	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n;
		cin >> n;
		int M[101][101] = { 0 };
		int K[101][101] = { 0 };

		int d[101];
		for (int i = 0;i <= n;i++) {
			cin >> d[i];
		}
		for (int diagonal = 1;diagonal <= n - 1;diagonal++) {
			for (int i = 1;i <= n - diagonal;i++) {
				int j = i + diagonal;
				M[i][j] = INT_MAX;
				for (int k = i;k <= j - 1;k++) {
					int count = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
					if (count < M[i][j]) {
						M[i][j] = count;
						K[i][j] = k;
					}
				}
			}
		}
		printAns(1, n,K);
		cout << "\n";
		cout << M[1][n] << "\n";
	}

}