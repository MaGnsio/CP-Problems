/**
 *    author:  MaGnsi0
 *    created: 04.10.2022 22:45:35
**/
#include <bits/stdc++.h>

using namespace std;

int64_t OO = 1e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<tuple<int64_t, int, int>> c(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        c[i] = make_tuple(w, u - 1, v - 1);
    }
    int comps = n;
    vector<int> p(n + 2), s(n + 2);
    function<int(int)> find = [&](int x) {
        if (p[x] == x) {
            return x;
        }
        return p[x] = find(p[x]);
    };
    function<int(int, int)> unite = [&](int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return 0;
        }
        if (s[x] < s[y]) {
            swap(x, y);
        }
        p[y] = x;
        s[x] += s[y];
        comps--;
        return 1;
    };
    function<int64_t(int)> F = [&](int x) {
        comps = n;
        iota(p.begin(), p.end(), 0);
        s.assign(n + 2, 1);
        vector<tuple<int64_t, int, int>> e = c;
        if (x & 1) {
            for (int i = 0; i < n; ++i) {
                e.push_back(make_tuple(a[i], i, n));
            }
            comps++;
        }
        if (x & 2) {
            for (int i = 0; i < n; ++i) {
                e.push_back(make_tuple(b[i], i, n + 1));
            }
            comps++;
        }
        sort(e.begin(), e.end());
        int64_t res = 0;
        for (auto& [w, u, v] : e) {
            res += unite(u, v) * w;
        }
        if (comps == 1) {
            return res;
        } else {
            return OO;
        }
    };
    int64_t ans = OO;
    for (int x = 0; x < 4; ++x) {
        ans = min(ans, F(x));
    }
    cout << ans;
}
