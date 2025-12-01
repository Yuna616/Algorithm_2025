#include <iostream>

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, k;
        cin >> n >> k;
        int dp[1001][1001] = { 0 };
        for (int i = 0; i <= n; i++) {
            int MIN = (i, k);
            for (int j = 0; j < MIN;j++) {
                if (j == 0 || j == i) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
                }
            }
        }
        cout << dp[n][k] % 10007 << "\n";
    }
}