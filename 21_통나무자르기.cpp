#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, k;
        cin >> L >> k;
        vector<int> cuts(k + 2);
        cuts[0] = 0;
        for (int i = 1; i <= k; i++) {
            cin >> cuts[i];
        }
        cuts[k + 1] = L;

        vector<vector<int>> dp(k + 2, vector<int>(k + 2, 0));

        for (int len = 2; len <= k + 1; len++) { 
            for (int i = 0; i + len <= k + 1; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int m = i + 1; m < j; m++) {
                    dp[i][j] = min(dp[i][j],
                        dp[i][m] + dp[m][j] + (cuts[j] - cuts[i]));
                }
            }
        }

        cout << dp[0][k + 1] << "\n";
    }
}
