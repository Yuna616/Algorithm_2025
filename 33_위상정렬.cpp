#include <iostream>
#include <vector>

using namespace std;

enum color {WHITE,GRAY,BLACK}; //각 정점의 색
vector<color>c;// 정점의 색

typedef vector<vector<int>>Graph;


vector<int>torder;
int toi;
bool hasCycle;


void DFS(const Graph& G, int u) {
	c[u] = GRAY;
	for (int v : G[u]) {
		if (c[v] == WHITE) {
			DFS(G, v);
			if (hasCycle)return;
		}
		else if (c[v] == GRAY) {
			hasCycle = true;
			return;
		}
	}
	torder[toi--] = u;
	c[u] = BLACK;
}

bool Topological_Sort(const Graph& G) {
	int n = G.size()-1;
	c.assign(n+1,WHITE);
	torder.assign(n,0);
	toi = n - 1;
	hasCycle = false;

	for (int u = 1;u <= n;u++) {
		if (c[u] == WHITE) {
			DFS(G, u);
			if (hasCycle)return false;
		}
	}
}




int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n;
		cin >> n;
		Graph G(n+1);
		for (int i = 0;i < n;i++) {
			int k,m;
			cin >> k>>m;
			for (int j = 0;j < m;j++) {
				int num;
				cin >> num;
				G[k].push_back(num);
			}
		}
		Topological_Sort(G);
		if (hasCycle)cout << -1;
		else {
			for (int num : torder) {
				cout << num << " ";
			}
		}
		cout << "\n";
	}
}