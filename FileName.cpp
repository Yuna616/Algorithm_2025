#include <iostream>
#include <algorithm>

using namespace std;
int arr[11] = { 0 };

void coinExchange(int coins[], int numDiffCoins, int change, int coinUsed[], int lastCoin[]) {
	int cents, j;

	coinUsed[0] = lastCoin[0] = 0;

	for (cents = 1; cents <= change; cents++) {
		int minCoins, newCoin;

		minCoins = cents;
		newCoin = 1;
		for (j = 0; j < numDiffCoins; j++) {
			if (coins[j] > cents)continue;
			if (coinUsed[cents - coins[j]] + 1 < minCoins) {
				minCoins = coinUsed[cents - coins[j]] + 1;
				newCoin = coins[j];
			}
		}
		coinUsed[cents] = minCoins;
		lastCoin[cents] = newCoin;
	}


}

void reconstruct(int change, int lastCoin[]) {
	if (change > 0) {
		reconstruct(change - lastCoin[change], lastCoin);
		cout << lastCoin[change] << " ";
	}
}

int main() {
	int test_case;
	cin >> test_case;

	while (test_case--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> arr[i];
		}
		/*int coinUsed[10001] = { 0 };
		int lastCoin[10001] = { 0 };

		coinExchange(arr, m, n, coinUsed, lastCoin);*/
		long long dp[10001] = { 0 };
		dp[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = arr[i]; j <= n; j++) {
				dp[j] += dp[j - arr[i]];
			}
		}
		cout << dp[n] << "\n";

	}
}