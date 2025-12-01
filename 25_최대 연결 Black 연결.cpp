#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct UnionFind {
    vector<int> parent, size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
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

        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        UnionFind uf(n * m);
        int dirs[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
        auto idx = [&](int r, int c) { return r * m + c; };

        // 연결 관계 생성
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '#') {
                    for (auto& d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '#') {
                            uf.unite(idx(r, c), idx(nr, nc));
                        }
                    }
                }
            }
        }

        // 최대 연결 요소 크기 계산
        int maxArea = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '#') {
                    int root = uf.find(idx(r, c));
                    maxArea = max(maxArea, uf.size[root]);
                }
            }
        }

        cout << maxArea << "\n";
    }

    return 0;
}
