#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

int DP[101][101];

string s, t;

int LCS(int m, int n) {
	if (m == 0 || n == 0) {
		return 0;
	}
	// 이미 계산된 값이 있다면 재사용
	if (DP[m][n] != -1)
		return DP[m][n];

	if (s[m - 1] == t[n - 1]) {
		DP[m][n] = LCS(m - 1, n - 1) + 1;;
	}
	else {
		DP[m][n] = max(LCS(m, n - 1), LCS(m - 1, n));
	}
	return DP[m][n];
}

int main() {

	int test_case;
	cin >> test_case;
	while (test_case--) {

		cin >> s >> t;
		int m = s.length();
		int n = t.length();

		memset(DP, -1, sizeof(DP));
		int answer = LCS(m, n);
		cout << answer << "\n";

	}

}