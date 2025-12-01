#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int n, m;
        cin >> n >> m;

        int coins[11];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        sort(coins, coins + m); // 없어도 OK

        int N[12][1001] = { 0 }; // N[i][j]: i개의 동전으로 j를 만드는 방법 수

        // base case
        for (int i = 0; i <= m; i++)
            N[i][0] = 1; // 합이 0이 되는 경우는 항상 1가지 (동전 안 쓰기)

        // DP
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j - coins[i - 1] >= 0)
                    N[i][j] = N[i - 1][j] + N[i][j - coins[i - 1]];
                else
                    N[i][j] = N[i - 1][j];
            }
        }

        cout << N[m][n] << "\n";
    }
}
