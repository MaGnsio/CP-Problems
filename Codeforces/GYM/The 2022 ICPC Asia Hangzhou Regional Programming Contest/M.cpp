/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 16:57:21
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e18;

struct segment {
    int64_t first, last;
    int64_t sum, gcd_diff;
    segment() {
        first = last = OO;
        gcd_diff = 0;
    }
};

const int N = 5e5 + 5;
int64_t n, k, dfs_time, sum, ans = OO;
int64_t a[N], tin[N], tout[N], dp[N], d[4 * N];
segment b[4 * N];
vector<int> I;
vector<pair<int64_t, int64_t>> adj[N];

void dfs(int v, int p) {
    tin[v] = dfs_time++;
    for (auto& [u, w] : adj[v]) {
        if (u == p) { continue; }
        dp[u] = dp[v] + w;
        dfs(u, v);
    }
    tout[v] = dfs_time++;
}

void propagte(int j, int l, int r) {
    if (d[j] == 0) { return; }
    if (b[j].first == OO) {
        b[j].first = 0;
        b[j].last = 0;
    }
    b[j].first += d[j];
    b[j].last += d[j];
    if (2 * j + 1 < 4 * k) {
        d[2 * j + 1] += d[j];
    }
    if (2 * j + 2 < 4 * k) {
        d[2 * j + 2] += d[j];
    }
    d[j] = 0;
}

segment combine(segment x, segment y) {
    if (x.first == OO) { return y; }
    if (y.first == OO) { return x; }
    segment z;
    z.first = x.first;
    z.last = y.last;
    z.gcd_diff = abs(__gcd(x.gcd_diff, __gcd(x.last - y.first, y.gcd_diff)));
    return z;
}

void _update(int j, int l, int r, int f, int t, int64_t add) {
    if (l > r) { return; }
    if (t < l || r < f) { return; }
    if (f <= l && r <= t) {
        d[j] += add;
        propagte(j, l, r);
        return;
    }
    propagte(j, l, r);
    int m = (l + r) / 2;
    _update(2 * j + 1, l, m, f, t, add);
    _update(2 * j + 2, m + 1, r, f, t, add);
    propagte(2 * j + 1, l, m);
    propagte(2 * j + 2, m + 1, r);
    b[j] = combine(b[2 * j + 1], b[2 * j + 2]);
}

void update(int l, int r, int64_t add) {
    _update(0, 0, k - 1, l, r, add);
}

segment _query(int j, int l, int r, int f, int t) {
    if (l > r) { return segment(); }
    if (t < l || r < f) { return segment(); }
    propagte(j, l, r);
    if (f <= l && r <= t) { return b[j]; }
    int m = (l + r) / 2;
    return combine(_query(2 * j + 1, l, m, f, t), _query(2 * j + 2, m + 1, r, f, t));
}

int64_t get_cur_ans() {
    segment s = _query(0, 0, k - 1, 0, k - 1);
    if (s.first == 0 && s.gcd_diff == 0) { return 0; }
    return int64_t(2) * sum / abs(__gcd(s.first, s.gcd_diff));
}

int L(int x) {
    int l = 0, r = k - 1, j = k;
    while (l <= r) {
        int m = (l + r) / 2;
        if (tin[a[I[m]]] >= x) {
            j = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return j;
}

int R(int x) {
    int l = 0, r = k - 1, j = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (tin[a[I[m]]] <= x) {
            j = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return j;
}

void solve(int v, int p) {
    ans = min(ans, get_cur_ans());
    for (auto& [u, w] : adj[v]) {
        if (u == p) { continue; }
        int l = L(tin[u]);
        int r = R(tout[u]);
        if (l <= r) {
            sum += k * w;
            sum -= 2 * (r - l + 1) * w;
            update(0, k - 1, w);
            update(l, r, -2 * w);
        } else {
            sum += k * w;
            update(0, k - 1, w);
        }
        solve(u, v);
        if (l <= r) {
            sum -= k * w;
            sum += 2 * (r - l + 1) * w;
            update(0, k - 1, -w);
            update(l, r, 2 * w);
        } else {
            sum -= k * w;
            update(0, k - 1, -w);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    dfs(0, -1);
    I.resize(k);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return tin[a[i]] < tin[a[j]];
        });
    for (int i = 0; i < 4 * N; ++i) {
        b[i] = segment();
    }
    for (int i = 0; i < k; ++i) {
        sum += dp[a[i]];
    }
    for (int i = 0; i < k; ++i) {
        update(i, i, dp[a[I[i]]]);
    }
    solve(0, -1);
    cout << ans;
}
