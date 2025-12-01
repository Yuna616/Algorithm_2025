#include <iostream>

using namespace std;

int answer = 0;
void merge(int arr[], int low, int mid, int high) {
	int i, j, k;
	int tmp[50000];
	for (i = low; i <= high; i++) {
		tmp[i] = arr[i];
	}
	i = k = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if (tmp[i] <= tmp[j]) {
			arr[k++] = tmp[i++];
		}
		else {
			answer += (mid - i + 1);
			arr[k++] = tmp[j++];
		}
	}
	while (i <= mid) {
		arr[k++] = tmp[i++];
	}
	while (j <= high) {
		arr[k++] = tmp[j++];
	}
}

void mergeSort(int arr[], int low, int high) {
	int mid;
	if (low >= high)return;

	mid = (low + high) / 2;

	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}


int main() {

	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n;
		cin >> n;
		int arr[50000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		mergeSort(arr, 0, n - 1);
		cout << answer << "\n";
		answer = 0;
	}



}
