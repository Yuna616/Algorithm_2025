#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef double Key;
struct Element {
	int id;
	Key key;
};

vector<Element>H;
int heapSize; // 힙 원소 수
vector<int>xmap;

inline int LeftChild(int i) { return 2 * i; };
inline int RightChild(int i) { return 2 * i+1; };
inline int Parent(int i) { return i / 2; };

void SwapHeap(int i, int j) {
	swap(H[i], H[j]);
	swap(xmap[H[i].id], xmap[H[j].id]);
}


void Heapify(int i) {
	int left = LeftChild(i);
	int right = RightChild(i);
	int smallest = i;
	if (left <= heapSize && H[left].key < H[smallest].key) {
		smallest = left;
	}
	if (right <= heapSize && H[right].key < H[smallest].key) {
		smallest = right;
	}
	if (smallest != i) {
		SwapHeap(i, smallest);
		Heapify(smallest);
	}
}

void UpHeap(int i) {
	while (i > 1 && H[Parent(i)].key > H[i].key) {
		SwapHeap(i, Parent(i));
		i = Parent(i);
	}
}

void Insert(int id, Key key) {
	H[++heapSize].key= key;
	H[heapSize].id = id;
	xmap[id] = heapSize;
	UpHeap(heapSize);
}

Element DeleteMin() {
	Element min = H[1];
	H[1] = H[heapSize];
	heapSize--;
	xmap[H[1].id] = 1;
	Heapify(1);
	return min;
}
void DecreaseKey(int id, Key new_key) {
	int index = xmap[id];
	H[index].key = new_key;
	UpHeap(index);
}

struct AdjVertex {
	int v;
	double wt;
	AdjVertex(int v = 0, double wt = 0.0) : v(v), wt(wt) {};
};
typedef vector<vector<AdjVertex>> Graph;



Key Mst_Prim(const Graph& G) {
	int n = G.size() - 1; // 정점의 개수
	Key min_weight = 0;// 가중치의 최소 합
	vector<bool>visited(n + 1, false);
	H.resize(n + 1, { 0,0 });
	xmap.resize(n + 1, 0);
	for (int i = 1;i <= n;i++) {
		H[i].id = i;
		H[i].key = INFINITY;
		xmap[i] = i;
	}
	heapSize = n;
	H[1].key = 0.0;
	while (heapSize>0) {
		auto e = DeleteMin();
		int v = e.id;
		Key wt = e.key;

		min_weight += wt;
		visited[v] = true;
		for (auto e : G[v]) {
			if (visited[e.v] == true)continue;
			int index = xmap[e.v];
			if (e.wt < H[index].key) {// 힙에 존재하는 경우
				DecreaseKey(e.v, e.wt);
			}
		}
	}
	return min_weight;

}


int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n;
		cin >> n;
		Graph G(n+1);

		for (int i = 0;i < n;i++) {
			int k, m;
			cin >> k >> m;

			for (int j = 0;j < m;j++) {
				int v, w;
				cin >> v >> w;

				G[k].push_back(AdjVertex(v, w));
				G[v].push_back(AdjVertex(k, w));
			}

		}
		double result = Mst_Prim(G);
		cout << (int)result << "\n";
	}
}