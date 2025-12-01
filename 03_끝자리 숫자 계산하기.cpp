#include <iostream>

using namespace std;


int main() {

	int test_case;
	cin >> test_case;

	while (test_case--) {

		int n;
		cin >> n;
		int answer = 1;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			num = num % 10;
			answer *= num;
			answer = answer % 10;

		}

		cout << answer << endl;
	}


}