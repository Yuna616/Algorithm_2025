#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000;
vector<vector<long long>> origin = { {1, 1}, {1, 0} }; // ÃÊ±â°ª Çà·Ä

// Çà·Ä °ö
vector<vector<long long>> multiply(vector<vector<long long>> arr1, vector<vector<long long>> arr2) {
    
    vector<vector<long long>> returnArr(2, vector<long long>(2));

    returnArr[0][0] = ((arr1[0][0] * arr2[0][0]) + (arr1[0][1] * arr2[1][0])) % MOD;
    returnArr[0][1] = ((arr1[0][0] * arr2[0][1]) + (arr1[0][1] * arr2[1][1])) % MOD;
    returnArr[1][0] = ((arr1[1][0] * arr2[0][0]) + (arr1[1][1] * arr2[1][0])) % MOD;
    returnArr[1][1] = ((arr1[1][0] * arr2[0][1]) + (arr1[1][1] * arr2[1][1])) % MOD;

    return returnArr;
}

// Çà·Ä °ÅµìÁ¦°ö 
vector<vector<long long>> power(vector<vector<long long>> A, long long exp) {
    if (exp == 1 || exp == 0) return A;

    vector<vector<long long>> returnArr = power(A, exp / 2);
    returnArr = multiply(returnArr, returnArr);

    if (exp % 2 == 1) {
        returnArr = multiply(returnArr, origin);
    }

    return returnArr;
}

int main() {

    int test_case;
    cin >> test_case;
    while (test_case--) {
        long long N;
        cin >> N;
        if (N == 0) {
            cout << 0<<"\n";
        }
        else {
            vector<vector<long long>> A = { {1, 1}, {1, 0} };

            cout << power(A, N - 1)[0][0] << "\n";
        }


    }


    return 0;
}
