#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


struct AdjVertex {
	int v;
	double wt;
};

typedef vector<vector<AdjVertex>>Graph;


typedef double Key;
struct Element {
	int id;
	int pred;
	Key dist;
};
vector<Element>H;
vector<int>xmap;

int heapSize;

inline int LeftChild(int i) { return 2 * i; };
inline int RightChild(int i) { return 2 * i + 1; };
inline int Parent(int i) { return i / 2; };

void SwapHeap(int i, int j) {
	swap(H[i], H[j]);
	swap(xmap[H[i].id], xmap[H[j].id]);
}

void Heapify(int i) {
	int left = LeftChild(i);
	int right = RightChild(i);
	int smallest = i;

	if (left <= heapSize && H[left].dist < H[smallest].dist) {
		smallest = left;
	}
	if (right <= heapSize && H[right].dist < H[smallest].dist) {
		smallest = right;
	}
	if (smallest != i) {
		SwapHeap(i, smallest);
		Heapify(smallest);
	}
}
void UpHeap(int i) {
	while (i > 1 && H[Parent(i)].dist > H[i].dist) {
		SwapHeap(i, Parent(i));
		i = Parent(i);
	}
}

Element HeapDeleteMin() {
	Element min = H[1];
	H[1] = H[heapSize];
	heapSize--;
	xmap[H[1].id] = 1;
	Heapify(1);
	return min;
}


void DecreaseKey(int id, int pred, Key new_key) {
	int idx = xmap[id];
	if (idx == 0) return; // 힙에 없으면 무시 (안나는 상황이어야 함)
	H[idx].dist = new_key;
	H[idx].pred = pred;
	UpHeap(idx);
}

struct Edge {
	int u;
	int v;
};

Key SumPathTree(const Graph& G, const vector<Edge>& sTree) {
	Key sum_wt = 0.0;
	for (auto e : sTree) {
		int u = e.u;
		for (auto adj : G[u]) {
			if (adj.v == e.v) {
				sum_wt += adj.wt;
				break;
			}
		}
	}
	return sum_wt;
}

vector<Edge>Dijkstra(const Graph& G) {
	int n = G.size() - 1;
	vector<Edge>sTree;
	vector<bool>visited(n + 1, false);
	H.resize(n + 1, { 0,0 });
	xmap.resize(n + 1, 0);
	heapSize = n;

	for (int i = 1;i <= n;i++) {
		H[i].id = i;
		H[i].pred = 1;
		H[i].dist = INFINITY;
		xmap[i] = i;
	}

	H[1].dist = 0.0;
	while (heapSize > 0) {
		auto e = HeapDeleteMin();
		int v = e.id;
		Key dist = e.dist;
		sTree.push_back({ e.pred,e.id });

		visited[v] = true;
		for (auto e : G[v]) {
			if (visited[e.v] == true)continue;
			int index = xmap[e.v];
			if (dist + e.wt < H[index].dist) {
				DecreaseKey(e.v, v, dist + e.wt);
			}
		}
	}
	return sTree;
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int N;
		cin >> N;
		Graph G(N + 1, vector<AdjVertex>{});
		for (int i = 1;i <= N;i++) {
			int id;
			int degree;
			cin >> id >> degree;
			for (int j = 0;j < degree;j++) {
				int v;
				double weight;
				cin >> v >> weight;
				G[id].push_back(AdjVertex{ v,weight });
			}
		}
		vector<Edge>sTree = Dijkstra(G);
		cout << (int)SumPathTree(G, sTree) << "\n";
	}
	return 0;
}