/**
 *    author:  MaGnsi0
 *    created: 01.08.2022 02:51:39
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244853;

template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<map<pair<int, int64_t>, int64_t>> adj(n);
    map<pair<int, int>, int64_t> cnt;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[min(u - 1, v - 1)][make_pair(max(u - 1, v - 1), w)]++;
        cnt[make_pair(min(u - 1, v - 1), max(u - 1, v - 1))]++;
    }
    map<pair<int, int>, int64_t> res;
    for (int i = 0; i < n; ++i) {
        for (auto& O : adj[i]) {
            int u = O.first.first;
            int w = O.first.second;
            int y = O.second;
            res[{i, u}] += (((w * y) % MOD) * power(cnt[{i, u}], MOD - 2, MOD)) % MOD;
            res[{i, u}] %= MOD;
        }
    }
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        a[i]--;
    }
    int64_t cur_10 = 1, ans = 0;
    for (int i = k - 2; i >= 0; --i) {
        int u = a[i], v = a[i + 1];
        if (u > v) {
            swap(u, v);
        }
        if (cnt.count({u, v}) == 0) {
            cout << "Stupid Msacywy!";
            return 0;
        }
        ans += cur_10 * res[{u, v}];
        ans %= MOD;
        cur_10 *= 10;
        cur_10 %= MOD;
    }
    cout << ans;
}
