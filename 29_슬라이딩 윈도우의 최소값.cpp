#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef int Key; // 입력 데이터 자료형
struct Element {
	int id; // 식별자
	Key key; // 키 값, 입력값
};
vector<Element> H; // 힙 배열
int n; // 힙에 저장된 원소의 수
vector<int> xmap; // 교차 맵 테이블
inline int LeftChild(int i) { return 2 * i; }
inline int RightChild(int i) { return 2 * i + 1; }
inline int Parent(int i) { return i / 2; }

void SwapHeap(int i, int j) // 힙 배열 원소와 대응하는 xmap 원소를 바꿈
{
	swap(H[i], H[j]); // 힙 배열 원소 H[i], H[j]를 바꿈
	swap(xmap[H[i].id], xmap[H[j].id]);// 힙 원소에 대응하는 xmap 원소도 바꿈
}
void UpHeap(int i) // 수정된 UpHeap 연산
{
	while (i > 1 && H[Parent(i)].key > H[i].key) {
		SwapHeap(i, Parent(i));
		i = Parent(i);
	}
}
void DecreaseKey(int id, Key key) // Decrease 연산
{
	int index = xmap[id];
	H[index].key = key;
	UpHeap(index);
}
void Insert(int id, int key)
{
	H[++n].id = id;
	H[n].key = key;
	xmap[id] = n;
	UpHeap(n);
}
void Heapify(int i)
{
	int left = LeftChild(i);
	int right = RightChild(i);
	int smallest = i;
	if (left <= n && H[left].key < H[smallest].key) {
		smallest = left;
	}
	if (right <= n && H[right].key < H[smallest].key) {
		smallest = right;
	}
	if (smallest != i) {
		SwapHeap(i, smallest);
		Heapify(smallest);
	}
}
int DeleteMin()
{
	int min_id = H[1].id;
	SwapHeap(1, n);
	n--;
	Heapify(1);
	return min_id;


}
void CreateHeap()
{
	for (int i = Parent(n); i >= 1;i--) {
		Heapify(i);
	}
}

int main()
{
	int NumTestCases;
	cin >> NumTestCases;
	while (NumTestCases--) {
		int num_elements, width;
		cin >> num_elements >> width;
		H.resize(width + 1); // 힙의 인덱스는 1 부터 시작
		xmap.resize(num_elements + 1);
		n = width; // 힙의 크기
		for (int i = 1; i <= width; ++i) {
			int val;
			cin >> val;
			H[i].id = i; // 입력 원소의 인덱스 (0~n-1)
			H[i].key = val; // 입력 값
			xmap[i] = i; // xmap
		}
		CreateHeap();

		vector<int> ans;
		ans.reserve(max(0, num_elements - width + 1));
		for (int i = width + 1, delete_id = 1;
			i <= num_elements; ++i, ++delete_id) {
			int val;
			cin >> val; // 다음 데이터를 입력
			ans.push_back(H[1].key); // 루트의 키 값 (윈도우 내에서 가장 작은 값)
			if (H[1].id != delete_id)
				DecreaseKey(delete_id, 0); // 윈도우 가장 앞 원소의 키를 0 으로
			// 줄여서, 루트로 이동시킨 다음
			DeleteMin();
			Insert(i, val);
		}
		ans.push_back(H[1].key); // 가장 마지막 윈도우 위치에서의 최소값
		int sum = 0;
		for (int i = 0; i < (int)ans.size(); ++i) {
			sum += ans[i];
			sum %= 100000007;
		}
		cout << sum << "\n";
	}
	return 0;
}