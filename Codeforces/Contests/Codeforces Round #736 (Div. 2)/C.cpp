/**
 *    author:  MaGnsi0
 *    created: 12/08/2021 22:37:34
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, q;
    cin >> n >> m;
    int res = n;
    vector<int> cnt(n, 0);
    vector<bool> died(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) {
            swap(u, v);
        }
        cnt[u]++;
        res -= (!died[u]);
        died[u] = true;
    }
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v) {
                swap(u, v);
            }
            cnt[u]++;
            res -= (!died[u]);
            died[u] = true;
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v) {
                swap(u, v);
            }
            cnt[u]--;
            res += (!cnt[u]);
            died[u] = (cnt[u]);
        } else {
            cout << res << "\n";
        }
    }
}
