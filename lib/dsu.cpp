#include <bits/stdc++.h>
using namespace std;

/* 
 *  DSU is a data structure that supports disjoint sets on n elements and allows two type of queries:
 *      - get(a) —> return the identifier (parent) of the set to which a belongs to.
 *      - union(a, b) —> join two sets that contain a and b.
 */

struct DSU {
    vector<int> parent;
    vector<int> length;
    vector<int> rank;
    DSU(int N) {
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
        length.resize(N);
        length.assign(N, 1);
        rank.resize(N, 0);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); //path compression optimization
        }
        return parent[x];
        //in some problems we can't compress the path.
    }
    void length_unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) { // x and y already in the same group
            return;
        }
        if (length[Px] < length[Py]) { //union by size
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += Py;
    }
    void rank_unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        rank[a] += (rank[a] == rank[b]);
        parent[b] = a;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
}
