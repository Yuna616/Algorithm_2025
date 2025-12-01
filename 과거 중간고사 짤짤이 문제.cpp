#include <iostream>

using namespace std;
// 3번 문제
//int M(int n) {
//	if (n > 100) return n - 10;
//	else {
//		return M(M(n + 11));
//	}
//}
//int main() {
//	cout << M(99);
//}

// 4번 문제
//int gcd(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	else {
//		gcd(b, a % b);
//	}
//}
//
//int main() {
//	cout << gcd(2035, 1258);
//}


//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int countNum = 0; // 출력 횟수 세기
//
//void swapChar(char* a, char* b) {
//    char temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void permuteString(char str[], int begin, int end) {
//    int range = end - begin;
//    if (range == 1) {
//        cout << str << "\n";
//        countNum++;
//        if (countNum == 19)
//            cout << "special " << str << endl; // 19번째 출력
//    }
//    else {
//        for (int i = 0; i < range; i++) {
//            swapChar(&str[begin], &str[begin + i]);
//            permuteString(str, begin + 1, end);
//            swapChar(&str[begin], &str[begin + i]); // 복원
//        }
//    }
//}
//
//void permute(char str[]) {
//    permuteString(str, 0, strlen(str));
//}
//
//int main() {
//    char str[] = "abcd";
//    permute(str);
//    return 0;
//}



//#include <iostream>
//using namespace std;
//
//int main() {
//    int coins[] = { 1, 2, 4, 5 };
//    int n = 4;      // 동전 개수
//    int K = 10;     // 목표 금액
//
//    int N[5][11] = { 0 }; // N[n][k] (0-based index, 크기 여유 있게)
//
//    // 초기 조건
//    for (int i = 0; i <= n; i++)
//        N[i][0] = 1; // 0원을 만드는 방법은 항상 1가지
//
//    // DP 채우기
//    for (int i = 1; i <= n; i++) {          // 동전 개수
//        for (int k = 1; k <= K; k++) {      // 금액
//            N[i][k] = N[i - 1][k];          // 동전 i를 쓰지 않는 경우
//            if (k >= coins[i - 1])
//                N[i][k] += N[i][k - coins[i - 1]]; // 동전 i를 사용하는 경우
//        }
//    }
//
//    cout << "거스름돈 10원을 만드는 조합의 수 = " << N[n][K] << endl;
//    return 0;
//}

int fiboCount = 0;
int fibo(int n) {
	if (n <= 1) return n;
	else {
		fiboCount += 1;
		return fibo(n - 1) + fibo(n - 2);
	}
}

int main() {
	fibo(10);
	cout << fiboCount;
}