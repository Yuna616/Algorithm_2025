#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum color {WHITE, GRAY,BLACK};
vector<color>c;
vector<int>p;

typedef vector<vector<int>>Graph;
vector<int>edge;
int cnt;
int edgeCount;

void DFS(const Graph& G, int u) {
	c[u] = GRAY;
	for (int v : G[u]) {
		if (c[v] == WHITE) {
			p[v] = u;
			edgeCount += 1;
			DFS(G, v);
		}
	}
}

void DFS_Driver(const Graph& G) {
	int n = G.size()-1;
	edge.clear();
	c.assign(n+1, WHITE);
	p.assign(n + 1, 0);
	cnt = 0;
	for (int u = 1;u <= n;u++) {
		if (c[u] == WHITE) {
			edgeCount = 1;
			cnt += 1;
			DFS(G, u);
			edge.push_back(edgeCount);
		}
	}

}


int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n;
		cin >> n;
		Graph G(n + 1);
		for (int i = 0;i < n;i++) {
			int k, m;
			cin >> k >> m;
			for (int j = 0;j < m;j++) {
				int num;
				cin >> num;
				G[k].push_back(num);
			}
		}
		DFS_Driver(G);
		cout << cnt << " ";
		sort(edge.begin(), edge.end());
		for (int num : edge) {
			cout << num << " ";
		}
		cout << "\n";
	}
}