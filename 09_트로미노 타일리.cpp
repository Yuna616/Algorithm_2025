#include <iostream>

using namespace std;

int countTromino =0;




void tromino(int (*arr) [257], int length, int x,int y,int holeX,int holeY) {
	if (length == 1) return;
	countTromino++;
	int s = length / 2;
	int midX = x +s;
	int midY = y +s;
	
	// 구멍이 어느 위치에 있는가 확인
	int quad = 0;
	if (holeX < midX && holeY < midY) quad = 1;
	else if (holeX < midX && holeY >= midY)quad = 2;
	else if (holeX >= midX && holeY < midY) quad = 3;
	else if (holeX >= midX && holeY >= midY) quad = 4;

	if (quad != 1)arr[midX - 1][midY-1] = countTromino;
	if (quad != 2)arr[midX - 1][midY] = countTromino;
	if(quad!=3) arr[midX][midY-1] = countTromino;
	if(quad!=4) arr[midX][midY] = countTromino;
	
	// 4개 영역 재귀
	tromino(arr,s, x, y, (quad == 1 ? holeX : midX - 1), (quad == 1 ? holeY : midY - 1));

	tromino(arr,s,x, midY, (quad == 2 ? holeX : midX - 1), (quad == 2 ? holeY : midY));

	tromino(arr,s,midX, y, (quad == 3 ? holeX : midX), (quad == 3 ? holeY : midY - 1));

	tromino(arr,s,midX, midY, (quad == 4 ? holeX : midX), (quad == 4 ? holeY : midY));

}

int main() {
	int test_case;
	cin >> test_case;

	while (test_case--) {
		int arr[257][257];
		int n, i, j;
		cin >> n >> i >> j;
		for (int ix = 0; ix < n; ix++) {
			for (int iy = 0; iy < n; iy++) {
				arr[ix][iy] = -1;
			}
		}
		arr[i][j] = 0;
	
		countTromino = 0;
	
		tromino(arr, n, 0,0,i,j);

		for (int ix = 0; ix < n; ix++) {
			for (int iy = 0; iy < n; iy++) {
				cout << arr[ix][iy] << " ";
			}
			cout << "\n";
		}
	}
}