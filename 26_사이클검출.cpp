#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int>parent;
    vector<int>size;
    UnionFind(int n) :parent(n), size(n, 0) {
        for (int i = 0;i < n;i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)return false;
        if (size[a] < size[b])swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, m;
        cin >> n >> m;
        bool hasCycle = false;
        UnionFind uf(n + 1);

        for (int i = 0;i < m;i++) {
            int u, v;
            cin >> u >> v;
            if (u > v)swap(u, v);

            if (!uf.unite(u, v)) {
                hasCycle = true;
            }
        }
        if (!hasCycle) {
            cout << 0 << "\n";
        }
        else {
            cout << 1 << "\n";
        }

    }
}