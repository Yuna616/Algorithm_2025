#include <iostream>

using namespace std;

int swapCount = 0;

int partioion(int a[], int low, int high) {
	int i, j;

	int pivot, pivotPos, tmp;

	pivot = a[low];
	j = low;
	for (i = low + 1; i <= high; i++) {
		if (a[i] <= pivot) {
			j++;
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			swapCount++;
		}
	}
	pivotPos = j;
	tmp = a[low];
	a[low] = a[pivotPos];
	a[pivotPos] = tmp;
	swapCount++;
	return pivotPos;
}

void quickSort(int v[], int low, int high) {
	int pivotPos;
	if (high > low) {
		pivotPos = partioion(v, low, high);
		quickSort(v, low, pivotPos - 1);
		quickSort(v, pivotPos + 1, high);
	}
}


int main() {
	int i, v[9] = {4,2,7,9,3,1,5,8,6};
	quickSort(v, 0, 8);
	cout << swapCount << "\n";
	for (auto aa : v) {
		cout << aa << " ";
	}
}