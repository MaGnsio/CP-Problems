#include <bits/stdc++.h>
using namespace std;

int maxN = 1e5 + 5, maxM = maxN * (maxN - 1); //those numbers are hypothetical and may not apply on the real algorithm

struct edge {
    int u, v, w;
    bool operator<(edge e) {
        return (this -> w < e.w);
    }
};

struct DSU {
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if (length[a] < length[b]) {
            swap(a, b);
        }
        length[a] += length[b];
        parent[b] = a;
    }
};

vector<edge> edges(maxM), mst;
vector<vector<int>> adj1(maxN, vector<int>(maxN, INT_MAX));
vector<vector<pair<int, int>>> adj2(maxN);

/*
 *  a minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph
 *  that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
 *  properties of the minimum spanning tree:
 *      - a mst of a graph is unique however there may be multiple minimum spanning trees.
 *      - mst is also the tree with minimum product of weights of edges.
 *      - in a mst of a graph, the maximum weight of an edge is the minimum possible from all possible spanning trees of that graph.
 *      - The maximum spanning tree of a graph can be obtained similarly to that of the minimum spanning tree.
 */

//kruskal's algorithm
//simplest implementation O(MlogM + N^2)
void kruskal_simple() {
    vector<int> tree_id(maxN);
    iota(tree_id.begin(), tree_id.end(), 0);
    sort(edges.begin(), edges.end());
    for (auto& [u, v, w] : edges) {
        if (tree_id[u] == tree_id[v]) {
            continue;
        }
        mst.push_back({u, v, w});
        for (auto& x : tree_id) {
            if (x == tree_id[v]) {
                x = tree_id[u];
            }
        }
    }
}
//dsu implementation O(MlogN)
void kruskal() {
    DSU D(maxN);
    for (auto& [u, v, w] : edges) {
        if (D.find(u) == D.find(v)) {
            continue;
        }
        mst.push_back({u, v, w});
        D.unite(u, v);
    }
}

//prim's algorithm
//dense graphs O(N^2)
void prim_dense() {
    vector<pair<int, int>> min_edge(maxN, {-1, INT_MAX});
    vector<bool> visited(maxN, false);
    min_edge[0].second = 0;
    for (int i = 0; i < maxN; ++i) {
        int v = -1;
        for (int j = 0; j < maxN; ++j) {
            if (!visited[j] && (v == -1 || min_edge[j].second < min_edge[v].second)) {
                v = j;
            }
        }
        if (min_edge[v].second == INT_MAX) {
            //no mst
            //disconnected graph
            return;
        }
        visited[v] = true;
        if (min_edge[v].first != -1) {
            mst.push_back({v, min_edge[v].first, min_edge[v].second});
        }
        for (int j = 0; j < maxN; ++j) { //update minimum edges
            if (adj1[v][j] < min_edge[j].second) {
                min_edge[j] = {v, adj1[v][j]};
            }
        }
    }
}
//sparse graphs: O(MlogN)
void prim_sparse() {
    vector<pair<int, int>> min_edge(maxN, {-1, INT_MAX});
    set<pair<int, int>> s;
    vector<bool> visited(maxN, false);
    s.insert({0, 0});
    min_edge[0].second = 0;
    for (int i = 0; i < maxN; ++i) {
        if (s.empty()) {
            //no mst
            //disconnected graph
            return;
        }
        int v = s.begin() -> second, w = s.begin() -> first;
        s.erase(s.begin());
        visited[v] = true;
        if (min_edge[v].first != -1) {
            mst.push_back({v, min_edge[v].first, min_edge[v].second});
        }
        for (auto& [u, w] : adj2[v]) {
            if (!visited[v] && w < min_edge[u].second) {
                s.erase({min_edge[u].second, u});
                s.insert({w, u});
                min_edge[u] = {v, w};
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
}
