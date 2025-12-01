#include <iostream>
#include <algorithm>

using namespace std;


void printLCS(string s, string t, int m, int n, int S[][101]) {
	if (m == 0 || n == 0) return;

	if (S[m][n] == 0) {
		printLCS(s, t, m - 1, n - 1, S);
		cout << s[m - 1];
	}
	else if (S[m][n] == 1) {
		printLCS(s, t, m, n - 1, S);
	}
	else { // S[m][n] == 2
		printLCS(s, t, m - 1, n, S);
	}
}


int main() {

	int test_case;
	cin >> test_case;
	while (test_case--) {
		string s, t;
		cin >> s >> t;
		int L[101][101] = { 0 };
		int S[101][101] = { 0 };
		int m = s.length();
		int n = t.length();
		for (int i = 0; i <= m;i++) {
			L[i][0] = 0;
		}
		for (int i = 0; i <= n;i++) {
			L[0][i] = 0;
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[i - 1] == t[j - 1]) {
					L[i][j] = L[i - 1][j - 1] + 1;
					S[i][j] = 0;
				}
				else {
					L[i][j] = max(L[i][j - 1], L[i - 1][j]);
					if (L[i][j] == L[i][j - 1]) {
						S[i][j] = 1;
					}
					else {
						S[i][j] = 2;
					}
				}
			}
		}
		int answer = L[m][n];
		cout << answer << " ";
		printLCS(s, t, m, n,S);
		cout << "\n";
	}

}