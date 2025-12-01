#include <iostream>

using namespace std;



int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n, m;
		cin >> n >> m;
		int coins[11];
		int path[1001] = { 0 };
		int lastCoin[1001] = { 0 };
		for (int i = 0; i < m;i ++) {
			cin >> coins[i];
		}
		
		for (int i = 1; i <= n;i++) {
			int minCoins, newCoin;
			minCoins = i;
			newCoin = 1;
			for (int j = 0; j < m;j++) {
				if (coins[j] > i) {
					continue;
				}
				if (path[i - coins[j]] + 1 < minCoins) {
					minCoins = path[i - coins[j]] + 1;
					newCoin = coins[j];
				}
			}
			path[i] = minCoins;
			lastCoin[i] = newCoin;
		}
		cout << path[n] << "\n";

	}
}