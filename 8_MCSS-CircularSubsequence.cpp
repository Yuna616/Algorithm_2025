#include <iostream>
#include <vector>

using namespace std;


long long kadenMax(vector<int> ark, int n) {

    int i, j;
    long long maxSum = 0, thisSum = 0;
    for (i = 0, j = 0; j < n; j++)
    {
        thisSum += ark[j];
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }
        else if (thisSum < 0)
        {
            i = j + 1;
            thisSum = 0;
        }
    }
    return maxSum;

}

long long kadenMin(vector<int> ark, int n) {
    int i, j;
    long long minSum = 0, thisSum = 0;
    for (i = 0, j = 0; j < n; j++)
    {
        thisSum += ark[j];
        if (thisSum < minSum)
        {
            minSum = thisSum;
        }
        else if (thisSum > 0)
        {
            i = j + 1;
            thisSum = 0;
        }
    }
    return minSum;

}

int main() {


	int test_case;
	cin >> test_case;

	while (test_case--) {
		vector<int> arr;
		int n;
		cin >> n;
        long long totalNum = 0;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            totalNum += num;
            arr.push_back(num);

        }
		
        long long LinearMax = kadenMax(arr, n);
        long long LinearMin = kadenMin(arr, n);
        if (totalNum == LinearMin) {
            cout << LinearMax << "\n";
        }
        else {
            cout << max(LinearMax, totalNum - LinearMin) << "\n";
        }

	}




}