#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionSets(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int resolve(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    int mstCost = 0;
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (uf.findParent(u) != uf.findParent(v)) {
            uf.unionSets(u, v);
            mstCost += weight;
        }
    }
    return mstCost;
}

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }

        vector<vector<int>> edges;
        int totalCost = 0;
        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
            totalCost += z;
        }

        int mstCost = resolve(m, edges);
        cout << totalCost - mstCost << endl;
    }

    return 0;
}