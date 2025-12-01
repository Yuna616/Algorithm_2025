#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
	vector<int>parent;
	UnionFind(int n) : parent(n) {
		for (int i = 0; i < n;i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) parent[b] = a;
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		UnionFind tree(2 * n);

		for (int i = 0; i < m;i++) {
			int q, x, y;
			cin >> q >> x >> y;

			if (q == 1) {
				if (tree.same(x, y + n)) {
					// 모순 발생
					cout << 0 << "\n";
				}
				else {
					tree.unite(x, y);
					tree.unite(x + n, y + n);
				}
			}
			else if (q == 2) {
				if (tree.same(x, y)) {
					// 모순 발생
					cout << 0 << "\n";
				}
				else {
					tree.unite(x, y + n);
					tree.unite(x + n, y);
				}
			}
			else if (q == 3) {
				if (tree.same(x, y)) {
					cout << 1 << "\n";
				}
				else if (tree.same(x, y + n)) {
					cout << 2 << "\n";
				}
				else {
					cout << 3 << "\n";
				}
			}
		}
	}
}