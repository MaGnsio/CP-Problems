/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 04:19:47
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
    }
    int find (int x) {
        if (parent[x] != x) {
            x = find(parent[x]);
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
    vector<int> parent_length() {
        set<int> s;
        for (int i = 1; i < parent.size(); ++i) {
            s.insert(find(i));
        }
        vector<int> v;
        for (auto& x : s) {
            v.push_back(length[x]);
        }
        sort(v.begin(), v.end(), greater<int>());
        if (v.size() > 1) {
            v[1] += v[0];
            v[0] = 0;
        }
        return v;
    }
    long long solve() {
        long long res = 0;
        vector<int> v = parent_length();
        for (auto& x : v) {
            res += (long long)x * (long long)x;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    DSU D(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        D.unite(i, x);
    }
    cout << D.solve();
}
