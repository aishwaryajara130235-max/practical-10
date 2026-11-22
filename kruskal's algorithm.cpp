
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({wt, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU ds(V);

    int mstWeight = 0;

    cout << "Edges in MST:\n";

    for (auto edge : edges) {
        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v);

            mstWeight += wt;

            cout << u << " - " << v
                 << " : " << wt << endl;
        }
    }

    cout << "Minimum Spanning Tree Weight: "
         << mstWeight << endl;

    return 0;
}
