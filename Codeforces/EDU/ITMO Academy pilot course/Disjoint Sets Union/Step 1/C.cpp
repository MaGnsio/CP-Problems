/**
 *    author:  MaGnsi0
 *    created: 24/06/2021 02:15:13
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> length;
    vector<int> score;
    vector<int> difference;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
        score = vector<int>(N, 0);
        difference = vector<int>(N, 0);
    }
    int find(int x) {
        //notice that path compression will spoil score calculations
        int root = x;
        while (root != parent[root]) {
            root = parent[root];
        }
        return root;
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
        difference[b] = score[a]; //score[b] = score[b] - score[a] (score a got before uniting)
        length[a] += length[b];
        parent[b] = a;
    }
    void add(int x, int value) {
        int a = find(x);
        score[a] += value;
    }
    int get(int x) {
        //score[x] = score[x] - difference[x] + score[parent[x]]
        if (parent[x] == x) {
            return score[x];
        } else {
            return score[x] - difference[x] + get(parent[x]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    DSU a(n + 1);
    while (m--) {
        string c;
        cin >> c;
        if (c == "join") {
            int x, y;
            cin >> x >> y;
            a.unite(x, y);
        } else if (c == "add") {
            int x, v;
            cin >> x >> v;
            a.add(x, v);
        } else {
            int x;
            cin >> x;
            cout << a.get(x) << "\n";
        }
    }
}
