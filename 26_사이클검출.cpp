#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> parent, rankArr;

int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool unionNodes(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false; // 사이클
    if (rankArr[a] < rankArr[b]) swap(a, b);
    parent[b] = a;
    if (rankArr[a] == rankArr[b]) rankArr[a]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        parent.resize(n + 1);
        rankArr.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        bool hasCycle = false;
        set<pair<int, int>> edgeSet;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v); // 무방향 정규화

            // 중복 간선은 무시
            if (edgeSet.count({ u, v })) continue;
            edgeSet.insert({ u, v });

            if (!unionNodes(u, v)) {
                hasCycle = true;
            }
        }

        cout << (hasCycle ? 1 : 0) << "\n";
    }

    return 0;
}
