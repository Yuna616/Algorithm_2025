#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> uf_parent;
vector<int> uf_size;

void UF_MakeSet(int n) {
	uf_parent.resize(n);
	uf_size.resize(n);
	for (int i = 0;i < n;i++) {
		uf_parent[i] = i;
		uf_size[i] = 1;
	}
}

int UF_Find(int x) {
	int root = x;
	while (uf_parent[root] != root) {
		root = uf_parent[root];
	}
	while (uf_parent[x] != root) {
		int parent = uf_parent[x];
		uf_parent[x] = root;
		x = parent;
	}
	return root;
}

void UF_Union(int x, int y) {
	int rx = UF_Find(x);
	int ry = UF_Find(y);

	if (rx != ry) {
		if (uf_size[rx] < uf_size[ry]) {
			uf_parent[rx] = ry;
			uf_size[ry] += uf_size[rx];
		}
		else {
			uf_parent[ry] = rx;
			uf_size[rx] += uf_size[ry];
		}
	}
}

struct AdjVertex {
	int v;
	double wt;
	AdjVertex(int v = 0, double wt = 0.0) : v(v), wt(wt) {};
};
typedef vector<vector<AdjVertex>> Graph;

struct WtEdge
{
	int u, v;
	double wt;
	WtEdge(int u = 0, int v = 0, double wt = 0.0) : u(u), v(v), wt(wt) {};
};

typedef vector<WtEdge> WtEdges;

// 그래프 G에서 모든 간선을 추출하여 edges에 저장
void BuildEdgeSet(const Graph& G, WtEdges& edges) {
	int n = G.size();
	for (int i = 0;i < n;i++) {
		for (AdjVertex vt : G[i]) {
			if (i < vt.v) {
				edges.push_back(WtEdge(i, vt.v, vt.wt));
			}
		}
	}
}

double MST_Kruskal(const Graph& G) {
	int n = G.size();
	double min_weight = 0;
	int mst_edge_count = 0;
	WtEdges edges;
	BuildEdgeSet(G, edges);
	sort(edges.begin(), edges.end(), [](WtEdge& a, WtEdge& b) {return a.wt < b.wt;});
	UF_MakeSet(n);
	for (WtEdge& e : edges) {
		if (UF_Find(e.u) != UF_Find(e.v)) {
			UF_Union(e.u, e.v);
			min_weight += e.wt;
			if (++mst_edge_count == n - 1) {
				break;
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
		Graph G(n);

		for (int i = 0;i < n;i++) {
			int k,m;
			cin >> k>>m;
			k -= 1;
			for (int j = 0;j < m;j++) {
				int v, w;
				cin >> v >> w;
				v -= 1;
				G[k].push_back(AdjVertex(v, w));
				G[v].push_back(AdjVertex(k, w));
			}

		}
		double result = MST_Kruskal(G);
		cout << (int)result << "\n";
	}
}