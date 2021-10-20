/**
 *    author:  MaGnsi0
 *    created: 29/06/2021 15:48:45
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU {
    int maxi = 0;
    vector<int> root, sum;
    DSU(int N) {
        root = vector<int>(N, -1);
        sum = vector<int>(N, 0);
    }
    int find(int x) {
        if (root[x] != -1 && root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b || a == -1) {
            return;
        }
        if (b == -1) {
            maxi = max(sum[a], maxi);
            return;
        }
        sum[a] += sum[b];
        root[b] = a;
        maxi = max(sum[a], maxi);
    }
};

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n + 1), q(n), ans;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    reverse(q.begin(), q.end());
    DSU d(n + 2);
    for (auto& x : q) {
        ans.push_back(d.maxi);
        d.root[x] = x;
        d.sum[x] = v[x];
        d.unite(x, x + 1);
        d.unite(x - 1, x);
    }
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << x << "\n";
    }

}
