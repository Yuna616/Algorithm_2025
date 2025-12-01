#include <iostream>
#include <vector>

using namespace std;

int main() {

	int test_case;
	cin >> test_case;
	while (test_case--) {

		int n;
		cin >> n;
		int first = 0;
		cin >> first;
		int min = first;
		int max = first;
		for (int i = 1; i < n; i++) {
			int cur;
			cin >> cur;
			if (cur > max) {
				max = cur;
			}
			if (cur < min) {

				min = cur;

			}


		}
		cout << max << " " << min << endl;

	}






}