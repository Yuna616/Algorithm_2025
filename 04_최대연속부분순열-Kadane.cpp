#include <iostream>

using namespace std;

int main() {


	int test_case;
	cin >> test_case;

	while (test_case--) {
		int arr[100];
		int n;
		cin >> n;
		for (int ee = 0; ee < n; ee++) {
			cin >> arr[ee];
		}
		int i, j;
		int maxSum = 0;
		int thisSum = 0;
		int start = -1;
		int end = -1;
		for (i = 0, j = 0; j < n; j++) {
			// 굉장히 중요한 포인트!!
			if (arr[i] == 0) {
				i += 1;
				continue;
			}
			thisSum += arr[j];
			if (thisSum > maxSum) {
				maxSum = thisSum;
				start = i;
				end = j;

			}
			else if (thisSum < 0) {
				i = j + 1;
				thisSum = 0;

			}

		}
		cout << maxSum <<" " << start<<" "<<end <<"\n";


	}


}